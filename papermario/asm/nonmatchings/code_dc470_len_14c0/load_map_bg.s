.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel load_map_bg
/* 0DC470 80145D70 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0DC474 80145D74 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0DC478 80145D78 1080001B */  beqz  $a0, .L80145DE8
/* 0DC47C 80145D7C AFB00018 */   sw    $s0, 0x18($sp)
/* 0DC480 80145D80 0080802D */  daddu $s0, $a0, $zero
/* 0DC484 80145D84 0000202D */  daddu $a0, $zero, $zero
/* 0DC488 80145D88 3C05F5DE */  lui   $a1, 0xf5de
/* 0DC48C 80145D8C 0C0B1EAF */  jal   get_variable
/* 0DC490 80145D90 34A50180 */   ori   $a1, $a1, 0x180
/* 0DC494 80145D94 28420035 */  slti  $v0, $v0, 0x35
/* 0DC498 80145D98 1440000A */  bnez  $v0, .L80145DC4
/* 0DC49C 80145D9C 0200202D */   daddu $a0, $s0, $zero
/* 0DC4A0 80145DA0 3C058015 */  lui   $a1, 0x8015
/* 0DC4A4 80145DA4 24A5F120 */  addiu $a1, $a1, -0xee0
/* 0DC4A8 80145DA8 0C01BB5C */  jal   strcmp
/* 0DC4AC 80145DAC 0200202D */   daddu $a0, $s0, $zero
/* 0DC4B0 80145DB0 54400004 */  bnel  $v0, $zero, .L80145DC4
/* 0DC4B4 80145DB4 0200202D */   daddu $a0, $s0, $zero
/* 0DC4B8 80145DB8 3C108015 */  lui   $s0, 0x8015
/* 0DC4BC 80145DBC 2610F128 */  addiu $s0, $s0, -0xed8
/* 0DC4C0 80145DC0 0200202D */  daddu $a0, $s0, $zero
.L80145DC4:
/* 0DC4C4 80145DC4 0C016B3A */  jal   load_asset_by_name
/* 0DC4C8 80145DC8 27A50010 */   addiu $a1, $sp, 0x10
/* 0DC4CC 80145DCC 0040802D */  daddu $s0, $v0, $zero
/* 0DC4D0 80145DD0 3C058020 */  lui   $a1, 0x8020
/* 0DC4D4 80145DD4 24A50000 */  addiu $a1, $a1, 0
/* 0DC4D8 80145DD8 0C01BB7C */  jal   decode_yay0
/* 0DC4DC 80145DDC 0200202D */   daddu $a0, $s0, $zero
/* 0DC4E0 80145DE0 0C00AB1E */  jal   general_heap_free
/* 0DC4E4 80145DE4 0200202D */   daddu $a0, $s0, $zero
.L80145DE8:
/* 0DC4E8 80145DE8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0DC4EC 80145DEC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0DC4F0 80145DF0 03E00008 */  jr    $ra
/* 0DC4F4 80145DF4 27BD0020 */   addiu $sp, $sp, 0x20

