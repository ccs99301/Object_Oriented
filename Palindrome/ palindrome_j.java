import java.util.Scanner;

public class hw1j
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		System.out.print("Enter the texts : ");
		String text=scan.nextLine();
		int left=0,right=text.length()-1;
		while(true)
		{
			if(text.charAt(left)>='a'&&text.charAt(left)<='z'||text.charAt(left)>='A'&&text.charAt(left)<='Z'||left>=text.length())
				break;
			left++;
		}
		while(true)
		{
			if(text.charAt(right)>='a'&&text.charAt(right)<='z'||text.charAt(right)>='A'&&text.charAt(right)<='Z'||right==0)
				break;
			right--;
		}
		if(text.charAt(left)==Character.toUpperCase(text.charAt(right))||text.charAt(left)==Character.toLowerCase(text.charAt(right)))
		{
			while(left<right)
			{
				while(true)
				{
					left++;
					if(text.charAt(left)>='a'&&text.charAt(left)<='z'||text.charAt(left)>='A'&&text.charAt(left)<='Z'||left>=text.length())
						break;
				}
				while(true)
				{
					right--;
					if(text.charAt(right)>='a'&&text.charAt(right)<='z'||text.charAt(right)>='A'&&text.charAt(right)<='Z'||right==0)
						break;
				}
				if(text.charAt(left)!=Character.toUpperCase(text.charAt(right))&&text.charAt(left)!=Character.toLowerCase(text.charAt(right)))
					break;
			}
		}
		if(left>=right&&left<text.length())
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}

