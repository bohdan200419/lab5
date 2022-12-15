#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Osoba {
protected:
	int age;

public:

	virtual void SetAge() {
		cout << "Введіть вік: " << endl;
		cin >> age;
	}

	int GetAge() {
		return age;
	}

	void printAge() {
		cout << "Ваш поточний вік: " << age << endl;
	}

	// створення віртуального методу, який змінює вік людини
	virtual void changeAge() {
		cout << "Змінити вік?" << endl;
		int option;
		cout << "1-так, 2-ні" << endl;
		cin >> option;
		if (option == 1) {
			cout << "Введіть вік: ";
			cin >> age;
			cout << "Ваш новий вік: " << age << endl;
		}
		else if (option == 2) {
			cout << "Поточний вік: " << age << endl;
		}
		else {
			cout << "Виберіть 1 або 2" << endl;
			exit(0);
		}
	}

};

class Student :public Osoba {

public:

	void SetAge() override {
		cout << "Введіть вік студента: " << endl;
		cin >> age;
	}

	// метод перевизначення
	void changeAge() override {

		if (age == 17) {
			cout << "Ви на першому курсі" << endl;
		}
		else if (age == 18) {
			cout << "Ви на другому курсі" << endl;
		}
		else if (age == 19) {
			cout << "Ви на третьому курсі" << endl;
		}
		else if (age == 20) {
			cout << "Ви на четвертому курсі" << endl;
		}
		else if (age < 17) {
			cout << "Ви ще школяр" << endl;
		}
		else {
			cout << "Ймовірно ви вже закінчили навчання!" << endl;
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
