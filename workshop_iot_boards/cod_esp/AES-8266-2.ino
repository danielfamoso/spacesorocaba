#include <AES.h>
//#include "./print.h"

AES aes ;

byte *key = (unsigned char*)"0123456789abcdef";

byte plain[] = "0123456789012345";

//real iv = iv x2 ex: 01234567 = 0123456701234567
unsigned long long int my_iv = 36753562;

void setup ()
{
  Serial.begin (57600) ;
  //print_begin();
  delay(500);
  Serial.print("\n===testng mode\n") ;
  
//  otfly_test () ;
//  otfly_test256 () ;
}

void loop () 
{
  prekey_test () ;
  delay(2000);
}

void prekey (int bits, int itera)
{
  int i;
  aes.iv_inc();
  byte iv [N_BLOCK] ;
  byte plain_p[48];
  byte cipher [48] ;
  byte check [48] ;
  unsigned long ms = millis ();
  aes.set_IV(my_iv);
  aes.get_IV(iv);
  for (i=0;i<itera;i++) {
    aes.do_aes_encrypt(plain,41,cipher,key,bits,iv);
  }
  //aes.do_aes_encrypt(plain,41,cipher,key,bits,iv);
  Serial.print("Encryption took: ");
  Serial.println(millis() - ms);
  ms = millis ();
  aes.set_IV(my_iv);
  aes.get_IV(iv);
  for (i=0;i<itera;i++){
    aes.do_aes_decrypt(cipher,48,check,key,bits,iv);
  }
  //aes.do_aes_decrypt(cipher,48,check,key,bits,iv);
  
  Serial.print("Decryption took: ");
  Serial.println(millis() - ms);
  Serial.print("\n\nPLAIN :");
  aes.printArray(plain,(bool)true);
  Serial.print("\nCIPHER:");
  aes.printArray(cipher,(bool)false);
  Serial.print("\nCHECK :");
  aes.printArray(check,(bool)true);
  Serial.print("\nIV    :");
  aes.printArray(iv,16);
  Serial.print("\n============================================================\n");
}

void prekey_test ()
{
  prekey (128, 2000) ;
//  prekey (128, 2000) ;
//  prekey (128, 3000) ;
}
