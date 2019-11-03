import java.util.*;

public class NoOfSubsetSum
{
    public static int subsetSum(int arr[],int sum)
    {
        int n=arr.length;
        int dp[][]=new int[n+1][sum+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(i==0 && j!=0)
                    dp[i][j]=0;
                else if(j==0)
                    dp[i][j]=1;
                else if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
                System.out.print(dp[i][j]+" ");
            System.out.println();
        }
        return dp[n][sum];
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int arr[]=new int[n];
		for(int j=0;j<n;j++)
			arr[j]=sc.nextInt();
		int sum=sc.nextInt();
		System.out.println(subsetSum(arr,sum));
    }
}