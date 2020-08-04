.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel enforce_hpfp_limits
/* 080D1C 800E786C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 080D20 800E7870 24040004 */  addiu $a0, $zero, 4
/* 080D24 800E7874 AFBF0018 */  sw    $ra, 0x18($sp)
/* 080D28 800E7878 AFB10014 */  sw    $s1, 0x14($sp)
/* 080D2C 800E787C 0C03A752 */  jal   is_ability_active
/* 080D30 800E7880 AFB00010 */   sw    $s0, 0x10($sp)
/* 080D34 800E7884 3C108011 */  lui   $s0, 0x8011
/* 080D38 800E7888 2610F290 */  addiu $s0, $s0, -0xd70
/* 080D3C 800E788C 00022080 */  sll   $a0, $v0, 2
/* 080D40 800E7890 00822021 */  addu  $a0, $a0, $v0
/* 080D44 800E7894 92030004 */  lbu   $v1, 4($s0)
/* 080D48 800E7898 00641821 */  addu  $v1, $v1, $a0
/* 080D4C 800E789C A2030003 */  sb    $v1, 3($s0)
/* 080D50 800E78A0 00031E00 */  sll   $v1, $v1, 0x18
/* 080D54 800E78A4 00031E03 */  sra   $v1, $v1, 0x18
/* 080D58 800E78A8 2863004C */  slti  $v1, $v1, 0x4c
/* 080D5C 800E78AC 14600003 */  bnez  $v1, .L800E78BC
/* 080D60 800E78B0 0200882D */   daddu $s1, $s0, $zero
/* 080D64 800E78B4 2402004B */  addiu $v0, $zero, 0x4b
/* 080D68 800E78B8 A2020003 */  sb    $v0, 3($s0)
.L800E78BC:
/* 080D6C 800E78BC 82030002 */  lb    $v1, 2($s0)
/* 080D70 800E78C0 82020003 */  lb    $v0, 3($s0)
/* 080D74 800E78C4 0043102A */  slt   $v0, $v0, $v1
/* 080D78 800E78C8 92030003 */  lbu   $v1, 3($s0)
/* 080D7C 800E78CC 54400001 */  bnezl $v0, .L800E78D4
/* 080D80 800E78D0 A2030002 */   sb    $v1, 2($s0)
.L800E78D4:
/* 080D84 800E78D4 0C03A752 */  jal   is_ability_active
/* 080D88 800E78D8 2404000C */   addiu $a0, $zero, 0xc
/* 080D8C 800E78DC 00022080 */  sll   $a0, $v0, 2
/* 080D90 800E78E0 92030007 */  lbu   $v1, 7($s0)
/* 080D94 800E78E4 00822021 */  addu  $a0, $a0, $v0
/* 080D98 800E78E8 00641821 */  addu  $v1, $v1, $a0
/* 080D9C 800E78EC A2030006 */  sb    $v1, 6($s0)
/* 080DA0 800E78F0 00031E00 */  sll   $v1, $v1, 0x18
/* 080DA4 800E78F4 00031E03 */  sra   $v1, $v1, 0x18
/* 080DA8 800E78F8 2863004C */  slti  $v1, $v1, 0x4c
/* 080DAC 800E78FC 14600002 */  bnez  $v1, .L800E7908
/* 080DB0 800E7900 2402004B */   addiu $v0, $zero, 0x4b
/* 080DB4 800E7904 A2020006 */  sb    $v0, 6($s0)
.L800E7908:
/* 080DB8 800E7908 82230005 */  lb    $v1, 5($s1)
/* 080DBC 800E790C 82220006 */  lb    $v0, 6($s1)
/* 080DC0 800E7910 0043102A */  slt   $v0, $v0, $v1
/* 080DC4 800E7914 92230006 */  lbu   $v1, 6($s1)
/* 080DC8 800E7918 54400001 */  bnezl $v0, .L800E7920
/* 080DCC 800E791C A2230005 */   sb    $v1, 5($s1)
.L800E7920:
/* 080DD0 800E7920 8FBF0018 */  lw    $ra, 0x18($sp)
/* 080DD4 800E7924 8FB10014 */  lw    $s1, 0x14($sp)
/* 080DD8 800E7928 8FB00010 */  lw    $s0, 0x10($sp)
/* 080DDC 800E792C 03E00008 */  jr    $ra
/* 080DE0 800E7930 27BD0020 */   addiu $sp, $sp, 0x20

