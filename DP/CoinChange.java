import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class CoinChange
{
    public static int findCoins(int arr[],int sum,int n)
    {
        int dp[][]=new int[n+1][sum+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(i==0 && j!=0)
                    dp[i][j]=0;
                else if(j==0)
                    dp[i][j]=1;
                else if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+ dp[i][j-arr[i-1]];
                else 
                    dp[i][j]=dp[i-1][j];
            }
        return dp[n][sum];
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int p[]=new int[n];
		for(int j=0;j<n;j++)
			p[j]=sc.nextInt();
		int sum=sc.nextInt();
		System.out.println(findCoins(p,sum,n));
    }
}