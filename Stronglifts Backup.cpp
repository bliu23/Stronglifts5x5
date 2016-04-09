#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <fstream>

using namespace std;

const int TARGET_REPS = 5;
const int TARGET_SETS = 5;
const int NUMBER_OF_EXERCISES = 5;
const int EXERCISES_PER_WORKOUT = 3;
const int NUMBER_OF_DATAS_RECORDED = 7;

const double KG_INCREMENT = 2.5;
const double LB_INCREMENT = 5;

class Exercise;

bool isNumber(string input);
double stringToDouble(string input);
int stringToInt(string input);
void convertToLowercase(string &input);
bool isAllAlpha(string input);
void record(string username, Exercise Exercises[]);
void read(string username, Exercise Exercises[]);

bool isNumber(string input)
{
	int decimal = 0;;
	if (input == "")
	{
		return false;
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			if (input[i] == '.' && decimal < 1)
			{
				decimal++;
				continue;
			}
			else
				return false;
		}
	}
	return true;
}

double stringToDouble(string input)
{
	int length = input.length();
	double result = 0;
	double degree = 1;
	size_t decimalCounter;
	for (decimalCounter = 0; decimalCounter < input.length(); decimalCounter++)
	{
		//decimalCounter = position before decimal. If no match, decimal counter = end position
		if (input[decimalCounter] == '.')
		{
			break;
		}
	}

	for (size_t i = 0; i < decimalCounter; i++)
		degree = degree * 10;

	for (int i = 0; i < length; i++)
	{
		if (input[i] == '.')
		{
			continue;
		}
		int unit = input[i] - '0';
		result = (unit * degree) + result;
		degree = degree / 10;
	}
	return result / 10;
}

int stringToInt(string input)
{
	int length = input.length();
	int result = 0;
	int degree = 1;
	for (int i = length; i > 0; i--)
	{
		char digit = input[i - 1];
		int unit = digit - '0';
		result = (unit * degree) + result;
		degree = degree * 10;
	}
	return result;
}

void convertToLowercase(string &in)
{
	for (size_t i = 0; i < in.length(); i++)
	{
		in[i] = tolower(in[i]);
	}
}

bool isAllAlpha(string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isalpha(input[i]))
			return false;
	}
	return true;
}

class Exercise
{
public:
	Exercise();
	Exercise(string m_name);

	void increaseWeight();
	void setWeight(double m_weight);
	void setName(string m_name);
	void setUnitIncrement(double m_unitIncrement);
	void read(string username, int position);
	void record(string username, int position);

	bool needDeload();
	bool needToDropSets();
	bool need1x5();

	double getWeight();
	string getName();
	double getUnitIncrement();
	string getUnits();
	int getNumOfSets();
	int getFailedSets();
	int getNumOfDeloads();

private:
	double weight;
	string name;
	double unitIncrement;
	string units;
	int numOfSets;
	int failedSets;
	int numOfDeloads;
	bool switchTo1x5;
	bool droppedSets;
	int forRecordingPurposes;
};

Exercise::Exercise()
{
	weight = 0;
	name = "";
	unitIncrement = 0;
	units = "";
	failedSets = 0;
	numOfDeloads = 0;
	numOfSets = 5;
	switchTo1x5 = false;
	droppedSets = false;
	forRecordingPurposes = 0;
}

Exercise::Exercise(string m_name)
{
	weight = 0;
	name = m_name;
	unitIncrement = 0;
	units = "";
	failedSets = 0;
	numOfDeloads = 0;
	numOfSets = 5;
	switchTo1x5 = false;
	droppedSets = false;
	forRecordingPurposes = 0;
}

void Exercise::increaseWeight()
{
	string unit;
	if (unitIncrement == 5)
		unit = "LB";
	else
		unit = "KG";

	cout << name << " @ " << weight << " " << unit << endl;

	bool madeAllReps = true;
	int sets[TARGET_SETS];

	int set = 0;
	while (set < numOfSets)
	{
		cout << "Set " << set + 1 << ". Enter reps: ";
		string input;
		int reps;
		getline(cin, input);
		if (isNumber(input))
			reps = stringToInt(input);
		else
		{
			cout << "Invalid input." << endl;
			continue;
		}

		if (reps > 5 || reps < 0)
		{
			cout << "Invalid input." << endl;
			continue;
		}
		sets[set] = reps;
		if (sets[set] < 5)
			madeAllReps = false;
		set++;
	}

	if (madeAllReps)
	{
		cout << "Completed all sets." << endl;
		weight = weight + unitIncrement;
		failedSets = 0;
	}
	else
	{
		cout << "Did not complete all sets." << endl;
		failedSets++;
		cout << "Failed sets: " << failedSets << endl;
	}

	cout << endl;
}

void Exercise::setWeight(double m_weight)
{
	weight = m_weight;
}

void Exercise::setName(string m_name)
{
	name = m_name;
}

void Exercise::setUnitIncrement(double m_unitIncrement)
{
	unitIncrement = m_unitIncrement;
	if (unitIncrement == KG_INCREMENT)
		units = "KG";
	else if (unitIncrement == LB_INCREMENT)
		units = "LB";
}

void Exercise::record(string username, int position)
{
	//write
	ofstream outFile;
	string file;
	file = username + ".txt";

	//overwrite if its the first one
	if (position == 0)
	{
		outFile.open(file);
	}

	//append if not the first
	else if (position != 0)
	{
		outFile.open(file, ios_base::app);
	}

	outFile << name << endl << weight << endl << unitIncrement << endl << units << endl << numOfSets << endl
		<< failedSets << endl << numOfDeloads << endl;

	outFile.close();
}

void Exercise::read(string username, int position)
{
	ifstream inFile;
	string file;
	file = username + ".txt";

	inFile.open(file);

	if (inFile.fail())
	{
		cerr << "Error opening file." << endl;
		exit(1);
	}
	//skip lines
	for (int i = 0; i < position; i++)
	{
		for (int j = 0; j < NUMBER_OF_DATAS_RECORDED; j++)
			inFile.ignore(10000, '\n');
	}

	getline(inFile, name);
	inFile >> weight >> unitIncrement >> units >> numOfSets >> failedSets >> numOfDeloads;

	inFile.close();
}

bool Exercise::needDeload()
{
	if (failedSets == 3)
	{
		if (unitIncrement == 5) // lbs
		{
			double a = (weight)* 9 / 10;
			a = a - (fmod(a, 5));
			weight = a;
			failedSets = 0;
			numOfDeloads++;
			return true;
		}
		else // kg
		{
			double a = (weight)* 9 / 10;
			a = a - (fmod(a, 2.5));
			weight = a;
			failedSets = 0;
			numOfDeloads++;
			return true;
		}
	}
	else
		return false;
}

bool Exercise::needToDropSets()
{
	if (numOfDeloads == 2 && switchTo1x5 == true)
	{
		cout << "It is time to move onto another program." << endl;
		return true;
	}
	if (numOfDeloads == 2 && droppedSets == false)
	{
		numOfSets = 3;
		numOfDeloads = 0;
		droppedSets = true;
		return true;
	}
	else if (numOfDeloads == 2 && droppedSets == true)
	{
		numOfSets = 1;
		numOfDeloads = 0;
		switchTo1x5 = true;
		return true;
	}
	else
		return false;
}

double Exercise::getWeight()
{
	return weight;
}

double Exercise::getUnitIncrement()
{
	return unitIncrement;
}

string Exercise::getName()
{
	return name;
}

string Exercise::getUnits()
{
	return units;
}

//int Exercise::getNumOfSets()
//{
//	return numOfSets;
//}


int Exercise::getNumOfSets()
{
	return numOfSets;
}

int Exercise::getFailedSets()
{
	return failedSets;
}
int Exercise::getNumOfDeloads()
{
	return numOfDeloads;
}

int main()
{
	//welcome, intialize everything
	cout << "Welcome to Stronglifts 5x5!" << endl;
	cout << "Enter your name." << endl;
	string username;
	getline(cin, username);

	string namesOfExercises[5] = { "Squat", "Bench Press", "Barbell Row", "Overhead Press", "Deadlift" };

	Exercise WorkoutAll[5];
	for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
	{
		WorkoutAll[i].setName(namesOfExercises[i]);
	}

	bool isThereFile;
	string file;
	for (;;)
	{
		cout << "Do you have a previous file? (y/n)" << endl;
		getline(cin, file);
		//check for a file
		if (file == "y")	//there's a file, supposedly
		{
			isThereFile = true;

			//read files for all workouts
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				WorkoutAll[i].read(username, i);
			}
			break;
		}
		if (file == "n")	//no file
		{
			isThereFile = false;
			break;
		}
		else
			continue;
	}
	//no file
	if (!isThereFile)
	{
		string unit = "";
		for (;;)
		{
			cout << "Select units: KG or LB." << endl;
			getline(cin, unit);
			convertToLowercase(unit);
			if (!isAllAlpha(unit))
			{
				cout << "Invalid input" << endl;
				continue;
			}

			if (unit == "kilogram" || unit == "kg" || unit == "kilograms")
			{
				//set KG (for all)
				for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
				{
					WorkoutAll[i].setUnitIncrement(KG_INCREMENT);
				}
				cout << "Unit are set in KG." << endl;
				break;
			}
			else if (unit == "pound" || unit == "lb" || unit == "pounds")
			{
				//select LB (for all)
				for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
				{
					WorkoutAll[i].setUnitIncrement(LB_INCREMENT);
				}
				cout << "Units are set in LB." << endl;
				break;
			}
			else
				cout << "Invalid input." << endl;
		}

		cout << endl;
		cout << "Select starting weights." << endl << "If you are a beginner, start with just the bar. (20KG, 45LB)" << endl
			<< "Else, start with 50% of your 5RM." << endl;

		double initWeight;
		string input = "";

		//select weights (for all)
		for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
		{
			for (;;)
			{
				cout << WorkoutAll[i].getName() << ": ";
				getline(cin, input);
				if (isNumber(input))
				{
					initWeight = stringToDouble(input);
					WorkoutAll[i].setWeight(initWeight);
					break;
				}
				else
				{
					cout << "Invalid input." << endl;
					continue;
				}
			}
		}
	}

	cout << endl;

	//end initializing all.

	string selectWorkout;
	int whichWorkout = 1;

	//loop between workouts
	while (whichWorkout == 1 || whichWorkout == 2)
	{
		//select workout
		cout << "Select workout A or B. Or, enter 'q' to quit." << endl;
		getline(cin, selectWorkout);

		if (selectWorkout == "q" || selectWorkout == "Q")
		{
			//write in, record all workouts
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
				WorkoutAll[i].record(username, i);
			break;
		}
		else if (selectWorkout == "a" || selectWorkout == "A")
		{
			whichWorkout = 1;
		}
		else if (selectWorkout == "b" || selectWorkout == "B")
		{
			whichWorkout = 2;
		}
		else
		{
			cout << "Invalid input." << endl;
			continue;
		}

		if (whichWorkout == 1)
		{
			cout << "You Selected Workout A: Squat, Bench Press, Barbell Row." << endl;
			//run through sets
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				if (i == 3 || i == 4)
					continue;
				WorkoutAll[i].increaseWeight();
			}
			//check for deloads
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				if (i == 3 || i == 4)
					continue;
				if (WorkoutAll[i].needDeload())
					cout << "Deload on " << WorkoutAll[i].getName() << "." << endl;
			}
			//check if need to drop sets
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				if (i == 3 || i == 4)
					continue;
				if (WorkoutAll[i].needToDropSets())
					cout << "Switch to 3x5 on " << WorkoutAll[i].getName() << "." << endl;
			}

			//output weights for next workout.
			cout << "Your weights for your next Workout A will be: " << endl;
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				if (i == 3 || i == 4)
					continue;
				cout << WorkoutAll[i].getName() << ": " << WorkoutAll[i].getWeight() << " " << WorkoutAll[i].getUnits() << endl;
			}
			cout << endl;
		}
		else
		{
			cout << "You Selected Workout B: Squat, Overhead Press, Deadlift." << endl;
			//run through sets
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				if (i == 1 || i == 2)
					continue;
				WorkoutAll[i].increaseWeight();
			}
			//check for deloads
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				if (i == 1 || i == 2)
					continue;
				if (WorkoutAll[i].needDeload())
					cout << "Deload on " << WorkoutAll[i].getName() << "." << endl;
			}
			//check if need to drop sets
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				if (i == 1 || i == 2)
					continue;
				if (WorkoutAll[i].needToDropSets())
					cout << "Switch to 3x5 on " << WorkoutAll[i].getName() << "." << endl;
			}

			//output weights for next workout.
			cout << "Your weights for your next Workout B will be: " << endl;
			for (int i = 0; i < NUMBER_OF_EXERCISES; i++)
			{
				if (i == 1 || i == 2)
					continue;
				cout << WorkoutAll[i].getName() << ": " << WorkoutAll[i].getWeight() << " " << WorkoutAll[i].getUnits() << endl;
			}
			cout << endl;
		}
	}
}
