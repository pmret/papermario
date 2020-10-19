.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240398
/* 90FA48 80240398 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 90FA4C 8024039C AFBF0024 */  sw        $ra, 0x24($sp)
/* 90FA50 802403A0 AFB40020 */  sw        $s4, 0x20($sp)
/* 90FA54 802403A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 90FA58 802403A8 AFB20018 */  sw        $s2, 0x18($sp)
/* 90FA5C 802403AC AFB10014 */  sw        $s1, 0x14($sp)
/* 90FA60 802403B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 90FA64 802403B4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 90FA68 802403B8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 90FA6C 802403BC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 90FA70 802403C0 0C00AB39 */  jal       heap_malloc
/* 90FA74 802403C4 24040320 */   addiu    $a0, $zero, 0x320
/* 90FA78 802403C8 0040982D */  daddu     $s3, $v0, $zero
/* 90FA7C 802403CC 0000202D */  daddu     $a0, $zero, $zero
/* 90FA80 802403D0 3C05FD05 */  lui       $a1, 0xfd05
/* 90FA84 802403D4 34A50F8F */  ori       $a1, $a1, 0xf8f
/* 90FA88 802403D8 0C0B2026 */  jal       set_variable
/* 90FA8C 802403DC 0260302D */   daddu    $a2, $s3, $zero
/* 90FA90 802403E0 0000902D */  daddu     $s2, $zero, $zero
/* 90FA94 802403E4 3C146666 */  lui       $s4, 0x6666
/* 90FA98 802403E8 36946667 */  ori       $s4, $s4, 0x6667
/* 90FA9C 802403EC 26700018 */  addiu     $s0, $s3, 0x18
/* 90FAA0 802403F0 0240882D */  daddu     $s1, $s2, $zero
/* 90FAA4 802403F4 3C014120 */  lui       $at, 0x4120
/* 90FAA8 802403F8 4481C000 */  mtc1      $at, $f24
/* 90FAAC 802403FC 3C018024 */  lui       $at, 0x8024
/* 90FAB0 80240400 D4346380 */  ldc1      $f20, 0x6380($at)
/* 90FAB4 80240404 3C013F80 */  lui       $at, 0x3f80
/* 90FAB8 80240408 4481B000 */  mtc1      $at, $f22
.L8024040C:
/* 90FABC 8024040C 2404000A */  addiu     $a0, $zero, 0xa
/* 90FAC0 80240410 02340018 */  mult      $s1, $s4
/* 90FAC4 80240414 00111FC3 */  sra       $v1, $s1, 0x1f
/* 90FAC8 80240418 AE600000 */  sw        $zero, ($s3)
/* 90FACC 8024041C AE00FFF0 */  sw        $zero, -0x10($s0)
/* 90FAD0 80240420 AE000004 */  sw        $zero, 4($s0)
/* 90FAD4 80240424 00003810 */  mfhi      $a3
/* 90FAD8 80240428 000710C3 */  sra       $v0, $a3, 3
/* 90FADC 8024042C 00431023 */  subu      $v0, $v0, $v1
/* 90FAE0 80240430 44820000 */  mtc1      $v0, $f0
/* 90FAE4 80240434 00000000 */  nop       
/* 90FAE8 80240438 46800020 */  cvt.s.w   $f0, $f0
/* 90FAEC 8024043C 0C00A67F */  jal       rand_int
/* 90FAF0 80240440 E600FFEC */   swc1     $f0, -0x14($s0)
/* 90FAF4 80240444 44921000 */  mtc1      $s2, $f2
/* 90FAF8 80240448 00000000 */  nop       
/* 90FAFC 8024044C 468010A0 */  cvt.s.w   $f2, $f2
/* 90FB00 80240450 460010A1 */  cvt.d.s   $f2, $f2
/* 90FB04 80240454 46341082 */  mul.d     $f2, $f2, $f20
/* 90FB08 80240458 00000000 */  nop       
/* 90FB0C 8024045C 2631FFE2 */  addiu     $s1, $s1, -0x1e
/* 90FB10 80240460 26730028 */  addiu     $s3, $s3, 0x28
/* 90FB14 80240464 24040167 */  addiu     $a0, $zero, 0x167
/* 90FB18 80240468 26520001 */  addiu     $s2, $s2, 1
/* 90FB1C 8024046C 44820000 */  mtc1      $v0, $f0
/* 90FB20 80240470 00000000 */  nop       
/* 90FB24 80240474 46800020 */  cvt.s.w   $f0, $f0
/* 90FB28 80240478 46180003 */  div.s     $f0, $f0, $f24
/* 90FB2C 8024047C 46000021 */  cvt.d.s   $f0, $f0
/* 90FB30 80240480 46220001 */  sub.d     $f0, $f0, $f2
/* 90FB34 80240484 AE00000C */  sw        $zero, 0xc($s0)
/* 90FB38 80240488 E616FFF4 */  swc1      $f22, -0xc($s0)
/* 90FB3C 8024048C 46200020 */  cvt.s.d   $f0, $f0
/* 90FB40 80240490 0C00A67F */  jal       rand_int
/* 90FB44 80240494 E6000008 */   swc1     $f0, 8($s0)
/* 90FB48 80240498 24040167 */  addiu     $a0, $zero, 0x167
/* 90FB4C 8024049C 44820000 */  mtc1      $v0, $f0
/* 90FB50 802404A0 00000000 */  nop       
/* 90FB54 802404A4 46800020 */  cvt.s.w   $f0, $f0
/* 90FB58 802404A8 0C00A67F */  jal       rand_int
/* 90FB5C 802404AC E600FFF8 */   swc1     $f0, -8($s0)
/* 90FB60 802404B0 24040167 */  addiu     $a0, $zero, 0x167
/* 90FB64 802404B4 44820000 */  mtc1      $v0, $f0
/* 90FB68 802404B8 00000000 */  nop       
/* 90FB6C 802404BC 46800020 */  cvt.s.w   $f0, $f0
/* 90FB70 802404C0 0C00A67F */  jal       rand_int
/* 90FB74 802404C4 E600FFFC */   swc1     $f0, -4($s0)
/* 90FB78 802404C8 44820000 */  mtc1      $v0, $f0
/* 90FB7C 802404CC 00000000 */  nop       
/* 90FB80 802404D0 46800020 */  cvt.s.w   $f0, $f0
/* 90FB84 802404D4 E6000000 */  swc1      $f0, ($s0)
/* 90FB88 802404D8 2A420014 */  slti      $v0, $s2, 0x14
/* 90FB8C 802404DC 1440FFCB */  bnez      $v0, .L8024040C
/* 90FB90 802404E0 26100028 */   addiu    $s0, $s0, 0x28
/* 90FB94 802404E4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 90FB98 802404E8 8FB40020 */  lw        $s4, 0x20($sp)
/* 90FB9C 802404EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 90FBA0 802404F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 90FBA4 802404F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 90FBA8 802404F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 90FBAC 802404FC D7B80038 */  ldc1      $f24, 0x38($sp)
/* 90FBB0 80240500 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 90FBB4 80240504 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 90FBB8 80240508 24020002 */  addiu     $v0, $zero, 2
/* 90FBBC 8024050C 03E00008 */  jr        $ra
/* 90FBC0 80240510 27BD0040 */   addiu    $sp, $sp, 0x40
/* 90FBC4 80240514 00000000 */  nop       
/* 90FBC8 80240518 00000000 */  nop       
/* 90FBCC 8024051C 00000000 */  nop       
