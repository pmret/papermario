.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F24
/* 919AD4 80240F24 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 919AD8 80240F28 AFB10014 */  sw        $s1, 0x14($sp)
/* 919ADC 80240F2C 0080882D */  daddu     $s1, $a0, $zero
/* 919AE0 80240F30 AFBF0018 */  sw        $ra, 0x18($sp)
/* 919AE4 80240F34 AFB00010 */  sw        $s0, 0x10($sp)
/* 919AE8 80240F38 8E300148 */  lw        $s0, 0x148($s1)
/* 919AEC 80240F3C 0C00EABB */  jal       get_npc_unsafe
/* 919AF0 80240F40 86040008 */   lh       $a0, 8($s0)
/* 919AF4 80240F44 0040182D */  daddu     $v1, $v0, $zero
/* 919AF8 80240F48 9462008E */  lhu       $v0, 0x8e($v1)
/* 919AFC 80240F4C 2442FFFF */  addiu     $v0, $v0, -1
/* 919B00 80240F50 A462008E */  sh        $v0, 0x8e($v1)
/* 919B04 80240F54 00021400 */  sll       $v0, $v0, 0x10
/* 919B08 80240F58 1C400007 */  bgtz      $v0, .L80240F78
/* 919B0C 80240F5C 24020008 */   addiu    $v0, $zero, 8
/* 919B10 80240F60 A462008E */  sh        $v0, 0x8e($v1)
/* 919B14 80240F64 8E0200CC */  lw        $v0, 0xcc($s0)
/* 919B18 80240F68 8C420038 */  lw        $v0, 0x38($v0)
/* 919B1C 80240F6C AC620028 */  sw        $v0, 0x28($v1)
/* 919B20 80240F70 24020034 */  addiu     $v0, $zero, 0x34
/* 919B24 80240F74 AE220070 */  sw        $v0, 0x70($s1)
.L80240F78:
/* 919B28 80240F78 8FBF0018 */  lw        $ra, 0x18($sp)
/* 919B2C 80240F7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 919B30 80240F80 8FB00010 */  lw        $s0, 0x10($sp)
/* 919B34 80240F84 03E00008 */  jr        $ra
/* 919B38 80240F88 27BD0020 */   addiu    $sp, $sp, 0x20
