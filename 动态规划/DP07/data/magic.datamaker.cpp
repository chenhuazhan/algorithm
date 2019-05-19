#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn=64,maxm=256,maxv=1024,maxk=32,Inf=1000000000;

int trans[maxn];
void randdata(int i,int N){
	int m=rand()%i+2;
	printf("%d %d",trans[i],m);
	for(int j=0;j<m;++j){
		if(rand()%3){
			printf(" %d",trans[rand()%(i+1)+1]);
		}
		else{
			printf(" %d",trans[rand()%N+1]);
		}
	}
	putchar('\n');
}
void swap(int& a,int &b){
	int t=a;
	a=b;
	b=t;
}
void InputDataMaker(int N,int M,int V,int K,const char* file){
	freopen(file,"w",stdout);
	printf("%d %d %d %d\n",N,M,V,K);
	static int par[maxn];
	static int price0[maxn],price1[maxn];
	static int childnum[maxn];
	for(int i=1;i<=N;++i){
		trans[i]=i;
	}
	for(int i=2;i<=N;++i){
		par[i]=1+rand()%(i-1);
		swap(trans[i],trans[rand()%(i-1)+1]);
	}
	memset(price0,0,sizeof(price0));
	memset(price1,0,sizeof(price1));
	memset(childnum,0,sizeof(childnum));
	for(int i=N;i>=1;--i){
		childnum[par[i]]++;
		price0[i]+=rand()%(2*V/N+1)+1;
		price0[par[i]]+=price0[i]+rand()%(childnum[par[i]]*2+1);
		price1[i]=price0[i]*(N-3)/N-rand()%(price0[i]/10+1);
		if(price1[i]<0){
			price1[i]=0;
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(trans[j]==i)
				printf("%d %d\n",price0[j],price1[j]);
		}
	}
	for(int i=1;i<=N;++i){
		if(childnum[i]<=1){
			randdata(i,N);
		}
		else{
			printf("%d %d",trans[i],childnum[i]);
			for(int j=i+1;j<=N;++j){
				if(par[j]==i){
					printf(" %d",trans[j]);
				}
			}
			putchar('\n');
		}
	}
	for(int i=N+1;i<=M;++i){
		randdata(N/2+rand()%(N/2+1),N);
	}
	fclose(stdout);
}
void OutputDataMaker(const char* input,const char* output){
	char cmd[128];
	sprintf(cmd,"magic <%s >%s",input,output);
	system(cmd);
}
int Ns[10]={5,15,20,25,28,30,40,50,60,60};
int Ms[10]={10,20,50,60,80,100,150,180,200,240};
int Vs[10]={100,200,300,400,500,600,700,800,900,1000};
int Ks[10]={2,4,6,8,10,15,20,24,28,30};
int main(){
	for(int i=0;i<10;++i){
		char input[32];
		sprintf(input,"magic%d.in",i);
		InputDataMaker(Ns[i],Ms[i],Vs[i],Ks[i],input);
	}
	for(int i=0;i<10;++i){
		char input[32];
		char output[32];
		sprintf(input,"magic%d.in",i);
		sprintf(output,"magic%d.out",i);
		OutputDataMaker(input,output);
	}
}
