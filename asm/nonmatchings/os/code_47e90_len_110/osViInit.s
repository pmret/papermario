.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViInit
/* 47E90 8006CA90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 47E94 8006CA94 AFB00010 */  sw        $s0, 0x10($sp)
/* 47E98 8006CA98 3C108009 */  lui       $s0, 0x8009
/* 47E9C 8006CA9C 26105970 */  addiu     $s0, $s0, 0x5970
/* 47EA0 8006CAA0 02002021 */  addu      $a0, $s0, $zero
/* 47EA4 8006CAA4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 47EA8 8006CAA8 0C01925C */  jal       bzero
/* 47EAC 8006CAAC 24050060 */   addiu    $a1, $zero, 0x60
/* 47EB0 8006CAB0 3C038000 */  lui       $v1, 0x8000
/* 47EB4 8006CAB4 8C630300 */  lw        $v1, 0x300($v1)
/* 47EB8 8006CAB8 3C018009 */  lui       $at, 0x8009
/* 47EBC 8006CABC AC3059D0 */  sw        $s0, 0x59d0($at)
/* 47EC0 8006CAC0 26100030 */  addiu     $s0, $s0, 0x30
/* 47EC4 8006CAC4 24020001 */  addiu     $v0, $zero, 1
/* 47EC8 8006CAC8 3C018009 */  lui       $at, 0x8009
/* 47ECC 8006CACC A42259A2 */  sh        $v0, 0x59a2($at)
/* 47ED0 8006CAD0 3C018009 */  lui       $at, 0x8009
/* 47ED4 8006CAD4 A4225972 */  sh        $v0, 0x5972($at)
/* 47ED8 8006CAD8 3C028000 */  lui       $v0, 0x8000
/* 47EDC 8006CADC 3C018009 */  lui       $at, %hi(D_800959D4)
/* 47EE0 8006CAE0 AC3059D4 */  sw        $s0, %lo(D_800959D4)($at)
/* 47EE4 8006CAE4 3C018009 */  lui       $at, 0x8009
/* 47EE8 8006CAE8 AC2259A4 */  sw        $v0, 0x59a4($at)
/* 47EEC 8006CAEC 3C018009 */  lui       $at, 0x8009
/* 47EF0 8006CAF0 AC225974 */  sw        $v0, 0x5974($at)
/* 47EF4 8006CAF4 14600004 */  bnez      $v1, .L8006CB08
/* 47EF8 8006CAF8 24020002 */   addiu    $v0, $zero, 2
/* 47EFC 8006CAFC 3C028009 */  lui       $v0, 0x8009
/* 47F00 8006CB00 0801B2C9 */  j         .L8006CB24
/* 47F04 8006CB04 244259E0 */   addiu    $v0, $v0, 0x59e0
.L8006CB08:
/* 47F08 8006CB08 14620004 */  bne       $v1, $v0, .L8006CB1C
/* 47F0C 8006CB0C 00000000 */   nop      
/* 47F10 8006CB10 3C028009 */  lui       $v0, 0x8009
/* 47F14 8006CB14 0801B2C9 */  j         .L8006CB24
/* 47F18 8006CB18 24425870 */   addiu    $v0, $v0, 0x5870
.L8006CB1C:
/* 47F1C 8006CB1C 3C028009 */  lui       $v0, 0x8009
/* 47F20 8006CB20 24425820 */  addiu     $v0, $v0, 0x5820
.L8006CB24:
/* 47F24 8006CB24 3C018009 */  lui       $at, 0x8009
/* 47F28 8006CB28 AC2259A8 */  sw        $v0, 0x59a8($at)
/* 47F2C 8006CB2C 3C038009 */  lui       $v1, %hi(D_800959D4)
/* 47F30 8006CB30 8C6359D4 */  lw        $v1, %lo(D_800959D4)($v1)
/* 47F34 8006CB34 8C640008 */  lw        $a0, 8($v1)
/* 47F38 8006CB38 24020020 */  addiu     $v0, $zero, 0x20
/* 47F3C 8006CB3C A4620000 */  sh        $v0, ($v1)
/* 47F40 8006CB40 8C820004 */  lw        $v0, 4($a0)
/* 47F44 8006CB44 3C04A440 */  lui       $a0, 0xa440
/* 47F48 8006CB48 34840010 */  ori       $a0, $a0, 0x10
/* 47F4C 8006CB4C AC62000C */  sw        $v0, 0xc($v1)
/* 47F50 8006CB50 8C820000 */  lw        $v0, ($a0)
/* 47F54 8006CB54 2C42000B */  sltiu     $v0, $v0, 0xb
/* 47F58 8006CB58 14400007 */  bnez      $v0, .L8006CB78
/* 47F5C 8006CB5C 3C02A440 */   lui      $v0, 0xa440
/* 47F60 8006CB60 3C03A440 */  lui       $v1, 0xa440
/* 47F64 8006CB64 34630010 */  ori       $v1, $v1, 0x10
.L8006CB68:
/* 47F68 8006CB68 8C620000 */  lw        $v0, ($v1)
/* 47F6C 8006CB6C 2C42000B */  sltiu     $v0, $v0, 0xb
/* 47F70 8006CB70 1040FFFD */  beqz      $v0, .L8006CB68
/* 47F74 8006CB74 3C02A440 */   lui      $v0, 0xa440
.L8006CB78:
/* 47F78 8006CB78 AC400000 */  sw        $zero, ($v0)
/* 47F7C 8006CB7C 0C019C1C */  jal       osViSwapContext
/* 47F80 8006CB80 00000000 */   nop      
/* 47F84 8006CB84 8FBF0014 */  lw        $ra, 0x14($sp)
/* 47F88 8006CB88 8FB00010 */  lw        $s0, 0x10($sp)
/* 47F8C 8006CB8C 03E00008 */  jr        $ra
/* 47F90 8006CB90 27BD0018 */   addiu    $sp, $sp, 0x18
/* 47F94 8006CB94 00000000 */  nop       
/* 47F98 8006CB98 00000000 */  nop       
/* 47F9C 8006CB9C 00000000 */  nop       
