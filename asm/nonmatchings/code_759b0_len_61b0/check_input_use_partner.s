.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel check_input_use_partner
/* 78EB0 800DFA00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78EB4 800DFA04 3C038011 */  lui       $v1, 0x8011
/* 78EB8 800DFA08 2463EFC8 */  addiu     $v1, $v1, -0x1038
/* 78EBC 800DFA0C AFBF0010 */  sw        $ra, 0x10($sp)
/* 78EC0 800DFA10 8C640004 */  lw        $a0, 4($v1)
/* 78EC4 800DFA14 806600B4 */  lb        $a2, 0xb4($v1)
/* 78EC8 800DFA18 30824000 */  andi      $v0, $a0, 0x4000
/* 78ECC 800DFA1C 14400020 */  bnez      $v0, .L800DFAA0
/* 78ED0 800DFA20 0060282D */   daddu    $a1, $v1, $zero
/* 78ED4 800DFA24 30820008 */  andi      $v0, $a0, 8
/* 78ED8 800DFA28 14400004 */  bnez      $v0, .L800DFA3C
/* 78EDC 800DFA2C 00000000 */   nop      
/* 78EE0 800DFA30 80620015 */  lb        $v0, 0x15($v1)
/* 78EE4 800DFA34 1440001A */  bnez      $v0, .L800DFAA0
/* 78EE8 800DFA38 00000000 */   nop      
.L800DFA3C:
/* 78EEC 800DFA3C 8CA300E0 */  lw        $v1, 0xe0($a1)
/* 78EF0 800DFA40 30620004 */  andi      $v0, $v1, 4
/* 78EF4 800DFA44 10400016 */  beqz      $v0, .L800DFAA0
/* 78EF8 800DFA48 00000000 */   nop      
/* 78EFC 800DFA4C 8CA20000 */  lw        $v0, ($a1)
/* 78F00 800DFA50 30420080 */  andi      $v0, $v0, 0x80
/* 78F04 800DFA54 14400012 */  bnez      $v0, .L800DFAA0
/* 78F08 800DFA58 30624000 */   andi     $v0, $v1, 0x4000
/* 78F0C 800DFA5C 14400010 */  bnez      $v0, .L800DFAA0
/* 78F10 800DFA60 30821000 */   andi     $v0, $a0, 0x1000
/* 78F14 800DFA64 1440000E */  bnez      $v0, .L800DFAA0
/* 78F18 800DFA68 2CC20003 */   sltiu    $v0, $a2, 3
/* 78F1C 800DFA6C 1040000C */  beqz      $v0, .L800DFAA0
/* 78F20 800DFA70 00000000 */   nop      
/* 78F24 800DFA74 3C028011 */  lui       $v0, 0x8011
/* 78F28 800DFA78 2442F290 */  addiu     $v0, $v0, -0xd70
/* 78F2C 800DFA7C 80430012 */  lb        $v1, 0x12($v0)
/* 78F30 800DFA80 24020001 */  addiu     $v0, $zero, 1
/* 78F34 800DFA84 14620004 */  bne       $v1, $v0, .L800DFA98
/* 78F38 800DFA88 00000000 */   nop      
/* 78F3C 800DFA8C 84A200C6 */  lh        $v0, 0xc6($a1)
/* 78F40 800DFA90 3C01802C */  lui       $at, 0x802c
/* 78F44 800DFA94 AC22DF60 */  sw        $v0, -0x20a0($at)
.L800DFA98:
/* 78F48 800DFA98 0C03ACC5 */  jal       partner_use_ability
/* 78F4C 800DFA9C 00000000 */   nop      
.L800DFAA0:
/* 78F50 800DFAA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 78F54 800DFAA4 03E00008 */  jr        $ra
/* 78F58 800DFAA8 27BD0018 */   addiu    $sp, $sp, 0x18
