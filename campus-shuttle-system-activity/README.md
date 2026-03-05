# 🚌 FAMU Campus Shuttle System

**Course:** COP 3330 – Introduction to Object-Oriented Programming  
**Topic:** Inheritance & Method Overriding

---

## About This Project

This project models a small fleet of campus vehicles for FAMU's transportation office. It is designed to demonstrate core object-oriented principles — specifically **inheritance** and **method overriding** — through a practical, campus-familiar scenario.

The program defines a base `Vehicle` class that captures the attributes and behaviors common to all campus vehicles, then extends it through three derived classes: `CampusShuttle`, `GolfCart`, and `MaintenanceTruck`. Each derived class inherits the shared foundation of `Vehicle` while introducing its own unique data members and overriding shared methods to reflect behavior specific to that vehicle type.

---

## Class Hierarchy

```
Vehicle                    ← base class
├── CampusShuttle          ← adds: routeName, maxCapacity
├── GolfCart               ← adds: departmentName, maxSpeed
└── MaintenanceTruck       ← adds: cargoDescription, cargoWeight
```

All three derived classes inherit `make`, `model`, and `fuelLevel` from `Vehicle`, along with its `describe()` and `refuel()` methods. Each class then overrides those methods as needed to produce output and behavior appropriate to that vehicle type.

---

## Repository Contents

| File | Description |
|---|---|
| `INSTRUCTIONS.md` | Activity prompt — read this first |
| `Vehicle.h` / `Vehicle.cpp` | Base class for all campus vehicles |
| `CampusShuttle.h` / `CampusShuttle.cpp` | Derived class representing a passenger shuttle |
| `GolfCart.h` / `GolfCart.cpp` | Derived class representing a department golf cart |
| `MaintenanceTruck.h` / `MaintenanceTruck.cpp` | Derived class representing a cargo/maintenance truck |
| `driver.cpp` | `main()` — instantiates one object of each type and exercises all methods |

---

## Activity Instructions

See `INSTRUCTIONS.md` for the full scenario, task breakdown, and reflection question.
