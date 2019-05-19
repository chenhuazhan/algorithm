#include <stdio.h>
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

void mergePass(int *a,int *b,int s,int n)
{
	int i=0;
	while(i<=n-2*s){
		merge(a,b,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}
	if(i+s<n)
		merge(a,b,i,i+s-1,n-1);
	else 
		for(int j=i;j<n;j++)
			b[j]=a[j];
}

void mergeSort(int *a,int n)
{
	int b[20];
	int s=1;
	while(s<n){
		mergePass(a,b,s,n);
		s+=s;
		mergePass(b,a,s,n);
		s+=s;
	}
}
int main()
{
	int a[7]={3,1,6,5,9,7,2};
	mergeSort(a,7);
	for(int i=0;i<7;i++)
		printf("%d ",a[i]);
}