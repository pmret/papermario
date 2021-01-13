.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B50_BE5300
/* BE5300 80241B50 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BE5304 80241B54 AFB3001C */  sw        $s3, 0x1c($sp)
/* BE5308 80241B58 0080982D */  daddu     $s3, $a0, $zero
/* BE530C 80241B5C AFBF0020 */  sw        $ra, 0x20($sp)
/* BE5310 80241B60 AFB20018 */  sw        $s2, 0x18($sp)
/* BE5314 80241B64 AFB10014 */  sw        $s1, 0x14($sp)
/* BE5318 80241B68 AFB00010 */  sw        $s0, 0x10($sp)
/* BE531C 80241B6C 8E720148 */  lw        $s2, 0x148($s3)
/* BE5320 80241B70 86440008 */  lh        $a0, 8($s2)
/* BE5324 80241B74 0C00EABB */  jal       get_npc_unsafe
/* BE5328 80241B78 00A0802D */   daddu    $s0, $a1, $zero
/* BE532C 80241B7C 0040882D */  daddu     $s1, $v0, $zero
/* BE5330 80241B80 C6420080 */  lwc1      $f2, 0x80($s2)
/* BE5334 80241B84 468010A0 */  cvt.s.w   $f2, $f2
/* BE5338 80241B88 460010A1 */  cvt.d.s   $f2, $f2
/* BE533C 80241B8C C6400084 */  lwc1      $f0, 0x84($s2)
/* BE5340 80241B90 46800020 */  cvt.s.w   $f0, $f0
/* BE5344 80241B94 46000021 */  cvt.d.s   $f0, $f0
/* BE5348 80241B98 3C014059 */  lui       $at, 0x4059
/* BE534C 80241B9C 44812800 */  mtc1      $at, $f5
/* BE5350 80241BA0 44802000 */  mtc1      $zero, $f4
/* BE5354 80241BA4 8E4200CC */  lw        $v0, 0xcc($s2)
/* BE5358 80241BA8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BE535C 80241BAC C62E0040 */  lwc1      $f14, 0x40($s1)
/* BE5360 80241BB0 46241083 */  div.d     $f2, $f2, $f4
/* BE5364 80241BB4 462010A0 */  cvt.s.d   $f2, $f2
/* BE5368 80241BB8 46240003 */  div.d     $f0, $f0, $f4
/* BE536C 80241BBC 8C420020 */  lw        $v0, 0x20($v0)
/* BE5370 80241BC0 46200020 */  cvt.s.d   $f0, $f0
/* BE5374 80241BC4 E622001C */  swc1      $f2, 0x1c($s1)
/* BE5378 80241BC8 E6200014 */  swc1      $f0, 0x14($s1)
/* BE537C 80241BCC AE220028 */  sw        $v0, 0x28($s1)
/* BE5380 80241BD0 C6000018 */  lwc1      $f0, 0x18($s0)
/* BE5384 80241BD4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE5388 80241BD8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE538C 80241BDC E6200018 */  swc1      $f0, 0x18($s1)
/* BE5390 80241BE0 8C460028 */  lw        $a2, 0x28($v0)
/* BE5394 80241BE4 0C00A720 */  jal       atan2
/* BE5398 80241BE8 8C470030 */   lw       $a3, 0x30($v0)
/* BE539C 80241BEC E620000C */  swc1      $f0, 0xc($s1)
/* BE53A0 80241BF0 8E420018 */  lw        $v0, 0x18($s2)
/* BE53A4 80241BF4 AE400074 */  sw        $zero, 0x74($s2)
/* BE53A8 80241BF8 9442002A */  lhu       $v0, 0x2a($v0)
/* BE53AC 80241BFC 30420002 */  andi      $v0, $v0, 2
/* BE53B0 80241C00 10400005 */  beqz      $v0, .L80241C18
/* BE53B4 80241C04 24020003 */   addiu    $v0, $zero, 3
/* BE53B8 80241C08 A622008E */  sh        $v0, 0x8e($s1)
/* BE53BC 80241C0C 2402000D */  addiu     $v0, $zero, 0xd
/* BE53C0 80241C10 0809071A */  j         .L80241C68
/* BE53C4 80241C14 AE620070 */   sw       $v0, 0x70($s3)
.L80241C18:
/* BE53C8 80241C18 24030001 */  addiu     $v1, $zero, 1
/* BE53CC 80241C1C 2402000E */  addiu     $v0, $zero, 0xe
/* BE53D0 80241C20 A623008E */  sh        $v1, 0x8e($s1)
/* BE53D4 80241C24 AE620070 */  sw        $v0, 0x70($s3)
/* BE53D8 80241C28 C6200038 */  lwc1      $f0, 0x38($s1)
/* BE53DC 80241C2C 4600018D */  trunc.w.s $f6, $f0
/* BE53E0 80241C30 44023000 */  mfc1      $v0, $f6
/* BE53E4 80241C34 00000000 */  nop
/* BE53E8 80241C38 A6420010 */  sh        $v0, 0x10($s2)
/* BE53EC 80241C3C C620003C */  lwc1      $f0, 0x3c($s1)
/* BE53F0 80241C40 4600018D */  trunc.w.s $f6, $f0
/* BE53F4 80241C44 44023000 */  mfc1      $v0, $f6
/* BE53F8 80241C48 00000000 */  nop
/* BE53FC 80241C4C A6420012 */  sh        $v0, 0x12($s2)
/* BE5400 80241C50 C6200040 */  lwc1      $f0, 0x40($s1)
/* BE5404 80241C54 A2430007 */  sb        $v1, 7($s2)
/* BE5408 80241C58 4600018D */  trunc.w.s $f6, $f0
/* BE540C 80241C5C 44023000 */  mfc1      $v0, $f6
/* BE5410 80241C60 00000000 */  nop
/* BE5414 80241C64 A6420014 */  sh        $v0, 0x14($s2)
.L80241C68:
/* BE5418 80241C68 8FBF0020 */  lw        $ra, 0x20($sp)
/* BE541C 80241C6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* BE5420 80241C70 8FB20018 */  lw        $s2, 0x18($sp)
/* BE5424 80241C74 8FB10014 */  lw        $s1, 0x14($sp)
/* BE5428 80241C78 8FB00010 */  lw        $s0, 0x10($sp)
/* BE542C 80241C7C 03E00008 */  jr        $ra
/* BE5430 80241C80 27BD0028 */   addiu    $sp, $sp, 0x28
