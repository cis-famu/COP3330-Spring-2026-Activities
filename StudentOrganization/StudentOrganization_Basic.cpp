#include <iostream>
#include <string>
using namespace std;

class StudentOrganization {
private:
    string organizationName;
    int numberOfMembers;
    double annualBudget;

public:
    // Constructor
    StudentOrganization(string name, int members, double budget) {
        organizationName = name;
        numberOfMembers = members;
        annualBudget = budget;
    }
    
    // Display organization information
    void displayInfo() {
        cout << "\nOrganization: " << organizationName << endl;
        cout << "Members: " << numberOfMembers << endl;
        cout << "Annual Budget: $" << annualBudget << endl;
    }
    
    // Add new members
    void addMembers(int newMembers) {
        numberOfMembers += newMembers;
        cout << "Added " << newMembers << " new members!" << endl;
    }
    
    // Update budget
    void updateBudget(double newBudget) {
        annualBudget = newBudget;
        cout << "Budget updated to $" << annualBudget << endl;
    }
};

int main() {
    // Creating objects (instances) of StudentOrganization
    StudentOrganization sga("Student Government Association", 15, 50000.00);
    StudentOrganization cab("Campus Activities Board", 25, 15000.00);
    
    // Using the objects
    cout << "===== Initial Information =====" << endl;
    sga.displayInfo();
    cab.displayInfo();
    
    // Modifying the SGA
    cout << "\n===== SGA Updates =====" << endl;
    sga.addMembers(3);
    sga.updateBudget(55000.00);
    sga.displayInfo();
    
    return 0;
}
