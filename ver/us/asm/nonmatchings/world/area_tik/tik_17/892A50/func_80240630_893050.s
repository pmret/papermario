.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240630_893050
/* 893050 80240630 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 893054 80240634 AFB60040 */  sw        $s6, 0x40($sp)
/* 893058 80240638 0080B02D */  daddu     $s6, $a0, $zero
/* 89305C 8024063C AFB00028 */  sw        $s0, 0x28($sp)
/* 893060 80240640 00A0802D */  daddu     $s0, $a1, $zero
/* 893064 80240644 AFBF0044 */  sw        $ra, 0x44($sp)
/* 893068 80240648 AFB5003C */  sw        $s5, 0x3c($sp)
/* 89306C 8024064C AFB40038 */  sw        $s4, 0x38($sp)
/* 893070 80240650 AFB30034 */  sw        $s3, 0x34($sp)
/* 893074 80240654 AFB20030 */  sw        $s2, 0x30($sp)
/* 893078 80240658 AFB1002C */  sw        $s1, 0x2c($sp)
/* 89307C 8024065C F7B80058 */  sdc1      $f24, 0x58($sp)
/* 893080 80240660 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 893084 80240664 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 893088 80240668 8ED3000C */  lw        $s3, 0xc($s6)
/* 89308C 8024066C 0C00EAD2 */  jal       get_npc_safe
/* 893090 80240670 2404FFFC */   addiu    $a0, $zero, -4
/* 893094 80240674 27A50018 */  addiu     $a1, $sp, 0x18
/* 893098 80240678 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 89309C 8024067C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 8930A0 80240680 27A6001C */  addiu     $a2, $sp, 0x1c
/* 8930A4 80240684 00041880 */  sll       $v1, $a0, 2
/* 8930A8 80240688 00641821 */  addu      $v1, $v1, $a0
/* 8930AC 8024068C 00031880 */  sll       $v1, $v1, 2
/* 8930B0 80240690 00641823 */  subu      $v1, $v1, $a0
/* 8930B4 80240694 000320C0 */  sll       $a0, $v1, 3
/* 8930B8 80240698 00641821 */  addu      $v1, $v1, $a0
/* 8930BC 8024069C 000318C0 */  sll       $v1, $v1, 3
/* 8930C0 802406A0 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 8930C4 802406A4 00230821 */  addu      $at, $at, $v1
/* 8930C8 802406A8 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* 8930CC 802406AC 0C00A88D */  jal       sin_cos_deg
/* 8930D0 802406B0 0040A82D */   daddu    $s5, $v0, $zero
/* 8930D4 802406B4 1200005D */  beqz      $s0, .L8024082C
/* 8930D8 802406B8 00000000 */   nop
/* 8930DC 802406BC 0C00AB0A */  jal       general_heap_malloc
/* 8930E0 802406C0 24040068 */   addiu    $a0, $zero, 0x68
/* 8930E4 802406C4 0040902D */  daddu     $s2, $v0, $zero
/* 8930E8 802406C8 02C0202D */  daddu     $a0, $s6, $zero
/* 8930EC 802406CC 0000882D */  daddu     $s1, $zero, $zero
/* 8930F0 802406D0 2414FFFF */  addiu     $s4, $zero, -1
/* 8930F4 802406D4 AED20060 */  sw        $s2, 0x60($s6)
/* 8930F8 802406D8 8E650000 */  lw        $a1, ($s3)
/* 8930FC 802406DC 3C014148 */  lui       $at, 0x4148
/* 893100 802406E0 4481C000 */  mtc1      $at, $f24
/* 893104 802406E4 3C013F80 */  lui       $at, 0x3f80
/* 893108 802406E8 4481B000 */  mtc1      $at, $f22
/* 89310C 802406EC 4480A000 */  mtc1      $zero, $f20
/* 893110 802406F0 0C0B1EAF */  jal       evt_get_variable
/* 893114 802406F4 0240802D */   daddu    $s0, $s2, $zero
/* 893118 802406F8 0C04417A */  jal       get_entity_by_index
/* 89311C 802406FC 0040202D */   daddu    $a0, $v0, $zero
/* 893120 80240700 AE42005C */  sw        $v0, 0x5c($s2)
.L80240704:
/* 893124 80240704 8E42005C */  lw        $v0, 0x5c($s2)
/* 893128 80240708 C440004C */  lwc1      $f0, 0x4c($v0)
/* 89312C 8024070C 0000202D */  daddu     $a0, $zero, $zero
/* 893130 80240710 E7B60010 */  swc1      $f22, 0x10($sp)
/* 893134 80240714 AFB40014 */  sw        $s4, 0x14($sp)
/* 893138 80240718 46180000 */  add.s     $f0, $f0, $f24
/* 89313C 8024071C 8C450048 */  lw        $a1, 0x48($v0)
/* 893140 80240720 8C470050 */  lw        $a3, 0x50($v0)
/* 893144 80240724 44060000 */  mfc1      $a2, $f0
/* 893148 80240728 0C01C5BC */  jal       fx_motion_blur_flame
/* 89314C 8024072C 26310001 */   addiu    $s1, $s1, 1
/* 893150 80240730 AE020008 */  sw        $v0, 8($s0)
/* 893154 80240734 E614002C */  swc1      $f20, 0x2c($s0)
/* 893158 80240738 E6140020 */  swc1      $f20, 0x20($s0)
/* 89315C 8024073C E6140014 */  swc1      $f20, 0x14($s0)
/* 893160 80240740 E6140050 */  swc1      $f20, 0x50($s0)
/* 893164 80240744 E6140044 */  swc1      $f20, 0x44($s0)
/* 893168 80240748 E6140038 */  swc1      $f20, 0x38($s0)
/* 89316C 8024074C 2A220003 */  slti      $v0, $s1, 3
/* 893170 80240750 1440FFEC */  bnez      $v0, .L80240704
/* 893174 80240754 26100004 */   addiu    $s0, $s0, 4
/* 893178 80240758 0000882D */  daddu     $s1, $zero, $zero
/* 89317C 8024075C 0240802D */  daddu     $s0, $s2, $zero
/* 893180 80240760 3C148024 */  lui       $s4, %hi(D_80241478_893E98)
/* 893184 80240764 26941478 */  addiu     $s4, $s4, %lo(D_80241478_893E98)
/* 893188 80240768 3C014248 */  lui       $at, 0x4248
/* 89318C 8024076C 4481A000 */  mtc1      $at, $f20
/* 893190 80240770 24130044 */  addiu     $s3, $zero, 0x44
/* 893194 80240774 AE400000 */  sw        $zero, ($s2)
/* 893198 80240778 AE400004 */  sw        $zero, 4($s2)
/* 89319C 8024077C AE400060 */  sw        $zero, 0x60($s2)
/* 8931A0 80240780 AE400064 */  sw        $zero, 0x64($s2)
.L80240784:
/* 8931A4 80240784 27A40020 */  addiu     $a0, $sp, 0x20
/* 8931A8 80240788 4406A000 */  mfc1      $a2, $f20
/* 8931AC 8024078C 8E870000 */  lw        $a3, ($s4)
/* 8931B0 80240790 02532821 */  addu      $a1, $s2, $s3
/* 8931B4 80240794 0C00A7E7 */  jal       add_vec2D_polar
/* 8931B8 80240798 AFA00020 */   sw       $zero, 0x20($sp)
/* 8931BC 8024079C C7A2001C */  lwc1      $f2, 0x1c($sp)
/* 8931C0 802407A0 C7A40020 */  lwc1      $f4, 0x20($sp)
/* 8931C4 802407A4 46041082 */  mul.s     $f2, $f2, $f4
/* 8931C8 802407A8 00000000 */  nop
/* 8931CC 802407AC C7A00018 */  lwc1      $f0, 0x18($sp)
/* 8931D0 802407B0 46040002 */  mul.s     $f0, $f0, $f4
/* 8931D4 802407B4 00000000 */  nop
/* 8931D8 802407B8 E6020038 */  swc1      $f2, 0x38($s0)
/* 8931DC 802407BC E6000050 */  swc1      $f0, 0x50($s0)
/* 8931E0 802407C0 8E42005C */  lw        $v0, 0x5c($s2)
/* 8931E4 802407C4 C6000038 */  lwc1      $f0, 0x38($s0)
/* 8931E8 802407C8 C4420048 */  lwc1      $f2, 0x48($v0)
/* 8931EC 802407CC 46001080 */  add.s     $f2, $f2, $f0
/* 8931F0 802407D0 C6A00038 */  lwc1      $f0, 0x38($s5)
/* 8931F4 802407D4 46020001 */  sub.s     $f0, $f0, $f2
/* 8931F8 802407D8 E6000038 */  swc1      $f0, 0x38($s0)
/* 8931FC 802407DC 8E42005C */  lw        $v0, 0x5c($s2)
/* 893200 802407E0 C6000044 */  lwc1      $f0, 0x44($s0)
/* 893204 802407E4 C442004C */  lwc1      $f2, 0x4c($v0)
/* 893208 802407E8 46001080 */  add.s     $f2, $f2, $f0
/* 89320C 802407EC C6A0003C */  lwc1      $f0, 0x3c($s5)
/* 893210 802407F0 46020001 */  sub.s     $f0, $f0, $f2
/* 893214 802407F4 E6000044 */  swc1      $f0, 0x44($s0)
/* 893218 802407F8 8E42005C */  lw        $v0, 0x5c($s2)
/* 89321C 802407FC C6000050 */  lwc1      $f0, 0x50($s0)
/* 893220 80240800 C4420050 */  lwc1      $f2, 0x50($v0)
/* 893224 80240804 26940004 */  addiu     $s4, $s4, 4
/* 893228 80240808 46001080 */  add.s     $f2, $f2, $f0
/* 89322C 8024080C C6A00040 */  lwc1      $f0, 0x40($s5)
/* 893230 80240810 26730004 */  addiu     $s3, $s3, 4
/* 893234 80240814 46020001 */  sub.s     $f0, $f0, $f2
/* 893238 80240818 26310001 */  addiu     $s1, $s1, 1
/* 89323C 8024081C 2A220003 */  slti      $v0, $s1, 3
/* 893240 80240820 E6000050 */  swc1      $f0, 0x50($s0)
/* 893244 80240824 1440FFD7 */  bnez      $v0, .L80240784
/* 893248 80240828 26100004 */   addiu    $s0, $s0, 4
.L8024082C:
/* 89324C 8024082C 8ED20060 */  lw        $s2, 0x60($s6)
/* 893250 80240830 8E430000 */  lw        $v1, ($s2)
/* 893254 80240834 24020001 */  addiu     $v0, $zero, 1
/* 893258 80240838 10620038 */  beq       $v1, $v0, .L8024091C
/* 89325C 8024083C 28620002 */   slti     $v0, $v1, 2
/* 893260 80240840 50400005 */  beql      $v0, $zero, .L80240858
/* 893264 80240844 24020002 */   addiu    $v0, $zero, 2
/* 893268 80240848 10600007 */  beqz      $v1, .L80240868
/* 89326C 8024084C 24040005 */   addiu    $a0, $zero, 5
/* 893270 80240850 08090280 */  j         .L80240A00
/* 893274 80240854 00000000 */   nop
.L80240858:
/* 893278 80240858 10620058 */  beq       $v1, $v0, .L802409BC
/* 89327C 8024085C 00000000 */   nop
/* 893280 80240860 08090280 */  j         .L80240A00
/* 893284 80240864 00000000 */   nop
.L80240868:
/* 893288 80240868 0000882D */  daddu     $s1, $zero, $zero
/* 89328C 8024086C 3C148024 */  lui       $s4, %hi(D_80241478_893E98)
/* 893290 80240870 26941478 */  addiu     $s4, $s4, %lo(D_80241478_893E98)
/* 893294 80240874 24130020 */  addiu     $s3, $zero, 0x20
/* 893298 80240878 3C064248 */  lui       $a2, 0x4248
/* 89329C 8024087C 44800000 */  mtc1      $zero, $f0
/* 8932A0 80240880 24020014 */  addiu     $v0, $zero, 0x14
/* 8932A4 80240884 AFA20010 */  sw        $v0, 0x10($sp)
/* 8932A8 80240888 44050000 */  mfc1      $a1, $f0
/* 8932AC 8024088C 8E470060 */  lw        $a3, 0x60($s2)
/* 8932B0 80240890 4485B000 */  mtc1      $a1, $f22
/* 8932B4 80240894 0C00A8ED */  jal       update_lerp
/* 8932B8 80240898 0240802D */   daddu    $s0, $s2, $zero
/* 8932BC 8024089C 46000506 */  mov.s     $f20, $f0
.L802408A0:
/* 8932C0 802408A0 4406A000 */  mfc1      $a2, $f20
/* 8932C4 802408A4 27A40020 */  addiu     $a0, $sp, 0x20
/* 8932C8 802408A8 E6160020 */  swc1      $f22, 0x20($s0)
/* 8932CC 802408AC 8E870000 */  lw        $a3, ($s4)
/* 8932D0 802408B0 02532821 */  addu      $a1, $s2, $s3
/* 8932D4 802408B4 0C00A7E7 */  jal       add_vec2D_polar
/* 8932D8 802408B8 E7B60020 */   swc1     $f22, 0x20($sp)
/* 8932DC 802408BC C7A4001C */  lwc1      $f4, 0x1c($sp)
/* 8932E0 802408C0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 8932E4 802408C4 46002102 */  mul.s     $f4, $f4, $f0
/* 8932E8 802408C8 00000000 */  nop
/* 8932EC 802408CC C7A20018 */  lwc1      $f2, 0x18($sp)
/* 8932F0 802408D0 26940004 */  addiu     $s4, $s4, 4
/* 8932F4 802408D4 46001082 */  mul.s     $f2, $f2, $f0
/* 8932F8 802408D8 00000000 */  nop
/* 8932FC 802408DC 26730004 */  addiu     $s3, $s3, 4
/* 893300 802408E0 26310001 */  addiu     $s1, $s1, 1
/* 893304 802408E4 2A220003 */  slti      $v0, $s1, 3
/* 893308 802408E8 E6040014 */  swc1      $f4, 0x14($s0)
/* 89330C 802408EC E602002C */  swc1      $f2, 0x2c($s0)
/* 893310 802408F0 1440FFEB */  bnez      $v0, .L802408A0
/* 893314 802408F4 26100004 */   addiu    $s0, $s0, 4
/* 893318 802408F8 8E420060 */  lw        $v0, 0x60($s2)
/* 89331C 802408FC 24420001 */  addiu     $v0, $v0, 1
/* 893320 80240900 AE420060 */  sw        $v0, 0x60($s2)
/* 893324 80240904 28420015 */  slti      $v0, $v0, 0x15
/* 893328 80240908 1440003D */  bnez      $v0, .L80240A00
/* 89332C 8024090C 24020001 */   addiu    $v0, $zero, 1
/* 893330 80240910 AE420000 */  sw        $v0, ($s2)
/* 893334 80240914 08090280 */  j         .L80240A00
/* 893338 80240918 AE400060 */   sw       $zero, 0x60($s2)
.L8024091C:
/* 89333C 8024091C 0000882D */  daddu     $s1, $zero, $zero
/* 893340 80240920 3C148024 */  lui       $s4, %hi(D_80241478_893E98)
/* 893344 80240924 26941478 */  addiu     $s4, $s4, %lo(D_80241478_893E98)
/* 893348 80240928 24130020 */  addiu     $s3, $zero, 0x20
/* 89334C 8024092C 0240802D */  daddu     $s0, $s2, $zero
/* 893350 80240930 3C014248 */  lui       $at, 0x4248
/* 893354 80240934 4481A000 */  mtc1      $at, $f20
/* 893358 80240938 4480B000 */  mtc1      $zero, $f22
.L8024093C:
/* 89335C 8024093C 4406A000 */  mfc1      $a2, $f20
/* 893360 80240940 27A40020 */  addiu     $a0, $sp, 0x20
/* 893364 80240944 E6160020 */  swc1      $f22, 0x20($s0)
/* 893368 80240948 8E870000 */  lw        $a3, ($s4)
/* 89336C 8024094C 02532821 */  addu      $a1, $s2, $s3
/* 893370 80240950 0C00A7E7 */  jal       add_vec2D_polar
/* 893374 80240954 E7B60020 */   swc1     $f22, 0x20($sp)
/* 893378 80240958 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* 89337C 8024095C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 893380 80240960 46002102 */  mul.s     $f4, $f4, $f0
/* 893384 80240964 00000000 */  nop
/* 893388 80240968 C7A20018 */  lwc1      $f2, 0x18($sp)
/* 89338C 8024096C 26940004 */  addiu     $s4, $s4, 4
/* 893390 80240970 46001082 */  mul.s     $f2, $f2, $f0
/* 893394 80240974 00000000 */  nop
/* 893398 80240978 26730004 */  addiu     $s3, $s3, 4
/* 89339C 8024097C 26310001 */  addiu     $s1, $s1, 1
/* 8933A0 80240980 2A220003 */  slti      $v0, $s1, 3
/* 8933A4 80240984 E6040014 */  swc1      $f4, 0x14($s0)
/* 8933A8 80240988 E602002C */  swc1      $f2, 0x2c($s0)
/* 8933AC 8024098C 1440FFEB */  bnez      $v0, .L8024093C
/* 8933B0 80240990 26100004 */   addiu    $s0, $s0, 4
/* 8933B4 80240994 8E420060 */  lw        $v0, 0x60($s2)
/* 8933B8 80240998 24420001 */  addiu     $v0, $v0, 1
/* 8933BC 8024099C AE420060 */  sw        $v0, 0x60($s2)
/* 8933C0 802409A0 28420010 */  slti      $v0, $v0, 0x10
/* 8933C4 802409A4 14400016 */  bnez      $v0, .L80240A00
/* 8933C8 802409A8 2402000F */   addiu    $v0, $zero, 0xf
/* 8933CC 802409AC AE420060 */  sw        $v0, 0x60($s2)
/* 8933D0 802409B0 24020002 */  addiu     $v0, $zero, 2
/* 8933D4 802409B4 08090280 */  j         .L80240A00
/* 8933D8 802409B8 AE420000 */   sw       $v0, ($s2)
.L802409BC:
/* 8933DC 802409BC 8E420060 */  lw        $v0, 0x60($s2)
/* 8933E0 802409C0 24420001 */  addiu     $v0, $v0, 1
/* 8933E4 802409C4 AE420060 */  sw        $v0, 0x60($s2)
/* 8933E8 802409C8 2842001F */  slti      $v0, $v0, 0x1f
/* 8933EC 802409CC 1440000C */  bnez      $v0, .L80240A00
/* 8933F0 802409D0 0000882D */   daddu    $s1, $zero, $zero
/* 8933F4 802409D4 0240282D */  daddu     $a1, $s2, $zero
.L802409D8:
/* 8933F8 802409D8 8CA20008 */  lw        $v0, 8($a1)
/* 8933FC 802409DC 8C430000 */  lw        $v1, ($v0)
/* 893400 802409E0 26310001 */  addiu     $s1, $s1, 1
/* 893404 802409E4 34630010 */  ori       $v1, $v1, 0x10
/* 893408 802409E8 AC430000 */  sw        $v1, ($v0)
/* 89340C 802409EC 2A220003 */  slti      $v0, $s1, 3
/* 893410 802409F0 1440FFF9 */  bnez      $v0, .L802409D8
/* 893414 802409F4 24A50004 */   addiu    $a1, $a1, 4
/* 893418 802409F8 080902CD */  j         .L80240B34
/* 89341C 802409FC 24020002 */   addiu    $v0, $zero, 2
.L80240A00:
/* 893420 80240A00 8E430004 */  lw        $v1, 4($s2)
/* 893424 80240A04 10600005 */  beqz      $v1, .L80240A1C
/* 893428 80240A08 24020001 */   addiu    $v0, $zero, 1
/* 89342C 80240A0C 1062000B */  beq       $v1, $v0, .L80240A3C
/* 893430 80240A10 0000882D */   daddu    $s1, $zero, $zero
/* 893434 80240A14 080902BC */  j         .L80240AF0
/* 893438 80240A18 0240282D */   daddu    $a1, $s2, $zero
.L80240A1C:
/* 89343C 80240A1C 8E420064 */  lw        $v0, 0x64($s2)
/* 893440 80240A20 24420001 */  addiu     $v0, $v0, 1
/* 893444 80240A24 AE420064 */  sw        $v0, 0x64($s2)
/* 893448 80240A28 28420010 */  slti      $v0, $v0, 0x10
/* 89344C 80240A2C 1440002F */  bnez      $v0, .L80240AEC
/* 893450 80240A30 0000882D */   daddu    $s1, $zero, $zero
/* 893454 80240A34 080902B8 */  j         .L80240AE0
/* 893458 80240A38 24020001 */   addiu    $v0, $zero, 1
.L80240A3C:
/* 89345C 80240A3C 4480A000 */  mtc1      $zero, $f20
/* 893460 80240A40 24130014 */  addiu     $s3, $zero, 0x14
/* 893464 80240A44 0240802D */  daddu     $s0, $s2, $zero
.L80240A48:
/* 893468 80240A48 4405A000 */  mfc1      $a1, $f20
/* 89346C 80240A4C AFB30010 */  sw        $s3, 0x10($sp)
/* 893470 80240A50 8E060038 */  lw        $a2, 0x38($s0)
/* 893474 80240A54 8E470064 */  lw        $a3, 0x64($s2)
/* 893478 80240A58 0C00A8ED */  jal       update_lerp
/* 89347C 80240A5C 24040001 */   addiu    $a0, $zero, 1
/* 893480 80240A60 C6020014 */  lwc1      $f2, 0x14($s0)
/* 893484 80240A64 46001080 */  add.s     $f2, $f2, $f0
/* 893488 80240A68 4405A000 */  mfc1      $a1, $f20
/* 89348C 80240A6C E6020014 */  swc1      $f2, 0x14($s0)
/* 893490 80240A70 AFB30010 */  sw        $s3, 0x10($sp)
/* 893494 80240A74 8E060044 */  lw        $a2, 0x44($s0)
/* 893498 80240A78 8E470064 */  lw        $a3, 0x64($s2)
/* 89349C 80240A7C 0C00A8ED */  jal       update_lerp
/* 8934A0 80240A80 24040001 */   addiu    $a0, $zero, 1
/* 8934A4 80240A84 C6020020 */  lwc1      $f2, 0x20($s0)
/* 8934A8 80240A88 46001080 */  add.s     $f2, $f2, $f0
/* 8934AC 80240A8C 4405A000 */  mfc1      $a1, $f20
/* 8934B0 80240A90 E6020020 */  swc1      $f2, 0x20($s0)
/* 8934B4 80240A94 AFB30010 */  sw        $s3, 0x10($sp)
/* 8934B8 80240A98 8E060050 */  lw        $a2, 0x50($s0)
/* 8934BC 80240A9C 8E470064 */  lw        $a3, 0x64($s2)
/* 8934C0 80240AA0 0C00A8ED */  jal       update_lerp
/* 8934C4 80240AA4 24040001 */   addiu    $a0, $zero, 1
/* 8934C8 80240AA8 C602002C */  lwc1      $f2, 0x2c($s0)
/* 8934CC 80240AAC 46001080 */  add.s     $f2, $f2, $f0
/* 8934D0 80240AB0 26310001 */  addiu     $s1, $s1, 1
/* 8934D4 80240AB4 2A220003 */  slti      $v0, $s1, 3
/* 8934D8 80240AB8 E602002C */  swc1      $f2, 0x2c($s0)
/* 8934DC 80240ABC 1440FFE2 */  bnez      $v0, .L80240A48
/* 8934E0 80240AC0 26100004 */   addiu    $s0, $s0, 4
/* 8934E4 80240AC4 8E420064 */  lw        $v0, 0x64($s2)
/* 8934E8 80240AC8 24420001 */  addiu     $v0, $v0, 1
/* 8934EC 80240ACC AE420064 */  sw        $v0, 0x64($s2)
/* 8934F0 80240AD0 28420015 */  slti      $v0, $v0, 0x15
/* 8934F4 80240AD4 14400005 */  bnez      $v0, .L80240AEC
/* 8934F8 80240AD8 0000882D */   daddu    $s1, $zero, $zero
/* 8934FC 80240ADC 24020002 */  addiu     $v0, $zero, 2
.L80240AE0:
/* 893500 80240AE0 AE420004 */  sw        $v0, 4($s2)
/* 893504 80240AE4 AE400064 */  sw        $zero, 0x64($s2)
/* 893508 80240AE8 0000882D */  daddu     $s1, $zero, $zero
.L80240AEC:
/* 89350C 80240AEC 0240282D */  daddu     $a1, $s2, $zero
.L80240AF0:
/* 893510 80240AF0 8CA20008 */  lw        $v0, 8($a1)
/* 893514 80240AF4 C4A00014 */  lwc1      $f0, 0x14($a1)
/* 893518 80240AF8 8C42000C */  lw        $v0, 0xc($v0)
/* 89351C 80240AFC E4400010 */  swc1      $f0, 0x10($v0)
/* 893520 80240B00 8CA20008 */  lw        $v0, 8($a1)
/* 893524 80240B04 C4A00020 */  lwc1      $f0, 0x20($a1)
/* 893528 80240B08 8C42000C */  lw        $v0, 0xc($v0)
/* 89352C 80240B0C 26310001 */  addiu     $s1, $s1, 1
/* 893530 80240B10 E4400014 */  swc1      $f0, 0x14($v0)
/* 893534 80240B14 8CA20008 */  lw        $v0, 8($a1)
/* 893538 80240B18 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* 89353C 80240B1C 8C42000C */  lw        $v0, 0xc($v0)
/* 893540 80240B20 E4400018 */  swc1      $f0, 0x18($v0)
/* 893544 80240B24 2A220003 */  slti      $v0, $s1, 3
/* 893548 80240B28 1440FFF1 */  bnez      $v0, .L80240AF0
/* 89354C 80240B2C 24A50004 */   addiu    $a1, $a1, 4
/* 893550 80240B30 0000102D */  daddu     $v0, $zero, $zero
.L80240B34:
/* 893554 80240B34 8FBF0044 */  lw        $ra, 0x44($sp)
/* 893558 80240B38 8FB60040 */  lw        $s6, 0x40($sp)
/* 89355C 80240B3C 8FB5003C */  lw        $s5, 0x3c($sp)
/* 893560 80240B40 8FB40038 */  lw        $s4, 0x38($sp)
/* 893564 80240B44 8FB30034 */  lw        $s3, 0x34($sp)
/* 893568 80240B48 8FB20030 */  lw        $s2, 0x30($sp)
/* 89356C 80240B4C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 893570 80240B50 8FB00028 */  lw        $s0, 0x28($sp)
/* 893574 80240B54 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 893578 80240B58 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 89357C 80240B5C D7B40048 */  ldc1      $f20, 0x48($sp)
/* 893580 80240B60 03E00008 */  jr        $ra
/* 893584 80240B64 27BD0060 */   addiu    $sp, $sp, 0x60
