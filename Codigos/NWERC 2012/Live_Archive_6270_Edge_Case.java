

  import java.io.PrintWriter;
  import java.math.BigInteger;
  import java.util.Scanner;

public class Main
{
	Scanner scan=new Scanner(System.in);
    PrintWriter out=new PrintWriter(System.out);
    BigInteger dp[]=new BigInteger[10005];
    int n;
	void init(){
		dp[3]=BigInteger.valueOf(4);
        dp[4]=BigInteger.valueOf(7);
        for(int i=5;i<=10001;i++) dp[i]=dp[i-1].add(dp[i-2]);
	}
	
	void empezar(){
		init();
		while(scan.hasNextInt()){
             n=scan.nextInt();
             out.println(dp[n]);
             out.flush();
         }
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		new Main().empezar();
	}
}