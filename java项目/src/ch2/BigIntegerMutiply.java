package ch2;
import java.util.Arrays;
import java.util.Scanner;

public class BigIntegerMutiply {
	
	static char[] toBinary(int temp,int n)
	{	
	    char []t=new char[n+2];
	    t[n+1]='\0';
	    int i;
	    for(i=n;temp>0;i--)
	    {
	    	t[i]=(char)(temp%2+'0');
	    	temp=temp/2;
	    }
	    for(;i>=0;i--)
	        t[i]='0';
	    return t;
	}

	static char[] Add(char []a,char []b,int flag)
	{
		int n=a.length;
		if(a.length>b.length)
		{
			int i,j;
			char []b1=new char[n+1];
			for(i=n,j=b.length;j>0;i--,j--)
			    b1[i]=b[j];
			for(;i>0;i--)
			    b1[i]='0';
			b1[0]=b[0];
			b=b1;
		}
		if(a.length<b.length)
		{
			n=b.length;
			char []a1=new char[n+1];
			int i,j;
			for(i=n,j=a.length;j>0;i--,j--)
			    a1[i]=a[j];
			for(;i>0;i--)
			    a1[i]='0';
			a1[0]=a[0];
			a=a1;
		}
		//output(a);
		//output(b);
		if(flag==1)//进行加法运算
		{
			if(a[0]!=b[0])//不同符号的加法运算会处理为减法
			{
				char []c;
			    if(a[0]=='1')
			    {
			    	b[0]='1';
			    	c=Add(a,b,0);
			    }    
			    else
			    {
			    	a[0]='1';
				    c=Add(b,a,0);
				} 
			    return c;
			}		 
			else if(a[0]=='0'&&b[0]=='0')
			{
				a[0]='1';
				b[0]='1';
				char []c=Add(a,b,1);
				c[0]='0';
				return c;
				
			}
			else
			{
				char []c=new char[n+2];
			    c[0]=a[0];
		    	for(int i=1;i<n;i++)
		    	    c[i]='0';
			    c[n]='\0';
		    	for(int i=n-1;i>0;i--)
			    {
			    	if(a[i]+b[i]+c[i]-3*'0'>=2)
			    	{
			    		c[i-1]+=1;
			    	    c[i]+=a[i]+b[i]-2*'0'-2;
			    	}
				    else
				        c[i]+=a[i]+b[i]-2*'0';    
			    }
			    //output(c);
			    //接下来处理进位问题
			    if(a[0]==c[0]) //符号没发生变化时，直接返回指针c 
			        return c;
			    else           //符号发生变化时，加一位 
			    {
			    	char []d=new char[n+2];
			    	d[0]=a[0];
			    	d[1]='1';
			    	for(int i=2;i<=n;i++)
			            d[i]=c[i-1];
			        d[n+1]='\0';
					//output(d);
			        return d;
			    } 
			}
			
		}
		else  //进行减法运算
		{
			if(a[0]=='1'&&b[0]=='1')  //两个正数相减 
			{
				//比较大小，确定符号
				char []c=new char[n+1];
				c[0]=a[0];
		    	for(int i=1;i<n;i++)
		    	    c[i]='0';
			    c[n]='\0';
			    int i;
			    for(i=1;i<n;i++)
			    {
			    	if(a[i]>b[i])
			    	{
			    		c[0]='1';
			    		break;
			    	}
			    	if(a[i]<b[i])
			    	{
			    		c[0]='0';
			    		break;
			    	}
			    }
			    if(i==n)
			    {
					return c;
			    }    
			    else
			    {
				    if(c[0]=='1')
			    	{
			    	    for(int j=n-1;j>0;j--)
			    	    {	
			    	        if(a[j]>=b[j])
					    	{
					    		c[j]=(char)(a[j]-b[j]+'0');
					    	}    
			    	        else
					    	{
				    			a[j-1]-=1;
				    			c[j]=(char)((b[j]-a[j])%2+'0');
				    		}													    
			        	}
						return c;
			        }else
			        {
			            for(int j=n-1;j>0;j--)
			    	    {	
			    	        if(b[j]>=a[j])
					    	    c[j]=(char)(b[j]-a[j]+'0');
			    	        else
					    	{
				    			b[j-1]-=1;
				    			c[j]=(char)((a[j]-b[j])%2+'0');
				    		}	    
			        	}
			        	return c;
			    	}
			    }
			}
			else if(a[0]=='1'&&b[0]=='0')  //正数减负数
			{
				b[0]='1';
				char []c=Add(a,b,1); 
				return c;
			}
			else if(a[0]=='0'&&b[0]=='1')  //负数减正数
			{
				a[0]='1';
				char []c =Add(a,b,1);
				c[0]='0';
				return c;
			} 
			else   //负数减负数(a[0]=='0'&&b[0]=='0')
			{
				a[0]='1';
				b[0]='1'; 
				char []c =Add(b,a,0);
				return c;
			} 
		} 
	}


	static char[] Mutliply(char[] X, char[] Y,int n)
	{
		if(n<=4)
		{
			int x=0,y=0;
			for(int i=n;i>0;i--)
			{
				x+=(X[i]-'0')*(int)Math.pow(2.0,n-i);
			}
			for(int i=n;i>0;i--)
			{
				y+=(Y[i]-'0')*(int)Math.pow(2.0,n-i);
			}
			int temp=x*y;
			char []t=toBinary(temp,2*n);
			if(X[0]==Y[0])
			    t[0]='1';
			else
			    t[0]='0';
			return t; 
		} 
		else
		{
			char []a;
			char []b;
			char []c;
			char []d;
			a=new char[n/2+2];
			b=new char[(n+1)/2+2];
			c=new char[n/2+2];
			d=new char[(n+1)/2+2];
			a[0]=X[0];
			for(int i=1;i<(n/2+1);i++)
			{
				a[i]=X[i];
			}
			a[n/2+1]='\0';
			b[0]=X[0];
			
			for(int i=1;i<((n+1)/2+1);i++)
			{
				b[i]=X[i+n/2];
			}
			b[(n+1)/2+1]='\0';
			c[0]=Y[0];
			for(int i=1;i<(n/2+1);i++)
			{
				c[i]=Y[i];
			}
			c[n/2+1]='\0';
			d[0]=Y[0];
			for(int i=1;i<((n+1)/2+1);i++)
			{
				d[i]=Y[i+n/2];
			}
			d[(n+1)/2+1]='\0';
			//output(X);
			//output(Y);
			//output(a);
			//output(b);
			//output(c);
			//output(d);
			char []AC=Mutliply(a,c,n/2);
			//output(AC);
			char []BD=Mutliply(b,d,(n+1)/2);
			//output(BD);
			char []s1=Add(a,b,0);
			//output(s1);
			char []s2=Add(d,c,0);
			//output(s2);
			int flag=1;
			if((s1[0]=='0'&&s2[0]=='1')||(s1[0]=='1'&&s2[0]=='0'))
				flag=0;
			s1[0]='1';
			s2[0]='1';
			char []ABCD=Mutliply(s1,s2,(n+1)/2);
			if(flag==0)
				ABCD[0]='0';
			//output(ABCD);
			char []t1=new char[AC.length+(n+1)/2*2];
			int len1=AC.length;
			t1[len1+(n+1)/2*2]='\0';
			for(int i=len1+(n+1)/2*2-1;i>=len1;i--)
			    t1[i]='0';
			for(int i=0;i<len1;i++)
			    t1[i]=AC[i]; 
			//output(t1);
			       
			char []t2=Add(AC,BD,1);              //output(t2);    
			char []t3=Add(ABCD,t2,1);            //output(t3);   
			char []t4=new char[t3.length+(n+1)/2+1]; 
			int len2=t3.length;
			t4[len2+(n+1)/2]='\0';
			for(int i=len2+(n+1)/2-1;i>=len2;i--)
			    t4[i]='0';
			for(int i=0;i<len2;i++)
			    t4[i]=t3[i]; 
			//output(t4); 
			char []t5=Add(t1,t4,1);     //output(t5);          
			char []t6=Add(t5,BD,1);	
			//output(t6);              
			return t6;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char []X;
		char []Y;
		Scanner scanner = new Scanner(System.in);
		while(true){
		System.out.print("请输入第一个大整数：");
		X = scanner.nextLine().toCharArray();
		System.out.print("请输入第二个大整数：");
		Y = scanner.nextLine().toCharArray();
		
		int xlen=X.length;
		int ylen=Y.length;
		int n=xlen;
		if(xlen>ylen)
		{
			int i,j;
			char []Y1=new char[xlen+1];
			for(i=xlen,j=ylen;j>0;i--,j--)
			{
				Y1[i]=Y[j];
			}
			for(;i>0;i--)
			    Y1[i]='0';
			Y1[0]=Y[0];
			Y=Y1;
		}
		if(xlen<ylen)
		{
			int i,j;
			char []X1=new char[ylen+1];
			
			for(i=ylen,j=xlen;j>0;i--,j--)
			{
				X1[i]=X[j];
			}
			for(;i>0;i--)
			    X1[i]='0';
			X1[0]=X[0];
			X=X1;
			n=ylen;
		}
		//printf("%s\n%s\n",X1,Y1);
		//printf("%s+%s=%s\n", X,Y,Hexadecimal_conversion(&Add(X1,Y1,1)[1],2,10));
		//printf("%s+%s=%s\n", X,Y,Add(X1,Y1,1)); 
		char []res=Mutliply(X, Y,n-1);
	}
	}
	
}
