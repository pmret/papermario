.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_C6CC30
/* C6CC30 80240310 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C6CC34 80240314 AFB1001C */  sw        $s1, 0x1c($sp)
/* C6CC38 80240318 00A0882D */  daddu     $s1, $a1, $zero
/* C6CC3C 8024031C AFBF0020 */  sw        $ra, 0x20($sp)
/* C6CC40 80240320 AFB00018 */  sw        $s0, 0x18($sp)
/* C6CC44 80240324 8E220070 */  lw        $v0, 0x70($s1)
/* C6CC48 80240328 3C0141C8 */  lui       $at, 0x41c8
/* C6CC4C 8024032C 44810000 */  mtc1      $at, $f0
/* C6CC50 80240330 00021080 */  sll       $v0, $v0, 2
/* C6CC54 80240334 3C018024 */  lui       $at, %hi(D_80241120_C6DA40)
/* C6CC58 80240338 00220821 */  addu      $at, $at, $v0
/* C6CC5C 8024033C C4221120 */  lwc1      $f2, %lo(D_80241120_C6DA40)($at)
/* C6CC60 80240340 46001082 */  mul.s     $f2, $f2, $f0
/* C6CC64 80240344 00000000 */  nop
/* C6CC68 80240348 C6200084 */  lwc1      $f0, 0x84($s1)
/* C6CC6C 8024034C 46800020 */  cvt.s.w   $f0, $f0
/* C6CC70 80240350 46020001 */  sub.s     $f0, $f0, $f2
/* C6CC74 80240354 0080802D */  daddu     $s0, $a0, $zero
/* C6CC78 80240358 E600004C */  swc1      $f0, 0x4c($s0)
/* C6CC7C 8024035C 8E220070 */  lw        $v0, 0x70($s1)
/* C6CC80 80240360 14400007 */  bnez      $v0, .L80240380
/* C6CC84 80240364 240401DA */   addiu    $a0, $zero, 0x1da
/* C6CC88 80240368 C6000050 */  lwc1      $f0, 0x50($s0)
/* C6CC8C 8024036C E7A00010 */  swc1      $f0, 0x10($sp)
/* C6CC90 80240370 8E060048 */  lw        $a2, 0x48($s0)
/* C6CC94 80240374 8E07004C */  lw        $a3, 0x4c($s0)
/* C6CC98 80240378 0C052757 */  jal       sfx_play_sound_at_position
/* C6CC9C 8024037C 0000282D */   daddu    $a1, $zero, $zero
.L80240380:
/* C6CCA0 80240380 8E230070 */  lw        $v1, 0x70($s1)
/* C6CCA4 80240384 28620005 */  slti      $v0, $v1, 5
/* C6CCA8 80240388 1440000C */  bnez      $v0, .L802403BC
/* C6CCAC 8024038C 30620001 */   andi     $v0, $v1, 1
/* C6CCB0 80240390 1040000A */  beqz      $v0, .L802403BC
/* C6CCB4 80240394 24020014 */   addiu    $v0, $zero, 0x14
/* C6CCB8 80240398 3C013F80 */  lui       $at, 0x3f80
/* C6CCBC 8024039C 44810000 */  mtc1      $at, $f0
/* C6CCC0 802403A0 AFA20014 */  sw        $v0, 0x14($sp)
/* C6CCC4 802403A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C6CCC8 802403A8 8E050048 */  lw        $a1, 0x48($s0)
/* C6CCCC 802403AC 8E06004C */  lw        $a2, 0x4c($s0)
/* C6CCD0 802403B0 8E070050 */  lw        $a3, 0x50($s0)
/* C6CCD4 802403B4 0C01C1CC */  jal       func_80070730
/* C6CCD8 802403B8 24040001 */   addiu    $a0, $zero, 1
.L802403BC:
/* C6CCDC 802403BC 8E220070 */  lw        $v0, 0x70($s1)
/* C6CCE0 802403C0 24420001 */  addiu     $v0, $v0, 1
/* C6CCE4 802403C4 AE220070 */  sw        $v0, 0x70($s1)
/* C6CCE8 802403C8 3842001C */  xori      $v0, $v0, 0x1c
/* C6CCEC 802403CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* C6CCF0 802403D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* C6CCF4 802403D4 8FB00018 */  lw        $s0, 0x18($sp)
/* C6CCF8 802403D8 2C420001 */  sltiu     $v0, $v0, 1
/* C6CCFC 802403DC 03E00008 */  jr        $ra
/* C6CD00 802403E0 27BD0028 */   addiu    $sp, $sp, 0x28
/* C6CD04 802403E4 00000000 */  nop
/* C6CD08 802403E8 00000000 */  nop
/* C6CD0C 802403EC 00000000 */  nop
