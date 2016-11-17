/*
TestThis
(c) 2016
original authors: David I. Schwartz
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*	This tutorial illustrates the utilization of this pointer.
*	It also covers the concepts such as constructor, destructor,
	and member access operator.
*/

// for this Pointer: see https://msdn.microsoft.com/en-us/library/y0dddwwd.aspx
// only used within nonstatic member functions 

#include <iostream>  // for cout and endl
#include <string>    // for string
using namespace std; // for cout and endl

class Person {  // define class Person
// define public members
public:
	Person(string n) : name(n) { } // constructor, pass parameter's value to private member name
	~Person() {                    // destructor
		//delete pal;
	}
	void makePal(Person* pal) {    // define member function makePal
		this->pal = pal;           // assign the parameter pal as the pal of object being called 
		this->pal->pal = this;     // assign the pointer to the object being called to be the pal of the parameter object
	}
	Person& getPal() const {       // define member function getPal
		return *pal;               // return the dereference of the private member pal
	}
	void print() {                 // define member function print
		cout << "Person: " << name << ", Pal: " << pal->name << endl;  // print out current object's name and its pal's name
	}
// define private members
private:
	Person* pal;  // private member pal is a pointer to an Person object
	string name;  // private string member name
};

int main() {

	Person* p1 = new Person("Pat");  // allocate memory for Person type object, pass "Pat" as its constructor's argument.
	Person* p2 = new Person("Sam");  // allocate memory for Person type object, pass "Sam" as its constructor's argument.
	p1->makePal(p2);    // "p2 becomes p1's pal"
	// p2->makePal(p1); // "p1 becomes p2's pal"
	p1->print();        // output: Person: Pat, Pal: Sam
	p2->print();        // output: Person: Sam, Pal: Pat
	delete p1;          // deallocate memory
	delete p2;          // deallocate memory
	//system("pause");

}