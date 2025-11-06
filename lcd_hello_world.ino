// LCD "Hello, World!" with Adjustable Contrast
// Description: Displays "Hello, World!" on a 16x2 LCD and allows real-time contrast
//               control using a 10k potentiometer connected to the contrast pin (V0).

#include <LiquidCrystal.h>

// LCD pin configuration (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define potPin A0 // Analog pin connected to potentiometer (for monitoring)

void setup() {
  lcd.begin(16, 2);   // Initialize 16x2 LCD
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!"); // Print main text
  delay(500);
}

void loop() {
  // Read potentiometer value for monitoring (0–1023)
  int potValue = analogRead(potPin);
  float voltage = potValue * (5.0 / 1023.0); // Convert to voltage (0–5V)

  // Display live voltage feedback (for demo purpose)
  lcd.setCursor(0, 1);
  lcd.print("V0: ");
  lcd.print(voltage, 2);
  lcd.print("V    "); // clear trailing chars

  delay(50); // Smooth 50 ms refresh rate
}
