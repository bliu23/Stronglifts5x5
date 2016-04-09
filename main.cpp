//#include <string>
//#include <iostream>
//#include "Exercise.h"
//#include "Utilities.h"
//using namespace std;
//
//
//
//int main()
//{
//	//welcome, intialize everything
//	cout << "Welcome to Stronglifts 5x5!" << endl;
//	cout << "Enter your name." << endl;
//	string username;
//	getline(cin, username);
//
//	string namesOfExercises[5] = { "Squat", "Bench Press", "Barbell Row", "Overhead Press", "Deadlift" };
//
//	Exercise WorkoutAll[5];
//	for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//	{
//		WorkoutAll[i].setName(namesOfExercises[i]);
//	}
//
//	bool isThereFile;
//	string file;
//	for (;;)
//	{
//		cout << "Do you have a previous file? (y/n)" << endl;
//		getline(cin, file);
//		//check for a file
//		if (file == "y")	//there's a file, supposedly
//		{
//			isThereFile = true;
//
//			//read files for all workouts
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				WorkoutAll[i].read(username, i);
//			}
//			break;
//		}
//		if (file == "n")	//no file
//		{
//			isThereFile = false;
//			break;
//		}
//		else
//			continue;
//	}
//	//no file
//	if (!isThereFile)
//	{
//		string unit = "";
//		for (;;)
//		{
//			cout << "Select units: KG or LB." << endl;
//			getline(cin, unit);
//			convertToLowercase(unit);
//			if (!isAllAlpha(unit))
//			{
//				cout << "Invalid input" << endl;
//				continue;
//			}
//
//			if (unit == "kilogram" || unit == "kg" || unit == "kilograms")
//			{
//				//set KG (for all)
//				for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//				{
//					WorkoutAll[i].setUnitIncrement(KG_INCREMENT);
//				}
//				cout << "Unit are set in KG." << endl;
//				break;
//			}
//			else if (unit == "pound" || unit == "lb" || unit == "pounds")
//			{
//				//select LB (for all)
//				for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//				{
//					WorkoutAll[i].setUnitIncrement(LB_INCREMENT);
//				}
//				cout << "Units are set in LB." << endl;
//				break;
//			}
//			else
//				cout << "Invalid input." << endl;
//		}
//
//		cout << endl;
//		cout << "Select starting weights." << endl << "If you are a beginner, start with just the bar. (20KG, 45LB)" << endl
//			<< "Else, start with 50% of your 5RM." << endl;
//
//		double initWeight;
//		string input = "";
//
//		//select weights (for all)
//		for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//		{
//			for (;;)
//			{
//				cout << WorkoutAll[i].getName() << ": ";
//				getline(cin, input);
//				if (isNumber(input))
//				{
//					initWeight = stringToDouble(input);
//					WorkoutAll[i].setWeight(initWeight);
//					break;
//				}
//				else
//				{
//					cout << "Invalid input." << endl;
//					continue;
//				}
//			}
//		}
//	}
//
//	cout << endl;
//
//	//end initializing all.
//
//	string selectWorkout;
//	int whichWorkout = 1;
//
//	//loop between workouts
//	while (whichWorkout == 1 || whichWorkout == 2)
//	{
//		//select workout
//		cout << "Select workout A or B. Or, enter 'q' to quit." << endl;
//		getline(cin, selectWorkout);
//
//		if (selectWorkout == "q" || selectWorkout == "Q")
//		{
//			//write in, record all workouts
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//				WorkoutAll[i].record(username, i);
//			break;
//		}
//		else if (selectWorkout == "a" || selectWorkout == "A")
//		{
//			whichWorkout = 1;
//		}
//		else if (selectWorkout == "b" || selectWorkout == "B")
//		{
//			whichWorkout = 2;
//		}
//		else
//		{
//			cout << "Invalid input." << endl;
//			continue;
//		}
//
//		if (whichWorkout == 1)
//		{
//			cout << "You Selected Workout A: Squat, Bench Press, Barbell Row." << endl;
//			//run through sets
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				if (i == 3 || i == 4)
//					continue;
//				WorkoutAll[i].increaseWeight();
//			}
//			//check for deloads
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				if (i == 3 || i == 4)
//					continue;
//				if (WorkoutAll[i].needDeload())
//					cout << "Deload on " << WorkoutAll[i].getName() << "." << endl;
//			}
//			//check if need to drop sets
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				if (i == 3 || i == 4)
//					continue;
//				if (WorkoutAll[i].needToDropSets())
//					cout << "Switch to 3x5 on " << WorkoutAll[i].getName() << "." << endl;
//			}
//
//			//output weights for next workout.
//			cout << "Your weights for your next Workout A will be: " << endl;
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				if (i == 3 || i == 4)
//					continue;
//				cout << WorkoutAll[i].getName() << ": " << WorkoutAll[i].getWeight() << " " << WorkoutAll[i].getUnits() << endl;
//			}
//			cout << endl;
//		}
//		else
//		{
//			cout << "You Selected Workout B: Squat, Overhead Press, Deadlift." << endl;
//			//run through sets
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				if (i == 1 || i == 2)
//					continue;
//				WorkoutAll[i].increaseWeight();
//			}
//			//check for deloads
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				if (i == 1 || i == 2)
//					continue;
//				if (WorkoutAll[i].needDeload())
//					cout << "Deload on " << WorkoutAll[i].getName() << "." << endl;
//			}
//			//check if need to drop sets
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				if (i == 1 || i == 2)
//					continue;
//				if (WorkoutAll[i].needToDropSets())
//					cout << "Switch to 3x5 on " << WorkoutAll[i].getName() << "." << endl;
//			}
//
//			//output weights for next workout.
//			cout << "Your weights for your next Workout B will be: " << endl;
//			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
//			{
//				if (i == 1 || i == 2)
//					continue;
//				cout << WorkoutAll[i].getName() << ": " << WorkoutAll[i].getWeight() << " " << WorkoutAll[i].getUnits() << endl;
//			}
//			cout << endl;
//		}
//	}
//}