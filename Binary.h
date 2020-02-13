#ifndef BINARY_H
#define BINARY_H
#include<iostream>
using namespace std;
class Binary {

	//Binary();
	//~Binary();
private:
	//��������, �� ��� ���������
	string multiplicationHelp(string newStr1, string newStr2);
	string divisionHelp(string str1, string str2);
public:
	//��������, ������������� �� �����
	bool minus(int input);
	//�������� ������� ����� ��� ���������� ���������
	int correctInput(int input);
	//��������
	string sum(int num1, int num2);
	//���������
	string subtraction(int num1, int num2);
	//���������
	string multiplication(int num1, int num2);
	//�������
	string division(int num1, int num2);
	//�������������� �� ���������� � ��������
	string inBinary(int num);
	//��������������
	char flip(char c) { return (c == '0') ? '1' : '0'; }
	//�������������� � �������� ��� � �������������� ���
	string printOneAndTwosComplement(string bin);
};


#endif // BINARYCALC_H

