#ifndef OPS_H
#define OPS_H

uint8_t *op_push_char(uint8_t *ip, STACK *s);
uint8_t *op_emit(uint8_t *ip, STACK *s);
uint8_t *op_nop(uint8_t *ip, STACK *s);

#endif