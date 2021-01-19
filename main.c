#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 256

typedef enum {
    OBJ_INT,
    OBJ_PAIR
} ObjectType;

typedef struct sObject {
    ObjectType type;
    unsigned char marked;

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
    int stackSize
} VM;

VM* newVM() {
    VM* vm = malloc(sizeof(VM));
    vm -> stackSize = 0;
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

Object* newObject(VM* vm, ObjectType type) {
    Object* object = malloc(sizeof(Object));
    object -> type = type;
    return object;
}

void pushInt(VM* vm, int intValue) {
    Object* object = newObject(vm, OBJ_INT);
    object -> value = intValue;
    push(vm, object);
}

void assert(int condition, const char* message) {
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


int main() {
    printf("Hello, garbage!\n");
    return 0;
}
