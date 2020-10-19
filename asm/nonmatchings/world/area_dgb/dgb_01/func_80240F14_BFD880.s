.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F14_BFE794
/* BFE794 80240F14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BFE798 80240F18 AFB00010 */  sw        $s0, 0x10($sp)
/* BFE79C 80240F1C 0080802D */  daddu     $s0, $a0, $zero
/* BFE7A0 80240F20 AFBF0014 */  sw        $ra, 0x14($sp)
/* BFE7A4 80240F24 8E020148 */  lw        $v0, 0x148($s0)
/* BFE7A8 80240F28 0C00EABB */  jal       get_npc_unsafe
/* BFE7AC 80240F2C 84440008 */   lh       $a0, 8($v0)
/* BFE7B0 80240F30 0040202D */  daddu     $a0, $v0, $zero
/* BFE7B4 80240F34 8482008E */  lh        $v0, 0x8e($a0)
/* BFE7B8 80240F38 9483008E */  lhu       $v1, 0x8e($a0)
/* BFE7BC 80240F3C 18400005 */  blez      $v0, .L80240F54
/* BFE7C0 80240F40 2462FFFF */   addiu    $v0, $v1, -1
/* BFE7C4 80240F44 A482008E */  sh        $v0, 0x8e($a0)
/* BFE7C8 80240F48 00021400 */  sll       $v0, $v0, 0x10
/* BFE7CC 80240F4C 1C400006 */  bgtz      $v0, .L80240F68
/* BFE7D0 80240F50 00000000 */   nop      
.L80240F54:
/* BFE7D4 80240F54 8482008C */  lh        $v0, 0x8c($a0)
/* BFE7D8 80240F58 14400003 */  bnez      $v0, .L80240F68
/* BFE7DC 80240F5C 2402000E */   addiu    $v0, $zero, 0xe
/* BFE7E0 80240F60 A480008E */  sh        $zero, 0x8e($a0)
/* BFE7E4 80240F64 AE020070 */  sw        $v0, 0x70($s0)
.L80240F68:
/* BFE7E8 80240F68 8FBF0014 */  lw        $ra, 0x14($sp)
/* BFE7EC 80240F6C 8FB00010 */  lw        $s0, 0x10($sp)
/* BFE7F0 80240F70 03E00008 */  jr        $ra
/* BFE7F4 80240F74 27BD0018 */   addiu    $sp, $sp, 0x18
