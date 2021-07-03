.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245978_A161F8
.double 1.570796

.section .text

glabel func_8024031C_A10B9C
/* A10B9C 8024031C 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A10BA0 80240320 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* A10BA4 80240324 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* A10BA8 80240328 3C014334 */  lui       $at, 0x4334
/* A10BAC 8024032C 44811000 */  mtc1      $at, $f2
/* A10BB0 80240330 3C014049 */  lui       $at, 0x4049
/* A10BB4 80240334 34210FD8 */  ori       $at, $at, 0xfd8
/* A10BB8 80240338 44812000 */  mtc1      $at, $f4
/* A10BBC 8024033C 2404012C */  addiu     $a0, $zero, 0x12c
/* A10BC0 80240340 AFBF0034 */  sw        $ra, 0x34($sp)
/* A10BC4 80240344 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* A10BC8 80240348 46020003 */  div.s     $f0, $f0, $f2
/* A10BCC 8024034C 46040782 */  mul.s     $f30, $f0, $f4
/* A10BD0 80240350 00000000 */  nop
/* A10BD4 80240354 AFB00030 */  sw        $s0, 0x30($sp)
/* A10BD8 80240358 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* A10BDC 8024035C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* A10BE0 80240360 3C018024 */  lui       $at, %hi(D_80245978_A161F8)
/* A10BE4 80240364 D4225978 */  ldc1      $f2, %lo(D_80245978_A161F8)($at)
/* A10BE8 80240368 4600F021 */  cvt.d.s   $f0, $f30
/* A10BEC 8024036C 46220100 */  add.d     $f4, $f0, $f2
/* A10BF0 80240370 F7B80048 */  sdc1      $f24, 0x48($sp)
/* A10BF4 80240374 F7B60040 */  sdc1      $f22, 0x40($sp)
/* A10BF8 80240378 46220001 */  sub.d     $f0, $f0, $f2
/* A10BFC 8024037C F7B40038 */  sdc1      $f20, 0x38($sp)
/* A10C00 80240380 46202120 */  cvt.s.d   $f4, $f4
/* A10C04 80240384 46200020 */  cvt.s.d   $f0, $f0
/* A10C08 80240388 E7A40020 */  swc1      $f4, 0x20($sp)
/* A10C0C 8024038C 0C00A67F */  jal       rand_int
/* A10C10 80240390 E7A00024 */   swc1     $f0, 0x24($sp)
/* A10C14 80240394 2442FF6A */  addiu     $v0, $v0, -0x96
/* A10C18 80240398 4482B000 */  mtc1      $v0, $f22
/* A10C1C 8024039C 00000000 */  nop
/* A10C20 802403A0 4680B5A0 */  cvt.s.w   $f22, $f22
/* A10C24 802403A4 0C00A67F */  jal       rand_int
/* A10C28 802403A8 2404012C */   addiu    $a0, $zero, 0x12c
/* A10C2C 802403AC 24040064 */  addiu     $a0, $zero, 0x64
/* A10C30 802403B0 2442FF6A */  addiu     $v0, $v0, -0x96
/* A10C34 802403B4 44823000 */  mtc1      $v0, $f6
/* A10C38 802403B8 00000000 */  nop
/* A10C3C 802403BC 468031A0 */  cvt.s.w   $f6, $f6
/* A10C40 802403C0 0C00A67F */  jal       rand_int
/* A10C44 802403C4 E7A60028 */   swc1     $f6, 0x28($sp)
/* A10C48 802403C8 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A10C4C 802403CC 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A10C50 802403D0 24420032 */  addiu     $v0, $v0, 0x32
/* A10C54 802403D4 C602002C */  lwc1      $f2, 0x2c($s0)
/* A10C58 802403D8 3C01437A */  lui       $at, 0x437a
/* A10C5C 802403DC 44810000 */  mtc1      $at, $f0
/* A10C60 802403E0 4482A000 */  mtc1      $v0, $f20
/* A10C64 802403E4 00000000 */  nop
/* A10C68 802403E8 4680A520 */  cvt.s.w   $f20, $f20
/* A10C6C 802403EC 4602003E */  c.le.s    $f0, $f2
/* A10C70 802403F0 00000000 */  nop
/* A10C74 802403F4 45010045 */  bc1t      .L8024050C
/* A10C78 802403F8 24020002 */   addiu    $v0, $zero, 2
/* A10C7C 802403FC 0C00A85B */  jal       sin_rad
/* A10C80 80240400 4600F306 */   mov.s    $f12, $f30
/* A10C84 80240404 4600A002 */  mul.s     $f0, $f20, $f0
/* A10C88 80240408 00000000 */  nop
/* A10C8C 8024040C C61A0028 */  lwc1      $f26, 0x28($s0)
/* A10C90 80240410 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* A10C94 80240414 0C00A85B */  jal       sin_rad
/* A10C98 80240418 4600D681 */   sub.s    $f26, $f26, $f0
/* A10C9C 8024041C 4600B002 */  mul.s     $f0, $f22, $f0
/* A10CA0 80240420 00000000 */  nop
/* A10CA4 80240424 C61C002C */  lwc1      $f28, 0x2c($s0)
/* A10CA8 80240428 4600D680 */  add.s     $f26, $f26, $f0
/* A10CAC 8024042C 3C014348 */  lui       $at, 0x4348
/* A10CB0 80240430 44810000 */  mtc1      $at, $f0
/* A10CB4 80240434 00000000 */  nop
/* A10CB8 80240438 4600E700 */  add.s     $f28, $f28, $f0
/* A10CBC 8024043C 0C00A874 */  jal       cos_rad
/* A10CC0 80240440 4600F306 */   mov.s    $f12, $f30
/* A10CC4 80240444 4600A002 */  mul.s     $f0, $f20, $f0
/* A10CC8 80240448 00000000 */  nop
/* A10CCC 8024044C C6180030 */  lwc1      $f24, 0x30($s0)
/* A10CD0 80240450 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* A10CD4 80240454 0C00A874 */  jal       cos_rad
/* A10CD8 80240458 4600C600 */   add.s    $f24, $f24, $f0
/* A10CDC 8024045C 4600B002 */  mul.s     $f0, $f22, $f0
/* A10CE0 80240460 00000000 */  nop
/* A10CE4 80240464 4600C601 */  sub.s     $f24, $f24, $f0
/* A10CE8 80240468 0C00A85B */  jal       sin_rad
/* A10CEC 8024046C 4600F306 */   mov.s    $f12, $f30
/* A10CF0 80240470 4600A002 */  mul.s     $f0, $f20, $f0
/* A10CF4 80240474 00000000 */  nop
/* A10CF8 80240478 C6160028 */  lwc1      $f22, 0x28($s0)
/* A10CFC 8024047C C7AC0024 */  lwc1      $f12, 0x24($sp)
/* A10D00 80240480 0C00A85B */  jal       sin_rad
/* A10D04 80240484 4600B581 */   sub.s    $f22, $f22, $f0
/* A10D08 80240488 C7A60028 */  lwc1      $f6, 0x28($sp)
/* A10D0C 8024048C 46003002 */  mul.s     $f0, $f6, $f0
/* A10D10 80240490 00000000 */  nop
/* A10D14 80240494 4600F306 */  mov.s     $f12, $f30
/* A10D18 80240498 C61E002C */  lwc1      $f30, 0x2c($s0)
/* A10D1C 8024049C 0C00A874 */  jal       cos_rad
/* A10D20 802404A0 4600B580 */   add.s    $f22, $f22, $f0
/* A10D24 802404A4 4600A002 */  mul.s     $f0, $f20, $f0
/* A10D28 802404A8 00000000 */  nop
/* A10D2C 802404AC C6140030 */  lwc1      $f20, 0x30($s0)
/* A10D30 802404B0 C7AC0024 */  lwc1      $f12, 0x24($sp)
/* A10D34 802404B4 0C00A874 */  jal       cos_rad
/* A10D38 802404B8 4600A500 */   add.s    $f20, $f20, $f0
/* A10D3C 802404BC C7A60028 */  lwc1      $f6, 0x28($sp)
/* A10D40 802404C0 46003002 */  mul.s     $f0, $f6, $f0
/* A10D44 802404C4 00000000 */  nop
/* A10D48 802404C8 2404000A */  addiu     $a0, $zero, 0xa
/* A10D4C 802404CC 0C00A67F */  jal       rand_int
/* A10D50 802404D0 4600A501 */   sub.s    $f20, $f20, $f0
/* A10D54 802404D4 24040001 */  addiu     $a0, $zero, 1
/* A10D58 802404D8 2442000A */  addiu     $v0, $v0, 0xa
/* A10D5C 802404DC 4405D000 */  mfc1      $a1, $f26
/* A10D60 802404E0 4406E000 */  mfc1      $a2, $f28
/* A10D64 802404E4 4407C000 */  mfc1      $a3, $f24
/* A10D68 802404E8 44820000 */  mtc1      $v0, $f0
/* A10D6C 802404EC 00000000 */  nop
/* A10D70 802404F0 46800020 */  cvt.s.w   $f0, $f0
/* A10D74 802404F4 E7B60010 */  swc1      $f22, 0x10($sp)
/* A10D78 802404F8 E7BE0014 */  swc1      $f30, 0x14($sp)
/* A10D7C 802404FC E7A0001C */  swc1      $f0, 0x1c($sp)
/* A10D80 80240500 0C01BF8C */  jal       playFX_0F
/* A10D84 80240504 E7B40018 */   swc1     $f20, 0x18($sp)
/* A10D88 80240508 24020002 */  addiu     $v0, $zero, 2
.L8024050C:
/* A10D8C 8024050C 8FBF0034 */  lw        $ra, 0x34($sp)
/* A10D90 80240510 8FB00030 */  lw        $s0, 0x30($sp)
/* A10D94 80240514 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* A10D98 80240518 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* A10D9C 8024051C D7BA0050 */  ldc1      $f26, 0x50($sp)
/* A10DA0 80240520 D7B80048 */  ldc1      $f24, 0x48($sp)
/* A10DA4 80240524 D7B60040 */  ldc1      $f22, 0x40($sp)
/* A10DA8 80240528 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A10DAC 8024052C 03E00008 */  jr        $ra
/* A10DB0 80240530 27BD0068 */   addiu    $sp, $sp, 0x68
