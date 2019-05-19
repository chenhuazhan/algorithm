#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"windows.h"

void knapsack(int *v,int *w,int c,int **m,int n)
{
	int jMax=min(w[n]-1,c);
	int i,j,k,l;
	for(j=0;j<=jMax;j++)
		m[n][j]=0;
	    
	for(j=w[n];j<=c;j++)
		m[n][j]=v[n];
	system("cls");
    for(k=1;k<n+1;k++)
    {
    	for(l=1;l<c+1;l++)
   	        printf("%d ",m[k][l]);
        printf("\n");
    }
	for(i=n-1;i>=1;i--){
		jMax=min(w[i]-1,c);
		for(j=0;j<=jMax;j++)
			m[i][j]=m[i+1][j];
		system("cls");
        for(k=1;k<n+1;k++)
		{
    	    for(l=1;l<c+1;l++)
   	            printf("%d ",m[k][l]);
            printf("\n");
		}

		for(j=w[i];j<=c;j++)
			m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);

		system("cls");
        for(k=1;k<n+1;k++)
		{
    	    for(l=1;l<c+1;l++)
   	            printf("%d ",m[k][l]);
            printf("\n");
		}
	}
	    
	//m[1][c]=m[2][c];
	//if(c>=w[1])
	//	m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
	system("cls");
    for(k=1;k<n+1;k++)
	{
        for(l=1;l<c+1;l++)
   	        printf("%d ",m[k][l]);
        printf("\n");
	}
	system("cls");
}

void traceback(int **m,int *w,int c,int *x,int n)
{
	int i;
	for(i=1;i<n;i++)
		if(m[i][c]==m[i+1][c])x[i]=0;
	    else
		{
			x[i]=1;
			c-=w[i];
		}
		x[n]=(m[n][c]>0)?1:0;
}
	

void main() 
{
	printf("�����뱳��������");
	int c;
	scanf("%d",&c);
	printf("��������Ʒ������");
	int n;
	scanf("%d",&n);
	int* w=new int[n+1];     //��Ʒ��������
	int* v=new int[n+1];     //��Ʒ��ֵ����
	int* x=new int[n+1];
    int** m = new int*[n+1];
	int i,j;
	for(i=0;i<n+1;i++)
    {
        m[i]=new int[c+1];
		for(j=0;j<c+1;j++)
			m[i][j]=0;
    }
    printf("�����������Ʒ������(�Կո�ֿ�):");

    for(i=1;i<n+1;i++)
    	scanf("%d",&w[i]);
    printf("�����������Ʒ�ļ�ֵ(�Կո�ֿ�):");
    for(i=1;i<n+1;i++)
    	scanf("%d",&v[i]);
    knapsack(v,w,c,m,n);
    printf("����ֵΪ��%d\n",m[1][c]);
    printf("��ӡ����m��\n");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<c+1;j++)
   	        printf("%2d ",m[i][j]);
        printf("\n");
    }    
    printf("\n");
    traceback(m,w,c,x,n);
    printf("���Ž�Ϊ��");
    for(i=1;i<n+1;i++)
    	printf("%d ",x[i]);
	system("pause");
}