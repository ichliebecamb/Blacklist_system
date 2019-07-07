#include "Model.h"


void Model::insert(int type, View view)
{
	Node* p = new Node;
	p->next = listHead->next;
	p->type = type;
	p->view = view;
	listHead->next = p;
}

void Model::Ldelete(int type)
{
	if (0 >= type) return;
	Node* p = listHead->next;
	Node* p1 = listHead;
	while (!p&&type != p->type)
	{
		p = p->next;
		p1 = p1->next;
	}
	if (NULL == p->next) return;
	else
	{
		p1->next = p->next;
		delete p;
	}
}

View Model::select(int n)
{
	Node* p = listHead->next;
	while (p&&n != p->type)
	{
		p = p->next;
	}
	if (NULL == p ) return viewExit;
	else
	{
		return p->view;
	}
}

Model::Model()
{
	listHead = new Node;
	listHead->next = NULL;
	listHead->type = 0;
	listHead->view = NULL;

	insert(LOGIN, viewLogin);
	insert(REGISTER, viewRegister);
	insert(S_EXIT, viewExit);

	insert(ADD, UserADD);
	insert(DELETE, UserDELETE);
	insert(SELECT, UserSELECT);
	insert(FIX, UserFIX);
	insert(EXIT, UserEXIT);
}

Model::~Model()
{
	Node* p = listHead->next;
	Node* p1 = listHead;
	while (p)
	{
		p = p->next;
		p1 = p1->next;
	}
	for (int i = p1->type; i > 0 ; i--)
	{
		Ldelete(i);
	}
	delete listHead;
}
