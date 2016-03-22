package module6;


import java.util.HashMap;

import de.fhpotsdam.unfolding.geo.Location;
import de.fhpotsdam.unfolding.marker.SimplePointMarker;
import processing.core.PGraphics;

/** Implements a common marker for cities and earthquakes on an earthquake map
 * 
 * @author UC San Diego Intermediate Software Development MOOC team
 *
 */
public abstract class CommonMarker extends SimplePointMarker {

	// Records whether this marker has been clicked (most recently)
	protected boolean clicked = false;
	// x,y coordinate on screen
	protected float markerX, markerY;
	protected int meterPerPixel;
	protected int zoomLevel;
	protected HashMap<Integer, Double> zoomScale = new HashMap<Integer, Double>();
	
	public int getX() {
		return (int)markerX;
	}
	public int getY() {
		return (int)markerY;
	}
	
	public int getMeterPerPixel() {
		//meterPerPixel = zoomScale.get(zoomLevel).intValue();
		meterPerPixel = (int) (156543.03392 * Math.cos(getLocation().getLat() * Math.PI / 180) / Math.pow(2, zoomLevel));
		return meterPerPixel;
	}
	
	public CommonMarker(Location location) {
		super(location);
		setZoomScale();
	}
	
	public CommonMarker(Location location, java.util.HashMap<java.lang.String,java.lang.Object> properties) {
		super(location, properties);
		setZoomScale();
	}
	
	private void setZoomScale() {
		// set up the meters per pixel based roughly on zoom level
		zoomScale.put(20, 1128.497220);
		zoomScale.put(19, 2256.994440);
		zoomScale.put(18, 4513.988880);
		zoomScale.put(17, 9027.977761);
		zoomScale.put(16, 18055.955520);
		zoomScale.put(15, 36111.911040);
		zoomScale.put(14, 72223.822090);
		zoomScale.put(13, 144447.644200);
		zoomScale.put(12, 288895.288400);
		zoomScale.put(11, 577790.576700);
		zoomScale.put(10, 1155581.153000);
		zoomScale.put(9, 2311162.307000);
		zoomScale.put(8, 4622324.614000);
		zoomScale.put(7, 9244649.227000);
		zoomScale.put(6, 18489298.450000);
		zoomScale.put(5, 36978596.910000);
		zoomScale.put(4, 73957193.820000);
		zoomScale.put(3, 147914387.600000);
		zoomScale.put(2, 295828775.300000);
		zoomScale.put(1, 591657550.500000);
	}
	
	// set current zoom level
	public void setZoom(int z) {
		zoomLevel = z;
	}
	
	// Getter method for clicked field
	public boolean getClicked() {
		return clicked;
	}
	
	// Setter method for clicked field
	public void setClicked(boolean state) {
		clicked = state;
	}
	
	// Common piece of drawing method for markers; 
	// YOU WILL IMPLEMENT. 
	// Note that you should implement this by making calls 
	// drawMarker and showTitle, which are abstract methods 
	// implemented in subclasses
	public void draw(PGraphics pg, float x, float y) {
		// For starter code just drawMaker(...)
		if (!hidden) {
			drawMarker(pg, x, y);
			if (selected) {
				showTitle(pg, x, y);
			}
		}
	}
	public abstract void drawMarker(PGraphics pg, float x, float y);
	public abstract void showTitle(PGraphics pg, float x, float y);
}