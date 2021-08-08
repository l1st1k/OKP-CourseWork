#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>

#include "validation.h"
#include "accs.h"
#include "students.h"
#include "md5.h"

using namespace std;
// Меню пользователя
void UserInterface(vector <Student>& vec_of_students, vector <Account>& vec_of_accounts, Account& current_account, bool& similar);
// Меню администратора
void AdminInterface(vector <Student>& vec_of_students, vector <Account>& vec_of_accounts, Account& current_account, bool& similar);
// Запуск системы
void System(vector <Student>& vec_of_students, vector <Account>& vec_of_accounts);