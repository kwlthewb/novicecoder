package module4;

import de.fhpotsdam.unfolding.data.PointFeature;
import processing.core.PGraphics;

/** Implements a visual marker for ocean earthquakes on an earthquake map
 * 
 * @author UC San Diego Intermediate Software Development MOOC team
 * @author Your name here
 *
 */
public class OceanQuakeMarker extends EarthquakeMarker {
	
	public OceanQuakeMarker(PointFeature quake) {
		super(quake);
		// setting field in earthquake marker
		isOnLand = false;
	}
		
	@Override
	public void drawEarthquake(PGraphics pg, float x, float y) {
		// Drawing a centered square for Ocean earthquakes
		// DO NOT set the fill color.  That will be set in the EarthquakeMarker
		// class to indicate the depth of the earthquake.
		// Simply draw a centered square.
		
		// HINT: Notice the radius variable in the EarthquakeMarker class
		// and how it is set in the EarthquakeMarker constructor
		
		// TODO: Implement this method
		int w = Integer.parseInt(this.getProperty("radius").toString());
		// Save previous drawing style
		pg.pushStyle();
		// TODO: Add code to draw a triangle to represent the CityMarker
		pg.rect(x, y, w, w);
		if(this.getAge().equals("Past Day")) {
			pg.line(x, y, x + 10, y + 10);
			pg.line(x + 10, y, x, y + 10);
		}
		// Restore previous drawing style
		pg.popStyle();
		
	}
	


	

}
