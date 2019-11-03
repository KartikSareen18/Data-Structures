import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class SubsetSum
{
    public static boolean subset(int arr[],int sum)
    {
        int n=arr.length;
        boolean dp[][]=new boolean[n+1][sum+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(i==0 && j!=0)
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
                else if (arr[i-1]<=j)
                    dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else 
                    dp[i][j]=dp[i-1][j];
            } 
        
        return dp[n][sum];
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        int sum=sc.nextInt();
        System.out.println(subset(arr,sum));
    }
}