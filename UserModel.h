#pragma once
#include <iostream>
#include "user_enum.h"
#include "UserView.h"
typedef void(*View)();
class UserModel
{
public:
	void insert(int type, View view);
	void Ldelete(int type);
	View select(int n);
	UserModel();
	~UserModel();
private:
	class Node
	{
		int type;
		View view;
		Node* next;
		friend class UserModel;
	};
	Node* listHead;
};
