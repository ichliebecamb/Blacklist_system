#include "UserSys.h"
const int INCREMENT = 10;
UserSys* UserSys::PuserSys = NULL;
UserSys* UserSys::getPuserSys()
{
	if (NULL == PuserSys)
	{
		PuserSys = new UserSys;
	}
	return nullptr;
}

void UserSys::run()
{
	int feature;
	while (true)
	{
		put();
		cin >> feature;
		feature += INCREMENT;
		if (feature <= EXIT&&feature >= ADD)
		{
			Contral::getContral()->process(feature);
		}
		else
		{
			cout << "please input a right number!" << endl;
		}
	}
}

void UserSys::put()
{
	cout << "please choose the feature." << endl;
	cout << ADD - INCREMENT << ",    ADD" << endl;
	cout << DELETE - INCREMENT << ",    DELETE" << endl;
	cout << SELECT - INCREMENT << ",    SELECT" << endl;
	cout << FIX - INCREMENT << ",    FIX" << endl;
	cout << EXIT - INCREMENT << ",    EXIT" << endl;
	cout << "please input the number!" << endl;
	cout << "number = ";
}
