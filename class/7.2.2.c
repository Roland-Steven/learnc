#include "stdio.h"
#include "stdlib.h"
struct s_list{ 
int data; /* 数据域 */
struct s_list *next; /* 指针域 */ 
} ;
struct s_list * create_list (struct s_list *headp,int *p);
void main(void)
{
	struct s_list *head=NULL,*p;
	int s[]={1,2,3,4,5,6,7,8,0}; /* 0为结束标记 */
	p = create_list(head,s); /* 创建新链表 */ /*遍历指针p指向链头 */
	while(p){
		printf("%d\t",p->data); /* 输出数据域的值 */
		free(p);
		p=p->next; /*遍历指针p指向下一结点 */
	}
	printf("\n");
}
struct s_list * create_list(struct s_list *headp,int *p)
{
	struct s_list * loc_head=NULL,*tail,*build;
	if(p[0]==0) /* 相当于*p==0 */
		;
	else { /* loc_head指向动态分配的第一个结点 */
		loc_head=(struct s_list *)malloc(sizeof(struct s_list));
		loc_head->data=*p++; /* 对数据域赋值 */
		tail=loc_head; /* tail指向第一个结点 */
		tail->next=NULL;
		while(*p){ /* tail所指结点的指针域指向动态创建的结点 */
			build=(struct s_list *)malloc(sizeof(struct s_list));
			build->next=tail;
			tail=build;
			build->data=*p++;
		}
	}
	return tail;
}