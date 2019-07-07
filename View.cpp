#include <iostream>
#include <string>
using namespace std;
#include "DataBase.h"
#include "UserSys.h"
void viewLogin()
{
	string id;
	string pw;
	cout << "please input you id." << endl;
	cout << "id= ";
	cin >> id;
	cout << "please input you password." << endl;
	cout << "password= ";
	cin >> pw;
	if (Database::getbase()->selectRoot(id,pw))
	{

		UserSys::getPuserSys()->run();
	}
	else
	{
		cout << "NOPOWER!" << endl;
	}
}

void viewRegister()
{
	string id;
	string pw, pw2;
	Database* data = Database::getbase();
	cout << "please input the id needed register." << endl;
	cout << "id= ";
	cin >> id;
	cout << "please input the password needed register." << endl;
	cout << "password= ";
	cin >> pw;
	cout << "please input the password agin." << endl;
	cout << "password= ";
	cin >> pw2;
	if (pw == pw2)
	{
		data->AddAdm(id, pw);
	}
	else
	{
		cout << "password wrong!" << endl;
	}
}

void viewExit()
{
	Database*p = Database::getbase();
	Contral *pC = Contral::getContral();
	delete pC;
	delete p;
	exit(0);
}
