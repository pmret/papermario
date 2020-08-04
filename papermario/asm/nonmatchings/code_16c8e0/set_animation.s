.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_animation
/* 1925DC 80263CFC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1925E0 80263D00 AFB00010 */  sw    $s0, 0x10($sp)
/* 1925E4 80263D04 0080802D */  daddu $s0, $a0, $zero
/* 1925E8 80263D08 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1925EC 80263D0C 00A0982D */  daddu $s3, $a1, $zero
/* 1925F0 80263D10 AFB20018 */  sw    $s2, 0x18($sp)
/* 1925F4 80263D14 00C0902D */  daddu $s2, $a2, $zero
/* 1925F8 80263D18 AFBF0020 */  sw    $ra, 0x20($sp)
/* 1925FC 80263D1C 06400033 */  bltz  $s2, .L80263DEC
/* 192600 80263D20 AFB10014 */   sw    $s1, 0x14($sp)
/* 192604 80263D24 0C09A75B */  jal   get_actor
/* 192608 80263D28 00000000 */   nop   
/* 19260C 80263D2C 0040882D */  daddu $s1, $v0, $zero
/* 192610 80263D30 32040700 */  andi  $a0, $s0, 0x700
/* 192614 80263D34 24020100 */  addiu $v0, $zero, 0x100
/* 192618 80263D38 10820015 */  beq   $a0, $v0, .L80263D90
/* 19261C 80263D3C 28820101 */   slti  $v0, $a0, 0x101
/* 192620 80263D40 50400005 */  beql  $v0, $zero, .L80263D58
/* 192624 80263D44 24020200 */   addiu $v0, $zero, 0x200
/* 192628 80263D48 10800007 */  beqz  $a0, .L80263D68
/* 19262C 80263D4C 00000000 */   nop   
/* 192630 80263D50 08098F7B */  j     .L80263DEC
/* 192634 80263D54 00000000 */   nop   

.L80263D58:
/* 192638 80263D58 10820016 */  beq   $a0, $v0, .L80263DB4
/* 19263C 80263D5C 0220202D */   daddu $a0, $s1, $zero
/* 192640 80263D60 08098F7B */  j     .L80263DEC
/* 192644 80263D64 00000000 */   nop   

.L80263D68:
/* 192648 80263D68 8E3001F4 */  lw    $s0, 0x1f4($s1)
/* 19264C 80263D6C 8E020088 */  lw    $v0, 0x88($s0)
/* 192650 80263D70 1052001E */  beq   $v0, $s2, .L80263DEC
/* 192654 80263D74 0000202D */   daddu $a0, $zero, $zero
/* 192658 80263D78 8E060090 */  lw    $a2, 0x90($s0)
/* 19265C 80263D7C 0240282D */  daddu $a1, $s2, $zero
/* 192660 80263D80 0C0B76A3 */  jal   func_802DDA8C
/* 192664 80263D84 AE050088 */   sw    $a1, 0x88($s0)
/* 192668 80263D88 08098F7B */  j     .L80263DEC
/* 19266C 80263D8C 00000000 */   nop   

.L80263D90:
/* 192670 80263D90 12600006 */  beqz  $s3, .L80263DAC
/* 192674 80263D94 0220202D */   daddu $a0, $s1, $zero
/* 192678 80263D98 0C099117 */  jal   get_actor_part
/* 19267C 80263D9C 0260282D */   daddu $a1, $s3, $zero
/* 192680 80263DA0 0040802D */  daddu $s0, $v0, $zero
/* 192684 80263DA4 16000006 */  bnez  $s0, .L80263DC0
/* 192688 80263DA8 00000000 */   nop   
.L80263DAC:
/* 19268C 80263DAC 08098F70 */  j     .L80263DC0
/* 192690 80263DB0 8E3001F4 */   lw    $s0, 0x1f4($s1)

.L80263DB4:
/* 192694 80263DB4 0C099117 */  jal   get_actor_part
/* 192698 80263DB8 0260282D */   daddu $a1, $s3, $zero
/* 19269C 80263DBC 0040802D */  daddu $s0, $v0, $zero
.L80263DC0:
.L80263DC0:
/* 1926A0 80263DC0 8E020088 */  lw    $v0, 0x88($s0)
/* 1926A4 80263DC4 10520009 */  beq   $v0, $s2, .L80263DEC
/* 1926A8 80263DC8 0240282D */   daddu $a1, $s2, $zero
/* 1926AC 80263DCC 8E040084 */  lw    $a0, 0x84($s0)
/* 1926B0 80263DD0 8E060090 */  lw    $a2, 0x90($s0)
/* 1926B4 80263DD4 0C0B78AB */  jal   func_802DE2AC
/* 1926B8 80263DD8 AE050088 */   sw    $a1, 0x88($s0)
/* 1926BC 80263DDC 8E040084 */  lw    $a0, 0x84($s0)
/* 1926C0 80263DE0 0C0B7972 */  jal   func_802DE5C8
/* 1926C4 80263DE4 00000000 */   nop   
/* 1926C8 80263DE8 AE02008C */  sw    $v0, 0x8c($s0)
.L80263DEC:
.L80263DEC:
/* 1926CC 80263DEC 8FBF0020 */  lw    $ra, 0x20($sp)
/* 1926D0 80263DF0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1926D4 80263DF4 8FB20018 */  lw    $s2, 0x18($sp)
/* 1926D8 80263DF8 8FB10014 */  lw    $s1, 0x14($sp)
/* 1926DC 80263DFC 8FB00010 */  lw    $s0, 0x10($sp)
/* 1926E0 80263E00 03E00008 */  jr    $ra
/* 1926E4 80263E04 27BD0028 */   addiu $sp, $sp, 0x28

