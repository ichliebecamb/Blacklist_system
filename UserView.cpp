#include "DataBase.h"
void viewExit();

void UserADD()
{
	Database::getbase()->AddBlack();
}

void UserDELETE()
{
	string id;
	cout << "please input the id needed deleted!" << endl;
	cin >> id;
	Database::getbase()->deleteBlack(id);
}

void UserSELECT()
{
	string id;
	cout << "please input the id needed selected!" << endl;
	cin >> id;
	Database::getbase()->selectBlack(id);
}

void UserFIX()
{
	string id;
	cout << "please input the id needed chaged!" << endl;
	cin >> id;
	Database::getbase()->changeBlack(id);
}

void UserEXIT()
{

	exit(0);
}
