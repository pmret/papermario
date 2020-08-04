.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PanToTarget
/* 0F014C 802CB79C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F0150 802CB7A0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0154 802CB7A4 0080902D */  daddu $s2, $a0, $zero
/* 0F0158 802CB7A8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F015C 802CB7AC AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0160 802CB7B0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0164 802CB7B4 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F0168 802CB7B8 8E50000C */  lw    $s0, 0xc($s2)
/* 0F016C 802CB7BC 8E050000 */  lw    $a1, ($s0)
/* 0F0170 802CB7C0 0C0B1EAF */  jal   get_variable
/* 0F0174 802CB7C4 26100004 */   addiu $s0, $s0, 4
/* 0F0178 802CB7C8 8E050000 */  lw    $a1, ($s0)
/* 0F017C 802CB7CC 26100004 */  addiu $s0, $s0, 4
/* 0F0180 802CB7D0 0240202D */  daddu $a0, $s2, $zero
/* 0F0184 802CB7D4 0C0B210B */  jal   get_float_variable
/* 0F0188 802CB7D8 0040882D */   daddu $s1, $v0, $zero
/* 0F018C 802CB7DC 0240202D */  daddu $a0, $s2, $zero
/* 0F0190 802CB7E0 8E050000 */  lw    $a1, ($s0)
/* 0F0194 802CB7E4 0C0B1EAF */  jal   get_variable
/* 0F0198 802CB7E8 46000506 */   mov.s $f20, $f0
/* 0F019C 802CB7EC 3C05800B */  lui   $a1, 0x800b
/* 0F01A0 802CB7F0 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0F01A4 802CB7F4 00111880 */  sll   $v1, $s1, 2
/* 0F01A8 802CB7F8 00711821 */  addu  $v1, $v1, $s1
/* 0F01AC 802CB7FC 00031880 */  sll   $v1, $v1, 2
/* 0F01B0 802CB800 00711823 */  subu  $v1, $v1, $s1
/* 0F01B4 802CB804 000320C0 */  sll   $a0, $v1, 3
/* 0F01B8 802CB808 00641821 */  addu  $v1, $v1, $a0
/* 0F01BC 802CB80C 000318C0 */  sll   $v1, $v1, 3
/* 0F01C0 802CB810 00651821 */  addu  $v1, $v1, $a1
/* 0F01C4 802CB814 24040001 */  addiu $a0, $zero, 1
/* 0F01C8 802CB818 10400004 */  beqz  $v0, .L802CB82C
/* 0F01CC 802CB81C A4640506 */   sh    $a0, 0x506($v1)
/* 0F01D0 802CB820 A4640504 */  sh    $a0, 0x504($v1)
/* 0F01D4 802CB824 080B2E10 */  j     .L802CB840
/* 0F01D8 802CB828 E4740508 */   swc1  $f20, 0x508($v1)

.L802CB82C:
/* 0F01DC 802CB82C 3C013F80 */  lui   $at, 0x3f80
/* 0F01E0 802CB830 44810000 */  mtc1  $at, $f0
/* 0F01E4 802CB834 A4600504 */  sh    $zero, 0x504($v1)
/* 0F01E8 802CB838 AC600508 */  sw    $zero, 0x508($v1)
/* 0F01EC 802CB83C E4600490 */  swc1  $f0, 0x490($v1)
.L802CB840:
/* 0F01F0 802CB840 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F01F4 802CB844 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F01F8 802CB848 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F01FC 802CB84C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0200 802CB850 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F0204 802CB854 24020002 */  addiu $v0, $zero, 2
/* 0F0208 802CB858 03E00008 */  jr    $ra
/* 0F020C 802CB85C 27BD0028 */   addiu $sp, $sp, 0x28

