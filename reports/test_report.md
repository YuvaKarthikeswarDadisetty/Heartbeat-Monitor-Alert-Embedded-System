# Test Report

## Test Matrix

| ID | Condition | Expected Result | Status |
|---|---|---|---|
| T01 | Startup | LCD startup message | PASS |
| T02 | No pulse | NO SIGNAL | PASS |
| T03 | 75 BPM | NORMAL + green LED | PASS |
| T04 | 40 BPM | LOW + red LED + buzzer | PASS |
| T05 | 120 BPM | HIGH + red LED + buzzer | PASS |
| T06 | Closely spaced peaks | Duplicate beat rejected | PASS |
| T07 | LCD | BPM/status displayed | PASS |
| T08 | Serial output | Debug values visible | PASS |

> These are intended as demonstration/test cases. Hardware measurements should be validated on the actual sensor and setup.
