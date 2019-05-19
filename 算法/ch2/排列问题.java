	public static void swap(int []list,int k,int i)
	{
		int t;
		t=list[k];list[k]=list[i];list[i]=t;
	}
	
	public static void perm(int []list,int k,int m)
	{
		if(k==m)
		{
			for(int i=0;i<=m;i++)
				System.out.print(list[i]);
			System.out.println();
		}
		else
		{
			for(int i=k;i<=m;i++)
			{
				swap(list,k,i);
				perm(list,k+1,m);
				swap(list,k,i);
			}
		}
	}