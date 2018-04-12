#include <aes_sbox.h>
#include <aes192_dec.h>
#include <aes_invsbox.h>
#include <aes256_dec.h>
#include <aes_types.h>
#include <bcal_aes128.h>
#include <aes_enc.h>
#include <AESLib.h>
#include <aes128_enc.h>
#include <bcal-cmac.h>
#include <bcal-basic.h>
#include <gf256mul.h>
#include <bcal-ofb.h>
#include <keysize_descriptor.h>
#include <blockcipher_descriptor.h>
#include <aes_dec.h>
#include <memxor.h>
#include <aes256_enc.h>
#include <aes.h>
#include <aes128_dec.h>
#include <aes192_enc.h>
#include <bcal_aes192.h>
#include <aes_keyschedule.h>
#include <bcal-cbc.h>
#include <bcal_aes256.h>

/* Instalar .zip da biblioteca AES-128 */
#include <aes128_enc.h>
#include <aes128_dec.h>


void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}


void aes128_enc_single(const uint8_t* key, void* data);
void aes128_dec_single(const uint8_t* key, void* data);
uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
char data[] = "0123456789012345"; //16 chars == 16 bytes

unsigned long tempo;
unsigned long i=0;

void criptografia(unsigned long n) {
  
  tempo=millis();
  
  for (i=0;i<n;i++)
  {
    aes128_enc_single(key, data);
  }
  
  tempo=millis()-tempo;

  Serial.print("Numero de vezes: ");
  Serial.println(n);
  Serial.print("encrypted:");
  Serial.println(data);
  Serial.print("tempo de criptografia: ");
  Serial.println(tempo);

  tempo=millis();
      
  for (i=0;i<n;i++)
  {
    aes128_dec_single(key, data);
  }
  
  tempo=millis()-tempo;
  Serial.print("decrypted:");
  Serial.println(data);
  Serial.print("tempo de descriptografia: ");
  Serial.println(tempo);
  Serial.println();
  Serial.println();
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  criptografia(1000);
  criptografia(2000);
  criptografia(3000);

  
}
