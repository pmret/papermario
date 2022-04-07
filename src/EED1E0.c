#include "dead.h"
#include "common.h"

// Copy of flo_16 (CD1F10.c)

#define NAMESPACE EED1E0

#define gPartnerActionStatus dead_gPartnerActionStatus2
#define entity_upgrade_block_hide_content dead_entity_upgrade_block_hide_content

#define create_popup_menu dead_create_popup_menu
#define hide_popup_menu dead_hide_popup_menu
#define destroy_popup_menu dead_destroy_popup_menu
#define heap_free dead_heap_free
#define wPartnerHudScripts D_80100060
#define wDisabledPartnerHudScripts D_801000A0

#include "world/common/atomic/SuperBlock.inc.c"

#include "world/common/UnkFunc44.inc.c"
