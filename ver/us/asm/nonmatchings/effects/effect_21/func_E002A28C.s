.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E002A28C
/* 33EB4C E002A28C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 33EB50 E002A290 AFBF0010 */  sw        $ra, 0x10($sp)
/* 33EB54 E002A294 8C83000C */  lw        $v1, 0xc($a0)
/* 33EB58 E002A298 8C62002C */  lw        $v0, 0x2c($v1)
/* 33EB5C E002A29C 2442FFFF */  addiu     $v0, $v0, -1
/* 33EB60 E002A2A0 04410005 */  bgez      $v0, .LE002A2B8
/* 33EB64 E002A2A4 AC62002C */   sw       $v0, 0x2c($v1)
/* 33EB68 E002A2A8 0C080128 */  jal       func_E02004A0
/* 33EB6C E002A2AC 00000000 */   nop
/* 33EB70 E002A2B0 0800A8DD */  j         .LE002A374
/* 33EB74 E002A2B4 00000000 */   nop
.LE002A2B8:
/* 33EB78 E002A2B8 8C660000 */  lw        $a2, ($v1)
/* 33EB7C E002A2BC 28420018 */  slti      $v0, $v0, 0x18
/* 33EB80 E002A2C0 10400009 */  beqz      $v0, .LE002A2E8
/* 33EB84 E002A2C4 00000000 */   nop
/* 33EB88 E002A2C8 3C01E003 */  lui       $at, %hi(D_E002A730)
/* 33EB8C E002A2CC D422A730 */  ldc1      $f2, %lo(D_E002A730)($at)
/* 33EB90 E002A2D0 C4600018 */  lwc1      $f0, 0x18($v1)
/* 33EB94 E002A2D4 46800021 */  cvt.d.w   $f0, $f0
/* 33EB98 E002A2D8 46220002 */  mul.d     $f0, $f0, $f2
/* 33EB9C E002A2DC 00000000 */  nop
/* 33EBA0 E002A2E0 4620020D */  trunc.w.d $f8, $f0
/* 33EBA4 E002A2E4 E4680018 */  swc1      $f8, 0x18($v1)
.LE002A2E8:
/* 33EBA8 E002A2E8 8C820008 */  lw        $v0, 8($a0)
/* 33EBAC E002A2EC 24050001 */  addiu     $a1, $zero, 1
/* 33EBB0 E002A2F0 00A2102A */  slt       $v0, $a1, $v0
/* 33EBB4 E002A2F4 1040001F */  beqz      $v0, .LE002A374
/* 33EBB8 E002A2F8 24630048 */   addiu    $v1, $v1, 0x48
/* 33EBBC E002A2FC 28C60002 */  slti      $a2, $a2, 2
/* 33EBC0 E002A300 3C01E003 */  lui       $at, %hi(D_E002A738)
/* 33EBC4 E002A304 D426A738 */  ldc1      $f6, %lo(D_E002A738)($at)
/* 33EBC8 E002A308 24630020 */  addiu     $v1, $v1, 0x20
.LE002A30C:
/* 33EBCC E002A30C C460FFF0 */  lwc1      $f0, -0x10($v1)
/* 33EBD0 E002A310 C462FFF4 */  lwc1      $f2, -0xc($v1)
/* 33EBD4 E002A314 46020000 */  add.s     $f0, $f0, $f2
/* 33EBD8 E002A318 C462FFE8 */  lwc1      $f2, -0x18($v1)
/* 33EBDC E002A31C 46001080 */  add.s     $f2, $f2, $f0
/* 33EBE0 E002A320 E460FFF0 */  swc1      $f0, -0x10($v1)
/* 33EBE4 E002A324 10C00006 */  beqz      $a2, .LE002A340
/* 33EBE8 E002A328 E462FFE8 */   swc1     $f2, -0x18($v1)
/* 33EBEC E002A32C C4600004 */  lwc1      $f0, 4($v1)
/* 33EBF0 E002A330 46000021 */  cvt.d.s   $f0, $f0
/* 33EBF4 E002A334 46260000 */  add.d     $f0, $f0, $f6
/* 33EBF8 E002A338 46200020 */  cvt.s.d   $f0, $f0
/* 33EBFC E002A33C E4600004 */  swc1      $f0, 4($v1)
.LE002A340:
/* 33EC00 E002A340 C464FFFC */  lwc1      $f4, -4($v1)
/* 33EC04 E002A344 C4600004 */  lwc1      $f0, 4($v1)
/* 33EC08 E002A348 C4620000 */  lwc1      $f2, ($v1)
/* 33EC0C E002A34C 46002100 */  add.s     $f4, $f4, $f0
/* 33EC10 E002A350 C4600008 */  lwc1      $f0, 8($v1)
/* 33EC14 E002A354 46001080 */  add.s     $f2, $f2, $f0
/* 33EC18 E002A358 24A50001 */  addiu     $a1, $a1, 1
/* 33EC1C E002A35C E464FFFC */  swc1      $f4, -4($v1)
/* 33EC20 E002A360 E4620000 */  swc1      $f2, ($v1)
/* 33EC24 E002A364 8C820008 */  lw        $v0, 8($a0)
/* 33EC28 E002A368 00A2102A */  slt       $v0, $a1, $v0
/* 33EC2C E002A36C 1440FFE7 */  bnez      $v0, .LE002A30C
/* 33EC30 E002A370 24630048 */   addiu    $v1, $v1, 0x48
.LE002A374:
/* 33EC34 E002A374 8FBF0010 */  lw        $ra, 0x10($sp)
/* 33EC38 E002A378 03E00008 */  jr        $ra
/* 33EC3C E002A37C 27BD0018 */   addiu    $sp, $sp, 0x18
