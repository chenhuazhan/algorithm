package ch4;

import java.util.Scanner;

public class Loading {
	public static class Element implements Comparable{
		float w;
		int i;
		public Element(float ww,int ii)
		{
			w=ww;
			i=ii;
		}
		
		public int compareTo(Object x)
		{
			float xw=((Element) x).w;
			if(w<xw) return -1;
			if(w==xw) return 0;
			return 1;
		}
	}
	
	public static void Sort(Element []d)
	{
		int n=d.length;
		Element t;
		for(int j=0;j<n-1;j++)
			for(int i=j+1;i<n;i++)
			{
				if(d[j].compareTo(d[i])==1)
				{
					t=d[i];
					d[i]=d[j];
					d[j]=t;
				}
			}
	}
	
	public static float loading(float c,float []w,int []x)
	{
		int n=w.length;
		Element []d=new Element[n];
		for(int i=0;i<n;i++)
			d[i]=new Element(w[i],i);
		Sort(d);
		float opt=0;
		for(int i=0;i<n;i++) x[i]=0;
		for(int i=0;i<n&&d[i].w<=c;i++)
		{
			x[d[i].i]=1;
			opt+=d[i].w;
			c-=d[i].w;
		}
		return opt;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner=new Scanner(System.in);
		System.out.print("请输入轮船载重量：");
		float c=scanner.nextFloat();;
		System.out.print("请输入集装箱个数：");
		int n=scanner.nextInt();
		float []w=new float[n];
		int []x=new int[n];
		System.out.print("请输入各个集装箱重量：");
		for(int i=0;i<n;i++)
			w[i]=scanner.nextFloat();
		scanner.close();
		System.out.println("最优值为:"+loading(c,w,x));
		System.out.print("最优解为：");
		for(int i=0;i<n;i++)
			System.out.print(x[i]+" ");
	}

}
