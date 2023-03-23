#include <iostream>
using namespace std;

class Employee
{
protected:
    string Surname;
    string Forename;

    int Birth_year;
    int Birth_month;
    int Birth_day;

    int total_hoilday;

    int holiday_taken;
    int remain_hoilday;

public:
    // used to count the total number of employees, cannot exceed 500.
    static int e_number;
    // every employee has an unique ID, used to search employee, cannot be reused after deleting an employee.
    static int e_id;
    int ID;

    void taking_hoilday()
    {
        // employee older than 50 have totally 32 days of hoilday, otherwise only 30 days.
        if (2021 - Birth_year > 50)
            total_hoilday = 32;
        else
            total_hoilday = 30;

        cout << "Your total hoilday is " << total_hoilday << " days, and you have " << remain_hoilday << " days remained. " << endl
             << "how many days do you want to take this time? Please enter an integer: " << endl;
        int h_number;
        cin >> h_number;

        // cannot take more days than the remained days.
        if (remain_hoilday >= h_number)
        {
            holiday_taken += h_number;
            remain_hoilday = total_hoilday - holiday_taken;
            cout << "this time you are going to take " << h_number << " days, and you have " << remain_hoilday << " days remained." << endl;
        }
        else
            cout << "You cannot exceed your total days of hoilday!!!" << endl;
    }
};

class HourlyEmployee : public Employee
{
private:
    float Hourly_wage;
    int Hours_worked;

public:
    ~HourlyEmployee() { cout << "The object of HourlyEmployee is deleted." << endl; };

    void Creating()
    {
        // only can create when the total number of employees <= 500.
        if (e_number <= 500)
        {
            // input all the data to create an hourly employee.
            cout << "Please enter the forename: " << endl;
            cin >> Forename;
            cout << "Please enter the surname: " << endl;
            cin >> Surname;
            cout << "Please enter the year of birth: " << endl;
            cin >> Birth_year;
            cout << "Please enter the month of birth: " << endl;
            cin >> Birth_month;
            cout << "Please enter the day of birth: " << endl;
            cin >> Birth_day;
            cout << "Please enter the hourly wage: " << endl;
            cin >> Hourly_wage;
            cout << "Please enter the hours worked: " << endl;
            cin >> Hours_worked;
            ID = e_id + 1;

            if (2021 - Birth_year > 50)
                remain_hoilday = 32, total_hoilday = 32;
            else
                remain_hoilday = 30, total_hoilday = 30;
            holiday_taken = 0;

            cout << "You have created an hourly employee, " << Forename << " " << Surname << ";" << endl
                 << "His/Her employee ID is " << ID << ";" << endl;

            e_id++;
            e_number++;
        }
        else
        {
            cout << "You cannot enter more than 500 employees!" << endl;
        }
    }

    void display()
    {
        cout << "Employee_ID: " << ID << ", Name: " << Forename << " " << Surname << ", Birthday: " << Birth_day << "/" << Birth_month << "/" << Birth_year << endl
             << "Position: hourly employee, Hourly wage: " << Hourly_wage << ", Hours worked: " << Hours_worked << endl
             << "Total days of hoildays: " << total_hoilday << ", Remained days of hoilday: " << remain_hoilday << endl
             << endl;
    }
};

class SalariedEmployee : public Employee
{
private:
    float Annual_salary;

public:
    ~SalariedEmployee() { cout << "The object of SalariedEmployee is deleted." << endl; };

    void Creating()
    {
        if (e_number <= 500)
        {
            cout << "Please enter the forename: " << endl;
            cin >> Forename;
            cout << "Please enter the surname: " << endl;
            cin >> Surname;
            cout << "Please enter the year of birth: " << endl;
            cin >> Birth_year;
            cout << "Please enter the month of birth: " << endl;
            cin >> Birth_month;
            cout << "Please enter the day of birth: " << endl;
            cin >> Birth_day;
            cout << "Please enter the annual salary: " << endl;
            cin >> Annual_salary;
            ID = e_id + 1;

            if (2021 - Birth_year > 50)
                remain_hoilday = 32, total_hoilday = 32;
            else
                remain_hoilday = 30, total_hoilday = 30;
            holiday_taken = 0;

            cout << "You have created a salaried employee, " << Forename << " " << Surname << ";" << endl
                 << "His/Her employee ID is " << ID << ";" << endl;

            e_id++;
            e_number++;
        }

        else
            cout << "You cannot enter more than 500 employees!" << endl;
    }

    void display()
    {
        cout << "Employee_ID: " << ID << ", Name: " << Forename << " " << Surname << ", Birthday: " << Birth_day << "/" << Birth_month << "/" << Birth_year << endl
             << "Position: salaried employee, Annual salary: " << Annual_salary << endl
             << "Total days of hoildays: " << total_hoilday << ", Remained days of hoilday: " << remain_hoilday << endl
             << endl;
    }
};

class Manager : public Employee
{
private:
    float Profit_sharing;

public:
    ~Manager() { cout << "The object of Manager is deleted." << endl; };

    void Creating()
    {
        if (e_number <= 500)
        {
            cout << "Please enter the forename: " << endl;
            cin >> Forename;
            cout << "Please enter the surname: " << endl;
            cin >> Surname;
            cout << "Please enter the year of birth: " << endl;
            cin >> Birth_year;
            cout << "Please enter the month of birth: " << endl;
            cin >> Birth_month;
            cout << "Please enter the day of birth: " << endl;
            cin >> Birth_day;
            cout << "Please enter the profit sharing: " << endl;
            cin >> Profit_sharing;
            ID = e_id + 1;

            if (2021 - Birth_year > 50)
                remain_hoilday = 32, total_hoilday = 32;
            else
                remain_hoilday = 30, total_hoilday = 30;
            holiday_taken = 0;

            cout << "You have created manager, " << Forename << " " << Surname << ";" << endl
                 << "His/Her employee ID is " << ID << ";" << endl;

            e_id++;
            e_number++;
        }

        else
            cout << "You cannot enter more than 500 employees!" << endl;
    }

    void display()
    {
        cout << "Employee_ID: " << ID << ", Name: " << Forename << " " << Surname << ", Birthday: " << Birth_day << "/" << Birth_month << "/" << Birth_year << endl
             << "Position: manager, Profit sharing: " << Profit_sharing << endl
             << "Total days of hoildays: " << total_hoilday << ", Remained days of hoilday: " << remain_hoilday << endl
             << endl;
    }
};

int Employee::e_number = 0;
int Employee::e_id = 0;

int main()
{
    // three arrays for three subclasses.
    HourlyEmployee he[500];
    SalariedEmployee se[500];
    Manager m[500];

    // the number of employees for three subclasses, initialized with 0.
    int he_number = 0;
    int se_number = 0;
    int m_number = 0;

    // a number used to continue or stop the program.
    int meun_number;

    do
    {
        // print out the menu.
        cout << "----------MENU-----------" << endl
             << endl;

        cout << "1. Creating employee" << endl;
        cout << "2. Deleting employee" << endl;
        cout << "3. Entering the number of days on which an employee wants to take a holiday" << endl;
        cout << "4. Search for an employee and output of his/her data and how many remaining days of holiday he/she has" << endl;
        cout << "5. Listing of all stored employee data" << endl
             << endl;

        cout << "What do you want to do? Please enter the menu number: " << endl;

        // a number to decide which function to use.
        int meun_number2;
        cin >> meun_number2;

        switch (meun_number2)
        {
        // function 1: creating employee
        case 1:
        {
            cout << "What kind of employee are you creating?" << endl
                 << "H. Hourly employee" << endl
                 << "S. Salaried employee" << endl
                 << "M. Manager" << endl
                 << endl;

            cout << "Please enter the meun letter: " << endl;

            // a character used to decide what kind of employee to create.
            char meun_letter;
            cin >> meun_letter;
            switch (meun_letter)
            {
            case 'H':
            {
                he[he_number].Creating();
                he_number++;
                break;
            }
            case 'S':
            {
                se[se_number].Creating();
                se_number++;
                break;
            }
            case 'M':
            {
                m[m_number].Creating();
                m_number++;
                break;
            }
            default:
            {
                cout << "Your input is WRONG!!!";
            }
            }
            break;
        }

        // function 2: deleting employee
        case 2:
        {
            // use the ID to delete an employee
            cout << "Who do you want to delete? Please enter the Employee_ID" << endl;
            int Search_ID, Delete_ID;
            cin >> Search_ID;

            // to find if this ID refers to an hourly employee
            int he_index;
            for (he_index = 0; he_index <= he_number; he_index++)
            {
                if (he[he_index].ID == Search_ID)
                {
                    // if this ID refers to an hourly employee, his/her information in the "he" array will be replaced and disappear.
                    for (he_index = he_index; he_index < he_number; he_index++)
                    {
                        he[he_index] = he[he_index + 1];
                    }
                    cout << "Employee (ID=" << Search_ID << ") is deleted." << endl;
                    Employee::e_number--;
                    he_number--;
                }
            }

            // to find if this ID refers to a salaried employee
            int se_index;
            for (se_index = 0; se_index <= se_number; se_index++)
            {
                // if this ID refers to a salaried employee, his/her information in the "se" array will be replaced and disappear.
                if (se[se_index].ID == Search_ID)
                {
                    for (se_index = se_index; se_index < se_number; se_index++)
                    {
                        se[se_index] = se[se_index + 1];
                    }
                    cout << "Employee (ID=" << Search_ID << ") is deleted." << endl;
                    Employee::e_number--;
                    se_number--;
                }
            }

            // to find if this ID refers to a manager
            int m_index;
            for (m_index = 0; m_index < m_number; m_index++)
            {
                // if this ID refers to a manager, his/her information in the "m" array will be replaced and disappear.
                if (m[m_index].ID == Search_ID)
                {
                    for (m_index = m_index; m_index < m_number; m_index++)
                    {
                        m[m_index] = m[m_index + 1];
                    }
                    cout << "Employee (ID=" << Search_ID << ") is deleted." << endl;
                    Employee::e_number--;
                    m_number--;
                }
            }
            break;
        }

        // function 3: inputing the number of hoildays this time for an employee
        case 3:
        {
            // use the ID to target an employee
            cout << "Who wants to take a hoilday? Please enter the Employee_ID" << endl;
            int Search_ID;
            cin >> Search_ID;

            // to find if this ID refers to an hourly employee, if yes, enter the numbers of hoildays.
            int he_index;
            for (he_index = 0; he_index < he_number; he_index++)
            {
                if (he[he_index].ID == Search_ID)
                {
                    he[he_index].taking_hoilday();
                }
            }

            // to find if this ID refers to an salaried employee, if yes, enter the numbers of hoildays.
            int se_index;
            for (se_index = 0; se_index < se_number; se_index++)
            {
                if (se[se_index].ID == Search_ID)
                {
                    se[se_index].taking_hoilday();
                }
            }

            // to find if this ID refers to a manager, if yes, enter the numbers of hoildays.
            int m_index;
            for (m_index = 0; m_index < m_number; m_index++)
            {
                if (m[m_index].ID == Search_ID)
                {
                    m[m_index].taking_hoilday();
                }
            }
            break;
        }

        // function 4: searching an employee and outputing all the data.
        case 4:
        {
            // use the ID to search an employee
            cout << "Who do you want to search? Please enter the Employee_ID"
                 << "(if you don't know, please check the list of all stored employee data): " << endl;
            int Search_ID;
            cin >> Search_ID;

            // to find if this ID refers to an hourly employee, if yes, display his/her information in the "he" array.
            int he_index;
            for (he_index = 0; he_index < he_number; he_index++)
            {
                if (he[he_index].ID == Search_ID)
                {
                    he[he_index].display();
                }
            }

            // to find if this ID refers to a salaried employee, if yes, display his/her information in the "se" array.
            int se_index;
            for (se_index = 0; se_index < se_number; se_index++)
            {
                if (se[se_index].ID == Search_ID)
                {
                    se[se_index].display();
                }
            }

            // to find if this ID refers to a manager, if yes, display his/her information in the "m" array.
            int m_index = 0;
            for (m_index = 0; m_index < m_number; m_index++)
            {
                if (m[m_index].ID == Search_ID)
                {
                    m[m_index].display();
                }
            }
            break;
        }

        // function 5: listing of all stored employee data.
        case 5:
        {
            // use he_number, se_number and m_number to determine the range of the three arrays, and then display all the data in the arrays.
            int he_index, se_index, m_index;
            if (he_number > 0)
                for (he_index = 0; he_index < he_number; he_index++)
                    he[he_index].display();
            if (se_number > 0)
                for (se_index = 0; se_index < se_number; se_index++)
                    se[se_index].display();
            if (m_number > 0)
                for (m_index = 0; m_index < m_number; m_index++)
                    m[m_index].display();

            break;
        }

        // remind the user not to input wrong integer in the menu.
        default:
        {
            cout << "Your input is WRONG!!!";
        }
        }

        // ask the user to coninue the loop or not
        cout << endl
             << "Do you want to continue? If Yes please enter 1; if No please enter 0: " << endl;
        cin >> meun_number;

    } while (meun_number == 1);

    return 0;
}