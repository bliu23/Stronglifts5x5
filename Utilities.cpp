//#include "Utilities.h"
//
//bool isNumber(string input)
//{
//	int decimal = 0;;
//	if (input == "")
//	{
//		return false;
//	}
//	for (size_t i = 0; i < input.length(); i++)
//	{
//		if (!isdigit(input[i]))
//		{
//			if (input[i] == '.' && decimal < 1)
//			{
//				decimal++;
//				continue;
//			}
//			else
//				return false;
//		}
//	}
//	return true;
//}
//
//double stringToDouble(string input)
//{
//	int length = input.length();
//	double result = 0;
//	double degree = 1;
//	size_t decimalCounter;
//	for (decimalCounter = 0; decimalCounter < input.length(); decimalCounter++)
//	{
//		//decimalCounter = position before decimal. If no match, decimal counter = end position
//		if (input[decimalCounter] == '.')
//		{
//			break;
//		}
//	}
//
//	for (size_t i = 0; i < decimalCounter; i++)
//		degree = degree * 10;
//
//	for (int i = 0; i < length; i++)
//	{
//		if (input[i] == '.')
//		{
//			continue;
//		}
//		int unit = input[i] - '0';
//		result = (unit * degree) + result;
//		degree = degree / 10;
//	}
//	return result / 10;
//}
//
//int stringToInt(string input)
//{
//	int length = input.length();
//	int result = 0;
//	int degree = 1;
//	for (int i = length; i > 0; i--)
//	{
//		char digit = input[i - 1];
//		int unit = digit - '0';
//		result = (unit * degree) + result;
//		degree = degree * 10;
//	}
//	return result;
//}
//
//void convertToLowercase(string &in)
//{
//	for (size_t i = 0; i < in.length(); i++)
//	{
//		in[i] = tolower(in[i]);
//	}
//}
//
//bool isAllAlpha(string input)
//{
//	for (size_t i = 0; i < input.length(); i++)
//	{
//		if (!isalpha(input[i]))
//			return false;
//	}
//	return true;
//}