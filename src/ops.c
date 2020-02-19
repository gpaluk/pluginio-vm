#include "headers.h"

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

uint8_t *op_nop(uint8_t *ip, STACK *s)
{
    return ip + 1;
}