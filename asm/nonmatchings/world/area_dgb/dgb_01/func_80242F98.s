.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F98
/* C00818 80242F98 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C0081C 80242F9C AFB10014 */  sw        $s1, 0x14($sp)
/* C00820 80242FA0 0080882D */  daddu     $s1, $a0, $zero
/* C00824 80242FA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C00828 80242FA8 AFB00010 */  sw        $s0, 0x10($sp)
/* C0082C 80242FAC 8E300148 */  lw        $s0, 0x148($s1)
/* C00830 80242FB0 0C00EABB */  jal       get_npc_unsafe
/* C00834 80242FB4 86040008 */   lh       $a0, 8($s0)
/* C00838 80242FB8 9443008E */  lhu       $v1, 0x8e($v0)
/* C0083C 80242FBC 2463FFFF */  addiu     $v1, $v1, -1
/* C00840 80242FC0 A443008E */  sh        $v1, 0x8e($v0)
/* C00844 80242FC4 00031C00 */  sll       $v1, $v1, 0x10
/* C00848 80242FC8 14600008 */  bnez      $v1, .L80242FEC
/* C0084C 80242FCC 00000000 */   nop      
/* C00850 80242FD0 8E0200B0 */  lw        $v0, 0xb0($s0)
/* C00854 80242FD4 30420080 */  andi      $v0, $v0, 0x80
/* C00858 80242FD8 10400003 */  beqz      $v0, .L80242FE8
/* C0085C 80242FDC 2402000F */   addiu    $v0, $zero, 0xf
/* C00860 80242FE0 08090BFB */  j         .L80242FEC
/* C00864 80242FE4 AE220070 */   sw       $v0, 0x70($s1)
.L80242FE8:
/* C00868 80242FE8 AE200070 */  sw        $zero, 0x70($s1)
.L80242FEC:
/* C0086C 80242FEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C00870 80242FF0 8FB10014 */  lw        $s1, 0x14($sp)
/* C00874 80242FF4 8FB00010 */  lw        $s0, 0x10($sp)
/* C00878 80242FF8 03E00008 */  jr        $ra
/* C0087C 80242FFC 27BD0020 */   addiu    $sp, $sp, 0x20
