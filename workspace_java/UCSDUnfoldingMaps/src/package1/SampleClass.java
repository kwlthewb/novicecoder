package package1;

public class SampleClass {
	public int public_var;
	protected int protected_var;
	int package_var;
	private int private_var;
	public SampleClass() {
		public_var = 100;
		protected_var = 200;
		package_var = 300;
		private_var = 400;
		System.out.println("From SampleClass - public_var: " + this.public_var 
				+ " protected_var: " + this.protected_var + " package_var: " + this.package_var
				+ " private_var: " + this.private_var);
	}
}
