import java.util.Scanner;

public class Timer {
	public static void main(String[] args) {
		System.out.println("Hellow world!!");
		Scanner scan = new Scanner(System.in);
		int something;
		something = scan.nextInt();
		System.out.println(something);
		scan.close();
		int a = 5, b = 7;
		swap(a,b);
		System.out.println(a + "," + b);
	}
	
	public static void swap(int a, int b) {
		int temp = a;
		b = a;
		a = temp;
	}
}
