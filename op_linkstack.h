#ifndef _OP_LINKSTACK_H
#define _OP_LINKSTACK_H
 
typedef char op_t;

typedef struct opnode_t {
	op_t op;
	struct opnode_t *next;
}oplinkstack_t;

void CreateOpLinkStack(oplinkstack_t **stack);
void ClearOpLinkStack(oplinkstack_t *stack);
int EmptyOpLinkStack(oplinkstack_t *stack);
int PushOpLinkStack(oplinkstack_t *stack, op_t op);
op_t PopOpLinkStack(oplinkstack_t *stack);
op_t GetOpLinkStack(oplinkstack_t *stack);
void DestoryOpLinkStack(oplinkstack_t **stack);

#endif
