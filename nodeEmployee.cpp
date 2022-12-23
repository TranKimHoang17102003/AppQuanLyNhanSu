#include "nodeEmployee.h"

nodeEmployee::nodeEmployee()
{
	next = NULL;
	prev = NULL;
}

nodeEmployee::nodeEmployee(Employee e)
{
	data = e;
	next = NULL;
	prev = NULL;
}

nodeEmployee::nodeEmployee(Employee e, NodeEmployee n, NodeEmployee p)
{
	data = e;
	next = n;
	prev = p;
}

void nodeEmployee::xuat()
{
	this->data.xuat();
}