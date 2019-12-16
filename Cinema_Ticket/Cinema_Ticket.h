#pragma once
#include <string>
#include <stdlib.h>
using namespace std;

struct salon
{
	string filmadi;
	int saat, boskoltuk, dolukoltuk = 0;

};

template <class T>
class cinema
{
	salon* a;
	const int indirimli = 10, tam = 15;
	const T acilissaati = 10;
public:
	int tamtop=0, intop=0;
	cinema();
	void menu();
	void getsaloninfo(int);
	void getallsalonsinfo();
	void ticketreturn();
	void ticketbuy();
	void koltukis(int, int, int);
	void contiueforpress();
	void hasilat();
};