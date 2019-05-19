package ch4;

import java.util.Scanner;

public class GreedySelector {
	public static int greedySelector(int []s, int []f, boolean a[])
	{
	    int n=s.length-1;
	    a[1]=true;
	    int j=1;
	    int count=1;
	    for(int i=2;i<=n;i++) {
	        if(s[i]>=f[j]) {
	            a[i]=true;
	            j=i;
	            count++;
	        }
	        else a[i]=false;
	    }
	    return count;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scanner=new Scanner(System.in);
	    System.out.print("������������");
		int n=scanner.nextInt();
		int []s=new int[n+1];
		int []f=new int[n+1];
		boolean a[]=new boolean[n+1];
		
	    System.out.print("�����������Ŀ�ʼʱ��(�Կո�ֿ�):");
	    for(int i=1;i<n+1;i++)
	    	s[i]=scanner.nextInt();
	    System.out.print("�����������Ľ���ʱ��(�Կո�ֿ�):");
	    for(int i=1;i<n+1;i++)
	    	f[i]=scanner.nextInt();
	    scanner.close();
	    System.out.print("���ɰ���"+greedySelector(s,f,a)+"������ֱ��ǣ�");
	    for(int i=1;i<n+1;i++)
	    	if(a[i]==true)System.out.print(i+" ");
	}

}
