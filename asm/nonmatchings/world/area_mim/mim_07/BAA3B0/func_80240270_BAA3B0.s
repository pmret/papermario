.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240270_BAA3B0
/* BAA3B0 80240270 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BAA3B4 80240274 AFB00030 */  sw        $s0, 0x30($sp)
/* BAA3B8 80240278 0080802D */  daddu     $s0, $a0, $zero
/* BAA3BC 8024027C AFBF0040 */  sw        $ra, 0x40($sp)
/* BAA3C0 80240280 AFB3003C */  sw        $s3, 0x3c($sp)
/* BAA3C4 80240284 AFB20038 */  sw        $s2, 0x38($sp)
/* BAA3C8 80240288 AFB10034 */  sw        $s1, 0x34($sp)
/* BAA3CC 8024028C F7B60050 */  sdc1      $f22, 0x50($sp)
/* BAA3D0 80240290 F7B40048 */  sdc1      $f20, 0x48($sp)
/* BAA3D4 80240294 8E130148 */  lw        $s3, 0x148($s0)
/* BAA3D8 80240298 00A0882D */  daddu     $s1, $a1, $zero
/* BAA3DC 8024029C 86640008 */  lh        $a0, 8($s3)
/* BAA3E0 802402A0 0C00EABB */  jal       get_npc_unsafe
/* BAA3E4 802402A4 00C0902D */   daddu    $s2, $a2, $zero
/* BAA3E8 802402A8 0200202D */  daddu     $a0, $s0, $zero
/* BAA3EC 802402AC 0220282D */  daddu     $a1, $s1, $zero
/* BAA3F0 802402B0 0240302D */  daddu     $a2, $s2, $zero
/* BAA3F4 802402B4 0C012568 */  jal       func_800495A0
/* BAA3F8 802402B8 0040802D */   daddu    $s0, $v0, $zero
/* BAA3FC 802402BC 8E020000 */  lw        $v0, ($s0)
/* BAA400 802402C0 2404002D */  addiu     $a0, $zero, 0x2d
/* BAA404 802402C4 34420800 */  ori       $v0, $v0, 0x800
/* BAA408 802402C8 0C00A67F */  jal       rand_int
/* BAA40C 802402CC AE020000 */   sw       $v0, ($s0)
/* BAA410 802402D0 0200202D */  daddu     $a0, $s0, $zero
/* BAA414 802402D4 3C05B000 */  lui       $a1, 0xb000
/* BAA418 802402D8 34A50017 */  ori       $a1, $a1, 0x17
/* BAA41C 802402DC 44820000 */  mtc1      $v0, $f0
/* BAA420 802402E0 00000000 */  nop       
/* BAA424 802402E4 46800021 */  cvt.d.w   $f0, $f0
/* BAA428 802402E8 3C014024 */  lui       $at, 0x4024
/* BAA42C 802402EC 44811800 */  mtc1      $at, $f3
/* BAA430 802402F0 44801000 */  mtc1      $zero, $f2
/* BAA434 802402F4 3C014020 */  lui       $at, 0x4020
/* BAA438 802402F8 44812800 */  mtc1      $at, $f5
/* BAA43C 802402FC 44802000 */  mtc1      $zero, $f4
/* BAA440 80240300 46220003 */  div.d     $f0, $f0, $f2
/* BAA444 80240304 46240000 */  add.d     $f0, $f0, $f4
/* BAA448 80240308 3C013FC0 */  lui       $at, 0x3fc0
/* BAA44C 8024030C 44811000 */  mtc1      $at, $f2
/* BAA450 80240310 0000302D */  daddu     $a2, $zero, $zero
/* BAA454 80240314 E6020014 */  swc1      $f2, 0x14($s0)
/* BAA458 80240318 46200020 */  cvt.s.d   $f0, $f0
/* BAA45C 8024031C 0C012530 */  jal       func_800494C0
/* BAA460 80240320 E600001C */   swc1     $f0, 0x1c($s0)
/* BAA464 80240324 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BAA468 80240328 C6000040 */  lwc1      $f0, 0x40($s0)
/* BAA46C 8024032C C4620000 */  lwc1      $f2, ($v1)
/* BAA470 80240330 468010A0 */  cvt.s.w   $f2, $f2
/* BAA474 80240334 C4640008 */  lwc1      $f4, 8($v1)
/* BAA478 80240338 46802120 */  cvt.s.w   $f4, $f4
/* BAA47C 8024033C E7A00010 */  swc1      $f0, 0x10($sp)
/* BAA480 80240340 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BAA484 80240344 44051000 */  mfc1      $a1, $f2
/* BAA488 80240348 C440000C */  lwc1      $f0, 0xc($v0)
/* BAA48C 8024034C 46800020 */  cvt.s.w   $f0, $f0
/* BAA490 80240350 E7A00014 */  swc1      $f0, 0x14($sp)
/* BAA494 80240354 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BAA498 80240358 44062000 */  mfc1      $a2, $f4
/* BAA49C 8024035C C4400010 */  lwc1      $f0, 0x10($v0)
/* BAA4A0 80240360 46800020 */  cvt.s.w   $f0, $f0
/* BAA4A4 80240364 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAA4A8 80240368 8C640018 */  lw        $a0, 0x18($v1)
/* BAA4AC 8024036C 0C0123F5 */  jal       is_point_within_region
/* BAA4B0 80240370 8E070038 */   lw       $a3, 0x38($s0)
/* BAA4B4 80240374 10400035 */  beqz      $v0, .L8024044C
/* BAA4B8 80240378 00000000 */   nop      
/* BAA4BC 8024037C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAA4C0 80240380 3C0141C8 */  lui       $at, 0x41c8
/* BAA4C4 80240384 4481B000 */  mtc1      $at, $f22
/* BAA4C8 80240388 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BAA4CC 8024038C C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAA4D0 80240390 C4480000 */  lwc1      $f8, ($v0)
/* BAA4D4 80240394 46804220 */  cvt.s.w   $f8, $f8
/* BAA4D8 80240398 44064000 */  mfc1      $a2, $f8
/* BAA4DC 8024039C C4480008 */  lwc1      $f8, 8($v0)
/* BAA4E0 802403A0 46804220 */  cvt.s.w   $f8, $f8
/* BAA4E4 802403A4 44074000 */  mfc1      $a3, $f8
/* BAA4E8 802403A8 3C01403E */  lui       $at, 0x403e
/* BAA4EC 802403AC 4481A800 */  mtc1      $at, $f21
/* BAA4F0 802403B0 4480A000 */  mtc1      $zero, $f20
/* BAA4F4 802403B4 0C00A720 */  jal       atan2
/* BAA4F8 802403B8 0000882D */   daddu    $s1, $zero, $zero
/* BAA4FC 802403BC C6020038 */  lwc1      $f2, 0x38($s0)
/* BAA500 802403C0 C604003C */  lwc1      $f4, 0x3c($s0)
/* BAA504 802403C4 C6060040 */  lwc1      $f6, 0x40($s0)
/* BAA508 802403C8 E600000C */  swc1      $f0, 0xc($s0)
/* BAA50C 802403CC E7A20020 */  swc1      $f2, 0x20($sp)
/* BAA510 802403D0 E7A40024 */  swc1      $f4, 0x24($sp)
/* BAA514 802403D4 E7A60028 */  swc1      $f6, 0x28($sp)
.L802403D8:
/* BAA518 802403D8 E7B60010 */  swc1      $f22, 0x10($sp)
/* BAA51C 802403DC C600000C */  lwc1      $f0, 0xc($s0)
/* BAA520 802403E0 E7A00014 */  swc1      $f0, 0x14($sp)
/* BAA524 802403E4 860200A8 */  lh        $v0, 0xa8($s0)
/* BAA528 802403E8 27A50020 */  addiu     $a1, $sp, 0x20
/* BAA52C 802403EC 44820000 */  mtc1      $v0, $f0
/* BAA530 802403F0 00000000 */  nop       
/* BAA534 802403F4 46800020 */  cvt.s.w   $f0, $f0
/* BAA538 802403F8 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAA53C 802403FC 860200A6 */  lh        $v0, 0xa6($s0)
/* BAA540 80240400 27A60024 */  addiu     $a2, $sp, 0x24
/* BAA544 80240404 44820000 */  mtc1      $v0, $f0
/* BAA548 80240408 00000000 */  nop       
/* BAA54C 8024040C 46800020 */  cvt.s.w   $f0, $f0
/* BAA550 80240410 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BAA554 80240414 8E040080 */  lw        $a0, 0x80($s0)
/* BAA558 80240418 0C037711 */  jal       func_800DDC44
/* BAA55C 8024041C 27A70028 */   addiu    $a3, $sp, 0x28
/* BAA560 80240420 10400016 */  beqz      $v0, .L8024047C
/* BAA564 80240424 26310001 */   addiu    $s1, $s1, 1
/* BAA568 80240428 C600000C */  lwc1      $f0, 0xc($s0)
/* BAA56C 8024042C 46000021 */  cvt.d.s   $f0, $f0
/* BAA570 80240430 46340000 */  add.d     $f0, $f0, $f20
/* BAA574 80240434 2A220006 */  slti      $v0, $s1, 6
/* BAA578 80240438 46200020 */  cvt.s.d   $f0, $f0
/* BAA57C 8024043C 1440FFE6 */  bnez      $v0, .L802403D8
/* BAA580 80240440 E600000C */   swc1     $f0, 0xc($s0)
/* BAA584 80240444 0809011F */  j         .L8024047C
/* BAA588 80240448 00000000 */   nop      
.L8024044C:
/* BAA58C 8024044C 0C00A67F */  jal       rand_int
/* BAA590 80240450 2404003C */   addiu    $a0, $zero, 0x3c
/* BAA594 80240454 C60C000C */  lwc1      $f12, 0xc($s0)
/* BAA598 80240458 44820000 */  mtc1      $v0, $f0
/* BAA59C 8024045C 00000000 */  nop       
/* BAA5A0 80240460 46800020 */  cvt.s.w   $f0, $f0
/* BAA5A4 80240464 46006300 */  add.s     $f12, $f12, $f0
/* BAA5A8 80240468 3C0141F0 */  lui       $at, 0x41f0
/* BAA5AC 8024046C 44810000 */  mtc1      $at, $f0
/* BAA5B0 80240470 0C00A6C9 */  jal       clamp_angle
/* BAA5B4 80240474 46006301 */   sub.s    $f12, $f12, $f0
/* BAA5B8 80240478 E600000C */  swc1      $f0, 0xc($s0)
.L8024047C:
/* BAA5BC 8024047C 8FBF0040 */  lw        $ra, 0x40($sp)
/* BAA5C0 80240480 8FB3003C */  lw        $s3, 0x3c($sp)
/* BAA5C4 80240484 8FB20038 */  lw        $s2, 0x38($sp)
/* BAA5C8 80240488 8FB10034 */  lw        $s1, 0x34($sp)
/* BAA5CC 8024048C 8FB00030 */  lw        $s0, 0x30($sp)
/* BAA5D0 80240490 D7B60050 */  ldc1      $f22, 0x50($sp)
/* BAA5D4 80240494 D7B40048 */  ldc1      $f20, 0x48($sp)
/* BAA5D8 80240498 03E00008 */  jr        $ra
/* BAA5DC 8024049C 27BD0058 */   addiu    $sp, $sp, 0x58
