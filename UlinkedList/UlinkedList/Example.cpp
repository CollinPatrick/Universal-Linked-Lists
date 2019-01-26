#include <stdio.h>
#include <string>
#include <iostream>

#include "UlinkedList.h"
using namespace std;

struct Person
{
	string name;
	int age;
};

int main()
{
	UlinkedList<Person> people;

	Person *p = people.CreateAtTop();
	p->age = 19;
	p->name = "Collin";
	std::cout << "Added " << p->name << ", " << p->age << " to top of list." << endl;

	p = people.CreateAtTop();
	p->age = 70;
	p->name = "John";
	std::cout << "Added " << p->name << ", " << p->age << " to top of list." << endl;

	p = people.CreateAtIndex(1);
	p->age = 43;
	p->name = "Sue";
	std::cout << "Added " << p->name << ", " << p->age << " at index 1." << endl;

	std::cout << "Count: " << people.Count() << endl;

	people.PrintList();

	return 0;
}
