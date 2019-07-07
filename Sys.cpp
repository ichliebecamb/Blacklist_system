#include "Sys.h"
#include"root_enum.h"
#include <iostream>
#include "Contral.h"
using namespace std;

void Sys::put()
{
	cout << "please choose the feature." << endl;
	cout << LOGIN    << ",    LOGIN" << endl;
	cout << REGISTER << ",    REGISTER" << endl;
	cout << S_EXIT     << ",    EXIT" << endl;
	cout << "please input the number!" << endl;
	cout << "number = ";
}

void Sys::run()
{
	int feature;
	while (true)
	{
		put();
		cin >> feature;
		if (feature<=EXIT&&feature>= LOGIN)
		{
			Contral::getContral()->process(feature);
		}
		else
		{
			cout << "please input a right number!" << endl;
		}
	}
}
