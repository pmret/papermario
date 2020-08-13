.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel MakeOwnerTargetIndex
/* 1AE498 8027FBB8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1AE49C 8027FBBC AFB40020 */  sw    $s4, 0x20($sp)
/* 1AE4A0 8027FBC0 0080A02D */  daddu $s4, $a0, $zero
/* 1AE4A4 8027FBC4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 1AE4A8 8027FBC8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1AE4AC 8027FBCC AFB20018 */  sw    $s2, 0x18($sp)
/* 1AE4B0 8027FBD0 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AE4B4 8027FBD4 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AE4B8 8027FBD8 8E840148 */  lw    $a0, 0x148($s4)
/* 1AE4BC 8027FBDC 0C09A75B */  jal   get_actor
/* 1AE4C0 8027FBE0 8E90000C */   lw    $s0, 0xc($s4)
/* 1AE4C4 8027FBE4 8E050000 */  lw    $a1, ($s0)
/* 1AE4C8 8027FBE8 26100004 */  addiu $s0, $s0, 4
/* 1AE4CC 8027FBEC 0040902D */  daddu $s2, $v0, $zero
/* 1AE4D0 8027FBF0 8251040C */  lb    $s1, 0x40c($s2)
/* 1AE4D4 8027FBF4 0C0B1EAF */  jal   get_variable
/* 1AE4D8 8027FBF8 0280202D */   daddu $a0, $s4, $zero
/* 1AE4DC 8027FBFC 8E050000 */  lw    $a1, ($s0)
/* 1AE4E0 8027FC00 26100004 */  addiu $s0, $s0, 4
/* 1AE4E4 8027FC04 0C0B1EAF */  jal   get_variable
/* 1AE4E8 8027FC08 0280202D */   daddu $a0, $s4, $zero
/* 1AE4EC 8027FC0C 0040302D */  daddu $a2, $v0, $zero
/* 1AE4F0 8027FC10 8E050000 */  lw    $a1, ($s0)
/* 1AE4F4 8027FC14 16200003 */  bnez  $s1, .L8027FC24
/* 1AE4F8 8027FC18 2653040D */   addiu $s3, $s2, 0x40d
/* 1AE4FC 8027FC1C 0809FF19 */  j     .L8027FC64
/* 1AE500 8027FC20 2406FFFF */   addiu $a2, $zero, -1

.L8027FC24:
/* 1AE504 8027FC24 10C00004 */  beqz  $a2, .L8027FC38
/* 1AE508 8027FC28 00D1102A */   slt   $v0, $a2, $s1
/* 1AE50C 8027FC2C 14400002 */  bnez  $v0, .L8027FC38
/* 1AE510 8027FC30 24C6FFFF */   addiu $a2, $a2, -1
/* 1AE514 8027FC34 2626FFFF */  addiu $a2, $s1, -1
.L8027FC38:
/* 1AE518 8027FC38 02661021 */  addu  $v0, $s3, $a2
/* 1AE51C 8027FC3C 80430000 */  lb    $v1, ($v0)
/* 1AE520 8027FC40 00031080 */  sll   $v0, $v1, 2
/* 1AE524 8027FC44 00431021 */  addu  $v0, $v0, $v1
/* 1AE528 8027FC48 00021080 */  sll   $v0, $v0, 2
/* 1AE52C 8027FC4C 2442022C */  addiu $v0, $v0, 0x22c
/* 1AE530 8027FC50 02421021 */  addu  $v0, $s2, $v0
/* 1AE534 8027FC54 94430000 */  lhu   $v1, ($v0)
/* 1AE538 8027FC58 A6430428 */  sh    $v1, 0x428($s2)
/* 1AE53C 8027FC5C 90420003 */  lbu   $v0, 3($v0)
/* 1AE540 8027FC60 A2420426 */  sb    $v0, 0x426($s2)
.L8027FC64:
/* 1AE544 8027FC64 0C0B2026 */  jal   set_variable
/* 1AE548 8027FC68 0280202D */   daddu $a0, $s4, $zero
/* 1AE54C 8027FC6C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1AE550 8027FC70 8FB40020 */  lw    $s4, 0x20($sp)
/* 1AE554 8027FC74 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1AE558 8027FC78 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AE55C 8027FC7C 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AE560 8027FC80 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AE564 8027FC84 24020002 */  addiu $v0, $zero, 2
/* 1AE568 8027FC88 03E00008 */  jr    $ra
/* 1AE56C 8027FC8C 27BD0028 */   addiu $sp, $sp, 0x28

/* 1AE570 8027FC90 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1AE574 8027FC94 AFB40028 */  sw    $s4, 0x28($sp)
/* 1AE578 8027FC98 0080A02D */  daddu $s4, $a0, $zero
/* 1AE57C 8027FC9C AFBF002C */  sw    $ra, 0x2c($sp)
/* 1AE580 8027FCA0 AFB30024 */  sw    $s3, 0x24($sp)
/* 1AE584 8027FCA4 AFB20020 */  sw    $s2, 0x20($sp)
/* 1AE588 8027FCA8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1AE58C 8027FCAC AFB00018 */  sw    $s0, 0x18($sp)
/* 1AE590 8027FCB0 8E92000C */  lw    $s2, 0xc($s4)
/* 1AE594 8027FCB4 8E450000 */  lw    $a1, ($s2)
/* 1AE598 8027FCB8 0C0B1EAF */  jal   get_variable
/* 1AE59C 8027FCBC 26520004 */   addiu $s2, $s2, 4
/* 1AE5A0 8027FCC0 0040202D */  daddu $a0, $v0, $zero
/* 1AE5A4 8027FCC4 3C13800E */  lui   $s3, 0x800e
/* 1AE5A8 8027FCC8 2673C070 */  addiu $s3, $s3, -0x3f90
/* 1AE5AC 8027FCCC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AE5B0 8027FCD0 14820002 */  bne   $a0, $v0, .L8027FCDC
/* 1AE5B4 8027FCD4 00000000 */   nop   
/* 1AE5B8 8027FCD8 8E840148 */  lw    $a0, 0x148($s4)
.L8027FCDC:
/* 1AE5BC 8027FCDC 0C09A75B */  jal   get_actor
/* 1AE5C0 8027FCE0 8E520000 */   lw    $s2, ($s2)
/* 1AE5C4 8027FCE4 8E630000 */  lw    $v1, ($s3)
/* 1AE5C8 8027FCE8 0040802D */  daddu $s0, $v0, $zero
/* 1AE5CC 8027FCEC 34630020 */  ori   $v1, $v1, 0x20
/* 1AE5D0 8027FCF0 0C09F8CA */  jal   calc_partner_damage_enemy
/* 1AE5D4 8027FCF4 AE630000 */   sw    $v1, ($s3)
/* 1AE5D8 8027FCF8 AFA00010 */  sw    $zero, 0x10($sp)
/* 1AE5DC 8027FCFC 8E060020 */  lw    $a2, 0x20($s0)
/* 1AE5E0 8027FD00 86670180 */  lh    $a3, 0x180($s3)
/* 1AE5E4 8027FD04 C60C0018 */  lwc1  $f12, 0x18($s0)
/* 1AE5E8 8027FD08 C60E001C */  lwc1  $f14, 0x1c($s0)
/* 1AE5EC 8027FD0C 0C09996B */  jal   show_damage_popup
/* 1AE5F0 8027FD10 0040882D */   daddu $s1, $v0, $zero
/* 1AE5F4 8027FD14 0280202D */  daddu $a0, $s4, $zero
/* 1AE5F8 8027FD18 0240282D */  daddu $a1, $s2, $zero
/* 1AE5FC 8027FD1C 0C0B2026 */  jal   set_variable
/* 1AE600 8027FD20 0220302D */   daddu $a2, $s1, $zero
/* 1AE604 8027FD24 8FBF002C */  lw    $ra, 0x2c($sp)
/* 1AE608 8027FD28 8FB40028 */  lw    $s4, 0x28($sp)
/* 1AE60C 8027FD2C 8FB30024 */  lw    $s3, 0x24($sp)
/* 1AE610 8027FD30 8FB20020 */  lw    $s2, 0x20($sp)
/* 1AE614 8027FD34 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1AE618 8027FD38 8FB00018 */  lw    $s0, 0x18($sp)
/* 1AE61C 8027FD3C 24020002 */  addiu $v0, $zero, 2
/* 1AE620 8027FD40 03E00008 */  jr    $ra
/* 1AE624 8027FD44 27BD0030 */   addiu $sp, $sp, 0x30

