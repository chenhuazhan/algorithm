public static float loading(float c, float [] w, int [] x)
   {
      int n=w.length;
      Element [] d = new Element [n];
      for (int i = 0; i < n; i++)
        d[i] = new Element(w[i],i);
      MergeSort.mergeSort(d);
      float opt=0;
      for (int i = 0; i < n; i++) x[i] = 0;
      for (int i = 0; i < n && d[i].w <= c; i++) {
         x[d[i].i] = 1;
         opt+=d[i].w;
         c -= d[i].w;
         }
      return opt;
   }