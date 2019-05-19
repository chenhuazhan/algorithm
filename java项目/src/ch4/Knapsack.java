package ch4;

public class Knapsack {
	public static class Element implements Comparable{
		float w;
		float v;
		int i;
		public Element(float ww,float vv,int ii)
		{
			w=ww;
			v=vv;
			i=ii;
		}
		
		public int compareTo(Object x)
		{
			float xw=((Element) x).w;
			if(w<xw) return -1;
			if(w==xw) return 0;
			return 1;
		}
	}
	
	public static void Sort(Element []d)
	{
		int n=d.length;
		Element t;
		for(int j=0;j<n-1;j++)
			for(int i=j+1;i<n;i++)
			{
				if(d[j].compareTo(d[i])==1)
				{
					t=d[i];
					d[i]=d[j];
					d[j]=t;
				}
			}
	}
	
	public static float knapsack(float c,float []w,float []v,float []x){
		int n=v.length;
	    Element [] d = new Element [n];
	    for (int i = 0; i < n; i++) d[i] = new Element(w[i],v[i],i);
	    Sort(d);
	    int i;
	    float opt=0;
	    for (i=0;i<n;i++) x[i]=0;
	    for (i=0;i<n;i++) {
	        if (d[i].w>c) break;
	        x[d[i].i]=1;
	        opt+=d[i].v;
	        c-=d[i].w;
	    }
	    if (i<n){
	        x[d[i].i]=c/d[i].w;
	        opt+=x[d[i].i]*d[i].v;
	    }
	    return opt;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
