package ch2;
import java.util.Scanner;
/*
 * ����n�Ľ׳�
 */

public class Factorial {
	
	public static int fun(int n){
		if(n==0)return 1;
		return n*fun(n-1);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner=new Scanner(System.in);
		System.out.println("������һ���Ǹ�������");
		int n=scanner.nextInt();		
		System.out.println(n+"�Ľ׳���:"+fun(n));
		scanner.close();
	}

}
