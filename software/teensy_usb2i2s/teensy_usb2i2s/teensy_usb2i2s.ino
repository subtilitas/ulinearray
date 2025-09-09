#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputUSB            usb1;           //xy=300,478
AudioAmplifier           amp2;           //xy=488,457
AudioAmplifier           amp1;           //xy=514,289
AudioOutputI2S2          i2s2_1;         //xy=641,448
AudioOutputI2S           i2s1;           //xy=747,243
AudioConnection          patchCord1(usb1, 0, amp1, 0);
AudioConnection          patchCord2(usb1, 1, amp2, 0);
AudioConnection          patchCord4(amp2, 0, i2s2_1, 1);
AudioConnection          patchCord6(amp1, 0, i2s1, 1);
// GUItool: end automatically generated code

float volume_read;

void setup() {
  Serial.begin(115200);
AudioMemory(200);
volume_read = 0.0;
amp1.gain(volume_read);
amp2.gain(volume_read);
}

void loop() {
  // put your main code here, to run repeatedly:
volume_read = usb1.volume();
Serial.println(volume_read);
amp1.gain(volume_read);
amp2.gain(volume_read);
}
