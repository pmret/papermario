.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel dispatch_event_player
/* 19FF38 80271658 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19FF3C 8027165C 2405000A */  addiu $a1, $zero, 0xa
/* 19FF40 80271660 AFB00010 */  sw    $s0, 0x10($sp)
/* 19FF44 80271664 3C10800E */  lui   $s0, 0x800e
/* 19FF48 80271668 8E10C148 */  lw    $s0, -0x3eb8($s0)
/* 19FF4C 8027166C AFBF001C */  sw    $ra, 0x1c($sp)
/* 19FF50 80271670 AFB20018 */  sw    $s2, 0x18($sp)
/* 19FF54 80271674 AFB10014 */  sw    $s1, 0x14($sp)
/* 19FF58 80271678 A20401F0 */  sb    $a0, 0x1f0($s0)
/* 19FF5C 8027167C 3C048028 */  lui   $a0, 0x8028
/* 19FF60 80271680 248452D4 */  addiu $a0, $a0, 0x52d4
/* 19FF64 80271684 8E1101D8 */  lw    $s1, 0x1d8($s0)
/* 19FF68 80271688 8E1201E8 */  lw    $s2, 0x1e8($s0)
/* 19FF6C 8027168C 0C0B0CF8 */  jal   start_script
/* 19FF70 80271690 24060020 */   addiu $a2, $zero, 0x20
/* 19FF74 80271694 AE0201D8 */  sw    $v0, 0x1d8($s0)
/* 19FF78 80271698 8C430144 */  lw    $v1, 0x144($v0)
/* 19FF7C 8027169C AE0301E8 */  sw    $v1, 0x1e8($s0)
/* 19FF80 802716A0 AC400148 */  sw    $zero, 0x148($v0)
/* 19FF84 802716A4 8E0201D4 */  lw    $v0, 0x1d4($s0)
/* 19FF88 802716A8 10400004 */  beqz  $v0, .L802716BC
/* 19FF8C 802716AC 00000000 */   nop   
/* 19FF90 802716B0 0C0B102B */  jal   kill_script_by_ID
/* 19FF94 802716B4 8E0401E4 */   lw    $a0, 0x1e4($s0)
/* 19FF98 802716B8 AE0001D4 */  sw    $zero, 0x1d4($s0)
.L802716BC:
/* 19FF9C 802716BC 12200003 */  beqz  $s1, .L802716CC
/* 19FFA0 802716C0 00000000 */   nop   
/* 19FFA4 802716C4 0C0B102B */  jal   kill_script_by_ID
/* 19FFA8 802716C8 0240202D */   daddu $a0, $s2, $zero
.L802716CC:
/* 19FFAC 802716CC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19FFB0 802716D0 8FB20018 */  lw    $s2, 0x18($sp)
/* 19FFB4 802716D4 8FB10014 */  lw    $s1, 0x14($sp)
/* 19FFB8 802716D8 8FB00010 */  lw    $s0, 0x10($sp)
/* 19FFBC 802716DC 03E00008 */  jr    $ra
/* 19FFC0 802716E0 27BD0020 */   addiu $sp, $sp, 0x20

