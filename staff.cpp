// Program to keep records of all the staffs in an universties which includes their roles,salary and empID

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Staff
{
public:
    static int nextID;

protected:
    string name;
    int empID;
    double baseSal;

public:
    Staff();
    Staff(string, double);
    virtual vector<pair<string, string>> details() const;
};

class TeachingStaff : virtual public Staff
{

protected:
    int teachHr;
    int allowancePerHr;

private:
    double sal;

public:
    TeachingStaff();
    TeachingStaff(string, double, int, int);

    vector<pair<string, string>> details() const;
};

class AdminStaff : virtual public Staff
{

protected:
    int allowanceForAdmin;

private:
    double sal;

public:
    AdminStaff();
    AdminStaff(string, double, int);

    vector<pair<string, string>> details() const;
};

class ResearchStaff : virtual public Staff
{

protected:
    int projects;
    int allowancePerProject;

private:
    double sal;

public:
    ResearchStaff();
    ResearchStaff(string, double, int, int);
    vector<pair<string, string>> details() const;
};

class TeachingandResearchStaff : virtual public TeachingStaff, virtual public ResearchStaff
{
private:
    double sal;

public:
    TeachingandResearchStaff();
    TeachingandResearchStaff(string, double, int, int, int, int);
    vector<pair<string, string>> details() const override;
};

class TeachingAdminAndResearchStaff : public TeachingandResearchStaff, public AdminStaff
{
private:
    double sal;

public:
    TeachingAdminAndResearchStaff();
    TeachingAdminAndResearchStaff(string, double, int, int, int, int, int);
    vector<pair<string, string>> details() const override;
};

int int_check(int);
int double_check(double);

int main()
{
    Staff *sptr = NULL;
    vector<Staff *> Staffs;
    string name;
    double baseSal;
    int teachHr, allowancePerHr, projects, allowancePerProject, allowanceForAdmin, choice = 0;
    while (choice != 7)
    {
        cout << endl
             << "+---------------+" << endl
             << "|     MENU      |" << endl
             << "+---------------+" << endl;
        cout << "1.Add Teaching Staff" << endl;
        cout << "2.Add Research Staff" << endl;
        cout << "3.Add Admin Staff" << endl;
        cout << "4.Add Teaching and Research Staff" << endl;
        cout << "5.Add Admin Teaching and Research Staff" << endl;
        cout << "6.Display all Staffs" << endl;
        cout << "7.Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter Staff Name: ";
            cin >> name;
            cout << "Enter Staff Basic Salary: ";
            cin >> baseSal;
            while (double_check(baseSal) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> baseSal;
            }
            cout << "Enter Staff Teaching Hour: ";
            cin >> teachHr;
            while (int_check(teachHr) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> teachHr;
            }
            cout << "Enter Allowance Per Hour: ";
            cin >> allowancePerHr;
            while (int_check(allowancePerHr) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> allowancePerHr;
            }

            sptr = new TeachingStaff(name, baseSal, teachHr, allowancePerHr);
            Staffs.push_back(sptr);
            cout << "\nStaff Successfully Added." << endl;
            sptr = NULL;
            break;
        }
        case 2:
        {
            cout << "Enter Staff Name: ";
            cin >> name;
            cout << "Enter Staff Basic Salary: ";
            cin >> baseSal;
            while (double_check(baseSal) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> baseSal;
            }
            cout << "Enter Number of Projects: ";
            cin >> projects;
            while (int_check(projects) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> projects;
            }
            cout << "Enter Allowance Per Project: ";
            cin >> allowancePerProject;
            while (int_check(allowancePerProject) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> allowancePerProject;
            }

            sptr = new ResearchStaff(name, baseSal, projects, allowancePerProject);
            Staffs.push_back(sptr);
            cout << "\nStaff Successfully Added." << endl;
            sptr = NULL;
            break;
        }
        case 3:
        {
            cout << "Enter Staff Name: ";
            cin >> name;
            cout << "Enter Staff Basic Salary: ";
            cin >> baseSal;
            while (double_check(baseSal) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> baseSal;
            }
            cout << "Enter Admin Allowance: ";
            cin >> allowanceForAdmin;
            while (int_check(allowanceForAdmin) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> allowanceForAdmin;
            }

            sptr = new AdminStaff(name, baseSal, allowanceForAdmin);
            Staffs.push_back(sptr);
            cout << "\nStaff Successfully Added." << endl;
            sptr = NULL;
            break;
        }
        case 4:
        {
            cout << "Enter Staff Name: ";
            cin >> name;
            cout << "Enter Staff Basic Salary: ";
            cin >> baseSal;
            while (double_check(baseSal) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> baseSal;
            }
            cout << "Enter Teaching Hours: ";
            cin >> teachHr;
            while (int_check(teachHr) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> teachHr;
            }
            cout << "Enter Allowance Per Hour: ";
            cin >> allowancePerHr;
            while (int_check(allowancePerHr) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> allowancePerHr;
            }
            cout << "Enter Number of Projects: ";
            cin >> projects;
            while (int_check(projects) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> projects;
            }
            cout << "Enter Allowance Per Project: ";
            cin >> allowancePerProject;
            while (int_check(allowancePerProject) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> allowancePerProject;
            }

            sptr = new TeachingandResearchStaff(name, baseSal, teachHr, allowancePerHr, projects, allowancePerProject);
            Staffs.push_back(sptr);
            cout << "\nStaff Successfully Added." << endl;
            sptr = NULL;
            break;
        }
        case 5:
        {
            cout << "Enter Staff Name: ";
            cin >> name;
            cout << "Enter Staff Basic Salary: ";
            cin >> baseSal;
            while (double_check(baseSal) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> baseSal;
            }
            cout << "Enter Teaching Hours: ";
            cin >> teachHr;
            while (int_check(teachHr) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> teachHr;
            }
            cout << "Enter Allowance Per Hour: ";
            cin >> allowancePerHr;
            while (int_check(allowancePerHr) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> allowancePerHr;
            }
            cout << "Enter Number of Projects: ";
            cin >> projects;
            while (int_check(projects) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> projects;
            }
            cout << "Enter Allowance Per Project: ";
            cin >> allowancePerProject;
            while (int_check(allowancePerProject) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> allowancePerProject;
            }
            cout << "Enter Admin Allowance: ";
            cin >> allowanceForAdmin;
            while (int_check(allowanceForAdmin) == 0)
            {
                cout << "Please Enter a valid value: ";
                cin >> allowanceForAdmin;
            }

            sptr = new TeachingAdminAndResearchStaff(name, baseSal, teachHr, allowancePerHr, projects, allowancePerProject, allowanceForAdmin);
            Staffs.push_back(sptr);
            cout << "\nStaff Successfully Added." << endl;
            sptr = NULL;
            break;
        }
        case 6:
        {
            if (Staffs.size() == 0)
            {
                cout << "No Staffs Added" << endl;
                break;
            }
            for (Staff *s : Staffs)
            {
                vector<pair<string, string>> d = s->details();
                for (auto i : d)
                {
                    cout << i.first << ": " << i.second << endl;
                }
                cout << "-----------------------" << endl;
            }
            break;
        }
        case 7:
            cout << "\nExiting.." << endl;
            break;
        default:
            cout << "\nPlease Enter a valid choice." << endl;
        }
    }
    return 0;
}

// Setting Value for nextID
int Staff::nextID = 1000;

// Constructor for Staff Class without arguments
Staff::Staff()
{
    this->empID = Staff::nextID;
    nextID++;
}

// Constructor for Staff class with arguments
Staff::Staff(string name, double baseSal) : name(name), baseSal(baseSal)
{
    this->empID = Staff::nextID;
    nextID++;
}

// This function will return the details of the Staff as a vector of pairs.The pair look like this : <Attribute>,<value>
vector<pair<string, string>> Staff::details() const
{
    return {
        {"ID", to_string(this->empID)},
        {"Name", this->name},
        {"Basic Salary", to_string(baseSal)}};
}

// Constructor for TeachingStaff Class without parameters
TeachingStaff::TeachingStaff() : teachHr(0), allowancePerHr(0) {}

// Constructor for TeachingStaff Class with parameters
TeachingStaff::TeachingStaff(string name, double baseSal, int teachHr, int allowancePerHr)
{
    this->baseSal = baseSal;
    this->name = name;
    this->teachHr = teachHr;
    this->allowancePerHr = allowancePerHr;
    this->sal = this->baseSal + (this->teachHr) * (this->allowancePerHr);
}

// This function will return the details of the Teaching Staff
vector<pair<string, string>> TeachingStaff::details() const
{
    vector<pair<string, string>> details = Staff::details();
    details.push_back({"Role", "Teacher"});
    details.push_back({"Total Salary", to_string(sal)});
    return details;
}

// Constructor for AdminStaff Class without parameters
AdminStaff::AdminStaff() : allowanceForAdmin(0) {}

// Constructor for AdminStaff Class with parameters
AdminStaff::AdminStaff(string name, double baseSal, int allowanceForAdmin)
{
    this->name = name;
    this->baseSal = baseSal;
    this->allowanceForAdmin = allowanceForAdmin;
    this->sal = this->baseSal + this->allowanceForAdmin;
}

// This function will return the details of the Admin Staff
vector<pair<string, string>> AdminStaff::details() const
{
    vector<pair<string, string>> details = Staff::details();
    details.push_back({"Role", "Admin"});
    details.push_back({"Total Salary", to_string(sal)});
    return details;
}

// Constructor for ResearchStaff Class without parameters
ResearchStaff::ResearchStaff() : projects(0), allowancePerProject(0) {}

// Constructor for ResearchStaff Class with parameters
ResearchStaff::ResearchStaff(string name, double baseSal, int projects, int allowancePerProject)
{
    this->name = name;
    this->baseSal = baseSal;
    this->projects = projects;
    this->allowancePerProject = allowancePerProject;
    this->sal = this->baseSal + (this->projects) * (this->allowancePerProject);
}

// This function will return the details of the Researching Staff
vector<pair<string, string>> ResearchStaff::details() const
{
    vector<pair<string, string>> details = Staff::details();
    details.push_back({"Role", "Researcher"});
    details.push_back({"Total Salary", to_string(sal)});
    return details;
}

// Constructor for Teaching and Research Staff without arguments
TeachingandResearchStaff::TeachingandResearchStaff() : sal(0) {}

// Constructor for Teaching and Research Staff with arguments
TeachingandResearchStaff::TeachingandResearchStaff(string name, double baseSal, int teachHr, int allowancePerHr, int projects, int allowancePerProject)
    : Staff(name, baseSal)
{
    this->teachHr = teachHr;
    this->allowancePerHr = allowancePerHr;
    this->projects = projects;
    this->allowancePerProject = allowancePerProject;
    this->sal = this->baseSal + (this->teachHr) * (this->allowancePerHr) + (this->projects) * (this->allowancePerProject);
}

// This function will return the details of the Teaching and Research Staff
vector<pair<string, string>> TeachingandResearchStaff::details() const
{
    vector<pair<string, string>> details = Staff::details();
    details.push_back({"Role", "Teacher and Researcher"});
    details.push_back({"Total Salary", to_string(sal)});
    return details;
}

// Constructor for Admin,Teaching and Research Staff without arguments
TeachingAdminAndResearchStaff::TeachingAdminAndResearchStaff() : sal(0) {}

// Constructor for Admin,Teaching and Research Staff with arguments
TeachingAdminAndResearchStaff::TeachingAdminAndResearchStaff(string name, double baseSal, int teachHr, int allowancePerHr, int projects, int allowancePerProject, int allowanceForAdmin)
    : Staff(name, baseSal)
{
    this->allowanceForAdmin = allowanceForAdmin;
    this->teachHr = teachHr;
    this->allowancePerHr = allowancePerHr;
    this->projects = projects;
    this->allowancePerProject = allowancePerProject;
    this->sal = this->baseSal + (this->teachHr) * (this->allowancePerHr) + (this->projects) * (this->allowancePerProject) + this->allowanceForAdmin;
}

// This function will return the details of the Admin, Teaching and Research Staff
vector<pair<string, string>> TeachingAdminAndResearchStaff::details() const
{
    vector<pair<string, string>> details = Staff::details();
    details.push_back({"Role", "Teacher, Researcher and Admin"});
    details.push_back({"Total Salary", to_string(sal)});
    return details;
}

// This function returns 1 if the entered value is positive and 0 if entered value is negative
int int_check(int n)
{
    if (n < 0)
        return 0;
    return 1;
}

// This function returns 1 if the entered value is positive and 0 if entered value is negative
int double_check(double n)
{
    if (n < 0)
        return 0;
    return 1;
}