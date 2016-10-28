#pragma once
class Liste
{
public:
	Liste();
	~Liste();
	void printList(Liste lst);
	void insertLast(Liste &lst, int info);
	void reverseList(Liste& lst);
};

