#ifndef BINARY_H
#define BINARY_H
#include<iostream>
using namespace std;
class Binary {

	//Binary();
	//~Binary();
private:
	//сложение, но для умножения
	string multiplicationHelp(string newStr1, string newStr2);
	string divisionHelp(string str1, string str2);
public:
	//проверка, отрицательное ли число
	bool minus(int input);
	//удаление лишнего знака для корректной обработки
	int correctInput(int input);
	//сложение
	string sum(int num1, int num2);
	//вычитание
	string subtraction(int num1, int num2);
	//умножение
	string multiplication(int num1, int num2);
	//деление
	string division(int num1, int num2);
	//преобразование из десятичной в двоичную
	string inBinary(int num);
	//инвертирование
	char flip(char c) { return (c == '0') ? '1' : '0'; }
	//преобразование в обратный код и дополнительный код
	string printOneAndTwosComplement(string bin);
};


#endif // BINARYCALC_H

