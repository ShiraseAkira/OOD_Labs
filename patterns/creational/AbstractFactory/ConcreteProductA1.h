#pragma once
#include "AbstractProductA.h"
/**
 * Конкретные продукты создаются соответствующими Конкретными Фабриками.
 */
class ConcreteProductA1 :
    public AbstractProductA
{
public:
    std::string UsefulFunctionA() const override {
        return "The result of the product A1.";
    }
};

