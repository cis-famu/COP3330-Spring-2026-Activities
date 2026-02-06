// tests/test_parking_meter.cpp
// Student-friendly GoogleTest suite with "common mistake" hints.
//
// This file tests the ParkingMeter class implementation.
// Students should read failure messages carefully - they contain debugging hints.

#include <gtest/gtest.h>
#include <cmath>
#include <string>
#include "../ParkingMeter.h"

// ---------- Helpers for clearer feedback ----------

static void ExpectTimeCalculatedCorrectly(int actual, int expected) {
    EXPECT_EQ(actual, expected)
        << "\n❌ Time calculation was incorrect."
        << "\nExpected: " << expected << " minutes"
        << "\nActual: " << actual << " minutes"
        << "\n\nWhat to do:"
        << "\n- Formula: minutes = (amount / ratePerHour) * 60"
        << "\n- Always round DOWN to nearest minute (use integer division)"
        << "\n\nCommon mistakes:"
        << "\n- Using floating-point division instead of integer truncation"
        << "\n- Rounding up instead of down"
        << "\n- Not converting hours to minutes correctly";
}

static void ExpectMoneyNear(double actual, double expected, double eps = 0.01) {
    EXPECT_NEAR(actual, expected, eps)
        << "\n❌ Money calculation was incorrect."
        << "\nExpected: $" << expected
        << "\nActual: $" << actual
        << "\n\nCommon mistakes:"
        << "\n- Not accumulating totalCollected_ correctly"
        << "\n- Resetting totalCollected_ when you shouldn't"
        << "\n- Using = instead of += for accumulation";
}

// ---------- Constructor Tests ----------

TEST(ParkingMeterConstructor, InitializesStateCorrectly) {
    SCOPED_TRACE("Constructing ParkingMeter(\"M-101\", 2.00)");
    
    ParkingMeter meter("M-101", 2.00);
    
    EXPECT_EQ(meter.getMeterID(), "M-101")
        << "\n❌ getMeterID() did not return the ID passed to constructor."
        << "\n\nCommon mistakes:"
        << "\n- Not assigning meterID_ in the constructor"
        << "\n- Returning the wrong member variable";
    
    EXPECT_NEAR(meter.getRatePerHour(), 2.00, 0.01)
        << "\n❌ getRatePerHour() did not return the rate passed to constructor."
        << "\n\nCommon mistakes:"
        << "\n- Not assigning ratePerHour_ in the constructor"
        << "\n- Using integer instead of double for rate";
    
    EXPECT_EQ(meter.getTimeRemaining(), 0)
        << "\n❌ A new meter should start with 0 minutes remaining."
        << "\n\nCommon mistakes:"
        << "\n- Not initializing timeRemaining_ to 0"
        << "\n- Forgetting to initialize it at all";
    
    ExpectMoneyNear(meter.getTotalCollected(), 0.0);
    
    EXPECT_TRUE(meter.isActive())
        << "\n❌ A newly created meter should start as active."
        << "\n\nCommon mistakes:"
        << "\n- Setting isActive_ to false in constructor"
        << "\n- Not initializing isActive_ (undefined behavior)";
}

// ---------- Insert Coin Tests ----------

TEST(ParkingMeterInsertCoin, AcceptsValidCoins) {
    ParkingMeter meter("M-202", 2.00);  // $2.00/hour
    
    SCOPED_TRACE("Inserting quarter (0.25)");
    EXPECT_TRUE(meter.insertCoin(0.25))
        << "\n❌ insertCoin(0.25) should return true for a valid quarter."
        << "\n\nCommon mistakes:"
        << "\n- Not checking against valid denominations (0.05, 0.10, 0.25, 1.00)"
        << "\n- Using exact equality (==) with doubles - use epsilon comparison";
    
    // Quarter at $2/hr = 0.25/2.00 * 60 = 7.5 minutes -> rounds down to 7
    ExpectTimeCalculatedCorrectly(meter.getTimeRemaining(), 7);
    ExpectMoneyNear(meter.getTotalCollected(), 0.25);
}

TEST(ParkingMeterInsertCoin, RejectsInvalidAmounts) {
    ParkingMeter meter("M-303", 2.00);
    
    SCOPED_TRACE("Attempting invalid coin (0.01 - penny)");
    EXPECT_FALSE(meter.insertCoin(0.01))
        << "\n❌ insertCoin(0.01) should return false - pennies not accepted."
        << "\n\nValid coins: 0.05, 0.10, 0.25, 1.00"
        << "\n\nCommon mistakes:"
        << "\n- Accepting any positive amount"
        << "\n- Not validating against specific denominations";
    
    SCOPED_TRACE("Attempting invalid coin (0.50 - half dollar)");
    EXPECT_FALSE(meter.insertCoin(0.50))
        << "\n❌ insertCoin(0.50) should return false - half dollars not accepted.";
    
    SCOPED_TRACE("Attempting negative amount");
    EXPECT_FALSE(meter.insertCoin(-0.25))
        << "\n❌ insertCoin should reject negative amounts.";
    
    // State should be unchanged
    EXPECT_EQ(meter.getTimeRemaining(), 0)
        << "\n❌ Invalid coins should NOT change timeRemaining_.";
    ExpectMoneyNear(meter.getTotalCollected(), 0.0);
}

TEST(ParkingMeterInsertCoin, AccumulatesTimeAndMoney) {
    ParkingMeter meter("M-404", 3.00);  // $3.00/hour
    
    SCOPED_TRACE("First coin: quarter");
    meter.insertCoin(0.25);
    // 0.25/3.00 * 60 = 5 minutes
    ExpectTimeCalculatedCorrectly(meter.getTimeRemaining(), 5);
    
    SCOPED_TRACE("Second coin: dime");
    meter.insertCoin(0.10);
    // 0.10/3.00 * 60 = 2 minutes
    // Total: 5 + 2 = 7
    ExpectTimeCalculatedCorrectly(meter.getTimeRemaining(), 7);
    
    ExpectMoneyNear(meter.getTotalCollected(), 0.35);
}

// ---------- Add Time Tests ----------

TEST(ParkingMeterAddTime, AddsTimeWhenActive) {
    ParkingMeter meter("M-505", 2.00);
    meter.insertCoin(0.25);  // Get some initial time
    
    SCOPED_TRACE("Adding 30 minutes to active meter");
    EXPECT_TRUE(meter.addTime(30))
        << "\n❌ addTime() should return true when meter is active."
        << "\n\nCommon mistakes:"
        << "\n- Not checking if meter is active"
        << "\n- Always returning false";
    
    // Initial 7 + added 30 = 37
    EXPECT_EQ(meter.getTimeRemaining(), 37)
        << "\n❌ addTime should ADD to existing time, not replace it."
        << "\n\nCommon mistakes:"
        << "\n- Using = instead of += for timeRemaining_";
}

TEST(ParkingMeterAddTime, RejectsWhenInactive) {
    ParkingMeter meter("M-606", 2.00);
    // Don't insert any coins - meter stays at 0 time but is active
    
    SCOPED_TRACE("Expire the meter first");
    meter.expire();
    EXPECT_FALSE(meter.isActive())
        << "\n❌ After expire(), meter should NOT be active.";
    
    SCOPED_TRACE("Attempting to add time to expired meter");
    EXPECT_FALSE(meter.addTime(15))
        << "\n❌ addTime() should return false when meter is not active."
        << "\n\nBusiness rule: Cannot add time to expired meter without payment."
        << "\n\nCommon mistakes:"
        << "\n- Not checking isActive_ before adding time"
        << "\n- Allowing time to be added regardless of state";
    
    EXPECT_EQ(meter.getTimeRemaining(), 0)
        << "\n❌ Time should not change when addTime() fails.";
}

TEST(ParkingMeterAddTime, RejectsInvalidValues) {
    ParkingMeter meter("M-707", 2.00);
    meter.insertCoin(0.25);
    
    SCOPED_TRACE("Attempting negative minutes");
    EXPECT_FALSE(meter.addTime(-10))
        << "\n❌ addTime() should reject negative values.";
    
    SCOPED_TRACE("Attempting zero minutes");
    EXPECT_FALSE(meter.addTime(0))
        << "\n❌ addTime() should reject zero.";
}

// ---------- Expire Tests ----------

TEST(ParkingMeterExpire, SetsCorrectState) {
    ParkingMeter meter("M-808", 2.00);
    meter.insertCoin(1.00);  // Add some time
    
    int timeBefore = meter.getTimeRemaining();
    EXPECT_GT(timeBefore, 0)
        << "\n❌ Setup failed - meter should have time before expiring.";
    
    SCOPED_TRACE("Calling expire()");
    meter.expire();
    
    EXPECT_EQ(meter.getTimeRemaining(), 0)
        << "\n❌ expire() should set timeRemaining_ to 0."
        << "\n\nCommon mistakes:"
        << "\n- Not resetting timeRemaining_";
    
    EXPECT_FALSE(meter.isActive())
        << "\n❌ expire() should set isActive_ to false."
        << "\n\nCommon mistakes:"
        << "\n- Not changing isActive_"
        << "\n- Setting isActive_ to true by accident";
    
    // Money collected should NOT change
    ExpectMoneyNear(meter.getTotalCollected(), 1.00);
}

// ---------- Post-Payment Tests ----------

TEST(ParkingMeterPostPayment, ReactivatesExpiredMeter) {
    ParkingMeter meter("M-909", 2.00);  // $2/hour
    
    SCOPED_TRACE("Expire the meter");
    meter.expire();
    EXPECT_FALSE(meter.isActive());
    
    SCOPED_TRACE("Post-payment of $2.00");
    EXPECT_TRUE(meter.postPayment(2.00))
        << "\n❌ postPayment() should return true for valid payment >= rate."
        << "\n\nCommon mistakes:"
        << "\n- Not checking if amount >= ratePerHour_"
        << "\n- Always returning false";
    
    EXPECT_TRUE(meter.isActive())
        << "\n❌ postPayment() should reactivate an expired meter."
        << "\n\nCommon mistakes:"
        << "\n- Not setting isActive_ to true";
    
    // $2.00 at $2/hour = 60 minutes
    ExpectTimeCalculatedCorrectly(meter.getTimeRemaining(), 60);
    ExpectMoneyNear(meter.getTotalCollected(), 2.00);
}

TEST(ParkingMeterPostPayment, RejectsInsufficientPayment) {
    ParkingMeter meter("M-010", 2.00);
    meter.expire();
    
    SCOPED_TRACE("Attempting post-payment less than hourly rate");
    EXPECT_FALSE(meter.postPayment(1.50))
        << "\n❌ postPayment() should reject amounts less than ratePerHour_."
        << "\n\nBusiness rule: Minimum post-payment is one full hour."
        << "\n\nCommon mistakes:"
        << "\n- Accepting any positive amount"
        << "\n- Not comparing against ratePerHour_";
    
    EXPECT_FALSE(meter.isActive())
        << "\n❌ Meter should remain inactive after failed post-payment.";
    
    EXPECT_EQ(meter.getTimeRemaining(), 0);
    ExpectMoneyNear(meter.getTotalCollected(), 0.0);
}

TEST(ParkingMeterPostPayment, RejectsNonPositivePayment) {
    ParkingMeter meter("M-011", 2.00);
    meter.expire();
    
    EXPECT_FALSE(meter.postPayment(0.0));
    EXPECT_FALSE(meter.postPayment(-5.00));
}

// ---------- State Independence Test ----------

TEST(ParkingMeterIndependence, MultipleMetersMaintainIndependentState) {
    ParkingMeter m1("M-AAA", 2.00);
    ParkingMeter m2("M-BBB", 3.00);
    
    SCOPED_TRACE("Insert coin in m1 only");
    m1.insertCoin(0.25);
    
    EXPECT_GT(m1.getTimeRemaining(), 0)
        << "\n❌ m1 should have time after coin insertion.";
    EXPECT_EQ(m2.getTimeRemaining(), 0)
        << "\n❌ m2 should NOT be affected by m1's coin insertion."
        << "\n\nCommon mistakes:"
        << "\n- Using static variables (shared across all objects)"
        << "\n- Not properly isolating object state";
    
    SCOPED_TRACE("Expire m2 only");
    m2.expire();
    
    EXPECT_TRUE(m1.isActive())
        << "\n❌ m1 should still be active - m2's expiration shouldn't affect it.";
    EXPECT_FALSE(m2.isActive());
    
    ExpectMoneyNear(m1.getTotalCollected(), 0.25);
    ExpectMoneyNear(m2.getTotalCollected(), 0.0);
}

// ---------- Integration Test ----------

TEST(ParkingMeterIntegration, RealisticUsageScenario) {
    ParkingMeter meter("M-DOWNTOWN-42", 4.00);  // $4/hour (expensive!)
    
    SCOPED_TRACE("Initial state check");
    EXPECT_TRUE(meter.isActive());
    EXPECT_EQ(meter.getTimeRemaining(), 0);
    
    SCOPED_TRACE("Customer inserts dollar coin");
    meter.insertCoin(1.00);
    // $1 at $4/hr = 0.25 * 60 = 15 minutes
    ExpectTimeCalculatedCorrectly(meter.getTimeRemaining(), 15);
    
    SCOPED_TRACE("Customer adds 10 more minutes manually");
    meter.addTime(10);
    EXPECT_EQ(meter.getTimeRemaining(), 25);
    
    SCOPED_TRACE("Meter expires (time runs out)");
    meter.expire();
    EXPECT_FALSE(meter.isActive());
    EXPECT_EQ(meter.getTimeRemaining(), 0);
    
    SCOPED_TRACE("Customer returns and pays for another hour");
    meter.postPayment(4.00);
    EXPECT_TRUE(meter.isActive());
    ExpectTimeCalculatedCorrectly(meter.getTimeRemaining(), 60);
    
    SCOPED_TRACE("Final total collected");
    ExpectMoneyNear(meter.getTotalCollected(), 5.00);  // $1 + $4
}
