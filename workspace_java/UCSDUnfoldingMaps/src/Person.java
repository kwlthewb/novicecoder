
public abstract class Person {
	private String name;
	public String getName() { return name; }
	public Person(String n) {
		this.name = n;
		System.out.println("#1 ");
	}
	public void method1() {
		System.out.println("Person 1");
	}
	public void method2() {
		System.out.println("Person 2");
	}
	public abstract void method3();
}
