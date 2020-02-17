#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

typedef uint8_t* (*instruction)(uint8_t *, STACK *);

STACK stack_new(int size)
{
    STACK s;
    s.top = 0;
    s.size = size;
    s.stack = (OBJECT *)malloc(sizeof(OBJECT) * size);
    return s;
}

int stack_push(STACK *s, OBJECT o)
{
    s->stack[s->top++] = o;
    return s->top;
}

OBJECT stack_pop(STACK *s)
{
    return s->stack[--(s->top)];
}

OBJECT stack_peek(STACK *s)
{
    return s->stack[s->top - 1];
}

void usage()
{
    printf("usage: vm <file>\n");
    exit(1);
}

uint8_t *load_file(char *filename)
{
    FILE *file;
    int size;
    uint8_t *code = NULL;
    struct stat st;

    if((file = fopen(filename, "rb")))
    {
        fstat(fileno(file), &st);
        code = (uint8_t *)malloc(st.st_size);
        fread((void *)code, 1, st.st_size, file);
    }
    else
    {
        printf("ERROR: Cannot open file %s\n", filename);
        usage();
    }

    fclose(file);

    return code;
}

uint8_t *op_nop(uint8_t *ip, STACK *s)
{
    return ip + 1;
}

uint8_t *op_push_char(uint8_t *ip, STACK *s)
{
    OBJECT o;
    o.type = 'c';
    o.u8 = *(ip + 1);
    stack_push(s, o);
    return ip + 2;
}

uint8_t *op_emit(uint8_t *ip, STACK *s)
{
    OBJECT o = stack_pop(s);
    putchar(o.u8);
    return ip + 1;
}

int main(int argc, char **argv)
{
    printf("Plugin.IO VM Initialized\n");

    uint8_t *code;
    uint8_t *ip;
    STACK data;
    instruction ops[256];

    if(argc != 2)
    {
        //usage();
    }

    // fill all instructions with no ops
    for(int i = 0; i < 256; i++)
    {
        ops[i] = op_nop;
    }

    ops['c'] = op_push_char;
    ops['e'] = op_emit;

    //code = load_file(argv[1]); // TODO send via args
    code = load_file("src/program.txt");
    data = stack_new(1024);
    ip = code;

    while(*ip != 'q')
    {
        ip = ops[*ip](ip, &data);
    }

    printf("\nPlugin.IO VM Exit\n");
    return 0;
}