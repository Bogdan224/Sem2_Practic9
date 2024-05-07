#pragma once

enum class Manufacturer {
	APPLE, SAMSUNG, XIAOMI, HTC, UNDEFINED
};
enum class Color {
	WHITE, GRAY, BLACK, BLUE, RED, GOLD, UNDEFINED
};
enum class OS {
	ANDROID, IOS, UNDEFINED
};
enum class CPU {
	SNAPDRAGON, APPLE, UNDEFINED
};

class SmartphoneSpec {
private:
	Manufacturer manufacturer;
	Color color;
	float displaySize;
	int ram;
	int storage;
	CPU cpu;
	OS os;
public:
	SmartphoneSpec();
	SmartphoneSpec(Manufacturer manufacturer, Color color, float displaySize, int ram, int storage, CPU cpu, OS os);
	Manufacturer getManufacturer() const;
	Color getColor() const;
	float getDisplay() const;
	int getRAM() const;
	int getStorage() const;
	CPU getCPU() const;
	OS getOS() const;

	bool operator==(const SmartphoneSpec& spec) const;
	bool operator!=(const SmartphoneSpec& spec) const;
};
