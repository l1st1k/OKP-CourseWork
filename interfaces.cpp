#include "interfaces.h"

void UserInterface(vector <Student>& vec_of_students, vector <Account>& vec_of_accounts, Account& current_account, bool& similar) {
	if (current_account.access == 0) {
		cout << endl << "���� ������ �� ����������� ��� �� �������� ���������������!" << endl << endl;
		system("pause");
		similar = false;
	}
	else {
		cout << "����� ���������� � ������� ������� ���������! " << endl;
		bool user_menu_flag = true;
		while (user_menu_flag) {
			system("cls");
			cout << "�� ���������� � ������ ������������!" << endl << "1) ������� ������� ���������" << endl << "2) �������� ������" << endl << "3) ����� �� ��������" << endl;
			int user_menu_choice = inputNumber(1, 3);
			if (user_menu_choice == 1) { showStudentsForUser(vec_of_students); }
			else if (user_menu_choice == 3) {
				user_menu_flag = false;
				similar = false;
			}
			else userPassChange(vec_of_accounts, current_account);
		}
	}
}

void AdminInterface(vector <Student>& vec_of_students, vector <Account>& vec_of_accounts, Account& current_account, bool& similar) {
	int admin_acc_menu_choice, admin_main_menu_choice;
	bool admin_main_menu_flag = true;
	while (admin_main_menu_flag) {
		system("cls");
		cout << "����� ���������� � ������� ������� ���������! " << endl;
		cout << "�� ���������� � ������ ��������������!" << endl;
		cout << "1) ������� ������� ���������" << endl << "2) ������ ���������� ����������" << endl << "3) �������� ������" << endl << "4) ����� �� ��������" << endl;
		admin_main_menu_choice = inputNumber(1, 4);
		system("cls");
		bool system_menu_flag = true, acc_menu = true;
		switch (admin_main_menu_choice)
		{
		case 1:

			while (system_menu_flag) {
				cout << "----------------------------" << endl << "  ������� ������� ��������  " << endl << "----------------------------" << endl << "�������� ��������: "
					<< endl << "1) ����� ���������� � ���������"
					<< endl << "2) ������������ ���������"
					<< endl << "3) �����" << endl;
				int system_menu_choice = inputNumber(1, 3);
				switch (system_menu_choice) {
				case 1: showStudents(vec_of_students); break;
				case 2: showStudentsPerfomance(vec_of_students); break;
				case 3: system("cls"); system_menu_flag = false; break;
				}
			}
			break;
		case 2:

			while (acc_menu) {
				cout << "----------------------------------------" << endl << "  ������ ���������� ���������� �������  " << endl << "----------------------------------------" << endl << "�������� ��������: " << endl << "1) �������� ��� ��������" << endl << "2) �������� ����� ������ �� ���� � �������" << endl << "3) �����" << endl;
				admin_acc_menu_choice = inputNumber(1, 3);
				system("cls");
				switch (admin_acc_menu_choice) {
				case 1: showAccounts(vec_of_accounts, current_account); break;
				case 2: showNewApplications(vec_of_accounts); break;
				case 3: acc_menu = false; break;
				}
			}
			break;
		case 3:
			userPassChange(vec_of_accounts, current_account);
			break;
		case 4:
			admin_main_menu_flag = false;
			similar = false;
			break;
		}
	}
}

void System(vector <Student>& vec_of_students, vector <Account>& vec_of_accounts) {
	string written_login, written_password;
	Account current_account;
	bool similar = false;
	bool system_flag = true;
	while (system_flag) {
		system("cls");
		cout << "1) �����" << endl << "2) ���������������� ����� �������" << endl << "3) ����� �� �������" << endl;
		int user_choice = inputNumber(1, 3);
		system("cls");
		switch (user_choice) {
		case 1:
			cout << "��������������� � �������" << endl;
			while (!similar) {
				cout << "������� �����: "; cin >> written_login; cout << endl;
				cout << "������� ������: ";
				written_password = inputPass();
				cout << endl;
				for (int i = 0; i < vec_of_accounts.size(); i++) {
					if (vec_of_accounts[i].login == written_login && vec_of_accounts[i].password == md5(written_password)) {
						current_account = vec_of_accounts[i];
						similar = true;
					}
				}
				if (!similar) cout << "������ ������� �����������! ��������� �������. " << endl;
			}
			system("cls");
			if (current_account.block == 1) {
				cout << "��� ������� ������������!" << endl;
				system("pause");
				similar = false;
			}
			else {
				// MAIN ---------------------
				switch (current_account.role) {
				case 1:
					AdminInterface(vec_of_students, vec_of_accounts, current_account, similar);
					break;
				case 0:
					UserInterface(vec_of_students, vec_of_accounts, current_account, similar);
					break;
				}
			}
			break;
		case 2:
			newAccountApplication(vec_of_accounts); break;
		case 3: system_flag = false; break;
		}
	}
}
