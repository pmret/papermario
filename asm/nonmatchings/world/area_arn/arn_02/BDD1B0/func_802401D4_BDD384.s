.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D4_BDD384
/* BDD384 802401D4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BDD388 802401D8 AFB3003C */  sw        $s3, 0x3c($sp)
/* BDD38C 802401DC 0080982D */  daddu     $s3, $a0, $zero
/* BDD390 802401E0 AFBF0044 */  sw        $ra, 0x44($sp)
/* BDD394 802401E4 AFB40040 */  sw        $s4, 0x40($sp)
/* BDD398 802401E8 AFB20038 */  sw        $s2, 0x38($sp)
/* BDD39C 802401EC AFB10034 */  sw        $s1, 0x34($sp)
/* BDD3A0 802401F0 AFB00030 */  sw        $s0, 0x30($sp)
/* BDD3A4 802401F4 8E700148 */  lw        $s0, 0x148($s3)
/* BDD3A8 802401F8 00A0902D */  daddu     $s2, $a1, $zero
/* BDD3AC 802401FC 86040008 */  lh        $a0, 8($s0)
/* BDD3B0 80240200 0C00EABB */  jal       get_npc_unsafe
/* BDD3B4 80240204 00C0A02D */   daddu    $s4, $a2, $zero
/* BDD3B8 80240208 8E630074 */  lw        $v1, 0x74($s3)
/* BDD3BC 8024020C 1C600032 */  bgtz      $v1, .L802402D8
/* BDD3C0 80240210 0040882D */   daddu    $s1, $v0, $zero
/* BDD3C4 80240214 8E420014 */  lw        $v0, 0x14($s2)
/* BDD3C8 80240218 AE620074 */  sw        $v0, 0x74($s3)
/* BDD3CC 8024021C C640000C */  lwc1      $f0, 0xc($s2)
/* BDD3D0 80240220 3C018024 */  lui       $at, %hi(func_80241AF0_A6FED0)
/* BDD3D4 80240224 D4221AF0 */  ldc1      $f2, %lo(func_80241AF0_A6FED0)($at)
/* BDD3D8 80240228 46000021 */  cvt.d.s   $f0, $f0
/* BDD3DC 8024022C 46220002 */  mul.d     $f0, $f0, $f2
/* BDD3E0 80240230 00000000 */  nop       
/* BDD3E4 80240234 0280202D */  daddu     $a0, $s4, $zero
/* BDD3E8 80240238 AFA00010 */  sw        $zero, 0x10($sp)
/* BDD3EC 8024023C 8E470010 */  lw        $a3, 0x10($s2)
/* BDD3F0 80240240 46200020 */  cvt.s.d   $f0, $f0
/* BDD3F4 80240244 44060000 */  mfc1      $a2, $f0
/* BDD3F8 80240248 0C01242D */  jal       func_800490B4
/* BDD3FC 8024024C 0200282D */   daddu    $a1, $s0, $zero
/* BDD400 80240250 10400021 */  beqz      $v0, .L802402D8
/* BDD404 80240254 0000202D */   daddu    $a0, $zero, $zero
/* BDD408 80240258 0220282D */  daddu     $a1, $s1, $zero
/* BDD40C 8024025C 0000302D */  daddu     $a2, $zero, $zero
/* BDD410 80240260 8E0200CC */  lw        $v0, 0xcc($s0)
/* BDD414 80240264 3C013F80 */  lui       $at, 0x3f80
/* BDD418 80240268 44810000 */  mtc1      $at, $f0
/* BDD41C 8024026C 3C014000 */  lui       $at, 0x4000
/* BDD420 80240270 44811000 */  mtc1      $at, $f2
/* BDD424 80240274 8C430024 */  lw        $v1, 0x24($v0)
/* BDD428 80240278 862200A8 */  lh        $v0, 0xa8($s1)
/* BDD42C 8024027C 3C01C1A0 */  lui       $at, 0xc1a0
/* BDD430 80240280 44812000 */  mtc1      $at, $f4
/* BDD434 80240284 44823000 */  mtc1      $v0, $f6
/* BDD438 80240288 00000000 */  nop       
/* BDD43C 8024028C 468031A0 */  cvt.s.w   $f6, $f6
/* BDD440 80240290 44073000 */  mfc1      $a3, $f6
/* BDD444 80240294 2402000F */  addiu     $v0, $zero, 0xf
/* BDD448 80240298 AE230028 */  sw        $v1, 0x28($s1)
/* BDD44C 8024029C AFA2001C */  sw        $v0, 0x1c($sp)
/* BDD450 802402A0 27A20028 */  addiu     $v0, $sp, 0x28
/* BDD454 802402A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* BDD458 802402A8 E7A20014 */  swc1      $f2, 0x14($sp)
/* BDD45C 802402AC E7A40018 */  swc1      $f4, 0x18($sp)
/* BDD460 802402B0 0C01BFA4 */  jal       fx_emote
/* BDD464 802402B4 AFA20020 */   sw       $v0, 0x20($sp)
/* BDD468 802402B8 0220202D */  daddu     $a0, $s1, $zero
/* BDD46C 802402BC 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BDD470 802402C0 0C012530 */  jal       func_800494C0
/* BDD474 802402C4 3C060020 */   lui      $a2, 0x20
/* BDD478 802402C8 2402000C */  addiu     $v0, $zero, 0xc
/* BDD47C 802402CC A622008E */  sh        $v0, 0x8e($s1)
/* BDD480 802402D0 24020002 */  addiu     $v0, $zero, 2
/* BDD484 802402D4 AE620070 */  sw        $v0, 0x70($s3)
.L802402D8:
/* BDD488 802402D8 8E620074 */  lw        $v0, 0x74($s3)
/* BDD48C 802402DC 2442FFFF */  addiu     $v0, $v0, -1
/* BDD490 802402E0 AE620074 */  sw        $v0, 0x74($s3)
/* BDD494 802402E4 8FBF0044 */  lw        $ra, 0x44($sp)
/* BDD498 802402E8 8FB40040 */  lw        $s4, 0x40($sp)
/* BDD49C 802402EC 8FB3003C */  lw        $s3, 0x3c($sp)
/* BDD4A0 802402F0 8FB20038 */  lw        $s2, 0x38($sp)
/* BDD4A4 802402F4 8FB10034 */  lw        $s1, 0x34($sp)
/* BDD4A8 802402F8 8FB00030 */  lw        $s0, 0x30($sp)
/* BDD4AC 802402FC 03E00008 */  jr        $ra
/* BDD4B0 80240300 27BD0048 */   addiu    $sp, $sp, 0x48
