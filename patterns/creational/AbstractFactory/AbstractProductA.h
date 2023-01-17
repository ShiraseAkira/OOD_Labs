#pragma once
#include <string>
/**
 * Каждый отдельный продукт семейства продуктов должен иметь базовый интерфейс.
 * Все вариации продукта должны реализовывать этот интерфейс.
 */
class AbstractProductA {
public:
	virtual ~AbstractProductA() {};
	virtual std::string UsefulFunctionA() const = 0;
};
