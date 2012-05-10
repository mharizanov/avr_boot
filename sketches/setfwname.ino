#include <EEPROM.h>

void setup() {
  int i = 0;
  
  /* debug */
  Serial.begin(9600);

  /* this is the name you give to the board */
  char name[] = "test.bin";
  
  /* copy name to eeprom in the inverse        */
  /* order, as the bootloader is expecting it that way */
  while (name[i] && i<13) {
    EEPROM.write(E2END - i, name[i]);
    i++;
  }
  
  /* mark end */
  EEPROM.write(E2END - i, 0xFF);
  delay(2000);
  Serial.print("The board was given the name '");
  Serial.println(name);
}

void loop() {
  /* do nothing */
}
