#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int maxn=128,maxm=1024;
char maze[maxn][maxn];
char query[maxm];
int N,M,X0,Y0;

void makemaze(){
	memset(maze,'*',sizeof(maze));
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			maze[i][j]=rand()%2?'.':'*';
	do{
		X0=rand()%N+1;
		Y0=rand()%N+1;
	}while(maze[X0][Y0]=='*');
	for(int i=0;i<N/10;++i){
		int x=rand()%N+1,y=rand()%N+1;
		int dx=rand()%3-1,dy=rand()%3-1;
		for(int k=0;k<N;++k){
			maze[x][y]='.';
			x+=dx;
			y+=dy;
			if(x<=0||x>N||y<=0||y>N)break;
		}
	}
}
void makequery(){
	const int dx[4]={-1,0,1,0};
	const int dy[4]={0,1,0,-1};
	int x=X0,y=Y0,d=0;
	for(int i=0;i<M;++i){
		char c;
		if(rand()%2){
			switch(rand()%6){
				case 0:
				case 1:
					if(maze[x+dx[d]][y+dy[d]]!='*'){
						c='F';
						x+=dx[d];
						y+=dy[d];
						break;
					}
				case 2:
				case 3:
					if(maze[x-dx[d]][y-dy[d]]!='*'){
						c='B';
						x-=dx[d];
						y-=dy[d];
						break;
					}
				case 4:
					c='R';
					d++;
					d%=4;
					break;
				case 5:
					c='L';
					if(d--==0)
						d=3;
					break;
			}
		}
		else{
			switch(rand()%8){
				case 0:
				case 1:
				case 2:
					c='F';
					break;
				case 3:
				case 4:
				case 5:
					c='B';
					break;
				case 6:
					c='L';
					break;
				case 7:
					c='R';
					break;
			}
		}
		query[i]=c;
	}
}
void makedata(int num){
	makemaze();
	makequery();
	
	freopen("robot.in","w",stdout);
	printf("%d %d %d %d\n",N,M,X0,Y0);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j)
			putchar(maze[i][j]);
		putchar('\n');
	}
	for(int i=0;i<M;++i){
		switch(query[i]){
			case 'F':
				puts("FORWARD");
				break;
			case 'B':
				puts("BACK");
				break;
			case 'L':
				puts("LEFT");
				break;
			case 'R':
				puts("RIGHT");
				break;
		}
	}
	fclose(stdout);
	
	system("robot");
	char order[20];
	sprintf(order,"rename robot.in robot%d.in",num);
	system(order);
	sprintf(order,"rename robot.out robot%d.out",num);
	system(order);
}
int main(){
	srand(time(0));
	const int Ns[]={10,20,30,40,50,60,70,80,90,100};
	const int Ms[]={10,20,50,100,200,500,700,800,900,1000};
	for(int i=0;i<10;++i){
		N=Ns[i];
		M=Ms[i];
		makedata(i);
	}
}
