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
	string customer; //��������
	string type_work; //��� ������������ �����
	int scope_work; //����� �����
	int time_work; //����������������� ������
	int price_work; //��������� �����
	string name; //��� ��������������
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
		cout << "�������� �������� : " << endl;
		cin >> var_menu;
		switch (var_menu)
		{
		case 1:
			cout << "������� ��� ���������" << endl;
			cin >> customer;
			menu.print_line();
			cout << "������� ��� ������������ ������" << endl;
			cin >> type_work;
			menu.print_line();
			cout << "������� ����� �����" << endl;
			cin >> scope_work;
			menu.print_line();
			cout << "������� ����������������� �����" << endl;
			cin >> time_work;
			menu.print_line();
			cout << "������� ��������� ������" << endl;
			cin >> price_work;
			menu.print_line();
			cout << "������� ��� ��������������" << endl;
			cin >> first_name;
			menu.print_line();
			cout << "������� ������� �������������" << endl;
			cin >> second_name;
			menu.print_line();
			cout << "������� �������� ��������������" << endl;
			cin >> third_name;
			menu.print_line();
			name = first_name + " " + second_name + " " + third_name;
			company.in_date(customer, type_work, scope_work, time_work, price_work, name);
			arr_company.push_back(company);
			cout << "������ ������ ������" << endl;
			break;
		case 2:
			if (arr_company.empty())
			{
				cout << "� ������� ��� ��������" << endl;
			}
			else
			{
				cout << "��������� ������� ��� �������� : " << endl;
				count = 1;
				for (auto& el : arr_company)
				{
					cout << "����� ������� - " << count << endl;
					count++;
				}
				cout << "�������� ������ ��� �������� : " << endl;
				cin >> var_delete;
				if (var_delete != 0 && var_delete < count + 1)
				{
					arr_company.erase(arr_company.begin() + var_delete-1);
					cout << "������ ������" << endl;
				}
				else
				{
					cout << "������ �� ������" << endl;
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
				cout << "� ������� ��� ��������" << endl;
			}
			else
			{
				cout << "��������� ���� ��� ������ ������������� �������� : " << endl;
				menu.print_field_for_max_or_min();
				cin >> var_find;
				if (var_find != 0 && var_find < 4)
				{
					result = company.find_max(&arr_company, var_find);
					cout << "������������ ������� = " << result << endl;
				}
				else
				{
					cout << "������� ������� ����" << endl;
				}
			}
			break;
		case 7:
			if (arr_company.empty())
			{
				cout << "� ������� ��� ��������" << endl;
			}
			else
			{
				cout << "��������� ���� ��� ������ ������������ �������� : " << endl;
				menu.print_field_for_max_or_min();
				cin >> var_find;
				if (var_find != 0 && var_find < 4)
				{
					result = company.find_min(&arr_company, var_find);
					cout << "����������� ������� = " << result << endl;
				}
				else
				{
					cout << "������� ������� ����" << endl;
				}
			}
			break;
		case 8:
			break;
		case 9:
			if (arr_company.empty())
			{
				cout << "� ������� ��� ��������" << endl;
			}
			else
			{
				count = 1;
				for (auto& el : arr_company)
				{
					menu.print_doubleLine();
					cout << "����� ������� - " << count << endl;
					el.print_field();
					count++;
					menu.print_doubleLine();
				}
			}
			break;
		case 10:
			exit = true; 
			menu.print_doubleLine();
			cout << "��������� ���������" << endl;
			menu.print_doubleLine();
			cout << "������� ������ ������������ ���-22�1" << endl;
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
	cout << "�������� : " << customer << endl;
	cout << "��� ������������ ����� : " << type_work << endl;
	cout << "����� ����� : " << scope_work << endl;
	cout << "����������������� ����� : " << time_work << endl;
	cout << "��������� ����� : " << price_work << endl;
	cout << "��� �������������� : " << name << endl;
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
		cout << "���� ������� ������" << endl;
		for (auto& el : *company)
		{
			file << el.customer;
			file << el.type_work;
			file << el.scope_work;
			file << el.time_work;
			file << el.price_work;
			file << el.name;
		}
		cout << "������ ������� �������� � ����" << endl;
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}

void Menu::print_info()
{
	cout << "��������� ��������" << endl;
	cout << "1 - ���� ������" << endl;
	cout << "2 - �������� ������" << endl;
	cout << "3 - ���������� ������ � ����" << endl;
	cout << "4 - ������ ������ �� �����" << endl;
	cout << "5 - ����� �� �����" << endl;
	cout << "6 - ����� ������������� ��������" << endl;
	cout << "7 - ����� ������������ ��������" << endl;
	cout << "8 - C��������� �� �����" << endl;
	cout << "9 - ����� ���� ������" << endl;
	cout << "10 - ����� �� ���������" << endl;
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
	cout << "1 - ����� ������" << endl;
	cout << "2 - ����������������� ������" << endl;
	cout << "3 - ��������� ������" << endl;
}
