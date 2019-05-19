package ch2;

import java.util.Scanner;

/*
 * Fibonacci数列
 */
public class Fibonacci {
	
	public static int fun(int n){
		if(n<=1)return 1;
		return fun(n-1)+fun(n-2);
	}
	
	public static void main(String[] args){
		Scanner scanner=new Scanner(System.in);
		System.out.print("请输入一个非负整数：");
		int n=scanner.nextInt();		
		System.out.println(fun(n));
		scanner.close();
	}
}
