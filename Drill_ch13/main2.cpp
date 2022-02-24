#include "Simple_window.h"
#include "Graph.h"

double one(double) {return 1; }
double square(double x) { return x*x; }

int main()
{
	using namespace Graph_lib;
	
	Point tl {100, 100};
	
	int xmax = 1280;	//ablak szélessége
	int ymax = 720;	//ablak magassága
	
	int rmin = -11;
	int rmax = 11;
	
	int n_points = 400;
	
	int x_orig = xmax/2;
	int y_orig = ymax/2;
	
	Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};  
	
	Point origo {x_orig,y_orig};			//tengely felvétele
		
	int xlength = xmax-40;
	int ylength = ymax-40;
	
	int xscale = 30;		//30 pixelenként egy beosztás
	int yscale = 30;
	
	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);		//átadunk egy fgv. pointert, h mit akarunk rajzolni, milyen skálán mozog, origo, hány pontot rajzoljon ki
		
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) {return cos(x); }
				, rmin, rmax, origo, n_points, xscale, yscale);
		
	Axis x {Axis::x,Point{20, y_orig}, xlength, xlength/xscale, "x" };	//tengelyek, x tengely felvétele,axis::x-vizszintestengely,honnan induljon(kezdőpont),hossz,darabszám(hány behúzás legyen), név
	
	Axis y {Axis::y,Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y" };	
	
	Rectangle r {Point{200,200}, 100, 50};		//pont megadása, szélesség magasság
	
	r.set_fill_color(Color::green);		//kitöltő szín áttllítása
	r.set_style(Line_style(Line_style::dash, 4));	//vonalstílus, x pixel vastag vonal
	
	Text t {Point{200, 400}, "Hello graphics!"};
	t.set_font(Font::times_bold);			//betűtípus
	t.set_font_size(20);				//betűméret
	
	Image ii {Point{100,100}, "badge.jpg"};
	
	Circle c  {Point{400, 400}, 50};
	
	
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(x);
	win.attach(y);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	
	win.wait_for_button(); 	
}
