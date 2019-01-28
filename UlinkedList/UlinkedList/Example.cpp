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
	std::cout << "Created " << p->name << ", " << p->age << " to top of list." << endl;

	p = people.CreateAtBottom();
	p->age = 43;
	p->name = "Sue";
	std::cout << "Created " << p->name << ", " << p->age << " at bottom of list." << endl;

	p = people.CreateAtIndex(1);;
	p->age = 70;
	p->name = "John";
	std::cout << "Created " << p->name << ", " << p->age << " at index [1] of list." << endl;

	p = new Person;
	p->age = 12;
	p->name = "Larry";
	people.AddAtTop(p);
	std::cout << "Added " << p->name << ", " << p->age << " to top of list." << endl;

	p = new Person;
	p->age = 34;
	p->name = "Jessica";
	people.AddAtBottom(p);
	std::cout << "Added " << p->name << ", " << p->age << " to bottom of list." << endl;

	p = new Person;
	p->age = 28;
	p->name = "Marry";
	people.AddAtIndex(p, 2);
	std::cout << "Added " << p->name << ", " << p->age << " to index [2] of list." << endl;

	std::cout << "Count: " << people.Count() << endl;
	people.PrintList();

	std::cout << endl;

	p = people.PopTop();
	std::cout << "Popped " << p->name << ", " << p->age << " from top of list." << endl;
	people.PrintList();

	p = people.PopBottom();
	std::cout << "Popped " << p->name << ", " << p->age << " from bottom of list." << endl;
	people.PrintList();

	p = people.PopAtIndex(2);
	std::cout << "Popped " << p->name << ", " << p->age << " from index[2] of list." << endl;
	people.PrintList();

	std::cout << endl;

	p = people.GetAtIndex(1);
	std::cout << "Retrieved " << p->name << ", " << p->age << " from index[1] of list." << endl;

	int index = people.GetIndex(p);
	std::cout << p->name << ", " << p->age << " is located at index[" << index << "] of list." << endl;
	people.PrintList();

	std::cout << endl;
	bool b = people.Peek();
	std::cout << "List is populated: " << b << endl;

	p = people.GetAtIndex(1);
	std::cout << "Removed " << p->name << ", " << p->age << " from index[1] of list." << endl;
	people.RemoveAtIndex(1);
	people.PrintList();

	p = people.GetHead();
	std::cout << "Removed " << p->name << ", " << p->age << " from list." << endl;
	people.Remove(p);
	people.PrintList();

	



	return 0;
}
