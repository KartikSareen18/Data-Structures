import java.util.*;

class LongestCommonSubsequence
{
    public static int lcs(char a[],char b[])
    {
        int m=a.length;
        int n=b.length;
        int arr[][]=new int[m+1][n+1];
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
            {
                if(i==0 ||j==0)
                    arr[i][j]=0;
                else if(a[i-1]==b[j-1])
                    arr[i][j]=1+arr[i-1][j-1];
                else 
                    arr[i][j]=Math.max(arr[i-1][j],arr[i][j-1]);
            }
        return arr[m][n];
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String a=sc.nextLine();
        String b=sc.nextLine();
        char x[]=a.toCharArray();
        char y[]=b.toCharArray();
        System.out.println(lcs(x,y));
    }
}