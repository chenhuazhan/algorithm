#include <stdio.h>

int a[7]={3,1,6,5,7,2,9};
void swap(int *a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

int partition(int p,int r)
{
	int i=p,j=r+1;
	int x=a[p];
	while(1)
	{
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)break;
		swap(a,i,j);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}

void qSort(int p,int r)
{
	if(p<r){
		int q=partition(p,r);
		qSort(p,q-1);
		qSort(q+1,r);
	}
}

int main()
{
	for(int i=0;i<7;i++)
		printf("%d ",a[i]);
	qSort(0,6);
	for(i=0;i<7;i++)
		printf("%d ",a[i]);
}