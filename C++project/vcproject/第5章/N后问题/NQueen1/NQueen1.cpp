#include <iostream>  
using namespace std;  
  
#define N 10  
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
  
void backtrack(int t)//递归回溯  
{  
    int i=0;  
    if(t>N)  
    {  
        for(i=1; i<=N; i++)  
            cout<<x[i]<<" ";  
        cout<<endl;  
        sum++;  
    }  
    else  
    {  
        for(i=1; i<=N; i++)  
        {  
            x[t]=i;  
            if(place(t))  
                backtrack(t+1);  
        }  
    }  
}  
void main()  
{  
  
    backtrack(1);  
    cout<<N<<"皇后问题共有"<<sum<<"个可行解"<<endl;  
} 