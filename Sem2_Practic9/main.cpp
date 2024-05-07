#include <iostream>
#include "Smartphone.h"

/*9. Добавьте в программу возможность продажи смартфонов
(из числа имеющихся в наличии). При этом должна вестись отчетность
о проданных смартфонах с возможностью вывода отчета за указанный
интервал дат.*/

int main() {
	using std::cout;
	SmartphoneSpec spSpec = SmartphoneSpec(Manufacturer::SAMSUNG, Color::GOLD, 6.2, 8, 128, CPU::SNAPDRAGON, OS::ANDROID);
	Smartphone sp = Smartphone("Samsung Galaxy S20", 399, spSpec);
	Smartphone sp2 = Smartphone("Samsung Galaxy S20", 399, spSpec);
	if (sp == sp2)
		cout << "True!";
	else
		cout << "False!";
}