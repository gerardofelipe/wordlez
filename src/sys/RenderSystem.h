#ifndef _SYS_RENDER_SYSTEM_H_
#define _SYS_RENDER_SYSTEM_H_

#include <cmp/TWord.h>
#include <cpctelera.h>

void sys_render_init();

void sys_render_initialRender();

void sys_render_initialRenderWord(struct TWord *word) __z88dk_fastcall;

void sys_render_initialRenderLetter(struct TLetter *letter) __z88dk_fastcall;

void sys_render_initialRenderLetterByFrame(struct TLetter *letter, u8 frame);

void sys_render_renderCurrentWord();

void sys_render_updateLetterCharacter(struct TLetter *letter) __z88dk_fastcall;

void sys_render_renderLetter(struct TLetter *letter, u8 color, u16 rplcPat);

void sys_render_renderWord(struct TWord *word) __z88dk_fastcall;

void sys_render_renderHeader();

void sys_render_renderWin();

void sys_render_renderLose();

#endif