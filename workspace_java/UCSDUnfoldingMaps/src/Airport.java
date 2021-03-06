import java.util.Random;

public class Airport implements Comparable<Airport> {
	private String m_name;
	private String m_code;
		
	public String getCode() {
		return m_code;
	}
	public String getCity() {
		return m_name;
	}
	public Airport(String n, String c) {
		m_name = n;
		m_code = c;
	}
	public static String findAirportCode(String toFind, Airport[] airports) {
		int low = 0;
		int high = airports.length / 2;
		int mid;
		while(low <= high) {
			mid = (low + high) / 2;
			int compare = toFind.compareTo(airports[mid].getCity());
			if(compare < 0) {
				high = mid - 1;
			} else if(compare > 0){
				low = mid + 1;
			} else {
				return airports[mid].getCode();
			}
		}
		return null;
	}
	public int compareTo(Airport other) {
		return m_name.compareTo(other.getCity());
	}
//	public static String findAirportCode(String toFind, Airport[] airports) {
//		for(int i = 0; i < airports.length; i++) {
//			if(airports[i].m_name.equals(toFind)) {
//				return airports[i].m_code;
//			}
//		}
//		return null;
//	}
	
	
	
	public static void main(String[] args) {
		Airport[] aps = new Airport[8];
		aps[0] = new Airport("Agra","AGR");
		aps[1] = new Airport("Beijing","PEK");
		aps[2] = new Airport("Chicago","ORD");
		aps[3] = new Airport("Essen","ESS");
		aps[4] = new Airport("Lagos","LOS");
		aps[5] = new Airport("Montreal","YMX");
		aps[6] = new Airport("Quito","UIO");
		aps[7] = new Airport("Sydney","SYD");
		System.out.println(findAirportCode("Beijing", aps));
		System.out.println(findAirportCode("Lagos", aps));
		System.out.println(findAirportCode("Bei", aps));
		
//		int[] nums = new int[100];
//		Random rand = new Random();
//		for(int i = 0; i < nums.length; i++) {
//			nums[i] = rand.nextInt(600);
//			//System.out.println(i + "," + nums[i]);
//		}
		int[] nums = {7,16,66,5,15,43,97,51};
		// Selection sort
//		int idx = 0, end = nums.length, temp = 0;
//		while (idx < end - 1) {
//			for(int i = idx + 1; i < end; i++) {
//				if(nums[i] < nums[idx]) {
//					temp = nums[i];
//					nums[i] = nums[idx];
//					nums[idx] = temp;
//				}
//			}
//			idx++;
//		}
		
		// Insertion sort
		int currInd,temp;
		for(int pos=1; pos < nums.length; pos++) {
			currInd = pos;
			while(currInd > 0 && nums[currInd] < nums[currInd - 1]) {
				temp = nums[currInd];
				nums[currInd] = nums[currInd - 1];
				nums[currInd - 1] = temp;
				currInd--;
			}
		}
	
		
		for(int i = 0; i < nums.length; i++) {
			System.out.println(i + "," + nums[i]);
		}
		
		
	}
}
