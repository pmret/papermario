.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80248AA4
/* 177384 80248AA4 3C02802A */  lui       $v0, 0x802a
/* 177388 80248AA8 8C42F254 */  lw        $v0, -0xdac($v0)
/* 17738C 80248AAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 177390 80248AB0 10400012 */  beqz      $v0, .L80248AFC
/* 177394 80248AB4 AFBF0010 */   sw       $ra, 0x10($sp)
/* 177398 80248AB8 3C038028 */  lui       $v1, 0x8028
/* 17739C 80248ABC 24630A30 */  addiu     $v1, $v1, 0xa30
/* 1773A0 80248AC0 8C620000 */  lw        $v0, ($v1)
/* 1773A4 80248AC4 14400004 */  bnez      $v0, .L80248AD8
/* 1773A8 80248AC8 2442FFEC */   addiu    $v0, $v0, -0x14
/* 1773AC 80248ACC 3C05BF80 */  lui       $a1, 0xbf80
/* 1773B0 80248AD0 080922BD */  j         .L80248AF4
/* 1773B4 80248AD4 240400FF */   addiu    $a0, $zero, 0xff
.L80248AD8:
/* 1773B8 80248AD8 04410002 */  bgez      $v0, .L80248AE4
/* 1773BC 80248ADC AC620000 */   sw       $v0, ($v1)
/* 1773C0 80248AE0 AC600000 */  sw        $zero, ($v1)
.L80248AE4:
/* 1773C4 80248AE4 C4600000 */  lwc1      $f0, ($v1)
/* 1773C8 80248AE8 46800020 */  cvt.s.w   $f0, $f0
/* 1773CC 80248AEC 44050000 */  mfc1      $a1, $f0
/* 1773D0 80248AF0 0000202D */  daddu     $a0, $zero, $zero
.L80248AF4:
/* 1773D4 80248AF4 0C04DF62 */  jal       func_80137D88
/* 1773D8 80248AF8 00000000 */   nop      
.L80248AFC:
/* 1773DC 80248AFC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1773E0 80248B00 03E00008 */  jr        $ra
/* 1773E4 80248B04 27BD0018 */   addiu    $sp, $sp, 0x18
