package ch3;
//µİ¹é¾ØÕóÁ¬³Ë

public class RecurMatrixChain {
    
    public static int recurMatrixChain(int []p,int [][]s,int i,int j){
        if(i==j) return 0;
        int u=recurMatrixChain(p,s,i+1,j)+p[i-1]*p[i]*p[j];
        s[i][j]=i;
        for(int k=i+1;k<j;k++){
            int t=recurMatrixChain(p,s,i+1,k)+recurMatrixChain(p,s,k+1,j)+p[i-1]*p[k]*p[j];
            if(t<u){
                u=t;
                s[i][j]=k;
            }
        }
        return u;
    } 
    public static void main(String[] args) {
    	int []p={30,35,15,5,10,20,25};
    	int[][]s=new int[7][7];
        System.out.println(recurMatrixChain(p,s,1,4));
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<7;j++)
				System.out.print(s[i][j]+" ");
			System.out.print("\n");
		}
    }
}
