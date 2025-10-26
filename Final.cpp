#include <iostream>
#include <cstdlib>//for random event generator
#include <ctime>//for srand time seed function
#include <string>//string text
using namespace std;

//Functions Prototypes
void start_day();
void pre_flight_check();
int get_weather();
int total_distance();
int check_obstacle();
double total_time(double,bool);
double battery_consumption(double, double);
bool heavy_load_check();
bool deliver_package(string location);
void post_delivery_check(int weather, bool obstacle);
void display_summary(int success, int failed, int delayed,double);


//Main Funciton
int main() {
    srand(time(0)); //random seed
    int success = 0, failed = 0, delayed = 0, weather;
    double battery = 100.0;
    double distance,l_time = 0,t_time = 0;//assign variables to counters
    string location;//location assignment
    bool obstacle, heavy;
    char start;
   
    cout << "===== DRONE DELIVERY SIMULATION =====\n\n";
    cout << "WELCOME TO DRONE DELIVERY SIMULATION\n\n";
    cout << "Initial Battery = "<<battery<<"%\n\n";
    cout << "Start Deliveries? (y/n): ";
    cin >> start;
    if (start != 'y' && start != 'Y') {
        cout << "\nDelivery Aborted.\n";
        display_summary(success, failed, delayed,t_time);//summary shown
        return 0;
    }//end system early with return 0

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
        distance = total_distance();
        cout << "\nResponse:\n";//response of drones with conditions taken into notice
        if (weather == 2) {
            if (obstacle) {
                cout << "Obstacle detected! Adjusting route...\n\n";
                distance = distance + 0.1;
            }
            if (heavy) cout << "Heavy load! Adjusting speed...\n\n";//heavy check with function
            if (deliver_package(location)) {
                if (heavy) 
                {
                    battery = battery - 4 * battery_consumption(distance, obstacle);
                }

                else {
                    battery = battery - 2 * battery_consumption(distance, obstacle);
                }
                /*taking into account when battery is depleted even though it has a very small chance*/
                if (battery <= 0) {
                    battery = 0;
                    cout << "\nNo battery left, Delaying all deliveries";
                    if (i == 1) delayed = delayed + 3;
                    if (i == 2) delayed = delayed + 2;
                    else if (i == 3) delayed = delayed + 1;
                    distance = 0;
                    break;
                }
                cout << "\nTotal distance covered: " << distance;
                cout << " km\n";
                success++;//success counter increment upon successful delivery
                cout << "\n\nPackage delivered successfully!\n";
                l_time = 2*total_time(distance, heavy);
                cout << "Battery remaining: " << battery <<"%\n";
                cout << "Total Time taken for delivery: "<<l_time << " minutes";
            }

            else {
                distance = 0;
                failed++;
            }//failed counter increment when delivery failed
            post_delivery_check(weather, obstacle);
            
        }

        else if (weather == 3)
        {
            cout << "Rain detected! Flight delayed.\n";
            distance = 0,l_time = 0;
            delayed++;
        }//delayed counter increment when flight cancelled

        else
        {
            if (obstacle) { 
                cout << "Obstacle detected! Adjusting route...\n\n";
                distance = distance + 0.1;
            }
            if (heavy) cout << "\nHeavy load! Adjusting speed...\n\n";//heavy check with funcion

            if (deliver_package(location)) {
                
                if (heavy)
                {
                    battery = battery - 4 * battery_consumption(distance, obstacle);
                }

                else {
                    battery = battery - 2 * battery_consumption(distance, obstacle);
                }

                /*taking into account when battery is depleted even though it has a very small chance*/
                if (battery <= 0) {
                    battery = 0;
                    cout << "\nNo battery left, Delaying all deliveries";
                    if (i == 1) delayed = delayed + 3;
                    if (i == 2) delayed = delayed + 2;
                    else if (i == 3) delayed = delayed + 1;
                    distance = 0;
                    break;
                }

                success++;//success counter increment upon successful delivery
                cout << "\nTotal distance covered: " << distance;
                cout << " km\n";
                
                cout << "\n\nPackage delivered successfully!\n";
                l_time = total_time(distance, heavy);
                cout << "Battery remaining: " << battery<<"%\n";
                cout << "Total Time taken for delivery: " << l_time<<" minutes\n";
            }

            else { 
                distance = 0;
                failed++;
            }//failed counter increment when delivery failed
            post_delivery_check(weather, obstacle);
        }//heads up of drone information at end of flight

        if (i <= 2) {
            char next;
            cout << "\nProceed to next delivery? (y/n): ";
            cin >> next;
            if (next != 'y' && next != 'Y') break;
        }//exit loop if user wants to exit early
        t_time = t_time + l_time;
    }

    display_summary(success, failed, delayed,t_time);//summary shown in last about deliveries.
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
int check_obstacle() {
    int obs = rand() % 2; //1 is true and 0 is false
    if (obs == 1) // random obstacle detection
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
    {
        cout << "Heavy" << endl;
        return true;
    }
    else
    {
        cout << "Normal" << endl;
        return false;
    }
    
}


// delivery simulation
bool deliver_package(string location) {
    cout << "\nDelivering package to " << location << ". . . \n";
    for (int j = 1; j <= 18; j++) { cout << ". "; }//visual addition of progress bar
    int check = 1 + rand() % 10;
    if (check != 10) {
 
        return true;
    }
    else {
        cout << "\n\nA technical error occured,Flight cancelled.\n" << "Sorry for the inconvenience.Try Again Later.\n";
        return false;
    }
}


// after-delivery checks
void post_delivery_check(int weather, bool obstacle) {
    cout << "\n--- Post-Delivery Check ---\n";
    if (weather == 2) cout << "Windy landing handled with Precaution.\n";
    if (obstacle) cout << "Longer Path Taken due to Obstacle.\n";
    cout << "\nDrone ready for next Delivery.\n";
}


// summary report
void display_summary(int success, int failed, int delayed,double time) {
    cout << "\n===== DELIVERIES SUMMARY =====\n";
    cout << "Successful Deliveries: " << success << endl;
    cout << "Failed Deliveries: " << failed << endl;
    cout << "Delayed Deliveries: " << delayed << endl;
    cout << "Total time taken for all deliveries: " <<time<< " minutes\n";
    cout << "Simulation complete.\n";
}


//Taking a random initial distance for a location 
int total_distance() {
    int distance = 1 + rand() % 30;
    return distance;
}


//calculating battery consumption
double battery_consumption(double distance, double obstacle) {
    double battery_consumed = distance + 1*obstacle;
    return battery_consumed;
}


//for calculating time for a delivery to one location
double total_time(double distance,bool heavy_load ) {
    int speed = 2;// in km per min
    double loc_time = distance/speed;/*time for delivering package to a location in minutes*/
    if (heavy_load) {
        loc_time = loc_time * 2;
    }
    return loc_time;
}
