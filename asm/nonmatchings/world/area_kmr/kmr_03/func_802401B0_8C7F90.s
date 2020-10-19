.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B0_8C8140
/* 8C8140 802401B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8C8144 802401B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8C8148 802401B8 0080882D */  daddu     $s1, $a0, $zero
/* 8C814C 802401BC 0000202D */  daddu     $a0, $zero, $zero
/* 8C8150 802401C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8C8154 802401C4 0C00EABB */  jal       get_npc_unsafe
/* 8C8158 802401C8 AFB00010 */   sw       $s0, 0x10($sp)
/* 8C815C 802401CC 0040802D */  daddu     $s0, $v0, $zero
/* 8C8160 802401D0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8C8164 802401D4 0C038022 */  jal       func_800E0088
/* 8C8168 802401D8 C60E0040 */   lwc1     $f14, 0x40($s0)
/* 8C816C 802401DC C6020018 */  lwc1      $f2, 0x18($s0)
/* 8C8170 802401E0 3C013F4C */  lui       $at, 0x3f4c
/* 8C8174 802401E4 3421CCCD */  ori       $at, $at, 0xcccd
/* 8C8178 802401E8 44812000 */  mtc1      $at, $f4
/* 8C817C 802401EC 46020003 */  div.s     $f0, $f0, $f2
/* 8C8180 802401F0 46040002 */  mul.s     $f0, $f0, $f4
/* 8C8184 802401F4 00000000 */  nop       
/* 8C8188 802401F8 4600018D */  trunc.w.s $f6, $f0
/* 8C818C 802401FC E6260088 */  swc1      $f6, 0x88($s1)
/* 8C8190 80240200 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8C8194 80240204 8FB10014 */  lw        $s1, 0x14($sp)
/* 8C8198 80240208 8FB00010 */  lw        $s0, 0x10($sp)
/* 8C819C 8024020C 24020002 */  addiu     $v0, $zero, 2
/* 8C81A0 80240210 03E00008 */  jr        $ra
/* 8C81A4 80240214 27BD0020 */   addiu    $sp, $sp, 0x20
