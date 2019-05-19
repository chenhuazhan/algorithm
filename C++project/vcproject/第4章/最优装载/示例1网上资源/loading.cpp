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
	cout<<"轮船最大载重量："<<c<<endl;
	//cin>>c;
	int n=rand()%8+4;
	cout<<"请输入待装物品的个数："<<n<<endl;
	//cin>>n;
	int *x=new int[n+1];
	cout<<"请输入各个待装物品的重量："<<endl;
	float *w = new float[n+1];
	for(int i=1; i<=n; i++)
		w[i]=rand()%12+1;
	for(i=1; i<=n; i++)
		cout<<w[i]<<" ";
	cout<<endl;
	cout<<"最优值为:"<<Loading(x,w,c,n)<<endl;

	cout<<"贪心选择结果为:"<<endl;
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
	int *t = new int [n+1];//存储排完序后w[]的原始索引
	SelectSort(w, t, n);

	for(int i=1; i<=n; i++)
	{
		x[i] = 0;//初始化数组x[]
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
	memcpy(tempArray,w,(n+1)*sizeof(Type));//将w拷贝到临时数组tempArray中
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