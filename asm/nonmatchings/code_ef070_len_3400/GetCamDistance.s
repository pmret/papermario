.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetCamDistance
/* 0F0A34 802CC084 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0A38 802CC088 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0A3C 802CC08C 0080882D */  daddu $s1, $a0, $zero
/* 0F0A40 802CC090 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F0A44 802CC094 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0A48 802CC098 8E30000C */  lw    $s0, 0xc($s1)
/* 0F0A4C 802CC09C 8E050000 */  lw    $a1, ($s0)
/* 0F0A50 802CC0A0 0C0B1EAF */  jal   get_variable
/* 0F0A54 802CC0A4 26100004 */   addiu $s0, $s0, 4
/* 0F0A58 802CC0A8 00021880 */  sll   $v1, $v0, 2
/* 0F0A5C 802CC0AC 00621821 */  addu  $v1, $v1, $v0
/* 0F0A60 802CC0B0 00031880 */  sll   $v1, $v1, 2
/* 0F0A64 802CC0B4 00621823 */  subu  $v1, $v1, $v0
/* 0F0A68 802CC0B8 000310C0 */  sll   $v0, $v1, 3
/* 0F0A6C 802CC0BC 00621821 */  addu  $v1, $v1, $v0
/* 0F0A70 802CC0C0 000318C0 */  sll   $v1, $v1, 3
/* 0F0A74 802CC0C4 8E050000 */  lw    $a1, ($s0)
/* 0F0A78 802CC0C8 3C06800B */  lui   $a2, 0x800b
/* 0F0A7C 802CC0CC 00C33021 */  addu  $a2, $a2, $v1
/* 0F0A80 802CC0D0 8CC6225C */  lw    $a2, 0x225c($a2)
/* 0F0A84 802CC0D4 0C0B2190 */  jal   set_float_variable
/* 0F0A88 802CC0D8 0220202D */   daddu $a0, $s1, $zero
/* 0F0A8C 802CC0DC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F0A90 802CC0E0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0A94 802CC0E4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0A98 802CC0E8 24020002 */  addiu $v0, $zero, 2
/* 0F0A9C 802CC0EC 03E00008 */  jr    $ra
/* 0F0AA0 802CC0F0 27BD0020 */   addiu $sp, $sp, 0x20

