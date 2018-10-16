#include<stdio.h>
#include<stdlib.h>

//�������
typedef struct link{
	int data;
	struct link *next;
}link;//struct link�ı���

//��ʼ������
link *initlink()
{
	link *p=(link*)malloc(sizeof(link));//Ϊp��㶯̬�����ڴ�
	link *temp=p;//����tempָ�����ڱ�������
	for(int i=1;i<6;i++)
	{
		link *a=(link*)malloc(sizeof(link));//����һ���µĽ��
		a->data=i;//���½���д洢����
		a->next=NULL;//��־������
		temp->next=a;//��ָ��tempָ��a���
		temp=temp->next;
	}
	return p;
}

//�������������
link *untilink(link *p)
{
	link *q,*t;
	q=p->next;
	p->next=NULL;
	while(q)
	{//��temp��ָ��ĵ�ǰ��㶨��Ϊ���b,��������ֻ�轫���b����һ�����������b����һ�����
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

//����
int main()
{
	printf("----------���������------------\n");
	printf("��ʼ������\n");
	link *p=initlink();
	display(p);
	printf("���������Ϊ��\n");
	p=untilink(p);
	display(p);
	return 0;
}