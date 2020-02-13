#include "Binary.h"
#include <bitset>
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

bool Binary::minus(int input) {
	string strInp = to_string(input);
	if (strInp[0] == '-') return true;
	else return false;
}

int Binary::correctInput(int input) {
	string strInp = to_string(input);
	if (strInp[0] == '-') {
		strInp.erase(strInp.find('-'), 1);
		int i = stoi(strInp);
		return i;
	}
	else  return input;
}
string Binary::sum(int num1, int num2) {
	string newStr1;
	string newStr2;
	if (minus(num1) == true) {

		newStr1 = printOneAndTwosComplement(inBinary(correctInput(num1)));
	}
	else {
		newStr1 = inBinary(num1);
	}
	if (minus(num2) == true) {
		newStr2 = printOneAndTwosComplement(inBinary(correctInput(num2)));
	}
	else {
		newStr2 = inBinary(num2);
	}

	if (newStr1.length() > newStr2.length())
		swap(newStr1, newStr2);
	string str = "";
	int n1 = newStr1.length(), n2 = newStr2.length();
	reverse(newStr1.begin(), newStr1.end());
	reverse(newStr2.begin(), newStr2.end());
	int carry = 0;
	for (int i = 0; i < n1; i++) {
		int sum = ((newStr1[i] - '0') + (newStr2[i] - '0') + carry);
		str.push_back(sum % 2 + '0');
		carry = sum / 2;
	}
	for (int i = n1; i < n2; i++) {
		int sum = ((newStr2[i] - '0') + carry);
		str.push_back(sum % 2 + '0');
		carry = sum / 2;
	}
	if (carry)
		str.push_back(carry + '0');
	if (str.size() > 8) {
		str.pop_back();
	}
	reverse(str.begin(), str.end());
	return str;
}
string Binary::inBinary(int num) {
	int copy, a = 0;
	string str, result;
	while (num != 0) {
		copy = num;
		copy = copy / 2;
		a = num % 2;
		num = copy;
		str += to_string(a);
	}
	for (int i = str.length() - 1; i >= 0; i--) {
		result += str[i];
	}
	for (int i = str.length() - 1; i < 7; i++)
		result = "0" + result;
	return result;
}
string Binary::printOneAndTwosComplement(string bin) {
	int n = bin.length();
	int i;

	string ones, twos;
	ones = twos = "";

	//  for ones complement flip every bit
	for (i = 0; i < n; i++)
		ones += flip(bin[i]);

	//  for two's complement go from right to left in ones complement and if we get 1 make, we make them 0 and keep going left when we get first 0, make that 1 and go out of loop
	twos = ones;
	for (i = n - 1; i >= 0; i--) {
		if (ones[i] == '1')
			twos[i] = '0';
		else {
			twos[i] = '1';
			break;
		}
	}

	// If No break : all are 1  as in 111  or  11111; in such case, add extra 1 at beginning
	if (i == -1)
		twos = '1' + twos;

	cout << "Обратный код: " << ones << endl;
	cout << "Дополнительный код: " << twos << endl;
	return twos;
}

string Binary::subtraction(int num1, int num2) {
	if (minus(num2) == true)
		num2 *= -1;
	return sum(num1, num2);
}

string Binary::multiplicationHelp(string newStr1, string newStr2) {
	string str = "";
	if (newStr1.length() > newStr2.length())
		swap(newStr1, newStr2);
	int n1 = newStr1.length(), n2 = newStr2.length();
	reverse(newStr1.begin(), newStr1.end());
	reverse(newStr2.begin(), newStr2.end());
	int carry = 0;
	for (int i = 0; i < n1; i++) {
		int sum = ((newStr1[i] - '0') + (newStr2[i] - '0') + carry);
		str.push_back(sum % 2 + '0');
		carry = sum / 2;
	}
	for (int i = n1; i < n2; i++) {
		int sum = ((newStr2[i] - '0') + carry);
		str.push_back(sum % 2 + '0');
		carry = sum / 2;
	}
	if (carry)
		str.push_back(carry + '0');
	if (str.size() > 8) {
		str.pop_back();
	}
	reverse(str.begin(), str.end());
	return str;
}

string Binary::multiplication(int num1, int num2) {
	string str = "", str1;
	if (minus(num1))
		str1 = inBinary(correctInput(num1));
	else
		str1 = inBinary(num1);
	for (int i = 0; i < abs(num2); i++) {
		str = multiplicationHelp(str, str1);
	}
	if (minus(num1) && !minus(num2) || !minus(num1) && minus(num2))
		return printOneAndTwosComplement(str);
	return str;
}

string Binary::divisionHelp(string str1, string str2) {
	str2 = printOneAndTwosComplement(str2);
	return multiplicationHelp(str1, str2);
}

string Binary::division(int num1, int num2) {
	string str = "", strOne = "00000001";
	string str1, str2;
	str1 = inBinary(correctInput(num1));
	str2 = inBinary(correctInput(num2));
	while (str1 >= str2) {
		str = multiplicationHelp(str, strOne);
		str1 = divisionHelp(str1, str2);
	}
	if (minus(num1) && !minus(num2) || !minus(num1) && minus(num2))
		return printOneAndTwosComplement(str);
	return str;
}

