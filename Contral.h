#pragma once
#include"Model.h"
#include"root_enum.h"
#include<iostream>
class Contral
{
public:
	static Contral* getContral();
	void process(int n);
	~Contral();
private:
	Contral();
	Model *Pmodel;
	static Contral* PContral;
};
 
