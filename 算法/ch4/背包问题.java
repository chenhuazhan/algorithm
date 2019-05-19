public static float knapsack(float c,float [] w, float [] v,float [] x)
   {
      int n=v.length;
      Element [] d = new Element [n];
      for (int i = 0; i < n; i++) d[i] = new Element(w[i],v[i],i);
      MergeSort.mergeSort(d);
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