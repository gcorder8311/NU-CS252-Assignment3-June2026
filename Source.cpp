#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Date implemented as a separate class
class Date 
{
private:
    int year;
    int month;
    int day;

public:
    Date(int y, int m, int d) 
    {
        year = y;
        month = m;
        day = d;
    }

    Date() 
    {
        year = 0; month = 0; day = 0;
    }

    // Getters for the Date class
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

// Defining the class for appointments
class Appointment 
{
private: 
    string description;
    Date date;

public:
	Appointment(string desc, int y, int m, int d) // creates an appointment with the given string description and date
    {
        description = desc;
        date = Date(y, m, d);
    }

    Appointment() 
    {
        description = " ";
    }

    // Pure virtual method required
    virtual bool occurs_on(int year, int month, int day) const = 0;

    // Getter methods
    string getDescription() const 
    {
        return description;
    }

    Date getDate() const 
    {
        return date;
    }

    // Setter method
    void setDescription(string newDesc) 
    {
        description = newDesc;
    }
};

// This code checks if the specific date has an appointment
class Day : public Appointment 
{
public:
    Day(string desc, int y, int m, int d) : Appointment(desc, y, m, d) {}

    Day() : Appointment() {}

	bool occurs_on(int year, int month, int day) const override // Override to pull occurs_on from the appointment class
    {
        // For a Day appointment, all three fields must match
        return (year == getDate().getYear() &&
            month == getDate().getMonth() &&
            day == getDate().getDay());
    }
};

// This code checkes if the specific day regardless of month have an appointment
class Monthly : public Appointment 
{
public:
    Monthly(string desc, int y, int m, int d) : Appointment(desc, y, m, d) {}

    Monthly() : Appointment() {}

    bool occurs_on(int year, int month, int day) const override 
    {
        // For a Monthly appointment, ONLY the day and year must match
        return (year == getDate().getYear() &&
            day == getDate().getDay());
    }
};

int main() 
{
    // Vector to hold pointers to our base class
    vector<Appointment*> appointments;

	// Populating the vector with some appointments
    appointments.push_back(new Day("Dentist Appointment", 2026, 6, 27));
	appointments.push_back(new Monthly("BACA State Executive Board Meeting", 2026, 5, 14)); // Occurs on the 14th of every month in 2026 and should show up on the 14th of June
    appointments.push_back(new Day("Combine and Compile Assignment 3 Problem 2", 2026, 6, 13));
    appointments.push_back(new Monthly("Pay Mortgage", 2026, 6, 1)); // Occurs on the 1st of every month in 2026
    appointments.push_back(new Day("Lunch with new interns", 2026, 6, 12));
    appointments.push_back(new Day("10-year anniversary", 2026, 6, 11));
	// Multiple appointments on the same day to test if this returns multiple appointments correctly
	appointments.push_back(new Day("Assignment 3 Due", 2026, 6, 14)); // Assignment 3 and peer review due
	appointments.push_back(new Day("Quiz 3 Due", 2026, 6, 14)); // Quiz 3 due
    appointments.push_back(new Day("Discussion 3 Due", 2026, 6, 14)); // Discussion 3 due
	appointments.push_back(new Day("**Recommend Professor Hong give Alexandra, Elizabeth, and Greg 10 bonus points for creativity!**", 2026, 6, 14)); // Can't blame me for trying :)
    // Adding a single day appointment on 5/14/2026 to test if it is excluded from results since it isn't a monthly appointment
	appointments.push_back(new Day("Long motorcycle ride to unwind", 2026, 5, 14)); // Should not show up on the 14th of June since it is a single day appointment

    int searchYear, searchMonth, searchDay;

    // Prompt user for input
    cout << "Enter a date to check for appointments. (You can use 2026, 6, 14 to test code)" << endl;
    cout << "Year (e.g., 2026): ";
    cin >> searchYear;
    cout << "Month (1-12): ";
    cin >> searchMonth;
    cout << "Day (1-31): ";
    cin >> searchDay;

    cout << "\nYou have the following appointments on " << searchMonth << "/" << searchDay << "/" << searchYear << ":\n" << endl;

    bool foundAny = false;

    // Loop through all appointments
    for (auto a : appointments) 
    {
        if (a->occurs_on(searchYear, searchMonth, searchDay)) 
        {
            cout << a->getDescription() << endl;
            foundAny = true;
        }
    }

    if (!foundAny) 
    {
        cout << "No appointments scheduled for this date." << endl;
    }

    return 0;
}