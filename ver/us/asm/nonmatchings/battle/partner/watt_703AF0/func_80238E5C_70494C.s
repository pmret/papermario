.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel battle_partner_watt_AverageTargetParalyzeChance
/* 70494C 80238E5C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 704950 80238E60 AFB60028 */  sw        $s6, 0x28($sp)
/* 704954 80238E64 3C16800E */  lui       $s6, %hi(gBattleStatus+0xDC)
/* 704958 80238E68 8ED6C14C */  lw        $s6, %lo(gBattleStatus+0xDC)($s6)
/* 70495C 80238E6C AFBE0030 */  sw        $fp, 0x30($sp)
/* 704960 80238E70 0080F02D */  daddu     $fp, $a0, $zero
/* 704964 80238E74 AFB40020 */  sw        $s4, 0x20($sp)
/* 704968 80238E78 0000A02D */  daddu     $s4, $zero, $zero
/* 70496C 80238E7C AFB50024 */  sw        $s5, 0x24($sp)
/* 704970 80238E80 0280A82D */  daddu     $s5, $s4, $zero
/* 704974 80238E84 AFBF0034 */  sw        $ra, 0x34($sp)
/* 704978 80238E88 AFB7002C */  sw        $s7, 0x2c($sp)
/* 70497C 80238E8C AFB3001C */  sw        $s3, 0x1c($sp)
/* 704980 80238E90 AFB20018 */  sw        $s2, 0x18($sp)
/* 704984 80238E94 AFB10014 */  sw        $s1, 0x14($sp)
/* 704988 80238E98 AFB00010 */  sw        $s0, 0x10($sp)
/* 70498C 80238E9C 82C2040C */  lb        $v0, 0x40c($s6)
/* 704990 80238EA0 1840001E */  blez      $v0, .L80238F1C
/* 704994 80238EA4 0280982D */   daddu    $s3, $s4, $zero
/* 704998 80238EA8 2417000E */  addiu     $s7, $zero, 0xe
/* 70499C 80238EAC 02C0902D */  daddu     $s2, $s6, $zero
.L80238EB0:
/* 7049A0 80238EB0 0C09A75B */  jal       get_actor
/* 7049A4 80238EB4 8644022C */   lh       $a0, 0x22c($s2)
/* 7049A8 80238EB8 0040802D */  daddu     $s0, $v0, $zero
/* 7049AC 80238EBC 8645022E */  lh        $a1, 0x22e($s2)
/* 7049B0 80238EC0 0C099117 */  jal       get_actor_part
/* 7049B4 80238EC4 0200202D */   daddu    $a0, $s0, $zero
/* 7049B8 80238EC8 24050005 */  addiu     $a1, $zero, 5
/* 7049BC 80238ECC 8E04020C */  lw        $a0, 0x20c($s0)
/* 7049C0 80238ED0 0C0997A6 */  jal       lookup_status_chance
/* 7049C4 80238ED4 0040882D */   daddu    $s1, $v0, $zero
/* 7049C8 80238ED8 82030218 */  lb        $v1, 0x218($s0)
/* 7049CC 80238EDC 14770002 */  bne       $v1, $s7, .L80238EE8
/* 7049D0 80238EE0 0040202D */   daddu    $a0, $v0, $zero
/* 7049D4 80238EE4 0000202D */  daddu     $a0, $zero, $zero
.L80238EE8:
/* 7049D8 80238EE8 8E22007C */  lw        $v0, 0x7c($s1)
/* 7049DC 80238EEC 30420020 */  andi      $v0, $v0, 0x20
/* 7049E0 80238EF0 54400001 */  bnel      $v0, $zero, .L80238EF8
/* 7049E4 80238EF4 0000202D */   daddu    $a0, $zero, $zero
.L80238EF8:
/* 7049E8 80238EF8 18800003 */  blez      $a0, .L80238F08
/* 7049EC 80238EFC 00000000 */   nop
/* 7049F0 80238F00 02649821 */  addu      $s3, $s3, $a0
/* 7049F4 80238F04 26940001 */  addiu     $s4, $s4, 1
.L80238F08:
/* 7049F8 80238F08 82C2040C */  lb        $v0, 0x40c($s6)
/* 7049FC 80238F0C 26B50001 */  addiu     $s5, $s5, 1
/* 704A00 80238F10 02A2102A */  slt       $v0, $s5, $v0
/* 704A04 80238F14 1440FFE6 */  bnez      $v0, .L80238EB0
/* 704A08 80238F18 26520014 */   addiu    $s2, $s2, 0x14
.L80238F1C:
/* 704A0C 80238F1C 5A80000C */  blezl     $s4, .L80238F50
/* 704A10 80238F20 AFC00084 */   sw       $zero, 0x84($fp)
/* 704A14 80238F24 16800002 */  bnez      $s4, .L80238F30
/* 704A18 80238F28 0274001A */   div      $zero, $s3, $s4
/* 704A1C 80238F2C 0007000D */  break     7
.L80238F30:
/* 704A20 80238F30 2401FFFF */   addiu    $at, $zero, -1
/* 704A24 80238F34 16810004 */  bne       $s4, $at, .L80238F48
/* 704A28 80238F38 3C018000 */   lui      $at, 0x8000
/* 704A2C 80238F3C 16610002 */  bne       $s3, $at, .L80238F48
/* 704A30 80238F40 00000000 */   nop
/* 704A34 80238F44 0006000D */  break     6
.L80238F48:
/* 704A38 80238F48 00001012 */   mflo     $v0
/* 704A3C 80238F4C AFC20084 */  sw        $v0, 0x84($fp)
.L80238F50:
/* 704A40 80238F50 8FBF0034 */  lw        $ra, 0x34($sp)
/* 704A44 80238F54 8FBE0030 */  lw        $fp, 0x30($sp)
/* 704A48 80238F58 8FB7002C */  lw        $s7, 0x2c($sp)
/* 704A4C 80238F5C 8FB60028 */  lw        $s6, 0x28($sp)
/* 704A50 80238F60 8FB50024 */  lw        $s5, 0x24($sp)
/* 704A54 80238F64 8FB40020 */  lw        $s4, 0x20($sp)
/* 704A58 80238F68 8FB3001C */  lw        $s3, 0x1c($sp)
/* 704A5C 80238F6C 8FB20018 */  lw        $s2, 0x18($sp)
/* 704A60 80238F70 8FB10014 */  lw        $s1, 0x14($sp)
/* 704A64 80238F74 8FB00010 */  lw        $s0, 0x10($sp)
/* 704A68 80238F78 24020002 */  addiu     $v0, $zero, 2
/* 704A6C 80238F7C 03E00008 */  jr        $ra
/* 704A70 80238F80 27BD0038 */   addiu    $sp, $sp, 0x38
/* 704A74 80238F84 00000000 */  nop
/* 704A78 80238F88 00000000 */  nop
/* 704A7C 80238F8C 00000000 */  nop
