.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80242BA0_91E480
.double 0.85

.section .text

glabel func_80240254_91BB34
/* 91BB34 80240254 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 91BB38 80240258 AFB3003C */  sw        $s3, 0x3c($sp)
/* 91BB3C 8024025C 0080982D */  daddu     $s3, $a0, $zero
/* 91BB40 80240260 AFBF0044 */  sw        $ra, 0x44($sp)
/* 91BB44 80240264 AFB40040 */  sw        $s4, 0x40($sp)
/* 91BB48 80240268 AFB20038 */  sw        $s2, 0x38($sp)
/* 91BB4C 8024026C AFB10034 */  sw        $s1, 0x34($sp)
/* 91BB50 80240270 AFB00030 */  sw        $s0, 0x30($sp)
/* 91BB54 80240274 8E700148 */  lw        $s0, 0x148($s3)
/* 91BB58 80240278 00A0902D */  daddu     $s2, $a1, $zero
/* 91BB5C 8024027C 86040008 */  lh        $a0, 8($s0)
/* 91BB60 80240280 0C00EABB */  jal       get_npc_unsafe
/* 91BB64 80240284 00C0A02D */   daddu    $s4, $a2, $zero
/* 91BB68 80240288 8E630074 */  lw        $v1, 0x74($s3)
/* 91BB6C 8024028C 1C600032 */  bgtz      $v1, .L80240358
/* 91BB70 80240290 0040882D */   daddu    $s1, $v0, $zero
/* 91BB74 80240294 8E420014 */  lw        $v0, 0x14($s2)
/* 91BB78 80240298 AE620074 */  sw        $v0, 0x74($s3)
/* 91BB7C 8024029C C640000C */  lwc1      $f0, 0xc($s2)
/* 91BB80 802402A0 3C018024 */  lui       $at, %hi(D_80242BA0_91E480)
/* 91BB84 802402A4 D4222BA0 */  ldc1      $f2, %lo(D_80242BA0_91E480)($at)
/* 91BB88 802402A8 46000021 */  cvt.d.s   $f0, $f0
/* 91BB8C 802402AC 46220002 */  mul.d     $f0, $f0, $f2
/* 91BB90 802402B0 00000000 */  nop
/* 91BB94 802402B4 0280202D */  daddu     $a0, $s4, $zero
/* 91BB98 802402B8 AFA00010 */  sw        $zero, 0x10($sp)
/* 91BB9C 802402BC 8E470010 */  lw        $a3, 0x10($s2)
/* 91BBA0 802402C0 46200020 */  cvt.s.d   $f0, $f0
/* 91BBA4 802402C4 44060000 */  mfc1      $a2, $f0
/* 91BBA8 802402C8 0C01242D */  jal       func_800490B4
/* 91BBAC 802402CC 0200282D */   daddu    $a1, $s0, $zero
/* 91BBB0 802402D0 10400021 */  beqz      $v0, .L80240358
/* 91BBB4 802402D4 0000202D */   daddu    $a0, $zero, $zero
/* 91BBB8 802402D8 0220282D */  daddu     $a1, $s1, $zero
/* 91BBBC 802402DC 0000302D */  daddu     $a2, $zero, $zero
/* 91BBC0 802402E0 8E0200CC */  lw        $v0, 0xcc($s0)
/* 91BBC4 802402E4 3C013F80 */  lui       $at, 0x3f80
/* 91BBC8 802402E8 44810000 */  mtc1      $at, $f0
/* 91BBCC 802402EC 3C014000 */  lui       $at, 0x4000
/* 91BBD0 802402F0 44811000 */  mtc1      $at, $f2
/* 91BBD4 802402F4 8C430024 */  lw        $v1, 0x24($v0)
/* 91BBD8 802402F8 862200A8 */  lh        $v0, 0xa8($s1)
/* 91BBDC 802402FC 3C01C1A0 */  lui       $at, 0xc1a0
/* 91BBE0 80240300 44812000 */  mtc1      $at, $f4
/* 91BBE4 80240304 44823000 */  mtc1      $v0, $f6
/* 91BBE8 80240308 00000000 */  nop
/* 91BBEC 8024030C 468031A0 */  cvt.s.w   $f6, $f6
/* 91BBF0 80240310 44073000 */  mfc1      $a3, $f6
/* 91BBF4 80240314 2402000F */  addiu     $v0, $zero, 0xf
/* 91BBF8 80240318 AE230028 */  sw        $v1, 0x28($s1)
/* 91BBFC 8024031C AFA2001C */  sw        $v0, 0x1c($sp)
/* 91BC00 80240320 27A20028 */  addiu     $v0, $sp, 0x28
/* 91BC04 80240324 E7A00010 */  swc1      $f0, 0x10($sp)
/* 91BC08 80240328 E7A20014 */  swc1      $f2, 0x14($sp)
/* 91BC0C 8024032C E7A40018 */  swc1      $f4, 0x18($sp)
/* 91BC10 80240330 0C01BFA4 */  jal       fx_emote
/* 91BC14 80240334 AFA20020 */   sw       $v0, 0x20($sp)
/* 91BC18 80240338 0220202D */  daddu     $a0, $s1, $zero
/* 91BC1C 8024033C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 91BC20 80240340 0C012530 */  jal       ai_enemy_play_sound
/* 91BC24 80240344 3C060020 */   lui      $a2, 0x20
/* 91BC28 80240348 2402000C */  addiu     $v0, $zero, 0xc
/* 91BC2C 8024034C A622008E */  sh        $v0, 0x8e($s1)
/* 91BC30 80240350 24020002 */  addiu     $v0, $zero, 2
/* 91BC34 80240354 AE620070 */  sw        $v0, 0x70($s3)
.L80240358:
/* 91BC38 80240358 8E620074 */  lw        $v0, 0x74($s3)
/* 91BC3C 8024035C 2442FFFF */  addiu     $v0, $v0, -1
/* 91BC40 80240360 AE620074 */  sw        $v0, 0x74($s3)
/* 91BC44 80240364 8FBF0044 */  lw        $ra, 0x44($sp)
/* 91BC48 80240368 8FB40040 */  lw        $s4, 0x40($sp)
/* 91BC4C 8024036C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 91BC50 80240370 8FB20038 */  lw        $s2, 0x38($sp)
/* 91BC54 80240374 8FB10034 */  lw        $s1, 0x34($sp)
/* 91BC58 80240378 8FB00030 */  lw        $s0, 0x30($sp)
/* 91BC5C 8024037C 03E00008 */  jr        $ra
/* 91BC60 80240380 27BD0048 */   addiu    $sp, $sp, 0x48
