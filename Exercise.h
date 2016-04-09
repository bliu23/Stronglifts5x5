#include <string>

using namespace std;

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
	int numOfSets;
	int failedSets;
	int numOfDeloads;
	bool switchTo1x5;
	bool droppedSets;
};