package ch2;

public class RandomizedSelect {
	
	private static int randomizedSelect(int []a,int p,int r,int k)
	{
		if(p==r)return a[p];
		int i=RandomizedQuickSort.randomizedPartition(a,p,r);
		int j=i-p+1;
		if(k<=j)return randomizedSelect(a,p,i,k);
		else return randomizedSelect(a,i+1,r,k-j);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int []a={1,2,3,4,5,6,7};
		System.out.println(randomizedSelect(a,0,6,4));
	}

}
