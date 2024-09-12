#include "include_asset.h"

#if VERSION_JP
INCLUDE_RAW("charset/kana.dat", charset_kana_OFFSET);
INCLUDE_RAW("charset/latin.dat", charset_latin_OFFSET);
INCLUDE_RAW("charset/kanji.dat", charset_kanji_OFFSET);
INCLUDE_RAW("charset/buttons.dat", charset_buttons_OFFSET);
INCLUDE_RAW("charset/menu_kana.dat", charset_menu_kana_OFFSET);
INCLUDE_RAW("charset/menu_latin.dat", charset_menu_latin_OFFSET);
#else
INCLUDE_RAW("charset/standard.dat", charset_standard_OFFSET);
#endif

INCLUDE_RAW("charset/standard/palette.dat", charset_standard_pal_OFFSET);
INCLUDE_RAW("charset/title.dat", charset_title_OFFSET);
INCLUDE_RAW("charset/subtitle.dat", charset_subtitle_OFFSET);
#if VERSION_IQUE
static int padding[] = {0, 0, 0, 0, 0, 0};
#endif
INCLUDE_RAW("charset/subtitle/palette.dat", charset_subtitle_pal_OFFSET);
INCLUDE_RAW("charset/title/palette.dat", charset_title_pal_OFFSET);

INCLUDE_IMG("charset/peach_letter.png", charset_peach_letter_OFFSET);
INCLUDE_PAL("charset/peach_letter.pal", charset_peach_letter_pal_OFFSET);

INCLUDE_IMG("charset/postcard.png", charset_postcard_OFFSET);
INCLUDE_PAL("charset/postcard.pal", charset_postcard_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_1.png", charset_letter_content_1_OFFSET);
INCLUDE_PAL("charset/letter_content_1.pal", charset_letter_content_1_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_2.png", charset_letter_content_2_OFFSET);
INCLUDE_PAL("charset/letter_content_2.pal", charset_letter_content_2_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_3.png", charset_letter_content_3_OFFSET);
INCLUDE_PAL("charset/letter_content_3.pal", charset_letter_content_3_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_4.png", charset_letter_content_4_OFFSET);
INCLUDE_PAL("charset/letter_content_4.pal", charset_letter_content_4_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_5.png", charset_letter_content_5_OFFSET);
INCLUDE_PAL("charset/letter_content_5.pal", charset_letter_content_5_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_6.png", charset_letter_content_6_OFFSET);
INCLUDE_PAL("charset/letter_content_6.pal", charset_letter_content_6_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_7.png", charset_letter_content_7_OFFSET);
INCLUDE_PAL("charset/letter_content_7.pal", charset_letter_content_7_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_8.png", charset_letter_content_8_OFFSET);
INCLUDE_PAL("charset/letter_content_8.pal", charset_letter_content_8_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_9.png", charset_letter_content_9_OFFSET);
INCLUDE_PAL("charset/letter_content_9.pal", charset_letter_content_9_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_10.png", charset_letter_content_10_OFFSET);
INCLUDE_PAL("charset/letter_content_10.pal", charset_letter_content_10_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_11.png", charset_letter_content_11_OFFSET);
INCLUDE_PAL("charset/letter_content_11.pal", charset_letter_content_11_pal_OFFSET);

INCLUDE_IMG("charset/letter_content_12.png", charset_letter_content_12_OFFSET);
INCLUDE_PAL("charset/letter_content_12.pal", charset_letter_content_12_pal_OFFSET);

#if VERSION_US || VERSION_PAL
static int padding2[] = {0, 0};
#endif

int something = 0x03E00008;
