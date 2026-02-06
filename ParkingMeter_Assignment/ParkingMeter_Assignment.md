# Programming Assignment 1: ParkingMeter Class

**Unit 3 – Custom Classes I**

**Course:** COP 3330 – Introduction to Object-Oriented Programming

**Evaluation:** Mastery-Based (Mastered / Not Yet Mastered)

---

## Purpose

The purpose of this assignment is to introduce you to the core mechanics of object-oriented programming (OOP) by designing and implementing your own custom C++ class. In earlier units, you wrote programs that used built-in data types. In this assignment, you will define a new data type that models a real-world concept and enforces rules about how it can be used.

This assignment focuses on:

- **Encapsulation:** protecting data and controlling access
- **Constructors:** ensuring objects start in a valid state
- **State and behavior:** defining what an object knows and what it can do

These skills are foundational for everything that follows in this course, including composition, inheritance, and polymorphism. Poor class design at this stage leads to fragile systems later—so the emphasis here is on intentional design, not just syntax.

---

## Task

You will design and implement a C++ class called `ParkingMeter` that models a coin-operated parking meter. Your class must manage its own internal state and enforce logical rules about payment, time allocation, and meter status.

You must complete all tasks below.

---

## Part 1: File Structure (Required)

Your submission must include all of the following files:

- `ParkingMeter.h`
- `ParkingMeter.cpp`
- `main.cpp`

**File responsibilities:**
- `ParkingMeter.h` contains the class declaration (interface)
- `ParkingMeter.cpp` contains the class implementation
- `main.cpp` demonstrates that your class works (this file must compile but is not graded by unit tests)

⚠️ **Submissions that do not separate interface and implementation will be marked Not Yet Mastered.**

---

## Part 2: Class Design Requirements

You must implement a class named `ParkingMeter` with the following **required private data members:**

| Data Member | Type | Purpose |
|-------------|------|---------|
| `meterID_` | `std::string` | Stores the unique meter identifier |
| `ratePerHour_` | `double` | Stores the cost per hour in dollars |
| `timeRemaining_` | `int` | Stores remaining minutes of paid time |
| `totalCollected_` | `double` | Stores total money collected by this meter |
| `isActive_` | `bool` | Tracks whether the meter is currently active |

**All data members must be private.**

---

## Part 3: Required Constructors

You must implement the following constructor:

```cpp
ParkingMeter(const std::string& meterID, double ratePerHour);
```

This constructor must:
- Initialize the meter ID and hourly rate
- Set time remaining to 0
- Set total collected to 0.0
- Set the meter as active (true)

You may include a default constructor if you choose, but it is **not required**.

---

## Part 4: Required Public Member Functions

Your class must include **all of the following public methods with exactly these signatures:**

```cpp
std::string getMeterID() const;
double getRatePerHour() const;
int getTimeRemaining() const;
double getTotalCollected() const;
bool isActive() const;

bool insertCoin(double amount);
bool addTime(int minutes);
void expire();
bool postPayment(double amount);
```

### Behavior Rules (Strictly Enforced)

#### `insertCoin(double amount)`
- Accepts only valid U.S. coin denominations: 0.05 (nickel), 0.10 (dime), 0.25 (quarter), 1.00 (dollar coin)
- Returns `false` for invalid amounts
- If valid, adds the amount to `totalCollected_`
- Calculates and adds corresponding time based on `ratePerHour_`
  - Formula: `minutes = (amount / ratePerHour_) * 60`
  - Round DOWN to nearest minute
- Automatically sets meter to active if it was expired
- Returns `true` for valid insertions

#### `addTime(int minutes)`
- Can only be called when meter is active
- Returns `false` if meter is not active
- Returns `false` if minutes is negative or zero
- If valid, adds minutes to `timeRemaining_`
- Returns `true` for valid additions

#### `expire()`
- Sets `timeRemaining_` to 0
- Sets `isActive_` to false
- This method has no return value (void)

#### `postPayment(double amount)`
- Used to reactivate an expired meter with a payment
- Returns `false` if amount is not positive
- Returns `false` if amount is less than the hourly rate
- If valid, adds amount to `totalCollected_`
- Calculates and sets `timeRemaining_` based on payment
- Sets meter to active
- Returns `true` for valid post-payments

⚠️ **Time calculation must be mathematically correct, using integer division where appropriate.**

---

## Part 5: Driver Program (main.cpp)

Your `main.cpp` file must:

- Create at least **two ParkingMeter objects**
- Demonstrate:
  - Inserting at least two valid coins
  - Attempting to insert an invalid coin
  - Adding time to an active meter
  - Expiring a meter
  - Reactivating an expired meter with post-payment
  - Retrieving and printing meter information

This file ensures your class works in practice, even though grading is done via automated tests.

---

## Part 6: AI Use (Allowed with Disclosure)

You may use AI tools to:
- Brainstorm class responsibilities
- Ask conceptual questions about constructors or encapsulation
- Debug compiler errors

You may **not**:
- Submit AI-generated code without understanding it
- Allow AI to make design decisions for you

**If AI is used, it must be documented in AI Log #2.**

---

## Criteria for Success (Mastery-Based)

### Mastered

To earn **Mastered**, your submission must:
- Compile with no errors
- Pass all automated GoogleTest unit tests
- Implement all required methods with correct behavior
- Use proper encapsulation (no public data members)
- Separate interface (.h) from implementation (.cpp)
- Demonstrate independent understanding through consistent design

### Not Yet Mastered

A submission will be marked **Not Yet Mastered** if any of the following occur:
- Code does not compile
- One or more required methods are missing or incorrect
- Encapsulation is violated
- Business rules are not enforced (e.g., invalid coins accepted)
- Automated tests fail

**Revisions are permitted according to the course token policy.**

---

## Why This Assignment Matters

Research in computer science education consistently shows that students struggle with OOP when classes are treated as syntax instead of conceptual models (Robins et al., 2003). This assignment slows the process down intentionally so you can build strong mental models of objects, responsibility, and state—skills that transfer directly to professional software development.

---

## Looking Ahead

In the next unit, you will:
- Separate class interfaces more formally
- Combine classes using composition
- Begin designing multi-object systems

The quality of your `ParkingMeter` class will directly affect your success moving forward.
