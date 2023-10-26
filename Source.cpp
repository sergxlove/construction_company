#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
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
	void write_file(string path,string path_two, vector<Construction_company> *company);
	void read_file(string path, string path_two, vector<Construction_company>* company);
	void search_field(vector<Construction_company>* company, int var_field, string field);
	void sort_field(vector<Construction_company>* company, int var_field);
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
	void print_field();
private:
};
int main()
{
	setlocale(LC_ALL, "rus");
	Menu menu;
	int var_menu = 0;
	int var_delete = 0;
	int var_find = 0;
	int var_field = 0;
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
	string name_field = "";
	string path = "data_company.txt";
	string path_colEl = "colvo_el.txt";
	menu.print_doubleLine();
	menu.print_info();
	menu.print_doubleLine();
	company.read_file(path, path_colEl, &arr_company);
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
			menu.print_line();
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
			menu.print_line();
			break;
		case 3:
			menu.print_line();
			if (arr_company.empty())
			{
				cout << "В векторе нет объектов" << endl;
			}
			else
			{
				company.write_file(path,path_colEl, &arr_company);
			}
			break;
			menu.print_line();
		case 4:
			menu.print_line();
			company.read_file(path, path_colEl, &arr_company);
			menu.print_line();
			break;
		case 5:
			menu.print_line();
			menu.print_field();
			cout << "Выберите полу по которому хотите провести поиск" << endl;
			cin >> var_field;
			cout << "Введи содержимое данного поля" << endl;
			cin >> name_field;
			company.search_field(&arr_company, var_field, name_field);
			menu.print_line();
			break;
		case 6:
			menu.print_line();
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
			menu.print_line();
			break;
		case 7:
			menu.print_line();
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
			menu.print_line();
			break;
		case 8:
			menu.print_line();
			menu.print_field();
			cout << "Выберите полу по которому хотите провести сортировку" << endl;
			cin >> var_field;
			company.sort_field(&arr_company, var_field);
			menu.print_line();
			break;
		case 9:
			menu.print_line();
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
			menu.print_line();
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

void Construction_company::write_file(string path, string path_two,vector<Construction_company> *company)
{
	fstream file;
	fstream file_col;
	file.open(path, fstream::out | fstream::app);
	file_col.open(path_two, fstream::out);
	if (file.is_open()&&file_col.is_open())
	{
		cout << "Файл успешно открыт" << endl;
		for (auto& el : *company)
		{
			file << el.customer<<"\n";
			file << el.type_work<<"\n";
			file << el.scope_work<<"\n";
			file << el.time_work<<"\n";
			file << el.price_work<<"\n";
			file << el.name<<"\n";
		}
		file_col.clear();
		file_col << company->size();
		cout << "Данные успешно записаны в файл" << endl;
		file.close();
		file_col.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void Construction_company::read_file(string path, string path_two, vector<Construction_company>* company)
{
	fstream file;
	string str;
	fstream file_col;
	Construction_company comp;
	int count = 0;
	file.open(path, fstream::in);
	file_col.open(path_two, fstream::in);
	if (file.is_open()&&file_col.is_open())
	{
		cout << "Файл успешно открыт" << endl;
		getline(file_col, str);
		count = stoi(str);
		for (int i = 0;i < count;i++)
		{
			getline(file, comp.customer);
			getline(file, comp.type_work);
			getline(file, str);
			comp.scope_work = stoi(str);
			getline(file, str);
			comp.time_work = stoi(str);
			getline(file, str);
			comp.price_work = stoi(str);
			getline(file, comp.name);
			company->push_back(comp);
		}
		cout << "Данные успешно считаны из файла" << endl;
		file.close();
		file_col.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void Construction_company::search_field(vector<Construction_company>* company, int var_field, string field)
{
	for (auto& el : *company)
	{
		switch (var_field)
		{
		case 1:
			if (field == el.customer)
			{
				el.print_field();
			}
			break;
		case 2:
			if (field == el.type_work)
			{
				el.print_field();
			}
			break;
		case 3:
			if (stoi(field) == el.scope_work)
			{
				el.print_field();
			}
			break;
		case 4:
			if (stoi(field) == el.time_work)
			{
				el.print_field();
			}
			break;
		case 5:
			if (stoi(field) == el.price_work)
			{
				el.print_field();
			}
			break;
		case 6:
			if (field == el.name)
			{
				el.print_field();
			}
			break;
		default:
			break;
		}
	}
}

void Construction_company::sort_field(vector<Construction_company>* company, int var_field)
{
	switch (var_field)
	{
	case 1:
		sort(company->begin(), company->end(), [](const Construction_company &c1, const Construction_company & c2) {
			return c1.customer > c2.customer;
			});
		break;
	case 2:
		sort(company->begin(), company->end(), [](const Construction_company& c1, const Construction_company& c2) {
			return c1.type_work > c2.type_work;
			});
		break;
	case 3:
		sort(company->begin(), company->end(), [](const Construction_company& c1, const Construction_company& c2) {
			return c1.scope_work > c2.scope_work;
			});
		break;
	case 4:
		sort(company->begin(), company->end(), [](const Construction_company& c1, const Construction_company& c2) {
			return c1.time_work > c2.time_work;
			});
		break;
	case 5:
		sort(company->begin(), company->end(), [](const Construction_company& c1, const Construction_company& c2) {
			return c1.price_work > c2.price_work;
			});
		break;
	case 6:
		sort(company->begin(), company->end(), [](const Construction_company& c1, const Construction_company& c2) {
			return c1.name > c2.name;
			});
		break;
	default:
		break;
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

void Menu::print_field()
{
	cout << "Доступные поля" << endl;
	cout << "1 - Заказчик" << endl;
	cout << "2 - Тип строительных работ" << endl;
	cout << "3 - Объем работ" << endl;
	cout << "4 - Продолжительность работ" << endl;
	cout << "5 - Стоимость работ" << endl;
	cout << "6 - Фио ответственного" << endl;
}
