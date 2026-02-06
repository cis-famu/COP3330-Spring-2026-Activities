# C++ Class Activity - Code Solutions

This folder contains two C++ solution files for the Student Organization class activity.

[Original Question](CPP_Class_Activity.md)

## Files Included

### 1. StudentOrganization_Basic.cpp
**What it contains:**
- The minimal StudentOrganization class as introduced in the activity
- 3 basic member variables: organizationName, numberOfMembers, annualBudget
- Constructor to initialize the organization
- 3 basic member functions:
  - `displayInfo()` - Shows organization details
  - `addMembers()` - Adds new members
  - `updateBudget()` - Updates the budget
- Simple main() function demonstrating object creation and usage

**Use this file for:**
- Understanding the basic structure of a C++ class
- Learning how to create and use objects
- Starting point before attempting the challenges

---

### 2. StudentOrganization_Complete.cpp
**What it contains:**
- Full implementation including all challenges (except Challenge 5)
- 7 member variables including extended data from Challenge 1:
  - organizationName, numberOfMembers, annualBudget
  - presidentName, yearFounded, meetingDay, numberOfEvents
  
- **Challenge 1 - Additional Variables & Functions:**
  - Extended constructor with more parameters
  - Updated displayInfo() function
  - `planEvent()` function for event planning

- **Challenge 2 - Budget Management:**
  - `spendMoney()` - Spend from budget with validation
  - `addFunds()` - Add money to budget
  - `getBudgetPerMember()` - Calculate per-member budget
  - `canAffordEvent()` - Check if an event is affordable
  - `displayBudgetSummary()` - Show budget breakdown

- **Challenge 3 - Member Management:**
  - `removeMembers()` - Remove members with validation
  - `displayGrowthStatus()` - Analyze membership growth
  - `hasReachedTarget()` - Check if membership target is met

- **Challenge 4 - Event Planning:**
  - `addEvent()` - Track events (increment counter)
  - `getEventsPerMember()` - Calculate events per member ratio
  - `displayActivityLevel()` - Assess organization activity

**Use this file for:**
- Seeing a complete implementation with error handling
- Understanding input validation
- Learning how to add multiple related functions
- Reference for implementing your own challenges

---

## How to Compile and Run

### Using g++ (Linux/Mac/Windows with MinGW):
```bash
# For the basic version:
g++ StudentOrganization_Basic.cpp -o basic
./basic

# For the complete version:
g++ StudentOrganization_Complete.cpp -o complete
./complete
```

### Using an IDE:
1. Open the .cpp file in your IDE (Visual Studio, Code::Blocks, CLion, etc.)
2. Build and run the project
3. View output in the console

---

## Key Concepts Demonstrated

### Object-Oriented Programming:
- **Encapsulation**: Private member variables protected from direct access
- **Abstraction**: Complex operations hidden behind simple function calls
- **Class vs Object**: Blueprint (class) vs instances (objects)

### C++ Features:
- Constructors for initialization
- Member functions (methods)
- Access specifiers (public/private)
- Function overloading concepts
- Input validation
- Type casting (static_cast)

### Programming Best Practices:
- Input validation (checking for negative numbers, overflow, etc.)
- Error messages that guide the user
- Clear, descriptive function and variable names
- Helpful output messages
- Organized, readable code structure

---

## Learning Path

1. **Start with Basic**: 
   - Compile and run StudentOrganization_Basic.cpp
   - Understand each line of code
   - Try modifying values in main()
   - Add your own organization objects

2. **Study Complete**:
   - Compare to the basic version
   - Identify what each challenge adds
   - Notice the validation patterns
   - See how functions build on each other

3. **Create Your Own**:
   - Start with the basic template
   - Implement one challenge at a time
   - Test thoroughly after each addition
   - Add your own creative functions

---

## Extension Ideas

Once you understand these solutions, try:
- Adding a member roster (using arrays or vectors)
- Creating officer positions with different roles
- Implementing a meeting scheduler
- Building a budget category system
- Creating relationships between organizations (collaborations)

---

## HBCU Context

These examples use Student Government Association (SGA) and Campus Activities Board (CAB) as the primary examples, reflecting typical HBCU campus organizations. The complete version includes features relevant to HBCU campus life:
- Homecoming coordination
- Step show planning
- MLK Day of Service
- Career fair management
- Campus events on the yard

Feel free to modify the examples to match organizations at your specific institution!

---

## Questions or Issues?

If you encounter compiler errors:
1. Ensure you're using C++11 or later
2. Check that all semicolons are in place
3. Verify matching brackets and parentheses
4. Make sure string header is included

Common mistakes to watch for:
- Forgetting semicolon after class definition
- Missing return type on functions
- Not matching parameter types
- Accessing private variables from outside the class
