.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A6C_C569AC
/* C569AC 80240A6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C569B0 80240A70 AFB10014 */  sw        $s1, 0x14($sp)
/* C569B4 80240A74 0080882D */  daddu     $s1, $a0, $zero
/* C569B8 80240A78 AFBF0018 */  sw        $ra, 0x18($sp)
/* C569BC 80240A7C AFB00010 */  sw        $s0, 0x10($sp)
/* C569C0 80240A80 8E300148 */  lw        $s0, 0x148($s1)
/* C569C4 80240A84 0C00EABB */  jal       get_npc_unsafe
/* C569C8 80240A88 86040008 */   lh       $a0, 8($s0)
/* C569CC 80240A8C 9443008E */  lhu       $v1, 0x8e($v0)
/* C569D0 80240A90 2463FFFF */  addiu     $v1, $v1, -1
/* C569D4 80240A94 A443008E */  sh        $v1, 0x8e($v0)
/* C569D8 80240A98 00031C00 */  sll       $v1, $v1, 0x10
/* C569DC 80240A9C 14600008 */  bnez      $v1, .L80240AC0
/* C569E0 80240AA0 00000000 */   nop      
/* C569E4 80240AA4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* C569E8 80240AA8 30420080 */  andi      $v0, $v0, 0x80
/* C569EC 80240AAC 10400003 */  beqz      $v0, .L80240ABC
/* C569F0 80240AB0 2402000F */   addiu    $v0, $zero, 0xf
/* C569F4 80240AB4 080902B0 */  j         .L80240AC0
/* C569F8 80240AB8 AE220070 */   sw       $v0, 0x70($s1)
.L80240ABC:
/* C569FC 80240ABC AE200070 */  sw        $zero, 0x70($s1)
.L80240AC0:
/* C56A00 80240AC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C56A04 80240AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* C56A08 80240AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* C56A0C 80240ACC 03E00008 */  jr        $ra
/* C56A10 80240AD0 27BD0020 */   addiu    $sp, $sp, 0x20
