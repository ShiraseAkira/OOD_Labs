#pragma once
#include <string>
#include "AbstractProductA.h"
/**
 * Ѕазовый интерфейс другого продукта. ¬се продукты могут взаимодействовать друг
 * с другом, но правильное взаимодействие возможно только между продуктами одной
 * и той же конкретной вариации.
 */
class AbstractProductB {
	/**
	 * ѕродукт B способен работать самосто€тельно...
	 */
public:
	virtual ~AbstractProductB() {};
	virtual std::string UsefulFunctionB() const = 0;
	/**
	 * ...а также взаимодействовать с ѕродуктами A той же вариации.
	 *
	 * јбстрактна€ ‘абрика гарантирует, что все продукты, которые она создает,
	 * имеют одинаковую вариацию и, следовательно, совместимы.
	 */
	virtual std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0;
};
