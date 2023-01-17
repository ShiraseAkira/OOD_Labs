#pragma once
#include "AbstractFactory.h"
#include "ConcreteProductA2.h"
#include "ConcreteProductB2.h"
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override {
        return new ConcreteProductA2();
    }
    AbstractProductB* CreateProductB() const override {
        return new ConcreteProductB2();
    }
};

