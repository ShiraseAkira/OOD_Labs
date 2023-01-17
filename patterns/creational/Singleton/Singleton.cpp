#include "Singleton.h"

Singleton* Singleton::instance_{ nullptr };

Singleton* Singleton::getInstance(int value) {
	if (instance_ == nullptr)
	{
		instance_ = new Singleton(value);
	}
	return instance_;
}

Singleton::Singleton(int value) :value_(value) {};

Singleton::~Singleton() {};