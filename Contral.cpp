#include "Contral.h"
Contral* Contral::PContral = NULL;

Contral * Contral::getContral()
{
	if (NULL == PContral)
	{
		PContral = new Contral;
	}
	return  PContral;
}

void Contral::process(int n)
{
	(*Pmodel->select(n))();
}

Contral::~Contral()
{
	delete Pmodel;
}

Contral::Contral()
{
	Pmodel = new Model;
}
