/*
 * =====================================================================
 *  MINI RADAR  -  INTERMEDIATE VERSION
 *  Elecsoc Radar Project, Session 0
 * =====================================================================
 *
 *  YOUR MISSION
 *  An enemy vehicle is approaching the base. Build a radar that measures
 *  its distance and alerts the defence personnel when it gets too close.
 *
 *  YOUR JOB
 *  The structure of the program is done: setup(), loop() and the
 *  function names are all here. The BODIES of three functions are
 *  missing. Each one is marked  TODO  and explains what it must do.
 *
 *    TODO 1  measureDistanceCm()   - fire the sensor and return a distance
 *    TODO 2  isEnemyDetected()     - decide if a target is a threat
 *    TODO 3  setAlarm()            - switch the warning LED on/off
 *
 *  The sketch compiles as it is (the functions return placeholder values),
 *  so you can Verify at any time. Implement one function at a time and
 *  check the Serial Monitor (9600 baud) after each.
 *
 *  Then carry on improving it: see the CHALLENGES at the bottom.
 *
 *  USEFUL FUNCTIONS (see the Function Reference in the handout)
 *    digitalWrite(), delayMicroseconds(), pulseIn(), Serial.print()
 *
 *  WIRING
 *    HC-SR04 VCC  -> 5V          HC-SR04 TRIG -> pin 11
 *    HC-SR04 GND  -> GND         HC-SR04 ECHO -> pin 10
 *    LED (+ 220-330 ohm resistor) -> pin 13 -> GND
 * =====================================================================
 */


// ------------------------------- Pins --------------------------------
const int TRIG_PIN = 11;
const int ECHO_PIN = 10;
const int LED_PIN  = 13;

// ----------------------------- Settings ------------------------------
const float ALERT_DISTANCE_CM = 20.0;     // alarm threshold
const unsigned long ECHO_TIMEOUT_US = 30000UL;  // ~5 m max range; stops pulseIn freezing
const unsigned long SCAN_INTERVAL_MS = 200;     // time between scans

// Physics: speed of sound = 343 m/s = 0.0343 cm per microsecond
const float SPEED_OF_SOUND_CM_PER_US = 0.0343;


// ======================================================================
//  TODO 1: measureDistanceCm()
// ----------------------------------------------------------------------
//  Fire ONE ultrasonic ping and return the distance to the target in cm.
//
//  Steps:
//    a) Make sure TRIG is LOW for 2 us (a clean start).
//    b) Set TRIG HIGH for 10 us, then LOW again. This fires the ping.
//    c) Use pulseIn() on ECHO_PIN to measure how long ECHO stays HIGH
//       (in microseconds). Pass ECHO_TIMEOUT_US as the timeout.
//    d) If pulseIn() returned 0, there was no echo: return -1.
//    e) Otherwise convert the time to distance and return it.
//       Remember the sound travels there AND back.
//
//  Returns: distance in cm, or -1 if nothing is in range.
// ======================================================================
float measureDistanceCm() {
  // TODO 1: write your code here

  return -1;   // placeholder - replace this
}


// ======================================================================
//  TODO 2: isEnemyDetected(distanceCm)
// ----------------------------------------------------------------------
//  Decide whether the measured distance means an enemy is too close.
//
//  Return true if:
//    - the reading is valid (not -1, i.e. greater than 0), AND
//    - it is closer than ALERT_DISTANCE_CM.
//  Otherwise return false.
//
//  Hint: this can be done in one line using && ("and").
// ======================================================================
bool isEnemyDetected(float distanceCm) {
  // TODO 2: write your code here

  return false;   // placeholder - replace this
}


// ======================================================================
//  TODO 3: setAlarm(alarmOn)
// ----------------------------------------------------------------------
//  Turn the warning LED on if alarmOn is true, off if it is false.
//
//  Extra: only print "ALERT" to the Serial Monitor when the alarm
//  CHANGES from off to on, not on every scan. (Hint: a static variable
//  inside the function remembers its value between calls.)
// ======================================================================
void setAlarm(bool alarmOn) {
  // TODO 3: write your code here

}


// ======================================================================
//  printReading()  - already done for you
//  Prints one line to the Serial Monitor, e.g.  "Distance: 42.7 cm"
// ======================================================================
void printReading(float distanceCm) {
  if (distanceCm < 0) {
    Serial.println("Distance: out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distanceCm, 1);   // 1 decimal place
    Serial.println(" cm");
  }
}


// ======================================================================
//  setup() - already done for you
// ======================================================================
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);

  Serial.println("Radar online. Scanning for enemy vehicles...");
}


// ======================================================================
//  loop() - already done for you
//  Measure -> report -> decide -> alert -> wait -> repeat
// ======================================================================
void loop() {
  float distanceCm = measureDistanceCm();
  printReading(distanceCm);

  bool enemy = isEnemyDetected(distanceCm);
  setAlarm(enemy);

  delay(SCAN_INTERVAL_MS);
}


/*
 * =====================================================================
 *  CHALLENGES - once the three TODOs work, iterate on your radar
 * =====================================================================
 *  1. ACCURACY: compare readings to a ruler at 10, 20, 50 and 100 cm.
 *     Is there a constant offset? Add a calibration correction.
 *
 *  2. NOISE: take 5 readings and return the average (or better, the
 *     median) to reject glitches.
 *
 *  3. THREAT LEVELS: add a second LED (or an RGB LED) for
 *       green  = clear,  amber = approaching (< 50 cm),  red = danger.
 *
 *  4. BUZZER: add a piezo buzzer with tone() that beeps faster as the
 *     target gets closer, like a car parking sensor. (Try map().)
 *
 *  5. NON-BLOCKING: replace delay() with millis() so the LED can flash
 *     while the radar keeps scanning.
 *
 *  6. SPEED: store the previous distance and time, and work out how
 *     fast the enemy is approaching in cm/s. Is it coming or going?
 *
 *  7. PLOTTING: print just the number and open Tools > Serial Plotter
 *     to see a live graph.
 * =====================================================================
 */
