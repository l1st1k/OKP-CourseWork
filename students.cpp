#include "students.h"

void showStudentsPerfomance(vector <Student>& v) {
	system("cls");
	bool flag = true;
	int number = 1;
	while (flag) {
		cout << "                   Экзамены                   Зачеты" << endl;
		cout << "№  Фамилия\tОС/Мат/ОАиП/Фил\t\tИст/ФК/ИКГ/ОКП/Англ\tСр. балл" << endl;
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
		cout << "Выберите действие: " << endl << "1) Отсортировать по алфавиту" << endl << "2) Отсортировать по среднему баллу" << endl << "3) Назад" << endl;
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
		cout << "№  Фамилия\tГруппа\tАктивность\tСр.б.\tСтипендия" << endl;
		cout << "---------------------------------------------------------" << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << number++ << ") "
				<< v[i].surname << "\t"
				<< v[i].group_number << "\t";
			if (v[i].active == 0) {
				cout << "Неактивен" << "\t";
			}
			else { cout << "  Активен" << "\t"; }
			cout << v[i].marks.average << "\t"
				<< v[i].benefits << endl;
		}
		cout << endl;
		cout << "Выберите действие: " << endl << "1) Отсортировать по алфавиту" << endl << "2) Отсортировать по активности" << endl << "3) Отсортировать по среднему баллу" << endl << "4) Отсортировать по размеру стипендии" << endl << "5) Изменить базовую стипендию" << endl << "6) Назад" << endl;
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
		cout << "№  Фамилия\tГруппа\tАктивность\tСр.б.\tСтипендия" << endl;
		cout << "---------------------------------------------------------" << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << number++ << ") "
				<< v[i].surname << "\t"
				<< v[i].group_number << "\t";
			if (v[i].active == 0) {
				cout << "Неактивен" << "\t";
			}
			else { cout << "  Активен" << "\t"; }
			cout << v[i].marks.average << "\t"
				<< v[i].benefits << endl;
		}
		cout << endl;
		cout << "Выберите действие: " << endl << "1) Отсортировать по алфавиту" << endl << "2) Отсортировать по активности" << endl << "3) Отсортировать по среднему баллу" << endl << "4) Отсортировать по размеру стипендии" << endl << "5) Добавить студента" << endl << "6) Редактировать данные студента" << endl << "7) Удалить студента" << endl << "8) Изменить базовую стипендию" << endl << "9) Назад" << endl;
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
	cout << "Введите номер изменяемой записи: ";
	int index = inputNumber(1, v.size()) - 1;
	system("cls");
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Какую информацию вы хотите изменить?" << endl
			<< "1) Фамилию (" << v[index].surname << ")" << endl
			<< "2) Номер группы (" << v[index].group_number << ")" << endl
			<< "3) Активность (";
		if (v[index].active == 1) { cout << "Активен"; }
		else { cout << "Неактивен"; }
		cout << ")" << endl
			<< "4) Оценку по Математике (" << v[index].marks.math << ")" << endl
			<< "5) Оценку по ОС (" << v[index].marks.os << ")" << endl
			<< "6) Оценку по Философии (" << v[index].marks.fil << ")" << endl
			<< "7) Оценку по ОАиП (" << v[index].marks.oaip << ")" << endl
			<< "8) Зачет по ИКГ (";
		if (v[index].marks.ikg == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "9) Зачет по Английскому языку (";
		if (v[index].marks.english == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "10) Зачет по ОКП (";
		if (v[index].marks.okp == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "11) Зачет по Истории (";
		if (v[index].marks.hist == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "12) Зачет по Физической культуре (";
		if (v[index].marks.pe == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "13) Завершить редактирование" << endl;
		int choice = inputNumber(1, 13);
		switch (choice)
		{
		case 1:
			cout << "Введите новую фамилию: ";
			cin >> v[index].surname;
			break;
		case 2:
			cout << "Введите новый номер группы: ";
			cin >> v[index].group_number;
			break;
		case 3:
			if (v[index].active == 1) { v[index].active = 0; }
			else { v[index].active = 1; }
			break;
		case 4:
			cout << "Новая оценка по Математике: ";
			cin >> v[index].marks.math;
			break;
		case 5:
			cout << "Новая оценка по ОС: ";
			cin >> v[index].marks.os;
			break;
		case 6:
			cout << "Новая оценка по Философии: ";
			cin >> v[index].marks.fil;
			break;
		case 7:
			cout << "Новая оценка по ОАиП: ";
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
		cout << "Какую информацию вы хотите изменить?" << endl
			<< "1) Фамилию (" << a.surname << ")" << endl
			<< "2) Номер группы (" << a.group_number << ")" << endl
			<< "3) Активность (";
		if (a.active == 1) { cout << "Активен"; }
		else { cout << "Неактивен"; }
		cout << ")" << endl
			<< "4) Оценку по Математике (" << a.marks.math << ")" << endl
			<< "5) Оценку по ОС (" << a.marks.os << ")" << endl
			<< "6) Оценку по Философии (" << a.marks.fil << ")" << endl
			<< "7) Оценку по ОАиП (" << a.marks.oaip << ")" << endl
			<< "8) Зачет по ИКГ (";
		if (a.marks.ikg == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "9) Зачет по Английскому языку (";
		if (a.marks.english == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "10) Зачет по ОКП (";
		if (a.marks.okp == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "11) Зачет по Истории (";
		if (a.marks.hist == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "12) Зачет по Физической культуре (";
		if (a.marks.pe == 1) { cout << "Зачет"; }
		else { cout << "Незачет"; }
		cout << ")" << endl
			<< "13) Завершить редактирование и сохранить студента" << endl;
		int choice = inputNumber(1, 13);
		switch (choice)
		{
		case 1:
			cout << "Введите новую фамилию: ";
			cin >> a.surname;
			break;
		case 2:
			cout << "Введите новый номер группы: ";
			cin >> a.group_number;
			break;
		case 3:
			if (a.active == 1) { a.active = 0; }
			else { a.active = 1; }
			break;
		case 4:
			cout << "Новая оценка по Математике: ";
			cin >> a.marks.math;
			break;
		case 5:
			cout << "Новая оценка по ОС: ";
			cin >> a.marks.os;
			break;
		case 6:
			cout << "Новая оценка по Философии: ";
			cin >> a.marks.fil;
			break;
		case 7:
			cout << "Новая оценка по ОАиП: ";
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
	cout << "Добавление нового студента в систему" << endl;
	cout << "Введите фамилию:  ";
	cin >> new_student.surname;
	cout << "Введите номер группы:  ";
	cin >> new_student.group_number;
	cout << "Студент ведет активную общественную жизнь?" << endl << "1) Да" << endl << "2) Нет" << endl;
	int active = inputNumber(1, 2);
	if (active == 1) { new_student.active = 1; }
	else { new_student.active = 0; }
	cout << "Оценка студента за экзамен по ОС:";
	new_student.marks.os = inputNumber(4, 10);
	cout << "Оценка студента за экзамен по ОАиП:";
	new_student.marks.oaip = inputNumber(4, 10);
	cout << "Оценка студента за экзамен по Математике:";
	new_student.marks.math = inputNumber(4, 10);
	cout << "Оценка студента за экзамен по Философии:";
	new_student.marks.fil = inputNumber(4, 10);
	new_student.marks.average = (new_student.marks.os + new_student.marks.oaip + new_student.marks.math + new_student.marks.fil) / 4.;
	new_student.benefits = 0;
	cout << "Студент сдал зачет по дисциплине 'ИКГ'?" << endl << "1) Да" << endl << "2) Нет" << endl;
	int choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.ikg = 1; }
	else { new_student.marks.ikg = 0; }

	cout << "Студент сдал зачет по дисциплине 'Физическая культура'?" << endl << "1) Да" << endl << "2) Нет" << endl;
	choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.pe = 1; }
	else { new_student.marks.pe = 0; }

	cout << "Студент сдал зачет по дисциплине 'История'?" << endl << "1) Да" << endl << "2) Нет" << endl;
	choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.hist = 1; }
	else { new_student.marks.hist = 0; }

	cout << "Студент сдал зачет по дисциплине 'Английский язык'?" << endl << "1) Да" << endl << "2) Нет" << endl;
	choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.english = 1; }
	else { new_student.marks.english = 0; }

	cout << "Студент сдал зачет по дисциплине 'ОКП'?" << endl << "1) Да" << endl << "2) Не смей сюда нажимать! Должно быть стыдно... " << endl << endl;
	choice = inputNumber(1, 2);
	if (choice == 1) { new_student.marks.okp = 1; }
	else {
		new_student.marks.okp = 0;
		cout << "Это никчемный студент, довольно бесполезной информации!" << endl;
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
	cout << "Введите размер базовой стипендии: ";
	int benefit = inputNumber(1, 500);
	for (int i = 0; i < v.size(); i++) {
		v[i].benefits = benefit;
		if (v[i].marks.average <= 5) v[i].benefits = 0;
		if (otlichnik(v[i]) && v[i].active == 1) v[i].benefits = 1.5 * benefit;
		if (otlichnik(v[i]) && v[i].active == 0) v[i].benefits = 1.25 * benefit;
	}
}

void deleteStudent(vector <Student>& v) {
	cout << "Введите номер удаляемое записи: ";
	int index = inputNumber(1, v.size()) - 1;
	system("cls");
	cout << "Вы действительно хотите удалить студента " << v[index].surname << " из системы?" << endl << "1) Да" << endl << "2) Отменить" << endl;
	int choice = inputNumber(1, 2);
	if (choice == 1) v.erase(v.begin() + index);
	system("cls");
}

void readFileStudents(vector <Student>& v) {
	ifstream fin(FILE_OF_DATA, ios::in); // Открыли файл для чтения
	if (!fin.is_open()) {
		cout << "На данный момент не существует ни одного студента в системе." << endl << "Пожалуйста, добавьте нового студента!" << endl;
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
	fin.close(); //Закрыли файл
}

void writeFileStudents(vector <Student>& v) {
	ofstream fout(FILE_OF_DATA, ios::out); // Открыли файл для записи
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
