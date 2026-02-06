#include <iostream>
#include <string>
using namespace std;

class StudentOrganization {
private:
    // Basic member variables
    string organizationName;
    int numberOfMembers;
    double annualBudget;
    
    // Extended member variables (Challenge 1)
    string presidentName;
    int yearFounded;
    string meetingDay;
    int numberOfEvents;

public:
    // Constructor with all parameters
    StudentOrganization(string name, int members, double budget, 
                       string president, int year, string meeting) {
        organizationName = name;
        numberOfMembers = members;
        annualBudget = budget;
        presidentName = president;
        yearFounded = year;
        meetingDay = meeting;
        numberOfEvents = 0;  // Start with 0 events
    }
    
    // Basic display function (updated for new variables)
    void displayInfo() {
        cout << "\n========================================" << endl;
        cout << "Organization: " << organizationName << endl;
        cout << "President: " << presidentName << endl;
        cout << "Members: " << numberOfMembers << endl;
        cout << "Annual Budget: $" << annualBudget << endl;
        cout << "Year Founded: " << yearFounded << endl;
        cout << "Meeting Day: " << meetingDay << endl;
        cout << "Events This Year: " << numberOfEvents << endl;
        cout << "========================================" << endl;
    }
    
    // Basic member management
    void addMembers(int newMembers) {
        if (newMembers > 0) {
            numberOfMembers += newMembers;
            cout << "Added " << newMembers << " new members!" << endl;
            cout << "Total members: " << numberOfMembers << endl;
        } else {
            cout << "Error: Cannot add negative members!" << endl;
        }
    }
    
    // Challenge 3: Remove members with validation
    void removeMembers(int membersLeaving) {
        if (membersLeaving < 0) {
            cout << "Error: Cannot remove negative members!" << endl;
        } else if (membersLeaving > numberOfMembers) {
            cout << "Error: Cannot remove more members than you have!" << endl;
            cout << "Current members: " << numberOfMembers << endl;
        } else {
            numberOfMembers -= membersLeaving;
            cout << "Removed " << membersLeaving << " members." << endl;
            cout << "Remaining members: " << numberOfMembers << endl;
        }
    }
    
    // Challenge 3: Calculate growth status
    void displayGrowthStatus(int previousMemberCount) {
        int change = numberOfMembers - previousMemberCount;
        double percentChange = (static_cast<double>(change) / previousMemberCount) * 100;
        
        cout << "\n--- Growth Analysis ---" << endl;
        cout << "Previous members: " << previousMemberCount << endl;
        cout << "Current members: " << numberOfMembers << endl;
        cout << "Change: " << change << " members (" << percentChange << "%)" << endl;
        
        if (change > 0) {
            cout << "Status: GROWING ✓" << endl;
        } else if (change < 0) {
            cout << "Status: DECLINING" << endl;
        } else {
            cout << "Status: STABLE" << endl;
        }
    }
    
    // Challenge 3: Check membership target
    bool hasReachedTarget(int targetMembers) {
        double percentReached = (static_cast<double>(numberOfMembers) / targetMembers) * 100;
        
        cout << "\n--- Target Progress ---" << endl;
        cout << "Current members: " << numberOfMembers << endl;
        cout << "Target: " << targetMembers << endl;
        cout << "Progress: " << percentReached << "%" << endl;
        
        if (numberOfMembers >= targetMembers) {
            cout << "TARGET REACHED! 🎉" << endl;
            return true;
        } else {
            cout << "Members needed: " << (targetMembers - numberOfMembers) << endl;
            return false;
        }
    }
    
    // Basic budget update
    void updateBudget(double newBudget) {
        annualBudget = newBudget;
        cout << "Budget updated to $" << annualBudget << endl;
    }
    
    // Challenge 2: Spend money with validation
    void spendMoney(double amount) {
        if (amount < 0) {
            cout << "Error: Cannot spend negative amount!" << endl;
        } else if (amount > annualBudget) {
            cout << "Error: Insufficient funds!" << endl;
            cout << "Available budget: $" << annualBudget << endl;
            cout << "Requested amount: $" << amount << endl;
        } else {
            annualBudget -= amount;
            cout << "Spent $" << amount << endl;
            cout << "Remaining budget: $" << annualBudget << endl;
        }
    }
    
    // Challenge 2: Add funds
    void addFunds(double amount) {
        if (amount > 0) {
            annualBudget += amount;
            cout << "Added $" << amount << " to budget" << endl;
            cout << "New budget: $" << annualBudget << endl;
        } else {
            cout << "Error: Cannot add negative funds!" << endl;
        }
    }
    
    // Challenge 2: Calculate budget per member
    double getBudgetPerMember() {
        if (numberOfMembers > 0) {
            return annualBudget / numberOfMembers;
        }
        return 0.0;
    }
    
    // Challenge 2: Check if event is affordable
    bool canAffordEvent(double eventCost) {
        cout << "\n--- Budget Check ---" << endl;
        cout << "Event cost: $" << eventCost << endl;
        cout << "Available budget: $" << annualBudget << endl;
        
        if (eventCost <= annualBudget) {
            cout << "Status: AFFORDABLE ✓" << endl;
            cout << "Remaining after event: $" << (annualBudget - eventCost) << endl;
            return true;
        } else {
            cout << "Status: CANNOT AFFORD" << endl;
            cout << "Additional funds needed: $" << (eventCost - annualBudget) << endl;
            return false;
        }
    }
    
    // Challenge 1: Plan an event
    void planEvent(string eventName) {
        cout << "\n=== Planning Event: " << eventName << " ===" << endl;
        cout << "Organization: " << organizationName << endl;
        cout << "Available budget: $" << annualBudget << endl;
        cout << "Remember to:" << endl;
        cout << "  - Check if budget is sufficient" << endl;
        cout << "  - Confirm venue and date" << endl;
        cout << "  - Assign committee members" << endl;
        cout << "  - Promote to all " << numberOfMembers << " members" << endl;
    }
    
    // Challenge 4: Add event (increment counter)
    void addEvent(string eventName) {
        numberOfEvents++;
        cout << "\n✓ Event added: " << eventName << endl;
        cout << "Total events this year: " << numberOfEvents << endl;
    }
    
    // Challenge 4: Calculate events per member
    double getEventsPerMember() {
        if (numberOfMembers > 0) {
            return static_cast<double>(numberOfEvents) / numberOfMembers;
        }
        return 0.0;
    }
    
    // Challenge 4: Display activity level
    void displayActivityLevel() {
        double eventsPerMember = getEventsPerMember();
        
        cout << "\n--- Activity Analysis ---" << endl;
        cout << "Total events: " << numberOfEvents << endl;
        cout << "Total members: " << numberOfMembers << endl;
        cout << "Events per member: " << eventsPerMember << endl;
        
        if (eventsPerMember >= 0.5) {
            cout << "Activity level: HIGHLY ACTIVE 🔥" << endl;
        } else if (eventsPerMember >= 0.25) {
            cout << "Activity level: MODERATELY ACTIVE" << endl;
        } else if (eventsPerMember > 0) {
            cout << "Activity level: BUILDING MOMENTUM" << endl;
        } else {
            cout << "Activity level: JUST GETTING STARTED" << endl;
        }
    }
    
    // Utility function to display budget summary
    void displayBudgetSummary() {
        cout << "\n--- Budget Summary ---" << endl;
        cout << "Total budget: $" << annualBudget << endl;
        cout << "Budget per member: $" << getBudgetPerMember() << endl;
        if (numberOfEvents > 0) {
            cout << "Budget per event: $" << (annualBudget / numberOfEvents) << endl;
        }
    }
};

int main() {
    cout << "=====================================" << endl;
    cout << "   STUDENT ORGANIZATION MANAGER" << endl;
    cout << "=====================================" << endl;
    
    // Create organization objects with extended parameters
    StudentOrganization sga("Student Government Association", 15, 50000.00,
                           "Marcus Johnson", 1925, "Tuesday");
    
    StudentOrganization cab("Campus Activities Board", 25, 15000.00,
                           "Ayanna Williams", 1998, "Thursday");
    
    // Display initial information
    cout << "\n===== INITIAL ORGANIZATION INFO =====" << endl;
    sga.displayInfo();
    cab.displayInfo();
    
    // Demonstrate SGA operations
    cout << "\n\n===== SGA OPERATIONS =====" << endl;
    
    // Member management
    cout << "\n--- Member Management ---" << endl;
    sga.addMembers(3);
    sga.displayGrowthStatus(15);
    sga.hasReachedTarget(20);
    
    // Budget operations
    cout << "\n--- Budget Management ---" << endl;
    sga.displayBudgetSummary();
    sga.canAffordEvent(8000.00);
    sga.spendMoney(8000.00);
    sga.addFunds(5000.00);
    
    // Event planning
    cout << "\n--- Event Planning ---" << endl;
    sga.planEvent("Homecoming Step Show");
    sga.addEvent("Homecoming Step Show");
    sga.addEvent("MLK Day of Service");
    sga.addEvent("Spring Career Fair");
    sga.displayActivityLevel();
    
    // Display final state
    cout << "\n--- Final SGA Status ---" << endl;
    sga.displayInfo();
    
    // Demonstrate CAB operations
    cout << "\n\n===== CAB OPERATIONS =====" << endl;
    
    cab.addMembers(5);
    cab.planEvent("Movie Night on the Yard");
    cab.canAffordEvent(2500.00);
    cab.spendMoney(2500.00);
    cab.addEvent("Movie Night on the Yard");
    cab.addEvent("Spring Concert");
    cab.displayActivityLevel();
    cab.displayInfo();
    
    // Test error handling
    cout << "\n\n===== ERROR HANDLING TESTS =====" << endl;
    sga.addMembers(-5);  // Should fail
    sga.removeMembers(100);  // Should fail
    sga.spendMoney(1000000.00);  // Should fail
    
    cout << "\n\n===== PROGRAM COMPLETE =====" << endl;
    
    return 0;
}
