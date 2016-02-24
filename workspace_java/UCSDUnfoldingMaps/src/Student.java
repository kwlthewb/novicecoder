
public class Student extends Person {
	private int id;
	public int getID() { return id; }
	public Student() {
		this("Student");
		System.out.println("#2 ");
	}
	public Student(String n) {
		super(n);
		System.out.println("#3 ");
	}
	public String toString() {
		return "12345: " + " Bill Li";
	}
	public void method1() {
		System.out.println("Student 1");
		super.method1();
		method2();
	}
	public void method2() {
		System.out.println("Student 2");
	}
	public void method3() {
		System.out.println("Student 3");
	}
}
