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