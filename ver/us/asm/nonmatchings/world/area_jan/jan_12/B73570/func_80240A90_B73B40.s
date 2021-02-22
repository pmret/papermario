.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A90_B73B40
/* B73B40 80240A90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B73B44 80240A94 AFB40028 */  sw        $s4, 0x28($sp)
/* B73B48 80240A98 0080A02D */  daddu     $s4, $a0, $zero
/* B73B4C 80240A9C AFBF002C */  sw        $ra, 0x2c($sp)
/* B73B50 80240AA0 AFB30024 */  sw        $s3, 0x24($sp)
/* B73B54 80240AA4 AFB20020 */  sw        $s2, 0x20($sp)
/* B73B58 80240AA8 AFB1001C */  sw        $s1, 0x1c($sp)
/* B73B5C 80240AAC AFB00018 */  sw        $s0, 0x18($sp)
/* B73B60 80240AB0 8E910148 */  lw        $s1, 0x148($s4)
/* B73B64 80240AB4 86240008 */  lh        $a0, 8($s1)
/* B73B68 80240AB8 0C00EABB */  jal       get_npc_unsafe
/* B73B6C 80240ABC 00A0802D */   daddu    $s0, $a1, $zero
/* B73B70 80240AC0 16000005 */  bnez      $s0, .L80240AD8
/* B73B74 80240AC4 0040902D */   daddu    $s2, $v0, $zero
/* B73B78 80240AC8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B73B7C 80240ACC 30420004 */  andi      $v0, $v0, 4
/* B73B80 80240AD0 10400015 */  beqz      $v0, .L80240B28
/* B73B84 80240AD4 00000000 */   nop
.L80240AD8:
/* B73B88 80240AD8 AE800070 */  sw        $zero, 0x70($s4)
/* B73B8C 80240ADC 8E420000 */  lw        $v0, ($s2)
/* B73B90 80240AE0 3C031F30 */  lui       $v1, 0x1f30
/* B73B94 80240AE4 A640008E */  sh        $zero, 0x8e($s2)
/* B73B98 80240AE8 34420102 */  ori       $v0, $v0, 0x102
/* B73B9C 80240AEC AE420000 */  sw        $v0, ($s2)
/* B73BA0 80240AF0 8E220000 */  lw        $v0, ($s1)
/* B73BA4 80240AF4 3C01C47A */  lui       $at, 0xc47a
/* B73BA8 80240AF8 44810000 */  mtc1      $at, $f0
/* B73BAC 80240AFC 00431025 */  or        $v0, $v0, $v1
/* B73BB0 80240B00 AE220000 */  sw        $v0, ($s1)
/* B73BB4 80240B04 AE400038 */  sw        $zero, 0x38($s2)
/* B73BB8 80240B08 E640003C */  swc1      $f0, 0x3c($s2)
/* B73BBC 80240B0C AE400040 */  sw        $zero, 0x40($s2)
/* B73BC0 80240B10 8E2300B0 */  lw        $v1, 0xb0($s1)
/* B73BC4 80240B14 30620004 */  andi      $v0, $v1, 4
/* B73BC8 80240B18 10400003 */  beqz      $v0, .L80240B28
/* B73BCC 80240B1C 2402FFFB */   addiu    $v0, $zero, -5
/* B73BD0 80240B20 00621024 */  and       $v0, $v1, $v0
/* B73BD4 80240B24 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240B28:
/* B73BD8 80240B28 8E930070 */  lw        $s3, 0x70($s4)
/* B73BDC 80240B2C 12600005 */  beqz      $s3, .L80240B44
/* B73BE0 80240B30 24020001 */   addiu    $v0, $zero, 1
/* B73BE4 80240B34 12620048 */  beq       $s3, $v0, .L80240C58
/* B73BE8 80240B38 00000000 */   nop
/* B73BEC 80240B3C 08090333 */  j         .L80240CCC
/* B73BF0 80240B40 00000000 */   nop
.L80240B44:
/* B73BF4 80240B44 86240008 */  lh        $a0, 8($s1)
/* B73BF8 80240B48 0C00FB3A */  jal       get_enemy
/* B73BFC 80240B4C 2484FFFF */   addiu    $a0, $a0, -1
/* B73C00 80240B50 0040802D */  daddu     $s0, $v0, $zero
/* B73C04 80240B54 0C00EABB */  jal       get_npc_unsafe
/* B73C08 80240B58 86040008 */   lh       $a0, 8($s0)
/* B73C0C 80240B5C 24030001 */  addiu     $v1, $zero, 1
/* B73C10 80240B60 0040982D */  daddu     $s3, $v0, $zero
/* B73C14 80240B64 A2230007 */  sb        $v1, 7($s1)
/* B73C18 80240B68 8E03006C */  lw        $v1, 0x6c($s0)
/* B73C1C 80240B6C 24020003 */  addiu     $v0, $zero, 3
/* B73C20 80240B70 14620056 */  bne       $v1, $v0, .L80240CCC
/* B73C24 80240B74 00000000 */   nop
/* B73C28 80240B78 8E2500A8 */  lw        $a1, 0xa8($s1)
/* B73C2C 80240B7C 10A00003 */  beqz      $a1, .L80240B8C
/* B73C30 80240B80 0260202D */   daddu    $a0, $s3, $zero
/* B73C34 80240B84 0C012530 */  jal       func_800494C0
/* B73C38 80240B88 0000302D */   daddu    $a2, $zero, $zero
.L80240B8C:
/* B73C3C 80240B8C 27A40010 */  addiu     $a0, $sp, 0x10
/* B73C40 80240B90 C6280070 */  lwc1      $f8, 0x70($s1)
/* B73C44 80240B94 46804220 */  cvt.s.w   $f8, $f8
/* B73C48 80240B98 C6620034 */  lwc1      $f2, 0x34($s3)
/* B73C4C 80240B9C 3C014387 */  lui       $at, 0x4387
/* B73C50 80240BA0 44810000 */  mtc1      $at, $f0
/* B73C54 80240BA4 44064000 */  mfc1      $a2, $f8
/* B73C58 80240BA8 46020001 */  sub.s     $f0, $f0, $f2
/* B73C5C 80240BAC C6660038 */  lwc1      $f6, 0x38($s3)
/* B73C60 80240BB0 C6640040 */  lwc1      $f4, 0x40($s3)
/* B73C64 80240BB4 44070000 */  mfc1      $a3, $f0
/* B73C68 80240BB8 27A50014 */  addiu     $a1, $sp, 0x14
/* B73C6C 80240BBC E7A60010 */  swc1      $f6, 0x10($sp)
/* B73C70 80240BC0 0C00A7E7 */  jal       add_vec2D_polar
/* B73C74 80240BC4 E7A40014 */   swc1     $f4, 0x14($sp)
/* B73C78 80240BC8 C7A00010 */  lwc1      $f0, 0x10($sp)
/* B73C7C 80240BCC 4600020D */  trunc.w.s $f8, $f0
/* B73C80 80240BD0 44024000 */  mfc1      $v0, $f8
/* B73C84 80240BD4 E6400038 */  swc1      $f0, 0x38($s2)
/* B73C88 80240BD8 A6220010 */  sh        $v0, 0x10($s1)
/* B73C8C 80240BDC C660003C */  lwc1      $f0, 0x3c($s3)
/* B73C90 80240BE0 C622006C */  lwc1      $f2, 0x6c($s1)
/* B73C94 80240BE4 468010A0 */  cvt.s.w   $f2, $f2
/* B73C98 80240BE8 46020000 */  add.s     $f0, $f0, $f2
/* B73C9C 80240BEC 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* B73CA0 80240BF0 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* B73CA4 80240BF4 E640003C */  swc1      $f0, 0x3c($s2)
/* B73CA8 80240BF8 C7A20014 */  lwc1      $f2, 0x14($sp)
/* B73CAC 80240BFC 4600020D */  trunc.w.s $f8, $f0
/* B73CB0 80240C00 44024000 */  mfc1      $v0, $f8
/* B73CB4 80240C04 00000000 */  nop
/* B73CB8 80240C08 A6220012 */  sh        $v0, 0x12($s1)
/* B73CBC 80240C0C 4600120D */  trunc.w.s $f8, $f2
/* B73CC0 80240C10 44024000 */  mfc1      $v0, $f8
/* B73CC4 80240C14 E6420040 */  swc1      $f2, 0x40($s2)
/* B73CC8 80240C18 A6220014 */  sh        $v0, 0x14($s1)
/* B73CCC 80240C1C 8C660028 */  lw        $a2, 0x28($v1)
/* B73CD0 80240C20 8C670030 */  lw        $a3, 0x30($v1)
/* B73CD4 80240C24 C64C0038 */  lwc1      $f12, 0x38($s2)
/* B73CD8 80240C28 0C00A720 */  jal       atan2
/* B73CDC 80240C2C C64E0040 */   lwc1     $f14, 0x40($s2)
/* B73CE0 80240C30 3C03E0EF */  lui       $v1, 0xe0ef
/* B73CE4 80240C34 E640000C */  swc1      $f0, 0xc($s2)
/* B73CE8 80240C38 8E220000 */  lw        $v0, ($s1)
/* B73CEC 80240C3C 3463FFFF */  ori       $v1, $v1, 0xffff
/* B73CF0 80240C40 00431024 */  and       $v0, $v0, $v1
/* B73CF4 80240C44 AE220000 */  sw        $v0, ($s1)
/* B73CF8 80240C48 24020001 */  addiu     $v0, $zero, 1
/* B73CFC 80240C4C A640008E */  sh        $zero, 0x8e($s2)
/* B73D00 80240C50 08090333 */  j         .L80240CCC
/* B73D04 80240C54 AE820070 */   sw       $v0, 0x70($s4)
.L80240C58:
/* B73D08 80240C58 86240008 */  lh        $a0, 8($s1)
/* B73D0C 80240C5C 0C00FB3A */  jal       get_enemy
/* B73D10 80240C60 2484FFFF */   addiu    $a0, $a0, -1
/* B73D14 80240C64 0040802D */  daddu     $s0, $v0, $zero
/* B73D18 80240C68 0C00EABB */  jal       get_npc_unsafe
/* B73D1C 80240C6C 86040008 */   lh       $a0, 8($s0)
/* B73D20 80240C70 9642008E */  lhu       $v0, 0x8e($s2)
/* B73D24 80240C74 24420001 */  addiu     $v0, $v0, 1
/* B73D28 80240C78 A642008E */  sh        $v0, 0x8e($s2)
/* B73D2C 80240C7C 00021400 */  sll       $v0, $v0, 0x10
/* B73D30 80240C80 8E23007C */  lw        $v1, 0x7c($s1)
/* B73D34 80240C84 00021403 */  sra       $v0, $v0, 0x10
/* B73D38 80240C88 0043102A */  slt       $v0, $v0, $v1
/* B73D3C 80240C8C 50400001 */  beql      $v0, $zero, .L80240C94
/* B73D40 80240C90 A2200007 */   sb       $zero, 7($s1)
.L80240C94:
/* B73D44 80240C94 8E03006C */  lw        $v1, 0x6c($s0)
/* B73D48 80240C98 24020004 */  addiu     $v0, $zero, 4
/* B73D4C 80240C9C 1462000B */  bne       $v1, $v0, .L80240CCC
/* B73D50 80240CA0 3C021F10 */   lui      $v0, 0x1f10
/* B73D54 80240CA4 8E230000 */  lw        $v1, ($s1)
/* B73D58 80240CA8 3C01C47A */  lui       $at, 0xc47a
/* B73D5C 80240CAC 44810000 */  mtc1      $at, $f0
/* B73D60 80240CB0 00621825 */  or        $v1, $v1, $v0
/* B73D64 80240CB4 AE230000 */  sw        $v1, ($s1)
/* B73D68 80240CB8 AE400038 */  sw        $zero, 0x38($s2)
/* B73D6C 80240CBC E640003C */  swc1      $f0, 0x3c($s2)
/* B73D70 80240CC0 AE400040 */  sw        $zero, 0x40($s2)
/* B73D74 80240CC4 A2330007 */  sb        $s3, 7($s1)
/* B73D78 80240CC8 AE800070 */  sw        $zero, 0x70($s4)
.L80240CCC:
/* B73D7C 80240CCC 8FBF002C */  lw        $ra, 0x2c($sp)
/* B73D80 80240CD0 8FB40028 */  lw        $s4, 0x28($sp)
/* B73D84 80240CD4 8FB30024 */  lw        $s3, 0x24($sp)
/* B73D88 80240CD8 8FB20020 */  lw        $s2, 0x20($sp)
/* B73D8C 80240CDC 8FB1001C */  lw        $s1, 0x1c($sp)
/* B73D90 80240CE0 8FB00018 */  lw        $s0, 0x18($sp)
/* B73D94 80240CE4 0000102D */  daddu     $v0, $zero, $zero
/* B73D98 80240CE8 03E00008 */  jr        $ra
/* B73D9C 80240CEC 27BD0030 */   addiu    $sp, $sp, 0x30
