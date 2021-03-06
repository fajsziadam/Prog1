#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

using namespace Graph_lib;

/*g++ drill1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill1 `fltk-config --ldflags --use-images`
*/

int main(){

try{

	Point tl {100, 100};
	
	Simple_window win {tl, 600, 400, "Window"};
	
	
	
	Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
	
	win.attach(xa);
	win.set_label("Axis X");
	
	
	Axis ya {Axis::y, Point{20, 300}, 200, 10, "y axis"};
	
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("Axis Y");
	
	
	
	Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
	
	win.attach(sine);
	win.set_label("Sin function");
	
	
	
	Polygon poly;
	poly.add(Point{300, 200});
	poly.add(Point{350, 100});
	poly.add(Point{400, 200});
	
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Polygon");
	
	
	
	Rectangle r {Point{200, 200}, 100, 50};
	
	win.attach(r);
	win.set_label("Rectangle");
	
	
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{100, 50});
	poly_rect.add(Point{200, 50});
	poly_rect.add(Point{200, 100});
	poly_rect.add(Point{100, 100});
	win.attach(poly_rect);
	win.set_label("Poly_rect");
	
	
	poly_rect.add(Point{50, 75});
	win.set_label("Poly_rect_2");
	
	
	
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Filling");
	
	
	
	Text t {Point{150, 150}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("Text");
	
	
	
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Text_font");
	
	
	
	Image ii {Point{250, 250}, "badge.jpg"};
	win.attach(ii);
	win.set_label("Image");
	
	
	/*ii.move(100, 200);
	win.set_label("badge.jpg");*/
	
	
	
	Circle c {Point{100, 200}, 50};
	Ellipse e {Point{100, 200}, 75, 25};
	e.set_color(Color::dark_red);
	Mark m {Point{100, 200}, 'x'};
	
	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.set_label("Extras");
	win.wait_for_button();

}
catch(exception& e){
	cerr << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "Error" << '\n';
	return 2;
}

}
