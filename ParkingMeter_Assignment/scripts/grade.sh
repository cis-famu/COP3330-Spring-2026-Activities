#!/usr/bin/env bash
set -euo pipefail

# 1) Ensure gtest exists
./scripts/install_gtest.sh >/dev/null 2>&1 || true

# 2) Run tests and capture status
set +e
./scripts/run_tests.sh >build/test_output.txt 2>&1
TEST_EXIT=$?
set -e

# 3) Parse results (count tests + failures) from XML if present
TOTAL=0
FAIL=0
if [ -f build/gtest_results.xml ]; then
    # total tests: sum of tests attributes in testsuite nodes
    TOTAL=$(grep -oP 'tests="\K[0-9]+' build/gtest_results.xml | awk '{s+=$1} END{print s+0}')
    # failures: sum of failures attributes
    FAIL=$(grep -oP 'failures="\K[0-9]+' build/gtest_results.xml | awk '{s+=$1} END{print s+0}')
else
    # fallback if XML missing
    TOTAL=1
    FAIL=$(( TEST_EXIT != 0 ? 1 : 0 ))
fi

PASSED=$(( TOTAL - FAIL ))
if [ "$TOTAL" -le 0 ]; then TOTAL=1; fi

# 4) Score as percentage
SCORE=$(( (PASSED * 100) / TOTAL ))

# 5) Feedback message
if [ "$TEST_EXIT" -eq 0 ]; then
    FEEDBACK="✓ All unit tests passed (${PASSED}/${TOTAL}). Excellent work! Your class meets all required API and behavior rules."
else
    # show last ~40 lines of output to help students debug
    TAIL="$(tail -n 40 build/test_output.txt | sed 's/"/\\"/g')"
    FEEDBACK="Some unit tests failed (${PASSED}/${TOTAL} passed). Review the error messages below and check your method signatures and behavior rules.\n\nDebug output:\n${TAIL}"
fi

# 6) Print Codio result JSON
echo "{\"score\": ${SCORE}, \"feedback\": \"${FEEDBACK}\"}"

# 7) Exit 0 so Codio records the JSON rather than a crash
exit 0
