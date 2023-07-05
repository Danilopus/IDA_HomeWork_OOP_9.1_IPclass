// HomeWork template project v 6.0 // 27.06.2023 //

/*

Основы ООП на языке С++
Перегрузка операторов

Задание Основное

1. Задача проверки валидности IP-адреса:
Создайте класс "IP-адрес", который имеет переменные-члены для каждого
октета IP-адреса.
Реализуйте перегрузку оператора ввода ( >> ), чтобы пользователь мог
вводить IP-адрес с клавиатуры.
Напишите метод-член класса, который проверяет, является ли введенный IP-
адрес валидным (соответствует формату xxx.xxx.xxx.xxx и значения каждого
октета находятся в диапазоне от 0 до 255).

2. Задача проверки принадлежности IP-адреса к подсети:
Создайте класс "Маска сети", который имеет переменные-члены для каждого
октета маски.
Реализуйте перегрузку оператора ввода ( >> ), чтобы пользователь мог
вводить маску сети с клавиатуры.
Добавьте метод-член класса "Маска сети", который проверяет, принадлежит
ли заданный IP-адрес данной маске сети. Например, метод может проверять,
совпадают ли первые N битов IP-адреса с первыми N битами маски сети.
+
3. Задача получения сетевого адреса:
Добавьте метод-член класса "IP-адрес", который возвращает сетевой адрес,
используя заданную маску сети. Например, если IP-адрес - 192.168.1.100,
а маска сети - 255.255.255.0, сетевой адрес будет 192.168.1.0.
+
4. Задача сравнения IP-адресов:
Реализуйте перегрузку оператора сравнения ( == ) для класса "IP-адрес",
чтобы можно было проверять равенство двух IP-адресов.
Реализуйте перегрузку оператора сравнения ( < ) для класса "IP-адрес",
чтобы можно было сравнивать IP-адреса и определять, является ли один IP-
адрес меньшим или большим по сравнению с другим.
+
5. Задача подсчета количества возможных узлов в сети:
Добавьте метод-член класса "Маска сети", который вычисляет количество
возможных узлов в сети, используя заданную маску. Например, для маски
255.255.255.0 количество возможных узлов будет 254.
*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
#include "IP_adress_UnitTest.h"
//#include "IP_adress.h"
//#include "Net_mask.h"
//#include "Struct_IP.h"



// Homework OOP 09 ----------------------------------------------------	


//Task 1 IP_adress class demo with overloaded operators: == | < | > 
void Task_1(std::string name_of_task)
{
	do
	{		
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";					
	
		std::cout << IP_adress_UnitTest::main_test();

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

//Task 2
void Task_2(std::string name_of_task)
{
	do
	{
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";

		//if (Flat_Handle::Mode_Input_Handle()) break;

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

//Task 3 
void Task_3() {}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 09: ");	// Homework name
	MainMenu.AddElement("IP_adress class demo with overloaded operators: == | < | > ");
	MainMenu.AddElement("Calculator class demo with overloaded operators: = | == | < | > ");

	//MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

