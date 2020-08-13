.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80245984
/* 138CC4 80245984 AFBE0078 */  sw    $fp, 0x78($sp)
/* 138CC8 80245988 00C0F02D */  daddu $fp, $a2, $zero
/* 138CCC 8024598C AFA50084 */  sw    $a1, 0x84($sp)
/* 138CD0 80245990 24A8008F */  addiu $t0, $a1, 0x8f
/* 138CD4 80245994 0100282D */  daddu $a1, $t0, $zero
/* 138CD8 80245998 AFB1005C */  sw    $s1, 0x5c($sp)
/* 138CDC 8024599C 3C118027 */  lui   $s1, 0x8027
/* 138CE0 802459A0 26310150 */  addiu $s1, $s1, 0x150
/* 138CE4 802459A4 AFBF007C */  sw    $ra, 0x7c($sp)
/* 138CE8 802459A8 AFB70074 */  sw    $s7, 0x74($sp)
/* 138CEC 802459AC AFB60070 */  sw    $s6, 0x70($sp)
/* 138CF0 802459B0 AFB5006C */  sw    $s5, 0x6c($sp)
/* 138CF4 802459B4 AFB40068 */  sw    $s4, 0x68($sp)
/* 138CF8 802459B8 AFB30064 */  sw    $s3, 0x64($sp)
/* 138CFC 802459BC AFB20060 */  sw    $s2, 0x60($sp)
/* 138D00 802459C0 AFB00058 */  sw    $s0, 0x58($sp)
/* 138D04 802459C4 AFA40080 */  sw    $a0, 0x80($sp)
/* 138D08 802459C8 AFA80050 */  sw    $t0, 0x50($sp)
/* 138D0C 802459CC 8E24000C */  lw    $a0, 0xc($s1)
/* 138D10 802459D0 0C051261 */  jal   set_icon_render_pos
/* 138D14 802459D4 27C6006D */   addiu $a2, $fp, 0x6d
/* 138D18 802459D8 8E24000C */  lw    $a0, 0xc($s1)
/* 138D1C 802459DC 0C0511F8 */  jal   func_801447E0
