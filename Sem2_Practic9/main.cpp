#include <iostream>
#include "Smartphone.h"

/*9. �������� � ��������� ����������� ������� ����������
(�� ����� ��������� � �������). ��� ���� ������ ������� ����������
� ��������� ���������� � ������������ ������ ������ �� ���������
�������� ���.*/

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