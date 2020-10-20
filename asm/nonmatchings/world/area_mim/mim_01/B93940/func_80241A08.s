.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A08
/* B94E48 80241A08 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B94E4C 80241A0C AFB10034 */  sw        $s1, 0x34($sp)
/* B94E50 80241A10 0080882D */  daddu     $s1, $a0, $zero
/* B94E54 80241A14 AFBF0038 */  sw        $ra, 0x38($sp)
/* B94E58 80241A18 AFB00030 */  sw        $s0, 0x30($sp)
/* B94E5C 80241A1C 8E300148 */  lw        $s0, 0x148($s1)
/* B94E60 80241A20 0C00EABB */  jal       get_npc_unsafe
/* B94E64 80241A24 86040008 */   lh       $a0, 8($s0)
/* B94E68 80241A28 0040282D */  daddu     $a1, $v0, $zero
/* B94E6C 80241A2C 94A2008E */  lhu       $v0, 0x8e($a1)
/* B94E70 80241A30 24420001 */  addiu     $v0, $v0, 1
/* B94E74 80241A34 A4A2008E */  sh        $v0, 0x8e($a1)
/* B94E78 80241A38 00021400 */  sll       $v0, $v0, 0x10
/* B94E7C 80241A3C 8E0300A0 */  lw        $v1, 0xa0($s0)
/* B94E80 80241A40 00021403 */  sra       $v0, $v0, 0x10
/* B94E84 80241A44 14430004 */  bne       $v0, $v1, .L80241A58
/* B94E88 80241A48 00000000 */   nop      
/* B94E8C 80241A4C 8E0200CC */  lw        $v0, 0xcc($s0)
/* B94E90 80241A50 8C42002C */  lw        $v0, 0x2c($v0)
/* B94E94 80241A54 ACA20028 */  sw        $v0, 0x28($a1)
.L80241A58:
/* B94E98 80241A58 84A3008E */  lh        $v1, 0x8e($a1)
/* B94E9C 80241A5C 8E0200A4 */  lw        $v0, 0xa4($s0)
/* B94EA0 80241A60 14620002 */  bne       $v1, $v0, .L80241A6C
/* B94EA4 80241A64 24020003 */   addiu    $v0, $zero, 3
/* B94EA8 80241A68 AE02006C */  sw        $v0, 0x6c($s0)
.L80241A6C:
/* B94EAC 80241A6C 84A2008E */  lh        $v0, 0x8e($a1)
/* B94EB0 80241A70 8E03009C */  lw        $v1, 0x9c($s0)
/* B94EB4 80241A74 0043102A */  slt       $v0, $v0, $v1
/* B94EB8 80241A78 1440001E */  bnez      $v0, .L80241AF4
/* B94EBC 80241A7C 24020004 */   addiu    $v0, $zero, 4
/* B94EC0 80241A80 AE02006C */  sw        $v0, 0x6c($s0)
/* B94EC4 80241A84 24020008 */  addiu     $v0, $zero, 8
/* B94EC8 80241A88 24040003 */  addiu     $a0, $zero, 3
/* B94ECC 80241A8C A4A2008E */  sh        $v0, 0x8e($a1)
/* B94ED0 80241A90 8E0200CC */  lw        $v0, 0xcc($s0)
/* B94ED4 80241A94 84A300A8 */  lh        $v1, 0xa8($a1)
/* B94ED8 80241A98 3C013F80 */  lui       $at, 0x3f80
/* B94EDC 80241A9C 44810000 */  mtc1      $at, $f0
/* B94EE0 80241AA0 3C014000 */  lui       $at, 0x4000
/* B94EE4 80241AA4 44811000 */  mtc1      $at, $f2
/* B94EE8 80241AA8 3C01C1A0 */  lui       $at, 0xc1a0
/* B94EEC 80241AAC 44812000 */  mtc1      $at, $f4
/* B94EF0 80241AB0 44833000 */  mtc1      $v1, $f6
/* B94EF4 80241AB4 00000000 */  nop       
/* B94EF8 80241AB8 468031A0 */  cvt.s.w   $f6, $f6
/* B94EFC 80241ABC 8C420000 */  lw        $v0, ($v0)
/* B94F00 80241AC0 44073000 */  mfc1      $a3, $f6
/* B94F04 80241AC4 0000302D */  daddu     $a2, $zero, $zero
/* B94F08 80241AC8 ACA20028 */  sw        $v0, 0x28($a1)
/* B94F0C 80241ACC 2402000A */  addiu     $v0, $zero, 0xa
/* B94F10 80241AD0 AFA2001C */  sw        $v0, 0x1c($sp)
/* B94F14 80241AD4 27A20028 */  addiu     $v0, $sp, 0x28
/* B94F18 80241AD8 E7A00010 */  swc1      $f0, 0x10($sp)
/* B94F1C 80241ADC E7A20014 */  swc1      $f2, 0x14($sp)
/* B94F20 80241AE0 E7A40018 */  swc1      $f4, 0x18($sp)
/* B94F24 80241AE4 0C01BFA4 */  jal       fx_emote
/* B94F28 80241AE8 AFA20020 */   sw       $v0, 0x20($sp)
/* B94F2C 80241AEC 2402000D */  addiu     $v0, $zero, 0xd
/* B94F30 80241AF0 AE220070 */  sw        $v0, 0x70($s1)
.L80241AF4:
/* B94F34 80241AF4 8FBF0038 */  lw        $ra, 0x38($sp)
/* B94F38 80241AF8 8FB10034 */  lw        $s1, 0x34($sp)
/* B94F3C 80241AFC 8FB00030 */  lw        $s0, 0x30($sp)
/* B94F40 80241B00 03E00008 */  jr        $ra
/* B94F44 80241B04 27BD0040 */   addiu    $sp, $sp, 0x40
