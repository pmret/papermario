.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B4_C3DDA4
/* C3DDA4 802401B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3DDA8 802401B8 AFB10014 */  sw        $s1, 0x14($sp)
/* C3DDAC 802401BC 0080882D */  daddu     $s1, $a0, $zero
/* C3DDB0 802401C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C3DDB4 802401C4 AFB00010 */  sw        $s0, 0x10($sp)
/* C3DDB8 802401C8 8E300148 */  lw        $s0, 0x148($s1)
/* C3DDBC 802401CC 0C00EABB */  jal       get_npc_unsafe
/* C3DDC0 802401D0 86040008 */   lh       $a0, 8($s0)
/* C3DDC4 802401D4 9443008E */  lhu       $v1, 0x8e($v0)
/* C3DDC8 802401D8 2463FFFF */  addiu     $v1, $v1, -1
/* C3DDCC 802401DC A443008E */  sh        $v1, 0x8e($v0)
/* C3DDD0 802401E0 00031C00 */  sll       $v1, $v1, 0x10
/* C3DDD4 802401E4 1C600003 */  bgtz      $v1, .L802401F4
/* C3DDD8 802401E8 2402000C */   addiu    $v0, $zero, 0xc
/* C3DDDC 802401EC AE00006C */  sw        $zero, 0x6c($s0)
/* C3DDE0 802401F0 AE220070 */  sw        $v0, 0x70($s1)
.L802401F4:
/* C3DDE4 802401F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3DDE8 802401F8 8FB10014 */  lw        $s1, 0x14($sp)
/* C3DDEC 802401FC 8FB00010 */  lw        $s0, 0x10($sp)
/* C3DDF0 80240200 03E00008 */  jr        $ra
/* C3DDF4 80240204 27BD0020 */   addiu    $sp, $sp, 0x20
