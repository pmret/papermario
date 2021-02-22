.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242314_CC5B24
/* CC5B24 80242314 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CC5B28 80242318 AFB3001C */  sw        $s3, 0x1c($sp)
/* CC5B2C 8024231C 0080982D */  daddu     $s3, $a0, $zero
/* CC5B30 80242320 AFBF0020 */  sw        $ra, 0x20($sp)
/* CC5B34 80242324 AFB20018 */  sw        $s2, 0x18($sp)
/* CC5B38 80242328 AFB10014 */  sw        $s1, 0x14($sp)
/* CC5B3C 8024232C AFB00010 */  sw        $s0, 0x10($sp)
/* CC5B40 80242330 8E710148 */  lw        $s1, 0x148($s3)
/* CC5B44 80242334 86240008 */  lh        $a0, 8($s1)
/* CC5B48 80242338 0C00EABB */  jal       get_npc_unsafe
/* CC5B4C 8024233C 00A0902D */   daddu    $s2, $a1, $zero
/* CC5B50 80242340 0040802D */  daddu     $s0, $v0, $zero
/* CC5B54 80242344 8602008E */  lh        $v0, 0x8e($s0)
/* CC5B58 80242348 9603008E */  lhu       $v1, 0x8e($s0)
/* CC5B5C 8024234C 18400005 */  blez      $v0, .L80242364
/* CC5B60 80242350 2462FFFF */   addiu    $v0, $v1, -1
/* CC5B64 80242354 A602008E */  sh        $v0, 0x8e($s0)
/* CC5B68 80242358 00021400 */  sll       $v0, $v0, 0x10
/* CC5B6C 8024235C 1C400033 */  bgtz      $v0, .L8024242C
/* CC5B70 80242360 00000000 */   nop
.L80242364:
/* CC5B74 80242364 8602008C */  lh        $v0, 0x8c($s0)
/* CC5B78 80242368 14400030 */  bnez      $v0, .L8024242C
/* CC5B7C 8024236C 00000000 */   nop
/* CC5B80 80242370 8E2200CC */  lw        $v0, 0xcc($s1)
/* CC5B84 80242374 8C420024 */  lw        $v0, 0x24($v0)
/* CC5B88 80242378 AE020028 */  sw        $v0, 0x28($s0)
/* CC5B8C 8024237C C6400018 */  lwc1      $f0, 0x18($s2)
/* CC5B90 80242380 E6000018 */  swc1      $f0, 0x18($s0)
/* CC5B94 80242384 8E230088 */  lw        $v1, 0x88($s1)
/* CC5B98 80242388 24020005 */  addiu     $v0, $zero, 5
/* CC5B9C 8024238C 10620005 */  beq       $v1, $v0, .L802423A4
/* CC5BA0 80242390 00000000 */   nop
/* CC5BA4 80242394 10600003 */  beqz      $v1, .L802423A4
/* CC5BA8 80242398 24020001 */   addiu    $v0, $zero, 1
/* CC5BAC 8024239C 14620006 */  bne       $v1, $v0, .L802423B8
/* CC5BB0 802423A0 00000000 */   nop
.L802423A4:
/* CC5BB4 802423A4 8E220084 */  lw        $v0, 0x84($s1)
/* CC5BB8 802423A8 00021FC2 */  srl       $v1, $v0, 0x1f
/* CC5BBC 802423AC 00431021 */  addu      $v0, $v0, $v1
/* CC5BC0 802423B0 00021043 */  sra       $v0, $v0, 1
/* CC5BC4 802423B4 A60200A8 */  sh        $v0, 0xa8($s0)
.L802423B8:
/* CC5BC8 802423B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CC5BCC 802423BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CC5BD0 802423C0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CC5BD4 802423C4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CC5BD8 802423C8 8C460028 */  lw        $a2, 0x28($v0)
/* CC5BDC 802423CC 0C00A7B5 */  jal       dist2D
/* CC5BE0 802423D0 8C470030 */   lw       $a3, 0x30($v0)
/* CC5BE4 802423D4 C6020018 */  lwc1      $f2, 0x18($s0)
/* CC5BE8 802423D8 46020003 */  div.s     $f0, $f0, $f2
/* CC5BEC 802423DC 3C018024 */  lui       $at, %hi(D_80247A88_CCB298)
/* CC5BF0 802423E0 D4227A88 */  ldc1      $f2, %lo(D_80247A88_CCB298)($at)
/* CC5BF4 802423E4 46000021 */  cvt.d.s   $f0, $f0
/* CC5BF8 802423E8 46220000 */  add.d     $f0, $f0, $f2
/* CC5BFC 802423EC 4620010D */  trunc.w.d $f4, $f0
/* CC5C00 802423F0 44022000 */  mfc1      $v0, $f4
/* CC5C04 802423F4 00000000 */  nop
/* CC5C08 802423F8 A602008E */  sh        $v0, 0x8e($s0)
/* CC5C0C 802423FC 00021400 */  sll       $v0, $v0, 0x10
/* CC5C10 80242400 8E230078 */  lw        $v1, 0x78($s1)
/* CC5C14 80242404 00021403 */  sra       $v0, $v0, 0x10
/* CC5C18 80242408 0043102A */  slt       $v0, $v0, $v1
/* CC5C1C 8024240C 10400003 */  beqz      $v0, .L8024241C
/* CC5C20 80242410 00000000 */   nop
/* CC5C24 80242414 9622007A */  lhu       $v0, 0x7a($s1)
/* CC5C28 80242418 A602008E */  sh        $v0, 0x8e($s0)
.L8024241C:
/* CC5C2C 8024241C 8602008E */  lh        $v0, 0x8e($s0)
/* CC5C30 80242420 AE22007C */  sw        $v0, 0x7c($s1)
/* CC5C34 80242424 2402000E */  addiu     $v0, $zero, 0xe
/* CC5C38 80242428 AE620070 */  sw        $v0, 0x70($s3)
.L8024242C:
/* CC5C3C 8024242C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CC5C40 80242430 8FB3001C */  lw        $s3, 0x1c($sp)
/* CC5C44 80242434 8FB20018 */  lw        $s2, 0x18($sp)
/* CC5C48 80242438 8FB10014 */  lw        $s1, 0x14($sp)
/* CC5C4C 8024243C 8FB00010 */  lw        $s0, 0x10($sp)
/* CC5C50 80242440 03E00008 */  jr        $ra
/* CC5C54 80242444 27BD0028 */   addiu    $sp, $sp, 0x28
