/*
    g++ drill2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill2 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"


int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;
    
    
    int x_size = 800;
    int y_size = 800;
    
    int x_grid = 100;
    int y_grid = 100;
    
     Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
    
    Lines grid;    
	for (int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for (int y = y_grid; y<y_size+1; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});
	win.attach(grid);		   
   

	Vector_ref<Rectangle> vr;
	for (int j = 0; j<8; ++j) {
	vr.push_back(new Rectangle{Point{j*100,j*100},100,100});
	vr[vr.size()-1].set_fill_color(Color::red);
	win.attach(vr[vr.size()-1]);}

	Vector_ref<Image> v2;
	for(int i = 0; i <= 401; i += 200){
		v2.push_back(new Image{Point{i+200, i}, "index.jpeg"});
		win.attach(v2[v2.size()-1]);}
	
	
	win.wait_for_button();
    
    while(true){
    	for(int i = 0; i <= 701; i += 100){
    		for(int j = 0; j <= 701; j += 100){
    		Image ii{Point{j,i}, "100.jpg"};
    		win.attach(ii);
    		win.wait_for_button();
    		}
    	}
    }
		
}



