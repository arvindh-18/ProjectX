#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Staff {
    protected:
        string name;
        string employeeID;
        double basicSalary;
    public:
        Staff(string name, string employeeID, double basicSalary);
        void setName(string name);
        void setEmployeeID(string id);
        void setBasicSalary(double salary);
        virtual void displayInfo() const;
        virtual double computeNetSalary() const;
        virtual ~Staff() {}
};

class TeachingStaff : virtual public Staff {
    protected:
        int teachingHoursPerWeek;
        double teachingAllowancePerHour;
    public:
        TeachingStaff(string name, string id, double basicSalary, int hours, double allowance);
        void setTeachingHours(int hours);
        void setTeachingAllowance(double allowance);
        virtual void displayInfo() const;
        virtual double computeNetSalary() const;
};

class ResearchStaff : virtual public Staff {
    protected:
        int numProjects;
        double researchGrantPerProject;
    public:
        ResearchStaff(string name, string id, double basicSalary, int projects, double grant);
        void setNumProjects(int projects);
        void setResearchGrant(double grant);
        virtual void displayInfo() const;
        virtual double computeNetSalary() const;
};

class AdministrativeStaff : virtual public Staff {
    protected:
        double adminAllowance;
        string adminRole;
    public:
        AdministrativeStaff(string name, string id, double basicSalary, double allowance, string role);
        void setAdminAllowance(double allowance);
        void setAdminRole(string role);
        virtual void displayInfo() const;
        virtual double computeNetSalary() const;
};

class TeachingResearchStaff : public TeachingStaff, public ResearchStaff {
    public:
        TeachingResearchStaff(string name, string id, double basicSalary,
                              int hours, double teachAllowance,
                              int projects, double grant);
        virtual void displayInfo() const;
        virtual double computeNetSalary() const;
};

class AdminTeachingResearchStaff : public TeachingResearchStaff, public AdministrativeStaff {
    public:
        AdminTeachingResearchStaff(string name, string id, double basicSalary,
                                   int hours, double teachAllowance,
                                   int projects, double grant,
                                   double adminAllow, string role);
        virtual void displayInfo() const;
        virtual double computeNetSalary() const;
};

vector<Staff*> staffList;

int main() {
    while (true) {
        int choice;
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Add Teaching Staff\n";
        cout << "2. Add Research Staff\n";
        cout << "3. Add Admin Staff\n";
        cout << "4. Add Teaching-Research Staff\n";
        cout << "5. Add Admin Teaching-Research Staff\n";
        cout << "6. Display All Staff\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            TeachingStaff* ts = nullptr;
            while (true) {
                int ch;
                cout << "\n----- Teaching Staff Menu -----\n";
                cout << "1. Input Staff Details\n";
                cout << "2. Display Staff Information\n";
                cout << "3. Display Net Salary\n";
                cout << "4. Modify Attributes\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> ch;
                if (ch == 1) {
                    string name, id;
                    double salary, allowance;
                    int hours;
                    cout << "Enter Name: "; cin >> name;
                    cout << "Enter Employee ID: "; cin >> id;
                    cout << "Enter Basic Salary: "; cin >> salary;
                    cout << "Enter Teaching Hours/Week: "; cin >> hours;
                    cout << "Enter Teaching Allowance/Hour: "; cin >> allowance;
                    ts = new TeachingStaff(name, id, salary, hours, allowance);
                    staffList.push_back(ts);
                    cout << "Teaching Staff added.\n";
                } else if (ch == 2) {
                    if (ts) ts->displayInfo();
                    else cout << "No staff entered yet.\n";
                } else if (ch == 3) {
                    if (ts) cout << "Net Salary: " << ts->computeNetSalary() << "\n";
                    else cout << "No staff entered yet.\n";
                } else if (ch == 4) {
                    if (!ts) { cout << "No staff entered yet.\n"; continue; }
                    int mod;
                    cout << "Modify: 1.Teaching Hours  2.Teaching Allowance\nChoice: ";
                    cin >> mod;
                    if (mod == 1) { int h; cout << "New hours: "; cin >> h; ts->setTeachingHours(h); }
                    else if (mod == 2) { double a; cout << "New allowance: "; cin >> a; ts->setTeachingAllowance(a); }
                } else if (ch == 5) {
                    break;
                } else {
                    cout << "Invalid Input, Enter Again\n";
                }
            }
        } else if (choice == 2) {
            ResearchStaff* rs = nullptr;
            while (true) {
                int ch;
                cout << "\n----- Research Staff Menu -----\n";
                cout << "1. Input Staff Details\n";
                cout << "2. Display Staff Information\n";
                cout << "3. Display Net Salary\n";
                cout << "4. Modify Attributes\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> ch;
                if (ch == 1) {
                    string name, id;
                    double salary, grant;
                    int projects;
                    cout << "Enter Name: "; cin >> name;
                    cout << "Enter Employee ID: "; cin >> id;
                    cout << "Enter Basic Salary: "; cin >> salary;
                    cout << "Enter Number of Projects: "; cin >> projects;
                    cout << "Enter Research Grant/Project: "; cin >> grant;
                    rs = new ResearchStaff(name, id, salary, projects, grant);
                    staffList.push_back(rs);
                    cout << "Research Staff added.\n";
                } else if (ch == 2) {
                    if (rs) rs->displayInfo();
                    else cout << "No staff entered yet.\n";
                } else if (ch == 3) {
                    if (rs) cout << "Net Salary: " << rs->computeNetSalary() << "\n";
                    else cout << "No staff entered yet.\n";
                } else if (ch == 4) {
                    if (!rs) { cout << "No staff entered yet.\n"; continue; }
                    int mod;
                    cout << "Modify: 1.Num Projects  2.Research Grant\nChoice: ";
                    cin >> mod;
                    if (mod == 1) { int p; cout << "New projects: "; cin >> p; rs->setNumProjects(p); }
                    else if (mod == 2) { double g; cout << "New grant: "; cin >> g; rs->setResearchGrant(g); }
                } else if (ch == 5) {
                    break;
                } else {
                    cout << "Invalid Input, Enter Again\n";
                }
            }
        } else if (choice == 3) {
            AdministrativeStaff* as = nullptr;
            while (true) {
                int ch;
                cout << "\n----- Admin Staff Menu -----\n";
                cout << "1. Input Staff Details\n";
                cout << "2. Display Staff Information\n";
                cout << "3. Display Net Salary\n";
                cout << "4. Modify Attributes\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> ch;
                if (ch == 1) {
                    string name, id, role;
                    double salary, allowance;
                    cout << "Enter Name: "; cin >> name;
                    cout << "Enter Employee ID: "; cin >> id;
                    cout << "Enter Basic Salary: "; cin >> salary;
                    cout << "Enter Admin Allowance: "; cin >> allowance;
                    cout << "Enter Admin Role: "; cin >> role;
                    as = new AdministrativeStaff(name, id, salary, allowance, role);
                    staffList.push_back(as);
                    cout << "Admin Staff added.\n";
                } else if (ch == 2) {
                    if (as) as->displayInfo();
                    else cout << "No staff entered yet.\n";
                } else if (ch == 3) {
                    if (as) cout << "Net Salary: " << as->computeNetSalary() << "\n";
                    else cout << "No staff entered yet.\n";
                } else if (ch == 4) {
                    if (!as) { cout << "No staff entered yet.\n"; continue; }
                    int mod;
                    cout << "Modify: 1.Admin Allowance  2.Admin Role\nChoice: ";
                    cin >> mod;
                    if (mod == 1) { double a; cout << "New allowance: "; cin >> a; as->setAdminAllowance(a); }
                    else if (mod == 2) { string r; cout << "New role: "; cin >> r; as->setAdminRole(r); }
                } else if (ch == 5) {
                    break;
                } else {
                    cout << "Invalid Input, Enter Again\n";
                }
            }
        } else if (choice == 4) {
            TeachingResearchStaff* trs = nullptr;
            while (true) {
                int ch;
                cout << "\n----- Teaching-Research Staff Menu -----\n";
                cout << "1. Input Staff Details\n";
                cout << "2. Display Staff Information\n";
                cout << "3. Display Net Salary\n";
                cout << "4. Modify Attributes\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> ch;
                if (ch == 1) {
                    string name, id;
                    double salary, allowance, grant;
                    int hours, projects;
                    cout << "Enter Name: "; cin >> name;
                    cout << "Enter Employee ID: "; cin >> id;
                    cout << "Enter Basic Salary: "; cin >> salary;
                    cout << "Enter Teaching Hours/Week: "; cin >> hours;
                    cout << "Enter Teaching Allowance/Hour: "; cin >> allowance;
                    cout << "Enter Number of Projects: "; cin >> projects;
                    cout << "Enter Research Grant/Project: "; cin >> grant;
                    trs = new TeachingResearchStaff(name, id, salary, hours, allowance, projects, grant);
                    staffList.push_back(trs);
                    cout << "Teaching-Research Staff added.\n";
                } else if (ch == 2) {
                    if (trs) trs->displayInfo();
                    else cout << "No staff entered yet.\n";
                } else if (ch == 3) {
                    if (trs) cout << "Net Salary: " << trs->computeNetSalary() << "\n";
                    else cout << "No staff entered yet.\n";
                } else if (ch == 4) {
                    if (!trs) { cout << "No staff entered yet.\n"; continue; }
                    int mod;
                    cout << "Modify: 1.Teaching Hours  2.Teaching Allowance  3.Num Projects  4.Research Grant\nChoice: ";
                    cin >> mod;
                    if (mod == 1) { int h; cout << "New hours: "; cin >> h; trs->setTeachingHours(h); }
                    else if (mod == 2) { double a; cout << "New allowance: "; cin >> a; trs->setTeachingAllowance(a); }
                    else if (mod == 3) { int p; cout << "New projects: "; cin >> p; trs->setNumProjects(p); }
                    else if (mod == 4) { double g; cout << "New grant: "; cin >> g; trs->setResearchGrant(g); }
                } else if (ch == 5) {
                    break;
                } else {
                    cout << "Invalid Input, Enter Again\n";
                }
            }
        } else if (choice == 5) {
            AdminTeachingResearchStaff* atrs = nullptr;
            while (true) {
                int ch;
                cout << "\n----- Admin Teaching-Research Staff Menu -----\n";
                cout << "1. Input Staff Details\n";
                cout << "2. Display Staff Information\n";
                cout << "3. Display Net Salary\n";
                cout << "4. Modify Attributes\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> ch;
                if (ch == 1) {
                    string name, id, role;
                    double salary, allowance, grant, adminAllow;
                    int hours, projects;
                    cout << "Enter Name: "; cin >> name;
                    cout << "Enter Employee ID: "; cin >> id;
                    cout << "Enter Basic Salary: "; cin >> salary;
                    cout << "Enter Teaching Hours/Week: "; cin >> hours;
                    cout << "Enter Teaching Allowance/Hour: "; cin >> allowance;
                    cout << "Enter Number of Projects: "; cin >> projects;
                    cout << "Enter Research Grant/Project: "; cin >> grant;
                    cout << "Enter Admin Allowance: "; cin >> adminAllow;
                    cout << "Enter Admin Role (e.g. HoD/Dean): "; cin >> role;
                    atrs = new AdminTeachingResearchStaff(name, id, salary, hours, allowance, projects, grant, adminAllow, role);
                    staffList.push_back(atrs);
                    cout << "Admin Teaching-Research Staff added.\n";
                } else if (ch == 2) {
                    if (atrs) atrs->displayInfo();
                    else cout << "No staff entered yet.\n";
                } else if (ch == 3) {
                    if (atrs) cout << "Net Salary: " << atrs->computeNetSalary() << "\n";
                    else cout << "No staff entered yet.\n";
                } else if (ch == 4) {
                    if (!atrs) { cout << "No staff entered yet.\n"; continue; }
                    int mod;
                    cout << "Modify: 1.Teaching Hours  2.Teaching Allowance  3.Num Projects  4.Research Grant  5.Admin Allowance  6.Admin Role\nChoice: ";
                    cin >> mod;
                    if (mod == 1) { int h; cout << "New hours: "; cin >> h; atrs->setTeachingHours(h); }
                    else if (mod == 2) { double a; cout << "New allowance: "; cin >> a; atrs->setTeachingAllowance(a); }
                    else if (mod == 3) { int p; cout << "New projects: "; cin >> p; atrs->setNumProjects(p); }
                    else if (mod == 4) { double g; cout << "New grant: "; cin >> g; atrs->setResearchGrant(g); }
                    else if (mod == 5) { double a; cout << "New admin allowance: "; cin >> a; atrs->setAdminAllowance(a); }
                    else if (mod == 6) { string r; cout << "New role: "; cin >> r; atrs->setAdminRole(r); }
                } else if (ch == 5) {
                    break;
                } else {
                    cout << "Invalid Input, Enter Again\n";
                }
            }
        } else if (choice == 6) {
            cout << "\n===== ALL STAFF =====\n";
            for (int i = 0; i < (int)staffList.size(); i++) {
                staffList[i]->displayInfo();
                cout << "Net Salary: " << staffList[i]->computeNetSalary() << "\n\n";
            }
        } else if (choice == 7) {
            cout << "Exiting...\n";
            for (int i = 0; i < (int)staffList.size(); i++) delete staffList[i];
            break;
        } else {
            cout << "Invalid Input, Enter Again\n";
        }
    }
    return 0;
}

Staff::Staff(string name, string employeeID, double basicSalary) {
    this->name = name;
    this->employeeID = employeeID;
    this->basicSalary = basicSalary;
}

void Staff::setName(string name)          { this->name = name; }
void Staff::setEmployeeID(string id)      { this->employeeID = id; }
void Staff::setBasicSalary(double salary) { this->basicSalary = salary; }

void Staff::displayInfo() const {
    cout << "Name: " << this->name
         << " | ID: " << this->employeeID
         << " | Basic Salary: " << this->basicSalary << "\n";
}

double Staff::computeNetSalary() const {
    return this->basicSalary;
}

TeachingStaff::TeachingStaff(string name, string id, double basicSalary, int hours, double allowance)
    : Staff(name, id, basicSalary) {
    this->teachingHoursPerWeek = hours;
    this->teachingAllowancePerHour = allowance;
}

void TeachingStaff::setTeachingHours(int hours)    { this->teachingHoursPerWeek = hours; }
void TeachingStaff::setTeachingAllowance(double a) { this->teachingAllowancePerHour = a; }

void TeachingStaff::displayInfo() const {
    Staff::displayInfo();
    cout << "  [Teaching] Hours/Week: " << this->teachingHoursPerWeek
         << " | Allowance/Hour: " << this->teachingAllowancePerHour << "\n";
}

double TeachingStaff::computeNetSalary() const {
    double deduction    = this->basicSalary * 0.10;
    double teachingComp = this->teachingHoursPerWeek * this->teachingAllowancePerHour * 4;
    return this->basicSalary - deduction + teachingComp;
}

ResearchStaff::ResearchStaff(string name, string id, double basicSalary, int projects, double grant)
    : Staff(name, id, basicSalary) {
    this->numProjects = projects;
    this->researchGrantPerProject = grant;
}

void ResearchStaff::setNumProjects(int p)      { this->numProjects = p; }
void ResearchStaff::setResearchGrant(double g) { this->researchGrantPerProject = g; }

void ResearchStaff::displayInfo() const {
    Staff::displayInfo();
    cout << "  [Research] Projects: " << this->numProjects
         << " | Grant/Project: " << this->researchGrantPerProject << "\n";
}

double ResearchStaff::computeNetSalary() const {
    double deduction     = this->basicSalary * 0.10;
    double researchBonus = this->numProjects * this->researchGrantPerProject * 0.15;
    return this->basicSalary - deduction + researchBonus;
}

AdministrativeStaff::AdministrativeStaff(string name, string id, double basicSalary, double allowance, string role)
    : Staff(name, id, basicSalary) {
    this->adminAllowance = allowance;
    this->adminRole = role;
}

void AdministrativeStaff::setAdminAllowance(double a) { this->adminAllowance = a; }
void AdministrativeStaff::setAdminRole(string role)   { this->adminRole = role; }

void AdministrativeStaff::displayInfo() const {
    Staff::displayInfo();
    cout << "  [Admin] Role: " << this->adminRole
         << " | Allowance: " << this->adminAllowance << "\n";
}

double AdministrativeStaff::computeNetSalary() const {
    double deduction = this->basicSalary * 0.10;
    return this->basicSalary - deduction + this->adminAllowance;
}

TeachingResearchStaff::TeachingResearchStaff(string name, string id, double basicSalary,
                                              int hours, double teachAllowance,
                                              int projects, double grant)
    : Staff(name, id, basicSalary),
      TeachingStaff(name, id, basicSalary, hours, teachAllowance),
      ResearchStaff(name, id, basicSalary, projects, grant) {}

void TeachingResearchStaff::displayInfo() const {
    Staff::displayInfo();
    cout << "  [Teaching] Hours/Week: " << this->teachingHoursPerWeek
         << " | Allowance/Hour: " << this->teachingAllowancePerHour << "\n";
    cout << "  [Research] Projects: " << this->numProjects
         << " | Grant/Project: " << this->researchGrantPerProject << "\n";
}

double TeachingResearchStaff::computeNetSalary() const {
    double deduction     = this->basicSalary * 0.10;
    double teachingComp  = this->teachingHoursPerWeek * this->teachingAllowancePerHour * 4;
    double researchBonus = this->numProjects * this->researchGrantPerProject * 0.15;
    return this->basicSalary - deduction + teachingComp + researchBonus;
}

AdminTeachingResearchStaff::AdminTeachingResearchStaff(string name, string id, double basicSalary,
                                                        int hours, double teachAllowance,
                                                        int projects, double grant,
                                                        double adminAllow, string role)
    : Staff(name, id, basicSalary),
      TeachingResearchStaff(name, id, basicSalary, hours, teachAllowance, projects, grant),
      AdministrativeStaff(name, id, basicSalary, adminAllow, role) {}

void AdminTeachingResearchStaff::displayInfo() const {
    Staff::displayInfo();
    cout << "  [Teaching] Hours/Week: " << this->teachingHoursPerWeek
         << " | Allowance/Hour: " << this->teachingAllowancePerHour << "\n";
    cout << "  [Research] Projects: " << this->numProjects
         << " | Grant/Project: " << this->researchGrantPerProject << "\n";
    cout << "  [Admin] Role: " << this->adminRole
         << " | Allowance: " << this->adminAllowance << "\n";
}

double AdminTeachingResearchStaff::computeNetSalary() const {
    double deduction     = this->basicSalary * 0.10;
    double teachingComp  = this->teachingHoursPerWeek * this->teachingAllowancePerHour * 4;
    double researchBonus = this->numProjects * this->researchGrantPerProject * 0.15;
    return this->basicSalary - deduction + teachingComp + researchBonus + this->adminAllowance;
}