public static void traceback(int [][]s,int i,int j)
{
    if(i==j) return;
    traceback(s,i,s[i][j]);
    traceback(s,s[i][j]+1,j);
    System.out.println("Multiply A"+i+","+s[i][j]+"and A"+(s[i][j]+1)+","+j);
}