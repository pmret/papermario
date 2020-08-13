.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80050900
/* 02BD00 80050900 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 02BD04 80050904 AFB10014 */  sw    $s1, 0x14($sp)
/* 02BD08 80050908 0080882D */  daddu $s1, $a0, $zero
/* 02BD0C 8005090C AFB00010 */  sw    $s0, 0x10($sp)
/* 02BD10 80050910 0000802D */  daddu $s0, $zero, $zero
/* 02BD14 80050914 AFBF0018 */  sw    $ra, 0x18($sp)
/* 02BD18 80050918 320500FF */  andi  $a1, $s0, 0xff
.L8005091C:
/* 02BD1C 8005091C 000510C0 */  sll   $v0, $a1, 3
/* 02BD20 80050920 00451021 */  addu  $v0, $v0, $a1
/* 02BD24 80050924 000210C0 */  sll   $v0, $v0, 3
/* 02BD28 80050928 8E230000 */  lw    $v1, ($s1)
/* 02BD2C 8005092C 24421320 */  addiu $v0, $v0, 0x1320
/* 02BD30 80050930 00622021 */  addu  $a0, $v1, $v0
/* 02BD34 80050934 90830045 */  lbu   $v1, 0x45($a0)
/* 02BD38 80050938 92220234 */  lbu   $v0, 0x234($s1)
/* 02BD3C 8005093C 14620003 */  bne   $v1, $v0, .L8005094C
/* 02BD40 80050940 26100001 */   addiu $s0, $s0, 1
/* 02BD44 80050944 0C014E31 */  jal   func_800538C4
/* 02BD48 80050948 00000000 */   nop   
.L8005094C:
/* 02BD4C 8005094C 320200FF */  andi  $v0, $s0, 0xff
/* 02BD50 80050950 2C420018 */  sltiu $v0, $v0, 0x18
/* 02BD54 80050954 1440FFF1 */  bnez  $v0, .L8005091C
/* 02BD58 80050958 320500FF */   andi  $a1, $s0, 0xff
/* 02BD5C 8005095C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 02BD60 80050960 8FB10014 */  lw    $s1, 0x14($sp)
/* 02BD64 80050964 8FB00010 */  lw    $s0, 0x10($sp)
/* 02BD68 80050968 03E00008 */  jr    $ra
/* 02BD6C 8005096C 27BD0020 */   addiu $sp, $sp, 0x20

