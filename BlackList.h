#pragma once
#include <iostream>
using namespace std;
#include <string>
class BlackList
{
public:
	BlackList();
	~BlackList();
	static BlackList* getblacklist();
private:
	static BlackList* PBlacklist;
	class Node
	{
		string B_id;
		string B_name;
		int year;
		int mouth;
		int data;
		int times;
		Node* next;
		friend class BlackList;
	};
	Node* B_listhead;
};