.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242CD8_C799B8
/* C799B8 80242CD8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C799BC 80242CDC AFB10014 */  sw        $s1, 0x14($sp)
/* C799C0 80242CE0 0080882D */  daddu     $s1, $a0, $zero
/* C799C4 80242CE4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C799C8 80242CE8 AFB00010 */  sw        $s0, 0x10($sp)
/* C799CC 80242CEC 8E300148 */  lw        $s0, 0x148($s1)
/* C799D0 80242CF0 0C00EABB */  jal       get_npc_unsafe
/* C799D4 80242CF4 86040008 */   lh       $a0, 8($s0)
/* C799D8 80242CF8 0040202D */  daddu     $a0, $v0, $zero
/* C799DC 80242CFC 9482008E */  lhu       $v0, 0x8e($a0)
/* C799E0 80242D00 24030003 */  addiu     $v1, $zero, 3
/* C799E4 80242D04 24420001 */  addiu     $v0, $v0, 1
/* C799E8 80242D08 A482008E */  sh        $v0, 0x8e($a0)
/* C799EC 80242D0C 00021400 */  sll       $v0, $v0, 0x10
/* C799F0 80242D10 00021403 */  sra       $v0, $v0, 0x10
/* C799F4 80242D14 14430003 */  bne       $v0, $v1, .L80242D24
/* C799F8 80242D18 00000000 */   nop      
/* C799FC 80242D1C 96020086 */  lhu       $v0, 0x86($s0)
/* C79A00 80242D20 A48200A8 */  sh        $v0, 0xa8($a0)
.L80242D24:
/* C79A04 80242D24 8482008E */  lh        $v0, 0x8e($a0)
/* C79A08 80242D28 8E030080 */  lw        $v1, 0x80($s0)
/* C79A0C 80242D2C 0043102A */  slt       $v0, $v0, $v1
/* C79A10 80242D30 14400004 */  bnez      $v0, .L80242D44
/* C79A14 80242D34 00000000 */   nop      
/* C79A18 80242D38 96020086 */  lhu       $v0, 0x86($s0)
/* C79A1C 80242D3C A48200A8 */  sh        $v0, 0xa8($a0)
/* C79A20 80242D40 AE200070 */  sw        $zero, 0x70($s1)
.L80242D44:
/* C79A24 80242D44 8FBF0018 */  lw        $ra, 0x18($sp)
/* C79A28 80242D48 8FB10014 */  lw        $s1, 0x14($sp)
/* C79A2C 80242D4C 8FB00010 */  lw        $s0, 0x10($sp)
/* C79A30 80242D50 03E00008 */  jr        $ra
/* C79A34 80242D54 27BD0020 */   addiu    $sp, $sp, 0x20
