#include "Tree.h"

Tree::~Tree()
{
	if (_head)
	{
		delete_tree(_head);
	}
}

void Tree::push(std::string& key, int data)
{
	if (!_head) 
	{ 
		_head = new Node();
		_head->_data = data;
	}
	else
	{
		Node* currentElement = move_on_tree(key);
		create_leaf_tree(currentElement, key, data);
	}
}    

void Tree::print_tree(std::vector<int>& vec)
{
	check_tree_no_rec(_head, vec);
}

bool Tree::check_tree_rec()
{
	bool flag = true;
	int data;

	check_tree_rec(_head, flag, data);

	return flag;
}

bool Tree::check_tree_no_rec()
{
	bool flag = true;

	std::vector<int> vec;

	check_tree_no_rec(_head, vec);

	for (int i = 0; i < vec.size() - 1; i++)
	{
		if (vec.at(i) > vec.at(i + 1))
		{
			flag = !flag;
			break;
		}
	}

	return flag;
}


Tree::Node* Tree::move_on_tree(std::string& key)
{
	Node* currentElement = _head;
	for (int i = 1; i < key.size() - 1; i++)
	{
		if (key[i] == '0')
		{
			currentElement = currentElement->_pLeft;
		}
		else
		{
			currentElement = currentElement->_pRight;
		}
	}
	return currentElement;
}

void Tree::create_leaf_tree(Node* currentElement, std::string& key, int data)
{
	if (key[key.size() - 1] == '0')
	{
		currentElement->_pLeft = new Node();
		currentElement->_pLeft->_data = data;
	}
	else
	{
		currentElement->_pRight = new Node();
		currentElement->_pRight->_data = data;
	}
}


void Tree::check_tree_rec(Node* currentElement, bool& flag, int& data)
{
	if (!currentElement)
	{
		return;
	}

	check_tree_rec(currentElement->_pLeft, flag, data);

	if (!flag)
	{
		return;
	}

	if (!currentElement->_pLeft && !currentElement->_pRight)
	{
		data = currentElement->_data;
		return;
	}
	else if (currentElement->_data > data)
	{
		data = currentElement->_data;
	}
	else
	{
		flag = !flag;
	}

	check_tree_rec(currentElement->_pRight, flag, data);
}

void Tree::check_tree_no_rec(Node* currentElement, std::vector<int>& vec)
{
	if (currentElement->_pLeft)
	{
		check_tree_no_rec(currentElement->_pLeft, vec);
	}

	vec.push_back(currentElement->_data);

	if (currentElement->_pRight)
	{
		check_tree_no_rec(currentElement->_pRight, vec);
	}
}


void Tree::delete_tree(Node* currentElement)
{
	if (currentElement->_pLeft)
	{
		delete_tree(currentElement->_pLeft);
	}

	if (currentElement->_pRight)
	{
		delete_tree(currentElement->_pRight);
	}

	delete currentElement;
}