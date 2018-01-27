#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef void LinkList;


typedef struct _tag_nodedata
{
	char op;
	int data;
	char flag;
}LinkListNode;

typedef struct _tag_linklist
{
	LinkListNode node;
	struct _tag_linklist *next;
	
}TLinkList;

LinkList *LinkList_Create();

int LinkList_Clear(LinkList *list);

int LinkList_Empty(LinkList *list);

int LinkList_Length(LinkList *list);

int LinkList_Insert(LinkList *list,char op,int data,char flag,int pos);

int LinkList_DeleteLocalNode(LinkList *list,int pos);

LinkListNode *LinkList_Get(LinkList *list,int pos);

void LinkList_Display(LinkList *list);

void LinkList_Destroy(LinkList *list);

#endif
