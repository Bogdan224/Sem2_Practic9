#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <io.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

//Part1_B
void AddToList(List** head) {
	system("cls");
	PersonalComputer* pc = (PersonalComputer*)malloc(sizeof(PersonalComputer));
	float displaySize, ram;
	char* cpu = (char*)malloc(20), * os = (char*)malloc(20);
	printf("Введите размер экрана(дюймы): ");
	scanf_s("%f", &displaySize);
	printf("Введите размер ОЗУ(гб): ");
	scanf_s("%f", &ram);
	getchar();
	printf("Введите название процессора: ");
	gets_s(cpu, 20);
	printf("Введите название ОС: ");
	gets_s(os, 20);

	Init(pc, displaySize, ram, cpu, os);
	Push_back(pc, head);
}
//Part1_B
void PrintList(List* head) {
	system("cls");
	for (size_t i = 0; i < Size(head); i++)
	{
		printf("Компьютер %d\n", i);
		Print(GetElementByPos(head, i));
	}
}
//Part1_B
void DeleteFromList(List** head) {
	system("cls");
	printf("Введите индекс элемента, который вы хотите удалить: ");
	int pos;
	scanf_s("%d", &pos);

	if (DeleteByPos(*head, pos) == 0) {
		printf("Элемент успешно удален!\n");
	}
	else {
		printf("При удалении элемента произошла ошибка, возможно вы указали неверный индекс!\n");
	}
}

//Part1_C
void WriteToFile(List* head) {
	char pathname[] = "file.txt";
	int fd = _open(pathname, O_CREAT | O_WRONLY, S_IWRITE);
	if (fd == -1) {
		printf("The file was not opened!");
		return;
	}
	while (head != NULL) {
		int cnt = _write(fd, &head->pc->displaySize, sizeof(head->pc->displaySize));
		cnt = _write(fd, &head->pc->ram, sizeof(head->pc->ram));
		cnt = _write(fd, &head->pc->cpu, sizeof(head->pc->cpu));
		cnt = _write(fd, &head->pc->os, sizeof(head->pc->os));
		head = head->next;
	}
	_close(fd);
}

List* ReadFromFile() {
	char pathname[] = "file.txt";
	int fd = _open(pathname, O_RDONLY, S_IREAD);
	if (fd == -1) {
		printf("The file was not opened!");
		return NULL;
	}
	List* head = NULL;
	while (true) {
		PersonalComputer* pc = (PersonalComputer*)malloc(sizeof(PersonalComputer));
		float displaySize, ram;	
		int cnt = _read(fd, &displaySize, sizeof(displaySize));
		cnt = _read(fd, &ram, sizeof(ram));
		char cpu[20], os[20];
		cnt = _read(fd, &cpu, 20);
		cnt = _read(fd, &os, 20);
		if (cnt == 0) {
			return head;
		}
		Init(pc, displaySize, ram, cpu, os);
		Push_back(pc, &head);
	}
	return head;
}

void Part1_A() {
	PersonalComputer pc1, pc2, pc3, pc4;
	Init(&pc1, 20, 8, "AMD", "Linux");
	Init(&pc2, 16, 4, "AMD", "MacOS");
	Init(&pc3, 24, 16, "Intel", "Windows");
	Init(&pc4, 20, 8, "AMD", "Linux");

	Print(&pc1);
	Print(&pc2);
	Print(&pc3);
	Print(&pc4);

	if (Equals(&pc1, &pc4)) {
		printf("Equals!\n");
	}

	if (Less(&pc2, &pc3)) {
		printf("Less!\n");
	}

	List* head = NULL;
	Push_back(&pc1, &head);
	Push_back(&pc2, &head);
	Push_back(&pc3, &head);
	//Push_back(&pc3, &head);

	printf("%d\n", Size(head));
	DeleteByPos(head, 1);
	Print(GetElementByPos(head, 1));
}

void Part1_B() {
	List* head = ReadFromFile();
	while (true) {
		system("cls");
		printf("Добро пожаловать!\n1)Добавить компьютер в список\n2)Вывести сведения об объектах в списке\n3)Удалить элемент по позиции в списке\n0)Выйти\nВведите номер действия -> ");
		int choise;
		scanf_s("%d", &choise);
		switch (choise)
		{
		case 1:
			AddToList(&head);
			break;
		case 2:
			PrintList(head);
			break;
		case 3:
			DeleteFromList(&head);
			break;
		case 0:
			WriteToFile(head);
			return;
		default:
			break;
		}
		system("pause");
	}
}

int main(int, char**) {
	setlocale(LC_ALL, "rus");
	//Part1_A();
	Part1_B();
}