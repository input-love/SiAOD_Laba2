#pragma once
#include <iostream>
#include <fstream>
#include "Tree.h"

class Console
{
public:
	void start();
private:
	void create_tree();

	void menu();

	void dialog_check_tree_rec();
	void dialog_check_tree_no_rec();
	void dialog_print_tree();

	int dialog_get_data();
	void print_menu();

	Tree _tree;
};