.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_set_cursor_opacity_BB04E0
/* BB04E0 80242BA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BB04E4 80242BA4 AFB10014 */  sw        $s1, 0x14($sp)
/* BB04E8 80242BA8 0080882D */  daddu     $s1, $a0, $zero
/* BB04EC 80242BAC AFBF0018 */  sw        $ra, 0x18($sp)
/* BB04F0 80242BB0 AFB00010 */  sw        $s0, 0x10($sp)
/* BB04F4 80242BB4 8E300148 */  lw        $s0, 0x148($s1)
/* BB04F8 80242BB8 0C00EABB */  jal       get_npc_unsafe
/* BB04FC 80242BBC 86040008 */   lh       $a0, 8($s0)
/* BB0500 80242BC0 0040182D */  daddu     $v1, $v0, $zero
/* BB0504 80242BC4 9462008E */  lhu       $v0, 0x8e($v1)
/* BB0508 80242BC8 2442FFFF */  addiu     $v0, $v0, -1
/* BB050C 80242BCC A462008E */  sh        $v0, 0x8e($v1)
/* BB0510 80242BD0 00021400 */  sll       $v0, $v0, 0x10
/* BB0514 80242BD4 14400005 */  bnez      $v0, .L80242BEC
/* BB0518 80242BD8 00000000 */   nop      
/* BB051C 80242BDC 960200AA */  lhu       $v0, 0xaa($s0)
/* BB0520 80242BE0 A462008E */  sh        $v0, 0x8e($v1)
/* BB0524 80242BE4 2402000E */  addiu     $v0, $zero, 0xe
/* BB0528 80242BE8 AE220070 */  sw        $v0, 0x70($s1)
.L80242BEC:
/* BB052C 80242BEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* BB0530 80242BF0 8FB10014 */  lw        $s1, 0x14($sp)
/* BB0534 80242BF4 8FB00010 */  lw        $s0, 0x10($sp)
/* BB0538 80242BF8 03E00008 */  jr        $ra
/* BB053C 80242BFC 27BD0020 */   addiu    $sp, $sp, 0x20
