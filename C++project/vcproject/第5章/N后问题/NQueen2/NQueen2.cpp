#include <iostream>  
using namespace std;  
  
#define N 8  
int sum=0;  
int *x=new int[N+1];  
  
bool place(int k)  
{  
    int i;  
    for(i=1; i<k; i++)  
    {  
        if(x[i]==x[k] || abs(i-k)==abs(x[i]-x[k]))  
            return false;  
    }  
    return true;  
}  
  
void backtrack2()//��������  
{  
    int i;  
    x[1]=0;  
    int k=1;  
    while(k>0)  
    {  
        x[k]+=1;//��ǰ�м�1��λ�ÿ�ʼ����  
        while((x[k]<=N) && !place(k))//��ǰ��λ���Ƿ���������  
            x[k]+=1;//����������������������һ��λ��  
  
        if(x[k]<=N)//����������������  
        {  
            if(k==N)//�����һ���ʺ��������  
            {  
                for(i=1; i<=N; i++)  
                    cout<<x[i]<<" ";  
                cout<<endl;  
                sum++;  
  
            }  
            else//���ǣ�������һ���ʺ�  
            {  
                k++;  
                x[k]=0;  
            }  
        }  
        else//����  
        {  
            k--;  
        }  
  
    }  
}  
  
void main()  
{  
    backtrack2();  
    cout<<sum<<endl;  
      
}  