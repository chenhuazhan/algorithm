#include <iostream>  
using namespace std;  
  
class Flowshop;  
int Flow(int **,int, int []);  
  
void Swap(int &a, int &b)  
{  
    int temp=a;  
    a=b;  
    b=temp;  
}  
  
class Flowshop  
{  
    friend int Flow(int **,int, int []);  
private:  
    void Backtrack(int i);  
    int **M,        //各作业所需的处理时间  
        *x,         //当前作业调度  
        *bestx,     //当前最优作业调度  
        *f2,        //机器2完成处理的时间  
        f1,         //机器1完成处理的时间  
        f,          //完成时间和  
        bestf,      //当前最优值  
        n;          //作业数  
};  
  
void Flowshop::Backtrack(int i)  
{  
    if(i>n)  
    {//到达叶子结点  
        for(int j=1; j<=n; ++j)  
            bestx[j]=x[j];  
        bestf = f;  
    }else  
        for(int j=i; j<=n; ++j)  // 因为问题的解空间是一颗由x[1:n]的所有排列构成的排列树  
        { // 所以第i次所调度的作业是从序号为i到n的作业中选择一个座位子树分支  
            f1 += M[x[j]][1]; // +第i次所调度的作业在机器1上的处理时间  
            f2[i] = ((f2[i-1]>f1) ? f2[i-1] : f1) + M[x[j]][2];  
            f += f2[i];      //  +第i次所调度的作业在机器2上的处理时间  
            if(f<bestf)  
            {  
                Swap(x[i], x[j]);  
                Backtrack(i+1);  
                Swap(x[i], x[j]);  
            }  
            f1 -= M[x[j]][1]; // -第i次所调度的作业在机器1上的处理时间  
            f -= f2[i];       // -第i次所调度的作业在机器2上的处理时间  
        }  
}  
  
int Flow(int **M, int n, int bestx[])  
{  
    int ub=INT_MAX;  
    Flowshop X;  
    X.x = new int[n+1];  
    X.f2 = new int[n+1];  
    X.M = M;  
    X.n = n;  
    X.bestx = bestx;  
    X.bestf = ub;  
    X.f1 = 0;  
    X.f = 0;  
    for(int i=0; i<=n; i++)  
    {  
        X.f2[i]=0;  
        X.x[i]=i;  
    }  
    X.Backtrack(1);  
    delete [] X.x;  
    delete [] X.f2;  
    return X.bestf;  
}  
  
int main(int argc, char *argv[])  
{  
    int **M = new int*[4];  
    for(int i=0; i<=3; ++i)  
        M[i] = new int[3];  
    M[1][1] = 2; M[1][2]=1;  
    M[2][1] = 3; M[2][2]=1;  
    M[3][1] = 2; M[3][2]=3;  
    int *bestx = new int[4];  
  
    for(int m=1; m<=3; m++)  
    {  
        for(int n=1; n<=2; n++)  
            cout << M[m][n] << " ";  
        cout << endl;  
    }  
  
    cout << Flow(M, 3, bestx) << endl;  
    for(i=1; i<=3; ++i)  
        cout << bestx[i] << ",";  
  
    cout << "Press the enter key to exit";  
    cin.ignore(cin.rdbuf()->in_avail()+1);  
    return 0;  
} 