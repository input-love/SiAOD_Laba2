#include "Console.h"

void Console::start()
{
	try
	{
		create_tree();
		menu();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}


void Console::create_tree()
{
	std::ifstream fin("Tree.txt");
	if (!fin.is_open()) 
	{
		throw std::exception("Нет такого файла...");
	}
	else 
	{
		std::string key;
		int data;
		while (fin >> key >> data)
		{
			_tree.push(key, data);
		}
	}
	fin.close();
}


void Console::menu()
{
	bool operation = true;
	while (operation)
	{
		print_menu();

		int check = dialog_get_data();

		switch (check)
		{
		case 1:
			dialog_check_tree_rec();
			break;
		case 2:
			dialog_check_tree_no_rec();
			break;
		case 3:
			dialog_print_tree();
			break;
		case 4:
			operation = false;
		}
	}
}


void Console::dialog_check_tree_rec()
{
	if (_tree.check_tree_rec())
	{
		std::cout << "Да, отсортирован" << std::endl;
	}
	else
	{
		std::cout << "Нет, не отсортирован" << std::endl;
	}
}

void Console::dialog_check_tree_no_rec()
{
	if (_tree.check_tree_no_rec())
	{
		std::cout << "Да, отсортирован" << std::endl;
	}
	else
	{
		std::cout << "Нет, не отсортирован" << std::endl;
	}
}

void Console::dialog_print_tree()
{
	std::vector<int> vec;

	_tree.print_tree(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec.at(i) << std::endl;
	}
}


int Console::dialog_get_data()
{
	int data;
	std::cin >> data;
	return data;
}

void Console::print_menu()
{
	std::cout << "------------------" << std::endl;
	std::cout << "1. Проверка дерева - рекурсивно" << std::endl;
	std::cout << "2. Проверка дерева - не рекурсивно" << std::endl;
	std::cout << "3. Вывод дерева" << std::endl;
	std::cout << "4. Выход" << std::endl;
	std::cout << "------------------" << std::endl;
}