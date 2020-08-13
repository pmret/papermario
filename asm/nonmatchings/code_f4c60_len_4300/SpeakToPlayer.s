.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SpeakToPlayer
/* 0F4C60 802D02B0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F4C64 802D02B4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F4C68 802D02B8 0C0B40C8 */  jal   _show_message
/* 0F4C6C 802D02BC 0000302D */   daddu $a2, $zero, $zero
/* 0F4C70 802D02C0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F4C74 802D02C4 03E00008 */  jr    $ra
/* 0F4C78 802D02C8 27BD0018 */   addiu $sp, $sp, 0x18

