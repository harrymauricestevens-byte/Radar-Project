/*
 * =====================================================================
 *  MINI RADAR  -  BEGINNER VERSION
 *  Elecsoc Radar Project, Session 0
 * =====================================================================
 *
 *  YOUR MISSION
 *  An enemy vehicle is approaching the base. Build a radar that measures
 *  how far away it is and switches on a warning LED to alert the defence
 *  personnel when it gets too close.
 *
 *  YOUR JOB
 *  All the code is written for you, but some values are missing. Every
 *  missing value is shown as  ___  (three underscores) and has a number,
 *  like  [BLANK 1].
 *
 *  Replace each  ___  with the correct value. Use the hints in the
 *  comments, the wiring diagram in the handout and the Function Reference.
 *  Until every blank is filled in, the code will NOT compile. That's
 *  normal: the error tells you which blank you missed.
 *
 *  HOW TO RUN IT
 *   1. Fill in all the blanks.
 *   2. Click the tick (Verify) button. Fix any errors.
 *   3. Plug in the Arduino. Choose Tools > Board > Arduino Uno and
 *      Tools > Port.
 *   4. Click the arrow (Upload) button.
 *   5. Open Tools > Serial Monitor to see the distance readings.
 *
 *  WIRING (see the diagram in the handout)
 *    HC-SR04 VCC  -> 5V
 *    HC-SR04 TRIG -> pin 11
 *    HC-SR04 ECHO -> pin 10
 *    HC-SR04 GND  -> GND
 *    LED (+ resistor) -> pin 13, other leg to GND
 * =====================================================================
 */


// ---------------------------------------------------------------------
//  PIN NUMBERS
//  These tell the Arduino which pin each wire is plugged into.
//  Look at the wiring list above.
// ---------------------------------------------------------------------
const int TRIG_PIN = ___;   // [BLANK 1] Which pin is the sensor's TRIG wire on?
const int ECHO_PIN = ___;   // [BLANK 2] Which pin is the sensor's ECHO wire on?
const int LED_PIN  = ___;   // [BLANK 3] Which pin is the warning LED on?


// ---------------------------------------------------------------------
//  SETTINGS - once it works, try changing these!
// ---------------------------------------------------------------------

// How close (in cm) the enemy can get before the alarm goes off.
const float ALERT_DISTANCE_CM = ___;   // [BLANK 4] Pick a distance, e.g. 20


// =====================================================================
//  setup() runs ONCE when the Arduino turns on
// =====================================================================
void setup() {
  // Start talking to the computer so we can see readings in the
  // Serial Monitor. The number is the speed (the "baud rate").
  // The Serial Monitor must be set to the same number (bottom right).
  Serial.begin(___);           // [BLANK 5] The usual speed is 9600

  // Tell the Arduino which pins SEND signals (OUTPUT)
  // and which pins RECEIVE signals (INPUT).
  pinMode(TRIG_PIN, OUTPUT);   // TRIG sends the "ping" command to the sensor
  pinMode(ECHO_PIN, ___);      // [BLANK 6] ECHO receives the reply. INPUT or OUTPUT?
  pinMode(LED_PIN, OUTPUT);    // The Arduino switches the LED on and off

  Serial.println("Radar online. Scanning for enemy vehicles...");
}


// =====================================================================
//  loop() runs FOREVER, over and over again
// =====================================================================
void loop() {

  // ---- STEP 1: Send a "ping" ----------------------------------------
  // The sensor fires a burst of sound when TRIG goes HIGH for a
  // short time. First we make sure TRIG starts LOW (off).
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Now turn TRIG on for a short pulse, then off again.
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(___);      // [BLANK 7] The HC-SR04 needs a 10 microsecond pulse
  digitalWrite(TRIG_PIN, LOW);


  // ---- STEP 2: Listen for the echo ----------------------------------
  // pulseIn() measures how long (in microseconds) the ECHO pin stays
  // HIGH. That is how long the sound took to travel there AND back.
  // The last number is a timeout: if no echo comes back within
  // 30000 microseconds, it gives up and returns 0.
  unsigned long echoTime = pulseIn(ECHO_PIN, HIGH, 30000UL);


  // ---- STEP 3: Work out the distance --------------------------------
  // Sound travels at about 343 metres per second,
  // which is 0.0343 centimetres per microsecond.
  //
  //   distance = time x speed of sound / 2
  //
  // We divide by 2 because the sound goes TO the enemy and BACK.
  float distanceCm = echoTime * ___ / ___;   // [BLANK 8] speed of sound (cm per microsecond)
                                             // [BLANK 9] divide by what?


  // ---- STEP 4: Report the distance ----------------------------------
  if (echoTime == 0) {
    // No echo came back, so nothing is in range.
    Serial.println("No target in range");
  } else {
    Serial.print("Target distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  }


  // ---- STEP 5: Raise the alarm! -------------------------------------
  // If something is in range AND closer than our alert distance,
  // turn the LED on. Otherwise, turn it off.
  if (echoTime != 0 && distanceCm < ALERT_DISTANCE_CM) {
    digitalWrite(LED_PIN, ___);    // [BLANK 10] HIGH = on, LOW = off. Which one?
    Serial.println("!!! ENEMY VEHICLE DETECTED - ALERT !!!");
  } else {
    digitalWrite(LED_PIN, ___);    // [BLANK 11] Which one turns the LED off?
  }


  // ---- STEP 6: Wait a moment, then scan again ------------------------
  delay(___);   // [BLANK 12] Time between scans in milliseconds.
                //            Try 200. (1000 ms = 1 second)
}


/*
 * =====================================================================
 *  FINISHED EARLY? TRY THESE
 * =====================================================================
 *  1. Measure a book with a ruler and with your radar. How close are they?
 *  2. Change ALERT_DISTANCE_CM. What happens?
 *  3. Change the delay in STEP 6. What happens to the readings?
 *  4. Make the LED FLASH when an enemy is detected instead of staying on.
 *     (Hint: turn it on, delay, turn it off, delay.)
 *  5. Ready for more? Ask Harry for the Intermediate version!
 * =====================================================================
 */
