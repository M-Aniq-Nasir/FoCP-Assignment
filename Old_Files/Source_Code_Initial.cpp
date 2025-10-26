#include <iostream>
#include <cstdlib>//for random event generator
#include <ctime>//for srand time seed function
#include <string>//string text
using namespace std;

//Functions Prototypes
void start_day();
void pre_flight_check();
int get_weather();
bool check_obstacle();
bool heavy_load_check();
bool deliver_package(string location);
void post_delivery_check(int weather, bool obstacle);
void display_summary(int success, int failed, int delayed);

//Main Funciton
int main() {
    srand(time(0)); //random seed
    int success = 0, failed = 0, delayed = 0, weather;//assign variables to counters
    string location;//location assignment
    bool obstacle, heavy;
    cout << "===== DRONE DELIVERY SIMULATION =====\n\n";
    cout << "WELCOME TO DRONE DELIVERY SIMULATION\n\n";
	cout << "Initial Battery = 100%\n\n";
    char start;
    cout << "Start Deliveries? (y/n): ";
    cin >> start;
    if (start != 'y' && start != 'Y') {
        cout << "\nDelivery Aborted.\n";
        display_summary(success, failed, delayed);//summary shown
        return 0;}//end system early with return 0
    start_day();//startup modules funciton calling
    pre_flight_check();//headsup of drone information at start of flight
    //three delivery attempts
    for (int i = 1; i <= 3; i++) {
        if (i == 1) location = "Location A";
        else if (i == 2) location = "Location B";
        else location = "Location C";
        cout << "\n--- Delivery #" << i << " to " << location << " ---\n\n";
        cout << "Conditions Detected:\n";
        weather = get_weather();//condtitions function calling
        obstacle = check_obstacle();
        heavy = heavy_load_check();
        cout << "\nResponse:\n";//response of drones with conditions taken into notice
        if (weather == 3)
             {cout << "Rain detected! Flight delayed.\n";
            delayed++;}//delayed counter increment when flight cancelled
        else 
        {   if (obstacle) cout << "Obstacle detected! Adjusting route...\n";
            if (heavy) cout << "Heavy load! Adjusting speed...\n";//heavy check with funcion
            if (deliver_package(location)) success++;//success counter increment upon successful delivery
            else failed++;//failed counter increment when delivery failed
            post_delivery_check(weather, obstacle);  }//heads up of drone information at end of flight
        if (i <= 2) {
            char next;
            cout << "\nProceed to next delivery? (y/n): ";
            cin >> next;
            if (next != 'y' && next != 'Y') break;}//exit loop if user wants to exit early
    }
    display_summary(success, failed, delayed);//summary shown in last about deliveries
    system("pause");
    return 0;
}

//Function Definitions
// startup display
void start_day() {
    cout << "\nStarting drone simulation...\nSystems initializing...\n";
}
// system checks before flight
void pre_flight_check() {
    cout << "\n--- Pre-Flight Check ---\nMotors: OK\nGPS: OK\nSensors: OK\nReady for takeoff!\n";
}
// random weather generator
int get_weather() {
    int w = 1 + rand() % 3; // 1=sunny, 2=windy, 3=rainy

    cout << "Weather: ";
    if (w == 1)
        cout << "Sunny\n";
    else if (w == 2)
        cout << "Windy\n";
    else
        cout << "Rainy\n";
    return w;
}
// random obstacle chance
bool check_obstacle() {
    int obs = rand() % 2; //1 is true and 0 is false
    if (obs==1) // random obstacle detection
        cout << "Obstacle: Detected\n";
    else 
        cout << "Obstacle: None\n";
    return obs;
}
// random load chance
bool heavy_load_check() {
    bool heavy = rand() % 2; // randomly decide if load is heavy
    cout << "Load: ";
    if (heavy)
    { cout << "Heavy" << endl; }
    else
    { cout << "Normal" << endl; }
    return heavy;
}
// delivery simulation
bool deliver_package(string location) {
    cout << "\nDelivering package to " << location << ". . . \n";
    for (int j = 1; j <=18; j++) {cout << ". ";}//visual addition of progress bar
    cout << "\n\nPackage delivered successfully!\n";
    return true;
}
// after-delivery checks
void post_delivery_check(int weather, bool obstacle) {
    cout << "\n--- Post-Delivery Check ---\n";
    if (weather == 2) cout << "Windy landing handled with Precaution.\n";
    if (obstacle) cout << "Longer Path Taken due to Obstacle.\n";
    cout << "\nDrone ready for next Delivery.\n";
}
// summary report
void display_summary(int success, int failed, int delayed) {
    cout << "\n===== DELIVERIES SUMMARY =====\n";
    cout << "Successful Deliveries: " << success << endl;
    cout << "Failed Deliveries: " << failed << endl;
    cout << "Delayed Deliveries: " << delayed << endl;
    cout << "Simulation complete.\n";
}
