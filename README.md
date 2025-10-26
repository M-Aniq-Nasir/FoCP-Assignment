--------------**DELIVERY DRONE SIMULATOR**---------------

**Title and Team Information**
1. Project Title:  "Delivery Drone Simulator"
   
2. Team Members names and roles:
   1. Muhammad Aniq Nasir(Team Lead): Logic Designer, Tester, Programmer 3
   2. Muhammad Faizan Asif: Programmer 2, Documenter
   3. Muhammad Ali Hassan: REAME.md author, Programmer 1

**Overview/Problem Description**

**1. Short Summary:**

The Drone Delivery Simulator is a simple program that shows how a delivery drone might work in real life. It simulates a drone making deliveries to different locations while facing random challenges
like bad weather, obstacles, or heavy packages. The drone’s battery level, delivery time, and success rate change based on these conditions.

**2. Applications in real world:**

This project helps understand how real delivery drones need to make smart decisions and adapt to their environment to complete tasks safely and efficiently as other modes of transportation become inefficient 
sometimes due to environmntal challenges and fuel consumption also increase pollution.

**Program Design / Logic**

**1. List of Functions implemented:**
1. start_day(): Printing of startup message.
2. pre_flight_check(): Information of drone before start of flight.
3. get_weather(): Randomly generates weather conditions.
4. total_distance(): Randomly assigns distance to delivery location.
5. check_obtsacle: Randomly decides if an obstacle is in way.
6. total_time(double, bool): Calculates the total delivery time.
7. battery_consumption(double, double): Calculates the battery usage per trip.
8. heavy_load_check(): Randomly determines if the delivery load is heavy.
9. deliver_package(string location): Simulates package delivery with success/failure chance.
10. post_delivery_check(int weather, bool obstacle): Reports post delivery status.
11. display_summary(int success, int failed, int delayed, double): Displays final delivery statistics.

**2. Logic Flow:**
1. start_day() and pre_flight_check() initialize the simulation.  
2. For each delivery location (A, B, C):  
   - The program determines weather, obstacles, and load weight.  
   - Based on these factors, the drone adjusts route/time and decides whether delivery is successful, failed, or delayed.  
3. The simulation tracks battery level, delivery success, and total time across all trips.  
4. Finally, display_summary() provides an overview of outcomes.

**3. Random Environmental Factors:**
Random numbers simulate unpredictable weather, obstacles, and delivery errors using rand() seeded by time(0).

**Execution Instructions**

**1. Compile and Run the Code:**
In Visual Studio 2022, we created a c++ file named "Final.cpp" and clicked "Start Without Debugging" to run it.

**2. Sample Input:**

Start Deliveries? (y/n): y

Proceed to next delivery? (y/n): y

Proceed to next delivery? (y/n): n

**3. Sample Output:**

===== DRONE DELIVERY SIMULATION =====

WELCOME TO DRONE DELIVERY SIMULATION

Initial Battery = 100%

Start Deliveries? (y/n): y

Starting drone simulation...

Systems initializing...

--- Pre-Flight Check ---

Motors: OK

GPS: OK

Sensors: OK

Ready for takeoff!

--- Delivery #1 to Location A ---

Conditions Detected:

Weather: Sunny

Obstacle: None

Load: Normal

Delivering package to Location A . . .

Package delivered successfully!

Battery remaining: 96%

Total Time taken for delivery: 8 minutes

Proceed to next delivery? (y/n): n

===== DELIVERIES SUMMARY =====

Successful Deliveries: 1

Failed Deliveries: 0

Delayed Deliveries: 0

Total time taken for all deliveries: 8 minutes

Simulation complete.

**4. Assumptions:**
- Deliveries happen one at a time to the same three locations (A, B, and C).
- Battery starts fully charged at 100%.
- If the battery runs out, all remaining deliveries are delayed.
- Each delivery trip starts with the remaining battery.

**Team Collaboration Summary**

**1. Division of Roles:**
1. Muhammad Aniq Nasir:
   - Created the repository
   - Designed the flowchart
   - Wrote functions of Battery Percentage, Distance, Check Weight and Time.
   - Debugging and testing
2. Muhammad Faizan Asif:
   - Wrote Main Function, Deliver Package and Pre-Flight Check function
   - Modification of code commited by Ali.
   - Made pdf file of report of whole assignment.
3. Muhammad Ali Hassan:
   - Functions Prototyping and Definitions of startup, weather, obstacles and summary
   - Wrote README.md

**2. Evidence of Git usage:**

![First screenshot](https://github.com/M-Aniq-Nasir/FoCP-Assignment/blob/main/1.png?raw=true)

![Second Screenshot](https://github.com/M-Aniq-Nasir/FoCP-Assignment/blob/main/2.png?raw=true)

Note: Screenshot of README.md commit is not present because screenshots were inserted during making of README.md

**AI Tool Reflection:**

**1. Tools used:**
1. ChatGPT
   
**2. Usage and Benefits:**
1. ChatGPT:
   -  Debugging by dry running to check for some cases with very little chances to occur.
   -  Logic of int obs = rand() % 2;
   -  Logic of Pressing 'n' or 'y' to start or exit the program.
   -  Future improvement ideas in README.md.

**3. What we learned?**
1. rand() % 2 is efficient when we want random number to be 1 or 0.
2. Take a char as input from user to start or exit the program.
3. Got idea about Arrays and File Handling.

**Future Improvements**

* Implement file handling to log each delivery’s performance and errors.
* Add array structures or data storage for managing multiple drone units simultaneously.

