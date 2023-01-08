#include "IShapeCreator.h"
#include <algorithm>

string IShapeCreator::getShapeNumbersDescription(string& shapeDescription) {
	replace_if(shapeDescription.begin(), shapeDescription.end(), [](unsigned char c) { return std::isalpha(c) || std::ispunct(c); }, ' ');
	return shapeDescription;
}