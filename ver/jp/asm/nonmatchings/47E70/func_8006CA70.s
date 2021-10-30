.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006CA70
/* 47E70 8006CA70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 47E74 8006CA74 AFB00010 */  sw        $s0, 0x10($sp)
/* 47E78 8006CA78 3C108009 */  lui       $s0, %hi(D_80095900)
/* 47E7C 8006CA7C 26105900 */  addiu     $s0, $s0, %lo(D_80095900)
/* 47E80 8006CA80 02002021 */  addu      $a0, $s0, $zero
/* 47E84 8006CA84 AFBF0014 */  sw        $ra, 0x14($sp)
/* 47E88 8006CA88 0C019250 */  jal       func_80064940
/* 47E8C 8006CA8C 24050060 */   addiu    $a1, $zero, 0x60
/* 47E90 8006CA90 3C038000 */  lui       $v1, %hi(osTvType)
/* 47E94 8006CA94 8C630300 */  lw        $v1, %lo(osTvType)($v1)
/* 47E98 8006CA98 3C018009 */  lui       $at, %hi(D_80095960)
/* 47E9C 8006CA9C AC305960 */  sw        $s0, %lo(D_80095960)($at)
/* 47EA0 8006CAA0 26100030 */  addiu     $s0, $s0, 0x30
/* 47EA4 8006CAA4 24020001 */  addiu     $v0, $zero, 1
/* 47EA8 8006CAA8 3C018009 */  lui       $at, %hi(D_80095932)
/* 47EAC 8006CAAC A4225932 */  sh        $v0, %lo(D_80095932)($at)
/* 47EB0 8006CAB0 3C018009 */  lui       $at, %hi(D_80095902)
/* 47EB4 8006CAB4 A4225902 */  sh        $v0, %lo(D_80095902)($at)
/* 47EB8 8006CAB8 3C028000 */  lui       $v0, 0x8000
/* 47EBC 8006CABC 3C018009 */  lui       $at, %hi(D_80095964)
/* 47EC0 8006CAC0 AC305964 */  sw        $s0, %lo(D_80095964)($at)
/* 47EC4 8006CAC4 3C018009 */  lui       $at, %hi(D_80095934)
/* 47EC8 8006CAC8 AC225934 */  sw        $v0, %lo(D_80095934)($at)
/* 47ECC 8006CACC 3C018009 */  lui       $at, %hi(D_80095904)
/* 47ED0 8006CAD0 AC225904 */  sw        $v0, %lo(D_80095904)($at)
/* 47ED4 8006CAD4 14600004 */  bnez      $v1, .L8006CAE8
/* 47ED8 8006CAD8 24020002 */   addiu    $v0, $zero, 2
/* 47EDC 8006CADC 3C028009 */  lui       $v0, %hi(D_80095970)
/* 47EE0 8006CAE0 0801B2C1 */  j         .L8006CB04
/* 47EE4 8006CAE4 24425970 */   addiu    $v0, $v0, %lo(D_80095970)
.L8006CAE8:
/* 47EE8 8006CAE8 14620004 */  bne       $v1, $v0, .L8006CAFC
/* 47EEC 8006CAEC 00000000 */   nop
/* 47EF0 8006CAF0 3C028009 */  lui       $v0, %hi(D_800959C0)
/* 47EF4 8006CAF4 0801B2C1 */  j         .L8006CB04
/* 47EF8 8006CAF8 244259C0 */   addiu    $v0, $v0, %lo(D_800959C0)
.L8006CAFC:
/* 47EFC 8006CAFC 3C028009 */  lui       $v0, %hi(D_80095800)
/* 47F00 8006CB00 24425800 */  addiu     $v0, $v0, %lo(D_80095800)
.L8006CB04:
/* 47F04 8006CB04 3C018009 */  lui       $at, %hi(D_80095938)
/* 47F08 8006CB08 AC225938 */  sw        $v0, %lo(D_80095938)($at)
/* 47F0C 8006CB0C 3C038009 */  lui       $v1, %hi(D_80095964)
/* 47F10 8006CB10 8C635964 */  lw        $v1, %lo(D_80095964)($v1)
/* 47F14 8006CB14 8C640008 */  lw        $a0, 8($v1)
/* 47F18 8006CB18 24020020 */  addiu     $v0, $zero, 0x20
/* 47F1C 8006CB1C A4620000 */  sh        $v0, ($v1)
/* 47F20 8006CB20 8C820004 */  lw        $v0, 4($a0)
/* 47F24 8006CB24 3C04A440 */  lui       $a0, 0xa440
/* 47F28 8006CB28 34840010 */  ori       $a0, $a0, 0x10
/* 47F2C 8006CB2C AC62000C */  sw        $v0, 0xc($v1)
/* 47F30 8006CB30 8C820000 */  lw        $v0, ($a0)
/* 47F34 8006CB34 2C42000B */  sltiu     $v0, $v0, 0xb
/* 47F38 8006CB38 14400007 */  bnez      $v0, .L8006CB58
/* 47F3C 8006CB3C 3C02A440 */   lui      $v0, 0xa440
/* 47F40 8006CB40 3C03A440 */  lui       $v1, 0xa440
/* 47F44 8006CB44 34630010 */  ori       $v1, $v1, 0x10
.L8006CB48:
/* 47F48 8006CB48 8C620000 */  lw        $v0, ($v1)
/* 47F4C 8006CB4C 2C42000B */  sltiu     $v0, $v0, 0xb
/* 47F50 8006CB50 1040FFFD */  beqz      $v0, .L8006CB48
/* 47F54 8006CB54 3C02A440 */   lui      $v0, 0xa440
.L8006CB58:
/* 47F58 8006CB58 AC400000 */  sw        $zero, ($v0)
/* 47F5C 8006CB5C 0C019C10 */  jal       func_80067040
/* 47F60 8006CB60 00000000 */   nop
/* 47F64 8006CB64 8FBF0014 */  lw        $ra, 0x14($sp)
/* 47F68 8006CB68 8FB00010 */  lw        $s0, 0x10($sp)
/* 47F6C 8006CB6C 03E00008 */  jr        $ra
/* 47F70 8006CB70 27BD0018 */   addiu    $sp, $sp, 0x18
/* 47F74 8006CB74 00000000 */  nop
/* 47F78 8006CB78 00000000 */  nop
/* 47F7C 8006CB7C 00000000 */  nop
