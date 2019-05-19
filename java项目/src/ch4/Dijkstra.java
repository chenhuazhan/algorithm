package ch4;

public class Dijkstra {
	public static void dijkstra(int v,float [][]a,float []dist,int []prev)
	{
		int n=dist.length-1;
		if(v<1||v>n)return ;
		
		boolean []s=new boolean[n+1];
		//初始化
		for(int i=1;i<=n;i++)
		{
			dist[i]=a[v][i];
			s[i]=false;
			if(dist[i]==Float.MAX_VALUE)prev[i]=0;
			else prev[i]=v;
		}
		dist[v]=0;
		s[v]=true;
		
		for(int i=1;i<n;i++){
			float temp=Float.MAX_VALUE;
			int u=v;
			for(int j=1;j<=n;j++)
				if((!s[j])&&(dist[j]<temp)){
					u=j;
					temp=dist[j];
				}
			s[u]=true;
			for(int j=1;j<=n;j++)
				if((!s[j])&&(a[u][j]<Float.MAX_VALUE)){
					float newdist=dist[u]+a[u][j];
					if(newdist<dist[j]){
						//dist[j]减少
						dist[j]=newdist;
						prev[j]=u;
					}
				}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int v=1;
		float [][]a={
				{0,0,0,0,0,0},
				{0,0,10,Float.MAX_VALUE,30,100},
				{0,Float.MAX_VALUE,0,50,Float.MAX_VALUE,Float.MAX_VALUE},
				{0,Float.MAX_VALUE,Float.MAX_VALUE,0,Float.MAX_VALUE,10},
				{0,Float.MAX_VALUE,Float.MAX_VALUE,20,0,60},
				{0,Float.MAX_VALUE,Float.MAX_VALUE,Float.MAX_VALUE,Float.MAX_VALUE,0}
		};
		
		float []dist=new float[6];
		int []prev=new int[6];
		dijkstra(v,a,dist,prev);
		for(int i=1;i<6;i++)
			System.out.print(prev[i]+" ");
		System.out.println();
		for(int i=1;i<6;i++)
			System.out.print(dist[i]+" ");
		System.out.println();
		int s[]=new int[6];
		int i=0;
		for(int j=5;j!=1;j=prev[j],i++)
			s[i]=j;
		s[i]=1;
		System.out.print("从顶点1到5的最短路径为：");
		for(;i>0;i--)
			System.out.print(s[i]+"->");
		System.out.println("5");
	}

}
