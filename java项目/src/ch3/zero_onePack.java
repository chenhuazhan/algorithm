package ch3;

import java.util.Scanner;

public class zero_onePack {
	public static void knapsack(int []v,int []w,int c,int [][]m)
	{
		int n=v.length-1;
		int jMax=Math.min(w[n]-1,c);
		for(int j=0;j<=jMax;j++)
			m[n][j]=0;
	    
		for(int j=w[n];j<=c;j++)
			m[n][j]=v[n];
	    
		for(int i=n-1;i>1;i--){
			jMax=Math.min(w[i]-1,c);
			for(int j=0;j<=jMax;j++)
				m[i][j]=m[i+1][j];
			for(int j=w[i];j<=c;j++)
				m[i][j]=Math.max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
		}
	    
		m[1][c]=m[2][c];
		if(c>=w[1])
			m[1][c]=Math.max(m[1][c],m[2][c-w[1]]+v[1]);
	}

	public static void traceback(int [][]m,int []w,int c,int []x)
	{
		int n=w.length-1;
		for(int i=1;i<n;i++)
			if(m[i][c]==m[i+1][c])x[i]=0;
		    else
			{
				x[i]=1;
				c-=w[i];
			}
			x[n]=(m[n][c]>0)?1:0;
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    
	    Scanner scanner=new Scanner(System.in);
	    System.out.print("请输入背包容量：");
		int c=scanner.nextInt();
		System.out.print("请输入物品个数：");
		int n=scanner.nextInt();
		int[] w=new int[n+1];     //物品重量数组
		int[] v=new int[n+1];     //物品价值数组
		int[] x=new int[n+1];
	    int[][]m = new int[n+1][c+1];
	    System.out.print("请输入各个物品的重量(以空格分开):");
	    for(int i=1;i<n+1;i++)
	    	w[i]=scanner.nextInt();
	    System.out.print("请输入各个物品的价值(以空格分开):");
	    for(int i=1;i<n+1;i++)
	    	v[i]=scanner.nextInt();
	    scanner.close();
	    knapsack(v,w,c,m);
	    System.out.println("最优值为："+m[1][c]);
//	    System.out.println("打印数组m：");
//	    for(int i=1;i<n;i++)
//	    {
//	    	for(int j=1;j<c+1;j++)
//	    	    System.out.print(m[i][j]+" ");
//	        System.out.print("\n");
//	    }    
	    System.out.print("\n");
	    traceback(m,w,c,x);
	    System.out.println("最优解为：");
	    for(int i=1;i<n+1;i++)
	    	System.out.print(x[i]+" ");
	}

}

