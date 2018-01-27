#ifndef _DATA_LINKSTACK_H
#define _DATA_LINKSTACK_H
 
typedef double data_t;

typedef struct node_t {
	data_t data;
	struct node_t *next;
}datalinkstack_t;

void CreateDataLinkStack(datalinkstack_t **stack);
void ClearDataLinkStack(datalinkstack_t *stack);
int EmptyDataLinkStack(datalinkstack_t *stack);
int PushDataLinkStack(datalinkstack_t *stack, data_t data);
data_t PopDataLinkStack(datalinkstack_t *stack);
data_t GetDataLinkStack(datalinkstack_t *stack);
void DestoryDataLinkStack(datalinkstack_t **stack);

#endif
