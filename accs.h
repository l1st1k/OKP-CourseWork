#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>
#include <algorithm>

#include "md5.h"
#include "validation.h"

using namespace std;

const string FILE_OF_ACCOUNTS = "accounts.txt";

// ��������� ��������
struct Account
{
	string login; // ����� �������� 
	string password; // ������ ������������ ����� md5
	int role; // ����, ��� 1 - admin, 2 - user
	int access; // ������. �������� ��� ������� � ������� ����� �������� - 0 (������������� ����� ������ �� ����������� ������ ��������), � �������� - 1
	int block; // ����������. ��������������� �������� ����� �������� - 1 � ���� ����, ��������� - 0 (�� ���������)
};

// ������� ��� ������ � ����������
// ��������� ������ �������������
void userPassChange(vector <Account>& v, Account& current_acc);
// ���� ������ � ����������� (���������� ������) 
string inputPass();
// �������� ����� ������
void deleteApplication(vector <Account>& v, int counter);
// ����� ������� ������
int searchApplicationIndex(vector <Account>& v, int counter);
// ������������� ������
void ApproveApplication(vector <Account>& v, int counter);
// ����������� ������
void showNewApplications(vector <Account>& v);
// ������� �������
void deleteAccount(vector <Account>& v, int counter, Account current_acc);
// �������� ���� ��������
void roleChange(vector <Account>& v, int counter);
// ����� ������� ������� �������� 
int searchAccIndex(vector <Account>& v, int counter);
// ���������� ��������
void blockAccount(vector <Account>& v, int counter);
// ������������� ��������
void unblockAccount(vector <Account>& v, int counter);
// ����������� ���� ���������
void showAccounts(vector <Account>& v, Account current_acc);
// �������� ������ �������� ���������������
void newAccountCreation(vector <Account>& v);
// ������ ���� ��������� � ����
void writeFileAccounts(vector <Account>& v);
// �������� ������ ��������� 
void newAccountApplication(vector <Account>& v);
// ������� ���-�� ����� � �����
int getCountOfStucturesInFile(string file_path);
//������ ��������� �� �����
void readFileAccounts(vector <Account>& v);

// ���������� ���������
// ���������� �� �������� (�� ���� � ��������)
bool mySortByLogin(Account a, Account b);
void sortByLogin(vector <Account>& v);
// ���������� �� ���� (�������������� > ������������)
bool mySortByRole(Account a, Account b);
void sortByRole(vector <Account>& v);