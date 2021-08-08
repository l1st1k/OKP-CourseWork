#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "validation.h"

using namespace std;

const string FILE_OF_DATA = "students.txt";
// ��������� ��� ������
struct Marks {
	//��������
	int os;
	int math;
	int oaip;
	int fil;
	//������
	int hist;
	int pe;
	int ikg;
	int okp;
	int english;
	double average;
};
// ��������� ��� ��������
struct Student
{
	string surname; // �������
	int group_number; // ����� ������
	int active; // ���������� ���������� (1 - �������, 0 - ���������)
	double benefits; // ������ ���������
	Marks marks; // ��������� ��������� ��� �������� ������ �� ������� ��������
};

// ������� ��� ������ �� ����������
// ����������� ������ ��������� � �������� �����������
void showStudents(vector <Student>& v);
// ������ ���������� � ��������� �� ����� � ������
void readFileStudents(vector <Student>& v);
// ������ ������� �� ���������� � ����
void writeFileStudents(vector <Student>& v);
// ����������� ������ ��������� � �� �������������
void showStudentsPerfomance(vector <Student>& v);
// �������� ����������� ��������
void deleteStudent(vector <Student>& v);
// ���� ��� ����������
bool otlichnik(Student a);
// ��������� ������� ������� ���������
void defaultBenefitChange(vector <Student>& v);
// ���������� ������ �������� � �������
void addStudent(vector <Student>& v);
// ��������� ���������� � ��������
void editStudent(vector <Student>& v);
// ����������� ��������� ���������� � ������ ��� ���������� ��������
void editAddedStudent(Student a);
// ���������������� ������� ���� �� ����������
void showStudentsForUser(vector <Student>& v);
// ������� ����������
// ���������� �� ������� ���������
bool mySortByBenefit(Student a, Student b);
void sortByBenefit(vector <Student>& v);
// ���������� �� ����������
bool mySortByActive(Student a, Student b);
void sortByActive(vector <Student>& v);
// ���������� �� �������� �����
bool mySortByAverageMark(Student a, Student b);
void sortByAverageMark(vector <Student>& v);
// ���������� �� �������� (�� ���� � ���������)
bool mySortBySurname(Student a, Student b);
void sortBySurname(vector <Student>& v);
