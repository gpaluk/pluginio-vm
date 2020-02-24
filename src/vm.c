#include "headers.h"

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

int main(int argc, char **argv)
{
    printf("Plugin.IO VM Initialized\n\n");

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
    code = load_file("src/_test.swf");
    data = stack_new(1024);
    
    char sig1 = (char)code[0];
    char sig2 = (char)code[1];
    char sig3 = (char)code[2];
    uint8_t version = (uint8_t)code[3];
    uint32_t length = (uint32_t)code[4];

    uint8_t nBits = ((uint8_t)code[8] & 0xF8) >> 3; // grab the first 5 bits
    //RECT frameSize = (Rect)code[8];

    switch (sig1)
    {
        case 'F':
            printf("Signature byte 1: %c (Uncompressed)\n", sig1);
        break;
        case 'C':
            printf("Signature byte 1: %c (zlib compression)\n", sig1);
        break;
        case 'Z':
            printf("Signature byte 1: %c (LZMA compression)\n", sig1);
        break;
        default:
            printf("Unknown signature byte 1: %c\n", sig1);
        break;
    }
    printf("Signature byte 2: %c\n", sig2);
    printf("Signature byte 3: %c\n", sig3);
    printf("SWF version: %u\n", version);
    printf("File length: %u bytes\n\n", length);

    printf("RECT\n");
    printf("nBits: %u\n", nBits);


/*
    ip = code;
    while(*ip != 'q')
    {
        ip = ops[*ip](ip, &data);
    }
*/
    printf("\nPlugin.IO VM Exit\n");
    return 0;
}