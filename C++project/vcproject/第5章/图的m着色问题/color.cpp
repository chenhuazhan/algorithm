#include<stdio.h>
#include<time.h>
#include <windows.h>
int color[100];
//int c[100][100];
bool ok(int k ,int c[][100])//判断顶点k的着色是否发生冲突
{
    int i,j;
    for(i=1;i<k;i++)
        if(c[k][i]==1&&color[i]==color[k])
            return false;
        return true;
}

void graphcolor(int n,int m,int c[][100])
{
    int i,k;
    for(i=1;i<=n;i++)
        color[i]=0;//初始化
    k=1;
	int num=0;
    while(k>=1)
    {
        color[k]=color[k]+1;
        while(color[k]<=m)
            if (ok(k,c)) break;
            else color[k]=color[k]+1;//搜索下一个颜色

        if(color[k]<=m&&k==n)//求解完毕，输出解
            {
			if(num<20)//只输出前20个解
            {    for(i=1;i<=n;i++)
                    printf("%d ",color[i]);
			num++;
                printf("\n");
            }    //return;//return表示之求解其中一种解
            }
            else if(color[k]<=m&&k<n)
                k=k+1;    //处理下一个顶点
            else
            {
                color[k]=0;
                k=k-1;//回溯
            }
    }
}


void main()
{
    int i,j,n,m;
    int c[100][100];//存储n个顶点的无向图的数组
	srand(time(NULL));
	n=rand()%5+5;
	m=rand()%2+n-2;
    printf("顶点数n=%d\n着色数m=%d\n",n,m);
    //scanf("%d %d",&n,&m);
    
	for(i=1;i<=n;i++)
		c[i][i]=0;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            c[i][j]=c[j][i]=rand()%2;
	printf("无向图的邻接矩阵:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
    printf("着色所有可能的解:\n");
    graphcolor(n,m,c);
}