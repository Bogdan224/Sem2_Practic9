#pragma once
#include <string>
#include <float.h>
#include "SmartphoneSpec.h"

class Smartphone {
private:
	std::string model;  
	double price;  
	SmartphoneSpec spec;
public:
	Smartphone();
	Smartphone(std::string model, double price, SmartphoneSpec spec);
	std::string getModel() const;
	SmartphoneSpec getSpec() const;
	double getPrice() const;
	void setPrice(double price);

	bool operator==(const Smartphone& smartphone) const;
	bool operator!=(const Smartphone& smartphone) const;
};
