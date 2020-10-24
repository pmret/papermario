.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412CC_832ACC
/* 832ACC 802412CC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 832AD0 802412D0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 832AD4 802412D4 10A00002 */  beqz      $a1, .L802412E0
/* 832AD8 802412D8 2402003C */   addiu    $v0, $zero, 0x3c
/* 832ADC 802412DC AC820070 */  sw        $v0, 0x70($a0)
.L802412E0:
/* 832AE0 802412E0 C4620080 */  lwc1      $f2, 0x80($v1)
/* 832AE4 802412E4 3C0141F0 */  lui       $at, 0x41f0
/* 832AE8 802412E8 44810000 */  mtc1      $at, $f0
/* 832AEC 802412EC 00000000 */  nop       
/* 832AF0 802412F0 46001000 */  add.s     $f0, $f2, $f0
/* 832AF4 802412F4 3C0143B4 */  lui       $at, 0x43b4
/* 832AF8 802412F8 44811000 */  mtc1      $at, $f2
/* 832AFC 802412FC 00000000 */  nop       
/* 832B00 80241300 4600103E */  c.le.s    $f2, $f0
/* 832B04 80241304 00000000 */  nop       
/* 832B08 80241308 45000003 */  bc1f      .L80241318
/* 832B0C 8024130C E4600080 */   swc1     $f0, 0x80($v1)
/* 832B10 80241310 46020001 */  sub.s     $f0, $f0, $f2
/* 832B14 80241314 E4600080 */  swc1      $f0, 0x80($v1)
.L80241318:
/* 832B18 80241318 8C820070 */  lw        $v0, 0x70($a0)
/* 832B1C 8024131C 2442FFFF */  addiu     $v0, $v0, -1
/* 832B20 80241320 AC820070 */  sw        $v0, 0x70($a0)
/* 832B24 80241324 000217C3 */  sra       $v0, $v0, 0x1f
/* 832B28 80241328 03E00008 */  jr        $ra
/* 832B2C 8024132C 30420002 */   andi     $v0, $v0, 2
