#include <cpctelera.h>
#include <stdlib.h>

#define PRNG_MAX 841       // modulus: 840+1 == 29^2
#define PRNG_MULTIPLIER 30 // multiplier: 29+1
u16 prng_c;                // increment: 0 < c < max, c != 29

// Mixed Congruential Generator with modulus NUM_OF_WORDS+1
// Use a pre-seeded rand function to get the incremental value and the start value
u16 prngInit() {
    prng_c = rand() % PRNG_MAX;
    if (prng_c == 29 || prng_c == 0) {
        // This ensures that mcd(c,m)=1
        ++prng_c; 
    }

    return rand() % PRNG_MAX; // start value: 0 <= start < max
}

u16 prng(u16 x) __z88dk_fastcall {
    return (PRNG_MULTIPLIER * x + prng_c) % PRNG_MAX;
}