from Crypto.Cipher import AES
import binascii
import sys
import time

count = int(sys.argv[1])

key = binascii.unhexlify('000102030405060708090a0b0c0d0e0f')
IV = binascii.unhexlify('00000000000000000000000000000000')
enc = AES.new(key, AES.MODE_CBC, IV=IV)
text = binascii.unhexlify('00010203040506070809000102030405')

start = time.clock()
for i in range(count):
        ciphertext = enc.encrypt(text)

end = time.clock()

#print(binascii.hexlify(ciphertext))
elapsed = end - start
print('Elapsed time:', elapsed * 1000.0, ' ms')

