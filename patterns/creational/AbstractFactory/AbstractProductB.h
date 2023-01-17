#pragma once
#include <string>
#include "AbstractProductA.h"
/**
 * ������� ��������� ������� ��������. ��� �������� ����� ����������������� ����
 * � ������, �� ���������� �������������� �������� ������ ����� ���������� �����
 * � ��� �� ���������� ��������.
 */
class AbstractProductB {
	/**
	 * ������� B �������� �������� ��������������...
	 */
public:
	virtual ~AbstractProductB() {};
	virtual std::string UsefulFunctionB() const = 0;
	/**
	 * ...� ����� ����������������� � ���������� A ��� �� ��������.
	 *
	 * ����������� ������� �����������, ��� ��� ��������, ������� ��� �������,
	 * ����� ���������� �������� �, �������������, ����������.
	 */
	virtual std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0;
};
