#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Construction_company
{
public:
	Construction_company();
	Construction_company(string customer, string type_work, int scope_work, int time_work, int price_work, string name);
	~Construction_company();
	void in_date(string customer, string type_work, int scope_work, int time_work, int price_work, string name);
	void print_field();
	int find_max(vector<Construction_company> *arr_company, int var_find);
	int find_min(vector<Construction_company> *arr_company, int var_find);
	void write_file(string path, vector<Construction_company> *company);
private:
	string customer; //заказчик
	string type_work; //тип строительных работ
	int scope_work; //объем работ
	int time_work; //продолжительность работы
	int price_work; //стоимость работ
	string name; //фио ответственного
};
class Menu
{
public:
	void print_info();
	void print_line();
	void print_doubleLine();
	void print_field_for_max_or_min();
private:
};
int main()
{
	setlocale(LC_ALL, "rus");
	Menu menu;
	int var_menu = 0;
	int var_delete = 0;
	int var_find = 0;
	bool exit = false;
	int result = 0;
	vector<Construction_company> arr_company;
	Construction_company company;
	string customer = "";
	string type_work = "";
	int scope_work = 0;
	int time_work = 0; 
	int price_work = 0; 
	string name = "";
	string first_name = "";
	string second_name = "";
	string third_name = "";
	int count = 1;
	string path = "data_company.txt";
	menu.print_doubleLine();
	menu.print_info();
	menu.print_doubleLine();
	while (exit!=true)
	{
		cout << "Выберите действие : " << endl;
		cin >> var_menu;
		switch (var_menu)
		{
		case 1:
			cout << "Введите имя заказчика" << endl;
			cin >> customer;
			menu.print_line();
			cout << "Введите тип строительных работы" << endl;
			cin >> type_work;
			menu.print_line();
			cout << "Введите объем работ" << endl;
			cin >> scope_work;
			menu.print_line();
			cout << "Введите продолжительность работ" << endl;
			cin >> time_work;
			menu.print_line();
			cout << "Введите стоимость работы" << endl;
			cin >> price_work;
			menu.print_line();
			cout << "Введите имя ответственного" << endl;
			cin >> first_name;
			menu.print_line();
			cout << "Введите фамилию ответсвенного" << endl;
			cin >> second_name;
			menu.print_line();
			cout << "Введите отчество ответственного" << endl;
			cin >> third_name;
			menu.print_line();
			name = first_name + " " + second_name + " " + third_name;
			company.in_date(customer, type_work, scope_work, time_work, price_work, name);
			arr_company.push_back(company);
			cout << "Объект класса создан" << endl;
			break;
		case 2:
			if (arr_company.empty())
			{
				cout << "В векторе нет объектов" << endl;
			}
			else
			{
				cout << "Доступные объекты для удаления : " << endl;
				count = 1;
				for (auto& el : arr_company)
				{
					cout << "Номер объекта - " << count << endl;
					count++;
				}
				cout << "Выберите объект для удаления : " << endl;
				cin >> var_delete;
				if (var_delete != 0 && var_delete < count + 1)
				{
					arr_company.erase(arr_company.begin() + var_delete-1);
					cout << "Объект удален" << endl;
				}
				else
				{
					cout << "Объект не найден" << endl;
				}
			}
			break;
		case 3:
			company.write_file(path, &arr_company);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			if (arr_company.empty())
			{
				cout << "В векторе нет объектов" << endl;
			}
			else
			{
				cout << "Доступные поля для поиска максимального элемента : " << endl;
				menu.print_field_for_max_or_min();
				cin >> var_find;
				if (var_find != 0 && var_find < 4)
				{
					result = company.find_max(&arr_company, var_find);
					cout << "Максимальный элемент = " << result << endl;
				}
				else
				{
					cout << "Неверно выбрано поле" << endl;
				}
			}
			break;
		case 7:
			if (arr_company.empty())
			{
				cout << "В векторе нет объектов" << endl;
			}
			else
			{
				cout << "Доступные поля для поиска минимального элемента : " << endl;
				menu.print_field_for_max_or_min();
				cin >> var_find;
				if (var_find != 0 && var_find < 4)
				{
					result = company.find_min(&arr_company, var_find);
					cout << "Минимальный элемент = " << result << endl;
				}
				else
				{
					cout << "Неверно выбрано поле" << endl;
				}
			}
			break;
		case 8:
			break;
		case 9:
			if (arr_company.empty())
			{
				cout << "В векторе нет объектов" << endl;
			}
			else
			{
				count = 1;
				for (auto& el : arr_company)
				{
					menu.print_doubleLine();
					cout << "Номер объекта - " << count << endl;
					el.print_field();
					count++;
					menu.print_doubleLine();
				}
			}
			break;
		case 10:
			exit = true; 
			menu.print_doubleLine();
			cout << "Программа завершена" << endl;
			menu.print_doubleLine();
			cout << "Лучинин Сергей Владимирович АСб-22э1" << endl;
			menu.print_doubleLine();
			break;
		default:
			break;
		}
	}
	return 0;
}

Construction_company::Construction_company()
{
	this->customer = "";
	this->type_work = "";
	this->scope_work = 0;
	this->time_work = 0;
	this->price_work = 0;
	this->name = "";
}

Construction_company::Construction_company(string customer, string type_work, int scope_work, int time_work, int price_work, string name)
{
	this->customer = customer;
	this->type_work = type_work;
	this->scope_work = scope_work;
	this->time_work = time_work;
	this->price_work = price_work;
	this->name = name;
}

Construction_company::~Construction_company()
{
	this->customer = "";
	this->type_work = "";
	this->scope_work = 0;
	this->time_work = 0;
	this->price_work = 0;
	this->name = "";
}

void Construction_company::in_date(string customer, string type_work, int scope_work, int time_work, int price_work, string name)
{
	this->customer = customer;
	this->type_work = type_work;
	this->scope_work = scope_work;
	this->time_work = time_work;
	this->price_work = price_work;
	this->name = name;
}

void Construction_company::print_field()
{
	cout << "Заказчик : " << customer << endl;
	cout << "Тип строительных работ : " << type_work << endl;
	cout << "Объем работ : " << scope_work << endl;
	cout << "Продолжительность работ : " << time_work << endl;
	cout << "Стоимость работ : " << price_work << endl;
	cout << "ФИО ответственного : " << name << endl;
}

int Construction_company::find_max(vector<Construction_company> *arr_company, int var_find)
{
	int max = 0;
	if (var_find == 1)
	{
		for (auto& el : *arr_company)
		{
			if (el.scope_work > max)
			{
				max = el.scope_work;
			}
		}
	}
	else if (var_find == 2)
	{
		for (auto& el : *arr_company)
		{
			if (el.time_work > max)
			{
				max = el.time_work;
			}
		}
	}
	else if (var_find == 3)
	{
		for (auto& el : *arr_company)
		{
			if (el.price_work > max)
			{
				max = el.time_work;
			}
		}
	}
	return max;
}

int Construction_company::find_min(vector<Construction_company> *arr_company, int var_find)
{
	int min = 100000;
	if (var_find == 1)
	{
		for (auto& el : *arr_company)
		{
			if (el.scope_work < min)
			{
				min = el.scope_work;
			}
		}
	}
	else if (var_find == 2)
	{
		for (auto& el : *arr_company)
		{
			if (el.time_work < min)
			{
				min = el.scope_work;
			}
		}
	}
	else if (var_find == 3)
	{
		for (auto& el : *arr_company)
		{
			if (el.price_work < min)
			{
				min = el.price_work;
			}
		}
	}
	return min;
}

void Construction_company::write_file(string path, vector<Construction_company> *company)
{
	fstream file;
	file.open(path, fstream::out | fstream::app);
	if (file.is_open())
	{
		cout << "Файл успешно открыт" << endl;
		for (auto& el : *company)
		{
			file << el.customer;
			file << el.type_work;
			file << el.scope_work;
			file << el.time_work;
			file << el.price_work;
			file << el.name;
		}
		cout << "Данные успешно записаны в файл" << endl;
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void Menu::print_info()
{
	cout << "Доступные действия" << endl;
	cout << "1 - Ввод данных" << endl;
	cout << "2 - Удаление данных" << endl;
	cout << "3 - Сохранение данных в файл" << endl;
	cout << "4 - Чтение данных из файла" << endl;
	cout << "5 - Поиск по полям" << endl;
	cout << "6 - Поиск максимального элемента" << endl;
	cout << "7 - Поиск минимального элемента" << endl;
	cout << "8 - Cортировка по полям" << endl;
	cout << "9 - Вывод всех данных" << endl;
	cout << "10 - Выход из программы" << endl;
}

void Menu::print_line()
{
	for (int i = 0;i < 80;++i)
	{
		cout << "-";
	}
	cout << endl;
}

void Menu::print_doubleLine()
{
	print_line();
	print_line();
}

void Menu::print_field_for_max_or_min()
{
	cout << "1 - Объем работы" << endl;
	cout << "2 - Продолжительность работы" << endl;
	cout << "3 - Стоимость работы" << endl;
}
