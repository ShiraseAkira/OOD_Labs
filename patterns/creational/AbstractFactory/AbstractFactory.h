#pragma once
#include "AbstractProductA.h"
#include "AbstractProductB.h"

class AbstractFactory {
public:
	virtual AbstractProductA* CreateProductA() const = 0;
	virtual AbstractProductB* CreateProductB() const = 0;
};

