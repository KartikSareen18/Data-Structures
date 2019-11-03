import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class PrintLCS
{
    public static void findLCS(char a[],char b[])
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
        
        printLCS(arr,a,b);
    }
    public static void printLCS(int arr[][],char a[],char b[])
    {
        int m=a.length;
        int n=b.length;
        int len=arr[m][n];
        int temp=len;
        char result[]=new char[len+1];
        result[len]=' ';
        int i=m,j=n;
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                result[len-1]=a[i-1];
                i--;
                j--;len--;
            }
            else if(arr[i-1][j]>arr[i][j-1])
                i--;
            else 
                j--;
        }
        for(int k=0;k<=temp;k++)
			System.out.print(result[k]);
    }
    public static void main(String args[])
    {   
        Scanner sc=new Scanner(System.in);
        String x=sc.nextLine();
        String y=sc.nextLine();
        char a[]=x.toCharArray();
        char b[]=y.toCharArray();
        findLCS(a,b);
    }
}