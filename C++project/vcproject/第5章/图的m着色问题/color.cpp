#include<stdio.h>
#include<time.h>
#include <windows.h>
int color[100];
//int c[100][100];
bool ok(int k ,int c[][100])//�ж϶���k����ɫ�Ƿ�����ͻ
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
        color[i]=0;//��ʼ��
    k=1;
	int num=0;
    while(k>=1)
    {
        color[k]=color[k]+1;
        while(color[k]<=m)
            if (ok(k,c)) break;
            else color[k]=color[k]+1;//������һ����ɫ

        if(color[k]<=m&&k==n)//�����ϣ������
            {
			if(num<20)//ֻ���ǰ20����
            {    for(i=1;i<=n;i++)
                    printf("%d ",color[i]);
			num++;
                printf("\n");
            }    //return;//return��ʾ֮�������һ�ֽ�
            }
            else if(color[k]<=m&&k<n)
                k=k+1;    //������һ������
            else
            {
                color[k]=0;
                k=k-1;//����
            }
    }
}


void main()
{
    int i,j,n,m;
    int c[100][100];//�洢n�����������ͼ������
	srand(time(NULL));
	n=rand()%5+5;
	m=rand()%2+n-2;
    printf("������n=%d\n��ɫ��m=%d\n",n,m);
    //scanf("%d %d",&n,&m);
    
	for(i=1;i<=n;i++)
		c[i][i]=0;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            c[i][j]=c[j][i]=rand()%2;
	printf("����ͼ���ڽӾ���:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
    printf("��ɫ���п��ܵĽ�:\n");
    graphcolor(n,m,c);
}