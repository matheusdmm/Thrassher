/***************************************************************************************\
 *
 *
 *    /^^^ /^^^^^^
 *        /^^    /^^                                    /^^
 *       /^^    /^^     /^ /^^^   /^^     /^^^^  /^^^^ /^^        /^^    /^ /^^^
 *      /^^    /^ /^    /^^    /^^  /^^ /^^    /^^    /^ /^    /^   /^^  /^^
 *     /^^    /^^  /^^ /^^   /^^   /^^   /^^^   /^^^ /^^  /^^/^^^^^ /^^ /^^
 *    /^^    /^   /^^ /^^   /^^   /^^     /^^    /^^/^   /^^/^         /^^
 *   /^^    /^^  /^^/^^^     /^^ /^^^/^^ /^^/^^ /^^/^^  /^^  /^^^^   /^^^
 *
 *                              Garbage collector - 2021
 *
 *
 *
 *          Made using C11 standards
 *          Clion
 *          GCCx64 for windows
 *
 *
 *
 *  Heavily inspired by this article http://journal.stuffwithstuff.com/2013/12/08/babys-first-garbage-collector/ and made to learn more about garbage collector and how it works with code, and to also sharp my C skills.
 \***************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_MAX 256
#define INIT_OBJ_NUM_MAX 8

typedef enum {
    OBJ_INT,
    OBJ_PAIR
} ObjectType;

typedef struct sObject {
    ObjectType type;
    unsigned char marked;

    //  next object in the linked list
    struct sObject* next;

    union {
        //  OBJ_INT
        int value;

        //  OBJ_PAIR
        struct {
            struct sObject* head;
            struct sObject* tail;
        };
    };
} Object;

typedef struct {
    Object* stack[STACK_MAX];
    int stackSize;

    //  first object in the linked list
    Object* firstObject;

    //  total numbers allocated in the garbage collector
    int numObjects;

    //  number of objects to trigger the garbage collector
    int maxObjects;

} VM;

VM* newVM() {
    VM* vm = malloc(sizeof(VM));
    vm -> stackSize = 0;
    vm -> firstObject = NULL;
    vm -> numObjects = 0;
    vm -> maxObjects = INIT_OBJ_NUM_MAX;

    return vm;
}

void push(VM* vm, Object* value) {
    _assert(vm -> stackSize < STACK_MAX, "Stack overflow");
    vm -> stack[vm -> stackSize++] = value;
}

Object* pop(VM* vm) {
    _assert(vm -> stackSize > 0, "Stack underflow");
    return vm -> stack[--vm -> stackSize];
}


void mark(Object* object) {
    //  if already marked, ok, if not, check again the graph
    if (object -> marked) return;
    object -> marked = 1;

    if (object -> type == OBJ_PAIR) {
        mark(object -> head);
        mark(object -> tail);
    }
}

void markAll(VM* vm) {
    for (int i = 0; i < vm -> stackSize; i++) {
        mark(vm -> stack[i]);
    }
}

void sweep(VM* vm) {
    Object ** object = &vm -> firstObject;

    while (*object) {
        if (!(*object) -> marked) {
            //  this obj isnt at reach, so it will be removed from the list
            Object * unreached = *object;
            *object = unreached -> next;
            free(unreached);
            vm -> numObjects--;
        } else {
            //  this one was reached, so it will be unmarked for the next garbage
            (*object) -> marked = 0;
            object = &(*object) -> next;
        }
    }
}

void gc(VM* vm) {
    int numObjects = vm -> numObjects;
    markAll(vm);
    sweep(vm);

    vm -> maxObjects = vm -> numObjects == 0 ? INIT_OBJ_NUM_MAX : vm -> numObjects * 2;

    printf("Collected %d objects, %d remaining.\n", numObjects - vm -> numObjects, vm -> numObjects);
}

Object* newObject(VM* vm, ObjectType type) {
    if (vm -> numObjects == vm -> maxObjects) gc(vm);
    Object* object = malloc(sizeof(Object));
    object -> type = type;
    object -> next = vm->firstObject;
    vm     -> firstObject = object;
    object -> marked = 0;
    vm->numObjects++;

    return object;
}

void pushInt(VM* vm, int intValue) {
    Object* object = newObject(vm, OBJ_INT);
    object -> value = intValue;
    push(vm, object);
}

void objectPrint(Object* object) {
    switch (object -> type) {
        case OBJ_INT:
            printf("%d", object -> value);
            break;

        case OBJ_PAIR:
            printf("(");
            objectPrint(object -> head);
            printf(", ");
            objectPrint(object -> tail);
            printf(")");
            break;
    }
}

void freeVM(VM *vm) {
    vm -> stackSize = 0;
    gc(vm);
    freeVM(vm);
}

void asserty(int condition, const char* message) {
        if (!condition) {
            printf("%s\n", message);
            exit(1);
        }
}

Object* pushPair(VM* vm) {
    Object* object = newObject(vm, OBJ_PAIR);
    object -> tail = pop(vm);
    object -> head = pop(vm);

    push(vm, object);
    return object;
}


void test() {
    printf("Test: Objects on stacks are preserved.\n");
    VM* vm = newVM();
    pushInt(vm, 1);
    pushInt(vm, 2);
    gc(vm);
    asserty(vm -> numObjects == 2, "should have stayed objects");
    free(vm);
}


int main(int argc, const char * argv[]) {
    printf("Hello, garbage!\n");
    test();
    return 0;
}
