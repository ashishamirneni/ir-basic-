#include <IRremote.h>

const int RECV_PIN = 15; // IR receiver pin (GPIO 15 on ESP32)

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  Serial.begin(115200); // Start serial communication at 115200 baud rate
  while (!Serial) { // Wait for serial monitor to open (useful for debugging)
    delay(50);
  }
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("IR Receiver is ready! Point your remote at the receiver and press buttons.");
}

void loop() {
  if (irrecv.decode(&results)) { // Check if IR signal is received
    Serial.print("IR Code Received: 0x");
    Serial.println(results.value, HEX); // Print the received code in HEX
    Serial.print("Bits: ");
    Serial.println(results.bits); // Print number of bits
    Serial.print("Protocol: ");
    
    // Print the protocol type
    switch (results.decode_type) {
      case NEC: Serial.println("NEC"); break;
      case SONY: Serial.println("SONY"); break;
      case RC5: Serial.println("RC5"); break;
      case RC6: Serial.println("RC6"); break;
      case UNKNOWN: Serial.println("UNKNOWN"); break;
      default: Serial.println("Other"); break;
    }

    irrecv.resume(); // Receive the next value
  }
  delay(100); // Small delay to prevent overwhelming the serial monitor
}