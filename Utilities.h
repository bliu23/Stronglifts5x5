#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using namespace std;

const int TARGET_REPS = 5;
const int TARGET_SETS = 5;
const int NUMBER_OF_EXERCISES = 5;
const int EXERCISES_PER_WORKOUT = 3;
const int NUMBER_OF_DATAS_RECORDED = 7;

const double KG_INCREMENT = 2.5;
const double LB_INCREMENT = 5;

bool isNumber(string input);
double stringToDouble(string input);
int stringToInt(string input);
void convertToLowercase(string &input);
bool isAllAlpha(string input);

#endif