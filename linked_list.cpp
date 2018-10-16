#include<stdio.h>
#include<stdlib.h>
//创建结点
typedef struct link{//link p;p就是一个结点
	int data;//数据域
	struct link *next;//指针域
}link;//结构体的别名

//初始化链表
link *initlink()
{
	link *p=(link*)malloc(sizeof(link));//创建一个头结点,为其动态分配内存
	link *temp=p;//创建一个指针用于遍历头结点，由于head是指针变量，所以temp必须为指针
	//生成链表
	for(int i=1;i<5;i++)
	{
		link *a=(link*)malloc(sizeof(link));//创建一个新的结点
		//对这个结点进行赋值
		a->data=i;
		a->next=NULL;//用于表示结点结束
		temp->next=a;//temp用于遍历整个链表,temp将链表与a结点连接
		temp=temp->next;//temp向下一个结点移动
	}
	return p;
}

//链表的基本操作
//对链表进行插入操作
link *insert(link *p,int elem,int add)
{
	link *temp=p;//创建临时结点用于遍历链表
	//先找到要插入结点的上一个结点
	for(int i=1;i<add;i++)
	{
		if(temp==NULL)//判断插入位置是否有效
		{
			printf("插入位置无效！\n");
			return p;//返回链表的头结点
		}
		temp=temp->next;
	}
	//链表中所有的存储方式必须为结点的方式
	link *b=(link*)malloc(sizeof(link));//创建插入结点b
	b->data=elem;
	b->next=temp->next;//令b结点的next指针指向temp的下一个结点
	temp->next=b;//令temp的next指针指向b结点
	return p;
}

//对链表进行删除操作
link *delect(link *p,int del)
{
	link *temp=p;//创建临时结点用于遍历链表
	//判断删除结点是否有效
	for(int i=1;i<del;i++)
	{
		if(temp==NULL)
		{
			printf("删除位置无效！\n");
			return p;
		}
		temp=temp->next;
	}
	link *b=temp->next;//将所要删除结点定义为b结点
	temp->next=b->next;//令temp的next指针指向所要删除结点的下一个结点
	free(b);//释放内存
	return p;
}

//查找元素位置
int select(link *p,int elem)
{
	link *temp=p;
	int i=0;
	while(temp->next)
	{
		if(temp->data==elem)
			return i;
		temp=temp->next;
		++i;
	}
	return -1;
}

//更改元素
link *change(link *p,int ch,int elem)
{
	link *temp=p;
	for(int i=1;i<ch;i++)
	{
		if(temp==NULL)
		{
			printf("更改位置无效！\n");
			return p;
		}
		temp=temp->next;
	}
	//此时temp指向所要更改结点的前一个结点
	link *c=temp->next;//创建结点c指代所要更改的结点
	c->data=elem;//将新数据进行更改
	return p;
}

//输出链表
void display(link *p)
{
	link *temp=p;
	while(temp->next)//只要指针temp不为空就一直输出
	{
		temp=temp->next;
		printf("%d ",temp->data);
	}
	printf("\n");
}

//测试
int main()
{
	//初始化链表
	printf("-----------初始化链表------------\n");
	link *p=initlink();
	display(p);
	
	//插入操作
	printf("在位置4上插入元素5\n");
	p=insert(p,5,4);
	display(p);

	//删除操作
	printf("删除位置3的元素\n");
	p=delect(p,3);
	display(p);

	//查找操作
	printf("元素2的位置为：\n");
	int s=select(p,2);
	if(s==-1) printf("未找到所要查找的元素！\n");
	else printf("%d\n",s);

	//更改操作
	printf("将位置3的元素更改为7\n");
	p=change(p,3,7);
	display(p);

	return 0;
}