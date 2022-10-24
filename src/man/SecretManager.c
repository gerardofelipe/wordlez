#include <cmp/TSecret.h>
#include <cpctelera.h>
#include <data/secretWordPool.h>
#include <enums.h>
#include <man/SecretManager.h>
#include <stdbool.h>
#include <utils/cpc.h>

struct TSecret secret;

void man_secret_init() {
}

struct TSecret *man_secret_getSecret() {
    return &secret;
}

void man_secret_initSecret(struct TSecret *self, u16 index) {
    self->index = index;
    cpct_memcpy(self->word, secretWordPool + index, LETTERS_PER_WORD);
}

u16 man_secret_getIndex(struct TSecret *self) __z88dk_fastcall {
    return self->index;
}

struct TSecretWord *man_secret_getSecretWord(struct TSecret *self) __z88dk_fastcall {
    return (struct TSecretWord *)(self->word);
}

u16 man_secret_getNextPooIndex(struct TSecret *self) __z88dk_fastcall {
    u16 nextIndex = self->index + 1;
    return nextIndex == SECRET_WORDS_COUNT ? 0 : nextIndex;
}

void man_secret_moveToNextSecret(struct TSecret *self) __z88dk_fastcall {
    u16 nextIndex = man_secret_getNextPooIndex(self);
    man_secret_initSecret(self, nextIndex);
}

u16 man_secret_getRandomPoolIndex() {
    return getRandom16Index(SECRET_WORDS_COUNT);
}