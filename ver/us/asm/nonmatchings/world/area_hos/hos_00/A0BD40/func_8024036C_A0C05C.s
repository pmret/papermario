.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244B48_A10838
.double 1.570796

.section .text

glabel func_8024036C_A0C05C
/* A0C05C 8024036C 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A0C060 80240370 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* A0C064 80240374 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* A0C068 80240378 3C014334 */  lui       $at, 0x4334
/* A0C06C 8024037C 44811000 */  mtc1      $at, $f2
/* A0C070 80240380 3C014049 */  lui       $at, 0x4049
/* A0C074 80240384 34210FD8 */  ori       $at, $at, 0xfd8
/* A0C078 80240388 44812000 */  mtc1      $at, $f4
/* A0C07C 8024038C 2404012C */  addiu     $a0, $zero, 0x12c
/* A0C080 80240390 AFBF0034 */  sw        $ra, 0x34($sp)
/* A0C084 80240394 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* A0C088 80240398 46020003 */  div.s     $f0, $f0, $f2
/* A0C08C 8024039C 46040782 */  mul.s     $f30, $f0, $f4
/* A0C090 802403A0 00000000 */  nop
/* A0C094 802403A4 AFB00030 */  sw        $s0, 0x30($sp)
/* A0C098 802403A8 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* A0C09C 802403AC F7BA0050 */  sdc1      $f26, 0x50($sp)
/* A0C0A0 802403B0 3C018024 */  lui       $at, %hi(D_80244B48_A10838)
/* A0C0A4 802403B4 D4224B48 */  ldc1      $f2, %lo(D_80244B48_A10838)($at)
/* A0C0A8 802403B8 4600F021 */  cvt.d.s   $f0, $f30
/* A0C0AC 802403BC 46220100 */  add.d     $f4, $f0, $f2
/* A0C0B0 802403C0 F7B80048 */  sdc1      $f24, 0x48($sp)
/* A0C0B4 802403C4 F7B60040 */  sdc1      $f22, 0x40($sp)
/* A0C0B8 802403C8 46220001 */  sub.d     $f0, $f0, $f2
/* A0C0BC 802403CC F7B40038 */  sdc1      $f20, 0x38($sp)
/* A0C0C0 802403D0 46202120 */  cvt.s.d   $f4, $f4
/* A0C0C4 802403D4 46200020 */  cvt.s.d   $f0, $f0
/* A0C0C8 802403D8 E7A40020 */  swc1      $f4, 0x20($sp)
/* A0C0CC 802403DC 0C00A67F */  jal       rand_int
/* A0C0D0 802403E0 E7A00024 */   swc1     $f0, 0x24($sp)
/* A0C0D4 802403E4 2442FF6A */  addiu     $v0, $v0, -0x96
/* A0C0D8 802403E8 4482B000 */  mtc1      $v0, $f22
/* A0C0DC 802403EC 00000000 */  nop
/* A0C0E0 802403F0 4680B5A0 */  cvt.s.w   $f22, $f22
/* A0C0E4 802403F4 0C00A67F */  jal       rand_int
/* A0C0E8 802403F8 2404012C */   addiu    $a0, $zero, 0x12c
/* A0C0EC 802403FC 24040064 */  addiu     $a0, $zero, 0x64
/* A0C0F0 80240400 2442FF6A */  addiu     $v0, $v0, -0x96
/* A0C0F4 80240404 44823000 */  mtc1      $v0, $f6
/* A0C0F8 80240408 00000000 */  nop
/* A0C0FC 8024040C 468031A0 */  cvt.s.w   $f6, $f6
/* A0C100 80240410 0C00A67F */  jal       rand_int
/* A0C104 80240414 E7A60028 */   swc1     $f6, 0x28($sp)
/* A0C108 80240418 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A0C10C 8024041C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A0C110 80240420 24420032 */  addiu     $v0, $v0, 0x32
/* A0C114 80240424 C602002C */  lwc1      $f2, 0x2c($s0)
/* A0C118 80240428 3C01437A */  lui       $at, 0x437a
/* A0C11C 8024042C 44810000 */  mtc1      $at, $f0
/* A0C120 80240430 4482A000 */  mtc1      $v0, $f20
/* A0C124 80240434 00000000 */  nop
/* A0C128 80240438 4680A520 */  cvt.s.w   $f20, $f20
/* A0C12C 8024043C 4602003E */  c.le.s    $f0, $f2
/* A0C130 80240440 00000000 */  nop
/* A0C134 80240444 45010045 */  bc1t      .L8024055C
/* A0C138 80240448 24020002 */   addiu    $v0, $zero, 2
/* A0C13C 8024044C 0C00A85B */  jal       sin_rad
/* A0C140 80240450 4600F306 */   mov.s    $f12, $f30
/* A0C144 80240454 4600A002 */  mul.s     $f0, $f20, $f0
/* A0C148 80240458 00000000 */  nop
/* A0C14C 8024045C C61A0028 */  lwc1      $f26, 0x28($s0)
/* A0C150 80240460 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* A0C154 80240464 0C00A85B */  jal       sin_rad
/* A0C158 80240468 4600D681 */   sub.s    $f26, $f26, $f0
/* A0C15C 8024046C 4600B002 */  mul.s     $f0, $f22, $f0
/* A0C160 80240470 00000000 */  nop
/* A0C164 80240474 C61C002C */  lwc1      $f28, 0x2c($s0)
/* A0C168 80240478 4600D680 */  add.s     $f26, $f26, $f0
/* A0C16C 8024047C 3C014348 */  lui       $at, 0x4348
/* A0C170 80240480 44810000 */  mtc1      $at, $f0
/* A0C174 80240484 00000000 */  nop
/* A0C178 80240488 4600E700 */  add.s     $f28, $f28, $f0
/* A0C17C 8024048C 0C00A874 */  jal       cos_rad
/* A0C180 80240490 4600F306 */   mov.s    $f12, $f30
/* A0C184 80240494 4600A002 */  mul.s     $f0, $f20, $f0
/* A0C188 80240498 00000000 */  nop
/* A0C18C 8024049C C6180030 */  lwc1      $f24, 0x30($s0)
/* A0C190 802404A0 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* A0C194 802404A4 0C00A874 */  jal       cos_rad
/* A0C198 802404A8 4600C600 */   add.s    $f24, $f24, $f0
/* A0C19C 802404AC 4600B002 */  mul.s     $f0, $f22, $f0
/* A0C1A0 802404B0 00000000 */  nop
/* A0C1A4 802404B4 4600C601 */  sub.s     $f24, $f24, $f0
/* A0C1A8 802404B8 0C00A85B */  jal       sin_rad
/* A0C1AC 802404BC 4600F306 */   mov.s    $f12, $f30
/* A0C1B0 802404C0 4600A002 */  mul.s     $f0, $f20, $f0
/* A0C1B4 802404C4 00000000 */  nop
/* A0C1B8 802404C8 C6160028 */  lwc1      $f22, 0x28($s0)
/* A0C1BC 802404CC C7AC0024 */  lwc1      $f12, 0x24($sp)
/* A0C1C0 802404D0 0C00A85B */  jal       sin_rad
/* A0C1C4 802404D4 4600B581 */   sub.s    $f22, $f22, $f0
/* A0C1C8 802404D8 C7A60028 */  lwc1      $f6, 0x28($sp)
/* A0C1CC 802404DC 46003002 */  mul.s     $f0, $f6, $f0
/* A0C1D0 802404E0 00000000 */  nop
/* A0C1D4 802404E4 4600F306 */  mov.s     $f12, $f30
/* A0C1D8 802404E8 C61E002C */  lwc1      $f30, 0x2c($s0)
/* A0C1DC 802404EC 0C00A874 */  jal       cos_rad
/* A0C1E0 802404F0 4600B580 */   add.s    $f22, $f22, $f0
/* A0C1E4 802404F4 4600A002 */  mul.s     $f0, $f20, $f0
/* A0C1E8 802404F8 00000000 */  nop
/* A0C1EC 802404FC C6140030 */  lwc1      $f20, 0x30($s0)
/* A0C1F0 80240500 C7AC0024 */  lwc1      $f12, 0x24($sp)
/* A0C1F4 80240504 0C00A874 */  jal       cos_rad
/* A0C1F8 80240508 4600A500 */   add.s    $f20, $f20, $f0
/* A0C1FC 8024050C C7A60028 */  lwc1      $f6, 0x28($sp)
/* A0C200 80240510 46003002 */  mul.s     $f0, $f6, $f0
/* A0C204 80240514 00000000 */  nop
/* A0C208 80240518 2404000A */  addiu     $a0, $zero, 0xa
/* A0C20C 8024051C 0C00A67F */  jal       rand_int
/* A0C210 80240520 4600A501 */   sub.s    $f20, $f20, $f0
/* A0C214 80240524 24040001 */  addiu     $a0, $zero, 1
/* A0C218 80240528 2442000A */  addiu     $v0, $v0, 0xa
/* A0C21C 8024052C 4405D000 */  mfc1      $a1, $f26
/* A0C220 80240530 4406E000 */  mfc1      $a2, $f28
/* A0C224 80240534 4407C000 */  mfc1      $a3, $f24
/* A0C228 80240538 44820000 */  mtc1      $v0, $f0
/* A0C22C 8024053C 00000000 */  nop
/* A0C230 80240540 46800020 */  cvt.s.w   $f0, $f0
/* A0C234 80240544 E7B60010 */  swc1      $f22, 0x10($sp)
/* A0C238 80240548 E7BE0014 */  swc1      $f30, 0x14($sp)
/* A0C23C 8024054C E7A0001C */  swc1      $f0, 0x1c($sp)
/* A0C240 80240550 0C01BF8C */  jal       playFX_0F
/* A0C244 80240554 E7B40018 */   swc1     $f20, 0x18($sp)
/* A0C248 80240558 24020002 */  addiu     $v0, $zero, 2
.L8024055C:
/* A0C24C 8024055C 8FBF0034 */  lw        $ra, 0x34($sp)
/* A0C250 80240560 8FB00030 */  lw        $s0, 0x30($sp)
/* A0C254 80240564 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* A0C258 80240568 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* A0C25C 8024056C D7BA0050 */  ldc1      $f26, 0x50($sp)
/* A0C260 80240570 D7B80048 */  ldc1      $f24, 0x48($sp)
/* A0C264 80240574 D7B60040 */  ldc1      $f22, 0x40($sp)
/* A0C268 80240578 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A0C26C 8024057C 03E00008 */  jr        $ra
/* A0C270 80240580 27BD0068 */   addiu    $sp, $sp, 0x68
