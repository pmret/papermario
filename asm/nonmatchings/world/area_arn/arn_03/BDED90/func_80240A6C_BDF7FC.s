.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A6C_BDF7FC
/* BDF7FC 80240A6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDF800 80240A70 AFB10014 */  sw        $s1, 0x14($sp)
/* BDF804 80240A74 0080882D */  daddu     $s1, $a0, $zero
/* BDF808 80240A78 AFBF0018 */  sw        $ra, 0x18($sp)
/* BDF80C 80240A7C AFB00010 */  sw        $s0, 0x10($sp)
/* BDF810 80240A80 8E300148 */  lw        $s0, 0x148($s1)
/* BDF814 80240A84 0C00EABB */  jal       get_npc_unsafe
/* BDF818 80240A88 86040008 */   lh       $a0, 8($s0)
/* BDF81C 80240A8C 9443008E */  lhu       $v1, 0x8e($v0)
/* BDF820 80240A90 2463FFFF */  addiu     $v1, $v1, -1
/* BDF824 80240A94 A443008E */  sh        $v1, 0x8e($v0)
/* BDF828 80240A98 00031C00 */  sll       $v1, $v1, 0x10
/* BDF82C 80240A9C 14600008 */  bnez      $v1, .L80240AC0
/* BDF830 80240AA0 00000000 */   nop      
/* BDF834 80240AA4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* BDF838 80240AA8 30420080 */  andi      $v0, $v0, 0x80
/* BDF83C 80240AAC 10400003 */  beqz      $v0, .L80240ABC
/* BDF840 80240AB0 2402000F */   addiu    $v0, $zero, 0xf
/* BDF844 80240AB4 080902B0 */  j         .L80240AC0
/* BDF848 80240AB8 AE220070 */   sw       $v0, 0x70($s1)
.L80240ABC:
/* BDF84C 80240ABC AE200070 */  sw        $zero, 0x70($s1)
.L80240AC0:
/* BDF850 80240AC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BDF854 80240AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* BDF858 80240AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* BDF85C 80240ACC 03E00008 */  jr        $ra
/* BDF860 80240AD0 27BD0020 */   addiu    $sp, $sp, 0x20
