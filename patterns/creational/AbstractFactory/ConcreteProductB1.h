#pragma once
#include "AbstractProductB.h"
/**
 * Конкретные Продукты создаются соответствующими Конкретными Фабриками.
 */
class ConcreteProductB1 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B1.";
    }
    /**
     * Продукт B1 может корректно работать только с Продуктом A1. Тем не менее, он
     * принимает любой экземпляр Абстрактного Продукта А в качестве аргумента.
     */
    std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};
