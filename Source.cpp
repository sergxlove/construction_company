#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class Construction_company
{
public:
	Construction_company();//�����������
	Construction_company(string customer, string type_work, int scope_work, int time_work, int price_work, string name);//����������� � �����������
	~Construction_company();//����������
	void in_data();//���� ������
	void print_field();//������ �����
	int find_max(vector<Construction_company>& arr_company, int var_find);//����� �������������
	int find_min(vector<Construction_company>& arr_company, int var_find);//����� ������������
	void write_file(string path, vector<Construction_company>& company);//������ � ����
	void read_file(string path, vector<Construction_company>& company);//������ �� �����
	void search_field(vector<Construction_company>& company, int var_field, string field);//����� �� ����
	void sort_field(vector<Construction_company>& company, int var_field);//���������� �� ����
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
	void print_info();//������ ��������� ��������
	void print_line();//������ �����
	void print_doubleLine();//������ ������� �����
	void print_field_for_max_or_min();//������ ��������� ����� ��� ����������� ��������� ��� ��������
	void print_field();//������ ��������� �����
private:
};
int main()
{
	setlocale(LC_ALL, "rus");
	Menu menu;
	Construction_company company;
	int var_menu, var_switch;
	var_menu = var_switch = 0;
	bool exit = false;
	vector<Construction_company> arr_company;
	string name_field;
	int result = 0;
	int count = 1;
	string path = "data_company.txt";
	menu.print_doubleLine();
	menu.print_info();
	menu.print_doubleLine();
	company.read_file(path, arr_company);
	while (exit!=true)
	{
		cout << "�������� �������� : " << endl;
		cin >> var_menu;
		switch (var_menu)
		{
		case 1:
			
			company.in_data();
			arr_company.push_back(company);
			cout << "������ ������ ������" << endl;
			break;
		case 2:
			menu.print_line();
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
				cin >> var_switch;
				if (var_switch != 0 && var_switch < count + 1)
				{
					arr_company.erase(arr_company.begin() + var_switch-1);
					cout << "������ ������" << endl;
					company.write_file(path, arr_company);
				}
				else
				{
					cout << "������ �� ������" << endl;
				}
			}
			menu.print_line();
			break;
		case 3:
			menu.print_line();
			if (arr_company.empty())
			{
				cout << "� ������� ��� ��������" << endl;
			}
			else
			{
				company.write_file(path,arr_company);
			}
			break;
			menu.print_line();
		case 4:
			menu.print_line();
			company.read_file(path, arr_company);
			menu.print_line();
			break;
		case 5:
			menu.print_line();
			menu.print_field();
			cout << "�������� ���� �� �������� ������ �������� �����" << endl;
			cin >> var_switch;
			cout << "����� ���������� ������� ����" << endl;
			cin >> name_field;
			company.search_field(arr_company, var_switch, name_field);
			menu.print_line();
			break;
		case 6:
			menu.print_line();
			if (arr_company.empty())
			{
				cout << "� ������� ��� ��������" << endl;
			}
			else
			{
				cout << "��������� ���� ��� ������ ������������� �������� : " << endl;
				menu.print_field_for_max_or_min();
				cin >> var_switch;
				if (var_switch != 0 && var_switch < 4)
				{
					result = company.find_max(arr_company, var_switch);
					cout << "������������ ������� = " << result << endl;
				}
				else
				{
					cout << "������� ������� ����" << endl;
				}
			}
			menu.print_line();
			break;
		case 7:
			menu.print_line();
			if (arr_company.empty())
			{
				cout << "� ������� ��� ��������" << endl;
			}
			else
			{
				cout << "��������� ���� ��� ������ ������������ �������� : " << endl;
				menu.print_field_for_max_or_min();
				cin >> var_switch;
				if (var_switch != 0 && var_switch < 4)
				{
					result = company.find_min(arr_company, var_switch);
					cout << "����������� ������� = " << result << endl;
				}
				else
				{
					cout << "������� ������� ����" << endl;
				}
			}
			menu.print_line();
			break;
		case 8:
			menu.print_line();
			menu.print_field();
			cout << "�������� ���� �� �������� ������ �������� ����������" << endl;
			cin >> var_switch;
			company.sort_field(arr_company, var_switch);
			cout << "���� �������������" << endl;
			menu.print_line();
			break;
		case 9:
			menu.print_line();
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
			menu.print_line();
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
			menu.print_field();
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
void Construction_company::in_data()
{
	Menu menu;
	string first_name, second_name, third_name;
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
	cout << "������� ������� ��������������" << endl;
	cin >> first_name;
	menu.print_line();
	cout << "������� ��� �������������" << endl;
	cin >> second_name;
	menu.print_line();
	cout << "������� �������� ��������������" << endl;
	cin >> third_name;
	menu.print_line();
	name = first_name + " " + second_name + " " + third_name;
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
int Construction_company::find_max(vector<Construction_company> &arr_company, int var_find)
{
	int max = 0;
	if (var_find == 1)
	{
		for (auto& el : arr_company)
		{
			if (el.scope_work > max)
			{
				max = el.scope_work;
			}
		}
	}
	else if (var_find == 2)
	{
		for (auto& el : arr_company)
		{
			if (el.time_work > max)
			{
				max = el.time_work;
			}
		}
	}
	else if (var_find == 3)
	{
		for (auto& el : arr_company)
		{
			if (el.price_work > max)
			{
				max = el.time_work;
			}
		}
	}
	return max;
}
int Construction_company::find_min(vector<Construction_company> &arr_company, int var_find)
{
	int min = 100000;
	if (var_find == 1)
	{
		for (auto& el : arr_company)
		{
			if (el.scope_work < min)
			{
				min = el.scope_work;
			}
		}
	}
	else if (var_find == 2)
	{
		for (auto& el : arr_company)
		{
			if (el.time_work < min)
			{
				min = el.scope_work;
			}
		}
	}
	else if (var_find == 3)
	{
		for (auto& el : arr_company)
		{
			if (el.price_work < min)
			{
				min = el.price_work;
			}
		}
	}
	return min;
}
void Construction_company::write_file(string path, vector<Construction_company>& company)
{
	fstream file;
	file.open(path, fstream::out);
	if (file.is_open())
	{
		file << company.size() << "\n";
		for (auto& el : company)
		{
			file << el.customer << "\n";
			file << el.type_work << "\n";
			file << el.scope_work << "\n";
			file << el.time_work << "\n";
			file << el.price_work << "\n";
			file << el.name << "\n";
		}
		cout << "������ ������� ��������" << endl;
		file.close();
	}
}
void Construction_company::read_file(string path, vector<Construction_company>& company)
{
	fstream file;
	string str;
	Construction_company comp;
	int size = 0;
	file.open(path, fstream::in);
	if (file.is_open())
	{
		company.clear();
		getline(file, str);
		size = stoi(str);
		for (int i = 0;i < size;i++)
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
			company.push_back(comp);
		}
		cout << "������ ������� ������� �� �����" << endl;
		file.close();
	}
	
}
void Construction_company::search_field(vector<Construction_company>& company, int var_field, string field)
{
	for (auto& el : company)
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
			cout << "���� �� �������" << endl;
			break;
		}
	}
}
void Construction_company::sort_field(vector<Construction_company>& company, int var_field)
{
	switch (var_field)
	{
	case 1:
		sort(company.begin(), company.end(), [](const Construction_company &c1, const Construction_company & c2) { return c1.customer > c2.customer; });
		break;
	case 2:
		sort(company.begin(), company.end(), [](const Construction_company& c1, const Construction_company& c2) { return c1.type_work > c2.type_work; });
		break;
	case 3:
		sort(company.begin(), company.end(), [](const Construction_company& c1, const Construction_company& c2) { return c1.scope_work > c2.scope_work; });
		break;
	case 4:
		sort(company.begin(), company.end(), [](const Construction_company& c1, const Construction_company& c2) { return c1.time_work > c2.time_work; });
		break;
	case 5:
		sort(company.begin(), company.end(), [](const Construction_company& c1, const Construction_company& c2) { return c1.price_work > c2.price_work; });
		break;
	case 6:
		sort(company.begin(), company.end(), [](const Construction_company& c1, const Construction_company& c2) { return c1.name > c2.name; });
		break;
	default:
		break;
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
void Menu::print_field()
{
	cout << "��������� ����" << endl;
	cout << "1 - ��������" << endl;
	cout << "2 - ��� ������������ �����" << endl;
	cout << "3 - ����� �����" << endl;
	cout << "4 - ����������������� �����" << endl;
	cout << "5 - ��������� �����" << endl;
	cout << "6 - ��� ��������������" << endl;
}
