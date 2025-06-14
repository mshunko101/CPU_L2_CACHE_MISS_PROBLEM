#include "tree.h"

static bss_classic m_sorter;

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
	return tree;
}


void tree::commit()
{
	bss_classic sort;
	std::sort(m_tree.begin(), m_tree.end(), sort);
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