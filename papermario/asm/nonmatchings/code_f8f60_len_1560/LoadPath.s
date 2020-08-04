.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel LoadPath
/* 0F9DE0 802D5430 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F9DE4 802D5434 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9DE8 802D5438 0080902D */  daddu $s2, $a0, $zero
/* 0F9DEC 802D543C AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F9DF0 802D5440 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F9DF4 802D5444 AFB40020 */  sw    $s4, 0x20($sp)
/* 0F9DF8 802D5448 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F9DFC 802D544C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9E00 802D5450 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9E04 802D5454 8E50000C */  lw    $s0, 0xc($s2)
/* 0F9E08 802D5458 8E050000 */  lw    $a1, ($s0)
/* 0F9E0C 802D545C 0C0B1EAF */  jal   get_variable
/* 0F9E10 802D5460 26100004 */   addiu $s0, $s0, 4
/* 0F9E14 802D5464 8E050000 */  lw    $a1, ($s0)
/* 0F9E18 802D5468 26100004 */  addiu $s0, $s0, 4
/* 0F9E1C 802D546C 0240202D */  daddu $a0, $s2, $zero
/* 0F9E20 802D5470 0C0B1EAF */  jal   get_variable
/* 0F9E24 802D5474 0040982D */   daddu $s3, $v0, $zero
/* 0F9E28 802D5478 8E050000 */  lw    $a1, ($s0)
/* 0F9E2C 802D547C 26100004 */  addiu $s0, $s0, 4
/* 0F9E30 802D5480 0240202D */  daddu $a0, $s2, $zero
/* 0F9E34 802D5484 0C0B1EAF */  jal   get_variable
/* 0F9E38 802D5488 0040A02D */   daddu $s4, $v0, $zero
/* 0F9E3C 802D548C 0240202D */  daddu $a0, $s2, $zero
/* 0F9E40 802D5490 8E050000 */  lw    $a1, ($s0)
/* 0F9E44 802D5494 0C0B1EAF */  jal   get_variable
/* 0F9E48 802D5498 0040882D */   daddu $s1, $v0, $zero
/* 0F9E4C 802D549C 2404001C */  addiu $a0, $zero, 0x1c
/* 0F9E50 802D54A0 0C00AB39 */  jal   heap_malloc
/* 0F9E54 802D54A4 0040A82D */   daddu $s5, $v0, $zero
/* 0F9E58 802D54A8 00112080 */  sll   $a0, $s1, 2
/* 0F9E5C 802D54AC 0040802D */  daddu $s0, $v0, $zero
/* 0F9E60 802D54B0 AE5000C0 */  sw    $s0, 0xc0($s2)
/* 0F9E64 802D54B4 0C00AB39 */  jal   heap_malloc
/* 0F9E68 802D54B8 AE110000 */   sw    $s1, ($s0)
/* 0F9E6C 802D54BC 00112040 */  sll   $a0, $s1, 1
/* 0F9E70 802D54C0 00912021 */  addu  $a0, $a0, $s1
/* 0F9E74 802D54C4 00042080 */  sll   $a0, $a0, 2
/* 0F9E78 802D54C8 AE020004 */  sw    $v0, 4($s0)
/* 0F9E7C 802D54CC 0C00AB39 */  jal   heap_malloc
/* 0F9E80 802D54D0 AE140008 */   sw    $s4, 8($s0)
/* 0F9E84 802D54D4 8E040000 */  lw    $a0, ($s0)
/* 0F9E88 802D54D8 8E050004 */  lw    $a1, 4($s0)
/* 0F9E8C 802D54DC 8E060008 */  lw    $a2, 8($s0)
/* 0F9E90 802D54E0 0040382D */  daddu $a3, $v0, $zero
/* 0F9E94 802D54E4 0C0B536B */  jal   setup_path_data
/* 0F9E98 802D54E8 AE02000C */   sw    $v0, 0xc($s0)
/* 0F9E9C 802D54EC 2673FFFF */  addiu $s3, $s3, -1
/* 0F9EA0 802D54F0 AE000010 */  sw    $zero, 0x10($s0)
/* 0F9EA4 802D54F4 AE130014 */  sw    $s3, 0x14($s0)
/* 0F9EA8 802D54F8 AE150018 */  sw    $s5, 0x18($s0)
/* 0F9EAC 802D54FC 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F9EB0 802D5500 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F9EB4 802D5504 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F9EB8 802D5508 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F9EBC 802D550C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9EC0 802D5510 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9EC4 802D5514 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9EC8 802D5518 24020002 */  addiu $v0, $zero, 2
/* 0F9ECC 802D551C 03E00008 */  jr    $ra
/* 0F9ED0 802D5520 27BD0030 */   addiu $sp, $sp, 0x30

