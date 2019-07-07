#pragma once
//#include "UserContral.h"
#include "Contral.h"
#include "user_enum.h"
#include <iostream>
using namespace std;
//time_t now;
//time(&now);
//
//// 定义两个变量，存储转换结果
//struct tm tmTmp;
////char stTmp[TIME_MAX];
//
//// 转换为tm结构
//localtime_s(&tmTmp, &now);
class UserSys
{
public:
	static UserSys* getPuserSys();
	void run();
private:
	static UserSys* PuserSys;
	void put();
};