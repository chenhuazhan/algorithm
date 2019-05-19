#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxn=1024;
int N,M,K;
int n;
int W[maxn],C[maxn];

void makedata(int num){
	freopen("bags.in","w",stdout);
	printf("%d %d %d\n",K,M,N);
	n=0;
	int sum=0;
	while(n<N){
		int w;
		if(rand()%16==0){
			w=rand()%(M/2)+(M/2)+1;
		}
		else if(rand()%8==0){
			w=rand()%(M/5)+(M/5)+1;
		}
		else if(rand()%4==0){
			w=rand()%(M/10)+(M/10)+1;
		}
		else if(rand()%2==0){
			w=rand()%(M*K/N)+(M*K/N)+1;
		}
		else{
			w=rand()%(M*K/N)+1;
		}
		if(sum+w>M)
			w=M-sum;
		int c=rand()%(w+10)+(w/N)+1;
		if(w>M)w=M;
		if(c>5000)c=5000;
		W[n]=w;
		C[n]=c;
		n++;
		sum+=w;
		if(sum==M)
			sum=0;
	}
	for(int i=0;i<N;++i){
		printf("%d %d\n",W[i],C[i]);
	}
	fclose(stdout);
	
	system("bags");
	char order[20];
	sprintf(order,"rename bags.in bags%d.in",num);
	system(order);
	sprintf(order,"rename bags.out bags%d.out",num);
	system(order);
}
int main(){
	int Ks[]={1,3,5,10,21,33,37,41,49,50};
	int Ms[]={10,100,511,1126,2034,3627,4541,4757,4999,5000};
	int Ns[]={10,20,50,100,159,180,185,190,195,200};
	for(int i=0;i<10;++i){
		K=Ks[i];
		M=Ms[i];
		N=Ns[i];
		makedata(i);
	}
}
