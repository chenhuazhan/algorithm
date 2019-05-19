#include<stdio.h>
void swap(int *list,int k,int i)
{
	int t;
	t=list[k];list[k]=list[i];list[i]=t;
}
void perm(int *list,int k,int m)
{
	if(k==m)
	{
		for(int i=0;i<=m;i++)
			printf("%d ",list[i]);
		printf("\n");
	}
	else
	{
		for(int i=k;i<=m;i++)
		{
			swap(list,k,i);
			perm(list,k+1,m);
			swap(list,k,i);
		}
	}
}
int main()
{
	int list[5]={1,2,3,4,5};
	perm(list,0,4);
}