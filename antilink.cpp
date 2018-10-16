#include<stdio.h>
#include<stdlib.h>

//创建结点
typedef struct link{
	int data;
	struct link *next;
}link;//struct link的别名

//初始化链表
link *initlink()
{
	link *p=(link*)malloc(sizeof(link));//为p结点动态分配内存
	link *temp=p;//定义temp指针用于遍历链表
	for(int i=1;i<6;i++)
	{
		link *a=(link*)malloc(sizeof(link));//创建一个新的结点
		a->data=i;//在新结点中存储数据
		a->next=NULL;//标志结点结束
		temp->next=a;//将指针temp指向a结点
		temp=temp->next;
	}
	return p;
}

//进行链表的逆置
link *untilink(link *p)
{
	link *q,*t;
	q=p->next;
	p->next=NULL;
	while(q)
	{//将temp所指向的当前结点定义为结点b,链表逆置只需将结点b的下一个结点移向结点b的上一个结点
		t=q;
		q=q->next;
		t->next=p->next;
		p->next=t;
	}
	return p;
}

void display(link *p)
{
	link *temp=p;
	while(temp->next)
	{
		temp=temp->next;
		printf("%d ",temp->data);
	}
	printf("\n");
}

//测试
int main()
{
	printf("----------链表的逆置------------\n");
	printf("初始化链表\n");
	link *p=initlink();
	display(p);
	printf("链表的逆置为：\n");
	p=untilink(p);
	display(p);
	return 0;
}