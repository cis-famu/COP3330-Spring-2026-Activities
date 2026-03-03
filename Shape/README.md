# Shape Inheritance Example
### COP 3330 – Introduction to Object-Oriented Programming

---

## Overview

This repository contains a small C++ program that demonstrates **inheritance** and **method overriding** using a simple shape hierarchy. It is intended to serve as a reference example as you begin working with base and derived classes in C++.

The program defines a base class `Shape` and two derived classes — `Circle` and `Rectangle` — each of which overrides the base class behavior to reflect its own properties.

---

## File Descriptions

### `Shape.h` / `Shape.cpp` — The Base Class

`Shape` is the base class of the hierarchy. It stores two data members:

- `color` — a `string` representing the color of the shape.
- `x` — a `double` used as a generic numeric dimension.

It provides two member functions:

- `getArea()` — returns a computed area based on `x`.
- `display()` — prints the shape's color and computed area.

The constructor accepts a `color` string and a `double x` value and initializes both using a member initializer list.

`color` and `x` are declared `protected`, which means they are accessible directly within derived classes while remaining hidden from code outside the hierarchy.

---

### `Circle.h` / `Circle.cpp` — First Derived Class

`Circle` inherits publicly from `Shape` and adds a `radius` data member. It overrides both `getArea()` and `display()`.

- `getArea()` — computes the circle's area using the formula `3.14 * radius * radius`.
- `display()` — prints the circle's color, radius, and computed area.

The `Circle` constructor uses a member initializer list to correctly pass values up to the `Shape` base class constructor before initializing `radius`.

---

### `Rectangle.h` / `Rectangle.cpp` — Second Derived Class

`Rectangle` inherits publicly from `Shape` and adds `width` and `height` data members. It overrides both `getArea()` and `display()`.

- `getArea()` — computes the rectangle's area as `width * height`.
- `display()` — calls `Shape::display()` to print the color and area, then prints the width and height.

Notice that `Rectangle::display()` explicitly calls `Shape::display()` using the scope resolution operator (`::`) rather than duplicating that output logic. This is a common and recommended pattern when a derived class wants to extend — rather than fully replace — the base class behavior.

---

### `driver.cpp` — The Driver Program

`main()` creates one object of each class type and calls `display()` on each:

```
Shape  → created with color "Red"
Circle → created with color "Blue" and radius 5.0
Rectangle → created with color "Green", width 4.0, height 6.0
```

Trace through each `display()` call and predict the output before running the program. Pay attention to which version of `display()` executes for each object and why.

---

## How to Compile

```bash
g++ -std=c++20 Shape.cpp Circle.cpp Rectangle.cpp driver.cpp -o shapes
```

---

## Things to Observe as You Read the Code

- How does each derived class constructor pass data up to the base class constructor?
- How does `Rectangle` reuse `Shape::display()` instead of rewriting it?
- What is the effect of declaring `color` and `x` as `protected` rather than `private`?
- How does overriding `getArea()` in each derived class produce different results even when called through the same function name?

---

*This example is a starting point. As the course progresses, you will see how virtual functions and abstract classes make this kind of hierarchy significantly more powerful and flexible.*