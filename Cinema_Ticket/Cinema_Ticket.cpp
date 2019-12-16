#include <iostream>
#include "Cinema_Ticket.h"
#define salonsayisi 5

template <class T>
cinema<T>::cinema() {
	a = new salon[salonsayisi];
	a[0].filmadi = "Avengers";
	a[1].filmadi = "Geri Donus";
	a[2].filmadi = "Hizli ve Ofkeli";
	a[3].filmadi = "Tas Kagit Makas";
	a[4].filmadi = "Bir Serlok Degilsin";
	a[0].saat = 12;
	a[1].saat = 14;
	a[2].saat = 20;
	a[3].saat = 8;
	a[4].saat = 23;
	a[0].boskoltuk = 30;
	a[1].boskoltuk = 30;
	a[2].boskoltuk = 30;
	a[3].boskoltuk = 30;
	a[4].boskoltuk = 30;
}

template <class T>
void cinema<T>::contiueforpress() {
	cin.ignore();
	cin.get();
}

template <class T>
void cinema<T>::koltukis(int salon, int in, int ta) {
	a[salon].dolukoltuk += (in + ta);
	a[salon].boskoltuk -= (in + ta);
}

template <class T>
void cinema<T>::getsaloninfo(int temporal)
{
	system("CLS");
	cout << "Film adi...:     \t" << a[temporal - 1].filmadi << endl;
	cout << "Bos koltuk sayisi...:\t" << a[temporal - 1].boskoltuk << endl;
	cout << "Satilan bilet sayisi...:" << a[temporal - 1].dolukoltuk << endl;
	cout << "Film saati...:   \t" << a[temporal - 1].saat << endl;
}

template <class T>
void cinema<T>::getallsalonsinfo()
{
	system("CLS");
	for (int i = 0; i < 5; i++)
	{
		cout << "Salon " << i + 1 << " :\t" << a[i].filmadi << endl;
	}
	cout << "Islemi bitirmek icin Enter'a basiniz...";
	contiueforpress();
	menu();
}

template <class T>
void cinema<T>::ticketbuy()
{
	system("CLS");
	char cev;
	int in, tams, salonnum, fiyat;
	for (int i = 0; i < 5; i++)
	{
		cout << "Salon " << i + 1 << " :\t" << a[i].filmadi << endl;
	}
	cout << "Salon numarasini giriniz...:";
	cin >> salonnum;
	getsaloninfo(salonnum);
	cout << "Satin Alinsin mi? (Evet icin e , hayir icin h harfine basin):";
	cin >> cev;
	if (cev == 'e' || cev == 'E')
	{
		cout << "Indirimli Bilet Sayisi...:";
		cin >> in;
		cout << "Tam Bilet Sayisi...:";
		cin >> tams;
		if ((in + tams) > a[salonnum - 1].boskoltuk)
		{
			cout << "Fazla deger girdiniz menuye donulecek" << endl;
			cout << "Islemi bitirmek icin Enter'a basiniz...";
			contiueforpress();
			menu();

		}
		else
		{
			fiyat = (in * indirimli) + (tams * tam);
			koltukis(salonnum - 1, tams, in);
			tamtop = tamtop + tams;
			intop = intop + in;
			cout << "Ucret: " << fiyat << endl;
			cout << "Islemi bitirmek icin Enter'a basiniz...";
			contiueforpress();
			menu();
		}

	}
	else
	{

		cout << "Islemi bitirmek icin Enter'a basiniz...";
		contiueforpress();
		menu();
	}

}

template <class T>
void cinema<T>::menu() {
	int deger;
	system("CLS");
	cout << "------------------------ Kultur Sinemasina Hosgeldiniz ------------------------" << endl;
	cout << "------->   Bilet Almak Icin 1'e basiniz..." << endl << "------->   Bilet Iade Icin 2'e basiniz..." << endl << "------->   Filmleri Gormek Icin 3'e basiniz..." << endl << "------->   Hasilati gormek icin 4'e basiniz" << endl << "Islem seciniz....: ";
	cin >> deger;
	switch (deger)
	{
	case 1:
		ticketbuy();
		break;
	case 2:
		ticketreturn();
		break;
	case 3:
		getallsalonsinfo();
		break;
	case 4:
		hasilat();
		break;
	default:
		menu();
		break;
	}
}

template <class T>
void cinema<T>::ticketreturn()
{
	system("CLS");
	char cev;
	int in, tams, salonnum, fiyat;
	for (int i = 0; i < 5; i++)
	{
		cout << "Salon " << i + 1 << " :\t" << a[i].filmadi << endl;
	}
	cout << "Salon numarasini giriniz...:";
	cin >> salonnum;
	getsaloninfo(salonnum);
	cout << "Iade Edilsin mi? (Evet icin e , hayir icin h harfine basin)";
	cin >> cev;
	if (cev == 'e' || cev == 'E')
	{
		cout << "Indirimli Bilet Sayisi...:";
		cin >> in;
		cout << "Tam Bilet Sayisi...:";
		cin >> tams;
		fiyat = (in * indirimli) + (tams * tam);
		if ((in + tams) > a[salonnum - 1].dolukoltuk)
		{
			cout << "Fazla deger girdiniz menuye donulecek" << endl;
			cout << "Islemi bitirmek icin Enter'a basiniz...";
			contiueforpress();
			menu();

		}
		else
		{
			koltukis(salonnum - 1, tams * (-1), in * (-1));
			cout << "Iade Edilecek Ucret: " << fiyat << endl;
			cout << "Islemi bitirmek icin Enter'a basiniz...";
			tamtop = tamtop - tams;
			intop = intop - in;
			contiueforpress();
			menu();
		}
	}
	else
	{
		cout << "Islemi bitirmek icin Enter'a basiniz...";
		contiueforpress();
		menu();
	}
}

template <class T>
void cinema<T>::hasilat() {
	system("CLS");
	cout << "Satilan toplam indirimli bilet adedi: " << intop << endl;
	cout << "Satilan toplam tam bilet adedi: " << tamtop << endl;
	cout << "Toplam hasilat:" << intop * 10 + tamtop * 15 << endl;
	cout << "Islemi bitirmek icin Enter'a basiniz...";
	contiueforpress();
	menu();
}

int main()
{
	cinema<int> sinema;
	sinema.menu();
}