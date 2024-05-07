#pragma once
#include "Smartphone.h"
#include <vector>

class Store
{
private:
	std::vector<std::pair<Smartphone, unsigned int>> smartponesInStock;
public:
	Store();
	void SellSmartphone(Smartphone smartphone, unsigned int count = 1);
	void AddSmartphoneToStock(Smartphone smartphone, unsigned int count = 1);
	int FindPos(Smartphone smartphone);
	int FindPos(std::string model, double price, SmartphoneSpec spec);
	int FindPos(std::string model, double price, Manufacturer manufacturer,
		Color color, float displaySize, int ram, int storage, CPU cpu, OS os);
};

