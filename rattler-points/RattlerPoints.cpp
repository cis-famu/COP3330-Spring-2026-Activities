// RattlerPoints.cpp
// Implementation of the RattlerPoints class.
// COP 3330 — Chapter 11: Operator Overloading

#include "RattlerPoints.h"
#include <format>
#include <stdexcept>

// -----------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------

RattlerPoints::RattlerPoints(std::string memberName, int points)
    : m_memberName{std::move(memberName)}, m_points{points}
{
    if (m_memberName.empty()) {
        throw std::invalid_argument{"Member name cannot be empty."};
    }
    if (m_points < 0) {
        throw std::invalid_argument{
            std::format("Initial point balance cannot be negative (got {}).",
                        m_points)};
    }
}

// -----------------------------------------------------------------------
// Accessors
// -----------------------------------------------------------------------

std::string RattlerPoints::getMemberName() const { return m_memberName; }
int         RattlerPoints::getPoints()     const { return m_points; }

// -----------------------------------------------------------------------
// Compound-assignment operators (member functions)
// -----------------------------------------------------------------------

// Operator +=  (RattlerPoints rhs)
// Adds rhs balance to this object's balance and returns *this.
// Returning a reference enables chaining: a += b += c
RattlerPoints& RattlerPoints::operator+=(const RattlerPoints& rhs) {
    m_points += rhs.m_points;
    return *this;
}

// Operator -=  (RattlerPoints rhs)
// Subtracts rhs balance from this object's balance.
// Throws if the result would produce a negative balance — members
// can never owe points.
RattlerPoints& RattlerPoints::operator-=(const RattlerPoints& rhs) {
    if (m_points < rhs.m_points) {
        throw std::underflow_error{
            std::format("Insufficient points: {} has {} but {} are required.",
                        m_memberName, m_points, rhs.m_points)};
    }
    m_points -= rhs.m_points;
    return *this;
}

// Operator +=  (int points)
// Adds a raw integer amount — useful for awarding points at check-in.
RattlerPoints& RattlerPoints::operator+=(int points) {
    if (points < 0) {
        throw std::invalid_argument{"Cannot add a negative point value."};
    }
    m_points += points;
    return *this;
}

// Operator -=  (int points)
// Subtracts a raw integer amount — useful for spending points on rewards.
RattlerPoints& RattlerPoints::operator-=(int points) {
    if (points < 0) {
        throw std::invalid_argument{"Cannot subtract a negative point value."};
    }
    if (m_points < points) {
        throw std::underflow_error{
            std::format("Insufficient points: {} has {} but {} are required.",
                        m_memberName, m_points, points)};
    }
    m_points -= points;
    return *this;
}

// -----------------------------------------------------------------------
// Binary arithmetic operators (non-member friend functions)
//
// Design note: both operator+ and operator- take their LEFT operand by
// VALUE (a copy), then delegate to the compound-assignment operators.
// This is the canonical "copy-and-modify" idiom — it avoids code
// duplication and keeps mutation logic in one place (the += / -= members).
// -----------------------------------------------------------------------

RattlerPoints operator+(RattlerPoints lhs, const RattlerPoints& rhs) {
    lhs += rhs;   // reuse operator+=; lhs is already a copy
    return lhs;
}

RattlerPoints operator-(RattlerPoints lhs, const RattlerPoints& rhs) {
    lhs -= rhs;   // reuse operator-=; throws if insufficient points
    return lhs;
}

// -----------------------------------------------------------------------
// Comparison operators (compare point balances, not member names)
//
// Design note: we define == and < in terms of m_points, then express the
// remaining four operators in terms of those two — a common, clean idiom.
// -----------------------------------------------------------------------

bool operator==(const RattlerPoints& lhs, const RattlerPoints& rhs) {
    return lhs.m_points == rhs.m_points;
}

bool operator!=(const RattlerPoints& lhs, const RattlerPoints& rhs) {
    return !(lhs == rhs);
}

bool operator<(const RattlerPoints& lhs, const RattlerPoints& rhs) {
    return lhs.m_points < rhs.m_points;
}

bool operator>(const RattlerPoints& lhs, const RattlerPoints& rhs) {
    return rhs < lhs;          // reuse operator<
}

bool operator<=(const RattlerPoints& lhs, const RattlerPoints& rhs) {
    return !(rhs < lhs);       // reuse operator<
}

bool operator>=(const RattlerPoints& lhs, const RattlerPoints& rhs) {
    return !(lhs < rhs);       // reuse operator<
}

// -----------------------------------------------------------------------
// Stream operators (non-member friend functions)
// -----------------------------------------------------------------------

// Insertion operator —— must be a non-member because the left operand
// is ostream, not RattlerPoints.  Returns ostream& to allow chaining:
//   std::cout << member1 << member2 << std::endl;
std::ostream& operator<<(std::ostream& out, const RattlerPoints& rp) {
    out << std::format("Member: {:<20} | Points: {:>6}",
                       rp.m_memberName, rp.m_points);
    return out;
}

// Extraction operator —— reads "name points" from the stream.
// Sets stream to fail state on a negative balance rather than throwing,
// which is the conventional behavior for stream extraction.
std::istream& operator>>(std::istream& in, RattlerPoints& rp) {
    std::string name{};
    int points{};

    if (in >> name >> points) {
        if (points < 0) {
            in.setstate(std::ios::failbit);  // signal bad input; do not modify
        } else {
            rp.m_memberName = std::move(name);
            rp.m_points     = points;
        }
    }
    return in;
}
