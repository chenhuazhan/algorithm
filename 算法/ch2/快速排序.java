public static void qSort(int p,int r)
{
	if(p<r){
		int q=partition(p,r);
		qSort(p,q-1);              //对左半段排序
		qSort(q+1,r);              //对右半段排序
	}
}

public static int partition(int p,int r)
{
	int i=p,j=r+1;
	int x=a[p];
	while(true)
	{
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)break;
		swap(a,i,j);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}

public static void swap(int []a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
