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
    int **M,        //����ҵ����Ĵ���ʱ��  
        *x,         //��ǰ��ҵ����  
        *bestx,     //��ǰ������ҵ����  
        *f2,        //����2��ɴ����ʱ��  
        f1,         //����1��ɴ����ʱ��  
        f,          //���ʱ���  
        bestf,      //��ǰ����ֵ  
        n;          //��ҵ��  
};  
  
void Flowshop::Backtrack(int i)  
{  
    if(i>n)  
    {//����Ҷ�ӽ��  
        for(int j=1; j<=n; ++j)  
            bestx[j]=x[j];  
        bestf = f;  
    }else  
        for(int j=i; j<=n; ++j)  // ��Ϊ����Ľ�ռ���һ����x[1:n]���������й��ɵ�������  
        { // ���Ե�i�������ȵ���ҵ�Ǵ����Ϊi��n����ҵ��ѡ��һ����λ������֧  
            f1 += M[x[j]][1]; // +��i�������ȵ���ҵ�ڻ���1�ϵĴ���ʱ��  
            f2[i] = ((f2[i-1]>f1) ? f2[i-1] : f1) + M[x[j]][2];  
            f += f2[i];      //  +��i�������ȵ���ҵ�ڻ���2�ϵĴ���ʱ��  
            if(f<bestf)  
            {  
                Swap(x[i], x[j]);  
                Backtrack(i+1);  
                Swap(x[i], x[j]);  
            }  
            f1 -= M[x[j]][1]; // -��i�������ȵ���ҵ�ڻ���1�ϵĴ���ʱ��  
            f -= f2[i];       // -��i�������ȵ���ҵ�ڻ���2�ϵĴ���ʱ��  
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