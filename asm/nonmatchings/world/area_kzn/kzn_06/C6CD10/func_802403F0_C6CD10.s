.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_C6CD10
/* C6CD10 802403F0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C6CD14 802403F4 AFB1002C */  sw        $s1, 0x2c($sp)
/* C6CD18 802403F8 0080882D */  daddu     $s1, $a0, $zero
/* C6CD1C 802403FC AFB20030 */  sw        $s2, 0x30($sp)
/* C6CD20 80240400 00A0902D */  daddu     $s2, $a1, $zero
/* C6CD24 80240404 AFBF003C */  sw        $ra, 0x3c($sp)
/* C6CD28 80240408 AFB40038 */  sw        $s4, 0x38($sp)
/* C6CD2C 8024040C AFB30034 */  sw        $s3, 0x34($sp)
/* C6CD30 80240410 AFB00028 */  sw        $s0, 0x28($sp)
/* C6CD34 80240414 F7B60048 */  sdc1      $f22, 0x48($sp)
/* C6CD38 80240418 F7B40040 */  sdc1      $f20, 0x40($sp)
/* C6CD3C 8024041C 8E30000C */  lw        $s0, 0xc($s1)
/* C6CD40 80240420 8E050000 */  lw        $a1, ($s0)
/* C6CD44 80240424 0C0B1EAF */  jal       get_variable
/* C6CD48 80240428 26100004 */   addiu    $s0, $s0, 4
/* C6CD4C 8024042C 0220202D */  daddu     $a0, $s1, $zero
/* C6CD50 80240430 8E050000 */  lw        $a1, ($s0)
/* C6CD54 80240434 0C0B1EAF */  jal       get_variable
/* C6CD58 80240438 0040A02D */   daddu    $s4, $v0, $zero
/* C6CD5C 8024043C 12400022 */  beqz      $s2, .L802404C8
/* C6CD60 80240440 0040982D */   daddu    $s3, $v0, $zero
/* C6CD64 80240444 12600013 */  beqz      $s3, .L80240494
/* C6CD68 80240448 26710002 */   addiu    $s1, $s3, 2
/* C6CD6C 8024044C 96620000 */  lhu       $v0, ($s3)
/* C6CD70 80240450 1040001D */  beqz      $v0, .L802404C8
/* C6CD74 80240454 0000802D */   daddu    $s0, $zero, $zero
.L80240458:
/* C6CD78 80240458 96240000 */  lhu       $a0, ($s1)
/* C6CD7C 8024045C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* C6CD80 80240460 26100001 */   addiu    $s0, $s0, 1
/* C6CD84 80240464 0C046B4C */  jal       get_model_from_list_index
/* C6CD88 80240468 0040202D */   daddu    $a0, $v0, $zero
/* C6CD8C 8024046C 0040202D */  daddu     $a0, $v0, $zero
/* C6CD90 80240470 2405FFFF */  addiu     $a1, $zero, -1
/* C6CD94 80240474 0C046F1F */  jal       func_8011BC7C
/* C6CD98 80240478 24060002 */   addiu    $a2, $zero, 2
/* C6CD9C 8024047C 96620000 */  lhu       $v0, ($s3)
/* C6CDA0 80240480 0202102A */  slt       $v0, $s0, $v0
/* C6CDA4 80240484 1440FFF4 */  bnez      $v0, .L80240458
/* C6CDA8 80240488 26310002 */   addiu    $s1, $s1, 2
/* C6CDAC 8024048C 08090132 */  j         .L802404C8
/* C6CDB0 80240490 00000000 */   nop      
.L80240494:
/* C6CDB4 80240494 3C118015 */  lui       $s1, %hi(gCurrentModelListPtr)
/* C6CDB8 80240498 8E3112CC */  lw        $s1, %lo(gCurrentModelListPtr)($s1)
/* C6CDBC 8024049C 0000802D */  daddu     $s0, $zero, $zero
.L802404A0:
/* C6CDC0 802404A0 8E240000 */  lw        $a0, ($s1)
/* C6CDC4 802404A4 50800005 */  beql      $a0, $zero, .L802404BC
/* C6CDC8 802404A8 26100001 */   addiu    $s0, $s0, 1
/* C6CDCC 802404AC 2405FFFF */  addiu     $a1, $zero, -1
/* C6CDD0 802404B0 0C046F1F */  jal       func_8011BC7C
/* C6CDD4 802404B4 24060002 */   addiu    $a2, $zero, 2
/* C6CDD8 802404B8 26100001 */  addiu     $s0, $s0, 1
.L802404BC:
/* C6CDDC 802404BC 2A020100 */  slti      $v0, $s0, 0x100
/* C6CDE0 802404C0 1440FFF7 */  bnez      $v0, .L802404A0
/* C6CDE4 802404C4 26310004 */   addiu    $s1, $s1, 4
.L802404C8:
/* C6CDE8 802404C8 3C028024 */  lui       $v0, %hi(D_80241370)
/* C6CDEC 802404CC 24421370 */  addiu     $v0, $v0, %lo(D_80241370)
/* C6CDF0 802404D0 C4420000 */  lwc1      $f2, ($v0)
/* C6CDF4 802404D4 3C013F80 */  lui       $at, 0x3f80
/* C6CDF8 802404D8 44810000 */  mtc1      $at, $f0
/* C6CDFC 802404DC 00000000 */  nop       
/* C6CE00 802404E0 46001000 */  add.s     $f0, $f2, $f0
/* C6CE04 802404E4 3C0143B4 */  lui       $at, 0x43b4
/* C6CE08 802404E8 44811000 */  mtc1      $at, $f2
/* C6CE0C 802404EC 00000000 */  nop       
/* C6CE10 802404F0 4600103C */  c.lt.s    $f2, $f0
/* C6CE14 802404F4 00000000 */  nop       
/* C6CE18 802404F8 45000003 */  bc1f      .L80240508
/* C6CE1C 802404FC E4400000 */   swc1     $f0, ($v0)
/* C6CE20 80240500 46020001 */  sub.s     $f0, $f0, $f2
/* C6CE24 80240504 E4400000 */  swc1      $f0, ($v0)
.L80240508:
/* C6CE28 80240508 24020002 */  addiu     $v0, $zero, 2
/* C6CE2C 8024050C 12820037 */  beq       $s4, $v0, .L802405EC
/* C6CE30 80240510 2A820003 */   slti     $v0, $s4, 3
/* C6CE34 80240514 10400005 */  beqz      $v0, .L8024052C
/* C6CE38 80240518 24020001 */   addiu    $v0, $zero, 1
/* C6CE3C 8024051C 12820008 */  beq       $s4, $v0, .L80240540
/* C6CE40 80240520 0000202D */   daddu    $a0, $zero, $zero
/* C6CE44 80240524 08090184 */  j         .L80240610
/* C6CE48 80240528 00000000 */   nop      
.L8024052C:
/* C6CE4C 8024052C 2402000A */  addiu     $v0, $zero, 0xa
/* C6CE50 80240530 12820077 */  beq       $s4, $v0, .L80240710
/* C6CE54 80240534 0000102D */   daddu    $v0, $zero, $zero
/* C6CE58 80240538 08090184 */  j         .L80240610
/* C6CE5C 8024053C 00000000 */   nop      
.L80240540:
/* C6CE60 80240540 3C05FD05 */  lui       $a1, 0xfd05
/* C6CE64 80240544 0C0B210B */  jal       get_float_variable
/* C6CE68 80240548 34A50F80 */   ori      $a1, $a1, 0xf80
/* C6CE6C 8024054C 44802000 */  mtc1      $zero, $f4
/* C6CE70 80240550 00000000 */  nop       
/* C6CE74 80240554 4604003E */  c.le.s    $f0, $f4
/* C6CE78 80240558 00000000 */  nop       
/* C6CE7C 8024055C 4501006C */  bc1t      .L80240710
/* C6CE80 80240560 24020002 */   addiu    $v0, $zero, 2
/* C6CE84 80240564 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C6CE88 80240568 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* C6CE8C 8024056C C4420028 */  lwc1      $f2, 0x28($v0)
/* C6CE90 80240570 3C01C296 */  lui       $at, 0xc296
/* C6CE94 80240574 44810000 */  mtc1      $at, $f0
/* C6CE98 80240578 00000000 */  nop       
/* C6CE9C 8024057C 46020081 */  sub.s     $f2, $f0, $f2
/* C6CEA0 80240580 4604103C */  c.lt.s    $f2, $f4
/* C6CEA4 80240584 00000000 */  nop       
/* C6CEA8 80240588 45030001 */  bc1tl     .L80240590
/* C6CEAC 8024058C 46001087 */   neg.s    $f2, $f2
.L80240590:
/* C6CEB0 80240590 3C014400 */  lui       $at, 0x4400
/* C6CEB4 80240594 44810000 */  mtc1      $at, $f0
/* C6CEB8 80240598 00000000 */  nop       
/* C6CEBC 8024059C 46020581 */  sub.s     $f22, $f0, $f2
/* C6CEC0 802405A0 4604B03C */  c.lt.s    $f22, $f4
/* C6CEC4 802405A4 00000000 */  nop       
/* C6CEC8 802405A8 45030001 */  bc1tl     .L802405B0
/* C6CECC 802405AC 46002586 */   mov.s    $f22, $f4
.L802405B0:
/* C6CED0 802405B0 0000202D */  daddu     $a0, $zero, $zero
/* C6CED4 802405B4 3C05FD05 */  lui       $a1, 0xfd05
/* C6CED8 802405B8 0C0B210B */  jal       get_float_variable
/* C6CEDC 802405BC 34A50F80 */   ori      $a1, $a1, 0xf80
/* C6CEE0 802405C0 3C018024 */  lui       $at, %hi(D_80241A00)
/* C6CEE4 802405C4 D4221A00 */  ldc1      $f2, %lo(D_80241A00)($at)
/* C6CEE8 802405C8 46000021 */  cvt.d.s   $f0, $f0
/* C6CEEC 802405CC 46220002 */  mul.d     $f0, $f0, $f2
/* C6CEF0 802405D0 00000000 */  nop       
/* C6CEF4 802405D4 4600B0A1 */  cvt.d.s   $f2, $f22
/* C6CEF8 802405D8 46201082 */  mul.d     $f2, $f2, $f0
/* C6CEFC 802405DC 00000000 */  nop       
/* C6CF00 802405E0 241103CA */  addiu     $s1, $zero, 0x3ca
/* C6CF04 802405E4 08090187 */  j         .L8024061C
/* C6CF08 802405E8 462015A0 */   cvt.s.d  $f22, $f2
.L802405EC:
/* C6CF0C 802405EC 3C0142C8 */  lui       $at, 0x42c8
/* C6CF10 802405F0 4481B000 */  mtc1      $at, $f22
/* C6CF14 802405F4 0000202D */  daddu     $a0, $zero, $zero
/* C6CF18 802405F8 3C05FD05 */  lui       $a1, 0xfd05
/* C6CF1C 802405FC 0C0B1EAF */  jal       get_variable
/* C6CF20 80240600 34A50F80 */   ori      $a1, $a1, 0xf80
/* C6CF24 80240604 240303E3 */  addiu     $v1, $zero, 0x3e3
/* C6CF28 80240608 08090187 */  j         .L8024061C
/* C6CF2C 8024060C 00628823 */   subu     $s1, $v1, $v0
.L80240610:
/* C6CF30 80240610 3C0142C8 */  lui       $at, 0x42c8
/* C6CF34 80240614 4481B000 */  mtc1      $at, $f22
/* C6CF38 80240618 241103CA */  addiu     $s1, $zero, 0x3ca
.L8024061C:
/* C6CF3C 8024061C 3C108024 */  lui       $s0, %hi(D_80241370)
/* C6CF40 80240620 26101370 */  addiu     $s0, $s0, %lo(D_80241370)
/* C6CF44 80240624 C6000000 */  lwc1      $f0, ($s0)
/* C6CF48 80240628 3C014040 */  lui       $at, 0x4040
/* C6CF4C 8024062C 44816000 */  mtc1      $at, $f12
/* C6CF50 80240630 00000000 */  nop       
/* C6CF54 80240634 460C0302 */  mul.s     $f12, $f0, $f12
/* C6CF58 80240638 0C00A8BB */  jal       sin_deg
/* C6CF5C 8024063C 00000000 */   nop      
/* C6CF60 80240640 C6020000 */  lwc1      $f2, ($s0)
/* C6CF64 80240644 3C014100 */  lui       $at, 0x4100
/* C6CF68 80240648 44816000 */  mtc1      $at, $f12
/* C6CF6C 8024064C 00000000 */  nop       
/* C6CF70 80240650 460C1302 */  mul.s     $f12, $f2, $f12
/* C6CF74 80240654 00000000 */  nop       
/* C6CF78 80240658 0C00A8BB */  jal       sin_deg
/* C6CF7C 8024065C 46000506 */   mov.s    $f20, $f0
/* C6CF80 80240660 3C013FE0 */  lui       $at, 0x3fe0
/* C6CF84 80240664 44811800 */  mtc1      $at, $f3
/* C6CF88 80240668 44801000 */  mtc1      $zero, $f2
/* C6CF8C 8024066C 4600A521 */  cvt.d.s   $f20, $f20
/* C6CF90 80240670 4622A502 */  mul.d     $f20, $f20, $f2
/* C6CF94 80240674 00000000 */  nop       
/* C6CF98 80240678 46000021 */  cvt.d.s   $f0, $f0
/* C6CF9C 8024067C 46220002 */  mul.d     $f0, $f0, $f2
/* C6CFA0 80240680 00000000 */  nop       
/* C6CFA4 80240684 4620A500 */  add.d     $f20, $f20, $f0
/* C6CFA8 80240688 4600B021 */  cvt.d.s   $f0, $f22
/* C6CFAC 8024068C 46340502 */  mul.d     $f20, $f0, $f20
/* C6CFB0 80240690 00000000 */  nop       
/* C6CFB4 80240694 46340000 */  add.d     $f0, $f0, $f20
/* C6CFB8 80240698 3C0141E0 */  lui       $at, 0x41e0
/* C6CFBC 8024069C 44811800 */  mtc1      $at, $f3
/* C6CFC0 802406A0 44801000 */  mtc1      $zero, $f2
/* C6CFC4 802406A4 00000000 */  nop       
/* C6CFC8 802406A8 4620103E */  c.le.d    $f2, $f0
/* C6CFCC 802406AC 00000000 */  nop       
/* C6CFD0 802406B0 45030005 */  bc1tl     .L802406C8
/* C6CFD4 802406B4 46220001 */   sub.d    $f0, $f0, $f2
/* C6CFD8 802406B8 4620018D */  trunc.w.d $f6, $f0
/* C6CFDC 802406BC 44073000 */  mfc1      $a3, $f6
/* C6CFE0 802406C0 080901B8 */  j         .L802406E0
/* C6CFE4 802406C4 2404003C */   addiu    $a0, $zero, 0x3c
.L802406C8:
/* C6CFE8 802406C8 3C028000 */  lui       $v0, 0x8000
/* C6CFEC 802406CC 4620018D */  trunc.w.d $f6, $f0
/* C6CFF0 802406D0 44073000 */  mfc1      $a3, $f6
/* C6CFF4 802406D4 00000000 */  nop       
/* C6CFF8 802406D8 00E23825 */  or        $a3, $a3, $v0
/* C6CFFC 802406DC 2404003C */  addiu     $a0, $zero, 0x3c
.L802406E0:
/* C6D000 802406E0 24050032 */  addiu     $a1, $zero, 0x32
/* C6D004 802406E4 2406001E */  addiu     $a2, $zero, 0x1e
/* C6D008 802406E8 24020014 */  addiu     $v0, $zero, 0x14
/* C6D00C 802406EC AFA20010 */  sw        $v0, 0x10($sp)
/* C6D010 802406F0 AFA20014 */  sw        $v0, 0x14($sp)
/* C6D014 802406F4 AFA20018 */  sw        $v0, 0x18($sp)
/* C6D018 802406F8 240203E8 */  addiu     $v0, $zero, 0x3e8
/* C6D01C 802406FC 30E700FF */  andi      $a3, $a3, 0xff
/* C6D020 80240700 AFB1001C */  sw        $s1, 0x1c($sp)
/* C6D024 80240704 0C046FAD */  jal       func_8011BEB4
/* C6D028 80240708 AFA20020 */   sw       $v0, 0x20($sp)
/* C6D02C 8024070C 0000102D */  daddu     $v0, $zero, $zero
.L80240710:
/* C6D030 80240710 8FBF003C */  lw        $ra, 0x3c($sp)
/* C6D034 80240714 8FB40038 */  lw        $s4, 0x38($sp)
/* C6D038 80240718 8FB30034 */  lw        $s3, 0x34($sp)
/* C6D03C 8024071C 8FB20030 */  lw        $s2, 0x30($sp)
/* C6D040 80240720 8FB1002C */  lw        $s1, 0x2c($sp)
/* C6D044 80240724 8FB00028 */  lw        $s0, 0x28($sp)
/* C6D048 80240728 D7B60048 */  ldc1      $f22, 0x48($sp)
/* C6D04C 8024072C D7B40040 */  ldc1      $f20, 0x40($sp)
/* C6D050 80240730 03E00008 */  jr        $ra
/* C6D054 80240734 27BD0050 */   addiu    $sp, $sp, 0x50
