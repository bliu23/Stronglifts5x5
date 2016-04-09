//#include <iostream>
//#include <string>
//#include <cctype>
//#include <cstdlib>
//#include <fstream>
//#include "Exercise.h"
//#include "Utilities.h"
//
//using namespace std;
//
//Exercise::Exercise()
//{
//	weight = 0;
//	name = "";
//	unitIncrement = 0;
//	units = "";
//	failedSets = 0;
//	numOfDeloads = 0;
//	numOfSets = 5;
//	switchTo1x5 = false;
//	droppedSets = false;
//}
//
//Exercise::Exercise(string m_name)
//{
//	weight = 0;
//	//name = m_name;
//	//unitIncrement = 0;
//	//units = "";
//	failedSets = 0;
//	numOfDeloads = 0;
//	numOfSets = 5;
//	switchTo1x5 = false;
//	droppedSets = false;
//}
//
//void Exercise::increaseWeight()
//{
//
//	/*string unit;
//	if (unitIncrement == 5)
//	unit = "LB";
//	else
//	unit = "KG";
//
//	cout << name << " @ " << weight << " " << unit << endl;*/
//
//	//bool madeAllReps = true;
//	//int sets[TARGET_SETS];
//
//	//int set = 0;
//	//while (set < numOfSets)
//	//{
//	//	cout << "Set " << set + 1 << ". Enter reps: ";
//	//	string input;
//	//	int reps;
//	//	getline(cin, input);
//	//	if (isNumber(input))
//	//		reps = stringToInt(input);
//	//	else
//	//	{
//	//		cout << "Invalid input." << endl;
//	//		continue;
//	//	}
//
//	//	if (reps > 5 || reps < 0)
//	//	{
//	//		cout << "Invalid input." << endl;
//	//		continue;
//	//	}
//	//	sets[set] = reps;
//	//	if (sets[set] < 5)
//	//		madeAllReps = false;
//	//	set++;
//	//}
//
//	//if (madeAllReps)
//	//{
//	//	cout << "Completed all sets." << endl;
//	//	weight = weight + unitIncrement;
//	//	failedSets = 0;
//	//}
//	//else
//	//{
//	//	cout << "Did not complete all sets." << endl;
//	//	failedSets++;
//	//	cout << "Failed sets: " << failedSets << endl;
//	//}
//
//	//cout << endl;
//}
//
//void Exercise::setWeight(double m_weight)
//{
//	weight = m_weight;
//}
//
//void Exercise::setName(string m_name)
//{
//	name = m_name;
//}
//
//void Exercise::setUnitIncrement(double m_unitIncrement)
//{
//	unitIncrement = m_unitIncrement;
//	if (unitIncrement == KG_INCREMENT)
//		units = "KG";
//	else if (unitIncrement == LB_INCREMENT)
//		units = "LB";
//}
//
//void Exercise::record(string username, int position)
//{
//	//write
//	ofstream outFile;
//	string file;
//	file = username + ".txt";
//
//	//overwrite if its the first one
//	if (position == 0)
//	{
//		outFile.open(file);
//	}
//
//	//append if not the first
//	else if (position != 0)
//	{
//		outFile.open(file, ios_base::app);
//	}
//
//	outFile << name << endl << weight << endl << unitIncrement << endl << units << endl << numOfSets << endl
//		<< failedSets << endl << numOfDeloads << endl;
//
//	outFile.close();
//}
//
//void Exercise::read(string username, int position)
//{
//	ifstream inFile;
//	string file;
//	file = username + ".txt";
//
//	inFile.open(file);
//
//	if (inFile.fail())
//	{
//		cerr << "Error opening file." << endl;
//		exit(1);
//	}
//	//skip lines
//	for (int i = 0; i < position; i++)
//	{
//		for (int j = 0; j < NUMBER_OF_DATAS_RECORDED; j++)
//			inFile.ignore(10000, '\n');
//	}
//
//	getline(inFile, name);
//	inFile >> weight >> unitIncrement >> units >> numOfSets >> failedSets >> numOfDeloads;
//
//	inFile.close();
//}
//
//bool Exercise::needDeload()
//{
//	if (failedSets == 3)
//	{
//		if (unitIncrement == 5) // lbs
//		{
//			double a = (weight)* 9 / 10;
//			a = a - (fmod(a, 5));
//			weight = a;
//			failedSets = 0;
//			numOfDeloads++;
//			return true;
//		}
//		else // kg
//		{
//			double a = (weight)* 9 / 10;
//			a = a - (fmod(a, 2.5));
//			weight = a;
//			failedSets = 0;
//			numOfDeloads++;
//			return true;
//		}
//	}
//	else
//		return false;
//}
//
//bool Exercise::needToDropSets()
//{
//	if (numOfDeloads == 2 && switchTo1x5 == true)
//	{
//		cout << "It is time to move onto another program." << endl;
//		return true;
//	}
//	if (numOfDeloads == 2 && droppedSets == false)
//	{
//		numOfSets = 3;
//		numOfDeloads = 0;
//		droppedSets = true;
//		return true;
//	}
//	else if (numOfDeloads == 2 && droppedSets == true)
//	{
//		numOfSets = 1;
//		numOfDeloads = 0;
//		switchTo1x5 = true;
//		return true;
//	}
//	else
//		return false;
//}
//
//double Exercise::getWeight()
//{
//	return weight;
//}
//
//double Exercise::getUnitIncrement()
//{
//	return unitIncrement;
//}
//
//string Exercise::getName()
//{
//	return name;
//}
//
//string Exercise::getUnits()
//{
//	return units;
//}
//
////int Exercise::getNumOfSets()
////{
////	return numOfSets;
////}
//
//
//int Exercise::getNumOfSets()
//{
//	return numOfSets;
//}
//
//int Exercise::getFailedSets()
//{
//	return failedSets;
//}
//int Exercise::getNumOfDeloads()
//{
//	return numOfDeloads;
//}
//
//
