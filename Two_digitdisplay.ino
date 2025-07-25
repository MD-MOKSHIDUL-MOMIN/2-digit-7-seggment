// Define the segment and digit pins(M M Momin)
const int segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // Segment pins A, B, C, D, E, F, G, DP
const int digitPins[] = {5, 4}; // Digit control pins

// Segment patterns for numbers 0-9 (common anode)
char arraCC[] = { 0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF };

void setup() {
  // Set segment pins as outputs
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], HIGH); // Turn off all segments (common anode)
  }
  
  // Set digit control pins as outputs
  for (int i = 0; i < 2; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH); // Turn off all digits (common anode)
  }
}

void loop() {
  for (int i = 0; i <= 99; i++) {
    int res = i / 10; // Calculate tens digit
    int mod = i % 10; // Calculate units digit

    // Display each digit for a brief delay
    for (int k = 0; k < 10; k++) {
      // Display tens digit
      digitalWrite(digitPins[0], LOW); // Activate tens digit
      displayNumber(arraCC[res]);
      delay(35);
      digitalWrite(digitPins[0], HIGH); // Deactivate tens digit

      // Display units digit
      digitalWrite(digitPins[1], LOW); // Activate units digit
      displayNumber(arraCC[mod]);
      delay(35);
      digitalWrite(digitPins[1], HIGH); // Deactivate units digit
    }
  }
}

void displayNumber(char num) {
  // Set segment states
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], (num & (1 << (7 - i))) ? HIGH : LOW); // Common anode: LOW to turn on segment
  }
}