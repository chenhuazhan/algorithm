// 0-1背包.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template<class Type>
void Traceback(int n,Type w[],Type v[],Type **p,int *head,int x[])
{
    Type j = p[head[0]-1][0],m=p[head[0]-1][1];
    for(int i=1; i<=n; i++)
    {
        x[i]=0;
        for(int k=head[i+1]; k<=head[i]-1; k++)
        {
            if(p[k][0]+w[i]==j && p[k][1]+v[i]==m)
            {
                x[i]=1;
                j=p[k][0];
                m=p[k][1];
                break;
            }
        }
    }
}
template<class Type>
int Knapsack(int n,Type c,Type v[],Type w[],int **p,int x[])
{
    int *head = new int[n+2];
    head[n+1]=0;
    p[0][0]=0;
    p[0][1]=0;
    int left = 0,right = 0,next = 1;
    head[n]=1;
    for(int i=n; i>=1; i--)
    {
        int k = left;
        for(int j=left; j<=right; j++)
        {
            if(p[j][0]+w[i]>c) break;
            Type y = p[j][0] + w[i],m = p[j][1] + v[i];
            while(k<=right && p[k][0]<y)
            {
                p[next][0]=p[k][0];
                p[next++][1]=p[k++][1];
            }
            if(k<=right && p[k][0]==y)
            {
                if(m<p[k][1])
                {
                    m=p[k][1];
                }
                k++;
            }
            if(m>p[next-1][1])
            {
                p[next][0]=y;
                p[next++][1]=m;
            }
            while(k<=right && p[k][1]<=p[next-1][1])
            {
                k++;
            }
        }
        while(k<=right)
        {
            p[next][0]=p[k][0];
            p[next++][1]=p[k++][1];
        }
        left = right + 1;
        right = next - 1;
        head[i-1] = next;
    }
    Traceback(n,w,v,p,head,x);
    return p[next-1][1];
}
int main()
{
    int c;
    cout<<"请输入待装物品的数量: "<<endl;
    int N;
    cin>>N;
    int *w=new int[N+1];
    int *v=new int[N+1];
    cout<<"请输入各个物品的重量及其对应价值:"<<endl;
    for(int i=1; i<=N; i++)
    {
        cin>>w[i];
        cin>>v[i];
    }
    int *x=new int[N+1];
    cout<<"请输入背包最大载重量:"<<endl;
    cin>>c;
    int **p = new int *[50];
    for(int i=0; i<50; i++)
    {
        p[i] = new int[2];
    }
    cout<<"背包能装的最大价值为："<<Knapsack(N,c,v,w,p,x)<<endl;
    cout<<"背包装下的物品编号为："<<endl;
    for(int i=1; i<=N; i++)
    {
        if(x[i]==1)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    for(int i=0; i<50; i++)
    {
        delete p[i];
    }
    delete[] p;
	system("pause");
    return 0;
}