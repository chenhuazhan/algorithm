#include <stdio.h>
int binarySearch(int *a,int x,int n)
{
	int left=0,right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle]) 
			return middle;
		if(x>a[middle]) 
			left=middle+1;
		else right=middle-1;
	}
	return -1;
}
int main()
{
	int a[10]={3,6,9,12,15,18,21,24,27,30};
	printf("%d\n",binarySearch(a,12,10));
}