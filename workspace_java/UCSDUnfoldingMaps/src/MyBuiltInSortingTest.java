import java.util.*;

public class MyBuiltInSortingTest {
	public static void main(String[] args) {
		Random random = new Random();
		List<Integer> numsToSort = new ArrayList<Integer>(15);
		for(int i=0; i < 15; i++) {
			numsToSort.add(random.nextInt(100));
		}
		Collections.sort(numsToSort);
		System.out.println(numsToSort.toString());
		
		List<Airport> airportsToSort = new ArrayList<Airport>(7);
		airportsToSort.add(new Airport("Lagos","LOS"));
		airportsToSort.add(new Airport("Chicago","ORD"));
		airportsToSort.add(new Airport("Essen","ESS"));
		airportsToSort.add(new Airport("Quito","UIO"));
		airportsToSort.add(new Airport("Montreal","YMX"));
		airportsToSort.add(new Airport("Beijing","PEK"));
		for(Airport a : airportsToSort) {
			System.out.println(a.getCity() + "," + a.getCode());
		}
		System.out.println("");
		Collections.sort(airportsToSort);
		for(Airport a : airportsToSort) {
			System.out.println(a.getCity() + "," + a.getCode());
		}

	}
}
