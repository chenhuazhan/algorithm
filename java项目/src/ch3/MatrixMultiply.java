package ch3;

public class MatrixMultiply {
	
	//ra、rb为行数，ca、cb为列数
	public static void matrixMultiply(int [][]a,int [][]b,int [][]c,int ra,int ca,int rb,int cb)
	{
		if(ca!=rb)
			throw new IllegalArgumentException("矩阵不可乘");
		for(int i=0;i<ra;i++)
			for(int j=0;j<cb;j++){
				int sum=a[i][0]*b[0][j];
				for(int k=1;k<ca;k++)
					sum+=a[i][k]*b[k][j];
				c[i][j]=sum;
			}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [][]a={{1,2,1},{3,2,1}};
		int [][]b={{1,2},{1,1},{2,3}};
		int [][]c=new int[2][2];
		matrixMultiply(a,b,c,2,3,3,2);
		for(int i=0;i<2;i++)
		{	for(int j=0;j<2;j++)
				System.out.print(c[i][j]+" ");
		    System.out.println();
		}
	}

}
