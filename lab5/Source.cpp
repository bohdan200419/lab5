#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Osoba {
protected:
	int age;

public:

	virtual void SetAge() {
		cout << "������ ��: " << endl;
		cin >> age;
	}

	int GetAge() {
		return age;
	}

	void printAge() {
		cout << "��� �������� ��: " << age << endl;
	}

	// ��������� ����������� ������, ���� ����� �� ������
	virtual void changeAge() {
		cout << "������ ��?" << endl;
		int option;
		cout << "1-���, 2-�" << endl;
		cin >> option;
		if (option == 1) {
			cout << "������ ��: ";
			cin >> age;
			cout << "��� ����� ��: " << age << endl;
		}
		else if (option == 2) {
			cout << "�������� ��: " << age << endl;
		}
		else {
			cout << "������� 1 ��� 2" << endl;
			exit(0);
		}
	}

};

class Student :public Osoba {

public:

	void SetAge() override {
		cout << "������ �� ��������: " << endl;
		cin >> age;
	}

	// ����� ��������������
	void changeAge() override {

		if (age == 17) {
			cout << "�� �� ������� ����" << endl;
		}
		else if (age == 18) {
			cout << "�� �� ������� ����" << endl;
		}
		else if (age == 19) {
			cout << "�� �� �������� ����" << endl;
		}
		else if (age == 20) {
			cout << "�� �� ���������� ����" << endl;
		}
		else if (age < 17) {
			cout << "�� �� ������" << endl;
		}
		else {
			cout << "������� �� ��� �������� ��������!" << endl;
		}
	}

};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Osoba personOne;
	Student studentOne;

	personOne.SetAge();
	personOne.changeAge();

	Osoba* person = &studentOne;

	studentOne.SetAge();
	person->changeAge();
	person->printAge();
}
