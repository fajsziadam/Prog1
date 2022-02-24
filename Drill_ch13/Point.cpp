#include "std_lib_facilities.h"	

ostream& print_array(ostream& os, char* p, int a)
{	
	for(int i = 0; i < a; ++i)		
	{
		os << p[i] << endl;
	}
		os << "Tömb mérete: " << a << endl;
}


int main()			
{
	char* p1 = new char[20] {'a', 'b', 'c' , 'd' , 'e' , 'f'};
		print_array(cout, p1, 20);
	
	delete[] p1;
					
	return 0;			
}
