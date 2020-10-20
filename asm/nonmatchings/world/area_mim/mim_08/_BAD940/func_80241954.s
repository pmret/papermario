.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241954
/* BAF294 80241954 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BAF298 80241958 AFB40028 */  sw        $s4, 0x28($sp)
/* BAF29C 8024195C 0080A02D */  daddu     $s4, $a0, $zero
/* BAF2A0 80241960 AFBF002C */  sw        $ra, 0x2c($sp)
/* BAF2A4 80241964 AFB30024 */  sw        $s3, 0x24($sp)
/* BAF2A8 80241968 AFB20020 */  sw        $s2, 0x20($sp)
/* BAF2AC 8024196C AFB1001C */  sw        $s1, 0x1c($sp)
/* BAF2B0 80241970 AFB00018 */  sw        $s0, 0x18($sp)
/* BAF2B4 80241974 8E910148 */  lw        $s1, 0x148($s4)
/* BAF2B8 80241978 86240008 */  lh        $a0, 8($s1)
/* BAF2BC 8024197C 0C00EABB */  jal       get_npc_unsafe
/* BAF2C0 80241980 00A0802D */   daddu    $s0, $a1, $zero
/* BAF2C4 80241984 16000005 */  bnez      $s0, .L8024199C
/* BAF2C8 80241988 0040902D */   daddu    $s2, $v0, $zero
/* BAF2CC 8024198C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BAF2D0 80241990 30420004 */  andi      $v0, $v0, 4
/* BAF2D4 80241994 10400015 */  beqz      $v0, .L802419EC
/* BAF2D8 80241998 00000000 */   nop      
.L8024199C:
/* BAF2DC 8024199C AE800070 */  sw        $zero, 0x70($s4)
/* BAF2E0 802419A0 8E420000 */  lw        $v0, ($s2)
/* BAF2E4 802419A4 3C031F30 */  lui       $v1, 0x1f30
/* BAF2E8 802419A8 A640008E */  sh        $zero, 0x8e($s2)
/* BAF2EC 802419AC 34420102 */  ori       $v0, $v0, 0x102
/* BAF2F0 802419B0 AE420000 */  sw        $v0, ($s2)
/* BAF2F4 802419B4 8E220000 */  lw        $v0, ($s1)
/* BAF2F8 802419B8 3C01C47A */  lui       $at, 0xc47a
/* BAF2FC 802419BC 44810000 */  mtc1      $at, $f0
/* BAF300 802419C0 00431025 */  or        $v0, $v0, $v1
/* BAF304 802419C4 AE220000 */  sw        $v0, ($s1)
/* BAF308 802419C8 AE400038 */  sw        $zero, 0x38($s2)
/* BAF30C 802419CC E640003C */  swc1      $f0, 0x3c($s2)
/* BAF310 802419D0 AE400040 */  sw        $zero, 0x40($s2)
/* BAF314 802419D4 8E2300B0 */  lw        $v1, 0xb0($s1)
/* BAF318 802419D8 30620004 */  andi      $v0, $v1, 4
/* BAF31C 802419DC 10400003 */  beqz      $v0, .L802419EC
/* BAF320 802419E0 2402FFFB */   addiu    $v0, $zero, -5
/* BAF324 802419E4 00621024 */  and       $v0, $v1, $v0
/* BAF328 802419E8 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802419EC:
/* BAF32C 802419EC 8E930070 */  lw        $s3, 0x70($s4)
/* BAF330 802419F0 12600005 */  beqz      $s3, .L80241A08
/* BAF334 802419F4 24020001 */   addiu    $v0, $zero, 1
/* BAF338 802419F8 12620048 */  beq       $s3, $v0, .L80241B1C
/* BAF33C 802419FC 00000000 */   nop      
/* BAF340 80241A00 080906E4 */  j         .L80241B90
/* BAF344 80241A04 00000000 */   nop      
.L80241A08:
/* BAF348 80241A08 86240008 */  lh        $a0, 8($s1)
/* BAF34C 80241A0C 0C00FB3A */  jal       get_enemy
/* BAF350 80241A10 2484FFFF */   addiu    $a0, $a0, -1
/* BAF354 80241A14 0040802D */  daddu     $s0, $v0, $zero
/* BAF358 80241A18 0C00EABB */  jal       get_npc_unsafe
/* BAF35C 80241A1C 86040008 */   lh       $a0, 8($s0)
/* BAF360 80241A20 24030001 */  addiu     $v1, $zero, 1
/* BAF364 80241A24 0040982D */  daddu     $s3, $v0, $zero
/* BAF368 80241A28 A2230007 */  sb        $v1, 7($s1)
/* BAF36C 80241A2C 8E03006C */  lw        $v1, 0x6c($s0)
/* BAF370 80241A30 24020003 */  addiu     $v0, $zero, 3
/* BAF374 80241A34 14620056 */  bne       $v1, $v0, .L80241B90
/* BAF378 80241A38 00000000 */   nop      
/* BAF37C 80241A3C 8E2500A8 */  lw        $a1, 0xa8($s1)
/* BAF380 80241A40 10A00003 */  beqz      $a1, .L80241A50
/* BAF384 80241A44 0260202D */   daddu    $a0, $s3, $zero
/* BAF388 80241A48 0C012530 */  jal       func_800494C0
/* BAF38C 80241A4C 0000302D */   daddu    $a2, $zero, $zero
.L80241A50:
/* BAF390 80241A50 27A40010 */  addiu     $a0, $sp, 0x10
/* BAF394 80241A54 C6280070 */  lwc1      $f8, 0x70($s1)
/* BAF398 80241A58 46804220 */  cvt.s.w   $f8, $f8
/* BAF39C 80241A5C C6620034 */  lwc1      $f2, 0x34($s3)
/* BAF3A0 80241A60 3C014387 */  lui       $at, 0x4387
/* BAF3A4 80241A64 44810000 */  mtc1      $at, $f0
/* BAF3A8 80241A68 44064000 */  mfc1      $a2, $f8
/* BAF3AC 80241A6C 46020001 */  sub.s     $f0, $f0, $f2
/* BAF3B0 80241A70 C6660038 */  lwc1      $f6, 0x38($s3)
/* BAF3B4 80241A74 C6640040 */  lwc1      $f4, 0x40($s3)
/* BAF3B8 80241A78 44070000 */  mfc1      $a3, $f0
/* BAF3BC 80241A7C 27A50014 */  addiu     $a1, $sp, 0x14
/* BAF3C0 80241A80 E7A60010 */  swc1      $f6, 0x10($sp)
/* BAF3C4 80241A84 0C00A7E7 */  jal       add_vec2D_polar
/* BAF3C8 80241A88 E7A40014 */   swc1     $f4, 0x14($sp)
/* BAF3CC 80241A8C C7A00010 */  lwc1      $f0, 0x10($sp)
/* BAF3D0 80241A90 4600020D */  trunc.w.s $f8, $f0
/* BAF3D4 80241A94 44024000 */  mfc1      $v0, $f8
/* BAF3D8 80241A98 E6400038 */  swc1      $f0, 0x38($s2)
/* BAF3DC 80241A9C A6220010 */  sh        $v0, 0x10($s1)
/* BAF3E0 80241AA0 C660003C */  lwc1      $f0, 0x3c($s3)
/* BAF3E4 80241AA4 C622006C */  lwc1      $f2, 0x6c($s1)
/* BAF3E8 80241AA8 468010A0 */  cvt.s.w   $f2, $f2
/* BAF3EC 80241AAC 46020000 */  add.s     $f0, $f0, $f2
/* BAF3F0 80241AB0 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* BAF3F4 80241AB4 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* BAF3F8 80241AB8 E640003C */  swc1      $f0, 0x3c($s2)
/* BAF3FC 80241ABC C7A20014 */  lwc1      $f2, 0x14($sp)
/* BAF400 80241AC0 4600020D */  trunc.w.s $f8, $f0
/* BAF404 80241AC4 44024000 */  mfc1      $v0, $f8
/* BAF408 80241AC8 00000000 */  nop       
/* BAF40C 80241ACC A6220012 */  sh        $v0, 0x12($s1)
/* BAF410 80241AD0 4600120D */  trunc.w.s $f8, $f2
/* BAF414 80241AD4 44024000 */  mfc1      $v0, $f8
/* BAF418 80241AD8 E6420040 */  swc1      $f2, 0x40($s2)
/* BAF41C 80241ADC A6220014 */  sh        $v0, 0x14($s1)
/* BAF420 80241AE0 8C660028 */  lw        $a2, 0x28($v1)
/* BAF424 80241AE4 8C670030 */  lw        $a3, 0x30($v1)
/* BAF428 80241AE8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* BAF42C 80241AEC 0C00A720 */  jal       atan2
/* BAF430 80241AF0 C64E0040 */   lwc1     $f14, 0x40($s2)
/* BAF434 80241AF4 3C03E0EF */  lui       $v1, 0xe0ef
/* BAF438 80241AF8 E640000C */  swc1      $f0, 0xc($s2)
/* BAF43C 80241AFC 8E220000 */  lw        $v0, ($s1)
/* BAF440 80241B00 3463FFFF */  ori       $v1, $v1, 0xffff
/* BAF444 80241B04 00431024 */  and       $v0, $v0, $v1
/* BAF448 80241B08 AE220000 */  sw        $v0, ($s1)
/* BAF44C 80241B0C 24020001 */  addiu     $v0, $zero, 1
/* BAF450 80241B10 A640008E */  sh        $zero, 0x8e($s2)
/* BAF454 80241B14 080906E4 */  j         .L80241B90
/* BAF458 80241B18 AE820070 */   sw       $v0, 0x70($s4)
.L80241B1C:
/* BAF45C 80241B1C 86240008 */  lh        $a0, 8($s1)
/* BAF460 80241B20 0C00FB3A */  jal       get_enemy
/* BAF464 80241B24 2484FFFF */   addiu    $a0, $a0, -1
/* BAF468 80241B28 0040802D */  daddu     $s0, $v0, $zero
/* BAF46C 80241B2C 0C00EABB */  jal       get_npc_unsafe
/* BAF470 80241B30 86040008 */   lh       $a0, 8($s0)
/* BAF474 80241B34 9642008E */  lhu       $v0, 0x8e($s2)
/* BAF478 80241B38 24420001 */  addiu     $v0, $v0, 1
/* BAF47C 80241B3C A642008E */  sh        $v0, 0x8e($s2)
/* BAF480 80241B40 00021400 */  sll       $v0, $v0, 0x10
/* BAF484 80241B44 8E23007C */  lw        $v1, 0x7c($s1)
/* BAF488 80241B48 00021403 */  sra       $v0, $v0, 0x10
/* BAF48C 80241B4C 0043102A */  slt       $v0, $v0, $v1
/* BAF490 80241B50 50400001 */  beql      $v0, $zero, .L80241B58
/* BAF494 80241B54 A2200007 */   sb       $zero, 7($s1)
.L80241B58:
/* BAF498 80241B58 8E03006C */  lw        $v1, 0x6c($s0)
/* BAF49C 80241B5C 24020004 */  addiu     $v0, $zero, 4
/* BAF4A0 80241B60 1462000B */  bne       $v1, $v0, .L80241B90
/* BAF4A4 80241B64 3C021F10 */   lui      $v0, 0x1f10
/* BAF4A8 80241B68 8E230000 */  lw        $v1, ($s1)
/* BAF4AC 80241B6C 3C01C47A */  lui       $at, 0xc47a
/* BAF4B0 80241B70 44810000 */  mtc1      $at, $f0
/* BAF4B4 80241B74 00621825 */  or        $v1, $v1, $v0
/* BAF4B8 80241B78 AE230000 */  sw        $v1, ($s1)
/* BAF4BC 80241B7C AE400038 */  sw        $zero, 0x38($s2)
/* BAF4C0 80241B80 E640003C */  swc1      $f0, 0x3c($s2)
/* BAF4C4 80241B84 AE400040 */  sw        $zero, 0x40($s2)
/* BAF4C8 80241B88 A2330007 */  sb        $s3, 7($s1)
/* BAF4CC 80241B8C AE800070 */  sw        $zero, 0x70($s4)
.L80241B90:
/* BAF4D0 80241B90 8FBF002C */  lw        $ra, 0x2c($sp)
/* BAF4D4 80241B94 8FB40028 */  lw        $s4, 0x28($sp)
/* BAF4D8 80241B98 8FB30024 */  lw        $s3, 0x24($sp)
/* BAF4DC 80241B9C 8FB20020 */  lw        $s2, 0x20($sp)
/* BAF4E0 80241BA0 8FB1001C */  lw        $s1, 0x1c($sp)
/* BAF4E4 80241BA4 8FB00018 */  lw        $s0, 0x18($sp)
/* BAF4E8 80241BA8 0000102D */  daddu     $v0, $zero, $zero
/* BAF4EC 80241BAC 03E00008 */  jr        $ra
/* BAF4F0 80241BB0 27BD0030 */   addiu    $sp, $sp, 0x30
