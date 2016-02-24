
public class TierThreeClass {
	private int t31, t32;
	private double d31, d32;
	private TierOneClass toc;
	public TierThreeClass(TierOneClass x) {
		t31 = 300;
		t32 = -300;
		d31 = 999.99;
		d32 = -999.99;
		toc = x;
		System.out.println("TierThreeClass constructor called.");
	}
	public void DoSomething() {
		System.out.println("TierThreeClass.DoSomething called...");
		toc.printVars();
	}
	public void printVars() {
		System.out.println("TierThreeClass: " + t31 + "," + t32 + "," + d31 + "," + d32);
	}
}
