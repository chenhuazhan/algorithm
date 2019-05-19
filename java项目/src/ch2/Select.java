package ch2;

public class Select {
	
	
	
	private static int select(int []a,int p,int r,int k)
	{
		if(r-p<5){
			sort(a,p, r);
			return a[p+k-1];
		}
		
		/*
		*将a[p+5*i]至a[p+5*i+4]的第3小元素与a[p+i]交换位置；
		*找中位数的中位数，r-p-4即上面说的n-5
		*/
		
		for(int i=0;i<=(r-p-4)/5;i++)
		{
			int s=p+5*i,t=s+4;
			for(int j=0;j<3;j++)
				sort(a,s,t-j);
			swap(a,p+i,s+2);
		}
		
		int x=select(a,p,p+(r-p-4)/5,(r-p+6)/10);
		int i=partition(a,p,r,x);
		int j=i-p+1;
		if(k<=j)return select(a,p,i,k);
		else return select(a,i+1,r,k-j);
	}
	
	public static int partition(int []a,int p,int r,int x)
	{
		int i=p,j=r+1;
		while(true)
		{
			while(a[++i]<x&&i<r);
			while(a[--j]>x);
			if(i>=j)break;
			RandomizedQuickSort.swap(a,i,j);
		}
		a[p]=a[j];
		a[j]=x;
		return j;
	}
	
	public static void sort(int []a,int p,int r){
		int t;
		for(int i=0;i<r-p;i++)
			for(int j=i;j<r-p;j++)
				if(a[j]<a[i])
				{
					t=a[i];
					a[i]=a[j];
		            a[j]=t;
				}
	}
	
	public static void swap(int []a,int i,int j)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int []a={3,2,1,5,4,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		System.out.println(select(a,0,19,4));
		for(int i=0;i<20;i++){
			System.out.print(a[i]+" ");
		}
	}

}
