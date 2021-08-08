#include "accs.h"
// ��������

string inputPass() {
	string pass;
	char input[30], c;
	int counter = 0;
	while ((c = _getch()) != '\r')
	{
		input[counter++] = c;
		_putch('*');
	}
	pass.assign(input, 0, counter);
	cout << endl;
	return pass;
}

void showAccounts(vector <Account>& v, Account current_acc) {
	int counter = 1;
	bool acc_table_flag = true;
	while (acc_table_flag) {
		cout << "�\tlogin\trole\tstate" << endl;
		cout << "---------------------------------------" << endl;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].access == 1) {
				cout << counter++ << ")\t"
					<< v[i].login << "\t";
				if (v[i].role == 0) {
					cout << "user" << "\t";
				}
				else { cout << "admin" << "\t"; }

				if (v[i].block == 0) {
					cout << "active" << endl;
				}
				else { cout << "blocked" << endl; }
			}
		}
		cout << endl << endl;
		cout << "�������� ��������: " << endl << "1) ������������� �� ��������" << endl << "2) ������������� �� ����" << endl << "3) �������� ����� �������" << endl << "4) ������� �������" << endl << "5) ������������� �������" << endl << "6) �������������� �������" << endl << "7) �������� ����" << endl << "8) �����" << endl;
		int user_choice = inputNumber(1, 8);
		switch (user_choice) {
		case 1: sortByLogin(v);  break;
		case 2: sortByRole(v);  break;
		case 3: newAccountCreation(v); break;
		case 4: deleteAccount(v, counter, current_acc);  break;
		case 5: blockAccount(v, counter); break;
		case 6: unblockAccount(v, counter); break;
		case 7: roleChange(v, counter);  break;
		case 8: acc_table_flag = false; break;
		}
		system("cls");
		counter = 1;
	}
}

void userPassChange(vector <Account>& v, Account& current_acc) {
	system("cls");
	string pass_comparison;
	bool first_attempt = true;
	int fail_counter = 0;
	while ((current_acc.password != md5(pass_comparison)) && (fail_counter != 3)) {
		if (first_attempt) cout << "��� ��������� ������ ������� ���� ������� ������: ";
		else cout << "������������ ���� ������. ��������� �������: ";
		pass_comparison = inputPass();
		fail_counter++;
		first_attempt = false;
	}
	if (fail_counter != 3) {
		string new_pass, new_pass_copy;
		cout << "������� ����� ������: ";
		new_pass = inputPass();
		cout << endl;
		bool first_attempt = true, match = false;
		int fails = 0;
		while (!match && fails != 3) {
			if (first_attempt) cout << "��������� ����� ������: ";
			else cout << "������������ ����! ��������� ����� ������: ";
			new_pass_copy = inputPass();
			if (new_pass == new_pass_copy) match = true;
			fails++;
			first_attempt = false;
		}
		if (fails != 3) {
			current_acc.password = new_pass;
			for (int i = 0; i < v.size(); i++) {
				if (v[i].login == current_acc.login) {
					v[i].password = md5(new_pass); break;
				}
			}
			cout << "��� ������ ������� �������!" << endl;
			system("pause");
		}
		else {
			cout << "��������� ���� ������ �� ������ ������. �������� ��������� ������ ���������. ������ �� �������!" << endl;
			system("pause");
		}
	}
	else {
		cout << "������������ ������ ��� ������ ������. ��������� ������ ����������!" << endl;
		system("pause");
		system("cls");
	}
}

void showNewApplications(vector <Account>& v) {
	int counter = 1;
	bool acc_table_flag = true;
	while (acc_table_flag) {
		cout << "�\tlogin" << endl;
		cout << "--------------------" << endl;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].access == 0) {
				cout << counter++ << ")\t"
					<< v[i].login << endl;

			}
		}
		cout << endl << endl;
		cout << "�������� ��������: " << endl << "1) ������������� �� ��������" << endl << "2) �������� ������ �� �����������" << endl << "3) ������� ������" << endl << "4) �����" << endl;
		int user_choice = inputNumber(1, 4);
		switch (user_choice) {
		case 1: sortByLogin(v);  break;
		case 2: ApproveApplication(v, counter);  break;
		case 3: deleteApplication(v, counter); break;
		case 4: acc_table_flag = false; break;
		}
		system("cls");
		counter = 1;
	}
}

void deleteApplication(vector <Account>& v, int counter) {
	cout << "������� ����� ������: ";
	int index = searchApplicationIndex(v, counter);
	system("cls");
	cout << "�� ������������� ������ ������� ������ �� ����������� ������������ " << v[index].login << " �� �������?" << endl << "1) ��" << endl << "2) ��������" << endl;
	int choice = inputNumber(1, 2);
	if (choice == 1) v.erase(v.begin() + index);
	system("cls");
}

void ApproveApplication(vector <Account>& v, int counter) {
	cout << "������� ����� ������: ";
	int index = searchApplicationIndex(v, counter);
	system("cls");
	cout << "�� ������������� ������ �������� ������ �� ����������� ������������ " << v[index].login << " � �������?" << endl << "1) ��" << endl << "2) ��������" << endl;
	int choice = inputNumber(1, 2);
	if (choice == 1) v[index].access = 1;
	system("cls");
}

void deleteAccount(vector <Account>& v, int counter, Account current_acc) {
	int index;
	while (true) {
		cout << "������� ����� ���������� ��������: ";
		index = searchAccIndex(v, counter);
		if (v[index].login == current_acc.login) cout << "�� �� ������ ������� ���� �������!" << endl;
		else break;
	}
	system("cls");
	cout << "�� ������������� ������ ������� �������� " << v[index].login << " �� �������?" << endl << "1) ��" << endl << "2) ��������" << endl;
	int choice = inputNumber(1, 2);
	if (choice == 1) v.erase(v.begin() + index);
	system("cls");
}

void roleChange(vector <Account>& v, int counter) {
	cout << "������� ����� ��������: ";
	int index = searchAccIndex(v, counter);
	if (v[index].role == 1) { v[index].role = 0; }
	else { v[index].role = 1; }
}

void blockAccount(vector <Account>& v, int counter) {
	cout << "������� ����� ������������ ��������: ";
	int index = searchAccIndex(v, counter);
	v[index].block = 1;
}

void unblockAccount(vector <Account>& v, int counter) {
	cout << "������� ����� ��������: ";
	int index = searchAccIndex(v, counter);
	v[index].block = 0;
}

int searchApplicationIndex(vector <Account>& v, int counter) {
	int index, number = inputNumber(1, counter - 1);

	int k = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].access == 0) {
			k++;
		}
		if (k == number) {
			index = i;
			break;
		}
	}
	return index;
}

int searchAccIndex(vector <Account>& v, int counter) {
	int index, number = inputNumber(1, counter - 1);

	int k = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].access == 1) {
			k++;
		}
		if (k == number) {
			index = i;
			break;
		}
	}
	return index;
}

void newAccountCreation(vector <Account>& v) {
	system("cls");
	Account new_acc;
	cout << "�������� ������ �������� � �������" << endl;
	bool flag = false;
	while (!flag) {
		flag = true;
		cout << "������� �����: ";
		cin >> new_acc.login;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].login == new_acc.login) {
				flag = false;
				cout << "������� � ����� ������� ��� ���������������! ����������, ���������� ������." << endl;
			}
		}
	}
	cout << "������� ������: ";
	cin >> new_acc.password;
	cout << "1) ������� ��������������" << endl << "2) ���������������� �������" << endl;
	int user_choice = inputNumber(1, 2);
	if (user_choice == 1) {
		new_acc.role = 1;
	}
	else
	{
		new_acc.role = 0;
		cout << "1) � �������� � �������" << endl << "2) ��� ������� � �������" << endl;
		user_choice = inputNumber(1, 2);
		if (user_choice == 1) {
			new_acc.access = 1;
		}
		else
		{
			new_acc.access = 0;
		}
	}
	new_acc.block = 0;
	v.push_back(new_acc);
	system("cls");
	cout << "����� ������� ������� ������!" << endl;
}

void newAccountApplication(vector <Account>& v) {
	Account new_acc;
	cout << "�������� ������ �������� � �������" << endl;
	bool flag = false;
	while (!flag) {
		flag = true;
		cout << "������� �����: ";
		cin >> new_acc.login;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].login == new_acc.login) {
				flag = false;
				cout << "������� � ����� ������� ��� ���������������! ����������, ���������� ������." << endl;
			}
		}
	}
	cout << "������� ������: ";
	cin >> new_acc.password;
	new_acc.password = md5(new_acc.password);
	new_acc.access = 0;
	new_acc.block = 0;
	new_acc.role = 0;
	v.push_back(new_acc);
	system("cls");
	cout << "���� ������ �� ����������� �������!" << endl << "������� ����� �������� ����� ��������� ����� ������ ���������������." << endl;
	system("pause");
}

void writeFileAccounts(vector <Account>& v)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::out); // ������� ���� ��� ������
	for (int i = 0; i < v.size(); i++)
	{
		fout << v[i].login << " "
			<< v[i].password << " "
			<< v[i].role << " "
			<< v[i].access << " "
			<< v[i].block;
		if (i < v.size() - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}

void readFileAccounts(vector <Account>& v)
{
	ifstream fin(FILE_OF_ACCOUNTS, ios::in); // ������� ���� ��� ������
	if (!fin.is_open()) {
		cout << "�� ������ ������ �� ���������� �� ������ ��������." << endl << "����������, ����������������� � �������!" << endl;
		newAccountCreation(v);
	}
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			if (i < v.size())
			{
				fin >> v[i].login
					>> v[i].password
					>> v[i].role
					>> v[i].access
					>> v[i].block;
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

int getCountOfStucturesInFile(string file_path)
{
	ifstream file(file_path, ios::in); // ������� ��������� ���� ��� ������
	int number_of_strings = 0;
	if (file.is_open())
	{
		string buffer;
		while (getline(file, buffer))
			number_of_strings++;
	}
	file.close();
	return number_of_strings;
}

// ��������
bool mySortByLogin(Account a, Account b) {
	return a.login < b.login;
}
void sortByLogin(vector <Account>& v) {
	system("cls");
	sort(v.begin(), v.end(), mySortByLogin);
}
bool mySortByRole(Account a, Account b) {
	return a.role > b.role;
}
void sortByRole(vector <Account>& v) {
	system("cls");
	sort(v.begin(), v.end(), mySortByRole);
}