package package1;

public class OtherClass1 {
	public OtherClass1() {
		SampleClass sc = new SampleClass();
		System.out.println("From OtherClass1 - SampleClass public_var: " + sc.public_var + " SampleClass protected_var: " + sc.protected_var + " SampleClass package_var: " + sc.package_var);
	}
}
