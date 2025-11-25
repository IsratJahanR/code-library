import random


class RSA:
    def __init__(self, p, q):
        self.p = p
        self.q = q
        self.n = p * q
        self.phi = (p - 1) * (q - 1)
        self.e, self.d = self._generate_keys()

    # Euclidean GCD
    def _gcd(self, a, b):
        while b != 0:
            a, b = b, a % b
        return a

    # Extended Euclidean Algorithm 
    def _extended_gcd(self, a, b):
        if b == 0:
            return a, 1, 0
        gcd_, x1, y1 = self._extended_gcd(b, a % b)
        x, y = y1, x1 - (a // b) * y1
        return gcd_, x, y

    # Modular Inverse
    def _mod_inverse(self, e, phi):
        gcd_, x, _ = self._extended_gcd(e, phi)
        if gcd_ != 1:
            raise Exception("Modular inverse does not exist.")
        return x % phi

    # Key Generation 
    def _generate_keys(self):
        e = random.randrange(2, self.phi)
        while self._gcd(e, self.phi) != 1:
            e = random.randrange(2, self.phi)
        d = self._mod_inverse(e, self.phi)
        return e, d

    # Public / Private Keys 
    def get_public_key(self):
        return (self.e, self.n)

    def get_private_key(self):
        return (self.d, self.n)

    # Encryption 
    def encrypt(self, message):
        e, n = self.get_public_key()
        if not isinstance(message, int):
            raise ValueError("Message must be a number.")
        if message >= n:
            raise ValueError(f"Message {message} must be smaller than n = {n}.")
        return pow(message, e, n)

    # Decryption
    def decrypt(self, ciphertext):
        d, n = self.get_private_key()
        return pow(ciphertext, d, n)


# check if a number is prime
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

# asking for p and q until  message < n.
def get_primes_for_message(message):
   
    while True:
        try:
            p = int(input("Enter first prime number (p): "))
            q = int(input("Enter second prime number (q): "))

            if not (is_prime(p) and is_prime(q)):
                print("Both numbers must be prime. Try again.\n")
                continue
            if p == q:
                print("p and q must be different primes.\n")
                continue

            n = p * q
            if n <= message:
                print(f"n = {n} is too small for message {message}. which must be n > message.")
                print("Please choose larger prime numbers.\n")
                continue

            return p, q
        except ValueError:
            print("Invalid input. Please enter integer values only.\n")


# --- Main Program ---
if __name__ == "__main__":
    print("RSA Algorithm - Implemented by Nadia Thonu\n")

    # Step 1: Take message first
    while True:
        try:
            message = int(input("Enter the numeric message to encrypt: "))
            if message < 0:
                print("Message must be a non-negative integer.\n")
                continue
            break
        except ValueError:
            print("Invalid input. Please enter an integer value.\n")

    # Step 2: Choose primes ensuring n > message
    p, q = get_primes_for_message(message)
    rsa = RSA(p, q)

    print("\nValid primes accepted!")
    print("Public Key :", rsa.get_public_key())
    print("Private Key:", rsa.get_private_key())

    # Step 3: Encrypt and Decrypt
    encrypted = rsa.encrypt(message)
    print("\nEncrypted Message:", encrypted)

    decrypted = rsa.decrypt(encrypted)
    print("Decrypted Message:", decrypted)
