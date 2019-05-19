#include <iostream>  
using namespace std;   
  
template <class Type>  
class Loading  
{  
    //friend Type MaxLoading(Type[],Type,int,int []);  
    //private:  
    public:  
        void Backtrack(int i);  
        int n,          //��װ����  
            *x,         //��ǰ��  
            *bestx;     //��ǰ���Ž�  
            Type *w,    //��װ����������  
            c,          //��һ���ִ���������  
            cw,         //��ǰ������  
            bestw,      //��ǰ����������  
            r;          //ʣ�༯װ������  
};  
  
template <class Type>  
void  Loading <Type>::Backtrack (int i);  
  
template<class Type>  
Type MaxLoading(Type w[], Type c, int n, int bestx[]);  
  
int main()  
{     
    int n=3,m;  
    int c=50,c2=50;  
  
    int w[4]={0,10,40,40};  
    int bestx[4];  
  
    m=MaxLoading(w, c, n, bestx);  
  
    cout<<"�ִ����������ֱ�Ϊ��"<<endl;  
    cout<<"c(1)="<<c<<",c(2)="<<c2<<endl;  
  
    cout<<"��װ��װ�������ֱ�Ϊ��"<<endl;  
    cout<<"w(i)=";  
    for (int i=1;i<=n;i++)  
    {  
        cout<<w[i]<<" ";  
    }  
    cout<<endl;  
  
    cout<<"����ѡ����Ϊ��"<<endl;  
    cout<<"m(1)="<<m<<endl;  
    cout<<"x(i)=";  
  
    for (i=1;i<=n;i++)  
    {  
        cout<<bestx[i]<<" ";  
    }  
    cout<<endl;  
  
    int m2=0;  
    for (int j=1;j<=n;j++)  
    {  
        m2=m2+w[j]*(1-bestx[j]);  
    }  
    cout<<"m(2)="<<m2<<endl;  
  
    if(m2>c2)  
    {  
        cout<<"��Ϊm(2)����c(2),����ԭ�����޽⣡"<<endl;  
    }  
    return 0;  
}  
  
template <class Type>  
void  Loading <Type>::Backtrack (int i)// ������i����  
{  
    if (i > n)// ����Ҷ���  
    {    
        if (cw>bestw)  
        {  
            for(int j=1;j<=n;j++)   
            {  
                bestx[j]=x[j];//�������Ž�  
                bestw=cw;   
            }  
        }   
        return;  
    }  
  
    r-=w[i];   
    if (cw + w[i] <= c) // ����������  
    {   
        x[i] = 1;  
        cw += w[i];  
        Backtrack(i+1);  
        cw-=w[i];      
    }  
  
    if (cw + r > bestw)  
    {  
        x[i] = 0;  // ����������  
        Backtrack(i + 1);    
    }  
    r+=w[i];   
}  
  
template<class Type>  
Type MaxLoading(Type w[], Type c, int n, int bestx[])//��������������  
{  
    Loading<Type>X;  
    //��ʼ��X  
    X.x=new int[n+1];  
    X.w=w;  
    X.c=c;  
    X.n=n;  
    X.bestx=bestx;  
    X.bestw=0;  
    X.cw=0;  
    //��ʼ��r  
    X.r=0;  
  
    for (int i=1;i<=n;i++)  
    {  
        X.r+=w[i];  
    }  
  
    X.Backtrack(1);  
    delete []X.x;  
    return X.bestw;  
}  