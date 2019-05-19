package ch2;

public class IntegerDivision {
	public static int q(int n,int m)
	{
		if((n<1)||(m<1))return 0;
		if((n==1)||(m==1))return 1;
		if(n<m)return q(n,n);
		if(n==m)return q(n,m-1)+1;
		return q(n,m-1)+q(n-m,m);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(q(6,6));
	}

}
