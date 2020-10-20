.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D08_C81EA8
/* C81EA8 80241D08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C81EAC 80241D0C AFB10014 */  sw        $s1, 0x14($sp)
/* C81EB0 80241D10 0080882D */  daddu     $s1, $a0, $zero
/* C81EB4 80241D14 AFBF0018 */  sw        $ra, 0x18($sp)
/* C81EB8 80241D18 AFB00010 */  sw        $s0, 0x10($sp)
/* C81EBC 80241D1C 8E300148 */  lw        $s0, 0x148($s1)
/* C81EC0 80241D20 0C00EABB */  jal       get_npc_unsafe
/* C81EC4 80241D24 86040008 */   lh       $a0, 8($s0)
/* C81EC8 80241D28 0040182D */  daddu     $v1, $v0, $zero
/* C81ECC 80241D2C 9462008E */  lhu       $v0, 0x8e($v1)
/* C81ED0 80241D30 2442FFFF */  addiu     $v0, $v0, -1
/* C81ED4 80241D34 A462008E */  sh        $v0, 0x8e($v1)
/* C81ED8 80241D38 00021400 */  sll       $v0, $v0, 0x10
/* C81EDC 80241D3C 1C400004 */  bgtz      $v0, .L80241D50
/* C81EE0 80241D40 00000000 */   nop      
/* C81EE4 80241D44 AE000074 */  sw        $zero, 0x74($s0)
/* C81EE8 80241D48 A460008E */  sh        $zero, 0x8e($v1)
/* C81EEC 80241D4C AE200070 */  sw        $zero, 0x70($s1)
.L80241D50:
/* C81EF0 80241D50 8FBF0018 */  lw        $ra, 0x18($sp)
/* C81EF4 80241D54 8FB10014 */  lw        $s1, 0x14($sp)
/* C81EF8 80241D58 8FB00010 */  lw        $s0, 0x10($sp)
/* C81EFC 80241D5C 03E00008 */  jr        $ra
/* C81F00 80241D60 27BD0020 */   addiu    $sp, $sp, 0x20
