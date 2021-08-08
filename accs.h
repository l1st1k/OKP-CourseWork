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

// Структура аккаунта
struct Account
{
	string login; // Логин аккаунта 
	string password; // Пароль хешированный через md5
	int role; // Роль, где 1 - admin, 2 - user
	int access; // Доступ. Аккаунты без доступа к системе имеют значение - 0 (присваивается после заявки на регистрацию нового аккаунта), с доступом - 1
	int block; // Блокировка. Заблокированные аккаунты имеют значение - 1 в этом поле, остальные - 0 (по умолчанию)
};

// ФУНКЦИИ ДЛЯ РАБОТЫ С АККАУНТАМИ
// Изменение пароля пользователем
void userPassChange(vector <Account>& v, Account& current_acc);
// Ввод пароля с маскировкой (возвращает пароль) 
string inputPass();
// Удаление новой заявкм
void deleteApplication(vector <Account>& v, int counter);
// Поиск индекса заявки
int searchApplicationIndex(vector <Account>& v, int counter);
// Подтверждение заявки
void ApproveApplication(vector <Account>& v, int counter);
// Отображение заявок
void showNewApplications(vector <Account>& v);
// Удалить аккаунт
void deleteAccount(vector <Account>& v, int counter, Account current_acc);
// Изменить роль аккаунта
void roleChange(vector <Account>& v, int counter);
// Поиск индекса нужного аккаунта 
int searchAccIndex(vector <Account>& v, int counter);
// Блокировка аккаунта
void blockAccount(vector <Account>& v, int counter);
// Разблокировка аккаунта
void unblockAccount(vector <Account>& v, int counter);
// Отображение всех аккаунтов
void showAccounts(vector <Account>& v, Account current_acc);
// Создание нового аккаунта администратором
void newAccountCreation(vector <Account>& v);
// Запись всех аккаунтов в файл
void writeFileAccounts(vector <Account>& v);
// Создание нового акккаунта 
void newAccountApplication(vector <Account>& v);
// Подсчет кол-ва строк в файле
int getCountOfStucturesInFile(string file_path);
//Чтение аккаунтов из файла
void readFileAccounts(vector <Account>& v);

// Сортировки аккаунтов
// Сортировка по алфавиту (по полю с логинами)
bool mySortByLogin(Account a, Account b);
void sortByLogin(vector <Account>& v);
// Сортировка по роли (администраторы > пользователи)
bool mySortByRole(Account a, Account b);
void sortByRole(vector <Account>& v);