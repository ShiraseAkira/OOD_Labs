#pragma once
#include <string>
/**
 * ������ ��������� ������� ��������� ��������� ������ ����� ������� ���������.
 * ��� �������� �������� ������ ������������� ���� ���������.
 */
class AbstractProductA {
public:
	virtual ~AbstractProductA() {};
	virtual std::string UsefulFunctionA() const = 0;
};
