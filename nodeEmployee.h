#pragma once

//include class
#include "Employee.h"

//include lib

typedef class nodeEmployee* NodeEmployee;

class nodeEmployee :public Employee
{
public:
	Employee data;
	NodeEmployee next;
	NodeEmployee prev;

public:
	nodeEmployee();
	nodeEmployee(Employee);
	nodeEmployee(Employee, NodeEmployee, NodeEmployee);

	void xuat();
};

