#include <iostream>
#include <vector>

using namespace std;

class Buku {
public:
	vector<Buku*> judul_buku;

	string nama;
	Buku(string pNama) :nama(pNama) {}
};

class Penerbit {
public:
	vector<Pengarang*> pengarang;
	vector<string> buku;

	string nama;
	Penerbit(string pNama) :nama(pNama) {}

	void tambahPengarang(Pengarang* pPengarang) {
		pengarang.push_back(pPengarang);
	}

	void tambahBuku(string judul) {
		buku.push_back(judul);
	}

	void tampilkanPengarang() {
		cout << "Pengarang yang dinaungi oleh \"" << nama << "\":\n";
		for (auto p : pengarang) {
			cout << p->nama << "\n";
		}
		cout << endl;
	}

	void tampilkanBuku() {
		cout << "Buku yang diterbitkan oleh \"" << nama << "\":\n";
		for (auto b : buku) {
			cout << b << "\n";
		}
		cout << endl;
	}
};

class Pengarang {
public:
	vector<Penerbit*> penerbitan;

	string nama;
	Pengarang(string pNama) : nama(pNama) {}

	string getNama() {
		return nama;
	}

	void tambahPenerbitan(Penerbit* pPenerbit) {
		penerbitan.push_back(pPenerbit);
	}

	void tampilkanPenerbitan() {
		cout << "Penerbitan oleh \"" << nama << "\":\n";
		for (auto p : penerbitan) {
			cout << p->nama << endl;
		}
	}
};

int main() {
	// Membuat Objek Pengarang
	Pengarang pengarang1("Pengarang 1");
	Pengarang pengarang2("Pengarang 2");

	// Membuat Objek Penerbit
	Penerbit penerbit1("Penerbit 1");
	Penerbit penerbit2("Penerbit 2");
	
	// Relasi Pengarang dan Penerbit
	pengarang1.tambahPenerbitan(&penerbit1);
	pengarang1.tambahPenerbitan(&penerbit2);
	pengarang2.tambahPenerbitan(&penerbit1);

	// Menambahkan Buku ke Penerbit
	penerbit1.tambahBuku("Buku 1");
	penerbit1.tambahBuku("Buku 2");
	penerbit2.tambahBuku("Buku 3");

	// Menampilkan Informasi
	pengarang1.tampilkanPenerbitan();
	penerbit1.tampilkanPengarang();
	penerbit1.tampilkanBuku();

	return 0;
}