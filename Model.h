#pragma once
#include <iostream>
#include "root_enum.h"
#include "user_enum.h"
#include "View.h"
#include "UserView.h"
typedef void(*View)();
class Model
{
public:
	void insert(int type,View view);
	void Ldelete(int type);
	View select(int n);
	Model();
	~Model();
private:
	class Node 
	{
		int type;
		View view;
		Node* next;
		friend class Model;
	};
	Node* listHead;
};
