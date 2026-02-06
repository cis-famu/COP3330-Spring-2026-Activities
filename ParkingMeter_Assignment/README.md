# ParkingMeter Assignment Exemplar

## Overview

This is a **complete exemplar** that mirrors the **BookTracker** assignment in complexity, structure, and pedagogical approach, but covers a completely different domain (parking meters vs. books).

---

## Complexity Mapping

### BookTracker → ParkingMeter

| **BookTracker** | **ParkingMeter** | **Complexity Match** |
|-----------------|------------------|----------------------|
| `title_`, `author_` (strings) | `meterID_` (string), `ratePerHour_` (double) | Simple data storage |
| `isAvailable_` (bool) | `isActive_` (bool) | Binary state tracking |
| `averageRating_` (double) | `totalCollected_` (double) | Numeric accumulation |
| `reviewCount_` (int) | `timeRemaining_` (int) | Integer tracking |
| **Constructor** initializes to valid state | **Constructor** initializes to valid state | Same pattern |
| **checkout()/returnBook()** manage availability | **insertCoin()/expire()** manage meter state | State transitions |
| **addReview()** validates 1-5, updates running average | **insertCoin()** validates denominations, calculates time | Input validation + math |
| Running average calculation | Time-per-payment calculation | Mathematical logic |
| Can't checkout if already checked out | Can't add time if expired | State-based rules |
| Invalid reviews rejected | Invalid coins rejected | Business rule enforcement |

**Complexity Level:** Both assignments require students to:
- Manage 5 private data members
- Implement 8-9 public methods
- Enforce state-based business rules
- Perform mathematical calculations correctly
- Validate user input against specific criteria
- Maintain object independence

---

## File Structure

```
ParkingMeter_Assignment/
├── ParkingMeter_Assignment.md       # Main assignment document
├── AI_Log_Discussion.md             # Discussion board activity
│
├── answer_code/                     # CORRECT implementation
│   ├── ParkingMeter.h
│   ├── ParkingMeter.cpp
│   └── main.cpp
│
├── buggy_code/                      # INTENTIONALLY BUGGY for demos
│   ├── ParkingMeter.h
│   └── ParkingMeter.cpp
│
├── tests/
│   └── test_parking_meter.cpp       # GoogleTest suite with student-friendly messages
│
└── scripts/                         # Codio autograder scripts
    ├── install_gtest.sh
    ├── run_tests.sh
    └── grade.sh
```

---

## Key Pedagogical Features

### 1. **Encapsulation Practice**
- All data members private
- Public getters are const-correct
- State can only be modified through defined behaviors

### 2. **State Management**
- Meter can be active or expired
- Some operations only work when active
- State transitions are carefully controlled

### 3. **Input Validation**
- Coin denominations must match valid U.S. currency (0.05, 0.10, 0.25, 1.00)
- Time additions must be positive
- Post-payments must meet minimum threshold

### 4. **Mathematical Correctness**
- Time calculation: `(payment / hourly_rate) * 60`
- Must round DOWN (use integer division)
- Must accumulate money correctly

### 5. **Business Logic**
- Can't add time to expired meter without payment
- Post-payment must be at least one hour's rate
- Each meter maintains independent state

---

## Test Coverage

The GoogleTest suite includes 11 test cases covering:

✓ Constructor initialization
✓ Valid coin acceptance
✓ Invalid coin rejection
✓ Time and money accumulation
✓ addTime() behavior when active/inactive
✓ Invalid time values
✓ expire() state changes
✓ Post-payment reactivation
✓ Post-payment validation
✓ Object independence
✓ Realistic usage scenario

**Each test includes:**
- Clear SCOPED_TRACE labels for multi-step tests
- Student-friendly error messages explaining what went wrong
- Common mistake hints
- References to the formula or business rule being tested

---

## Common Student Mistakes (Intentionally Included in Buggy Code)

1. **Constructor Bug:** Starting meter as inactive instead of active
2. **Validation Bug:** Accepting any positive coin amount instead of valid denominations
3. **Math Bug:** Rounding up instead of down for time calculation
4. **State Bug:** Not checking if meter is active before adding time
5. **State Bug:** Not resetting time to 0 in expire()
6. **Validation Bug:** Not enforcing minimum payment in postPayment()
7. **Logic Bug:** Adding time instead of replacing in postPayment()

These mirror the types of mistakes students make with the BookTracker assignment.

---

## Grading Philosophy

### Mastery-Based (Binary)
- **Mastered:** All tests pass (100/100)
- **Not Yet Mastered:** Any test fails (<100/100)

This is consistent with specs grading and professional standards ("it works" vs. "it doesn't yet").

### Autograder Output
- Codio reports numeric score (0-100)
- Instructor can map to Mastered/NYM in Canvas
- Students see detailed feedback from test failures

---

## How to Use This Exemplar

### For Instructors:
1. **Adapt the assignment document** to your course calendar/policies
2. **Deploy to Codio:**
   - Upload test suite and scripts
   - Set autograder command: `bash scripts/grade.sh`
   - Mark scripts as executable
3. **Post discussion activity** to Canvas
4. **Use buggy code** in class to demonstrate common mistakes
5. **Use correct code** as reference for struggling students (after deadline)

### For Student Practice:
1. Read assignment carefully
2. Implement ParkingMeter class following specifications
3. Test locally or in Codio
4. Review test failures and fix bugs
5. Complete discussion activity comparing AI design to your design

---

## Learning Objectives Alignment

This assignment teaches:

**Conceptual Understanding:**
- Objects as stateful entities
- Encapsulation as information hiding
- Constructors as initialization contracts
- Methods as behaviors that respect object state

**Technical Skills:**
- Separating interface (.h) from implementation (.cpp)
- Writing const-correct getters
- Validating input before changing state
- Integer vs. floating-point arithmetic
- Boolean logic for state transitions

**Professional Practices:**
- Reading specifications carefully
- Testing incrementally
- Debugging systematically
- Comparing design alternatives
- Using AI as a tool, not an authority

---

## Differences from BookTracker

While complexity is equivalent, this assignment:

1. **Uses currency and time** instead of books and ratings
2. **Requires epsilon comparison** for floating-point coin validation
3. **Has more complex validation** (coin denominations vs. 1-5 rating scale)
4. **Uses replacement semantics** in postPayment() vs. accumulation in addReview()
5. **Models a physical system** vs. an information system

These differences ensure students can't simply copy BookTracker solutions.

---

## Extensions (Optional)

If you want to increase complexity:

- Add `refund()` method
- Track individual transactions (composition with Transaction class)
- Add `isExpired()` method that checks time <= 0
- Support multiple parking zones with different rates
- Add `toString()` method for formatted output
- Implement operator overloading (Unit 4+)

---

## Credits

This exemplar was created to match the BookTracker assignment in:
- Conceptual complexity
- Implementation difficulty  
- Testing rigor
- Pedagogical scaffolding
- Mastery-based evaluation

Designed for COP 3330 - Introduction to Object-Oriented Programming.
