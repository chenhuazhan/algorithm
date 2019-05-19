private static int select(int p,int r,int k)
{
	if(r-p<5){
		bubbleSort(p,r);
		return a[p+k-1];
	}
	
	/*
	*将a[p+5*i]至a[p+5*i+4]的第3小元素与a[p+i]交换位置；
	*找中位数的中位数，r-p-4即上面说的n-5
	*/
	
	for(int i=0;i<=(r-p-4)/5;i++)
	{
		int s=p+5*i，
		    t=s+4;
		for(int j=0;j<3;j++)
			bubble(s,t-j);
		swap(a,p+i,s+2);
	}
	
	int x=select(p,p+(r-p-4)/5,(r-p+6)/10);
	int i=partition(p,r,x);
	int j=i-p+1;
	if(k<=j)return select(p,i,k);
	else return select(i+1,r,k-j);
}