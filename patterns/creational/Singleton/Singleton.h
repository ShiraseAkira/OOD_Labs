#pragma once
class Singleton
{
public:
	Singleton(Singleton &) = delete; // Не должен быть клонируем
	void operator=(const Singleton &) = delete; // Не должен быть присвояемым
	static Singleton* getInstance(int); // Метод управляющий доступом к экземпляру одиночки.
protected:
	Singleton(int); // Скрыт чтобы предотвратить создание через new
	~Singleton();
	int value_;
private:
	static Singleton* instance_;
};

