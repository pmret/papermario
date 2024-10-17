#include "common.h"
#include "include_asset.h"

// TODO should move this in a header
typedef struct TitleMenuDataStruct {
    /* 0x0 */ IMG_BIN* startGame;
    /* 0x4 */ IMG_BIN* languages;
} TitleMenuDataStruct; // size = 0x8

extern IMG_BIN title_start_game_png[];
extern IMG_BIN title_languages_png[];
extern IMG_BIN title_start_game_de_png[];
extern IMG_BIN title_languages_de_png[];
extern IMG_BIN title_start_game_fr_png[];
extern IMG_BIN title_languages_fr_png[];
extern IMG_BIN title_start_game_es_png[];
extern IMG_BIN title_languages_es_png[];

TitleMenuDataStruct TitleMenuOffsets[] = {
    {
        .startGame = title_start_game_png,
        .languages = title_languages_png,
    },
    {
        .startGame = title_start_game_de_png,
        .languages = title_languages_de_png,
    },
    {
        .startGame = title_start_game_fr_png,
        .languages = title_languages_fr_png,
    },
    {
        .startGame = title_start_game_es_png,
        .languages = title_languages_es_png,
    },
};

Gfx titlemenu_pad_2596C0[] = { gsSPEndDisplayList(), };
INCLUDE_IMG("title/start_game.png", title_start_game_png);
Gfx titlemenu_pad_259CE8[] = { gsSPEndDisplayList(), };
INCLUDE_IMG("title/languages.png", title_languages_png);

Gfx titlemenu_pad_25A270[] = { gsSPEndDisplayList(), };
INCLUDE_IMG("de/title/start_game.png", title_start_game_de_png);
Gfx titlemenu_pad_25A7F8[] = { gsSPEndDisplayList(), };
INCLUDE_IMG("de/title/languages.png", title_languages_de_png);

Gfx titlemenu_pad_25AD00[] = { gsSPEndDisplayList(), };
INCLUDE_IMG("fr/title/start_game.png", title_start_game_fr_png);
Gfx titlemenu_pad_25B608[] = { gsSPEndDisplayList(), };
INCLUDE_IMG("fr/title/languages.png", title_languages_fr_png);

Gfx titlemenu_pad_25BA10[] = { gsSPEndDisplayList(), };
INCLUDE_IMG("es/title/start_game.png", title_start_game_es_png);
Gfx titlemenu_pad_25C198[] = { gsSPEndDisplayList(), };
INCLUDE_IMG("es/title/languages.png", title_languages_es_png);

