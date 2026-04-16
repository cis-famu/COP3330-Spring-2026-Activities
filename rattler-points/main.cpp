// main.cpp
// Driver program for the RattlerPoints class.
// Demonstrates all overloaded operators in a FAMU Rec Center context.
// COP 3330 — Chapter 11: Operator Overloading

#include "RattlerPoints.h"
#include <iostream>
#include <format>
#include <sstream>
#include <vector>
#include <algorithm>  // std::sort — uses operator<
#include <stdexcept>

// -----------------------------------------------------------------------
// Helper: print a section header for readability
// -----------------------------------------------------------------------
void printSection(const std::string& title) {
    std::cout << "\n" << std::string(55, '-') << "\n"
              << "  " << title << "\n"
              << std::string(55, '-') << "\n";
}

int main() {

    // ===================================================================
    // 1. Construction
    // ===================================================================
    printSection("1. Constructing RattlerPoints objects");

    RattlerPoints devin{"Devin Carter", 120};
    RattlerPoints amara{"Amara Johnson", 200};
    RattlerPoints kofi {"Kofi Williams", 120};   // same balance as Devin

    std::cout << devin << "\n"
              << amara << "\n"
              << kofi  << "\n";

    // ===================================================================
    // 2. Arithmetic: operator+= and operator-= (RattlerPoints operand)
    // ===================================================================
    printSection("2. Compound assignment: += and -=");

    // Devin earns Amara's points (e.g., combined workout session reward)
    RattlerPoints combined{"Devin Carter", devin.getPoints()};
    combined += amara;
    std::cout << "After combined += amara:\n  " << combined << "\n";

    // Spend points
    RattlerPoints cost{"Redemption", 80};
    combined -= cost;
    std::cout << "After combined -= cost(80):\n  " << combined << "\n";

    // ===================================================================
    // 3. Arithmetic: operator+= and operator-= (int operand)
    // ===================================================================
    printSection("3. Compound assignment with int: earn and spend");

    devin += 50;   // checked in at the gym today
    std::cout << "Devin checks in (+50):     " << devin << "\n";

    devin -= 30;   // redeems points for a water bottle
    std::cout << "Devin redeems 30 points:   " << devin << "\n";

    // ===================================================================
    // 4. Binary arithmetic: operator+ and operator-
    // ===================================================================
    printSection("4. Binary arithmetic: + and -");

    RattlerPoints total = devin + amara;
    std::cout << "devin + amara = " << total << "\n";

    RattlerPoints diff = amara - devin;
    std::cout << "amara - devin = " << diff  << "\n";

    // ===================================================================
    // 5. Comparison operators
    // ===================================================================
    printSection("5. Comparison operators (by point balance)");

    // Helper lambda to print a labelled bool result
    auto printCmp = [](const std::string& expr, bool result) {
        std::cout << std::format("  {:<35} -> {}\n",
                                 expr, result ? "true" : "false");
    };

    printCmp("devin == kofi  (same balance?)", devin == kofi);
    printCmp("devin != amara (different?)",    devin != amara);
    printCmp("devin < amara  (fewer points?)", devin <  amara);
    printCmp("amara > kofi   (more points?)",  amara >  kofi);
    printCmp("devin <= kofi  (at most?)",      devin <= kofi);
    printCmp("amara >= devin (at least?)",     amara >= devin);

    // ===================================================================
    // 6. Stream insertion: operator<<
    // ===================================================================
    printSection("6. Stream insertion: operator<<");

    // Chain multiple objects in a single output statement
    std::cout << devin << "\n" << amara << "\n" << kofi << "\n";

    // ===================================================================
    // 7. Stream extraction: operator>>
    // ===================================================================
    printSection("7. Stream extraction: operator>>");

    // Simulate reading from a string stream (mirrors reading from cin)
    std::istringstream inputStream{"JordanBrown 175"};
    RattlerPoints newMember{"placeholder", 0};

    if (inputStream >> newMember) {
        std::cout << "Read from stream: " << newMember << "\n";
    } else {
        std::cout << "Stream extraction failed.\n";
    }

    // ===================================================================
    // 8. Practical use: sort a leaderboard using operator<
    // ===================================================================
    printSection("8. Leaderboard: std::sort uses operator<");

    std::vector<RattlerPoints> leaderboard;
    leaderboard.emplace_back("Nia Thompson",  340);
    leaderboard.emplace_back("Marcus Bell",    95);
    leaderboard.emplace_back("Devin Carter",  devin.getPoints());
    leaderboard.emplace_back("Amara Johnson", amara.getPoints());
    leaderboard.emplace_back("Kofi Williams", kofi.getPoints());

    // Sort descending: member with the most points first
    std::sort(leaderboard.begin(), leaderboard.end(),
              [](const RattlerPoints& a, const RattlerPoints& b) {
                  return a > b;  // operator>
              });

    std::cout << "Rattler Rec Center — Top Members:\n";
    for (int rank{1}; const auto& member : leaderboard) {
        std::cout << std::format("  {:>2}. ", rank++) << member << "\n";
    }

    // ===================================================================
    // 9. Exception handling: guard against invalid operations
    // ===================================================================
    printSection("9. Exception safety: underflow and invalid input");

    try {
        RattlerPoints poorMarcus{"Marcus Bell", 20};
        poorMarcus -= 50;   // spending more than he has
    } catch (const std::underflow_error& e) {
        std::cout << "Caught underflow_error: " << e.what() << "\n";
    }

    try {
        RattlerPoints bad{"", 50};   // empty name
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: " << e.what() << "\n";
    }

    try {
        RattlerPoints bad{"Someone", -10};   // negative initial balance
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: " << e.what() << "\n";
    }

    std::cout << "\nDone.\n";
    return 0;
}
