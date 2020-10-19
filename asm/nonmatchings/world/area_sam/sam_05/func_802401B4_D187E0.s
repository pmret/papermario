.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B4_D18994
/* D18994 802401B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D18998 802401B8 AFB10014 */  sw        $s1, 0x14($sp)
/* D1899C 802401BC 0080882D */  daddu     $s1, $a0, $zero
/* D189A0 802401C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* D189A4 802401C4 AFB00010 */  sw        $s0, 0x10($sp)
/* D189A8 802401C8 8E300148 */  lw        $s0, 0x148($s1)
/* D189AC 802401CC 0C00EABB */  jal       get_npc_unsafe
/* D189B0 802401D0 86040008 */   lh       $a0, 8($s0)
/* D189B4 802401D4 9443008E */  lhu       $v1, 0x8e($v0)
/* D189B8 802401D8 2463FFFF */  addiu     $v1, $v1, -1
/* D189BC 802401DC A443008E */  sh        $v1, 0x8e($v0)
/* D189C0 802401E0 00031C00 */  sll       $v1, $v1, 0x10
/* D189C4 802401E4 1C600003 */  bgtz      $v1, .L802401F4
/* D189C8 802401E8 2402000C */   addiu    $v0, $zero, 0xc
/* D189CC 802401EC AE00006C */  sw        $zero, 0x6c($s0)
/* D189D0 802401F0 AE220070 */  sw        $v0, 0x70($s1)
.L802401F4:
/* D189D4 802401F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D189D8 802401F8 8FB10014 */  lw        $s1, 0x14($sp)
/* D189DC 802401FC 8FB00010 */  lw        $s0, 0x10($sp)
/* D189E0 80240200 03E00008 */  jr        $ra
/* D189E4 80240204 27BD0020 */   addiu    $sp, $sp, 0x20
