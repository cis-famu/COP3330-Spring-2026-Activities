# Introduction to Classes in C++
## Building a Student Organization Class

---

## Scenario: Managing Your Campus Organization

Imagine you're the president of your university's Student Government Association (SGA). This semester has been incredibly busy—you're coordinating Homecoming activities with 12 different organizations, planning the annual MLK Day of Service with over 200 volunteers, organizing the Spring Career Fair with 40+ companies, and managing your executive board of 15 officers. On top of that, you're trying to track a $50,000 annual budget across multiple initiatives.

You've been tracking everything in different places: member contact info in your phone, committee assignments in a Google Doc, event budgets in random notebooks, and RSVPs in various group chats. It's becoming chaotic, especially with Homecoming just two months away. You think, "There has to be a better way to organize all this information about our organizations and events."

This is exactly the problem that ***classes*** in programming help solve. A class is like a blueprint or template for organizing related information and actions. Just as your SGA has certain characteristics (name, number of members, budget, event schedule) and can perform certain actions (hold meetings, plan events, allocate funds, recruit members), a class in C++ lets you define both the *data* (characteristics) and *functions* (actions) that belong together.

---

## Learning Objectives

By the end of this activity, you will be able to:

• Understand what a class is and why it's useful
• Identify the components of a class (member variables and member functions)
• Write a basic class definition in C++
• Create and use objects (instances) of a class
• Understand access specifiers (public and private)

---

## Part 1: Understanding Classes and Objects

### What is a Class?

A **class** is a user-defined data type that groups together related data and functions. Think of it as a blueprint or template. Just as an architect creates a blueprint for a house, you create a class as a blueprint for organizing information.

An **object** is a specific instance created from that class. Using our house analogy, if the class is the blueprint, then each actual house built from that blueprint is an object. You can create many houses (objects) from one blueprint (class), and each house can have different characteristics (like different paint colors or furniture) even though they all follow the same basic design.

**Example:** If 'StudentOrganization' is our class (the blueprint), then the specific organizations like 'SGA,' 'NPHC (National Pan-Hellenic Council),' 'Campus Activities Board,' and 'Pre-Law Society' would each be objects (instances) created from that class.

### Key Components of a Class

A class typically contains two main components:

1. **Member Variables (Data Members):** These are the characteristics or attributes of the class. For a StudentOrganization, this might include the organization's name, number of members, or budget.

2. **Member Functions (Methods):** These are the actions or behaviors the class can perform. For a StudentOrganization, this might include functions to add members, plan events, or display information.

---

## Part 2: Building Our StudentOrganization Class

### Step 1: Class Declaration

Let's start by creating a basic class structure. In C++, we use the keyword `class` followed by the class name:

```cpp
class StudentOrganization {
    // Class contents will go here
};
```

**Important notes:**
• Class names typically start with a capital letter
• The class definition ends with a semicolon (;)
• Everything between the curly braces { } belongs to the class

### Step 2: Adding Member Variables

Now let's think about what information we need to track for a student organization. 

**Your Task:** Before looking at the example below, brainstorm what data you would want to store about a student organization. Write down at least 3-5 pieces of information.

Here's a starting point with three basic member variables:

```cpp
class StudentOrganization {
private:
    string organizationName;
    int numberOfMembers;
    double annualBudget;
};
```

**Understanding Access Specifiers:**

The `private:` keyword is called an *access specifier*. It means that these variables can only be accessed from within the class itself—not from outside code. This is a key concept in *encapsulation*, which helps protect our data from accidental misuse.

Think of it like your organization's financial records: you wouldn't want just anyone to be able to change your budget numbers. By making these private, we ensure they can only be modified through specific functions we create.

### Step 3: Adding a Constructor

A **constructor** is a special function that runs automatically when you create an object. It's used to set up the initial values of your member variables. The constructor has the same name as the class and no return type.

**Your Task:** Write a constructor for the StudentOrganization class that takes three parameters: name, members, and budget. Inside the constructor, assign these parameters to the corresponding member variables.

**Hints:**
- The constructor should be in the `public:` section (so it can be called from outside the class)
- The constructor syntax is: `ClassName(parameters) { // initialization code }`
- Use the assignment operator (=) to set member variables

Try writing it yourself before checking the example below:

<details>
<summary>Click to see an example constructor</summary>

```cpp
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
};
```
</details>

### Step 4: Adding Member Functions

Now comes the fun part—deciding what actions your class should be able to perform!

**Your Design Challenge:** 

Before implementing anything, design at least **four member functions** that would be useful for managing a student organization. For each function, write:

1. The function name
2. What parameters it needs (if any)
3. What it should do
4. What it should return (if anything)

**Example format:**
```
Function: displayInfo
Parameters: none
Purpose: Prints out the organization's name, member count, and budget
Returns: nothing (void)
```

**Here are some ideas to get you thinking:**
- How would you show information about the organization?
- How would you add new members?
- How would you track events or meetings?
- How would you update the budget?
- How would you calculate something (like budget per member)?

After you've designed your functions, implement at least two of them. Here's one example to get you started:

```cpp
void displayInfo() {
    cout << "Organization: " << organizationName << endl;
    cout << "Members: " << numberOfMembers << endl;
    cout << "Annual Budget: $" << annualBudget << endl;
}
```

Now implement your other functions!

---

## Part 3: Using Your Class (Creating Objects)

Now that you've defined your class, let's see how to actually use it!

### Creating Objects

To create an object, you use this syntax:
```cpp
ClassName objectName(constructor arguments);
```

**Example:**
```cpp
StudentOrganization sga("Student Government Association", 15, 50000.00);
```

This creates an object named `sga` with the specified initial values.

### Calling Member Functions

You use the **dot operator** (.) to call member functions on an object:

```cpp
sga.displayInfo();  // Calls the displayInfo function on the sga object
```

### Your Complete Program

Now put it all together! Write a complete C++ program that:

1. Includes the necessary headers (`<iostream>`, `<string>`)
2. Contains your complete StudentOrganization class definition
3. Has a `main()` function that:
   - Creates at least two StudentOrganization objects for different campus organizations
   - Calls various member functions on these objects
   - Demonstrates the functionality you've implemented

**Starter template:**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Your StudentOrganization class goes here

int main() {
    // Create your objects here
    
    // Use your objects here
    
    return 0;
}
```

---

## Part 4: Extended Challenges

Ready to take your class to the next level? Try these challenges:

### Challenge 1: Add More Member Variables

Add at least two new private member variables to track additional information. Consider adding:
- `string presidentName` - who leads the organization
- `int yearFounded` - when it was established  
- `string meetingDay` - when the organization meets
- `int numberOfEvents` - how many events held this year

**Remember:** You'll need to update your constructor to initialize these new variables!

### Challenge 2: Implement a Budget Management System

Create member functions to:
- Spend money from the budget (with validation to prevent overspending)
- Add funds to the budget
- Calculate the budget per member
- Check if the organization can afford a specific event

### Challenge 3: Member Management

Create member functions to:
- Add new members (updating the count)
- Remove members (with validation to prevent negative counts)
- Calculate what percentage of the target membership has been reached
- Display whether the organization is "growing," "stable," or "declining" based on changes

### Challenge 4: Event Planning

Add functionality to:
- Store a count of planned events
- Add a new event (increment counter)
- Calculate events per member
- Display a message about the organization's activity level

### Challenge 5: Create a Related Class

Think about other aspects of HBCU campus life that could be modeled with classes. Design and implement a new class such as:
- `Course` (with properties like name, professor, credits, enrollment)
- `HomecomingEvent` (with properties like name, date, attendees, location, committee)
- `GreekOrganization` (with properties like chapter name, founding year, members, colors)
- `StepShowTeam` (with properties like team name, members, practice schedule, competitions won)
- `CareerFairCompany` (with properties like company name, positions available, contact person)
- `CommunityServiceProject` (with properties like project name, volunteers needed, hours completed)

---

## Reflection Questions

Take a moment to think about and discuss these questions:

1. **Why is it useful to make member variables private instead of public?** Think about what could go wrong if anyone could directly change your organization's budget or member count.

2. **What's the difference between a class and an object?** Can you think of another real-world analogy besides the blueprint/house example?

3. **What other classes might be useful to create for managing aspects of HBCU campus life?** Consider academics, homecoming planning, Greek life, community service initiatives, alumni relations, etc.

4. **How does organizing information into classes make programs easier to understand and maintain?** What would your code look like if you just used individual variables for everything?

5. **What challenges did you face when designing your member functions?** How did you decide what functions to include?

6. **How could multiple objects of the same class interact with each other?** For example, how might two student organizations collaborate on an event?

---

## Key Takeaways

✓ A **class** is a blueprint for creating objects that groups related data and functions together

✓ **Member variables** store the characteristics or state of an object

✓ **Member functions** define the behaviors or actions an object can perform

✓ **Access specifiers** (`private` and `public`) control who can access different parts of your class

✓ **Constructors** initialize objects when they are created

✓ Classes help organize code, make it more maintainable, and model real-world entities effectively

✓ You can create multiple objects from one class, each with its own data

---

## Next Steps

Congratulations on creating your first C++ class! As you continue learning object-oriented programming, you'll discover more advanced concepts like:

• **Inheritance** - creating new classes based on existing ones
• **Polymorphism** - objects taking multiple forms  
• **Operator overloading** - defining how operators work with your classes
• **Templates** - creating generic classes that work with different data types

Keep practicing by creating classes to model different aspects of your life and interests. The more you practice, the more natural object-oriented thinking will become!

---

## Submission Checklist

When you're ready to submit your work, make sure you have:

- [ ] A complete StudentOrganization class with at least 3 member variables
- [ ] A working constructor
- [ ] At least 4 member functions that you designed and implemented
- [ ] A main() function that creates and uses at least 2 objects
- [ ] Comments explaining what your code does
- [ ] Answers to at least 3 of the reflection questions
- [ ] At least one completed challenge (optional but recommended)

**Pro tip:** Test your code thoroughly! Try creating objects with different values and calling your functions in different orders to make sure everything works as expected.
