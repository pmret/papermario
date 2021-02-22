.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240238_D4BC58
/* D4BC58 80240238 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* D4BC5C 8024023C AFB1002C */  sw        $s1, 0x2c($sp)
/* D4BC60 80240240 0080882D */  daddu     $s1, $a0, $zero
/* D4BC64 80240244 AFBF0030 */  sw        $ra, 0x30($sp)
/* D4BC68 80240248 AFB00028 */  sw        $s0, 0x28($sp)
/* D4BC6C 8024024C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* D4BC70 80240250 F7B80048 */  sdc1      $f24, 0x48($sp)
/* D4BC74 80240254 F7B60040 */  sdc1      $f22, 0x40($sp)
/* D4BC78 80240258 F7B40038 */  sdc1      $f20, 0x38($sp)
/* D4BC7C 8024025C 8E30000C */  lw        $s0, 0xc($s1)
/* D4BC80 80240260 8E050000 */  lw        $a1, ($s0)
/* D4BC84 80240264 0C0B210B */  jal       get_float_variable
/* D4BC88 80240268 26100004 */   addiu    $s0, $s0, 4
/* D4BC8C 8024026C 8E050000 */  lw        $a1, ($s0)
/* D4BC90 80240270 26100004 */  addiu     $s0, $s0, 4
/* D4BC94 80240274 0220202D */  daddu     $a0, $s1, $zero
/* D4BC98 80240278 0C0B210B */  jal       get_float_variable
/* D4BC9C 8024027C 46000686 */   mov.s    $f26, $f0
/* D4BCA0 80240280 8E050000 */  lw        $a1, ($s0)
/* D4BCA4 80240284 26100004 */  addiu     $s0, $s0, 4
/* D4BCA8 80240288 0220202D */  daddu     $a0, $s1, $zero
/* D4BCAC 8024028C 0C0B210B */  jal       get_float_variable
/* D4BCB0 80240290 46000506 */   mov.s    $f20, $f0
/* D4BCB4 80240294 8E050000 */  lw        $a1, ($s0)
/* D4BCB8 80240298 26100004 */  addiu     $s0, $s0, 4
/* D4BCBC 8024029C 0220202D */  daddu     $a0, $s1, $zero
/* D4BCC0 802402A0 0C0B210B */  jal       get_float_variable
/* D4BCC4 802402A4 46000586 */   mov.s    $f22, $f0
/* D4BCC8 802402A8 0220202D */  daddu     $a0, $s1, $zero
/* D4BCCC 802402AC 8E050000 */  lw        $a1, ($s0)
/* D4BCD0 802402B0 0C0B210B */  jal       get_float_variable
/* D4BCD4 802402B4 46000606 */   mov.s    $f24, $f0
/* D4BCD8 802402B8 3C065555 */  lui       $a2, 0x5555
/* D4BCDC 802402BC 3C078011 */  lui       $a3, %hi(gPlayerStatus)
/* D4BCE0 802402C0 24E7EFC8 */  addiu     $a3, $a3, %lo(gPlayerStatus)
/* D4BCE4 802402C4 94E200B0 */  lhu       $v0, 0xb0($a3)
/* D4BCE8 802402C8 34C65556 */  ori       $a2, $a2, 0x5556
/* D4BCEC 802402CC 00021400 */  sll       $v0, $v0, 0x10
/* D4BCF0 802402D0 00022403 */  sra       $a0, $v0, 0x10
/* D4BCF4 802402D4 00041840 */  sll       $v1, $a0, 1
/* D4BCF8 802402D8 00660018 */  mult      $v1, $a2
/* D4BCFC 802402DC C4E20028 */  lwc1      $f2, 0x28($a3)
/* D4BD00 802402E0 46141080 */  add.s     $f2, $f2, $f20
/* D4BD04 802402E4 00005010 */  mfhi      $t2
/* D4BD08 802402E8 C4E4002C */  lwc1      $f4, 0x2c($a3)
/* D4BD0C 802402EC 00000000 */  nop
/* D4BD10 802402F0 00860018 */  mult      $a0, $a2
/* D4BD14 802402F4 00031FC3 */  sra       $v1, $v1, 0x1f
/* D4BD18 802402F8 44051000 */  mfc1      $a1, $f2
/* D4BD1C 802402FC 01431823 */  subu      $v1, $t2, $v1
/* D4BD20 80240300 44831000 */  mtc1      $v1, $f2
/* D4BD24 80240304 00000000 */  nop
/* D4BD28 80240308 468010A0 */  cvt.s.w   $f2, $f2
/* D4BD2C 8024030C 46022100 */  add.s     $f4, $f4, $f2
/* D4BD30 80240310 26100004 */  addiu     $s0, $s0, 4
/* D4BD34 80240314 8E100000 */  lw        $s0, ($s0)
/* D4BD38 80240318 46162100 */  add.s     $f4, $f4, $f22
/* D4BD3C 8024031C E7BA0014 */  swc1      $f26, 0x14($sp)
/* D4BD40 80240320 000217C3 */  sra       $v0, $v0, 0x1f
/* D4BD44 80240324 00004010 */  mfhi      $t0
/* D4BD48 80240328 01021023 */  subu      $v0, $t0, $v0
/* D4BD4C 8024032C 00021400 */  sll       $v0, $v0, 0x10
/* D4BD50 80240330 00021403 */  sra       $v0, $v0, 0x10
/* D4BD54 80240334 44821000 */  mtc1      $v0, $f2
/* D4BD58 80240338 00000000 */  nop
/* D4BD5C 8024033C 468010A0 */  cvt.s.w   $f2, $f2
/* D4BD60 80240340 46001080 */  add.s     $f2, $f2, $f0
/* D4BD64 80240344 C4E00030 */  lwc1      $f0, 0x30($a3)
/* D4BD68 80240348 46180000 */  add.s     $f0, $f0, $f24
/* D4BD6C 8024034C 0000202D */  daddu     $a0, $zero, $zero
/* D4BD70 80240350 44062000 */  mfc1      $a2, $f4
/* D4BD74 80240354 44070000 */  mfc1      $a3, $f0
/* D4BD78 80240358 27A20020 */  addiu     $v0, $sp, 0x20
/* D4BD7C 8024035C AFA20018 */  sw        $v0, 0x18($sp)
/* D4BD80 80240360 0C01C1FC */  jal       fx_sleep_bubble
/* D4BD84 80240364 E7A20010 */   swc1     $f2, 0x10($sp)
/* D4BD88 80240368 0220202D */  daddu     $a0, $s1, $zero
/* D4BD8C 8024036C 8FA60020 */  lw        $a2, 0x20($sp)
/* D4BD90 80240370 0C0B2026 */  jal       set_variable
/* D4BD94 80240374 0200282D */   daddu    $a1, $s0, $zero
/* D4BD98 80240378 8FBF0030 */  lw        $ra, 0x30($sp)
/* D4BD9C 8024037C 8FB1002C */  lw        $s1, 0x2c($sp)
/* D4BDA0 80240380 8FB00028 */  lw        $s0, 0x28($sp)
/* D4BDA4 80240384 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* D4BDA8 80240388 D7B80048 */  ldc1      $f24, 0x48($sp)
/* D4BDAC 8024038C D7B60040 */  ldc1      $f22, 0x40($sp)
/* D4BDB0 80240390 D7B40038 */  ldc1      $f20, 0x38($sp)
/* D4BDB4 80240394 24020002 */  addiu     $v0, $zero, 2
/* D4BDB8 80240398 03E00008 */  jr        $ra
/* D4BDBC 8024039C 27BD0058 */   addiu    $sp, $sp, 0x58
