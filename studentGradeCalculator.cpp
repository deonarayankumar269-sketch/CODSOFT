#include <iostream>
using namespace std;

int main()
{
    int subjects;
    float marks, totalMarks = 0, average;
    char grade;

    cout << "===== STUDENT GRADE CALCULATOR =====\n";

    // Input number of subjects
    cout << "Enter number of subjects: ";
    cin >> subjects;

    // Input marks for each subject
    for(int i = 1; i <= subjects; i++)
    {
        cout << "Enter marks for Subject " << i << " (out of 100): ";
        cin >> marks;

        // Validation
        while(marks < 0 || marks > 100)
        {
            cout << "Invalid marks! Enter marks between 0 and 100: ";
            cin >> marks;
        }

        totalMarks += marks;
    }

    // Calculate average percentage
    average = totalMarks / subjects;

    // Grade calculation
    if(average >= 90)
        grade = 'A';
    else if(average >= 80)
        grade = 'B';
    else if(average >= 70)
        grade = 'C';
    else if(average >= 60)
        grade = 'D';
    else if(average >= 50)
        grade = 'E';
    else
        grade = 'F';

    // Display results
    cout << "\n===== RESULT =====\n";
    cout << "Total Marks = " << totalMarks << endl;
    cout << "Average Percentage = " << average << "%" << endl;
    cout << "Grade = " << grade << endl;

    // Grade message
    if(grade == 'A')
        cout << "Excellent Performance!" << endl;
    else if(grade == 'B')
        cout << "Very Good!" << endl;
    else if(grade == 'C')
        cout << "Good Job!" << endl;
    else if(grade == 'D')
        cout << "Average Performance!" << endl;
    else if(grade == 'E')
        cout << "Needs Improvement!" << endl;
    else
        cout << "Failed!" << endl;

    return 0;
}