
public class ArrayLocation {
	private double[] coords;
	private double x;
	public ArrayLocation(double[] coords, double x) {
		this.coords = coords;
		this.x = x;
	}
	public static void main(String[] args) {
		double[] coords = {5.0, 0.0};
		double x = 45.1;
		ArrayLocation accra = new ArrayLocation(coords, x);
		coords[0] = 32.9;
		coords[1] = -117.2;
		x = -45.1;
		// the private variable coords in ArrayLocation actually got modified
		System.out.println(accra.coords[0] + "," + accra.coords[1] + "," + accra.x);
	}
}
