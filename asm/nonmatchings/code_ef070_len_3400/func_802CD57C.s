.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD57C
/* F1F2C 802CD57C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* F1F30 802CD580 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* F1F34 802CD584 80420070 */  lb        $v0, 0x70($v0)
/* F1F38 802CD588 14400007 */  bnez      $v0, .L802CD5A8
/* F1F3C 802CD58C 00000000 */   nop      
/* F1F40 802CD590 3C02802E */  lui       $v0, 0x802e
/* F1F44 802CD594 2442ADF0 */  addiu     $v0, $v0, -0x5210
/* F1F48 802CD598 3C01802E */  lui       $at, 0x802e
/* F1F4C 802CD59C AC22AE30 */  sw        $v0, -0x51d0($at)
/* F1F50 802CD5A0 03E00008 */  jr        $ra
/* F1F54 802CD5A4 00000000 */   nop      
.L802CD5A8:
/* F1F58 802CD5A8 3C02802E */  lui       $v0, 0x802e
/* F1F5C 802CD5AC 2442ADB0 */  addiu     $v0, $v0, -0x5250
/* F1F60 802CD5B0 3C01802E */  lui       $at, 0x802e
/* F1F64 802CD5B4 AC22AE30 */  sw        $v0, -0x51d0($at)
/* F1F68 802CD5B8 03E00008 */  jr        $ra
/* F1F6C 802CD5BC 00000000 */   nop      
