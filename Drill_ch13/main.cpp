#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	
	Point tl {100, 100};		//pont rajzolása pont koordinátái
	
	Simple_window win {tl, 1280, 720, "Canvas"};  //Ablak megrajzolása,méret(600*400),ablak cím, tl-t átadjuk paraméterként és onnantól kezdődően fogja az ablakot kirajzolni
	
	Polygon poly;			//polygon típusu objektum, sokszög
	
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});	//polygonhoz hozzáadunk pontokat, polygon pontjai hol legyenek
	win.attach(poly);		//felcsatoljuk az ablakra
	
	win.wait_for_button(); 	//Ezt az ablakot tegye ki és várjon a gombnyomásra
}
