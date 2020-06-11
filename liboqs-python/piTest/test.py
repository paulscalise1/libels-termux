import oqs
import random
import base64

message = bytes(random.getrandbits(8) for _ in range (100))
sig = oqs.Signature("DILITHIUM_3")
publicKey = sig.generate_keypair()
privateKey = sig.export_secret_key()

##print ("Printing algorithms")
##print (oqs._enabled_sigs)

##print ("current algorithm")
##print (oqs.alg_name)

##print (publicKey)
##print ()
##print (privateKey)

##with open("Pkey.key", 'wb') as out:
##    out.write(privateKey)

##trying to decode text 
encryptedText = base64.b64decode(privateKey)
print (encryptedText)