.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024158C
/* C32A6C 8024158C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C32A70 80241590 AFB10014 */  sw        $s1, 0x14($sp)
/* C32A74 80241594 0080882D */  daddu     $s1, $a0, $zero
/* C32A78 80241598 AFBF0018 */  sw        $ra, 0x18($sp)
/* C32A7C 8024159C AFB00010 */  sw        $s0, 0x10($sp)
/* C32A80 802415A0 8E300148 */  lw        $s0, 0x148($s1)
/* C32A84 802415A4 0C00EABB */  jal       get_npc_unsafe
/* C32A88 802415A8 86040008 */   lh       $a0, 8($s0)
/* C32A8C 802415AC 9443008E */  lhu       $v1, 0x8e($v0)
/* C32A90 802415B0 2463FFFF */  addiu     $v1, $v1, -1
/* C32A94 802415B4 A443008E */  sh        $v1, 0x8e($v0)
/* C32A98 802415B8 00031C00 */  sll       $v1, $v1, 0x10
/* C32A9C 802415BC 14600008 */  bnez      $v1, .L802415E0
/* C32AA0 802415C0 00000000 */   nop      
/* C32AA4 802415C4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* C32AA8 802415C8 30420080 */  andi      $v0, $v0, 0x80
/* C32AAC 802415CC 10400003 */  beqz      $v0, .L802415DC
/* C32AB0 802415D0 2402000F */   addiu    $v0, $zero, 0xf
/* C32AB4 802415D4 08090578 */  j         .L802415E0
/* C32AB8 802415D8 AE220070 */   sw       $v0, 0x70($s1)
.L802415DC:
/* C32ABC 802415DC AE200070 */  sw        $zero, 0x70($s1)
.L802415E0:
/* C32AC0 802415E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C32AC4 802415E4 8FB10014 */  lw        $s1, 0x14($sp)
/* C32AC8 802415E8 8FB00010 */  lw        $s0, 0x10($sp)
/* C32ACC 802415EC 03E00008 */  jr        $ra
/* C32AD0 802415F0 27BD0020 */   addiu    $sp, $sp, 0x20
