#ifndef _CMP_SECRET_MANAGER_H_
#define _CMP_SECRET_MANAGER_H_

#include <cmp/TSecret.h>
#include <enums.h>
#include <stdbool.h>

void man_secret_init();

struct TSecret *man_secret_getSecret();

void man_secret_initSecret(struct TSecret *self, u16 index);

u16 man_secret_getIndex(struct TSecret *self) __z88dk_fastcall;

struct TSecretWord *man_secret_getSecretWord(struct TSecret *self) __z88dk_fastcall;

u16 man_secret_getNextPooIndex(struct TSecret *self) __z88dk_fastcall;

void man_secret_moveToNextSecret(struct TSecret *self) __z88dk_fastcall;

u16 man_secret_getRandomPoolIndex();

#endif
