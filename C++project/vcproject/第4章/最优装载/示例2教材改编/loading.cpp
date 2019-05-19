#include "stdio.h"
#include "stdlib.h"

typedef struct{
	float w;
	int i;
}Element;

void Sort(Element *d,int n)
{
	Element t;
	int i,j;
	for(j=0;j<=n-1;j++)
		for(i=j+1;i<=n;i++)
		{
			if(d[j].w>d[i].w)
			{
				t=d[i];
				d[i]=d[j];
				d[j]=t;
			}
		}	
}

float loading(float c,float *w,int *x,int n)
{
	Element *d=new Element[n+1];
	int i;
	for(i=0;i<=n;i++)
	{
		d[i].w=w[i];
		d[i].i=i;
		printf("%f ",d[i].w);
	}
	printf("\n");
	Sort(d,n);
	for(i=0;i<=n;i++)
	{
		printf("%f ",d[i].w);
	}printf("\n");
	float opt=0;
	
	for(i=0;i<=n;i++) x[i]=0;
	for(i=0;i<=n&&d[i].w<=c;i++)
	{
		x[d[i].i]=1;
		opt+=d[i].w;
		c-=d[i].w;
	}
	for(i=1;i<=n;i++)
		printf("%d ",x[i]);
	return opt;
}

int main()
{
	float c;
	printf("请输入轮船载重量：");
	scanf("%f",&c);
	int n,i;
	printf("请输入集装箱个数：");
	scanf("%d",&n);
	float *w=new float[n+1];
	printf("请输入各个集装箱重量:");
	w[0]=0;
	for(i=1;i<n+1;i++)
		scanf("%f",&w[i]);
	int *x=new int[n+1];
	
	printf("%f",loading(c,w,x,n));

}
