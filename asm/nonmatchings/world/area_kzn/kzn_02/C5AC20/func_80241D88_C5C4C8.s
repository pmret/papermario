.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D88_C5C4C8
/* C5C4C8 80241D88 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C5C4CC 80241D8C AFB10014 */  sw        $s1, 0x14($sp)
/* C5C4D0 80241D90 0080882D */  daddu     $s1, $a0, $zero
/* C5C4D4 80241D94 AFBF0018 */  sw        $ra, 0x18($sp)
/* C5C4D8 80241D98 AFB00010 */  sw        $s0, 0x10($sp)
/* C5C4DC 80241D9C 8E300148 */  lw        $s0, 0x148($s1)
/* C5C4E0 80241DA0 0C00EABB */  jal       get_npc_unsafe
/* C5C4E4 80241DA4 86040008 */   lh       $a0, 8($s0)
/* C5C4E8 80241DA8 0040182D */  daddu     $v1, $v0, $zero
/* C5C4EC 80241DAC 9462008E */  lhu       $v0, 0x8e($v1)
/* C5C4F0 80241DB0 2442FFFF */  addiu     $v0, $v0, -1
/* C5C4F4 80241DB4 A462008E */  sh        $v0, 0x8e($v1)
/* C5C4F8 80241DB8 00021400 */  sll       $v0, $v0, 0x10
/* C5C4FC 80241DBC 1C400004 */  bgtz      $v0, .L80241DD0
/* C5C500 80241DC0 00000000 */   nop
/* C5C504 80241DC4 AE000074 */  sw        $zero, 0x74($s0)
/* C5C508 80241DC8 A460008E */  sh        $zero, 0x8e($v1)
/* C5C50C 80241DCC AE200070 */  sw        $zero, 0x70($s1)
.L80241DD0:
/* C5C510 80241DD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C5C514 80241DD4 8FB10014 */  lw        $s1, 0x14($sp)
/* C5C518 80241DD8 8FB00010 */  lw        $s0, 0x10($sp)
/* C5C51C 80241DDC 03E00008 */  jr        $ra
/* C5C520 80241DE0 27BD0020 */   addiu    $sp, $sp, 0x20
