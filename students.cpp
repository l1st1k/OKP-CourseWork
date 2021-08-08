#include "students.h"

void showStudentsPerfomance(vector <Student>& v) {
	system("cls");
	bool flag = true;
	int number = 1;
	while (flag) {
		cout << "                   ��������                   ������" << endl;
		cout << "�  �������\t��/���/����/���\t\t���/��/���/���/����\t��. ����" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << number++ << ") "
				<< v[i].surname << "\t"
				<< " " << v[i].marks.os << " / "
				<< v[i].marks.math << " / "
				<< v[i].marks.oaip << " / "
				<< v[i].marks.fil << "\t\t"
				<< " " << v[i].marks.hist << " / "
				<< v[i].marks.pe << " / "
				<< v[i].marks.ikg << " / "
				<< v[i].marks.okp << " / "
				<< v[i].marks.english << "\t"
				<< v[i].marks.average << endl;
		}
		cout << endl;
		cout << "�������� ��������: " << endl << "1) ������������� �� ��������" << endl << "2) ������������� �� �������� �����" << endl << "3) �����" << endl;
		int user_choice = inputNumber(1, 3);
		switch (user_choice)
		{
		case 1: sortBySurname(v); break;
		case 2: sortByAverageMark(v); break;
		case 3: flag = false; system("cls"); break;
		}
		number = 1;
		system("cls");
	}
}

void showStudentsForUser(vector <Student>& v) {
	system("cls");
	bool system_menu_flag = true;
	int number = 1;
	while (system_menu_flag) {
		cout << "�  �������\t������\t����������\t��.�.\t���������" << endl;
		cout << "---------------------------------------------------------" << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << number++ << ") "
				<< v[i].surname << "\t"
				<< v[i].group_number << "\t";
			if (v[i].active == 0) {
				cout << "���������" << "\t";
			}
			else { cout << "  �������" << "\t"; }
			cout << v[i].marks.average << "\t"
				<< v[i].benefits << endl;
		}
		cout << endl;
		cout << "�������� ��������: " << endl << "1) ������������� �� ��������" << endl << "2) ������������� �� ����������" << endl << "3) ������������� �� �������� �����" << endl << "4) ������������� �� ������� ���������" << endl << "5) �������� ������� ���������" << endl << "6) �����" << endl;
		int user_choice = inputNumber(1, 6);
		switch (user_choice) {
		case 1: sortBySurname(v); break;
		case 2: sortByActive(v); break;
		case 3: sortByAverageMark(v); break;
		case 4: sortByBenefit(v); break;
		case 5: defaultBenefitChange(v); break;
		case 6: system_menu_flag = false; break;
		}
		number = 1;
		system("cls");
	}
}

void showStudents(vector <Student>& v) {
	system("cls");
	bool system_menu_flag = true;
	int number = 1;
	while (system_menu_flag) {
		cout << "�  �������\t������\t����������\t��.�.\t���������" << endl;
		cout << "---------------------------------------------------------" << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << number++ << ") "
				<< v[i].surname << "\t"
				<< v[i].group_number << "\t";
			if (v[i].active == 0) {
				cout << "���������" << "\t";
			}
			else { cout << "  �������" << "\t"; }
			cout << v[i].marks.average << "\t"
				<< v[i].benefits << endl;
		}
		cout << endl;
		cout << "�������� ��������: " << endl << "1) ������������� �� ��������" << endl << "2) ������������� �� ����������" << endl << "3) ������������� �� �������� �����" << endl << "4) ������������� �� ������� ���������" << endl << "5) �������� ��������" << endl << "6) ������������� ������ ��������" << endl << "7) ������� ��������" << endl << "8) �������� ������� ���������" << endl << "9) �����" << endl;
		int user_choice = inputNumber(1, 9);
		switch (user_choice) {
		case 1: sortBySurname(v); break;
		case 2: sortByActive(v); break;
		case 3: sortByAverageMark(v); break;
		case 4: sortByBenefit(v); break;
		case 5: addStudent(v); break;
		case 6: editStudent(v); break;
		case 7: deleteStudent(v);  break;
		case 8: defaultBenefitChange(v); break;
		case 9: system_menu_flag = false; break;
		}
		number = 1;
		system("cls");
	}
}

void editStudent(vector <Student>& v) {
	cout << "������� ����� ���������� ������: ";
	int index = inputNumber(1, v.size()) - 1;
	system("cls");
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "����� ���������� �� ������ ��������?" << endl
			<< "1) ������� (" << v[index].surname << ")" << endl
			<< "2) ����� ������ (" << v[index].group_number << ")" << endl
			<< "3) ���������� (";
		if (v[index].active == 1) { cout << "�������"; }
		else { cout << "���������"; }
		cout << ")" << endl
			<< "4) ������ �� ���������� (" << v[index].marks.math << ")" << endl
			<< "5) ������ �� �� (" << v[index].marks.os << ")" << endl
			<< "6) ������ �� ��������� (" << v[index].marks.fil << ")" << endl
			<< "7) ������ �� ���� (" << v[index].marks.oaip << ")" << endl
			<< "8) ����� �� ��� (";
		if (v[index].marks.ikg == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "9) ����� �� ����������� ����� (";
		if (v[index].marks.english == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "10) ����� �� ��� (";
		if (v[index].marks.okp == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "11) ����� �� ������� (";
		if (v[index].marks.hist == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "12) ����� �� ���������� �������� (";
		if (v[index].marks.pe == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "13) ��������� ��������������" << endl;
		int choice = inputNumber(1, 13);
		switch (choice)
		{
		case 1:
			cout << "������� ����� �������: ";
			cin >> v[index].surname;
			break;
		case 2:
			cout << "������� ����� ����� ������: ";
			cin >> v[index].group_number;
			break;
		case 3:
			if (v[index].active == 1) { v[index].active = 0; }
			else { v[index].active = 1; }
			break;
		case 4:
			cout << "����� ������ �� ����������: ";
			cin >> v[index].marks.math;
			break;
		case 5:
			cout << "����� ������ �� ��: ";
			cin >> v[index].marks.os;
			break;
		case 6:
			cout << "����� ������ �� ���������: ";
			cin >> v[index].marks.fil;
			break;
		case 7:
			cout << "����� ������ �� ����: ";
			cin >> v[index].marks.oaip;
			break;
		case 8:
			if (v[index].marks.ikg == 1) { v[index].marks.ikg = 0; }
			else { v[index].marks.ikg = 1; }
			break;
		case 9:
			if (v[index].marks.english == 1) { v[index].marks.english = 0; }
			else { v[index].marks.english = 1; }
			break;
		case 10:
			if (v[index].marks.okp == 1) { v[index].marks.okp = 0; }
			else { v[index].marks.okp = 1; }
			break;
		case 11:
			if (v[index].marks.hist == 1) { v[index].marks.hist = 0; }
			else { v[index].marks.hist = 1; }
			break;
		case 12:
			if (v[index].marks.pe == 1) { v[index].marks.pe = 0; }
			else { v[index].marks.pe = 1; }
			break;
		case 13: flag = false;  break;
		}
		v[index].marks.average = (v[index].marks.os + v[index].marks.oaip + v[index].marks.math + v[index].marks.fil) / 4.;
	}
}

void editAddedStudent(Student a) {
	system("cls");
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "����� ���������� �� ������ ��������?" << endl
			<< "1) ������� (" << a.surname << ")" << endl
			<< "2) ����� ������ (" << a.group_number << ")" << endl
			<< "3) ���������� (";
		if (a.active == 1) { cout << "�������"; }
		else { cout << "���������"; }
		cout << ")" << endl
			<< "4) ������ �� ���������� (" << a.marks.math << ")" << endl
			<< "5) ������ �� �� (" << a.marks.os << ")" << endl
			<< "6) ������ �� ��������� (" << a.marks.fil << ")" << endl
			<< "7) ������ �� ���� (" << a.marks.oaip << ")" << endl
			<< "8) ����� �� ��� (";
		if (a.marks.ikg == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "9) ����� �� ����������� ����� (";
		if (a.marks.english == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "10) ����� �� ��� (";
		if (a.marks.okp == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "11) ����� �� ������� (";
		if (a.marks.hist == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "12) ����� �� ���������� �������� (";
		if (a.marks.pe == 1) { cout << "�����"; }
		else { cout << "�������"; }
		cout << ")" << endl
			<< "13) ��������� �������������� � ��������� ��������" << endl;
		int choice = inputNumber(1, 13);
		switch (choice)
		{
		case 1:
			cout << "������� ����� �������: ";
			cin >> a.surname;
			break;
		case 2:
			cout << "������� ����� ����� ������: ";
			cin >> a.group_number;
			break;
		case 3:
			if (a.active == 1) { a.active = 0; }
			else { a.active = 1; }
			break;
		case 4:
			cout << "����� ������ �� ����������: ";
			cin >> a.marks.math;
			break;
		case 5:
			cout << "����� ������ �� ��: ";
			cin >> a.marks.os;
			break;
		case 6:
			cout << "����� ������ �� ���������: ";
			cin >> a.marks.fil;
			break;
		case 7:
			cout << "����� ������ �� ����: ";
			cin >> a.marks.oaip;
			break;
		case 8:
			if (a.marks.ikg == 1) { a.marks.ikg = 0; }
			else { a.marks.ikg = 1; }
			break;
		case 9:
			if (a.marks.english == 1) { a.marks.english = 0; }
			else { a.marks.english = 1; }
			break;
		case 10:
			if (a.marks.okp == 1) { a.marks.okp = 0; }
			else { a.marks.okp = 1; }
			break;
		case 11:
			if (a.marks.hist == 1) { a.marks.hist = 0; }
			else { a.marks.hist = 1; }
			break;
		case 12:
			if (a.marks.pe == 1) { a.marks.pe = 0; }
			else { a.marks.pe = 1; }
			break;
		case 13: flag = false;  break;
		}
		a.marks.average = (a.marks.os + a.marks.oaip + a.marks.math + a.marks.fil) / 4.;
	}
}

void addStudent(vector <Student>& v) {
	system("cls");
	Student new_student;
	cout << "���������� ������ �������� � �������" << endl;
	cout << "������� �������:  ";
	cin >> new_student.surname;
	cout << "������� ����� ������:  ";
	cin >> new_student.group_number;
	cout << "������� ����� �������� ������������ �����?" << endl << "1) ��" << endl << "2) ���" << endl;
	int active = inputNumber(1, 2);
	if (active == 1) { new_student.active = 1; }
	else { new_student.active = 0; }
	cout << "������ �������� �� ������� �� ��:";
	new_student.marks.os = inputNumber(4, 10);
	cout << "������ �������� �� ������� �� ����:";
	new_student.marks.oaip = inputNumber(4, 10);
	cout << "������ �������� �� ������� �� ����������:";
	new_student.marks.math = inputNumber(4, 10);
	cout << "������ �������� �� ������� �� ���������:";
	new_student.marks.fil = inputNumber(4, 10);
	new_student.marks.average = (new_student.marks.os + new_student.marks.oaip + new_student.marks.math + new_student.marks.fil) / 4.;
	new_student.benefits = 0;
	cout << "������� ���� ����� �� ���������� '���'?" << endl << "1) ��" << endl << "2) ���" << endl;
	int choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.ikg = 1; }
	else { new_student.marks.ikg = 0; }

	cout << "������� ���� ����� �� ���������� '���������� ��������'?" << endl << "1) ��" << endl << "2) ���" << endl;
	choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.pe = 1; }
	else { new_student.marks.pe = 0; }

	cout << "������� ���� ����� �� ���������� '�������'?" << endl << "1) ��" << endl << "2) ���" << endl;
	choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.hist = 1; }
	else { new_student.marks.hist = 0; }

	cout << "������� ���� ����� �� ���������� '���������� ����'?" << endl << "1) ��" << endl << "2) ���" << endl;
	choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.english = 1; }
	else { new_student.marks.english = 0; }

	cout << "������� ���� ����� �� ���������� '���'?" << endl << "1) ��" << endl << "2) �� ���� ���� ��������! ������ ���� ������... " << endl << endl;
	choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.okp = 1; }
	else {
		new_student.marks.okp = 0;
		cout << "��� ��������� �������, �������� ����������� ����������!" << endl;
		system("pause");
	}
	editAddedStudent(new_student);
	v.push_back(new_student);
}

bool otlichnik(Student a) {
	if (((a.marks.os == 9) || (a.marks.os == 10)) &&
		((a.marks.math == 9) || (a.marks.math == 10)) &&
		((a.marks.oaip == 9) || (a.marks.oaip == 10)) &&
		((a.marks.fil == 9) || (a.marks.fil == 10))) {
		return true;
	}
	else return false;
}

void defaultBenefitChange(vector <Student>& v) {
	cout << "������� ������ ������� ���������: ";
	int benefit = inputNumber(1, 500);
	for (int i = 0; i < v.size(); i++) {
		v[i].benefits = benefit;
		if (v[i].marks.average <= 5) v[i].benefits = 0;
		if (otlichnik(v[i]) && v[i].active == 1) v[i].benefits = 1.5 * benefit;
		if (otlichnik(v[i]) && v[i].active == 0) v[i].benefits = 1.25 * benefit;
	}
}

void deleteStudent(vector <Student>& v) {
	cout << "������� ����� ��������� ������: ";
	int index = inputNumber(1, v.size()) - 1;
	system("cls");
	cout << "�� ������������� ������ ������� �������� " << v[index].surname << " �� �������?" << endl << "1) ��" << endl << "2) ��������" << endl;
	int choice = inputNumber(1, 2);
	if (choice == 1) v.erase(v.begin() + index);
	system("cls");
}

void readFileStudents(vector <Student>& v) {
	ifstream fin(FILE_OF_DATA, ios::in); // ������� ���� ��� ������
	if (!fin.is_open()) {
		cout << "�� ������ ������ �� ���������� �� ������ �������� � �������." << endl << "����������, �������� ������ ��������!" << endl;
		addStudent(v);
	}
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			if (i < v.size())
			{
				fin >> v[i].surname
					>> v[i].group_number
					>> v[i].active
					>> v[i].benefits
					>> v[i].marks.average
					>> v[i].marks.os
					>> v[i].marks.math
					>> v[i].marks.oaip
					>> v[i].marks.fil
					>> v[i].marks.hist
					>> v[i].marks.pe
					>> v[i].marks.ikg
					>> v[i].marks.okp
					>> v[i].marks.english;
				i++;
			}
			else
			{
				break;
			}
		}
	}
	fin.close(); //������� ����
}

void writeFileStudents(vector <Student>& v) {
	ofstream fout(FILE_OF_DATA, ios::out); // ������� ���� ��� ������
	for (int i = 0; i < v.size(); i++)
	{
		fout << v[i].surname << " "
			<< v[i].group_number << " "
			<< v[i].active << " "
			<< v[i].benefits << " "
			<< v[i].marks.average << " "
			<< v[i].marks.os << " "
			<< v[i].marks.math << " "
			<< v[i].marks.oaip << " "
			<< v[i].marks.fil << " "
			<< v[i].marks.hist << " "
			<< v[i].marks.pe << " "
			<< v[i].marks.ikg << " "
			<< v[i].marks.okp << " "
			<< v[i].marks.english;
		if (i < v.size() - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}

bool mySortByBenefit(Student a, Student b) {
	return a.benefits > b.benefits;
}
void sortByBenefit(vector <Student>& v) {
	system("cls");
	sort(v.begin(), v.end(), mySortByBenefit);
}
bool mySortByActive(Student a, Student b) {
	return a.active > b.active;
}
void sortByActive(vector <Student>& v) {
	system("cls");
	sort(v.begin(), v.end(), mySortByActive);
}
bool mySortByAverageMark(Student a, Student b) {
	return a.marks.average > b.marks.average;
}
void sortByAverageMark(vector <Student>& v) {
	system("cls");
	sort(v.begin(), v.end(), mySortByAverageMark);
}
bool mySortBySurname(Student a, Student b) {
	return a.surname < b.surname;
}
void sortBySurname(vector <Student>& v) {
	system("cls");
	sort(v.begin(), v.end(), mySortBySurname);
}
