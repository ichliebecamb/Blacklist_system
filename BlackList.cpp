#include "BlackList.h"
BlackList* BlackList::PBlacklist = NULL;
BlackList::BlackList()
{
	B_listhead = new Node;
}
BlackList::~BlackList()
{
}
BlackList * BlackList::getblacklist()
{
	if (NULL == PBlacklist)
	{
		PBlacklist = new BlackList;
	}
	return PBlacklist;
}
