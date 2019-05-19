package ch3;

public class improve_zero_onePack {
	public static double knapsack(double []w,double []v,double c,double [][]p,int []head)
	{
		int n=v.length-1;
		head[n+1]=0;
		p[0][0]=0;
		p[0][1]=0;
		int left=0,right=0,next=1;
		head[n]=1;
	    for(int i=n; i>=1; i--)
	    {
	        int k = left;
	        for(int j=left; j<=right; j++)
	        {
	            if(p[j][0]+w[i]>c) break;
	            double y = p[j][0] + w[i],m = p[j][1] + v[i];
	            while(k<=right && p[k][0]<y)
	            {
	                p[next][0]=p[k][0];
	                p[next++][1]=p[k++][1];
	            }
	            if(k<=right && p[k][0]==y)
	            {
	                if(m<p[k][1])
	                {
	                    m=p[k][1];
	                }
	                k++;
	            }
	            if(m>p[next-1][1])
	            {
	                p[next][0]=y;
	                p[next++][1]=m;
	            }
	            while(k<=right && p[k][1]<=p[next-1][1])
	            {
	                k++;
	            }
	        }
	        while(k<=right)
	        {
	            p[next][0]=p[k][0];
	            p[next++][1]=p[k++][1];
	        }
	        left = right + 1;
	        right = next - 1;
	        head[i-1] = next;
	    }
	    return p[next-1][1];
	}

	public static void traceback(double []w,double []v,double [][]p,int []head,int []x)
	{
		int n=w.length-1;
		double j = p[head[0]-1][0],m=p[head[0]-1][1];
	    for(int i=1; i<=n; i++)
	    {
	        x[i]=0;
	        for(int k=head[i+1]; k<=head[i]-1; k++)
	        {
	            if(p[k][0]+w[i]==j && p[k][1]+v[i]==m)
	            {
	                x[i]=1;
	                j=p[k][0];
	                m=p[k][1];
	                break;
	            }
	        }
	    }
	}


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int c=10;
		int n=6;
	    double[] w={0,2,2,6,5,4};
	    double[] v={0,6,3,5,4,6};
	    int[] x=new int[n];
	    double [][]p=new double[30][2];
	    int []head=new int[n+1];
	    System.out.println(knapsack(w,v,c,p,head));
	    traceback(w,v,p,head,x);
	    for(int i=1;i<n;i++)
	    	System.out.print(x[i]+" ");
	    System.out.print("\n");
	    for(int i=0;i<30;i++)
	    {
	    	for(int j=0;j<2;j++)
	    	    System.out.print(p[i][j]+" ");
	        System.out.print("\n");
	    }   
	}

}
