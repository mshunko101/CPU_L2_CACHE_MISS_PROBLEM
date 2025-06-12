#include "tree.h"

std::ostream& operator<<(std::ostream& o, tree& tree)
{
	for (auto i = tree.m_tree.begin(); i != tree.m_tree.end(); ++i)
	{
		o << (*i)<< std::endl;
	}
	return o;
}

tree& operator>>(tree& tree, bbs& item)
{
	tree.m_tree.push_back(item);
	std::sort(tree.m_tree.begin(), tree.m_tree.end(), std::less<bbs>());
	return tree;
}

tree::tree()
{
	
}

tree::~tree()
{

}


size_t tree::size()
{
	return m_tree.size();
}