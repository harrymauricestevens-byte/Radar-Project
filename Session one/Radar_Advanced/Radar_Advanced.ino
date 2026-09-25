/*
 * =====================================================================
 *  MINI RADAR  -  ADVANCED VERSION
 *  Elecsoc Radar Project, Session 0
 * =====================================================================
 *
 *  YOUR MISSION
 *  An enemy vehicle is approaching the base. Design and program a radar
 *  that detects it and alerts the defence personnel. No starter code is
 *  provided: the design is up to you.
 *
 *  HARDWARE
 *    Arduino Uno, HC-SR04 ultrasonic sensor, 1x LED, 1x 220-330 ohm
 *    resistor, breadboard, jumper wires.
 *
 *    Suggested wiring (change it if you like, but update your code):
 *      HC-SR04 VCC  -> 5V         HC-SR04 TRIG -> pin 11
 *      HC-SR04 GND  -> GND        HC-SR04 ECHO -> pin 10
 *      LED (+ resistor) -> pin 13 -> GND
 *
 *  HOW THE SENSOR WORKS
 *    - Hold TRIG HIGH for >= 10 us to fire a 40 kHz ultrasonic burst.
 *    - The sensor then drives ECHO HIGH for exactly as long as the sound
 *      takes to reach the target and come back.
 *    - Speed of sound ~ 343 m/s (0.0343 cm/us). Range is ~2 cm to ~4 m.
 *    - Leave at least ~60 ms between pings so old echoes die away.
 *
 * ---------------------------------------------------------------------
 *  REQUIREMENTS (must have)
 * ---------------------------------------------------------------------
 *   R1  Measure target distance in cm and print it to the Serial Monitor.
 *   R2  Handle "no echo" properly: the program must never freeze when
 *       nothing is in range.
 *   R3  Switch the warning LED on when a target is closer than a
 *       configurable alert distance, and off otherwise.
 *   R4  Structure the code with your own functions, and name constants
 *       (no magic numbers scattered through loop()).
 *   R5  Check accuracy against a ruler at several distances and write
 *       down your error.
 *
 * ---------------------------------------------------------------------
 *  STRETCH GOALS (pick any)
 * ---------------------------------------------------------------------
 *   S1  Filtering: median or moving-average filter to reject glitches.
 *   S2  Non-blocking design: use millis() instead of delay(), so the
 *       alarm LED can flash at a rate that depends on distance while
 *       the radar keeps scanning.
 *   S3  Hysteresis: arm the alarm at one distance and clear it at a
 *       slightly larger one, so it doesn't flicker at the boundary.
 *   S4  Target velocity: estimate closing speed (cm/s) from successive
 *       readings. Only alarm on targets that are APPROACHING.
 *   S5  Temperature compensation: the speed of sound is roughly
 *       331.3 + 0.606 * T(degC) m/s. How much error does 10 degC cause?
 *   S6  Serial command interface: e.g. send "A30" to set the alert
 *       distance to 30 cm, "S" to stand down, "R" to resume.
 *   S7  Machine-readable output: print "time_ms,distance_cm" as CSV and
 *       plot it (Serial Plotter or Python on the Pi).
 *   S8  Think ahead: what limits the range resolution of this sensor?
 *       How does our 24 GHz FMCW radar measure distance differently?
 *
 *  RESOURCES
 *    Function Reference in the session handout, docs.arduino.cc,
 *    and wokwi.com to simulate before touching hardware.
 * =====================================================================
 */


void setup() {

}


void loop() {

}
