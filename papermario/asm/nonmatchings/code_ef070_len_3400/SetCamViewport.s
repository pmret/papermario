.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamViewport
/* 0EF4C8 802CAB18 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0EF4CC 802CAB1C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0EF4D0 802CAB20 0080882D */  daddu $s1, $a0, $zero
/* 0EF4D4 802CAB24 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0EF4D8 802CAB28 AFB40028 */  sw    $s4, 0x28($sp)
/* 0EF4DC 802CAB2C AFB30024 */  sw    $s3, 0x24($sp)
/* 0EF4E0 802CAB30 AFB20020 */  sw    $s2, 0x20($sp)
/* 0EF4E4 802CAB34 AFB00018 */  sw    $s0, 0x18($sp)
/* 0EF4E8 802CAB38 8E30000C */  lw    $s0, 0xc($s1)
/* 0EF4EC 802CAB3C 8E050000 */  lw    $a1, ($s0)
/* 0EF4F0 802CAB40 0C0B1EAF */  jal   get_variable
/* 0EF4F4 802CAB44 26100004 */   addiu $s0, $s0, 4
/* 0EF4F8 802CAB48 8E050000 */  lw    $a1, ($s0)
/* 0EF4FC 802CAB4C 26100004 */  addiu $s0, $s0, 4
/* 0EF500 802CAB50 0220202D */  daddu $a0, $s1, $zero
/* 0EF504 802CAB54 0C0B1EAF */  jal   get_variable
/* 0EF508 802CAB58 0040A02D */   daddu $s4, $v0, $zero
/* 0EF50C 802CAB5C 8E050000 */  lw    $a1, ($s0)
/* 0EF510 802CAB60 26100004 */  addiu $s0, $s0, 4
/* 0EF514 802CAB64 0220202D */  daddu $a0, $s1, $zero
/* 0EF518 802CAB68 0C0B1EAF */  jal   get_variable
/* 0EF51C 802CAB6C 0040902D */   daddu $s2, $v0, $zero
/* 0EF520 802CAB70 8E050000 */  lw    $a1, ($s0)
/* 0EF524 802CAB74 26100004 */  addiu $s0, $s0, 4
/* 0EF528 802CAB78 0220202D */  daddu $a0, $s1, $zero
/* 0EF52C 802CAB7C 0C0B1EAF */  jal   get_variable
/* 0EF530 802CAB80 0040982D */   daddu $s3, $v0, $zero
/* 0EF534 802CAB84 0220202D */  daddu $a0, $s1, $zero
/* 0EF538 802CAB88 8E050000 */  lw    $a1, ($s0)
/* 0EF53C 802CAB8C 0C0B1EAF */  jal   get_variable
/* 0EF540 802CAB90 0040802D */   daddu $s0, $v0, $zero
/* 0EF544 802CAB94 0014A400 */  sll   $s4, $s4, 0x10
/* 0EF548 802CAB98 00142403 */  sra   $a0, $s4, 0x10
/* 0EF54C 802CAB9C 00129400 */  sll   $s2, $s2, 0x10
/* 0EF550 802CABA0 00122C03 */  sra   $a1, $s2, 0x10
/* 0EF554 802CABA4 00021400 */  sll   $v0, $v0, 0x10
/* 0EF558 802CABA8 00021403 */  sra   $v0, $v0, 0x10
/* 0EF55C 802CABAC 00139C00 */  sll   $s3, $s3, 0x10
/* 0EF560 802CABB0 00108400 */  sll   $s0, $s0, 0x10
/* 0EF564 802CABB4 00133403 */  sra   $a2, $s3, 0x10
/* 0EF568 802CABB8 00103C03 */  sra   $a3, $s0, 0x10
/* 0EF56C 802CABBC 0C00B8C5 */  jal   set_cam_viewport
/* 0EF570 802CABC0 AFA20010 */   sw    $v0, 0x10($sp)
/* 0EF574 802CABC4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0EF578 802CABC8 8FB40028 */  lw    $s4, 0x28($sp)
/* 0EF57C 802CABCC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0EF580 802CABD0 8FB20020 */  lw    $s2, 0x20($sp)
/* 0EF584 802CABD4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0EF588 802CABD8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0EF58C 802CABDC 24020002 */  addiu $v0, $zero, 2
/* 0EF590 802CABE0 03E00008 */  jr    $ra
/* 0EF594 802CABE4 27BD0030 */   addiu $sp, $sp, 0x30

/* 0EF598 802CABE8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EF59C 802CABEC AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF5A0 802CABF0 0080882D */  daddu $s1, $a0, $zero
/* 0EF5A4 802CABF4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0EF5A8 802CABF8 AFB40020 */  sw    $s4, 0x20($sp)
/* 0EF5AC 802CABFC AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EF5B0 802CAC00 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EF5B4 802CAC04 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF5B8 802CAC08 8E30000C */  lw    $s0, 0xc($s1)
/* 0EF5BC 802CAC0C 8E050000 */  lw    $a1, ($s0)
/* 0EF5C0 802CAC10 0C0B1EAF */  jal   get_variable
/* 0EF5C4 802CAC14 26100004 */   addiu $s0, $s0, 4
/* 0EF5C8 802CAC18 8E050000 */  lw    $a1, ($s0)
/* 0EF5CC 802CAC1C 26100004 */  addiu $s0, $s0, 4
/* 0EF5D0 802CAC20 0220202D */  daddu $a0, $s1, $zero
/* 0EF5D4 802CAC24 0C0B1EAF */  jal   get_variable
/* 0EF5D8 802CAC28 0040902D */   daddu $s2, $v0, $zero
/* 0EF5DC 802CAC2C 8E050000 */  lw    $a1, ($s0)
/* 0EF5E0 802CAC30 26100004 */  addiu $s0, $s0, 4
/* 0EF5E4 802CAC34 0220202D */  daddu $a0, $s1, $zero
/* 0EF5E8 802CAC38 0C0B1EAF */  jal   get_variable
/* 0EF5EC 802CAC3C 0040A02D */   daddu $s4, $v0, $zero
/* 0EF5F0 802CAC40 8E050000 */  lw    $a1, ($s0)
/* 0EF5F4 802CAC44 26100004 */  addiu $s0, $s0, 4
/* 0EF5F8 802CAC48 0220202D */  daddu $a0, $s1, $zero
/* 0EF5FC 802CAC4C 0C0B1EAF */  jal   get_variable
/* 0EF600 802CAC50 0040982D */   daddu $s3, $v0, $zero
/* 0EF604 802CAC54 0220202D */  daddu $a0, $s1, $zero
/* 0EF608 802CAC58 8E050000 */  lw    $a1, ($s0)
/* 0EF60C 802CAC5C 0C0B1EAF */  jal   get_variable
/* 0EF610 802CAC60 0040802D */   daddu $s0, $v0, $zero
/* 0EF614 802CAC64 3C05800B */  lui   $a1, 0x800b
/* 0EF618 802CAC68 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0EF61C 802CAC6C 00121880 */  sll   $v1, $s2, 2
/* 0EF620 802CAC70 00721821 */  addu  $v1, $v1, $s2
/* 0EF624 802CAC74 00031880 */  sll   $v1, $v1, 2
/* 0EF628 802CAC78 00721823 */  subu  $v1, $v1, $s2
/* 0EF62C 802CAC7C 000320C0 */  sll   $a0, $v1, 3
/* 0EF630 802CAC80 00641821 */  addu  $v1, $v1, $a0
/* 0EF634 802CAC84 000318C0 */  sll   $v1, $v1, 3
/* 0EF638 802CAC88 00651821 */  addu  $v1, $v1, $a1
/* 0EF63C 802CAC8C A4620022 */  sh    $v0, 0x22($v1)
/* 0EF640 802CAC90 A474001C */  sh    $s4, 0x1c($v1)
/* 0EF644 802CAC94 A473001E */  sh    $s3, 0x1e($v1)
/* 0EF648 802CAC98 A4700020 */  sh    $s0, 0x20($v1)
/* 0EF64C 802CAC9C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0EF650 802CACA0 8FB40020 */  lw    $s4, 0x20($sp)
/* 0EF654 802CACA4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EF658 802CACA8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EF65C 802CACAC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF660 802CACB0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF664 802CACB4 24020002 */  addiu $v0, $zero, 2
/* 0EF668 802CACB8 03E00008 */  jr    $ra
/* 0EF66C 802CACBC 27BD0028 */   addiu $sp, $sp, 0x28

/* 0EF670 802CACC0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EF674 802CACC4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF678 802CACC8 0080882D */  daddu $s1, $a0, $zero
/* 0EF67C 802CACCC AFBF0024 */  sw    $ra, 0x24($sp)
/* 0EF680 802CACD0 AFB40020 */  sw    $s4, 0x20($sp)
/* 0EF684 802CACD4 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EF688 802CACD8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EF68C 802CACDC AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF690 802CACE0 8E30000C */  lw    $s0, 0xc($s1)
/* 0EF694 802CACE4 8E050000 */  lw    $a1, ($s0)
/* 0EF698 802CACE8 0C0B1EAF */  jal   get_variable
/* 0EF69C 802CACEC 26100004 */   addiu $s0, $s0, 4
/* 0EF6A0 802CACF0 8E050000 */  lw    $a1, ($s0)
/* 0EF6A4 802CACF4 26100004 */  addiu $s0, $s0, 4
/* 0EF6A8 802CACF8 0220202D */  daddu $a0, $s1, $zero
/* 0EF6AC 802CACFC 0C0B1EAF */  jal   get_variable
/* 0EF6B0 802CAD00 0040902D */   daddu $s2, $v0, $zero
/* 0EF6B4 802CAD04 8E050000 */  lw    $a1, ($s0)
/* 0EF6B8 802CAD08 26100004 */  addiu $s0, $s0, 4
/* 0EF6BC 802CAD0C 0220202D */  daddu $a0, $s1, $zero
/* 0EF6C0 802CAD10 0C0B1EAF */  jal   get_variable
/* 0EF6C4 802CAD14 0040A02D */   daddu $s4, $v0, $zero
/* 0EF6C8 802CAD18 8E050000 */  lw    $a1, ($s0)
/* 0EF6CC 802CAD1C 26100004 */  addiu $s0, $s0, 4
/* 0EF6D0 802CAD20 0220202D */  daddu $a0, $s1, $zero
/* 0EF6D4 802CAD24 0C0B1EAF */  jal   get_variable
/* 0EF6D8 802CAD28 0040982D */   daddu $s3, $v0, $zero
/* 0EF6DC 802CAD2C 0220202D */  daddu $a0, $s1, $zero
/* 0EF6E0 802CAD30 8E050000 */  lw    $a1, ($s0)
/* 0EF6E4 802CAD34 0C0B1EAF */  jal   get_variable
/* 0EF6E8 802CAD38 0040802D */   daddu $s0, $v0, $zero
/* 0EF6EC 802CAD3C 3C05800B */  lui   $a1, 0x800b
/* 0EF6F0 802CAD40 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0EF6F4 802CAD44 00121880 */  sll   $v1, $s2, 2
/* 0EF6F8 802CAD48 00721821 */  addu  $v1, $v1, $s2
/* 0EF6FC 802CAD4C 00031880 */  sll   $v1, $v1, 2
/* 0EF700 802CAD50 00721823 */  subu  $v1, $v1, $s2
/* 0EF704 802CAD54 000320C0 */  sll   $a0, $v1, 3
/* 0EF708 802CAD58 00641821 */  addu  $v1, $v1, $a0
/* 0EF70C 802CAD5C 000318C0 */  sll   $v1, $v1, 3
/* 0EF710 802CAD60 00651821 */  addu  $v1, $v1, $a1
/* 0EF714 802CAD64 A462002A */  sh    $v0, 0x2a($v1)
/* 0EF718 802CAD68 A4740024 */  sh    $s4, 0x24($v1)
/* 0EF71C 802CAD6C A4730026 */  sh    $s3, 0x26($v1)
/* 0EF720 802CAD70 A4700028 */  sh    $s0, 0x28($v1)
/* 0EF724 802CAD74 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0EF728 802CAD78 8FB40020 */  lw    $s4, 0x20($sp)
/* 0EF72C 802CAD7C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EF730 802CAD80 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EF734 802CAD84 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF738 802CAD88 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF73C 802CAD8C 24020002 */  addiu $v0, $zero, 2
/* 0EF740 802CAD90 03E00008 */  jr    $ra
/* 0EF744 802CAD94 27BD0028 */   addiu $sp, $sp, 0x28

