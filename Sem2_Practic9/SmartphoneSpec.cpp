#include "SmartphoneSpec.h"

SmartphoneSpec::SmartphoneSpec(){
	manufacturer = Manufacturer::UNDEFINED;
	color = Color::UNDEFINED;
	displaySize = 0;
	ram = 0;
	storage = 0;
	cpu = CPU::UNDEFINED;
	os = OS::UNDEFINED;
}
SmartphoneSpec::SmartphoneSpec(Manufacturer manufacturer, Color color, float displaySize, int ram, int storage, CPU cpu, OS os){
	this->manufacturer = manufacturer;
	this->color = color;
	this->displaySize = displaySize;
	this->ram = ram;
	this->storage = storage;
	this->cpu = cpu;
	this->os = os;
}
Manufacturer SmartphoneSpec::getManufacturer() const{ 
	return manufacturer;
}
Color SmartphoneSpec::getColor() const{ 
	return color;
}
float SmartphoneSpec::getDisplay() const{ 
	return displaySize;
}
int SmartphoneSpec::getRAM() const{ 
	return ram;
}
int SmartphoneSpec::getStorage() const{
	return storage;
}
CPU SmartphoneSpec::getCPU() const{
	return cpu;
}
OS SmartphoneSpec::getOS() const{
	return os;
}

bool SmartphoneSpec::operator==(const SmartphoneSpec& spec) const {
	if (this->color != spec.color) {
		return false;
	}
	else if (this->cpu != spec.cpu) {
		return false;
	}
	else if (this->displaySize != spec.displaySize) {
		return false;
	}
	else if (this->manufacturer != spec.manufacturer) {
		return false;
	}
	else if (this->os != spec.os) {
		return false;
	}
	else if (this->ram != spec.ram) {
		return false;
	}
	else if (this->storage != spec.storage) {
		return false;
	}
	return true;
}
bool SmartphoneSpec::operator!=(const SmartphoneSpec& spec) const {
	if (this->operator==(spec))
		return false;
	return true;
}