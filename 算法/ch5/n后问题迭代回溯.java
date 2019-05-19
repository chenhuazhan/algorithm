public class NQueen2
{
	static int n;    //皇后个数
	static int []x;  //当前解
	static long sum; //当前已找到的可行方案数
	
	public static long nQueen(int nn)
	{
		n=nn;
		sum=0;
		x=new int[n+1];
		for(int i=0;i<=n;i++)
		    x[i]=0;
		backtrack(1);
		return sum;
	}
	
	public static boolean place(int k)
	{
		for(int j=1;j<k;j++)
		{
			if((Math.abs(k-j)==Math.abs(x[j]-x[k]))||(x[j]==x[k]))
				return false;
		}
		return true;
	}
	
	public static void backtrack(int t)
	{
		x[1]=0;
		int k=1;
		while(k>0){
			x[k]+=1;
			while((x[k]<=n)&&!(place(k)))
				x[k]+=1;
			if(x[k]<=n)
				if(k==n)
					sum++;
				else
				{
				    k++;
				    x[k]=0;
			    }
			else
				k--;
		}
	}
}