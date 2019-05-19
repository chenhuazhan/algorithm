#include <cstdio>
#include <cstring>
const int maxn=30010;
bool prime[maxn];
int pp[maxn],pn;
bool win[maxn];
int f[maxn];
int Q[10]; 
int N,M; 


void minimize(int& o,int x){
	if(o>x)o=x;
}
void maximize(int& o,int x){
	if(o<x)o=x;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&N);
	M=0;
	for(int i=0;i<N;++i){
		scanf("%d",Q+i);
		if(M<Q[i])M=Q[i];
	}
	
	memset(prime,-1,sizeof(prime));
	pn=0;
	prime[0]=prime[1]=false;
	for(int i=2;i<=M;++i){
		if(prime[i]){
			pp[pn++]=i;
			for(int j=i;i*j<=M;++j)
				prime[i*j]=false;
		}
	}
	pp[pn]=maxn;
	
	win[0]=win[1]=false;
	for(int i=2;i<=M;++i){
		win[i]=false;
		for(int j=0;pp[j]<=i;++j){
			if(false==win[i-pp[j]]){
				win[i]=true;
				break;
			}
		}
	}
	f[0]=f[1]=0;
	int max=0;
	for(int i=2;i<=M;++i){
		void (*opt)(int&,int);
		if(win[i]){
			opt=minimize;
			f[i]=maxn+1;
		}
		else{
			opt=maximize;
			f[i]=-1;
		}
		for(int j=0;pp[j]<=i;++j){
			if(win[i]!=win[i-pp[j]]){
				opt(f[i],f[i-pp[j]]);
			}
		}
		f[i]++;
	}
	for(int i=0;i<N;++i){
		if(win[Q[i]])
			printf("%d\n",f[Q[i]]);
		else
			puts("-1");
	}
}
