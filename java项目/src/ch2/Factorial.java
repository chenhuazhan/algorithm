package ch2;
import java.util.Scanner;
/*
 * 求数n的阶乘
 */

public class Factorial {
	
	public static int fun(int n){
		if(n==0)return 1;
		return n*fun(n-1);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner=new Scanner(System.in);
		System.out.println("请输入一个非负整数：");
		int n=scanner.nextInt();		
		System.out.println(n+"的阶乘是:"+fun(n));
		scanner.close();
	}

}
