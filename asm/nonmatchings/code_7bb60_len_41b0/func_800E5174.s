.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E5174
/* 7E624 800E5174 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7E628 800E5178 2404FFFF */  addiu     $a0, $zero, -1
/* 7E62C 800E517C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 7E630 800E5180 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 7E634 800E5184 AFBF0038 */  sw        $ra, 0x38($sp)
/* 7E638 800E5188 AFB30034 */  sw        $s3, 0x34($sp)
/* 7E63C 800E518C AFB20030 */  sw        $s2, 0x30($sp)
/* 7E640 800E5190 AFB1002C */  sw        $s1, 0x2c($sp)
/* 7E644 800E5194 AFB00028 */  sw        $s0, 0x28($sp)
/* 7E648 800E5198 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 7E64C 800E519C 8C620000 */  lw        $v0, ($v1)
/* 7E650 800E51A0 30422000 */  andi      $v0, $v0, 0x2000
/* 7E654 800E51A4 1440004B */  bnez      $v0, .L800E52D4
/* 7E658 800E51A8 0060802D */   daddu    $s0, $v1, $zero
/* 7E65C 800E51AC 8E0200E0 */  lw        $v0, 0xe0($s0)
/* 7E660 800E51B0 30428000 */  andi      $v0, $v0, 0x8000
/* 7E664 800E51B4 10400047 */  beqz      $v0, .L800E52D4
/* 7E668 800E51B8 27B20018 */   addiu    $s2, $sp, 0x18
/* 7E66C 800E51BC 0200202D */  daddu     $a0, $s0, $zero
/* 7E670 800E51C0 0240282D */  daddu     $a1, $s2, $zero
/* 7E674 800E51C4 27B1001C */  addiu     $s1, $sp, 0x1c
/* 7E678 800E51C8 0220302D */  daddu     $a2, $s1, $zero
/* 7E67C 800E51CC 27B30020 */  addiu     $s3, $sp, 0x20
/* 7E680 800E51D0 0260382D */  daddu     $a3, $s3, $zero
/* 7E684 800E51D4 860200B2 */  lh        $v0, 0xb2($s0)
/* 7E688 800E51D8 C6080080 */  lwc1      $f8, 0x80($s0)
/* 7E68C 800E51DC C6040028 */  lwc1      $f4, 0x28($s0)
/* 7E690 800E51E0 C606002C */  lwc1      $f6, 0x2c($s0)
/* 7E694 800E51E4 3C013F00 */  lui       $at, 0x3f00
/* 7E698 800E51E8 4481A000 */  mtc1      $at, $f20
/* 7E69C 800E51EC C6020030 */  lwc1      $f2, 0x30($s0)
/* 7E6A0 800E51F0 44820000 */  mtc1      $v0, $f0
/* 7E6A4 800E51F4 00000000 */  nop
/* 7E6A8 800E51F8 46800020 */  cvt.s.w   $f0, $f0
/* 7E6AC 800E51FC 46140002 */  mul.s     $f0, $f0, $f20
/* 7E6B0 800E5200 00000000 */  nop
/* 7E6B4 800E5204 E7A40018 */  swc1      $f4, 0x18($sp)
/* 7E6B8 800E5208 E7A6001C */  swc1      $f6, 0x1c($sp)
/* 7E6BC 800E520C E7A20020 */  swc1      $f2, 0x20($sp)
/* 7E6C0 800E5210 E7A80014 */  swc1      $f8, 0x14($sp)
/* 7E6C4 800E5214 0C037D18 */  jal       test_player_lateral
/* 7E6C8 800E5218 E7A00010 */   swc1     $f0, 0x10($sp)
/* 7E6CC 800E521C 0040202D */  daddu     $a0, $v0, $zero
/* 7E6D0 800E5220 0481002D */  bgez      $a0, .L800E52D8
/* 7E6D4 800E5224 0080102D */   daddu    $v0, $a0, $zero
/* 7E6D8 800E5228 C6020054 */  lwc1      $f2, 0x54($s0)
/* 7E6DC 800E522C 44800000 */  mtc1      $zero, $f0
/* 7E6E0 800E5230 00000000 */  nop
/* 7E6E4 800E5234 46001032 */  c.eq.s    $f2, $f0
/* 7E6E8 800E5238 00000000 */  nop
/* 7E6EC 800E523C 45000026 */  bc1f      .L800E52D8
/* 7E6F0 800E5240 0240282D */   daddu    $a1, $s2, $zero
/* 7E6F4 800E5244 0200202D */  daddu     $a0, $s0, $zero
/* 7E6F8 800E5248 0220302D */  daddu     $a2, $s1, $zero
/* 7E6FC 800E524C 0260382D */  daddu     $a3, $s3, $zero
/* 7E700 800E5250 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7E704 800E5254 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7E708 800E5258 C4800028 */  lwc1      $f0, 0x28($a0)
/* 7E70C 800E525C C482002C */  lwc1      $f2, 0x2c($a0)
/* 7E710 800E5260 00031080 */  sll       $v0, $v1, 2
/* 7E714 800E5264 00431021 */  addu      $v0, $v0, $v1
/* 7E718 800E5268 00021080 */  sll       $v0, $v0, 2
/* 7E71C 800E526C 00431023 */  subu      $v0, $v0, $v1
/* 7E720 800E5270 E7A00018 */  swc1      $f0, 0x18($sp)
/* 7E724 800E5274 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 7E728 800E5278 848300B2 */  lh        $v1, 0xb2($a0)
/* 7E72C 800E527C 000240C0 */  sll       $t0, $v0, 3
/* 7E730 800E5280 44833000 */  mtc1      $v1, $f6
/* 7E734 800E5284 00000000 */  nop
/* 7E738 800E5288 468031A0 */  cvt.s.w   $f6, $f6
/* 7E73C 800E528C 46143182 */  mul.s     $f6, $f6, $f20
/* 7E740 800E5290 00000000 */  nop
/* 7E744 800E5294 00481021 */  addu      $v0, $v0, $t0
/* 7E748 800E5298 C48000A8 */  lwc1      $f0, 0xa8($a0)
/* 7E74C 800E529C 3C0142B4 */  lui       $at, 0x42b4
/* 7E750 800E52A0 44811000 */  mtc1      $at, $f2
/* 7E754 800E52A4 000210C0 */  sll       $v0, $v0, 3
/* 7E758 800E52A8 46020001 */  sub.s     $f0, $f0, $f2
/* 7E75C 800E52AC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 7E760 800E52B0 00220821 */  addu      $at, $at, $v0
/* 7E764 800E52B4 C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 7E768 800E52B8 C4840030 */  lwc1      $f4, 0x30($a0)
/* 7E76C 800E52BC 46020200 */  add.s     $f8, $f0, $f2
/* 7E770 800E52C0 E7A40020 */  swc1      $f4, 0x20($sp)
/* 7E774 800E52C4 E7A60010 */  swc1      $f6, 0x10($sp)
/* 7E778 800E52C8 0C037D18 */  jal       test_player_lateral
/* 7E77C 800E52CC E7A80014 */   swc1     $f8, 0x14($sp)
/* 7E780 800E52D0 0040202D */  daddu     $a0, $v0, $zero
.L800E52D4:
/* 7E784 800E52D4 0080102D */  daddu     $v0, $a0, $zero
.L800E52D8:
/* 7E788 800E52D8 8FBF0038 */  lw        $ra, 0x38($sp)
/* 7E78C 800E52DC 8FB30034 */  lw        $s3, 0x34($sp)
/* 7E790 800E52E0 8FB20030 */  lw        $s2, 0x30($sp)
/* 7E794 800E52E4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 7E798 800E52E8 8FB00028 */  lw        $s0, 0x28($sp)
/* 7E79C 800E52EC D7B40040 */  ldc1      $f20, 0x40($sp)
/* 7E7A0 800E52F0 03E00008 */  jr        $ra
/* 7E7A4 800E52F4 27BD0048 */   addiu    $sp, $sp, 0x48
