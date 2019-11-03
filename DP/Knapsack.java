import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class Knapsack
{
    public static int findProfit(int p[],int w[],int c)
    {
        int n=p.length;
        int arr[][]=new int[n+1][c+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=c;j++)
            {
                if(i==0 || j==0)
                    arr[i][j]=0;
                else if(w[i-1]>j)
                    arr[i][j]=arr[i-1][j];
                else
                    arr[i][j]=Math.max(arr[i-1][j-w[i-1]]+p[i-1],arr[i-1][j]);
            }
            return arr[n][c];
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int p[]=new int[n];
        int w[]=new int[n];
        for(int i=0;i<n;i++)
            p[i]=sc.nextInt();
        for(int i=0;i<n;i++)
            w[i]=sc.nextInt();
        int c=sc.nextInt();
        System.out.println(findProfit(p,w,c));
    } 
}
