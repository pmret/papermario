.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403EC_EA0CEC
/* EA0CEC 802403EC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* EA0CF0 802403F0 AFB10034 */  sw        $s1, 0x34($sp)
/* EA0CF4 802403F4 0080882D */  daddu     $s1, $a0, $zero
/* EA0CF8 802403F8 AFBF0038 */  sw        $ra, 0x38($sp)
/* EA0CFC 802403FC AFB00030 */  sw        $s0, 0x30($sp)
/* EA0D00 80240400 8E300148 */  lw        $s0, 0x148($s1)
/* EA0D04 80240404 0C00F92F */  jal       func_8003E4BC
/* EA0D08 80240408 86040008 */   lh       $a0, 8($s0)
/* EA0D0C 8024040C 0040282D */  daddu     $a1, $v0, $zero
/* EA0D10 80240410 94A2008E */  lhu       $v0, 0x8e($a1)
/* EA0D14 80240414 2442FFFF */  addiu     $v0, $v0, -1
/* EA0D18 80240418 A4A2008E */  sh        $v0, 0x8e($a1)
/* EA0D1C 8024041C 00021400 */  sll       $v0, $v0, 0x10
/* EA0D20 80240420 1C400023 */  bgtz      $v0, .L802404B0
/* EA0D24 80240424 24020004 */   addiu    $v0, $zero, 4
/* EA0D28 80240428 8E0300CC */  lw        $v1, 0xcc($s0)
/* EA0D2C 8024042C AE02006C */  sw        $v0, 0x6c($s0)
/* EA0D30 80240430 8C620000 */  lw        $v0, ($v1)
/* EA0D34 80240434 ACA20028 */  sw        $v0, 0x28($a1)
/* EA0D38 80240438 9602007A */  lhu       $v0, 0x7a($s0)
/* EA0D3C 8024043C A4A2008E */  sh        $v0, 0x8e($a1)
/* EA0D40 80240440 8E020078 */  lw        $v0, 0x78($s0)
/* EA0D44 80240444 28420008 */  slti      $v0, $v0, 8
/* EA0D48 80240448 14400018 */  bnez      $v0, .L802404AC
/* EA0D4C 8024044C 24020021 */   addiu    $v0, $zero, 0x21
/* EA0D50 80240450 24040003 */  addiu     $a0, $zero, 3
/* EA0D54 80240454 27A30028 */  addiu     $v1, $sp, 0x28
/* EA0D58 80240458 84A700A8 */  lh        $a3, 0xa8($a1)
/* EA0D5C 8024045C 3C013F80 */  lui       $at, 0x3f80
/* EA0D60 80240460 44810000 */  mtc1      $at, $f0
/* EA0D64 80240464 3C014000 */  lui       $at, 0x4000
/* EA0D68 80240468 44811000 */  mtc1      $at, $f2
/* EA0D6C 8024046C 3C01C1A0 */  lui       $at, 0xc1a0
/* EA0D70 80240470 44812000 */  mtc1      $at, $f4
/* EA0D74 80240474 44873000 */  mtc1      $a3, $f6
/* EA0D78 80240478 00000000 */  nop       
/* EA0D7C 8024047C 468031A0 */  cvt.s.w   $f6, $f6
/* EA0D80 80240480 E7A00010 */  swc1      $f0, 0x10($sp)
/* EA0D84 80240484 E7A20014 */  swc1      $f2, 0x14($sp)
/* EA0D88 80240488 E7A40018 */  swc1      $f4, 0x18($sp)
/* EA0D8C 8024048C 8E020078 */  lw        $v0, 0x78($s0)
/* EA0D90 80240490 44073000 */  mfc1      $a3, $f6
/* EA0D94 80240494 0000302D */  daddu     $a2, $zero, $zero
/* EA0D98 80240498 AFA30020 */  sw        $v1, 0x20($sp)
/* EA0D9C 8024049C 2442FFFF */  addiu     $v0, $v0, -1
/* EA0DA0 802404A0 0C01D444 */  jal       func_80075110
/* EA0DA4 802404A4 AFA2001C */   sw       $v0, 0x1c($sp)
/* EA0DA8 802404A8 24020021 */  addiu     $v0, $zero, 0x21
.L802404AC:
/* EA0DAC 802404AC AE220070 */  sw        $v0, 0x70($s1)
.L802404B0:
/* EA0DB0 802404B0 8FBF0038 */  lw        $ra, 0x38($sp)
/* EA0DB4 802404B4 8FB10034 */  lw        $s1, 0x34($sp)
/* EA0DB8 802404B8 8FB00030 */  lw        $s0, 0x30($sp)
/* EA0DBC 802404BC 03E00008 */  jr        $ra
/* EA0DC0 802404C0 27BD0040 */   addiu    $sp, $sp, 0x40
