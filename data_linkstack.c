#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "data_linkstack.h"

void CreateDataLinkStack(datalinkstack_t **stack)
{
	*stack =(datalinkstack_t *)malloc(sizeof(datalinkstack_t));
	if(*stack==NULL){
		perror("malloc");
		return ;
	}
	memset(*stack,0,sizeof(datalinkstack_t));
	(*stack)->next = NULL;
	(*stack)->data=0;
}

void ClearDataLinkStack(datalinkstack_t *stack)
{
	
	if(EmptyDataLinkStack(stack)){
		printf("DataStack is empty!\n");
		return ;
	}
	datalinkstack_t *p=stack->next;
	datalinkstack_t *q=NULL;
	stack->next=NULL;
	while(p->next!=NULL){
		q=p;
		p=p->next;
		free(q);
	}

}
int EmptyDataLinkStack(datalinkstack_t *stack)
{
	return(stack->next==NULL);
}


int PushDataLinkStack(datalinkstack_t *stack, data_t data)
{
	datalinkstack_t *q=(datalinkstack_t *)malloc(sizeof(datalinkstack_t));
	if(NULL==q){
		perror("malloc");
		return -1;
	}
	q->data=data;

	q->next=stack->next;
	stack->next=q;	
	return 0;
	
}
data_t PopDataLinkStack(datalinkstack_t *stack)
{
	data_t ret = 0;
	datalinkstack_t *p = stack->next;
	if(EmptyDataLinkStack(stack)){
		printf("datalinkstack is empty!\n");
		return -1;
	}
	stack->next=p->next;
	ret=p->data;
	free(p);
	p=NULL;
	return ret;
	
}
data_t GetDataLinkStack(datalinkstack_t *stack)
{
	if(EmptyDataLinkStack(stack)){
		printf("Get: datalinkstack is empty!\n");
		return -1;
	}
	
	return stack->next->data;
}
void DestoryDataLinkStack(datalinkstack_t **stack)
{
	free(*stack);
	*stack = NULL;
}
