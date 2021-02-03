.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802185D4_5CEC64
/* 5CEC64 802185D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5CEC68 802185D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CEC6C 802185DC 0080802D */  daddu     $s0, $a0, $zero
/* 5CEC70 802185E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 5CEC74 802185E4 0C09A75B */  jal       get_actor
/* 5CEC78 802185E8 8E040148 */   lw       $a0, 0x148($s0)
/* 5CEC7C 802185EC 804201F1 */  lb        $v0, 0x1f1($v0)
/* 5CEC80 802185F0 3C018022 */  lui       $at, %hi(D_8021A35C_5D09EC)
/* 5CEC84 802185F4 AC22A35C */  sw        $v0, %lo(D_8021A35C_5D09EC)($at)
/* 5CEC88 802185F8 0C09A75B */  jal       get_actor
/* 5CEC8C 802185FC 8E040148 */   lw       $a0, 0x148($s0)
/* 5CEC90 80218600 804301F1 */  lb        $v1, 0x1f1($v0)
/* 5CEC94 80218604 8FBF0014 */  lw        $ra, 0x14($sp)
/* 5CEC98 80218608 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CEC9C 8021860C 24020002 */  addiu     $v0, $zero, 2
/* 5CECA0 80218610 3C018022 */  lui       $at, %hi(D_8021A378_5D0A08)
/* 5CECA4 80218614 AC23A378 */  sw        $v1, %lo(D_8021A378_5D0A08)($at)
/* 5CECA8 80218618 03E00008 */  jr        $ra
/* 5CECAC 8021861C 27BD0018 */   addiu    $sp, $sp, 0x18
