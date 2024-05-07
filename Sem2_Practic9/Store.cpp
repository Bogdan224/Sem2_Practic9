#include "Store.h"

Store::Store(){ 
	smartponesInStock = std::vector<std::pair<Smartphone, unsigned int>>();
}
void Store::SellSmartphone(Smartphone smartphone, unsigned int count = 1){ 
	
}
void Store::AddSmartphoneToStock(Smartphone smartphone, unsigned int count = 1){ 
	int pos = FindPos(smartphone);
	if (pos != -1)
	{
		smartponesInStock[pos].second += count;
	}
	else {
		smartponesInStock.push_back(std::pair<Smartphone, int>(smartphone, count));
	}
}

int Store::FindPos(Smartphone smartphone){
	for (int i = 0; i < smartponesInStock.size(); i++) {
		if (smartphone == smartponesInStock[i].first)
			return i;
	}
	return -1;
}
int Store::FindPos(std::string model, double price, SmartphoneSpec spec){
	for (int i = 0; i < smartponesInStock.size(); i++) {
		if (model != smartponesInStock[i].first.getModel())
			continue;
		if (price != smartponesInStock[i].first.getPrice())
			continue;
		if (spec != smartponesInStock[i].first.getSpec())
			continue;
		return i;
	}
	return -1;
}
int Store::FindPos(std::string model, double price, Manufacturer manufacturer,
	Color color, float displaySize, int ram, int storage, CPU cpu, OS os){ 
	for (int i = 0; i < smartponesInStock.size(); i++) {
		if (model != smartponesInStock[i].first.getModel())
			continue;
		if (price != smartponesInStock[i].first.getPrice())
			continue;
		if (manufacturer != smartponesInStock[i].first.getSpec().getManufacturer())
			continue;
		if (color != smartponesInStock[i].first.getSpec().getColor())
			continue;
		if (displaySize != smartponesInStock[i].first.getSpec().getDisplay())
			continue;
		if (ram != smartponesInStock[i].first.getSpec().getRAM())
			continue;
		if (storage != smartponesInStock[i].first.getSpec().getStorage())
			continue;
		if (cpu != smartponesInStock[i].first.getSpec().getCPU())
			continue;
		if (os != smartponesInStock[i].first.getSpec().getOS())
			continue;
		return i;
	}
	return -1;
}
