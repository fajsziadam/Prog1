/*
g++ drill4_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill4_2 `fltk-config --ldflags --use-images`
*/

#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

	double one(double) { return 1; }
	double slope(double x) { return x/2; }
	double square(double x) { return x*x; }
	double sloping_cos(double x) { return cos(x) + slope(x); }

int main(){

	constexpr int xmax = 600;
	constexpr int ymax = 600; 	//window size
	
	constexpr int x_orig = xmax/2;  // position of (0,0) is center of window
	constexpr int y_orig = ymax/2;
	const Point orig {x_orig,y_orig};
	
	
	constexpr int r_min = -10;
	constexpr int r_max = 11; // range [–10:11)
	
	constexpr int n_points = 400; // number of points used in range
	
	constexpr int x_scale = 20; // scaling factors
	constexpr int y_scale= 20;
	
Simple_window win {Point{100,100},xmax,ymax,"Function graphing"};

	Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
	Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

	
Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s4 {sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
Function cosine {cos, -10, 11, Point{300, 300}, 400, 20, 20};
cosine.set_color(Color::blue);

	win.attach(cosine);
	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);

	Text ts {Point{100, y_orig-40}, "one"};
	Text ts2 {Point{100, y_orig+y_orig/2-20}, "x/2"};
	Text ts3 {Point{x_orig-100,20}, "x*x"};

	win.attach(ts);
	win.attach(ts2);
	win.attach(ts3);

	win.wait_for_button();
	


}

