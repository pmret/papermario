.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E1C_BAAF5C
/* BAAF5C 80240E1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BAAF60 80240E20 AFB00010 */  sw        $s0, 0x10($sp)
/* BAAF64 80240E24 0080802D */  daddu     $s0, $a0, $zero
/* BAAF68 80240E28 AFBF0014 */  sw        $ra, 0x14($sp)
/* BAAF6C 80240E2C 8E020148 */  lw        $v0, 0x148($s0)
/* BAAF70 80240E30 0C00EABB */  jal       get_npc_unsafe
/* BAAF74 80240E34 84440008 */   lh       $a0, 8($v0)
/* BAAF78 80240E38 9443008E */  lhu       $v1, 0x8e($v0)
/* BAAF7C 80240E3C 2463FFFF */  addiu     $v1, $v1, -1
/* BAAF80 80240E40 A443008E */  sh        $v1, 0x8e($v0)
/* BAAF84 80240E44 00031C00 */  sll       $v1, $v1, 0x10
/* BAAF88 80240E48 58600001 */  blezl     $v1, .L80240E50
/* BAAF8C 80240E4C AE000070 */   sw       $zero, 0x70($s0)
.L80240E50:
/* BAAF90 80240E50 8FBF0014 */  lw        $ra, 0x14($sp)
/* BAAF94 80240E54 8FB00010 */  lw        $s0, 0x10($sp)
/* BAAF98 80240E58 03E00008 */  jr        $ra
/* BAAF9C 80240E5C 27BD0018 */   addiu    $sp, $sp, 0x18
