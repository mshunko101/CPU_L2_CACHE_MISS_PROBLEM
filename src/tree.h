#pragma once
#include <iostream>
#include <vector>
#include "bbs.h"

class tree;

std::ostream& operator<<(std::ostream& o, tree& tree);
tree& operator>>(tree& tree, bbs& item);

class tree
{
public:
	tree();
	~tree();
	size_t size();
private:
	friend std::ostream& operator<<(std::ostream& o, tree& tree);
	friend tree& operator>>(tree& tree, bbs& item);
	std::vector<bbs> m_tree;
};

