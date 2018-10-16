#include<stdio.h>
#include<stdlib.h>
//�������
typedef struct link{//link p;p����һ�����
	int data;//������
	struct link *next;//ָ����
}link;//�ṹ��ı���

//��ʼ������
link *initlink()
{
	link *p=(link*)malloc(sizeof(link));//����һ��ͷ���,Ϊ�䶯̬�����ڴ�
	link *temp=p;//����һ��ָ�����ڱ���ͷ��㣬����head��ָ�����������temp����Ϊָ��
	//��������
	for(int i=1;i<5;i++)
	{
		link *a=(link*)malloc(sizeof(link));//����һ���µĽ��
		//����������и�ֵ
		a->data=i;
		a->next=NULL;//���ڱ�ʾ������
		temp->next=a;//temp���ڱ�����������,temp��������a�������
		temp=temp->next;//temp����һ������ƶ�
	}
	return p;
}

//����Ļ�������
//��������в������
link *insert(link *p,int elem,int add)
{
	link *temp=p;//������ʱ������ڱ�������
	//���ҵ�Ҫ���������һ�����
	for(int i=1;i<add;i++)
	{
		if(temp==NULL)//�жϲ���λ���Ƿ���Ч
		{
			printf("����λ����Ч��\n");
			return p;//���������ͷ���
		}
		temp=temp->next;
	}
	//���������еĴ洢��ʽ����Ϊ���ķ�ʽ
	link *b=(link*)malloc(sizeof(link));//����������b
	b->data=elem;
	b->next=temp->next;//��b����nextָ��ָ��temp����һ�����
	temp->next=b;//��temp��nextָ��ָ��b���
	return p;
}

//���������ɾ������
link *delect(link *p,int del)
{
	link *temp=p;//������ʱ������ڱ�������
	//�ж�ɾ������Ƿ���Ч
	for(int i=1;i<del;i++)
	{
		if(temp==NULL)
		{
			printf("ɾ��λ����Ч��\n");
			return p;
		}
		temp=temp->next;
	}
	link *b=temp->next;//����Ҫɾ����㶨��Ϊb���
	temp->next=b->next;//��temp��nextָ��ָ����Ҫɾ��������һ�����
	free(b);//�ͷ��ڴ�
	return p;
}

//����Ԫ��λ��
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

//����Ԫ��
link *change(link *p,int ch,int elem)
{
	link *temp=p;
	for(int i=1;i<ch;i++)
	{
		if(temp==NULL)
		{
			printf("����λ����Ч��\n");
			return p;
		}
		temp=temp->next;
	}
	//��ʱtempָ����Ҫ���Ľ���ǰһ�����
	link *c=temp->next;//�������cָ����Ҫ���ĵĽ��
	c->data=elem;//�������ݽ��и���
	return p;
}

//�������
void display(link *p)
{
	link *temp=p;
	while(temp->next)//ֻҪָ��temp��Ϊ�վ�һֱ���
	{
		temp=temp->next;
		printf("%d ",temp->data);
	}
	printf("\n");
}

//����
int main()
{
	//��ʼ������
	printf("-----------��ʼ������------------\n");
	link *p=initlink();
	display(p);
	
	//�������
	printf("��λ��4�ϲ���Ԫ��5\n");
	p=insert(p,5,4);
	display(p);

	//ɾ������
	printf("ɾ��λ��3��Ԫ��\n");
	p=delect(p,3);
	display(p);

	//���Ҳ���
	printf("Ԫ��2��λ��Ϊ��\n");
	int s=select(p,2);
	if(s==-1) printf("δ�ҵ���Ҫ���ҵ�Ԫ�أ�\n");
	else printf("%d\n",s);

	//���Ĳ���
	printf("��λ��3��Ԫ�ظ���Ϊ7\n");
	p=change(p,3,7);
	display(p);

	return 0;
}