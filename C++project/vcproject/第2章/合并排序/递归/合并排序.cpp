#include <stdio.h>
int b[20];
void merge(int *c,int *d,int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	while((i<=m)&&(j<=r))
		if(c[i]<=c[j])
			d[k++]=c[i++];
		else
			d[k++]=c[j++];
		if(i>m)
			for(int q=j;q<=r;q++)
				d[k++]=c[q];
		else
			for(int q=i;q<=r;q++)
				d[k++]=c[q];
}

void copy(int *a,int *b,int left,int right)
{
	for(int i=left;i<=right;i++)
		a[i]=b[i];
}

void mergeSort(int *a,int left,int right)
{
	if(left<right){
		int i=(left+right)/2;
		mergeSort(a,left,i);
		mergeSort(a,i+1,right);
		merge(a,b,left,i,right);
		copy(a,b,left,right);
	}
}
int main()
{
	int a[7]={3,1,6,5,9,7,2};
	mergeSort(a,0,6);
	for(int i=0;i<7;i++)
		printf("%d ",a[i]);
}