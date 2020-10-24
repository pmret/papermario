.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D44_882F04
/* 882F04 80240D44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 882F08 80240D48 AFB10014 */  sw        $s1, 0x14($sp)
/* 882F0C 80240D4C 0080882D */  daddu     $s1, $a0, $zero
/* 882F10 80240D50 AFBF0018 */  sw        $ra, 0x18($sp)
/* 882F14 80240D54 AFB00010 */  sw        $s0, 0x10($sp)
/* 882F18 80240D58 8E300148 */  lw        $s0, 0x148($s1)
/* 882F1C 80240D5C 0C00EABB */  jal       get_npc_unsafe
/* 882F20 80240D60 86040008 */   lh       $a0, 8($s0)
/* 882F24 80240D64 0040202D */  daddu     $a0, $v0, $zero
/* 882F28 80240D68 9482008E */  lhu       $v0, 0x8e($a0)
/* 882F2C 80240D6C 24030003 */  addiu     $v1, $zero, 3
/* 882F30 80240D70 24420001 */  addiu     $v0, $v0, 1
/* 882F34 80240D74 A482008E */  sh        $v0, 0x8e($a0)
/* 882F38 80240D78 00021400 */  sll       $v0, $v0, 0x10
/* 882F3C 80240D7C 00021403 */  sra       $v0, $v0, 0x10
/* 882F40 80240D80 14430003 */  bne       $v0, $v1, .L80240D90
/* 882F44 80240D84 00000000 */   nop      
/* 882F48 80240D88 96020086 */  lhu       $v0, 0x86($s0)
/* 882F4C 80240D8C A48200A8 */  sh        $v0, 0xa8($a0)
.L80240D90:
/* 882F50 80240D90 8482008E */  lh        $v0, 0x8e($a0)
/* 882F54 80240D94 8E030080 */  lw        $v1, 0x80($s0)
/* 882F58 80240D98 0043102A */  slt       $v0, $v0, $v1
/* 882F5C 80240D9C 14400004 */  bnez      $v0, .L80240DB0
/* 882F60 80240DA0 00000000 */   nop      
/* 882F64 80240DA4 96020086 */  lhu       $v0, 0x86($s0)
/* 882F68 80240DA8 A48200A8 */  sh        $v0, 0xa8($a0)
/* 882F6C 80240DAC AE200070 */  sw        $zero, 0x70($s1)
.L80240DB0:
/* 882F70 80240DB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 882F74 80240DB4 8FB10014 */  lw        $s1, 0x14($sp)
/* 882F78 80240DB8 8FB00010 */  lw        $s0, 0x10($sp)
/* 882F7C 80240DBC 03E00008 */  jr        $ra
/* 882F80 80240DC0 27BD0020 */   addiu    $sp, $sp, 0x20
