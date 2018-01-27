#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "data_linkstack.h"
#include "op_linkstack.h"
#include "calc_linkstack.h"
#include "linklist.h"


int main()
{
	datalinkstack_t *data_stack=NULL;
	oplinkstack_t *op_stack=NULL;
	TLinkList *list=LinkList_Create();

	CreateDataLinkStack(&data_stack);
	CreateOpLinkStack(&op_stack);
//	char str[]="((2+5)*3-8/2)*723+3";
	char str[]="(((234443-3222)*323)-(((3-1)/2)*((2+3)/2)+((2+1)/(4-1))))";
//	char str[]="((2+5)*3-8/2)*723-7+(9-8)*100/2+3";
//	char str[]="3+(9-5+5*5/5)*6/2";
	deal_with(data_stack,op_stack,list,str);

#ifdef DEBUG
	LinkList_Display(list);
	printf("length:%d\n",LinkList_Length(list));
#endif


	data_t result = last_calc(data_stack,op_stack,list);
	printf("result:%.2f\n",result);


	DestoryDataLinkStack(&data_stack);
	DestoryOpLinkStack(&op_stack);
	LinkList_Destroy(list);
	
	return 0;
}
