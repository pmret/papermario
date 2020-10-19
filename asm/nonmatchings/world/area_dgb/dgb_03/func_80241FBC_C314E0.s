.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FBC_C3349C
/* C3349C 80241FBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C334A0 80241FC0 AFB10014 */  sw        $s1, 0x14($sp)
/* C334A4 80241FC4 0080882D */  daddu     $s1, $a0, $zero
/* C334A8 80241FC8 AFBF0018 */  sw        $ra, 0x18($sp)
/* C334AC 80241FCC AFB00010 */  sw        $s0, 0x10($sp)
/* C334B0 80241FD0 8E300148 */  lw        $s0, 0x148($s1)
/* C334B4 80241FD4 0C00EABB */  jal       get_npc_unsafe
/* C334B8 80241FD8 86040008 */   lh       $a0, 8($s0)
/* C334BC 80241FDC 0040182D */  daddu     $v1, $v0, $zero
/* C334C0 80241FE0 9462008E */  lhu       $v0, 0x8e($v1)
/* C334C4 80241FE4 2442FFFF */  addiu     $v0, $v0, -1
/* C334C8 80241FE8 A462008E */  sh        $v0, 0x8e($v1)
/* C334CC 80241FEC 00021400 */  sll       $v0, $v0, 0x10
/* C334D0 80241FF0 1C400006 */  bgtz      $v0, .L8024200C
/* C334D4 80241FF4 24020001 */   addiu    $v0, $zero, 1
/* C334D8 80241FF8 A462008E */  sh        $v0, 0x8e($v1)
/* C334DC 80241FFC 24020028 */  addiu     $v0, $zero, 0x28
/* C334E0 80242000 AE020088 */  sw        $v0, 0x88($s0)
/* C334E4 80242004 24020003 */  addiu     $v0, $zero, 3
/* C334E8 80242008 AE220070 */  sw        $v0, 0x70($s1)
.L8024200C:
/* C334EC 8024200C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C334F0 80242010 8FB10014 */  lw        $s1, 0x14($sp)
/* C334F4 80242014 8FB00010 */  lw        $s0, 0x10($sp)
/* C334F8 80242018 03E00008 */  jr        $ra
/* C334FC 8024201C 27BD0020 */   addiu    $sp, $sp, 0x20
