
public class TierOneClass {
	private int ti1, ti2;
	private double td1, td2;
	
	public TierOneClass() {
		ti1 = 100;
		ti2 = 100;
		td1 = -999.9;
		td2 = -999.9;
	}
	public TierOneClass(int i1, int i2, double d1, double d2) {
		ti1 = i1;
		ti2 = i2;
		td1 = d1;
		td2 = d2;
	}
	public void TierOneFunc1() {
		System.out.println("TierOneFunc1 called...");
	}
	public void TierOneFunc2() {
		System.out.println("TierOneFunc2 called...");
	}
	
	public void TierOneFunc3() {
		System.out.println("TierOneFunc3 called...");
	}
	public void TierOneFunc4() {
		System.out.println("TierOneFunc4 called...");
	}
	public void printVars() {
		System.out.println("TierOneClass: " + ti1 + "," + ti2 + "," + td1 + "," + td2);
	}
}
