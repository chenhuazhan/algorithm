#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int maxn=20001;
int N,Max0,Max;
bool prime[maxn];
int sg[maxn];
bool used[maxn];

void pretreat(){
	freopen("game.log","w",stdout);
	memset(prime,-1,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<maxn;++i){
		if(prime[i]){
			for(int j=2;i*j<maxn;++j)
				prime[i*j]=false;
		}
	}
	sg[0]=sg[1]=0;
	for(int i=2;i<maxn;++i){
		memset(used,0,sizeof(used));
		for(int j=0;j<i;++j)
			if(prime[i-j])
				used[sg[j]]=true;
		for(sg[i]=0;used[sg[i]];++sg[i]);
	}
	for(int i=0;i<maxn;++i){
		printf("sg[%d]=%d\n",i,sg[i]);
	}
}
void makedata(int num){
	freopen("game.in","w",stdout);
	printf("%d\n",N);
	printf("%d\n",Max0);
	for(int i=2;i<N;++i){
		bool res=rand()&1;
		int x;
		do{
			x=1+rand()%(Max-1);
		}while(res==!sg[x]);
		printf("%d\n",x);
	}
	printf("%d\n",Max);
	
	fclose(stdout);
	
	system("game");
	char order[20];
	sprintf(order,"rename game.in game%d.in",num);
	system(order);
	sprintf(order,"rename game.out game%d.out",num);
	system(order);
}
int main(){
	pretreat();
	srand(time(0));
	N=10;
	const int Max0s[]={1,15,36,120,130,370,405,901,4209,11139};
	const int Maxs[]={20,100,400,1024,1984,7777,10000,12000,19999,20000};
	for(int i=0;i<10;++i){
		Max0=Max0s[i];
		Max=Maxs[i];
		makedata(i);
	}
}
