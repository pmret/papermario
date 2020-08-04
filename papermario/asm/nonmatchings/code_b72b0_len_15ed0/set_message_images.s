.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_message_images
/* 0BC22C 80125B2C 3C018015 */  lui   $at, 0x8015
/* 0BC230 80125B30 AC2412F4 */  sw    $a0, 0x12f4($at)
/* 0BC234 80125B34 03E00008 */  jr    $ra
/* 0BC238 80125B38 00000000 */   nop   

