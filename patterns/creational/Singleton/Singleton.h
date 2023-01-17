#pragma once
class Singleton
{
public:
	Singleton(Singleton &) = delete; // �� ������ ���� ���������
	void operator=(const Singleton &) = delete; // �� ������ ���� �����������
	static Singleton* getInstance(int); // ����� ����������� �������� � ���������� ��������.
protected:
	Singleton(int); // ����� ����� ������������� �������� ����� new
	~Singleton();
	int value_;
private:
	static Singleton* instance_;
};

