.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E13B8
/* 102C38 802E13B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 102C3C 802E13BC AFB00010 */  sw        $s0, 0x10($sp)
/* 102C40 802E13C0 0080802D */  daddu     $s0, $a0, $zero
/* 102C44 802E13C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 102C48 802E13C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 102C4C 802E13CC 0C0B8DB9 */  jal       entity_init_Hammer23Block_normal
/* 102C50 802E13D0 8E110040 */   lw       $s1, 0x40($s0)
/* 102C54 802E13D4 3C02802E */  lui       $v0, 0x802e
/* 102C58 802E13D8 24420DE0 */  addiu     $v0, $v0, 0xde0
/* 102C5C 802E13DC AE02003C */  sw        $v0, 0x3c($s0)
/* 102C60 802E13E0 24020008 */  addiu     $v0, $zero, 8
/* 102C64 802E13E4 A6220004 */  sh        $v0, 4($s1)
/* 102C68 802E13E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 102C6C 802E13EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 102C70 802E13F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 102C74 802E13F4 03E00008 */  jr        $ra
/* 102C78 802E13F8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 102C7C 802E13FC 00000000 */  nop       
