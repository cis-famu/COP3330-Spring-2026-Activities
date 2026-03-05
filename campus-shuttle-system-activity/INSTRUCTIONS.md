# Class Activity: The FAMU Campus Shuttle System 🚌

**Course:** COP 3330 – Introduction to Object-Oriented Programming  
**Topic:** Inheritance & Method Overriding  
**Estimated Time:** 20–25 minutes  
**Group Size:** Individual or pairs

---

## The Scenario

FAMU's transportation office manages several types of vehicles that operate across campus. Every vehicle on the fleet shares some common characteristics — each one has a **make** (e.g., "Ford"), a **model** (e.g., "Transit"), and a **fuel level** stored as a percentage between 0 and 100. Every vehicle can also perform two general actions: it can `refuel()` and it can `describe()` itself.

However, not all vehicles behave the same way. Here is how each type works:

- A **Campus Shuttle** carries passengers across campus. It has a **route name** (e.g., "Blue Route") and a **passenger capacity**. When it describes itself, it should print its make, model, fuel level, route name, and capacity. When it refuels, it prints a message like: `"Shuttle on Blue Route refueled to 100%."` and sets the fuel level to 100.

- A **Golf Cart** is used by facilities staff to move around campus quickly. It has a **department name** it is assigned to (e.g., "Facilities Management") and a **max speed in mph**. When it describes itself, it should print its make, model, fuel level, assigned department, and max speed. When it refuels, it adds 50 to the current fuel level (without exceeding 100) and prints a confirmation message.

- A **Maintenance Truck** hauls equipment and supplies. It has a **cargo description** (e.g., "landscaping tools") and a **cargo weight in pounds**. When it describes itself, it should print its make, model, fuel level, cargo description, and cargo weight.

The transportation office wants a unified system where any vehicle can be described or refueled using the same function calls — but the output should always reflect each vehicle's unique characteristics.

---

## Your Task

Design and implement a C++ program that models this scenario using **inheritance** and **method overriding**. Work through the steps below in order.

**Step 1 — Build the base class.**  
Create a class called `Vehicle`. It should store the make, model, and fuel level as data members. Write a constructor that accepts all three values. Define a `describe()` function that prints the make, model, and fuel level. Define a `refuel()` function that sets the fuel level to 100 and prints a generic confirmation message.

**Step 2 — Build at least two derived classes.**  
Choose at least two of the three vehicle types described above (Campus Shuttle, Golf Cart, or Maintenance Truck) and implement them as derived classes of `Vehicle`. Each derived class should:
- Have its own constructor that accepts both the base class data and its own additional data members, passing the appropriate values up to the base class constructor.
- Override `describe()` to print everything the base class version prints, **plus** the additional data members specific to that vehicle type.

**Step 3 — Override `refuel()` in at least one derived class.**  
Pick one of your derived classes and override `refuel()` so that it behaves differently from the base class version, as described in the scenario above.

**Step 4 — Test everything in `main()`.**  
Create one object of each derived class you implemented. Call `describe()` and `refuel()` on each object. Then call `describe()` again after refueling to confirm the fuel level changed.

---

## Constraints

- Do **not** use abstract classes or pure virtual functions — those are coming up next week.
- Do **not** use pointers or dynamic memory allocation.
- Every data member in every class should be **private** or **protected** with appropriate access.

---

## Reflection Question

After you finish, think about this: if you created a plain `Vehicle` object and called `describe()` on it, what would print? How does that output differ from calling `describe()` on one of your derived class objects? Why does that happen? Be ready to share your answer with the class.

---

*Transportation services keep FAMU moving — now you're helping build the system that tracks it.*