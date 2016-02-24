import package1.SampleClass;

public class OtherClass2 {
	public OtherClass2() {
		SampleClass sc = new SampleClass();
		System.out.println("From OtherClass2 - SampleClass public_var: " + sc.public_var);
	}
}
