import package1.OtherClass1;
import package1.SubClass1;

public class MainClass {
	public static void main(String[] args) {
//		TierOneClass toc = new TierOneClass();
//		TierTwoClass ttc = new TierTwoClass(200,-200,222.22,-222.22);
//		toc.TierOneFunc1();
//		toc.TierOneFunc2();
//		toc.TierOneFunc3();
//		toc.TierOneFunc4();
//		ttc.TierOneFunc1();
//		ttc.TierOneFunc2();
//		ttc.TierOneFunc3();
//		ttc.TierOneFunc4();
//		ttc.printVars();
		Student s = new Student();
		s.method1();
		s.method2();
		s.method3();
		//Person p = new Person("Bill");
		//Person q = new Person("Amanda");
		Faculty f = new Faculty();
		f.method1();
		f.method2();
		f.method3();
		Object o = new Faculty();
		String n = s.getName();
		//p = s;
		//int m = ((Student)p).getID();
		//f = q;
		o = s;
		OtherClass1 oc1 = new OtherClass1();
		OtherClass2 oc2 = new OtherClass2();
		SubClass1 sc1 = new SubClass1();
		SubClass2 sc2 = new SubClass2();
	}

}
