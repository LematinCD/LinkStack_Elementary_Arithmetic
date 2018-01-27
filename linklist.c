#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"


LinkList *LinkList_Create()
{
	TLinkList *ret =(TLinkList *)malloc(sizeof(TLinkList));
	if(NULL == ret){
		perror("malloc");
		return NULL;
	}
	ret->next=NULL;
	memset(ret,0,sizeof(TLinkList));
	return ret;
}

int LinkList_Clear(LinkList *list)
{
	TLinkList *klist =((TLinkList *)list)->next;
	TLinkList *p=NULL;
	if(NULL==klist){
		printf("Clear error\n");
		return -1;
	}
	((TLinkList *)list)->next=NULL;
	while(klist!=NULL){
		p=klist;
		klist=klist->next;
		free(p);
	}
	return 0;
}

int LinkList_Empty(LinkList *list)
{
	TLinkList *klist=(TLinkList *)list;
	return (klist->next==NULL);
}

int LinkList_Length(LinkList *list)
{
	int ret=0;
	TLinkList *current =(TLinkList *)list;
	if(NULL==current){
		printf("Get length error!\n");
		return -1;
	}
	while(current->next!=NULL){
		ret++;
		current=current->next;
	}
	return ret;
}

int LinkList_Insert(LinkList *list,char op,int data,char flag,int pos)
{
	int i=0;
	TLinkList *current =(TLinkList *)list;
	TLinkList *insert=NULL;
	if(NULL==current){
		printf("Insert error!\n");
		return -1;
	}
	if(pos<0 || pos>LinkList_Length(list)){
		printf("Insert pos is invalid\n");
		return -1;
	}
	insert=(TLinkList *)malloc(sizeof(TLinkList));
	if(NULL==insert){
		perror("malloc");
		return -1;
	}
	memset(insert,0,sizeof(TLinkList));
	insert->node.op=op;
	insert->node.data=data;
	insert->node.flag=flag;
	insert->next=NULL;
	for(i=0;i<pos;i++){
		current = current->next;
	}
	insert->next = current->next;
	current->next=insert;

	return 0;
}

int LinkList_DeleteLocalNode(LinkList *list,int pos)
{
	int i = 0;
	TLinkList *current =(TLinkList *)list;
	TLinkList *delete=NULL;
	if(NULL==current){
		printf("DeleteLocalNode error!\n");
		return -1;
	}
	if(pos<0 || pos>LinkList_Length(list)){
		printf("Delete pos is invalid\n");
		return -1;
	}
	for(i=0;i<pos;i++){
		current = current->next;
	}
	delete=current->next;
	current->next=delete->next;
	free(delete);
	delete=NULL;	
	return 0;
}

LinkListNode *LinkList_Get(LinkList *list,int pos)
{
	int i=0;
	TLinkList *klist =(TLinkList *)list;
	LinkListNode *node=NULL;
	if(NULL==klist){
		printf("LinkList_Get error!\n");
		return NULL;
	}
	for(i=0;i<pos;i++){
		klist=klist->next;
	}
	node=(LinkListNode *)(klist->next);
	return node;	
}


void LinkList_Display(LinkList *list)
{
	TLinkList *klist = (TLinkList *)list;
	LinkListNode *node =NULL;
	while(NULL!=klist->next){
		node=(LinkListNode *)(klist->next);
		printf("op:%c,data:%d,flag:%d\n",node->op,node->data,node->flag);
		klist=klist->next;
	}
	printf("\n");	
}

void LinkList_Destroy(LinkList *list)
{
	free(list);
}

