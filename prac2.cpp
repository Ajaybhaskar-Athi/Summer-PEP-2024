#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Manually assigned values for testing
    int N = 5;  // Total tasks
    int n1 = 3; // Feature development developers
    int n2 = 3; // Bug fixing developers
    int n3 = 9; // Code review developers
    int d1 = 6; // Days for feature development per task
    int D = 30; // Allowed days to complete tasks

    // Calculate task completion rates for each team
    double feature_rate = static_cast<double>(n1) / d1;           // Feature team rate per day
    double bug_fixing_rate = static_cast<double>(n2) / (d1 + 2);  // Bug-fixing team rate per day
    double code_review_rate = static_cast<double>(n3) / (d1 - 2); // Code review team rate per day

    // Total rate of tasks completed per day by all teams
    double total_rate = feature_rate + bug_fixing_rate + code_review_rate;

    // Calculate the days needed to complete N tasks
    double days_needed = N / total_rate;
    int rounded_days_needed = ceil(days_needed); // Round up to the nearest integer for whole days

    // Check if tasks can be completed within D days
    if (rounded_days_needed <= D)
    {
        cout << "Yes " << rounded_days_needed << endl;
    }
    else
    {
        cout << "No " << rounded_days_needed - D << endl; // Output extra days required
    }

    return 0;
}
