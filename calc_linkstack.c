#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_linkstack.h"
#include "op_linkstack.h"
#include "calc_linkstack.h"
#include "linklist.h"

/**
*函数功能：获取运算符优先级
*参数：op_t op 传入运算符 
*返回值:运算符等级
*/
data_t op_level(op_t op)
{
	int value=0;
	switch(op){
		case '-':
		case '+':
			value=1;
		break;
		
		case '*':
		case '/':
			value=2;
		break;
		default :
			value =0;
		break;
	}
	return value;
} 
/**
*函数功能:运算符等级比较
*参数:op_t op1 op_t op2 
*返回值:
*/
data_t op_cmp(op_t op1,op_t op2)
{
	return((op_level(op1)>op_level(op2))?1:0);
}


/**
*函数功能：将普通表达式（中缀表达式）转换为后缀表达式
*参数： datalinkstack_t *data   数字栈
*	oplinkstack_t   *op	运算符栈
*	LinkList        *list    单链表存储数据和运算符
×       char *str        待处理的字符串   
*返回值：无
*
*处理规则：
*1.从左到右遍历中缀表达式的每一个数字和运算符号，
*若是数字则直接插入链表中
*2.若是运算符，先判断运算符栈是否为空，如果为空或着为‘（’则直接压入栈中
*若不为空则先判断和栈顶运算符的优先级大小
*3.如果优先级大于栈顶运算符，则直接入栈，否则先弹出栈中的运算符，
*并将其插入链表中，然后再将运算符入栈
*4，如果为‘）’则依次弹出栈中的运算符，并插入到链表中，除了‘（’,
*/

void deal_with(datalinkstack_t *data,oplinkstack_t *op,LinkList *list,char *str)
{
	char *p=str;
	data_t num=0;
	int i=0;
	while(*p){
		if(*p<='9'&&*p>='0'){
			while(*p<='9'&&*p>='0'){
				num=num*10+(*p-'0')*1.0;
				p++;
			}
			LinkList_Insert(list,0,num,1,i++);
			num=0;
			p--;
		}
		else{
			if(EmptyOpLinkStack(op)||*p=='('){
				PushOpLinkStack(op,*p);
			}
			else{
				if(*p==')'){
					while(GetOpLinkStack(op)!='('&& !EmptyOpLinkStack(op)){
						char c=PopOpLinkStack(op);
						if(c!='('){
							LinkList_Insert(list,c,0,0,i++);
						}
					}
					PopOpLinkStack(op);
				}
				else if(op_cmp(*p,GetOpLinkStack(op))){
					PushOpLinkStack(op,*p);
				}
				else if(!op_cmp(*p,GetOpLinkStack(op))){
					while(!EmptyOpLinkStack(op)&&!op_cmp(*p,GetOpLinkStack(op))){
						char c=PopOpLinkStack(op);
						if(c!='('){
							LinkList_Insert(list,c,0,0,i++);
						}
					}
					PushOpLinkStack(op,*p);
				}
			}
		}

	p++;
	}
	while(!EmptyOpLinkStack(op)){
		if(GetOpLinkStack(op)!='('){
			LinkList_Insert(list,PopOpLinkStack(op),0,0,i++);
		}
	}
}


data_t calc_result(datalinkstack_t *data,oplinkstack_t *op)
{
	data_t value=0;
	if(!EmptyDataLinkStack(data)){
		data_t x1=PopDataLinkStack(data);
		if(!EmptyDataLinkStack(data)){
			data_t x2=PopDataLinkStack(data);
			if(!EmptyOpLinkStack(op)){
				switch(PopOpLinkStack(op)){
					case '+':
						value = x2 + x1;
					break;
					case '-':
						value = x2 - x1;
					break;
					case '*':
						value = x2 * x1;
					break;
					case '/':
						value = x2 / x1;
					break;
				}
			}
			else{
				printf("op_stack is empty!\n");
			}	
		
		}
		else{
			value = x1;
		}	
	}
	else{
		printf("data_stack is empty!\n");
	}
	return value;
}

data_t last_calc(datalinkstack_t *data,oplinkstack_t *op,LinkList *list)
{
	int length=LinkList_Length(list);
	int i=0;
	LinkListNode *node=NULL;
	ClearDataLinkStack(data);
	ClearOpLinkStack(op);
	for(i=0;i<length;i++){
		node=LinkList_Get(list,i);
		if(node->flag==1){
			PushDataLinkStack(data,node->data);
		}else if(node->flag==0){
			PushOpLinkStack(op,node->op);
			PushDataLinkStack(data,calc_result(data,op));	
		}
	}
	return PopDataLinkStack(data);
}
