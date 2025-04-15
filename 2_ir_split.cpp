#include <IRremote.h>

// Define the GPIO pin your IR receiver's OUT is connected to
#define IR_RECEIVE_PIN 15

void setup() {
  Serial.begin(115200);  // Start Serial monitor at 115200 baud
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the IR receiver
  Serial.println("IR Receiver ready to decode signals...");
}

void loop() {
  // Check if an IR signal has been received
  if (IrReceiver.decode()) {
    Serial.print("Received IR code: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print code in HEX

    // Optionally, print the full protocol details:
    IrReceiver.printIRResultShort(&Serial);

    IrReceiver.resume(); // Prepare to receive the next value
  }
}
