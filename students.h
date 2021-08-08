#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "validation.h"

using namespace std;

const string FILE_OF_DATA = "students.txt";
// Структура для оценок
struct Marks {
	//экзамены
	int os;
	int math;
	int oaip;
	int fil;
	//зачеты
	int hist;
	int pe;
	int ikg;
	int okp;
	int english;
	double average;
};
// Стурктура для студента
struct Student
{
	string surname; // Фамилия
	int group_number; // Номер группы
	int active; // Показатель активности (1 - активен, 0 - неактивен)
	double benefits; // Размер стипендии
	Marks marks; // Отдельная структура для фиксации оценок по каждому предмету
};

// ФУНКЦИИ ДЛЯ РАБОТЫ СО СТУДЕНТАМИ
// Отображение списка студентов с основной информацией
void showStudents(vector <Student>& v);
// Чтение информации о студентах из файла в вектор
void readFileStudents(vector <Student>& v);
// Запись вектора со студентами в файл
void writeFileStudents(vector <Student>& v);
// Отображение списка студентов с их успеваемостью
void showStudentsPerfomance(vector <Student>& v);
// Удаление конкретного студента
void deleteStudent(vector <Student>& v);
// Флаг для отличников
bool otlichnik(Student a);
// Изменение размера базовой стипендии
void defaultBenefitChange(vector <Student>& v);
// Добавление нового студента в систему
void addStudent(vector <Student>& v);
// Изменение информации о студенте
void editStudent(vector <Student>& v);
// Возможность изменения информации о только что добаленном студенте
void editAddedStudent(Student a);
// Пользовательский вариант меню со студентами
void showStudentsForUser(vector <Student>& v);
// Функции сортировки
// Сортировка по размеру стипендии
bool mySortByBenefit(Student a, Student b);
void sortByBenefit(vector <Student>& v);
// Сортировка по активности
bool mySortByActive(Student a, Student b);
void sortByActive(vector <Student>& v);
// Сортировка по среднему баллу
bool mySortByAverageMark(Student a, Student b);
void sortByAverageMark(vector <Student>& v);
// Сортировка по алфавиту (по полю с фамилиями)
bool mySortBySurname(Student a, Student b);
void sortBySurname(vector <Student>& v);
