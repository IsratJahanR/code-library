import random


def simple_hash(M, q):
    h = 0
    for ch in M:
        h = (h * 31 + ord(ch)) % q
    return h


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def mod_exp(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result


def mod_inverse(a, mod):
    t1, t2 = 0, 1
    r1, r2 = mod, a
    while r2 > 0:
        q = r1 // r2
        r1, r2 = r2, r1 - q * r2
        t1, t2 = t2, t1 - q * t2
    if r1 != 1:
        return None
    return t1 % mod


class ElGamal:
    def __init__(self, q, alpha):
        self.q = q
        self.alpha = alpha
        self.Xa = random.randrange(q - 2) + 1
        self.Ya = mod_exp(alpha, self.Xa, q)

    def sign(self, M):
        m = simple_hash(M, self.q)
        while True:
            K = random.randrange(self.q - 2) + 1
            if gcd(K, self.q - 1) == 1:
                break
        S1 = mod_exp(self.alpha, K, self.q)
        K_inv = mod_inverse(K, self.q - 1)
        S2 = ((m - self.Xa * S1) * K_inv) % (self.q - 1)
        return (S1, S2)

    def verify(self, M, S1, S2):
        m = simple_hash(M, self.q)
        V1 = mod_exp(self.alpha, m, self.q)
        V2 = (mod_exp(self.Ya, S1, self.q) *
              mod_exp(S1, S2, self.q)) % self.q
        return V1 == V2


q = 19
alpha = 10
elg = ElGamal(q, alpha)

message = "HELLO"

print("ELGAMAL DIGITAL SIGNATURE by Nadia")
print(f"Prime q: {q}")
print(f"Primitive Root α: {alpha}")

print("\n--- KEY GENERATION ---")
print(f"Private Key Xa: {elg.Xa}")
print(f"Public Key Ya: {elg.Ya}")

print("\n--- MESSAGE ---")
print(f"Message: {message}")
print(f"Hashed m: {simple_hash(message, q)}")

print("\n--- SIGNING ---")
S1, S2 = elg.sign(message)
print(f"Signature S1: {S1}")
print(f"Signature S2: {S2}")
print(f"Signature Pair (S1, S2): ({S1}, {S2})")

print("\n--- VERIFICATION ---")
valid = elg.verify(message, S1, S2)
print(f"Verification Result: {'VALID' if valid else 'INVALID'}")


