#ifndef _CALC_LINKSTACK_H
#define _CALC_LINKSTACK_H
#include "linklist.h"
void deal_with(datalinkstack_t *data,oplinkstack_t *op,LinkList *list,char *str);
data_t calc_result(datalinkstack_t *data,oplinkstack_t *op);
data_t last_calc(datalinkstack_t *data,oplinkstack_t *op,LinkList *list);


#endif
