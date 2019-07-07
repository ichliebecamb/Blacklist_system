#include "UserContral.h"
UserContral *UserContral::PContral = NULL;
UserContral * UserContral::getContral()
{
	if (NULL== PContral)
	{
		PContral = new UserContral;
	}
	return PContral;
}

void UserContral::process(int n)
{
}

UserContral::UserContral()
{
	Pmodel = new UserModel;
}

UserContral::~UserContral()
{
}
