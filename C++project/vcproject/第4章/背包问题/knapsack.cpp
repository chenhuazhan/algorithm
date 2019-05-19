#include "stdio.h"

typedef struct{
	float w,v;
	int i;
}Element;

void Sort(Element *d,int n)
{
	Element t;
	for(int j=0;j<n-1;j++)
		for(int i=j+1;i<n;i++)
		{
			if(d[j].v/d[j].w<d[i].v/d[i].w)
			{
				t=d[i];
				d[i]=d[j];
				d[j]=t;
			}
		}
}
	
float knapsack(float c,float *w,float *v,float *x,int n)
{
	Element *d = new Element[n];
	int i;
	for (i = 0; i < n; i++) 
	{
		d[i].w=w[i];
		d[i].v=v[i];
		d[i].i=i;
	}
	Sort(d,n);
	float opt=0;
	for (i=0;i<n;i++) x[i]=0;
	for (i=0;i<n;i++) {
	    if (d[i].w>c) break;
	    x[d[i].i]=1;
	    opt+=d[i].v;
	    c-=d[i].w;
	}
	if (i<n){
	    x[d[i].i]=c/d[i].w;
	    opt+=x[d[i].i]*d[i].v;
	}
	return opt;
}

int main()
{
	float c;
	printf("请输入背包容量：");
	scanf("%f",&c);
	int n,i;
	printf("请输入物品个数：");
	scanf("%d",&n);
	float *w=new float[n+1];
	printf("请输入各个物品重量:");
	w[0]=0;
	for(i=1;i<n+1;i++)
		scanf("%f",&w[i]);
	float *v=new float[n+1];
	printf("请输入各个物品价值:");
	v[0]=0;
	for(i=1;i<n+1;i++)
		scanf("%f",&v[i]);
	float *x=new float[n+1];
	
	printf("%f",knapsack(c,w,v,x,n+1));

}