package ch2;

public class BinarySearch {
    
	public static int binarySearch(int []a,int x,int n)
	{
		int left=0,right=n-1;
		while(left<=right){
			int middle=(left+right)/2;
			if(x==a[middle]) 
				return middle;
			if(x>a[middle]) 
				left=middle+1;
			else right=middle-1;
		}
		return -1;
	}
	
	public static int binarySearch1(int []a,int x,int n)
	{
		if(n>0&&x>=a[0])
		{
		    int left=0,right=n-1;
		    while(left<right)
		    {
			    int middle=(left+right+1)/2;
			    if(x<a[middle]) 
				    right=middle-1;
			    else 
			    	left=middle;
		    }
		    if(x==a[left])
			    return left;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a={3,6,9,12,15,18,21,24,27,30};
		System.out.println(binarySearch(a,12,10));
		System.out.println(binarySearch1(a,12,10));
	}

}
