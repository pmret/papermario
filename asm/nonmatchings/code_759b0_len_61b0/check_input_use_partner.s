.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel check_input_use_partner
/* 078EB0 800DFA00 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 078EB4 800DFA04 3C038011 */  lui   $v1, 0x8011
/* 078EB8 800DFA08 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 078EBC 800DFA0C AFBF0010 */  sw    $ra, 0x10($sp)
/* 078EC0 800DFA10 8C640004 */  lw    $a0, 4($v1)
/* 078EC4 800DFA14 806600B4 */  lb    $a2, 0xb4($v1)
/* 078EC8 800DFA18 30824000 */  andi  $v0, $a0, 0x4000
/* 078ECC 800DFA1C 14400020 */  bnez  $v0, .L800DFAA0
/* 078ED0 800DFA20 0060282D */   daddu $a1, $v1, $zero
/* 078ED4 800DFA24 30820008 */  andi  $v0, $a0, 8
/* 078ED8 800DFA28 14400004 */  bnez  $v0, .L800DFA3C
/* 078EDC 800DFA2C 00000000 */   nop   
/* 078EE0 800DFA30 80620015 */  lb    $v0, 0x15($v1)
/* 078EE4 800DFA34 1440001A */  bnez  $v0, .L800DFAA0
/* 078EE8 800DFA38 00000000 */   nop   
.L800DFA3C:
/* 078EEC 800DFA3C 8CA300E0 */  lw    $v1, 0xe0($a1)
/* 078EF0 800DFA40 30620004 */  andi  $v0, $v1, 4
/* 078EF4 800DFA44 10400016 */  beqz  $v0, .L800DFAA0
/* 078EF8 800DFA48 00000000 */   nop   
/* 078EFC 800DFA4C 8CA20000 */  lw    $v0, ($a1)
/* 078F00 800DFA50 30420080 */  andi  $v0, $v0, 0x80
/* 078F04 800DFA54 14400012 */  bnez  $v0, .L800DFAA0
/* 078F08 800DFA58 30624000 */   andi  $v0, $v1, 0x4000
/* 078F0C 800DFA5C 14400010 */  bnez  $v0, .L800DFAA0
/* 078F10 800DFA60 30821000 */   andi  $v0, $a0, 0x1000
/* 078F14 800DFA64 1440000E */  bnez  $v0, .L800DFAA0
/* 078F18 800DFA68 2CC20003 */   sltiu $v0, $a2, 3
/* 078F1C 800DFA6C 1040000C */  beqz  $v0, .L800DFAA0
/* 078F20 800DFA70 00000000 */   nop   
/* 078F24 800DFA74 3C028011 */  lui   $v0, 0x8011
/* 078F28 800DFA78 2442F290 */  addiu $v0, $v0, -0xd70
/* 078F2C 800DFA7C 80430012 */  lb    $v1, 0x12($v0)
/* 078F30 800DFA80 24020001 */  addiu $v0, $zero, 1
/* 078F34 800DFA84 14620004 */  bne   $v1, $v0, .L800DFA98
/* 078F38 800DFA88 00000000 */   nop   
/* 078F3C 800DFA8C 84A200C6 */  lh    $v0, 0xc6($a1)
/* 078F40 800DFA90 3C01802C */  lui   $at, 0x802c
/* 078F44 800DFA94 AC22DF60 */  sw    $v0, -0x20a0($at)
.L800DFA98:
/* 078F48 800DFA98 0C03ACC5 */  jal   use_partner_ability
/* 078F4C 800DFA9C 00000000 */   nop   
.L800DFAA0:
/* 078F50 800DFAA0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 078F54 800DFAA4 03E00008 */  jr    $ra
/* 078F58 800DFAA8 27BD0018 */   addiu $sp, $sp, 0x18

