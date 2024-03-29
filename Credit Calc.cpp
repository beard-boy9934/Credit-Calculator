#include "stdc++.h"
#include<bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include "windows.h"
using namespace std;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class applicant
{
	string name;
	int age;
	string address;
	int m_sal;
	int h_loan;
	int p_loan;
	int no_chq_bounce;
	char own_house;
	char spouse_working;
	char dependent_parents;
	int company_tier;

public:
	void get_data();
	int calc_liability();
	void display_score();
};
void applicant::get_data()
{
	system("cls");
	cout << "Name of applicant: ";
	getline(cin, name);
	cout << "Age:";
	cin >> age;

	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Address: ";
	getline(cin, address);

	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Monthly Salary: ";
	cin >> m_sal;
	cout << "Total Home Loan EMI: ";
	cin >> h_loan;
	cout << "Total Personal Loan EMI: ";
	cin >> p_loan;
	cout << "Number of cheque bounce in last six months:";
	cin >> no_chq_bounce;
	cout << "own_house? (y or n): ";
	cin >> own_house;
	cout << "spouse working? (y or  n) : ";
	cin >> spouse_working;
	cout << "Dependent_parents? (y or n) :";
	cin >> dependent_parents;
	cout << "company_tier? (1, 2, or 3): ";
	cin >> company_tier;
}

int applicant::calc_liability()
{
	int score = 0;
	int liability;

	if (age > 22 && age <= 30)
		score = score + 2;
	else if (age > 30 && age <= 35)
		score = score + 1;
	else
		score = score - 1;
	liability = h_loan + p_loan;
	if (liability <= m_sal / 4)
		score = score + 5;
	if (liability > m_sal / 4 && liability <= m_sal / 3)
		score = score + 3;
	if (liability > m_sal / 3 && liability <= m_sal / 2)
		score = score + 1;
	if (liability > m_sal / 2)
		score = score - 1;
	if (no_chq_bounce > 1)
		score = score - 2;
	if (no_chq_bounce == 1)
		score = score - 1;
	if (no_chq_bounce == 1)
		score = score + 1;
	if (p_loan > h_loan)
		score = score - 1;
	else
		score = score + 1;
	if (own_house == 'y')
		score = score + 1;
	if (spouse_working == 'y')
		score = score + 1;
	if (dependent_parents == 'y')
		score = score - 1;
	else
		score = score + 1;
	if (company_tier == 1)
		score = score + 3;
	if (company_tier == 2)
		score = score + 2;
	else
		score = score + 1;
	return (score);
}

void applicant ::display_score()
{
	int sc = calc_liability();
	system("cls");

	if (sc > 9)
		cout << "The applicant " << name << " is at low risk.\nCredit score =" << sc << "\nCredit can be given. ";
	else
	{
		if (sc > 5 && sc <= 9)
			cout << "The applicant " << name << " is at average risk.\nCredit score = " << sc << "\nCredit can be given with due precaution.";

		else
			cout << "The applicant " << name << " is at high risk.\nCredit score = " << sc << "\nCredit can be given.";
	}
	getch();
}

int main()

{
	char flag = 'f';
	applicant a;
	char ch;
	while (1)
	{
		system("cls");
		gotoxy(31, 8);
		cout << "Credit CalC";
		gotoxy(31, 9);
		cout << "__________";
		gotoxy(22, 12);
		cout << "1 - Enter loan applicant's details";
		gotoxy(22, 13);
		cout << "2 - Display credit score";
		gotoxy(22, 14);
		cout << "3 - Exit";
		gotoxy(22, 16);
		cout << "select an option by typing the numeric code: ";
		ch = getch();
		switch (ch)
		{
		case ('1'):
		{
			a.get_data();
			flag = 't';
			break;
		}

		case ('2'):
		{
			if (flag == 'f')
			{
				gotoxy(22, 18);
				cout << "Loan applicant's details not yet entered! press anykey to continue..";
				getch();
			}
			else
				a.display_score();
			break;
		}
		case ('3'):
		{
			exit(1);
			break;
		}

		deafult:
		{
			gotoxy(22, 18);
			cout << "invalid Choice! Press any key to continue..";
			getch();
		}
			{
			}
		}
	}
}
