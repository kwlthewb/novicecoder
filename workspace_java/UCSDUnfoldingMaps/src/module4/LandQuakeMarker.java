package module4;

import de.fhpotsdam.unfolding.data.PointFeature;
import processing.core.PGraphics;

/** Implements a visual marker for land earthquakes on an earthquake map
 * 
 * @author UC San Diego Intermediate Software Development MOOC team
 * @author Your name here
 *
 */
public class LandQuakeMarker extends EarthquakeMarker {
	
	public LandQuakeMarker(PointFeature quake) {
		
		// calling EarthquakeMarker constructor
		super(quake);
		// setting field in earthquake marker
		isOnLand = true;
	}

	@Override
	public void drawEarthquake(PGraphics pg, float x, float y) {
		// Draw a centered circle for land quakes
		// DO NOT set the fill color here.  That will be set in the EarthquakeMarker
		// class to indicate the depth of the earthquake.
		// Simply draw a centered circle.
		
		// HINT: Notice the radius variable in the EarthquakeMarker class
		// and how it is set in the EarthquakeMarker constructor
		
		// TODO: Implement this method
		int w = Integer.parseInt(this.getProperty("radius").toString());
		// Save previous drawing style
		pg.pushStyle();
		// TODO: Add code to draw a triangle to represent the CityMarker
		pg.ellipse(x, y, w, w);
		if(this.getAge().equals("Past Day")) {
			pg.line(x - 5, y - 5, x + 5, y + 5);
			pg.line(x + 5, y - 5, x - 5, y + 5);
		}
		// Restore previous drawing style
		pg.popStyle();
	}
	

	// Get the country the earthquake is in
	public String getCountry() {
		return (String) getProperty("country");
	}



		
}