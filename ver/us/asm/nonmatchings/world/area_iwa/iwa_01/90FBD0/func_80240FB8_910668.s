.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802463A0_915A50
.double 180.0

dlabel D_802463A8_915A58
.double 90.0

dlabel D_802463B0_915A60
.double 1.2

.section .text

glabel func_80240FB8_910668
/* 910668 80240FB8 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 91066C 80240FBC AFB3003C */  sw        $s3, 0x3c($sp)
/* 910670 80240FC0 0080982D */  daddu     $s3, $a0, $zero
/* 910674 80240FC4 AFB40040 */  sw        $s4, 0x40($sp)
/* 910678 80240FC8 0000A02D */  daddu     $s4, $zero, $zero
/* 91067C 80240FCC 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* 910680 80240FD0 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* 910684 80240FD4 3C04800B */  lui       $a0, %hi(gCameras)
/* 910688 80240FD8 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 91068C 80240FDC AFBF0044 */  sw        $ra, 0x44($sp)
/* 910690 80240FE0 AFB20038 */  sw        $s2, 0x38($sp)
/* 910694 80240FE4 AFB10034 */  sw        $s1, 0x34($sp)
/* 910698 80240FE8 AFB00030 */  sw        $s0, 0x30($sp)
/* 91069C 80240FEC F7B80058 */  sdc1      $f24, 0x58($sp)
/* 9106A0 80240FF0 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 9106A4 80240FF4 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 9106A8 80240FF8 8E710148 */  lw        $s1, 0x148($s3)
/* 9106AC 80240FFC 00031080 */  sll       $v0, $v1, 2
/* 9106B0 80241000 00431021 */  addu      $v0, $v0, $v1
/* 9106B4 80241004 00021080 */  sll       $v0, $v0, 2
/* 9106B8 80241008 00431023 */  subu      $v0, $v0, $v1
/* 9106BC 8024100C 000218C0 */  sll       $v1, $v0, 3
/* 9106C0 80241010 00431021 */  addu      $v0, $v0, $v1
/* 9106C4 80241014 000210C0 */  sll       $v0, $v0, 3
/* 9106C8 80241018 10A00002 */  beqz      $a1, .L80241024
/* 9106CC 8024101C 00449021 */   addu     $s2, $v0, $a0
/* 9106D0 80241020 AE600070 */  sw        $zero, 0x70($s3)
.L80241024:
/* 9106D4 80241024 0C00FB5A */  jal       get_enemy_safe
/* 9106D8 80241028 86240008 */   lh       $a0, 8($s1)
/* 9106DC 8024102C 14400006 */  bnez      $v0, .L80241048
/* 9106E0 80241030 24020005 */   addiu    $v0, $zero, 5
/* 9106E4 80241034 0260202D */  daddu     $a0, $s3, $zero
/* 9106E8 80241038 3C05FE36 */  lui       $a1, 0xfe36
/* 9106EC 8024103C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 9106F0 80241040 080904EA */  j         .L802413A8
/* 9106F4 80241044 0000302D */   daddu    $a2, $zero, $zero
.L80241048:
/* 9106F8 80241048 8E23006C */  lw        $v1, 0x6c($s1)
/* 9106FC 8024104C 14620005 */  bne       $v1, $v0, .L80241064
/* 910700 80241050 0260202D */   daddu    $a0, $s3, $zero
/* 910704 80241054 3C05FE36 */  lui       $a1, 0xfe36
/* 910708 80241058 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 91070C 8024105C 080904EA */  j         .L802413A8
/* 910710 80241060 0000302D */   daddu    $a2, $zero, $zero
.L80241064:
/* 910714 80241064 86240008 */  lh        $a0, 8($s1)
/* 910718 80241068 0C00FB5A */  jal       get_enemy_safe
/* 91071C 8024106C 00000000 */   nop
/* 910720 80241070 14400005 */  bnez      $v0, .L80241088
/* 910724 80241074 0260202D */   daddu    $a0, $s3, $zero
/* 910728 80241078 3C05FE36 */  lui       $a1, 0xfe36
/* 91072C 8024107C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 910730 80241080 080904EA */  j         .L802413A8
/* 910734 80241084 0000302D */   daddu    $a2, $zero, $zero
.L80241088:
/* 910738 80241088 86240008 */  lh        $a0, 8($s1)
/* 91073C 8024108C 0C00EABB */  jal       get_npc_unsafe
/* 910740 80241090 00000000 */   nop
/* 910744 80241094 8E630070 */  lw        $v1, 0x70($s3)
/* 910748 80241098 10600006 */  beqz      $v1, .L802410B4
/* 91074C 8024109C 0040802D */   daddu    $s0, $v0, $zero
/* 910750 802410A0 24020001 */  addiu     $v0, $zero, 1
/* 910754 802410A4 1062003F */  beq       $v1, $v0, .L802411A4
/* 910758 802410A8 0000102D */   daddu    $v0, $zero, $zero
/* 91075C 802410AC 080904FA */  j         .L802413E8
/* 910760 802410B0 00000000 */   nop
.L802410B4:
/* 910764 802410B4 AFA00010 */  sw        $zero, 0x10($sp)
/* 910768 802410B8 AFA00014 */  sw        $zero, 0x14($sp)
/* 91076C 802410BC 8E050038 */  lw        $a1, 0x38($s0)
/* 910770 802410C0 8E06003C */  lw        $a2, 0x3c($s0)
/* 910774 802410C4 8E070040 */  lw        $a3, 0x40($s0)
/* 910778 802410C8 0C01BECC */  jal       fx_walk
/* 91077C 802410CC 24040002 */   addiu    $a0, $zero, 2
/* 910780 802410D0 C64C006C */  lwc1      $f12, 0x6c($s2)
/* 910784 802410D4 0C00A6C9 */  jal       clamp_angle
/* 910788 802410D8 00000000 */   nop
/* 91078C 802410DC 3C018024 */  lui       $at, %hi(D_802463A0_915A50)
/* 910790 802410E0 D43863A0 */  ldc1      $f24, %lo(D_802463A0_915A50)($at)
/* 910794 802410E4 46000521 */  cvt.d.s   $f20, $f0
/* 910798 802410E8 4638A300 */  add.d     $f12, $f20, $f24
/* 91079C 802410EC 3C018024 */  lui       $at, %hi(D_802463A8_915A58)
/* 9107A0 802410F0 D43663A8 */  ldc1      $f22, %lo(D_802463A8_915A58)($at)
/* 9107A4 802410F4 0C00A6C9 */  jal       clamp_angle
/* 9107A8 802410F8 46206320 */   cvt.s.d  $f12, $f12
/* 9107AC 802410FC 4636A500 */  add.d     $f20, $f20, $f22
/* 9107B0 80241100 4620A320 */  cvt.s.d   $f12, $f20
/* 9107B4 80241104 0C00A6C9 */  jal       clamp_angle
/* 9107B8 80241108 46000506 */   mov.s    $f20, $f0
/* 9107BC 8024110C 4600A521 */  cvt.d.s   $f20, $f20
/* 9107C0 80241110 4636A500 */  add.d     $f20, $f20, $f22
/* 9107C4 80241114 46000586 */  mov.s     $f22, $f0
/* 9107C8 80241118 0C00A6C9 */  jal       clamp_angle
/* 9107CC 8024111C 4620A320 */   cvt.s.d  $f12, $f20
/* 9107D0 80241120 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9107D4 80241124 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9107D8 80241128 C64C006C */  lwc1      $f12, 0x6c($s2)
/* 9107DC 8024112C C44E0084 */  lwc1      $f14, 0x84($v0)
/* 9107E0 80241130 0C00A70A */  jal       get_clamped_angle_diff
/* 9107E4 80241134 46000506 */   mov.s    $f20, $f0
/* 9107E8 80241138 0C00A6C9 */  jal       clamp_angle
/* 9107EC 8024113C 46000306 */   mov.s    $f12, $f0
/* 9107F0 80241140 46000021 */  cvt.d.s   $f0, $f0
/* 9107F4 80241144 4638003C */  c.lt.d    $f0, $f24
/* 9107F8 80241148 00000000 */  nop
/* 9107FC 8024114C 45020002 */  bc1fl     .L80241158
/* 910800 80241150 E614000C */   swc1     $f20, 0xc($s0)
/* 910804 80241154 E616000C */  swc1      $f22, 0xc($s0)
.L80241158:
/* 910808 80241158 C6000018 */  lwc1      $f0, 0x18($s0)
/* 91080C 8024115C 3C018024 */  lui       $at, %hi(D_802463B0_915A60)
/* 910810 80241160 D42263B0 */  ldc1      $f2, %lo(D_802463B0_915A60)($at)
/* 910814 80241164 46000021 */  cvt.d.s   $f0, $f0
/* 910818 80241168 46220002 */  mul.d     $f0, $f0, $f2
/* 91081C 8024116C 00000000 */  nop
/* 910820 80241170 3C013F66 */  lui       $at, 0x3f66
/* 910824 80241174 34216666 */  ori       $at, $at, 0x6666
/* 910828 80241178 44812000 */  mtc1      $at, $f4
/* 91082C 8024117C 2402001E */  addiu     $v0, $zero, 0x1e
/* 910830 80241180 A602008E */  sh        $v0, 0x8e($s0)
/* 910834 80241184 3C014120 */  lui       $at, 0x4120
/* 910838 80241188 44811000 */  mtc1      $at, $f2
/* 91083C 8024118C 24020001 */  addiu     $v0, $zero, 1
/* 910840 80241190 E6040014 */  swc1      $f4, 0x14($s0)
/* 910844 80241194 E602001C */  swc1      $f2, 0x1c($s0)
/* 910848 80241198 46200020 */  cvt.s.d   $f0, $f0
/* 91084C 8024119C E6000018 */  swc1      $f0, 0x18($s0)
/* 910850 802411A0 AE620070 */  sw        $v0, 0x70($s3)
.L802411A4:
/* 910854 802411A4 C6000038 */  lwc1      $f0, 0x38($s0)
/* 910858 802411A8 C602003C */  lwc1      $f2, 0x3c($s0)
/* 91085C 802411AC C6040040 */  lwc1      $f4, 0x40($s0)
/* 910860 802411B0 C6060018 */  lwc1      $f6, 0x18($s0)
/* 910864 802411B4 0000202D */  daddu     $a0, $zero, $zero
/* 910868 802411B8 E7A00020 */  swc1      $f0, 0x20($sp)
/* 91086C 802411BC E7A20024 */  swc1      $f2, 0x24($sp)
/* 910870 802411C0 E7A40028 */  swc1      $f4, 0x28($sp)
/* 910874 802411C4 E7A60010 */  swc1      $f6, 0x10($sp)
/* 910878 802411C8 C600000C */  lwc1      $f0, 0xc($s0)
/* 91087C 802411CC 27A50020 */  addiu     $a1, $sp, 0x20
/* 910880 802411D0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 910884 802411D4 860200A6 */  lh        $v0, 0xa6($s0)
/* 910888 802411D8 27A60024 */  addiu     $a2, $sp, 0x24
/* 91088C 802411DC 44820000 */  mtc1      $v0, $f0
/* 910890 802411E0 00000000 */  nop
/* 910894 802411E4 46800020 */  cvt.s.w   $f0, $f0
/* 910898 802411E8 E7A00018 */  swc1      $f0, 0x18($sp)
/* 91089C 802411EC 860200A8 */  lh        $v0, 0xa8($s0)
/* 9108A0 802411F0 27A70028 */  addiu     $a3, $sp, 0x28
/* 9108A4 802411F4 44820000 */  mtc1      $v0, $f0
/* 9108A8 802411F8 00000000 */  nop
/* 9108AC 802411FC 46800020 */  cvt.s.w   $f0, $f0
/* 9108B0 80241200 0C037711 */  jal       npc_test_move_simple_with_slipping
/* 9108B4 80241204 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 9108B8 80241208 54400007 */  bnel      $v0, $zero, .L80241228
/* 9108BC 8024120C 24140001 */   addiu    $s4, $zero, 1
/* 9108C0 80241210 8E050018 */  lw        $a1, 0x18($s0)
/* 9108C4 80241214 8E06000C */  lw        $a2, 0xc($s0)
/* 9108C8 80241218 0C00EA95 */  jal       npc_move_heading
/* 9108CC 8024121C 0200202D */   daddu    $a0, $s0, $zero
/* 9108D0 80241220 0809048B */  j         .L8024122C
/* 9108D4 80241224 0000902D */   daddu    $s2, $zero, $zero
.L80241228:
/* 9108D8 80241228 0000902D */  daddu     $s2, $zero, $zero
.L8024122C:
/* 9108DC 8024122C C600001C */  lwc1      $f0, 0x1c($s0)
/* 9108E0 80241230 44801000 */  mtc1      $zero, $f2
/* 9108E4 80241234 44801800 */  mtc1      $zero, $f3
/* 9108E8 80241238 46000021 */  cvt.d.s   $f0, $f0
/* 9108EC 8024123C 4622003C */  c.lt.d    $f0, $f2
/* 9108F0 80241240 00000000 */  nop
/* 9108F4 80241244 45000028 */  bc1f      .L802412E8
/* 9108F8 80241248 27A50020 */   addiu    $a1, $sp, 0x20
/* 9108FC 8024124C 27A60024 */  addiu     $a2, $sp, 0x24
/* 910900 80241250 27A2002C */  addiu     $v0, $sp, 0x2c
/* 910904 80241254 C602003C */  lwc1      $f2, 0x3c($s0)
/* 910908 80241258 C6060038 */  lwc1      $f6, 0x38($s0)
/* 91090C 8024125C 3C01402A */  lui       $at, 0x402a
/* 910910 80241260 4481A800 */  mtc1      $at, $f21
/* 910914 80241264 4480A000 */  mtc1      $zero, $f20
/* 910918 80241268 460010A1 */  cvt.d.s   $f2, $f2
/* 91091C 8024126C 46341080 */  add.d     $f2, $f2, $f20
/* 910920 80241270 C600001C */  lwc1      $f0, 0x1c($s0)
/* 910924 80241274 C6040040 */  lwc1      $f4, 0x40($s0)
/* 910928 80241278 46000005 */  abs.s     $f0, $f0
/* 91092C 8024127C E7A40028 */  swc1      $f4, 0x28($sp)
/* 910930 80241280 3C014030 */  lui       $at, 0x4030
/* 910934 80241284 44812800 */  mtc1      $at, $f5
/* 910938 80241288 44802000 */  mtc1      $zero, $f4
/* 91093C 8024128C 46000021 */  cvt.d.s   $f0, $f0
/* 910940 80241290 E7A60020 */  swc1      $f6, 0x20($sp)
/* 910944 80241294 46240000 */  add.d     $f0, $f0, $f4
/* 910948 80241298 462010A0 */  cvt.s.d   $f2, $f2
/* 91094C 8024129C E7A20024 */  swc1      $f2, 0x24($sp)
/* 910950 802412A0 46200020 */  cvt.s.d   $f0, $f0
/* 910954 802412A4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 910958 802412A8 AFA20010 */  sw        $v0, 0x10($sp)
/* 91095C 802412AC 8E040080 */  lw        $a0, 0x80($s0)
/* 910960 802412B0 0C0372DF */  jal       npc_raycast_down_sides
/* 910964 802412B4 27A70028 */   addiu    $a3, $sp, 0x28
/* 910968 802412B8 1040000B */  beqz      $v0, .L802412E8
/* 91096C 802412BC 00000000 */   nop
/* 910970 802412C0 C600001C */  lwc1      $f0, 0x1c($s0)
/* 910974 802412C4 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 910978 802412C8 46000005 */  abs.s     $f0, $f0
/* 91097C 802412CC 46000021 */  cvt.d.s   $f0, $f0
/* 910980 802412D0 46340000 */  add.d     $f0, $f0, $f20
/* 910984 802412D4 460010A1 */  cvt.d.s   $f2, $f2
/* 910988 802412D8 4620103E */  c.le.d    $f2, $f0
/* 91098C 802412DC 00000000 */  nop
/* 910990 802412E0 45030001 */  bc1tl     .L802412E8
/* 910994 802412E4 24120001 */   addiu    $s2, $zero, 1
.L802412E8:
/* 910998 802412E8 56400008 */  bnel      $s2, $zero, .L8024130C
/* 91099C 802412EC 2414000A */   addiu    $s4, $zero, 0xa
/* 9109A0 802412F0 C604003C */  lwc1      $f4, 0x3c($s0)
/* 9109A4 802412F4 C600001C */  lwc1      $f0, 0x1c($s0)
/* 9109A8 802412F8 46002100 */  add.s     $f4, $f4, $f0
/* 9109AC 802412FC C6020014 */  lwc1      $f2, 0x14($s0)
/* 9109B0 80241300 46020001 */  sub.s     $f0, $f0, $f2
/* 9109B4 80241304 E604003C */  swc1      $f4, 0x3c($s0)
/* 9109B8 80241308 E600001C */  swc1      $f0, 0x1c($s0)
.L8024130C:
/* 9109BC 8024130C 9602008E */  lhu       $v0, 0x8e($s0)
/* 9109C0 80241310 2442FFFF */  addiu     $v0, $v0, -1
/* 9109C4 80241314 A602008E */  sh        $v0, 0x8e($s0)
/* 9109C8 80241318 00021400 */  sll       $v0, $v0, 0x10
/* 9109CC 8024131C 58400001 */  blezl     $v0, .L80241324
/* 9109D0 80241320 2414000B */   addiu    $s4, $zero, 0xb
.L80241324:
/* 9109D4 80241324 12800024 */  beqz      $s4, .L802413B8
/* 9109D8 80241328 00000000 */   nop
/* 9109DC 8024132C AFA00010 */  sw        $zero, 0x10($sp)
/* 9109E0 80241330 AFA00014 */  sw        $zero, 0x14($sp)
/* 9109E4 80241334 8E050038 */  lw        $a1, 0x38($s0)
/* 9109E8 80241338 8E06003C */  lw        $a2, 0x3c($s0)
/* 9109EC 8024133C 8E070040 */  lw        $a3, 0x40($s0)
/* 9109F0 80241340 0C01BECC */  jal       fx_walk
/* 9109F4 80241344 24040002 */   addiu    $a0, $zero, 2
/* 9109F8 80241348 3C01C47A */  lui       $at, 0xc47a
/* 9109FC 8024134C 44810000 */  mtc1      $at, $f0
/* 910A00 80241350 AE20006C */  sw        $zero, 0x6c($s1)
/* 910A04 80241354 8E020000 */  lw        $v0, ($s0)
/* 910A08 80241358 0200202D */  daddu     $a0, $s0, $zero
/* 910A0C 8024135C AE000038 */  sw        $zero, 0x38($s0)
/* 910A10 80241360 AE000040 */  sw        $zero, 0x40($s0)
/* 910A14 80241364 34420002 */  ori       $v0, $v0, 2
/* 910A18 80241368 E600003C */  swc1      $f0, 0x3c($s0)
/* 910A1C 8024136C 0C00EAFF */  jal       disable_npc_shadow
/* 910A20 80241370 AE020000 */   sw       $v0, ($s0)
/* 910A24 80241374 0260202D */  daddu     $a0, $s3, $zero
/* 910A28 80241378 3C05FE36 */  lui       $a1, 0xfe36
/* 910A2C 8024137C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 910A30 80241380 24060001 */  addiu     $a2, $zero, 1
/* 910A34 80241384 8E020000 */  lw        $v0, ($s0)
/* 910A38 80241388 2403F7FF */  addiu     $v1, $zero, -0x801
/* 910A3C 8024138C 00431024 */  and       $v0, $v0, $v1
/* 910A40 80241390 AE020000 */  sw        $v0, ($s0)
/* 910A44 80241394 8E220000 */  lw        $v0, ($s1)
/* 910A48 80241398 3C031F00 */  lui       $v1, 0x1f00
/* 910A4C 8024139C 00431025 */  or        $v0, $v0, $v1
/* 910A50 802413A0 AE220000 */  sw        $v0, ($s1)
/* 910A54 802413A4 AC800070 */  sw        $zero, 0x70($a0)
.L802413A8:
/* 910A58 802413A8 0C0B2026 */  jal       evt_set_variable
/* 910A5C 802413AC 00000000 */   nop
/* 910A60 802413B0 080904FA */  j         .L802413E8
/* 910A64 802413B4 24020002 */   addiu    $v0, $zero, 2
.L802413B8:
/* 910A68 802413B8 8E220070 */  lw        $v0, 0x70($s1)
/* 910A6C 802413BC 30420001 */  andi      $v0, $v0, 1
/* 910A70 802413C0 10400009 */  beqz      $v0, .L802413E8
/* 910A74 802413C4 0000102D */   daddu    $v0, $zero, $zero
/* 910A78 802413C8 C600004C */  lwc1      $f0, 0x4c($s0)
/* 910A7C 802413CC 3C01404E */  lui       $at, 0x404e
/* 910A80 802413D0 44811800 */  mtc1      $at, $f3
/* 910A84 802413D4 44801000 */  mtc1      $zero, $f2
/* 910A88 802413D8 46000021 */  cvt.d.s   $f0, $f0
/* 910A8C 802413DC 46220000 */  add.d     $f0, $f0, $f2
/* 910A90 802413E0 46200020 */  cvt.s.d   $f0, $f0
/* 910A94 802413E4 E600004C */  swc1      $f0, 0x4c($s0)
.L802413E8:
/* 910A98 802413E8 8FBF0044 */  lw        $ra, 0x44($sp)
/* 910A9C 802413EC 8FB40040 */  lw        $s4, 0x40($sp)
/* 910AA0 802413F0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 910AA4 802413F4 8FB20038 */  lw        $s2, 0x38($sp)
/* 910AA8 802413F8 8FB10034 */  lw        $s1, 0x34($sp)
/* 910AAC 802413FC 8FB00030 */  lw        $s0, 0x30($sp)
/* 910AB0 80241400 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 910AB4 80241404 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 910AB8 80241408 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 910ABC 8024140C 03E00008 */  jr        $ra
/* 910AC0 80241410 27BD0060 */   addiu    $sp, $sp, 0x60
