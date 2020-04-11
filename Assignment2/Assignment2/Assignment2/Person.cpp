#include "Person.h"

Person::Person(string n, int t)
{
	name = n;
	switch (t) {
	case 0:
		setType(t);
		health = 5;
	case 1:
		setType(t);
		health = 5;
	case 2:
		setType(t);
		health = 5;
	case 3:
		setType(t);
		health = 15;
	}
}
