#include <cpctelera.h>
#include <enums.h>
#include <man/BoardManager.h>
#include <man/GameManager.h>
#include <man/LetterManager.h>
#include <man/SecretManager.h>
#include <man/WordManager.h>
#include <sprites/letter_box_sprites.h>
#include <sys/InputSystem.h>
#include <sys/PlaySystem.h>
#include <sys/RenderSystem.h>

void initialize() {
    cpct_disableFirmware();
    cpct_setVideoMode(0);
    cpct_setPalette(g_palette, 16);
    cpct_setBorder(HW_BRIGHT_WHITE);
}

int main(void) {
    initialize();

    man_secret_init();
    man_letter_init();
    man_word_init();
    man_board_init();
    man_game_init();
    sys_input_init();
    sys_render_init();
    sys_play_init();

    sys_render_renderHeader();

    // initial render
    sys_render_initialRender();

    sys_render_eraseFooter();

    // start playing
    sys_play_initPlay();
}