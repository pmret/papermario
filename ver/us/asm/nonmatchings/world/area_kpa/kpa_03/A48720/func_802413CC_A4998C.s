.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413CC_A4998C
/* A4998C 802413CC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A49990 802413D0 AFB30034 */  sw        $s3, 0x34($sp)
/* A49994 802413D4 0080982D */  daddu     $s3, $a0, $zero
/* A49998 802413D8 AFBF0038 */  sw        $ra, 0x38($sp)
/* A4999C 802413DC AFB20030 */  sw        $s2, 0x30($sp)
/* A499A0 802413E0 AFB1002C */  sw        $s1, 0x2c($sp)
/* A499A4 802413E4 AFB00028 */  sw        $s0, 0x28($sp)
/* A499A8 802413E8 8E700148 */  lw        $s0, 0x148($s3)
/* A499AC 802413EC 0C00EABB */  jal       get_npc_unsafe
/* A499B0 802413F0 86040008 */   lh       $a0, 8($s0)
/* A499B4 802413F4 0040902D */  daddu     $s2, $v0, $zero
/* A499B8 802413F8 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* A499BC 802413FC 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* A499C0 80241400 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A499C4 80241404 8E220000 */  lw        $v0, ($s1)
/* A499C8 80241408 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A499CC 8024140C 8C460028 */  lw        $a2, 0x28($v0)
/* A499D0 80241410 0C00A7B5 */  jal       dist2D
/* A499D4 80241414 8C470030 */   lw       $a3, 0x30($v0)
/* A499D8 80241418 24020001 */  addiu     $v0, $zero, 1
/* A499DC 8024141C AE02006C */  sw        $v0, 0x6c($s0)
/* A499E0 80241420 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A499E4 80241424 8E0200CC */  lw        $v0, 0xcc($s0)
/* A499E8 80241428 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A499EC 8024142C 8E230000 */  lw        $v1, ($s1)
/* A499F0 80241430 8C420020 */  lw        $v0, 0x20($v0)
/* A499F4 80241434 AE420028 */  sw        $v0, 0x28($s2)
/* A499F8 80241438 8C660028 */  lw        $a2, 0x28($v1)
/* A499FC 8024143C 8C670030 */  lw        $a3, 0x30($v1)
/* A49A00 80241440 0C00A720 */  jal       atan2
/* A49A04 80241444 E7A00024 */   swc1     $f0, 0x24($sp)
/* A49A08 80241448 8E420000 */  lw        $v0, ($s2)
/* A49A0C 8024144C 3C013DCC */  lui       $at, 0x3dcc
/* A49A10 80241450 3421CCCD */  ori       $at, $at, 0xcccd
/* A49A14 80241454 44811000 */  mtc1      $at, $f2
/* A49A18 80241458 2403FFFD */  addiu     $v1, $zero, -3
/* A49A1C 8024145C E640000C */  swc1      $f0, 0xc($s2)
/* A49A20 80241460 00431024 */  and       $v0, $v0, $v1
/* A49A24 80241464 AE420000 */  sw        $v0, ($s2)
/* A49A28 80241468 30420008 */  andi      $v0, $v0, 8
/* A49A2C 8024146C E6420054 */  swc1      $f2, 0x54($s2)
/* A49A30 80241470 E6420058 */  swc1      $f2, 0x58($s2)
/* A49A34 80241474 1440001B */  bnez      $v0, .L802414E4
/* A49A38 80241478 E642005C */   swc1     $f2, 0x5c($s2)
/* A49A3C 8024147C 27A6001C */  addiu     $a2, $sp, 0x1c
/* A49A40 80241480 27A70020 */  addiu     $a3, $sp, 0x20
/* A49A44 80241484 27A20024 */  addiu     $v0, $sp, 0x24
/* A49A48 80241488 C6420038 */  lwc1      $f2, 0x38($s2)
/* A49A4C 8024148C C640003C */  lwc1      $f0, 0x3c($s2)
/* A49A50 80241490 3C014348 */  lui       $at, 0x4348
/* A49A54 80241494 44813000 */  mtc1      $at, $f6
/* A49A58 80241498 46000021 */  cvt.d.s   $f0, $f0
/* A49A5C 8024149C E7A20018 */  swc1      $f2, 0x18($sp)
/* A49A60 802414A0 3C014059 */  lui       $at, 0x4059
/* A49A64 802414A4 44811800 */  mtc1      $at, $f3
/* A49A68 802414A8 44801000 */  mtc1      $zero, $f2
/* A49A6C 802414AC C6440040 */  lwc1      $f4, 0x40($s2)
/* A49A70 802414B0 46220000 */  add.d     $f0, $f0, $f2
/* A49A74 802414B4 E7A60024 */  swc1      $f6, 0x24($sp)
/* A49A78 802414B8 E7A40020 */  swc1      $f4, 0x20($sp)
/* A49A7C 802414BC 46200020 */  cvt.s.d   $f0, $f0
/* A49A80 802414C0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A49A84 802414C4 AFA20010 */  sw        $v0, 0x10($sp)
/* A49A88 802414C8 8E440080 */  lw        $a0, 0x80($s2)
/* A49A8C 802414CC 0C0372DF */  jal       npc_raycast_down_sides
/* A49A90 802414D0 27A50018 */   addiu    $a1, $sp, 0x18
/* A49A94 802414D4 10400004 */  beqz      $v0, .L802414E8
/* A49A98 802414D8 2402000B */   addiu    $v0, $zero, 0xb
/* A49A9C 802414DC C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A49AA0 802414E0 E640003C */  swc1      $f0, 0x3c($s2)
.L802414E4:
/* A49AA4 802414E4 2402000B */  addiu     $v0, $zero, 0xb
.L802414E8:
/* A49AA8 802414E8 A640008E */  sh        $zero, 0x8e($s2)
/* A49AAC 802414EC AE620070 */  sw        $v0, 0x70($s3)
/* A49AB0 802414F0 8FBF0038 */  lw        $ra, 0x38($sp)
/* A49AB4 802414F4 8FB30034 */  lw        $s3, 0x34($sp)
/* A49AB8 802414F8 8FB20030 */  lw        $s2, 0x30($sp)
/* A49ABC 802414FC 8FB1002C */  lw        $s1, 0x2c($sp)
/* A49AC0 80241500 8FB00028 */  lw        $s0, 0x28($sp)
/* A49AC4 80241504 03E00008 */  jr        $ra
/* A49AC8 80241508 27BD0040 */   addiu    $sp, $sp, 0x40
