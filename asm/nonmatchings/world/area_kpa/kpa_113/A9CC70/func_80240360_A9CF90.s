.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240360_A9CF90
/* A9CF90 80240360 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A9CF94 80240364 AFB3003C */  sw        $s3, 0x3c($sp)
/* A9CF98 80240368 0080982D */  daddu     $s3, $a0, $zero
/* A9CF9C 8024036C AFBF0040 */  sw        $ra, 0x40($sp)
/* A9CFA0 80240370 AFB20038 */  sw        $s2, 0x38($sp)
/* A9CFA4 80240374 AFB10034 */  sw        $s1, 0x34($sp)
/* A9CFA8 80240378 AFB00030 */  sw        $s0, 0x30($sp)
/* A9CFAC 8024037C 8E710148 */  lw        $s1, 0x148($s3)
/* A9CFB0 80240380 0C00EABB */  jal       get_npc_unsafe
/* A9CFB4 80240384 86240008 */   lh       $a0, 8($s1)
/* A9CFB8 80240388 0040802D */  daddu     $s0, $v0, $zero
/* A9CFBC 8024038C 8E22007C */  lw        $v0, 0x7c($s1)
/* A9CFC0 80240390 8603008E */  lh        $v1, 0x8e($s0)
/* A9CFC4 80240394 2442FFFF */  addiu     $v0, $v0, -1
/* A9CFC8 80240398 14620012 */  bne       $v1, $v0, .L802403E4
/* A9CFCC 8024039C 00000000 */   nop      
/* A9CFD0 802403A0 C6000038 */  lwc1      $f0, 0x38($s0)
/* A9CFD4 802403A4 4600020D */  trunc.w.s $f8, $f0
/* A9CFD8 802403A8 44024000 */  mfc1      $v0, $f8
/* A9CFDC 802403AC 00000000 */  nop       
/* A9CFE0 802403B0 A6220010 */  sh        $v0, 0x10($s1)
/* A9CFE4 802403B4 C600003C */  lwc1      $f0, 0x3c($s0)
/* A9CFE8 802403B8 4600020D */  trunc.w.s $f8, $f0
/* A9CFEC 802403BC 44024000 */  mfc1      $v0, $f8
/* A9CFF0 802403C0 00000000 */  nop       
/* A9CFF4 802403C4 A6220012 */  sh        $v0, 0x12($s1)
/* A9CFF8 802403C8 C6000040 */  lwc1      $f0, 0x40($s0)
/* A9CFFC 802403CC 24020001 */  addiu     $v0, $zero, 1
/* A9D000 802403D0 A2220007 */  sb        $v0, 7($s1)
/* A9D004 802403D4 4600020D */  trunc.w.s $f8, $f0
/* A9D008 802403D8 44024000 */  mfc1      $v0, $f8
/* A9D00C 802403DC 00000000 */  nop       
/* A9D010 802403E0 A6220014 */  sh        $v0, 0x14($s1)
.L802403E4:
/* A9D014 802403E4 C6000038 */  lwc1      $f0, 0x38($s0)
/* A9D018 802403E8 C602003C */  lwc1      $f2, 0x3c($s0)
/* A9D01C 802403EC C6040040 */  lwc1      $f4, 0x40($s0)
/* A9D020 802403F0 C6060018 */  lwc1      $f6, 0x18($s0)
/* A9D024 802403F4 E7A00020 */  swc1      $f0, 0x20($sp)
/* A9D028 802403F8 E7A20024 */  swc1      $f2, 0x24($sp)
/* A9D02C 802403FC E7A40028 */  swc1      $f4, 0x28($sp)
/* A9D030 80240400 E7A60010 */  swc1      $f6, 0x10($sp)
/* A9D034 80240404 C600000C */  lwc1      $f0, 0xc($s0)
/* A9D038 80240408 E7A00014 */  swc1      $f0, 0x14($sp)
/* A9D03C 8024040C 860200A8 */  lh        $v0, 0xa8($s0)
/* A9D040 80240410 27A50020 */  addiu     $a1, $sp, 0x20
/* A9D044 80240414 44820000 */  mtc1      $v0, $f0
/* A9D048 80240418 00000000 */  nop       
/* A9D04C 8024041C 46800020 */  cvt.s.w   $f0, $f0
/* A9D050 80240420 E7A00018 */  swc1      $f0, 0x18($sp)
/* A9D054 80240424 860200A6 */  lh        $v0, 0xa6($s0)
/* A9D058 80240428 27A60024 */  addiu     $a2, $sp, 0x24
/* A9D05C 8024042C 44820000 */  mtc1      $v0, $f0
/* A9D060 80240430 00000000 */  nop       
/* A9D064 80240434 46800020 */  cvt.s.w   $f0, $f0
/* A9D068 80240438 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A9D06C 8024043C 8E040080 */  lw        $a0, 0x80($s0)
/* A9D070 80240440 0C037711 */  jal       func_800DDC44
/* A9D074 80240444 27A70028 */   addiu    $a3, $sp, 0x28
/* A9D078 80240448 0040902D */  daddu     $s2, $v0, $zero
/* A9D07C 8024044C 16400005 */  bnez      $s2, .L80240464
/* A9D080 80240450 00000000 */   nop      
/* A9D084 80240454 8E050018 */  lw        $a1, 0x18($s0)
/* A9D088 80240458 8E06000C */  lw        $a2, 0xc($s0)
/* A9D08C 8024045C 0C00EA95 */  jal       npc_move_heading
/* A9D090 80240460 0200202D */   daddu    $a0, $s0, $zero
.L80240464:
/* A9D094 80240464 8602008E */  lh        $v0, 0x8e($s0)
/* A9D098 80240468 9603008E */  lhu       $v1, 0x8e($s0)
/* A9D09C 8024046C 18400007 */  blez      $v0, .L8024048C
/* A9D0A0 80240470 2462FFFF */   addiu    $v0, $v1, -1
/* A9D0A4 80240474 A602008E */  sh        $v0, 0x8e($s0)
/* A9D0A8 80240478 00021400 */  sll       $v0, $v0, 0x10
/* A9D0AC 8024047C 18400003 */  blez      $v0, .L8024048C
/* A9D0B0 80240480 00000000 */   nop      
/* A9D0B4 80240484 12400008 */  beqz      $s2, .L802404A8
/* A9D0B8 80240488 00000000 */   nop      
.L8024048C:
/* A9D0BC 8024048C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A9D0C0 80240490 A2200007 */  sb        $zero, 7($s1)
/* A9D0C4 80240494 8C420028 */  lw        $v0, 0x28($v0)
/* A9D0C8 80240498 A600008E */  sh        $zero, 0x8e($s0)
/* A9D0CC 8024049C AE020028 */  sw        $v0, 0x28($s0)
/* A9D0D0 802404A0 2402000F */  addiu     $v0, $zero, 0xf
/* A9D0D4 802404A4 AE620070 */  sw        $v0, 0x70($s3)
.L802404A8:
/* A9D0D8 802404A8 8FBF0040 */  lw        $ra, 0x40($sp)
/* A9D0DC 802404AC 8FB3003C */  lw        $s3, 0x3c($sp)
/* A9D0E0 802404B0 8FB20038 */  lw        $s2, 0x38($sp)
/* A9D0E4 802404B4 8FB10034 */  lw        $s1, 0x34($sp)
/* A9D0E8 802404B8 8FB00030 */  lw        $s0, 0x30($sp)
/* A9D0EC 802404BC 03E00008 */  jr        $ra
/* A9D0F0 802404C0 27BD0048 */   addiu    $sp, $sp, 0x48
