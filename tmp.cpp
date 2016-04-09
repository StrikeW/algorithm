#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Num
{
	char num;
	struct Num *next;
};


int creat(Num *l,char a[],int n)
{ 
	int i;
	Num *s;
	l=(Num *)malloc(sizeof(Num));
	l->next=NULL;
	for (i=0;i<n;i++)
	{
		s=(Num *)malloc(sizeof(Num));
		s->num=a[i];
		s->next=l->next;
		l->next=s;
	}
	return 0;
}


Num*  creat(char a[],int n)
{
	if(n==0){
		return NULL;
	} 
	Num *header=(Num *)malloc(sizeof(Num));
	header->num=a[0];
	header->next=NULL;
	Num *tail=header;
	int i;
	for (i=1;i<n;i++)
	{
		Num * s=(Num *)malloc(sizeof(Num));
		s->num=a[i];
		s->next=NULL;
		tail->next=s;
		tail=s;
	}
	return header;
}



int main ()
{
	Num*  creat(char a[],int n);
	char S[200];
	int n;
	scanf("%d",&n);
	int i;
	scanf("%s",S);
	Num *head=creat(S,n);
	while (head!=NULL)
	{

		printf("%c ",head->num);
		head=head->next;
	}
	return 0;
}


