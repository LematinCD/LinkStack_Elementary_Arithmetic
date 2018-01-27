#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "op_linkstack.h"

void CreateOpLinkStack(oplinkstack_t **stack)
{
	*stack =(oplinkstack_t *)malloc(sizeof(oplinkstack_t));
	if(*stack==NULL){
		perror("malloc");
		return ;
	}
	memset(*stack,0,sizeof(oplinkstack_t));
	(*stack)->next = NULL;
}

void ClearOpLinkStack(oplinkstack_t *stack)
{
	if(EmptyOpLinkStack(stack)){
		printf("OpStack is empty!\n");
		return ;
	}
	oplinkstack_t *p=stack->next;
	oplinkstack_t *q=NULL;

	stack->next=NULL;
	while(p->next!=NULL){
		q=p;
		p=p->next;
		free(q);
		q=NULL;
	}

}
int EmptyOpLinkStack(oplinkstack_t *stack)
{
	return(stack->next==NULL);
}


int PushOpLinkStack(oplinkstack_t *stack, op_t op)
{
	oplinkstack_t *q=(oplinkstack_t *)malloc(sizeof(oplinkstack_t));
	if(NULL==q){
		perror("malloc");
		return -1;
	}
	q->op=op;

	q->next=stack->next;
	stack->next=q;	
	return 0;
	
}
op_t PopOpLinkStack(oplinkstack_t *stack)
{
	op_t ret = 0;
	oplinkstack_t *p = stack->next;
	if(EmptyOpLinkStack(stack)){
		printf("oplinkstack is empty!\n");
		return -1;
	}
	stack->next=p->next;
	ret=p->op;
	free(p);
	p=NULL;
	return ret;
	
}
op_t GetOpLinkStack(oplinkstack_t *stack)
{
	if(EmptyOpLinkStack(stack)){
		printf("Get: oplinkstack is empty!\n");
		return -1;
	}
	
	return stack->next->op;
}
void DestoryOpLinkStack(oplinkstack_t **stack)
{
	free(*stack);
	*stack = NULL;
}
