#include <iostream>
#include <cmath>

using namespace std;

// Calculating system reliability with the given number of copies
double calculateSystemReliability(double R, int m)
{
    return 1 - pow(1 - R, m);
}

int main()
{
    double C1, R1, C2, R2, C;
    int u1, u2;

    cout << "\nEnter the cost of device 1 (C1): ";
    cin >> C1;
    cout << "Enter the reliability of device 1 (R1): ";
    cin >> R1;

    cout << "\nEnter the cost of device 2 (C2): ";
    cin >> C2;
    cout << "Enter the reliability of device 2 (R2): ";
    cin >> R2;

    cout << "\nEnter the total available cost (C): ";
    cin >> C;

    // Calculating max no. of copies for 2 devices
    u1 = (C + C1 - (C1 + C2)) / C1;
    u2 = (C + C2 - (C1 + C2)) / C2;

    double bestReliability = 0.0, bestCost = 0.0;
    int bestM1 = 0, bestM2 = 0;

    for (int m1 = 1; m1 <= u1; m1++)
    {
        for (int m2 = 1; m2 <= u2; m2++)
        {
            double totalCost = m1 * C1 + m2 * C2;
            if (totalCost <= C)
            {
                double currentReliability = calculateSystemReliability(R1, m1) * calculateSystemReliability(R2, m2);
                if (currentReliability > bestReliability)
                {
                    bestReliability = currentReliability;
                    bestM1 = m1;
                    bestM2 = m2;
                    bestCost = totalCost;
                }
            }
        }
    }

    cout << "\n\nThe best design has a reliability of " << bestReliability << endl;
    cout << "\nTotal cost for the best design is " << bestCost << endl;
    cout << "\nTracing back for the solution, we can determine that m1=" << bestM1 << " and m2=" << bestM2 << "\n\n";

    return 0;
}
