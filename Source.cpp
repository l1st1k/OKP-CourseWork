#include <windows.h>
#include <vector>

#include "accs.h"
#include "students.h"
#include "interfaces.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <Account> vec_of_accounts(getCountOfStucturesInFile(FILE_OF_ACCOUNTS));
	vector <Student> vec_of_students(getCountOfStucturesInFile(FILE_OF_DATA));
	readFileAccounts(vec_of_accounts);
	readFileStudents(vec_of_students);

	System(vec_of_students, vec_of_accounts);

	writeFileStudents(vec_of_students);
	writeFileAccounts(vec_of_accounts);
	system("pause");
	return 0;
}