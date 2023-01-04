
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class bookshope {
public:
	void control_panel();
	void add_book();
	void show_book();
	void check_book();
	void update_book();
	void del_book();
};

// Fungsi tampilan menu
void bookshope::control_panel()
{
	system("cls");
	cout << "\n\n\t\t\t\tPERPUSTAKAAN";
	cout << "\n\n1. TAMBAH BUKU";
	cout << "\n2. TAMPILAN BUKU";
	cout << "\n3. PERIKSA BUKU TERTENTU";
	cout << "\n4. UPDATE BUKU";
	cout << "\n5. DELETE BUKU";
	cout << "\n6. KELUAR";
}

// Fungsi untuk menambah buku
void bookshope::add_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string b_name, a_name, b_id;
	cout << "\n\n\t\t\t\tTAMBAH BUKU";
	cout << "\n\nNomor Buku : ";
	cin >> b_id;
	cout << "\nNama Buku : ";
	cin >> b_name;
	cout << "\nNama Pengarang : ";
	cin >> a_name;
	cout << "\nJumlah Buku : ";
	cin >> no_copy;

}

// Fungsi untuk menampilkan buku
void bookshope::show_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string b_name, b_id, a_name;
	cout << "\n\n\t\t\t\t\tSEMUA BUKU";

	// Input mode
	file.open("D:// book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\nNOMOR BUKU\t\tBUKU"
			<< "\t\tPENGARANG\t\tJUMLAH "
			"BUKU\n\n";
		file >> b_id >> b_name;
		file >> a_name >> no_copy;


		while (!file.eof()) {

			cout << " " << b_id
				<< "\t\t" << b_name
				<< "\t\t" << a_name
				<< "\t\t" << no_copy
				<< "\n\n";
			file >> b_id >> b_name;
			file >> a_name >> no_copy;
		}

		system("pause");

		// Menutup file
		file.close();
	}
}

// fungsi untuk mengechek buku
void bookshope::check_book()
{
	system("cls");
	fstream file;
	int no_copy, count = 0;
	string b_id, b_name, a_name, b_idd;

	cout << "\n\n\t\t\t\tPeriksa "
		<< "Buku Tertentu";


	file.open("D:// book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_idd;
		file >> b_id >> b_name;
		file >> a_name >> no_copy;

		while (!file.eof()) {

			if (b_idd == b_id) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Periksa Buku Tertentu";
				cout << "\n\nNomor Buku : "
					<< b_id;
				cout << "\nNama : "
					<< b_name;
				cout << "\nPengarang : "
					<< a_name;
				cout << "\nJumlah Buku : "
					<< no_copy;
				cout << endl
					<< endl;
				count++;
				break;
			}
			file >> b_id >> b_name;
			file >> a_name >> no_copy;
		}
		system("pause");
		file.close();
		if (count == 0)
			cout << "\n\nNomor Buku Tidak"
			<< " Ditemukan...";
	}
}

// fungsi untuk mengupdate buku
void bookshope::update_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, no_co, count = 0;
	string b_name, b_na, a_name;
	string a_na, b_idd, b_id;

	cout << "\n\n\t\t\t\tUpdate Rekaman Buku";
	file1.open("D:// book1.txt",
		ios::app | ios::out);
	file.open("D:// book.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nNomor Buku : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy;


		while (!file.eof()) {
			if (b_id == b_idd) {
				system("cls");
				cout << "\t\t\t\t"
					<< "Update Rekaman Buku";
				cout << "\n\nNama Buku Baru : ";
				cin >> b_na;
				cout << "\nNama Pengarang : ";
				cin >> a_na;
				cout << "\nJumlah Buku : ";
				cin >> no_co;
				file1 << " " << b_id << " "
					<< b_na << " "
					<< a_na << " " << no_co
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << b_idd
				<< " " << b_name
				<< " " << a_name
				<< " " << no_copy
				<< "\n\n";
			file >> b_idd >> b_name;
			file >> a_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\nNomor Buku"
			<< " Tidak Ditemukan...";
	}
	cout << endl;
	system("pause");

}

// fungsi untuk menghapus buku

void bookshope::del_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, count = 0;
	string b_id, b_idd, b_name, a_name;
	cout << "\n\n\t\t\t\tHapus Buku";

	
	file1.open("D:// book1.txt",
		ios::app | ios::out);
	file.open("D:// book.txt",
		ios::in);

	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\nNomor Buku : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy;
		while (!file.eof()) {

			if (b_id == b_idd) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Hapus Buku";
				cout << "\n\nBuku Telah Terhapus "
					"Berhasil...\n\n";
				count++;
			}
			else
				file1 << " " << b_idd
				<< " " << b_name
				<< " " << a_name
				<< " " << no_copy
				<< "\n\n";
			file >> b_idd >> b_name;
			file >> a_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\nNomor Buku "
			<< "Tidak Ditemukan...";
	}
	system("pause");

}

// fungsi untuk merekam buku

void bookShopRecord()
{
	int choice;
	char x;
	bookshope b;

	while (1) {

		b.control_panel();
		cout << "\n\nMasukan Pilihan Anda : ";
		cin >> choice;
		switch (choice) {

		case 1:
			do {

				b.add_book();
				cout << "\n\nIngin menambahkan"
					<< " buku lainnya? "
					"(y/n) : ";
				cin >> x;
			} while (x == 'y');
			break;

		case 2:
			b.show_book();
			break;

		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;

		case 5:
			b.del_book();
			break;

		case 6:
			exit(0);
			break;

		default:
			cout << "\n\nPILIHAN YANG TIDAK SAH\n";
		}
	}
}


int main()
{

	bookShopRecord();

	return 0;
}
