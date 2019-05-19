public class Knapsack
{
	private static class Element implements Comparable
	{
		int id;                      //物品编号
		double d;
		
		private Element(int idd,double dd)
		{
			id=idd;
			d=dd;
		}
		
		public int compareTo(Object x)
		{
			double xd=((Element) x).d;
			if(d<xd)return -1;
			if(d==xd)return 0;
			return 1;
		}
		
		public boolean equals(Object x)
		{
			return d==((Element) x).d;
		}
	}
	
	static double c;                 //背包容量
	static int n;                    //物品数
	static double []w;               //物品重量数组
	static double []p;               // 物品价值数组
	static double cw;                //当前重量
	static double cp;                //当前价值
	static double bestp;             //当前最优价值
	
	public static double knapsack(double []pp,double []ww,double cc)
	{
		c=cc;
		n=pp.length-1;
		cw=0.0;
		cp=0.0;
		bestp=0.0;
		
		
		//q为单位重量价值数组
		Element []q=new Element[n];
		
		
		//初始化q[0:n-1]
		for(int i=1;i<=n;i++)
			q[i-1]=new Element(i,pp[i]/ww[i]);
		
		
		//将各物品依单位重量价值从大到小排序
		MergeSort.mergeSort(q);
		
		
		p=new double[n+1];
		w=new double[n+1];
		for(int i=1;i<=n;i++)
		{
			p[i]=pp[q[n-i].id];
			w[i]=ww[q[n-i].id];
		}
		backtrack(1);
		return bestp;
	}
	
	private static void backtrack(int i)
	{
		if(i>n)
		{//到达叶节点
	        bestp=cp;
			return;
		}
		
		//搜索子树
		if(cw+w[i]<=c)
		{//进入左子树
			cw+=w[i];
			cp+=p[i];
			backtrack(i+1);
			cw-=w[i];
			cp-=p[i];
		}
		
		if(bound(i+1)>bestp)
			backtrack(i+1);    //进入右子树
	}
	
	private static double bound(int i)
	{//计算上界
		double cleft=c-cw;    //剩余容量
		double bound=cp;
		//以物品单位重量价值递减顺序装入物品
		while(i<=n&&w[i]<=cleft)
		{
			cleft-=w[i];
			bound+=p[i];
			i++;
		}
		
		//装满背包
		if(i<=n)
			bound+=p[i]*cleft/w[i];
		return bound;
	}
}
			