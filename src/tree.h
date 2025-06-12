#pragma once
#include <iostream>
#include <vector>
#include "bbs.h"

class tree
{
public:
	tree();
	~tree();
	size_t size();
private:
	friend static std::ostream& operator<<(std::ostream& o, tree& tree);
	friend static tree& operator>>(tree& tree, bbs& item);
	std::vector<bbs> m_tree;
};

static std::ostream& operator<<(std::ostream& o, tree& tree)
{
	for (auto i = tree.m_tree.begin(); i != tree.m_tree.end(); ++i)
	{
		o << (*i)<<(*i).value();
		o << std::endl;
	}
	return o;
}
static tree& operator>>(tree& tree, bbs& item)
{
	tree.m_tree.push_back(item);
	std::sort(tree.m_tree.begin(), tree.m_tree.end(), std::less<bbs>());
	return tree;
}