package ch2;

import java.util.Random;

public class RandomizedQuickSort {
	
	public static void randomizedQuickSort(int []a,int p,int r){
		if(p<r){
			int q=randomizedPartition(a,p,r);
			randomizedQuickSort(a,p,q-1);
			randomizedQuickSort(a,q+1,r);
		}
	}
	
	public static int randomizedPartition(int []a,int p,int r){
		int i=random(p,r);
		swap(a,i,p);
		return partition(a,p,r);
	}
	
	public static int partition(int []a,int p,int r)
	{
		int i=p,j=r+1;
		int x=a[p];
		while(true)
		{
			while(a[++i]<x&&i<r);
			while(a[--j]>x);
			if(i>=j)break;
			swap(a,i,j);
		}
		a[p]=a[j];
		a[j]=x;
		return j;
	}
	
	public static void swap(int []a,int i,int j)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	
    public static int random(int min,int max) {
        Random random = new Random();
        int s = random.nextInt(max)%(max-min+1) + min;
        return s;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int []a={3,5,7,4,6,9,8};
		randomizedQuickSort(a,0,6);
		for(int i=0;i<7;i++){
			System.out.print(a[i]+" ");
		}
	}
}
