# Employee Payroll System
### A C++ Demonstration of Inheritance, Polymorphism, and Virtual Functions

---

## Overview

This program models a simple payroll system using object-oriented programming (OOP) in C++. It demonstrates three foundational OOP concepts — **inheritance**, **virtual functions**, and **polymorphism** — through a class hierarchy of employee types. The program calculates and prints pay stubs for hourly and salaried employees.

---

## Files

```
employee_payroll.cpp    # Single-file source containing all class definitions and main()
```

---

## Class Hierarchy

```
Employee                  (Base Class)
├── HourlyEmployee        (Derived Class — adds department, overrides printPayStub)
└── SalariedEmployee      (Derived Class — overrides calcWage for flat salary)
```

---

## Class Descriptions

### `Employee` (Base Class)

The `Employee` class defines the shared interface and default behavior for all employee types.

| Member | Type | Description |
|---|---|---|
| `name` | `string` (protected) | Employee's name |
| `hours` | `double` (protected) | Hours worked |
| `rate` | `double` (protected) | Hourly rate or salary amount |
| `calcWage()` | `virtual` method | Calculates pay using overtime formula: **40 hrs × rate + (hours − 40) × rate × 1.5** |
| `printPayStub()` | non-virtual method | Prints name, hours, rate, and salary to console |

> **Note:** `calcWage()` is declared `virtual`, enabling derived classes to substitute their own wage logic at runtime. `printPayStub()` is **not** virtual, which has important consequences for how it is called through base class pointers (see [Key Concepts](#key-concepts)).

---

### `HourlyEmployee` (Derived from `Employee`)

Represents an employee paid by the hour, belonging to a specific department.

| Member | Type | Description |
|---|---|---|
| `departmentName` | `string` (private) | The employee's assigned department |
| `HourlyEmployee(n, h, r, d)` | Constructor | Initializes name, hours, rate, and department |
| `printPayStub()` | Override | Prints department name, then delegates to `Employee::printPayStub()` |

- Uses the **inherited** `calcWage()` from `Employee` (overtime formula applies).
- The overridden `printPayStub()` only takes effect when called on a **concrete `HourlyEmployee` variable** — not through an `Employee*` pointer, because `printPayStub` is non-virtual.

---

### `SalariedEmployee` (Derived from `Employee`)

Represents an employee on a fixed salary, regardless of hours worked.

| Member | Type | Description |
|---|---|---|
| `SalariedEmployee(n, r)` | Constructor | Sets name, rate (as flat salary), and hours = 40 |
| `calcWage()` | `override` | Returns `rate` directly — no hourly calculation |

- Hours are set to 40 as a placeholder, but they have no effect on the wage.
- The `override` keyword signals to the compiler that this function is intentionally replacing a virtual function in the base class; the compiler will raise an error if no matching virtual function exists.

---

## Sample Output

```
Name : John
Hours: 43
Rate: 34.98
Salary: 1554.411

Name : Smith
Hours: 40
Rate: 5000
Salary: 5000

Deparment: Sales
Name : Kevin
Hours: 43
Rate: 34.98
Salary: 1554.411
```

> **Observation:** Notice that `emp1` (John) does **not** print a department line, even though it is a `HourlyEmployee`. `emp3` (Kevin) does. See below for why.

---

## Key Concepts

### 1. Virtual Functions and Dynamic Dispatch

A function declared `virtual` in the base class tells C++ to determine *which version to call* at **runtime**, based on the actual type of the object — not the declared type of the pointer. This is called **dynamic dispatch**.

`calcWage()` is virtual. So when `printPayStub()` calls `calcWage()` internally, C++ looks up the correct version for each object:
- `HourlyEmployee` objects use `Employee::calcWage()` (inherited overtime formula).
- `SalariedEmployee` objects use `SalariedEmployee::calcWage()` (flat salary).

### 2. Non-Virtual Functions and Static Binding

A function that is **not** declared `virtual` is resolved at **compile time** based on the *declared type* of the pointer or variable — not the runtime object. This is called **static binding**.

`printPayStub()` is non-virtual. Both `emp1` and `emp2` are declared as `Employee*`, so the compiler always calls `Employee::printPayStub()` for them — even though `emp1` holds a `HourlyEmployee` object that has its own version of `printPayStub()`.

### 3. Why the Three Outputs Differ

| Object | Declared Type | Actual Type | `printPayStub()` Called | Department Printed? |
|---|---|---|---|---|
| `emp1` | `Employee*` | `HourlyEmployee` | `Employee::printPayStub()` | ❌ No |
| `emp2` | `Employee*` | `SalariedEmployee` | `Employee::printPayStub()` | ❌ No |
| `emp3` | `HourlyEmployee` | `HourlyEmployee` | `HourlyEmployee::printPayStub()` | ✅ Yes |

`emp3` is declared directly as a `HourlyEmployee` variable (not a pointer to `Employee`), so the compiler knows its exact type at compile time and calls the overridden `printPayStub()` — which prints the department line before delegating to the base class version.

---

## How to Compile and Run

**Requirements:** A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`)

```bash
# Compile
g++ -std=c++11 employee_payroll.cpp -o employee_payroll

# Run
./employee_payroll
```

---

## Concepts Covered

- Class inheritance (`public` inheritance)
- `protected` access modifier for shared member variables
- `virtual` functions and runtime polymorphism
- `override` keyword for safe function overriding
- Static vs. dynamic binding
- Base class pointers holding derived class objects
- Explicit base class method calls (`Employee::printPayStub()`)
