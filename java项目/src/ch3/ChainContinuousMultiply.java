package ch3;

public class ChainContinuousMultiply {
    public static void matrixChain(int []p,int [][]m,int [][]s){
        int n=p.length-1;
        for(int i=1;i<=n;i++) m[i][i]=0;
        for(int r=2;r<=n;r++)
        {
        	for(int i=1;i<=n-r+1;i++)
        
            {
                int j=i+r-1;
                m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
                s[i][j]=i;
		        for(int k=i+1;k<j;k++)
		        {
		        	int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
			        if(t<m[i][j])
		        	{
			        	m[i][j]=t;
			        	s[i][j]=k;
		        	}
		        }
            }
        }
    }
    
    public static void traceback(int [][]s,int i,int j){
        if(i==j) return;
        traceback(s,i,s[i][j]);
        traceback(s,s[i][j]+1,j);
        System.out.println("Multiply A"+i+","+s[i][j]+"and A"+(s[i][j]+1)+","+j);
    }
    

    
    
    public static void main(String[] args) {
        // TODO code application logic here
        int []p={30,35,15,5,10,20,25};
		int[][]m=new int[7][7];int[][] s=new int[7][7];
                
		matrixChain(p,m,s);
		
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<7;j++)
				System.out.print(m[i][j]+" ");
			System.out.print("\n");
		}
                System.out.print("\n");
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<7;j++)
				System.out.print(s[i][j]+" ");
			System.out.print("\n");
		}
                traceback(s,1,6);
    }
    
}

