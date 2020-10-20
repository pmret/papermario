.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A6C_AC5BDC
/* AC5BDC 80240A6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AC5BE0 80240A70 AFB10014 */  sw        $s1, 0x14($sp)
/* AC5BE4 80240A74 0080882D */  daddu     $s1, $a0, $zero
/* AC5BE8 80240A78 AFBF0018 */  sw        $ra, 0x18($sp)
/* AC5BEC 80240A7C AFB00010 */  sw        $s0, 0x10($sp)
/* AC5BF0 80240A80 8E300148 */  lw        $s0, 0x148($s1)
/* AC5BF4 80240A84 0C00EABB */  jal       get_npc_unsafe
/* AC5BF8 80240A88 86040008 */   lh       $a0, 8($s0)
/* AC5BFC 80240A8C 9443008E */  lhu       $v1, 0x8e($v0)
/* AC5C00 80240A90 2463FFFF */  addiu     $v1, $v1, -1
/* AC5C04 80240A94 A443008E */  sh        $v1, 0x8e($v0)
/* AC5C08 80240A98 00031C00 */  sll       $v1, $v1, 0x10
/* AC5C0C 80240A9C 14600008 */  bnez      $v1, .L80240AC0
/* AC5C10 80240AA0 00000000 */   nop      
/* AC5C14 80240AA4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* AC5C18 80240AA8 30420080 */  andi      $v0, $v0, 0x80
/* AC5C1C 80240AAC 10400003 */  beqz      $v0, .L80240ABC
/* AC5C20 80240AB0 2402000F */   addiu    $v0, $zero, 0xf
/* AC5C24 80240AB4 080902B0 */  j         .L80240AC0
/* AC5C28 80240AB8 AE220070 */   sw       $v0, 0x70($s1)
.L80240ABC:
/* AC5C2C 80240ABC AE200070 */  sw        $zero, 0x70($s1)
.L80240AC0:
/* AC5C30 80240AC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* AC5C34 80240AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* AC5C38 80240AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* AC5C3C 80240ACC 03E00008 */  jr        $ra
/* AC5C40 80240AD0 27BD0020 */   addiu    $sp, $sp, 0x20
