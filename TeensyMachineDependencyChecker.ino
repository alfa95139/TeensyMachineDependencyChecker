
/*
//  machdep.c
//
//  Machine dependencies checker
//
//  (C) R.P.Bellis 1993
*/


  union {
    struct {
      uint8_t field1;
      uint8_t field2;
    } bytes;
    uint16_t  value;
  } tmpByte;

  union {
    struct {
      unsigned int  field1 : 1;
      unsigned int  dummys : 6;
      unsigned int  field2 : 1;
    } bits;
    unsigned int    value;
  } tmpBitfield;

void setup() {
  
  FILE    *f;
  char    *path;
  time_t    tp;

  Serial.begin(115200);

  while (!Serial);


  tmpBitfield.value = 0;
  tmpBitfield.bits.field1 = 1;

  if (tmpBitfield.value == 1) {
    Serial.printf("#define MACH_BITFIELDS_LSB_FIRST\n");
  } else {
    Serial.printf("#define MACH_BITFIELDS_MSB_FIRST\n");
  }

  
  tmpByte.value = 0;
  tmpByte.bytes.field1 = 1;

  if (tmpByte.value == 0x0001) {
    Serial.printf("#define MACH_BYTE_ORDER_LSB_FIRST\n");
  } else if (tmpByte.value == 0x0100) {
    Serial.printf("#define MACH_BYTE_ORDER_MSB_FIRST\n");
  } else {
    Serial.printf("Cannot determine byte order\n");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
