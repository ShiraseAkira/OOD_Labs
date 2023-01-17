#pragma once
#include <string>
/**
 * Интерфейс Продукта объявляет операции, которые должны выполнять все
 * конкретные продукты.
 */

class Product {
public:
	virtual ~Product() {}
	virtual std::string Operation() const = 0;
};
