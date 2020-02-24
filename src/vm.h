#ifndef VM_H
#define VM_H

typedef struct OBJECT_t
{
    uint8_t type;

    union {
        uint8_t u8;
        int8_t i8;
        uint32_t u32;
        int32_t i32;
        void *ptr;
    };
} OBJECT;

typedef struct STACK_t
{
    int top;
    int size;
    OBJECT *stack;
} STACK;

typedef struct RECT_t
{
    uint64_t nbits; // expanded bits
    int64_t Xmin;
    int64_t Xmax;
    int64_t Ymin;
    int64_t Ymax;
} RECT;

typedef uint8_t* (*instruction)(uint8_t *, STACK *);
STACK stack_new(int size);
int stack_push(STACK *s, OBJECT o);
OBJECT stack_pop(STACK *s);
OBJECT stack_peek(STACK *s);
void usage();
uint8_t *load_file(char *filename);
int main(int argc, char **argv);

#endif