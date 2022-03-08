#include <iostream>
#include <string>

using namespace std;

class B1{
	public:
	virtual void vf() {cout << "B1::vf()" << endl;}
		void f() {cout << "B1::f()" << endl;}
	virtual void pvf() = 0; //(5.) teljesen virtuális, absztrakt függvény, így az osztály is absztrakttá válik. Absztrakt osztály nem példányosítható. A fordító hibát fog feldobni.
 };
 
//Öröklődés, de vf() újból lesz definiálva (2. feladat)
 class D1 : public B1{
 	public:
 	virtual void vf() override {cout << "D1::vf()" << endl;}
		void f() {cout << "D1::f()" << endl;}	//új fgv létrehozása
 };
 
class D2 : public D1{
	public:
	void pvf() override {cout << "D2::pvf()" << endl;} //6.
};
//7.
class B2{
	public:
	virtual void pvf() = 0;
};

class D21 : public B2{
	public:
	string s;
	void pvf() override {cout << s << endl;} 
};

class D22 : public B2{
	public:
	int n;
	void pvf() override {cout << n << endl;} 
};//7.			
	
//Függvény, melynek argumentuma egy B2 referencia és erre meghívja a pvf()-et
void f(B2& b2){
	b2.pvf();
}
 
 int main(){
 
 	/*B1 b1;
 	b1.vf();
 	b1.f();
 	
 	D1 d1;
 	d1.vf();
 	d1.f();
 	
 	B1& b1r = d1; //3. -> B1 referencia, melyet a D1 objektumhoz inicializálunk
	b1r.vf();
	b1r.f();
 	
 	/*(4.)Amíg a D1-ben f() nics definiálva, output:
	B1::vf()
	B1::f()
	D1::vf()
	B1::f()
	D1::vf()
	B1::f()
	Miután D1-ben f() definiálva van, output:
	B1::vf()
	B1::f()
	D1::vf()
	D1::f()    -> ez a sor változott, mert f() újból lett definiálva D1-ben
	D1::vf()
	B1::f()*/
 
 	D2 d2;
 	d2.vf();
 	d2.f();
 	d2.pvf(); //(6.) D1-be nem tudom átvinni a pvf-et, így a main-ben D2 d2-ig ki kell kommentelni mindent különben hibát dob ki
 	

	/*B2 b2;
	b2.pvf();*/ //7.
	
	D21 d21;
	d21.s = "D21:pvf()";
	d21.pvf();	//7.
	
	D22 d22;
	d22.n = 100;
	d22.pvf();	//7.
	
	f(d21);
	f(d22);	//7.
 }
