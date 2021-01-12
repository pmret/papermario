.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1B68_731E68
/* 731E68 802A1B68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 731E6C 802A1B6C 24050006 */  addiu     $a1, $zero, 6
/* 731E70 802A1B70 AFB00010 */  sw        $s0, 0x10($sp)
/* 731E74 802A1B74 3C10800E */  lui       $s0, %hi(gBattleStatus+0xD8)
/* 731E78 802A1B78 8E10C148 */  lw        $s0, %lo(gBattleStatus+0xD8)($s0)
/* 731E7C 802A1B7C 24060003 */  addiu     $a2, $zero, 3
/* 731E80 802A1B80 AFBF0014 */  sw        $ra, 0x14($sp)
/* 731E84 802A1B84 0C0997D0 */  jal       inflict_status
/* 731E88 802A1B88 0200202D */   daddu    $a0, $s0, $zero
/* 731E8C 802A1B8C A200021C */  sb        $zero, 0x21c($s0)
/* 731E90 802A1B90 8FBF0014 */  lw        $ra, 0x14($sp)
/* 731E94 802A1B94 8FB00010 */  lw        $s0, 0x10($sp)
/* 731E98 802A1B98 24020002 */  addiu     $v0, $zero, 2
/* 731E9C 802A1B9C 03E00008 */  jr        $ra
