#include <iostream>
#include <vector>

using namespace std;

// FUNCTION PROTOTYPES

// Displays all recorded temperatures
void displayTemperatures(const vector<double>& temps);

// Calculates and returns the average temperature
double calculateAverage(const vector<double>& temps);

// Returns the highest temperature recorded
double getHighest(const vector<double>& temps);

// Returns the lowest temperature recorded
double getLowest(const vector<double>& temps);

// Counts how many temperatures are above 40°C
int countExtremeHot(const vector<double>& temps);

// Sorts temperatures in ascending order using Bubble Sort
vector<double> sortAscending(vector<double> temps);

// Categorizes temperatures as Cold, Normal, or Hot
void categorizeTemperatures(const vector<double>& temps);

int main() {

    char choice;

    // MAIN PROGRAM LOOP
    // Allows user to repeat the program for another day

    do {

        int numReadings;

        cout << "\nDAILY TEMPERATURE MONITORING SYSTEM\n";

        // INPUT VALIDATION FOR NUMBER OF READINGS
        // Ensures user enters a valid positive number

        do {
            cout << "Enter number of temperature readings: ";
            cin >> numReadings;

            if (cin.fail() || numReadings <= 0) {
                cout << "Invalid input. Enter a number greater than 0.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

        } while (cin.fail() || numReadings <= 0);

        vector<double> temperatures;


        // INPUT TEMPERATURE READINGS
        // Accepts only values between 0 and 50

        for (int i = 0; i < numReadings; i++) {

            double temp;

            while (true) {

                cout << "Enter temperature #" << i + 1 << ": ";
                cin >> temp;

                // Check if input is not numeric
                if (cin.fail()) {
                    cout << "Invalid input. Numbers only.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                // Check if temperature is outside valid range
                else if (temp <= 0 || temp > 50) {
                    cout << "Temperature must be between 0 and 50.\n";
                }

                // Store valid temperature
                else {
                    temperatures.push_back(temp);
                    break;
                }
            }
        }

        // DISPLAY RECORDED TEMPERATURES

        cout << "\nRecorded Temperatures: ";
        displayTemperatures(temperatures);


        // DISPLAY TEMPERATURE ANALYSIS

        cout << "Average Temperature: "
             << calculateAverage(temperatures) << "°C\n";

        cout << "Highest Temperature: "
             << getHighest(temperatures) << "°C\n";

        cout << "Lowest Temperature: "
             << getLowest(temperatures) << "°C\n";

        cout << "Temperatures above 40°C: "
             << countExtremeHot(temperatures) << "\n";


        // SORT TEMPERATURES USING BUBBLE SORT

        vector<double> sortedTemps = sortAscending(temperatures);

        cout << "Sorted Temperatures (Ascending): ";
        displayTemperatures(sortedTemps);


        // DISPLAY TEMPERATURE CATEGORIES

        cout << "\nTemperature Categorization:\n";
        categorizeTemperatures(temperatures);


        // ASK USER IF THEY WANT TO RUN THE PROGRAM AGAIN

        cout << "\nDo you want to enter another day? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nProgram Ended.\n";

    return 0;
}

// FUNCTION: displayTemperatures
// Displays all temperatures separated by commas

void displayTemperatures(const vector<double>& temps) {

    for (int i = 0; i < temps.size(); i++) {

        cout << temps[i] << "°C";

        if (i != temps.size() - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

// FUNCTION: calculateAverage
// Computes the average of all temperatures

double calculateAverage(const vector<double>& temps) {

    double sum = 0;

    for (double temp : temps) {
        sum += temp;
    }

    return sum / temps.size();
}

// FUNCTION: getHighest
// Finds and returns the highest temperature

double getHighest(const vector<double>& temps) {

    double highest = temps[0];

    for (double temp : temps) {

        if (temp > highest) {
            highest = temp;
        }
    }

    return highest;
}

// FUNCTION: getLowest
// Finds and returns the lowest temperature

double getLowest(const vector<double>& temps) {

    double lowest = temps[0];

    for (double temp : temps) {

        if (temp < lowest) {
            lowest = temp;
        }
    }

    return lowest;
}

// FUNCTION: countExtremeHot
// Counts temperatures greater than 40°C

int countExtremeHot(const vector<double>& temps) {

    int count = 0;

    for (double temp : temps) {

        if (temp > 40) {
            count++;
        }
    }

    return count;
}

// FUNCTION: sortAscending
// Sorts temperatures using Bubble Sort algorithm

vector<double> sortAscending(vector<double> temps) {

    // Outer loop controls the number of passes
    for (int i = 0; i < temps.size() - 1; i++) {

        // Inner loop compares values besides each other
        for (int j = 0; j < temps.size() - i - 1; j++) {

            // Swap values if left value is greater, using swap()
            if (temps[j] > temps[j + 1]) {
                swap(temps[j], temps[j + 1]);
            }
        }
    }

    return temps;
}

// FUNCTION: categorizeTemperatures
// Labels each temperature as:
// Cold   -> below 20°C
// Normal -> 20°C to 34°C
// Hot    -> above 34°C

void categorizeTemperatures(const vector<double>& temps) {

    for (int i = 0; i < temps.size(); i++) {

        if (temps[i] < 20) {
            cout << temps[i] << "°C - Cold\n";
        }
        else if (temps[i] <= 34) {
            cout << temps[i] << "°C - Normal\n";
        }
        else {
            cout << temps[i] << "°C - Hot\n";
        }
    }
}
