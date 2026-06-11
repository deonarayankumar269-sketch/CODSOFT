#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    string grade;

    Student() {}

    Student(int r, string n, string g)
    {
        rollNo = r;
        name = n;
        grade = g;
    }
};

class StudentManagementSystem
{
private:
    vector<Student> students;

public:

    // Load data from file
    void loadFromFile()
    {
        ifstream file("students.txt");

        if(file.is_open())
        {
            Student s;

            while(file >> s.rollNo)
            {
                file.ignore();
                getline(file, s.name);
                getline(file, s.grade);

                students.push_back(s);
            }

            file.close();
        }
    }

    // Save data to file
    void saveToFile()
    {
        ofstream file("students.txt");

        for(Student s : students)
        {
            file << s.rollNo << endl;
            file << s.name << endl;
            file << s.grade << endl;
        }

        file.close();
    }

    // Add Student
    void addStudent()
    {
        int roll;
        string name, grade;

        cout << "\nEnter Roll Number: ";
        cin >> roll;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        while(name.empty())
        {
            cout << "Name cannot be empty.\n";
            cout << "Enter Name: ";
            getline(cin, name);
        }

        cout << "Enter Grade: ";
        getline(cin, grade);

        students.push_back(Student(roll, name, grade));

        saveToFile();

        cout << "\nStudent Added Successfully!\n";
    }

    // Display all students
    void displayStudents()
    {
        if(students.empty())
        {
            cout << "\nNo Student Records Found.\n";
            return;
        }

        cout << "\n===== STUDENT RECORDS =====\n";

        for(Student s : students)
        {
            cout << "\nRoll Number: " << s.rollNo;
            cout << "\nName: " << s.name;
            cout << "\nGrade: " << s.grade;
            cout << "\n----------------------";
        }
    }

    // Search student
    void searchStudent()
    {
        int roll;

        cout << "\nEnter Roll Number to Search: ";
        cin >> roll;

        for(Student s : students)
        {
            if(s.rollNo == roll)
            {
                cout << "\nStudent Found:";
                cout << "\nRoll Number: " << s.rollNo;
                cout << "\nName: " << s.name;
                cout << "\nGrade: " << s.grade;
                return;
            }
        }

        cout << "\nStudent Not Found.\n";
    }

    // Remove student
    void removeStudent()
    {
        int roll;

        cout << "\nEnter Roll Number to Remove: ";
        cin >> roll;

        for(int i = 0; i < students.size(); i++)
        {
            if(students[i].rollNo == roll)
            {
                students.erase(students.begin() + i);

                saveToFile();

                cout << "\nStudent Removed Successfully!\n";
                return;
            }
        }

        cout << "\nStudent Not Found.\n";
    }

    // Edit student
    void editStudent()
    {
        int roll;

        cout << "\nEnter Roll Number to Edit: ";
        cin >> roll;

        cin.ignore();

        for(int i = 0; i < students.size(); i++)
        {
            if(students[i].rollNo == roll)
            {
                cout << "Enter New Name: ";
                getline(cin, students[i].name);

                cout << "Enter New Grade: ";
                getline(cin, students[i].grade);

                saveToFile();

                cout << "\nStudent Updated Successfully!\n";
                return;
            }
        }

        cout << "\nStudent Not Found.\n";
    }
};

int main()
{
    StudentManagementSystem sms;

    sms.loadFromFile();

    int choice;

    do
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Edit Student";
        cout << "\n5. Remove Student";
        cout << "\n6. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                sms.addStudent();
                break;

            case 2:
                sms.displayStudents();
                break;

            case 3:
                sms.searchStudent();
                break;

            case 4:
                sms.editStudent();
                break;

            case 5:
                sms.removeStudent();
                break;

            case 6:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 6);

    return 0;
}