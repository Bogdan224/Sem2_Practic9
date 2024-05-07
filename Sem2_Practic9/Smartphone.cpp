#include "Smartphone.h"

Smartphone::Smartphone(){ 
	model = "";
	price = 0;
	spec = SmartphoneSpec();
}
Smartphone::Smartphone(std::string model, double price, SmartphoneSpec spec){
	this->model = model;
	setPrice(price);
	this->spec = spec;
}
std::string Smartphone::getModel() const{ 
	return model;
}
SmartphoneSpec Smartphone::getSpec() const{ 
	return spec;
}
double Smartphone::getPrice() const{
	return price;
}
void Smartphone::setPrice(double price){
	if (price < 0 || price > DBL_MAX)
		price = 0;
	this->price = price;
}

bool Smartphone::operator==(const Smartphone& smartphone) const {
	if (this->model != smartphone.model)
		return false;
	else if (this->price != smartphone.price)
		return false;
	else if(this->spec != smartphone.spec)
		return false;
	return true;
}
bool Smartphone::operator!=(const Smartphone& smartphone) const {
	if (this->operator==(smartphone)) {
		return false;
	}
	return true;
}
