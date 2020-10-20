.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B4_C46D94
/* C46D94 802401B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C46D98 802401B8 AFB10014 */  sw        $s1, 0x14($sp)
/* C46D9C 802401BC 0080882D */  daddu     $s1, $a0, $zero
/* C46DA0 802401C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C46DA4 802401C4 AFB00010 */  sw        $s0, 0x10($sp)
/* C46DA8 802401C8 8E300148 */  lw        $s0, 0x148($s1)
/* C46DAC 802401CC 0C00EABB */  jal       get_npc_unsafe
/* C46DB0 802401D0 86040008 */   lh       $a0, 8($s0)
/* C46DB4 802401D4 9443008E */  lhu       $v1, 0x8e($v0)
/* C46DB8 802401D8 2463FFFF */  addiu     $v1, $v1, -1
/* C46DBC 802401DC A443008E */  sh        $v1, 0x8e($v0)
/* C46DC0 802401E0 00031C00 */  sll       $v1, $v1, 0x10
/* C46DC4 802401E4 1C600003 */  bgtz      $v1, .L802401F4
/* C46DC8 802401E8 2402000C */   addiu    $v0, $zero, 0xc
/* C46DCC 802401EC AE00006C */  sw        $zero, 0x6c($s0)
/* C46DD0 802401F0 AE220070 */  sw        $v0, 0x70($s1)
.L802401F4:
/* C46DD4 802401F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* C46DD8 802401F8 8FB10014 */  lw        $s1, 0x14($sp)
/* C46DDC 802401FC 8FB00010 */  lw        $s0, 0x10($sp)
/* C46DE0 80240200 03E00008 */  jr        $ra
/* C46DE4 80240204 27BD0020 */   addiu    $sp, $sp, 0x20
