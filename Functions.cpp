#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Function Prototypes
void startDay();
int getWeather();
bool checkObstacles();
bool deliverPackage(string location, int& battery);
void displaySummary(int success, int failed, int delayed, int battery);

int main() {

	return 0;
}

// Function Definitions
void startDay() {
	cout << "WELCOME TO DRONE DELIVERY SIMULATION\n\n";
	cout << "Initial Battery = 100%\n";
	cout << "Press any key to begin the delivery day: ";
	char x;
	cin >> x;
}

int getWeather() {
	int w = 1 + rand() % 3;   // 1 = sunny, 2 = windy, 3 = rainy
	cout << "Weather Condition: ";
	if (w == 1) {
		cout << "Sunny\n";
	}
	else if (w == 2) {
		cout << "Windy\n";
	}
	else {
		cout << "Rainy\n";
	}
	return w;
}

bool checkObstacles() {
	int obs = rand() % 2;  // 0 = none, 1 = obstacle
	if (obs == 1) {
		cout << "Obstacle detected! Rerouting in progress...\n";
		return true;
	}
	else {
		cout << "No Obstacle detected.\n";
		return false;
	}
	
}

void displaySummary(int success, int failed, int delayed, int battery) {
	cout << "\nMISSION SUMMARY\n\n";
	cout << "Total Deliveries: " << success + failed + delayed << endl;
	cout << "Successfull Deliveries: " << success << endl;
	cout << "Failed Deliveries: " << failed << endl;
	cout << "Delayed deliveries: " << delayed << endl;
	cout << "Remaining Battery: " << battery << "%" << endl << endl;
	cout << "Simulation Complete.Thank you!";
}




