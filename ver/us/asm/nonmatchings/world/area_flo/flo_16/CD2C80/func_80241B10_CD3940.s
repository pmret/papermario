.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B10_CD3940
/* CD3940 80241B10 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CD3944 80241B14 AFB3001C */  sw        $s3, 0x1c($sp)
/* CD3948 80241B18 0080982D */  daddu     $s3, $a0, $zero
/* CD394C 80241B1C AFBF0020 */  sw        $ra, 0x20($sp)
/* CD3950 80241B20 AFB20018 */  sw        $s2, 0x18($sp)
/* CD3954 80241B24 AFB10014 */  sw        $s1, 0x14($sp)
/* CD3958 80241B28 AFB00010 */  sw        $s0, 0x10($sp)
/* CD395C 80241B2C 8E720148 */  lw        $s2, 0x148($s3)
/* CD3960 80241B30 86440008 */  lh        $a0, 8($s2)
/* CD3964 80241B34 0C00EABB */  jal       get_npc_unsafe
/* CD3968 80241B38 00A0802D */   daddu    $s0, $a1, $zero
/* CD396C 80241B3C 0040882D */  daddu     $s1, $v0, $zero
/* CD3970 80241B40 C6420080 */  lwc1      $f2, 0x80($s2)
/* CD3974 80241B44 468010A0 */  cvt.s.w   $f2, $f2
/* CD3978 80241B48 460010A1 */  cvt.d.s   $f2, $f2
/* CD397C 80241B4C C6400084 */  lwc1      $f0, 0x84($s2)
/* CD3980 80241B50 46800020 */  cvt.s.w   $f0, $f0
/* CD3984 80241B54 46000021 */  cvt.d.s   $f0, $f0
/* CD3988 80241B58 3C014059 */  lui       $at, 0x4059
/* CD398C 80241B5C 44812800 */  mtc1      $at, $f5
/* CD3990 80241B60 44802000 */  mtc1      $zero, $f4
/* CD3994 80241B64 8E4200CC */  lw        $v0, 0xcc($s2)
/* CD3998 80241B68 C62C0038 */  lwc1      $f12, 0x38($s1)
/* CD399C 80241B6C C62E0040 */  lwc1      $f14, 0x40($s1)
/* CD39A0 80241B70 46241083 */  div.d     $f2, $f2, $f4
/* CD39A4 80241B74 462010A0 */  cvt.s.d   $f2, $f2
/* CD39A8 80241B78 46240003 */  div.d     $f0, $f0, $f4
/* CD39AC 80241B7C 8C420020 */  lw        $v0, 0x20($v0)
/* CD39B0 80241B80 46200020 */  cvt.s.d   $f0, $f0
/* CD39B4 80241B84 E622001C */  swc1      $f2, 0x1c($s1)
/* CD39B8 80241B88 E6200014 */  swc1      $f0, 0x14($s1)
/* CD39BC 80241B8C AE220028 */  sw        $v0, 0x28($s1)
/* CD39C0 80241B90 C6000018 */  lwc1      $f0, 0x18($s0)
/* CD39C4 80241B94 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD39C8 80241B98 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD39CC 80241B9C E6200018 */  swc1      $f0, 0x18($s1)
/* CD39D0 80241BA0 8C460028 */  lw        $a2, 0x28($v0)
/* CD39D4 80241BA4 0C00A720 */  jal       atan2
/* CD39D8 80241BA8 8C470030 */   lw       $a3, 0x30($v0)
/* CD39DC 80241BAC E620000C */  swc1      $f0, 0xc($s1)
/* CD39E0 80241BB0 8E420018 */  lw        $v0, 0x18($s2)
/* CD39E4 80241BB4 AE400074 */  sw        $zero, 0x74($s2)
/* CD39E8 80241BB8 9442002A */  lhu       $v0, 0x2a($v0)
/* CD39EC 80241BBC 30420002 */  andi      $v0, $v0, 2
/* CD39F0 80241BC0 10400005 */  beqz      $v0, .L80241BD8
/* CD39F4 80241BC4 24020003 */   addiu    $v0, $zero, 3
/* CD39F8 80241BC8 A622008E */  sh        $v0, 0x8e($s1)
/* CD39FC 80241BCC 2402000D */  addiu     $v0, $zero, 0xd
/* CD3A00 80241BD0 0809070A */  j         .L80241C28
/* CD3A04 80241BD4 AE620070 */   sw       $v0, 0x70($s3)
.L80241BD8:
/* CD3A08 80241BD8 24030001 */  addiu     $v1, $zero, 1
/* CD3A0C 80241BDC 2402000E */  addiu     $v0, $zero, 0xe
/* CD3A10 80241BE0 A623008E */  sh        $v1, 0x8e($s1)
/* CD3A14 80241BE4 AE620070 */  sw        $v0, 0x70($s3)
/* CD3A18 80241BE8 C6200038 */  lwc1      $f0, 0x38($s1)
/* CD3A1C 80241BEC 4600018D */  trunc.w.s $f6, $f0
/* CD3A20 80241BF0 44023000 */  mfc1      $v0, $f6
/* CD3A24 80241BF4 00000000 */  nop
/* CD3A28 80241BF8 A6420010 */  sh        $v0, 0x10($s2)
/* CD3A2C 80241BFC C620003C */  lwc1      $f0, 0x3c($s1)
/* CD3A30 80241C00 4600018D */  trunc.w.s $f6, $f0
/* CD3A34 80241C04 44023000 */  mfc1      $v0, $f6
/* CD3A38 80241C08 00000000 */  nop
/* CD3A3C 80241C0C A6420012 */  sh        $v0, 0x12($s2)
/* CD3A40 80241C10 C6200040 */  lwc1      $f0, 0x40($s1)
/* CD3A44 80241C14 A2430007 */  sb        $v1, 7($s2)
/* CD3A48 80241C18 4600018D */  trunc.w.s $f6, $f0
/* CD3A4C 80241C1C 44023000 */  mfc1      $v0, $f6
/* CD3A50 80241C20 00000000 */  nop
/* CD3A54 80241C24 A6420014 */  sh        $v0, 0x14($s2)
.L80241C28:
/* CD3A58 80241C28 8FBF0020 */  lw        $ra, 0x20($sp)
/* CD3A5C 80241C2C 8FB3001C */  lw        $s3, 0x1c($sp)
/* CD3A60 80241C30 8FB20018 */  lw        $s2, 0x18($sp)
/* CD3A64 80241C34 8FB10014 */  lw        $s1, 0x14($sp)
/* CD3A68 80241C38 8FB00010 */  lw        $s0, 0x10($sp)
/* CD3A6C 80241C3C 03E00008 */  jr        $ra
/* CD3A70 80241C40 27BD0028 */   addiu    $sp, $sp, 0x28
