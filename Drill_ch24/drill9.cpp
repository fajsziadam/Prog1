#include <iostream>
#include <string>
#include <complex>
#include <numeric>
#include <stdexcept>
#include<iomanip>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;
using namespace std;

//4.feladat
void sqrt_operation(){
	
	int val;
	cin >> val;
	
	if (val < 0)
		cout << "no square root" << endl;
	else	
		cout << sqrt(val) << endl;
}

int main()
try {
	//1.feladat
	cout << "sizeof: " << endl;
	cout << "char: " << sizeof(char) << endl;
	cout << "short: " << sizeof(short) << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "int*: " << sizeof(int*) << endl;
	cout << "double: " << sizeof(double*) << endl; //írjuk ki a méretét a változóknak.

	//2.feladat
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int, 3> e(10,10,10);

	cout << "sizeof: "<<endl;
	cout << "Matrix<int> a(10): "<< sizeof(a) << endl;
	cout << "Matrix<int> b(100): "<< sizeof(b) << endl;
	cout << "Matrix<double> c(10): "<< sizeof(c) << endl;
	cout << "Matrix<int,2> d(10,10): "<< sizeof(d) << endl;
	cout << "Matrix<int,3> e(10,10,10): "<< sizeof(e) << endl;

	//3.feladat
	cout << "number of elements: " << endl;
	cout << " Matrix<int> a(10): " << a.size() << endl;
	cout << "Matrix<int> b(100): " << b.size() << endl;
	cout << "Matrix<double> c(10): " << c.size() << endl;
	cout << "Matrix <int, 2> d(10,10):"  << d.size() << endl;
	cout << "Matrix <int, 3> e(10,10,10): " << e.size() << endl;

	//4.feladat
	cout << "Enter 5 int for square_root: " << endl;
    	for (int i = 0; i < 5; ++i)
    	    sqrt_operation();

	//5.feladat
    Matrix<double> md(10);
    cout << "Enter 10 floating-point values:\n";
    	for (int i = 0; i < 10; ++i)
    		cin>>md[i];
    cout<<md<<"\n";

	//6.feladat
	cout << "Multiplication table: ";
	cout<<"Enter n: ";
    int n;
    cin >> n;
    cout << "Enter m: ";
    int m;
    cin >> m;

    Matrix<int,2> multi_table(n,m);

   for(int i = 0; i < multi_table.dim1(); ++i)
   {
		for(int j = 0; j < multi_table.dim2(); ++j)
		{
			multi_table(i,j) = (i+1)*(j+1);
			cout << setw(5) << multi_table(i,j);
		}
		cout<<"\n";
   }

	//7.feladat
    Matrix<complex<double>> complex_matrix(10);
    cout << "Enter 10 complex numbers (Real,Imaginary):\n";
    for (int i = 0; i<complex_matrix.size(); ++i) 
    {
        cin>>complex_matrix[i];
    }

    complex<double> sum;
     for (int i = 0; i<complex_matrix.size(); ++i)
        sum += complex_matrix[i];
    cout << "Sum of the complex numbers:: " << sum << '\n';
	
	//8.feladat
    Matrix<int,2> matr_eight (2,3);
    cout << "Enter 6 int for Matrix<int,2>m(2,3):\n";
    for (int i = 0; i<matr_eight.dim1(); ++i)
        for (int j = 0; j<matr_eight.dim2(); ++j) 
        {
            cin >> matr_eight(i,j);
        }
    cout<<matr_eight<<"\n";

	return 0;

} catch (Matrix_error& e) {
	std::cerr << e.name << '\n';
	return 1;
}
