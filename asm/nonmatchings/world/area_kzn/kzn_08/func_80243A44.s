.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243A44
/* C74EC4 80243A44 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C74EC8 80243A48 AFB10034 */  sw        $s1, 0x34($sp)
/* C74ECC 80243A4C 0080882D */  daddu     $s1, $a0, $zero
/* C74ED0 80243A50 AFBF0038 */  sw        $ra, 0x38($sp)
/* C74ED4 80243A54 AFB00030 */  sw        $s0, 0x30($sp)
/* C74ED8 80243A58 8E300148 */  lw        $s0, 0x148($s1)
/* C74EDC 80243A5C 0C00EABB */  jal       get_npc_unsafe
/* C74EE0 80243A60 86040008 */   lh       $a0, 8($s0)
/* C74EE4 80243A64 0040282D */  daddu     $a1, $v0, $zero
/* C74EE8 80243A68 94A2008E */  lhu       $v0, 0x8e($a1)
/* C74EEC 80243A6C 24420001 */  addiu     $v0, $v0, 1
/* C74EF0 80243A70 A4A2008E */  sh        $v0, 0x8e($a1)
/* C74EF4 80243A74 00021400 */  sll       $v0, $v0, 0x10
/* C74EF8 80243A78 8E0300A0 */  lw        $v1, 0xa0($s0)
/* C74EFC 80243A7C 00021403 */  sra       $v0, $v0, 0x10
/* C74F00 80243A80 14430004 */  bne       $v0, $v1, .L80243A94
/* C74F04 80243A84 00000000 */   nop      
/* C74F08 80243A88 8E0200CC */  lw        $v0, 0xcc($s0)
/* C74F0C 80243A8C 8C42002C */  lw        $v0, 0x2c($v0)
/* C74F10 80243A90 ACA20028 */  sw        $v0, 0x28($a1)
.L80243A94:
/* C74F14 80243A94 84A3008E */  lh        $v1, 0x8e($a1)
/* C74F18 80243A98 8E0200A4 */  lw        $v0, 0xa4($s0)
/* C74F1C 80243A9C 14620002 */  bne       $v1, $v0, .L80243AA8
/* C74F20 80243AA0 24020003 */   addiu    $v0, $zero, 3
/* C74F24 80243AA4 AE02006C */  sw        $v0, 0x6c($s0)
.L80243AA8:
/* C74F28 80243AA8 84A2008E */  lh        $v0, 0x8e($a1)
/* C74F2C 80243AAC 8E03009C */  lw        $v1, 0x9c($s0)
/* C74F30 80243AB0 0043102A */  slt       $v0, $v0, $v1
/* C74F34 80243AB4 1440001E */  bnez      $v0, .L80243B30
/* C74F38 80243AB8 24020004 */   addiu    $v0, $zero, 4
/* C74F3C 80243ABC AE02006C */  sw        $v0, 0x6c($s0)
/* C74F40 80243AC0 24020008 */  addiu     $v0, $zero, 8
/* C74F44 80243AC4 24040003 */  addiu     $a0, $zero, 3
/* C74F48 80243AC8 A4A2008E */  sh        $v0, 0x8e($a1)
/* C74F4C 80243ACC 8E0200CC */  lw        $v0, 0xcc($s0)
/* C74F50 80243AD0 84A300A8 */  lh        $v1, 0xa8($a1)
/* C74F54 80243AD4 3C013F80 */  lui       $at, 0x3f80
/* C74F58 80243AD8 44810000 */  mtc1      $at, $f0
/* C74F5C 80243ADC 3C014000 */  lui       $at, 0x4000
/* C74F60 80243AE0 44811000 */  mtc1      $at, $f2
/* C74F64 80243AE4 3C01C1A0 */  lui       $at, 0xc1a0
/* C74F68 80243AE8 44812000 */  mtc1      $at, $f4
/* C74F6C 80243AEC 44833000 */  mtc1      $v1, $f6
/* C74F70 80243AF0 00000000 */  nop       
/* C74F74 80243AF4 468031A0 */  cvt.s.w   $f6, $f6
/* C74F78 80243AF8 8C420000 */  lw        $v0, ($v0)
/* C74F7C 80243AFC 44073000 */  mfc1      $a3, $f6
/* C74F80 80243B00 0000302D */  daddu     $a2, $zero, $zero
/* C74F84 80243B04 ACA20028 */  sw        $v0, 0x28($a1)
/* C74F88 80243B08 2402000A */  addiu     $v0, $zero, 0xa
/* C74F8C 80243B0C AFA2001C */  sw        $v0, 0x1c($sp)
/* C74F90 80243B10 27A20028 */  addiu     $v0, $sp, 0x28
/* C74F94 80243B14 E7A00010 */  swc1      $f0, 0x10($sp)
/* C74F98 80243B18 E7A20014 */  swc1      $f2, 0x14($sp)
/* C74F9C 80243B1C E7A40018 */  swc1      $f4, 0x18($sp)
/* C74FA0 80243B20 0C01BFA4 */  jal       fx_emote
/* C74FA4 80243B24 AFA20020 */   sw       $v0, 0x20($sp)
/* C74FA8 80243B28 2402000D */  addiu     $v0, $zero, 0xd
/* C74FAC 80243B2C AE220070 */  sw        $v0, 0x70($s1)
.L80243B30:
/* C74FB0 80243B30 8FBF0038 */  lw        $ra, 0x38($sp)
/* C74FB4 80243B34 8FB10034 */  lw        $s1, 0x34($sp)
/* C74FB8 80243B38 8FB00030 */  lw        $s0, 0x30($sp)
/* C74FBC 80243B3C 03E00008 */  jr        $ra
/* C74FC0 80243B40 27BD0040 */   addiu    $sp, $sp, 0x40
