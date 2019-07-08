#pragma once
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class Database
{
private:
	static Database* PDatabase;
	class Node
	{
		string N_id;
		string N_pw;
		Node* next;
		friend class Database;
	};
	Node* listHead;
	class Blacklist
	{
		string B_id;
		string B_name;
		int B_year;
		int B_mouth;
		int B_data;
		int B_times;
		Blacklist* B_next;
		friend class Database;
	};
	Blacklist* BlackListHead;

public:
	static Database* getbase();
	Database();
	~Database();
	bool selectRoot(string id, string pw);
	void AddAdm(string id, string pw);
	void AddBlack();

	void deleteBlack(string id);
	void selectBlack(string id);
	bool selectBlack(string id, Blacklist* & BN);
	void changeBlack(string id);
	void showBlack(Blacklist * BN);
};  
