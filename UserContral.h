#pragma once
#include "UserModel.h"
#include <iostream>
class UserContral
{
public:
	static UserContral* getContral();
	void process(int n);
private:
	UserContral();
	~UserContral();
private:
	static UserContral* PContral;
	UserModel *Pmodel;
};