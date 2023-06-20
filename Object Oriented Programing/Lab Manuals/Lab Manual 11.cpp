#include "Header.h"

void main()
{
	char a[] = "Ted";
	char b[] = "Thompson";
	char a1[] = "Ted";
	char b1[] = "Thompson";
	char c1[] = "The Event Locator";
	char a2[] = "Richard";
	char b2[] = "Karp";
	char c2[] = "Distributed Algorithms";
	char a3[] = "Arnold";
	char b3[] = "Gates";
	Student s(a,b, 22, 3.91);
	Faculty f(a2, b2, 45, 2, 420);
	s.Student_print();
	f.Faculty_print();
	Undergraduate u(a, b, 22, 3.91, c1);
	Graduate g(a3,b3, 25, 3.01,c2);
	u.Undergraduate_print();
	g.Graduate_print();
	u.Student_print();
	Faculty f(a, b, 40, 3, 123);
	f.Faculty::Information_print();
	Undergraduate u(a1, b1, 22, 3.91, c1);
	Graduate g(a2, b2, 25, 3.01, c2);
	u.Undergraduate_print();
	g.Graduate_print();
	u.Student::Information_print();
}