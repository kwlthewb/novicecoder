
public class TierTwoClass extends TierOneClass {
	private int t21, t22;
	private double d21, d22;
	public TierTwoClass(int i1, int i2, double d1, double d2) {
		t21 = i1;
		t22 = i2;
		d21 = d1;
		d22 = d2;
	}
	public void TierOneFunc1() {
		System.out.println("TierTwoFunc1 called...");
	}
	public void TierOneFunc2() {
		System.out.println("TierTwoFunc2 called...");
		TierThreeClass ttc = new TierThreeClass(this);
		ttc.DoSomething();
	}
	public void printVars() {
		System.out.println("TierTwoClass: " + t21 + "," + t22 + "," + d21 + "," + d22);
	}
}
