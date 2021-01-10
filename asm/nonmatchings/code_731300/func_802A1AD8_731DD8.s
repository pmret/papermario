.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1AD8_731DD8
/* 731DD8 802A1AD8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 731DDC 802A1ADC 2405000B */  addiu     $a1, $zero, 0xb
/* 731DE0 802A1AE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 731DE4 802A1AE4 3C10800E */  lui       $s0, %hi(gBattleStatus+0xD8)
/* 731DE8 802A1AE8 8E10C148 */  lw        $s0, %lo(gBattleStatus+0xD8)($s0)
/* 731DEC 802A1AEC 24060003 */  addiu     $a2, $zero, 3
/* 731DF0 802A1AF0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 731DF4 802A1AF4 0C0997D0 */  jal       inflict_status
/* 731DF8 802A1AF8 0200202D */   daddu    $a0, $s0, $zero
/* 731DFC 802A1AFC A200021C */  sb        $zero, 0x21c($s0)
/* 731E00 802A1B00 8FBF0014 */  lw        $ra, 0x14($sp)
/* 731E04 802A1B04 8FB00010 */  lw        $s0, 0x10($sp)
/* 731E08 802A1B08 24020002 */  addiu     $v0, $zero, 2
/* 731E0C 802A1B0C 03E00008 */  jr        $ra
/* 731E10 802A1B10 27BD0018 */   addiu    $sp, $sp, 0x18
