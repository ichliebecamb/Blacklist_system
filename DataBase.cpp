#include "DataBase.h"
Database* Database::PDatabase = NULL;

Database * Database::getbase()
{
	if (NULL == PDatabase)
	{
		PDatabase = new Database;
	}
	return  PDatabase;
}

bool Database::selectRoot(string id, string pw)
{
	Node* B_ptem = listHead->next;
	while (B_ptem != NULL && (id!= B_ptem->N_id || pw!=B_ptem->N_pw))
	{
		B_ptem = B_ptem->next;
	}
	if (NULL == B_ptem)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Database::AddAdm(string id, string pw)
{
	Node* Ptem = listHead->next;
	listHead->next = new Node;
	listHead->next->N_id = id;
	listHead->next->N_pw = pw;
	listHead->next->next = Ptem;
}

void Database::AddBlack()
{
	Blacklist *Ptem = BlackListHead->B_next;
	BlackListHead->B_next = new Blacklist;
	cout << "please input the id !" << endl;
	cout << "id = ";
	cin >> BlackListHead->B_next->B_id;
	cout << "please input the name!" << endl;
	cout << "name=";
	cin >> BlackListHead->B_next->B_name;
	cout << "please input the times(day)!" << endl;
	cin >> BlackListHead->B_next->B_times;
	time_t now = time(0);
	//
	//// 定义两个变量，存储转换结果
	////char stTmp[TIME_MAX];
	//// 转换为tm结构
	struct tm* tmTmp = localtime( &now);
	BlackListHead->B_next->B_year = tmTmp->tm_year + 1900;
	BlackListHead->B_next->B_mouth = tmTmp->tm_mon;
	BlackListHead->B_next->B_data = tmTmp->tm_mday;
	BlackListHead->B_next->B_next = Ptem;
}

void Database::deleteBlack(string id)
{
	Blacklist * BN;
	if (selectBlack(id, BN))
	{
		Blacklist * Btem;
		Btem = BN->B_next;
		BN->B_next = Btem->B_next;
		delete Btem;
	}
}

void Database::selectBlack(string id)
{
	Blacklist* B_ptem = BlackListHead->B_next;
	while ( B_ptem !=NULL && id != B_ptem->B_id )
	{
		B_ptem = B_ptem->B_next;
	}
	if (NULL == B_ptem)
	{
		std::cout << "not Found !" << std::endl;
	}
	else
	{
		showBlack(B_ptem);
	}
}

bool Database::selectBlack(string id, Blacklist *& BN)
{
	Blacklist* B_ptem = BlackListHead->B_next;
	BN = BlackListHead;
	while (B_ptem != NULL && id != B_ptem->B_id)
	{
		B_ptem = B_ptem->B_next;
		BN = BN->B_next;
	}
	if (NULL == B_ptem)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Database::changeBlack(string id)
{
	Blacklist * BN;
	if (selectBlack(id, BN))
	{

	}
	else
	{
		cout << "Not find that id!" << endl;
	}
}

void Database::showBlack(Blacklist * BN)
{
	cout << "the id is " << BN->B_id << " !" << endl;
	cout << "the name is " << BN->B_name << " !" << endl;
	cout << "the forbidden time is from " << BN->B_year << " years ";
	cout << BN->B_mouth << " mouths " << BN->B_data << endl;
	cout << "TO " << BN->B_times << " days!" << endl;
}

Database::Database()
{
	listHead = new Node;
	listHead->next = NULL;
	BlackListHead = new Blacklist;
	BlackListHead->B_next = NULL;
}

Database::~Database()
{
	Node* ptem = NULL;
	while (NULL!= listHead)
	{
		ptem = listHead->next;
		delete listHead;
		listHead = ptem;
	}
	Blacklist* B_ptem = NULL;
	while (NULL != BlackListHead)
	{
		B_ptem = BlackListHead->B_next;
		delete BlackListHead;
		BlackListHead = B_ptem;
	}
}
