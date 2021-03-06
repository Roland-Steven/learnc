/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
/*定义各类常量*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define INFEASTABLE -2
#define OVERFLOW -3
#define STOP -4

typedef int status; 
typedef int ElemType; //数据元素类型定义

typedef struct LNode{  //链表（顺序结构）结点的定义
	ElemType elem;
	struct LNode *next=NULL;
}LNode, *LinkList;

/*进行函数的声明，之后在主函数之后会进行构造的*/
status InitList(LinkList& head);
status DestroyList(LinkList& head);
status ClearList(LinkList& haed);
status ListEmpty(LinkList head);
status ListLength(LinkList head);
status GetElem(LinkList head,int i,ElemType& e);
int LocateElem(LinkList head,ElemType e);
status PriorElem(LinkList head,ElemType cur,ElemType& pre_e);
status NextElem(LinkList head,ElemType cur,ElemType& next_e);
status ListInsert(LinkList& head,int i,ElemType e);
status ListDelete(LinkList& head,int i,ElemType& e);
status ListTrabverse(LinkList head);

int main(void){
LinkList head=NULL; 
LinkList L[30]={NULL}; //定义主表head和用于存储表指针的指针数组L
int op=1;  //输入操作数
int j=0,flag,i,k;  //定义i用于基本的循环，定义j用于指示当前的表为第几号，定义k用来保护j
ElemType e,x; //定义元素类型，用来进行之后部分的数据元素输出
char string[100];  //用于存储之后会使用的文件名称
FILE *fp;  //定义文件指针，之后进行文件操作
while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitList      7. LocateElem\n");
	printf("    	  2. DestroyList   8. PriorElem\n");
	printf("    	  3. ClearList     9. NextElem \n");
	printf("    	  4. ListEmpty     10. ListInsert\n");
	printf("    	  5. ListLength    11. ListDelete\n");
	printf("    	  6. GetElem       12. ListTrabverse\n");
	printf("    	  13.Switch        0. Exit\n");
	printf("-------------------------------------------------\n");
    printf("          101.存储链表      102.读取链表\n");
	printf("请选择你的操作[0~12]:");
	scanf("%d",&op);
    switch(op){
        case 1:
            if(j) L[j-1]=head;  //先将当前使用的主表进行储存
			printf("请输入要创建的表（1~30）:\n");
			for(k=0;k<30;k++) 
			if(L[k]==NULL)
			printf("%d ",k+1);  //使用for循环，输出当前尚可建立的线性表，也就是当前尚未存在的表
			printf("\n");
			scanf("%d",&k);
			if(0<k&&k<=30){
				if(L[k-1]==NULL){
					if(InitList(head)==OK) {
						printf("链表创建成功！\n");
						j=k;
					}
					else printf("链表创建失败！\n");
				}
				else printf("链表已经创建，请重试\n");
			}
			else printf("请输入正确的值\n");
			getchar();getchar();
			break;
        case 2:
            DestroyList(head);    
            getchar();getchar();
            break;
        case 3:
            ClearList(head);    
            getchar();getchar();
            break;
        case 4:
            flag=ListEmpty(head);
			if(flag!=ERROR){
				if(flag==false) printf("表不为空\n");  //使用函数的返回值进行判断并输出
				else printf("表为空\n");
			}     
			getchar();getchar();
			break;
        case 5:
            flag=ListLength(head);
			if(flag>0)
			printf("链表的长度为%d\n",flag);   
			else if(flag==FALSE) printf("表为空\n");    //若函数的输出为error，由listlength的返回值知表为空
			getchar();getchar();
			break;
        case 6:
            if(!head){
                printf("链表不存在\n");
                getchar();getchar();
                break;
            }
            if(head->elem)
			printf("请输入位置值：（输入范围为1~%d）\n",head->elem);
			else printf("请输入位置值：\n");
			scanf("%d",&i);
			flag=GetElem(head,i,e);
			if(flag==FALSE)
			printf("链表为空\n");
			if(flag==OVERFLOW)
			printf("位置值不对哦,最大输入位置值为%d\n",head->elem); 
			if(flag==OK)
			printf("该位置的元素为：%d\n",e);   
			getchar();getchar();
			break;
        case 7:
            printf("请输入要查找的元素：\n");
			scanf("%d",&e);
			i=LocateElem(head,e);
			if(i!=ERROR) printf("该元素在第%d位\n",i);   
			getchar();getchar();
			break;
        case 8:
            printf("请输入要查找的元素：\n");
			scanf("%d",&e); 
			flag=PriorElem(head,e,x);
			if(flag!=ERROR) printf("该元素前一个元素为：%d\n",x);  
			getchar();getchar();
			break;
        case 9:
            printf("请输入要查找的元素：\n");
			scanf("%d",&e); 
			flag=NextElem(head,e,x);
			if(flag!=ERROR) printf("该元素后一个元素为：%d\n",x); 
			getchar();getchar();
            break;
        case 10:
            printf("请输入要插入的元素：\n");
			scanf("%d",&e);
			if(head)
			printf("请输入要插入的位置：（输入范围为1~%d）\n",head->elem+1);
			else printf("请输入要插入的位置：\n");
			scanf("%d",&i);
			flag=ListInsert(head,i,e);
			if (flag==OVERFLOW) printf("存储空间不够\n");
			else if(flag==OK) printf("插入成功\n"); 
			else if(flag==FALSE) printf("位置值不对哦,最大输入位置值为%d\n",head->elem+1); 
			getchar();getchar();
			break;
        case 11:
            if(!head){
                printf("链表不存在\n");
                getchar();getchar();
                break;
            }
            if(head->elem)
			printf("请输入要删除的位置：（输入范围为1~%d）\n",head->elem);
			else {
				printf("表为空，无法删除\n");
				getchar();getchar();
				break;
			}
			scanf("%d",&i);
			flag=ListDelete(head,i,e);
			if(flag==OK) printf("成功删除第%d位元素，其值为%d\n",i,e);
			else if(flag==FALSE) printf("位置值不对哦,最大输入位置值为%d\n",head->elem);   
			getchar();getchar();
			break;
        case 12:
            flag=ListTrabverse(head);  
			if(flag==FALSE) printf("链表是空表！\n");
			else if(flag!=ERROR) printf("一共是%d个元素\n",flag);
			getchar();getchar();
			break;
        case 13:
			if(j) L[j-1]=head;
			printf("选择要切换的表：\n");
			for(k=0;k<30;k++) 
			if(L[k]!=NULL)
			printf("%d ",k+1);
			printf("\n");
			scanf("%d",&k);
			if(k<=0 || k>30) printf("请输入正确的值\n");
			else if(L[k-1]!=NULL){
				head=L[k-1];
				printf("切换成功\n");
				j=k;
			}
			else printf("切换的表不存在\n");
			getchar();getchar();
			break;
		case 0:
			break;
		case 101:
            if(!head){
                printf("链表不存在\n");
                getchar();getchar();
                break;
            }
			printf("请输入要存储的文件\n");
			scanf("%s",string);
			if((fp=fopen(string,"w"))==NULL){
				printf("打开文件失败\n");
				getchar();getchar();
				break;
			}
            LinkList p;
			for(p=head->next;p;p=p->next) fprintf(fp," %d",p->elem);
			printf("已经写入文件%s",string);
			fclose(fp);
			getchar();getchar();
			break;
		case 102:
            if(!head){
                printf("链表不存在\n");
                getchar();getchar();
                break;
            }
			printf("请输入要读取的文件：\n");
			scanf("%s",string);
			if((fp=fopen(string,"r"))==NULL){
				printf("请输入正确的文件，打开失败\n");
				getchar();getchar();
				break;
			}
			while(!feof(fp)){
				fscanf(fp,"%d",&x);
				ListInsert(head,head->elem+1,x);	
			}
			fclose(fp);
			printf("文件元素已添加到链表末尾\n");
			getchar();getchar();
			break;
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
system("pause");
}//end of main()

status InitList(LinkList& head){
    head=(LinkList)malloc(sizeof(LNode));
    if(head==NULL) return ERROR;
    head->elem=0;
    head->next=NULL;
    return OK;
}  //创立一个顺序表，若无法创立返回overflow

status DestroyList(LinkList& head){
    LinkList p,q;
    if(ListEmpty(head)==ERROR) return ERROR;  //首先判断是否创建了表
    char c;
    getchar();
    printf("是否摧毁表？【y/n】\n");
    c=getchar();
    if(c!='y') {  //若停止删除，则返回stop
		printf("停止摧毁\n");
		return STOP;
	}
    for(p=head;p;){  //若确认删除，就依次释放表结点的内存
        q=p;
        p=p->next;
        free(q);
    }
    head=NULL;  //使指针指空
    printf("摧毁成功\n");
    return OK;
}  //正确删除线性表，则返回ok；若停止删除，则返回stop；若表为不存在，则返回error

status ClearList(LinkList& head){
    int flag=ListEmpty(head);
    if(flag==ERROR) return ERROR;
    if(flag==TRUE) printf("表已为空，无法清空\n");
    else{
        char c;int i;LinkList p,q;
        getchar();
        printf("是否清空表？【y/n】\n"); //进行确认是否删除，避免误操作
        c=getchar();
        if(c!='y'){
            printf("停止清空链表\n");
            return STOP;
        }
        for(p=head->next;p;){  //依次释放表结点，但不清楚头结点，仍然保持头结点存在
            q=p;
            p=q->next;
            free(q);
        }
        head->next=NULL;
        head->elem=0;
        printf("成功清空链表\n");
        return OK;
    }
}  //若正确清空，则返回ok；若停止，则返回stop；若表为空，则返回error

status ListEmpty(LinkList head){
    if(head==NULL){
        printf("链表不存在\n");   //与其他函数一起配合，可以简化判断条件，便于优化
        return ERROR;             //可以在其他函数中进行省略这句话
    }
    else if(!head->elem) return TRUE;
    else return FALSE;
}

status ListLength(LinkList head){
    int flag=ListEmpty(head);  //调用函数进行判断，并储存返回值在flag里面
    if(flag==ERROR) return ERROR;
    if(flag==TRUE) return FALSE;
    else return head->elem;
}

status GetElem(LinkList head,int i,ElemType& e){
    int flag=ListEmpty(head);
    if(flag==ERROR) return ERROR;
    if(flag==TRUE) return FALSE;  //若表为空，返回false
    else{
        if(i<=0||i>head->elem) return OVERFLOW; //若输入值超过限制，则返回overflow
        LinkList p;
        for(p=head;i;i--) p=p->next;
        e=p->elem;
    }
    return OK;
}

int LocateElem(LinkList head,ElemType e){
    int flag;
	flag=ListEmpty(head);
	if(flag!=ERROR){
		LinkList p;
        int i;
		for(p=head->next,i=1;p;p=p->next,i++)
			if(p->elem==e) return i;	
		printf("无法找到\n");
		if(flag==TRUE) printf("因为表为空\n");
		return ERROR;
	}
	else return ERROR;
}	

status PriorElem(LinkList head,ElemType cur,ElemType& pre_e){
    int i;
    i=LocateElem(head,cur);
    if(i!=ERROR){
        if(i>1){
            GetElem(head,i-1,pre_e);
            return OK;
        }
        else if(i==1) printf("该元素为首结点，没有前驱结点\n");  //超限条件的判断和提示
    }
    return ERROR;
}

status NextElem(LinkList head,ElemType cur,ElemType& next_e){
    int i;
    i=LocateElem(head,cur);
    if(i!=ERROR){
        if(i!=head->elem){
            GetElem(head,i+1,next_e);
            return OK;
        }
        else if(i==head->elem) printf("该元素为尾结点，没有后继结点\n");    //超限条件的判断与提示
    }
    return ERROR;
}

status ListInsert(LinkList& head,int i,ElemType e){
    if(ListEmpty(head)==ERROR) return ERROR;
	if(i<1||i>head->elem+1) return FALSE;
	LinkList p,q;
    for(p=head;i-1;i--) p=p->next;
    q=p;
    p=p->next;
    q->next=(LinkList)malloc(sizeof(LNode));
    if(!q) return OVERFLOW;   //若扩容不成功，便返回overflow
    q->next->elem=e;
    q->next->next=p;
    head->elem++;
    return OK;  //若成功，则返回OK
}

status ListDelete(LinkList& head,int i,ElemType& e){
    if(ListEmpty(head)!=ERROR){
		if (i<1||i>ListLength(head)) return FALSE; 
		LinkList p,q;
        for(p=head;i-1;i--) p=p->next; //将该位置的结点删除，并将指针重新规划
        e=p->next->elem;
        q=p;
        p=p->next;
        q->next=p->next;
        free(p);
        head->elem--;
		return OK;  //成功删除返回OK，错误返回error
	}
	else return ERROR;  //若出现其他奇怪的现象则返回error
}

status ListTrabverse(LinkList head){
    int flag;
	flag=ListEmpty(head);
	if(flag==TRUE) return FALSE;
	else if(flag==ERROR) return ERROR;
    int i;
    LinkList p=head->next;
	printf("\n-----------all elements -----------------------\n");
	for(i=0;i<head->elem;i++,p=p->next) printf("%d ",p->elem);   //使用间隔分割输出的元素
	printf("\n------------------ end ------------------------\n");
	return head->elem;
}  //遍历链表，输出每一个结点存储的元素