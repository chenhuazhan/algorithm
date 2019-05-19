#include <iostream> 
#include <time.h>
using namespace std; 

template <class Type>  
void Swap(Type &x,Type &y); 

template<class Type>
float Loading(int x[],  Type w[], Type c, int n);

template<class Type>
void SelectSort(Type w[],int *t,int n);

int main()
{
	float c;
	srand(time(NULL));
	c=rand()%10+20;
	cout<<"�ִ������������"<<c<<endl;
	//cin>>c;
	int n=rand()%8+4;
	cout<<"�������װ��Ʒ�ĸ�����"<<n<<endl;
	//cin>>n;
	int *x=new int[n+1];
	cout<<"�����������װ��Ʒ��������"<<endl;
	float *w = new float[n+1];
	for(int i=1; i<=n; i++)
		w[i]=rand()%12+1;
	for(i=1; i<=n; i++)
		cout<<w[i]<<" ";
	cout<<endl;
	cout<<"����ֵΪ:"<<Loading(x,w,c,n)<<endl;

	cout<<"̰��ѡ����Ϊ:"<<endl;
	for(i=1; i<=n; i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
	return 0;
}

template<class Type>
float Loading(int x[],Type w[], Type c, int n)
{
	int *t = new int [n+1];//�洢�������w[]��ԭʼ����
	SelectSort(w, t, n);

	for(int i=1; i<=n; i++)
	{
		x[i] = 0;//��ʼ������x[]
	}
	for(i=1; i<=n && w[t[i]]<=c; i++)
	{
		x[t[i]] = 1;
		c -= w[t[i]];
	}
	float l=0;
	for(i=1;i<=n;i++)
		l+=w[i]*x[i];
	return l;
}

template<class Type>
void SelectSort(Type w[],int *t,int n)
{
	Type *tempArray=new Type[n+1],temp;
	memcpy(tempArray,w,(n+1)*sizeof(Type));//��w��������ʱ����tempArray��
	int min;

	for(int i=1;i<=n;i++)
	{
		t[i] = i;
	}

	for(i=1;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<=n;j++)
		{
			if(tempArray[min]>tempArray[j])
			{
				min=j;
			}
		}
		Swap(tempArray[i],tempArray[min]);
		Swap(t[i],t[min]);
	}
}

template <class Type>  
void Swap(Type &x,Type &y)
{
	Type temp = x;  
    x = y;  
    y = temp;  
}