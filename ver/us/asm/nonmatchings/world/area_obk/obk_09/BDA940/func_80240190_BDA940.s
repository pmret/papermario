.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240190_BDA940
/* BDA940 80240190 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BDA944 80240194 AFB20020 */  sw        $s2, 0x20($sp)
/* BDA948 80240198 0080902D */  daddu     $s2, $a0, $zero
/* BDA94C 8024019C AFBF0024 */  sw        $ra, 0x24($sp)
/* BDA950 802401A0 AFB1001C */  sw        $s1, 0x1c($sp)
/* BDA954 802401A4 AFB00018 */  sw        $s0, 0x18($sp)
/* BDA958 802401A8 0C00EAD2 */  jal       get_npc_safe
/* BDA95C 802401AC 8E44014C */   lw       $a0, 0x14c($s2)
/* BDA960 802401B0 24040020 */  addiu     $a0, $zero, 0x20
/* BDA964 802401B4 0C00AB39 */  jal       heap_malloc
/* BDA968 802401B8 0040882D */   daddu    $s1, $v0, $zero
/* BDA96C 802401BC 0040802D */  daddu     $s0, $v0, $zero
/* BDA970 802401C0 AE500060 */  sw        $s0, 0x60($s2)
/* BDA974 802401C4 C6200038 */  lwc1      $f0, 0x38($s1)
/* BDA978 802401C8 3C013F80 */  lui       $at, 0x3f80
/* BDA97C 802401CC 44811000 */  mtc1      $at, $f2
/* BDA980 802401D0 E6000000 */  swc1      $f0, ($s0)
/* BDA984 802401D4 C620003C */  lwc1      $f0, 0x3c($s1)
/* BDA988 802401D8 E6000004 */  swc1      $f0, 4($s0)
/* BDA98C 802401DC C6200040 */  lwc1      $f0, 0x40($s1)
/* BDA990 802401E0 AE000010 */  sw        $zero, 0x10($s0)
/* BDA994 802401E4 E6000008 */  swc1      $f0, 8($s0)
/* BDA998 802401E8 E7A20010 */  swc1      $f2, 0x10($sp)
/* BDA99C 802401EC AFA00014 */  sw        $zero, 0x14($sp)
/* BDA9A0 802401F0 8E050000 */  lw        $a1, ($s0)
/* BDA9A4 802401F4 8E060004 */  lw        $a2, 4($s0)
/* BDA9A8 802401F8 8E070008 */  lw        $a3, 8($s0)
/* BDA9AC 802401FC 0C01C9AC */  jal       playFX_7B
/* BDA9B0 80240200 24040001 */   addiu    $a0, $zero, 1
/* BDA9B4 80240204 AE02001C */  sw        $v0, 0x1c($s0)
/* BDA9B8 80240208 8C43000C */  lw        $v1, 0xc($v0)
/* BDA9BC 8024020C 24020002 */  addiu     $v0, $zero, 2
/* BDA9C0 80240210 A0620034 */  sb        $v0, 0x34($v1)
/* BDA9C4 80240214 8E050000 */  lw        $a1, ($s0)
/* BDA9C8 80240218 8E060004 */  lw        $a2, 4($s0)
/* BDA9CC 8024021C 8E070008 */  lw        $a3, 8($s0)
/* BDA9D0 80240220 0C044898 */  jal       create_shadow_type
/* BDA9D4 80240224 0000202D */   daddu    $a0, $zero, $zero
/* BDA9D8 80240228 AE020018 */  sw        $v0, 0x18($s0)
/* BDA9DC 8024022C 8FBF0024 */  lw        $ra, 0x24($sp)
/* BDA9E0 80240230 8FB20020 */  lw        $s2, 0x20($sp)
/* BDA9E4 80240234 8FB1001C */  lw        $s1, 0x1c($sp)
/* BDA9E8 80240238 8FB00018 */  lw        $s0, 0x18($sp)
/* BDA9EC 8024023C 24020002 */  addiu     $v0, $zero, 2
/* BDA9F0 80240240 03E00008 */  jr        $ra
/* BDA9F4 80240244 27BD0028 */   addiu    $sp, $sp, 0x28
