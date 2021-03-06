package module3;

//Java utilities libraries
import java.util.ArrayList;
//import java.util.Collections;
//import java.util.Comparator;
import java.util.List;

//Processing library
import processing.core.PApplet;

//Unfolding libraries
import de.fhpotsdam.unfolding.UnfoldingMap;
import de.fhpotsdam.unfolding.marker.Marker;
import de.fhpotsdam.unfolding.data.PointFeature;
import de.fhpotsdam.unfolding.marker.SimplePointMarker;
import de.fhpotsdam.unfolding.providers.Google;
import de.fhpotsdam.unfolding.providers.MBTilesMapProvider;
import de.fhpotsdam.unfolding.utils.MapUtils;

//Parsing library
import parsing.ParseFeed;

/** EarthquakeCityMap
 * An application with an interactive map displaying earthquake data.
 * Author: UC San Diego Intermediate Software Development MOOC team
 * @author Your name here
 * Date: July 17, 2015
 * */
public class EarthquakeCityMap extends PApplet {

	// You can ignore this.  It's to keep eclipse from generating a warning.
	private static final long serialVersionUID = 1L;

	// IF YOU ARE WORKING OFFLINE, change the value of this variable to true
	private static final boolean offline = false;
	
	// Less than this threshold is a light earthquake
	public static final float THRESHOLD_MODERATE = 5;
	// Less than this threshold is a minor earthquake
	public static final float THRESHOLD_LIGHT = 4;

	/** This is where to find the local tiles, for working without an Internet connection */
	public static String mbTilesString = "blankLight-1-3.mbtiles";
	
	// The map
	private UnfoldingMap map;
	
	//feed with magnitude 2.5+ Earthquakes
	private String earthquakesURL = "http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/2.5_week.atom";

	
	public void setup() {
		size(1300, 800, OPENGL);

		if (offline) {
		    map = new UnfoldingMap(this, 200, 20, 1000, 750, new MBTilesMapProvider(mbTilesString));
		    earthquakesURL = "2.5_week.atom"; 	// Same feed, saved Aug 7, 2015, for working offline
		}
		else {
			map = new UnfoldingMap(this, 200, 20, 1000, 750, new Google.GoogleMapProvider());
			// IF YOU WANT TO TEST WITH A LOCAL FILE, uncomment the next line
			//earthquakesURL = "2.5_week.atom";
		}
		
	    map.zoomToLevel(2);
	    MapUtils.createDefaultEventDispatcher(this, map);	
			
	    // The List you will populate with new SimplePointMarkers
	    List<Marker> markers = new ArrayList<Marker>();

	    //Use provided parser to collect properties for each earthquake
	    //PointFeatures have a getLocation method
	    List<PointFeature> earthquakes = ParseFeed.parseEarthquake(this, earthquakesURL);
	    System.out.println("PointFeature size: " + earthquakes.size());
	    // These print statements show you (1) all of the relevant properties 
	    // in the features, and (2) how to get one property and use it
	    if (earthquakes.size() > 0) {
//	    	PointFeature f = earthquakes.get(0);
//	    	System.out.println(f.getProperties());
//	    	Object magObj = f.getProperty("magnitude");
//	    	Object locObj = f.getProperty("title");
//	    	float mag = Float.parseFloat(magObj.toString());
//	    	System.out.println("Magnitude: " + magObj + " Location: " + locObj) ;
//	    	SimplePointMarker m = createMarker(f);
//	    	m.setColor(color(255,255,0));
//	    	m.setRadius(10);
//	    	map.addMarker(m);
	    	// PointFeatures also have a getLocation method
	    	int red = color(255,0,0);
	    	int yellow = color(255, 255, 0);
	    	int blue = color(0,0,255);
	    	int count = 1, radius = 50, color = 0;
	    	SimplePointMarker m;
	    	for(PointFeature element: earthquakes) {
	    		double mag = Double.parseDouble(element.getProperty("magnitude").toString());
	    		String loc = element.getProperty("title").toString();
	    		if(mag < 4.0) {
	    			radius = 10;
	    			color = blue;
	    		} else if(mag >= 4.0 && mag < 5.0) {
	    			radius = 20;
	    			color = yellow;
	    		} else if (mag >= 5.0) {
	    			radius = 30;
	    			color = red;
	    		}
	    		System.out.println(count++ + "," + loc + "," + mag + ",radius," + radius + ",color," + color);
	    		m = createMarker(element);
		    	m.setColor(color);
		    	m.setRadius(radius);
		    	map.addMarker(m);
	    	}
	    }
	    
	    // Here is an example of how to use Processing's color method to generate 
	    // an int that represents the color yellow.  
	    int yellow = color(255, 255, 0);
	    
	    //TODO: Add code here as appropriate
	}
		
	// A suggested helper method that takes in an earthquake feature and 
	// returns a SimplePointMarker for that earthquake
	// TODO: Implement this method and call it from setUp, if it helps
	private SimplePointMarker createMarker(PointFeature feature)
	{
		// finish implementing and use this method, if it helps.
		return new SimplePointMarker(feature.getLocation(), feature.getProperties());
	}
	
	public void draw() {
	    background(100,100,0);
	    map.draw();
	    addKey();
	}


	// helper method to draw key in GUI
	// TODO: Implement this method to draw the key
	private void addKey() 
	{	
		// Remember you can use Processing's graphics methods here
		fill(255,255,204);
		rect(10,20,180,200,7);
		// magnitude >= 5.0
		fill(255,0,0);
		ellipse(40,100,30,30);
		// magnitude >= 4.0 && < 5.0
		fill(255,255,0);
		ellipse(40,140,20,20);
		// magnitude < 4.0;
		fill(0,0,255);
		ellipse(40,170,10,10);
		// Add index
		fill(0,0,0);
		text("Earthquake Key",40,60);
		text("5.0+ Magnitude",60,105);
		text("4.0+ Magnitude",60,145);
		text("Below 4.0",60,175);
		
	}
}
