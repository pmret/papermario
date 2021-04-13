.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802687BC
/* 19709C 802687BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1970A0 802687C0 24020002 */  addiu     $v0, $zero, 2
/* 1970A4 802687C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1970A8 802687C8 3C01802A */  lui       $at, %hi(D_8029FBC0)
/* 1970AC 802687CC AC22FBC0 */  sw        $v0, %lo(D_8029FBC0)($at)
/* 1970B0 802687D0 0C09A0A1 */  jal       func_80268284
/* 1970B4 802687D4 00000000 */   nop
/* 1970B8 802687D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1970BC 802687DC 03E00008 */  jr        $ra
/* 1970C0 802687E0 27BD0018 */   addiu    $sp, $sp, 0x18
