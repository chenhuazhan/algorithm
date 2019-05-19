private static int randomizedSelect(int p,int r,int k)
{
	if(p==r)return a[p];
	int i=randomizedpartition(p,r);
	int j=i-p+1;
	if(k<=j)return randomizedSelect(p,i,k);
	else return randomizedSelect(i+1,r,k-j);
}
