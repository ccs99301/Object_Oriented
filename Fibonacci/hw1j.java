import java.math.BigInteger;

public class hw1j
{
	public static void main(String args[])
	{
		BigInteger[] fib=new BigInteger[3];
		int n=Integer.parseInt(args[0]);
		fib[0]=new BigInteger("1");
		fib[1]=new BigInteger("1");
		fib[2]=new BigInteger("2");
		if(n<4&&n>0)
			System.out.println(fib[n-1]);
		else
		{
			for(n=n;n>3;n--)
			{
				fib[0]=fib[1];
				fib[1]=fib[2];
				fib[2]=fib[0].add(fib[1]);
			}
			System.out.println(fib[2]);
		}
	}
}
