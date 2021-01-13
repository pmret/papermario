.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1270
/* 102AF0 802E1270 3C02802F */  lui       $v0, %hi(D_802EB390)
/* 102AF4 802E1274 8C42B390 */  lw        $v0, %lo(D_802EB390)($v0)
/* 102AF8 802E1278 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102AFC 802E127C 10400003 */  beqz      $v0, .L802E128C
/* 102B00 802E1280 AFBF0010 */   sw       $ra, 0x10($sp)
/* 102B04 802E1284 0C043F5A */  jal       func_8010FD68
/* 102B08 802E1288 00000000 */   nop
.L802E128C:
/* 102B0C 802E128C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 102B10 802E1290 03E00008 */  jr        $ra
/* 102B14 802E1294 27BD0018 */   addiu    $sp, $sp, 0x18
