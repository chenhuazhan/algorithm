/*
*递归方法，其中merge合并两个排好序的数组段到新的数组b中，
*算法copy将合并后的数组段再复制回数组a中
*/
public static void mergeSort(int []a,int left,int right)
{
	if(left<right){
		int i=(left+right)/2;
		mergeSort(a,left,i);
		mergeSort(a,i+1,right);
		merge(a,b,left,i,right);
		copy(a,b,left,right);
	}
}

//非递归

public static void mergeSort(int []a)
{
	int []b=new int[a.length];
	int s=1;
	while(s<a.length){
		mergePass(a,b,s);
		s+=s;
		mergePass(b,a,s);
		s+=s;
	}
}
public static void mergePass(int []x,int []y,int s)
{
	int i=0;
	while(i<=x.length-2*s){
		merge(x,y,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}
	if(i+s<x.length)
		merge(x,y,i,i+s-1,x.length-1);
	else 
		for(int j=i;j<x.length;j++)
			y[j]=x[j];
}

public static void merge(int []c,int []d,int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	while((i<=m)&&(j<=r))
		if(c[i]<=c[j])
			d[k++]=c[i++];
		else
			d[k++]=c[j++];
		if(i>m)
			for(int q=j;q<=r;q++)
				d[k++]=c[q];
		else
			for(int q=i;q<=r;q++)
				d[k++]=c[q];
}