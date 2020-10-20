.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A6C_BE864C
/* BE864C 80240A6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE8650 80240A70 AFB10014 */  sw        $s1, 0x14($sp)
/* BE8654 80240A74 0080882D */  daddu     $s1, $a0, $zero
/* BE8658 80240A78 AFBF0018 */  sw        $ra, 0x18($sp)
/* BE865C 80240A7C AFB00010 */  sw        $s0, 0x10($sp)
/* BE8660 80240A80 8E300148 */  lw        $s0, 0x148($s1)
/* BE8664 80240A84 0C00EABB */  jal       get_npc_unsafe
/* BE8668 80240A88 86040008 */   lh       $a0, 8($s0)
/* BE866C 80240A8C 9443008E */  lhu       $v1, 0x8e($v0)
/* BE8670 80240A90 2463FFFF */  addiu     $v1, $v1, -1
/* BE8674 80240A94 A443008E */  sh        $v1, 0x8e($v0)
/* BE8678 80240A98 00031C00 */  sll       $v1, $v1, 0x10
/* BE867C 80240A9C 14600008 */  bnez      $v1, .L80240AC0
/* BE8680 80240AA0 00000000 */   nop      
/* BE8684 80240AA4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* BE8688 80240AA8 30420080 */  andi      $v0, $v0, 0x80
/* BE868C 80240AAC 10400003 */  beqz      $v0, .L80240ABC
/* BE8690 80240AB0 2402000F */   addiu    $v0, $zero, 0xf
/* BE8694 80240AB4 080902B0 */  j         .L80240AC0
/* BE8698 80240AB8 AE220070 */   sw       $v0, 0x70($s1)
.L80240ABC:
/* BE869C 80240ABC AE200070 */  sw        $zero, 0x70($s1)
.L80240AC0:
/* BE86A0 80240AC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE86A4 80240AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* BE86A8 80240AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* BE86AC 80240ACC 03E00008 */  jr        $ra
/* BE86B0 80240AD0 27BD0020 */   addiu    $sp, $sp, 0x20
