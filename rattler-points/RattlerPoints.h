// RattlerPoints.h
// Represents a FAMU Rec Center member's reward point balance.
// Demonstrates operator overloading: arithmetic, comparison, and stream I/O.
// COP 3330 — Chapter 11: Operator Overloading
//
// Operator overloading summary for this class:
//   Arithmetic  : +, -, +=, -=
//   Comparison  : ==, !=, <, >, <=, >=
//   Stream I/O  : << (insertion), >> (extraction)

#ifndef RATTLER_POINTS_H
#define RATTLER_POINTS_H

#include <string>
#include <iostream>
#include <stdexcept>

class RattlerPoints {
public:
    // -----------------------------------------------------------------------
    // Constructors
    // -----------------------------------------------------------------------

    // Primary constructor — initializes member name and starting point balance.
    // Throws std::invalid_argument if points is negative or name is empty.
    explicit RattlerPoints(std::string memberName, int points = 0);

    // -----------------------------------------------------------------------
    // Accessors
    // -----------------------------------------------------------------------
    std::string getMemberName() const;
    int getPoints() const;

    // -----------------------------------------------------------------------
    // Arithmetic member operators
    // -----------------------------------------------------------------------

    // Adds rhs points to this balance; returns reference for chaining.
    RattlerPoints& operator+=(const RattlerPoints& rhs);

    // Subtracts rhs points from this balance.
    // Throws std::underflow_error if result would go below zero.
    RattlerPoints& operator-=(const RattlerPoints& rhs);

    // Adds a raw integer point value (e.g., earning 50 points at check-in).
    RattlerPoints& operator+=(int points);

    // Subtracts a raw integer point value (e.g., spending 100 points on gear).
    // Throws std::underflow_error if result would go below zero.
    RattlerPoints& operator-=(int points);

    // -----------------------------------------------------------------------
    // Friend: binary arithmetic operators (non-member, needs private access)
    // -----------------------------------------------------------------------

    // Returns a NEW RattlerPoints whose balance = lhs.points + rhs.points.
    // The resulting object takes the name of the left-hand operand.
    friend RattlerPoints operator+(RattlerPoints lhs, const RattlerPoints& rhs);

    // Returns a NEW RattlerPoints whose balance = lhs.points - rhs.points.
    // Throws std::underflow_error if result would go below zero.
    friend RattlerPoints operator-(RattlerPoints lhs, const RattlerPoints& rhs);

    // -----------------------------------------------------------------------
    // Friend: comparison operators (compare point balances only)
    // -----------------------------------------------------------------------
    friend bool operator==(const RattlerPoints& lhs, const RattlerPoints& rhs);
    friend bool operator!=(const RattlerPoints& lhs, const RattlerPoints& rhs);
    friend bool operator< (const RattlerPoints& lhs, const RattlerPoints& rhs);
    friend bool operator> (const RattlerPoints& lhs, const RattlerPoints& rhs);
    friend bool operator<=(const RattlerPoints& lhs, const RattlerPoints& rhs);
    friend bool operator>=(const RattlerPoints& lhs, const RattlerPoints& rhs);

    // -----------------------------------------------------------------------
    // Friend: stream operators
    // -----------------------------------------------------------------------

    // Inserts a formatted summary of the RattlerPoints object into the stream.
    // Format: "Member: <name> | Points: <balance>"
    friend std::ostream& operator<<(std::ostream& out,
                                    const RattlerPoints& rp);

    // Extracts a member name and point balance from the stream.
    // Expects format: <name> <points>
    // Sets stream to fail state if points value is negative.
    friend std::istream& operator>>(std::istream& in, RattlerPoints& rp);

private:
    std::string m_memberName; // Rec Center member's name
    int         m_points;     // Current reward point balance (always >= 0)
};

#endif // RATTLER_POINTS_H
