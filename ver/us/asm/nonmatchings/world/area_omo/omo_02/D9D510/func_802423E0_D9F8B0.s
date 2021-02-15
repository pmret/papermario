.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423E0_D9F8B0
/* D9F8B0 802423E0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* D9F8B4 802423E4 AFB3003C */  sw        $s3, 0x3c($sp)
/* D9F8B8 802423E8 0080982D */  daddu     $s3, $a0, $zero
/* D9F8BC 802423EC AFB40040 */  sw        $s4, 0x40($sp)
/* D9F8C0 802423F0 0000A02D */  daddu     $s4, $zero, $zero
/* D9F8C4 802423F4 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D9F8C8 802423F8 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D9F8CC 802423FC 3C04800B */  lui       $a0, %hi(gCameras)
/* D9F8D0 80242400 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* D9F8D4 80242404 AFBF0044 */  sw        $ra, 0x44($sp)
/* D9F8D8 80242408 AFB20038 */  sw        $s2, 0x38($sp)
/* D9F8DC 8024240C AFB10034 */  sw        $s1, 0x34($sp)
/* D9F8E0 80242410 AFB00030 */  sw        $s0, 0x30($sp)
/* D9F8E4 80242414 F7B80058 */  sdc1      $f24, 0x58($sp)
/* D9F8E8 80242418 F7B60050 */  sdc1      $f22, 0x50($sp)
/* D9F8EC 8024241C F7B40048 */  sdc1      $f20, 0x48($sp)
/* D9F8F0 80242420 8E710148 */  lw        $s1, 0x148($s3)
/* D9F8F4 80242424 00031080 */  sll       $v0, $v1, 2
/* D9F8F8 80242428 00431021 */  addu      $v0, $v0, $v1
/* D9F8FC 8024242C 00021080 */  sll       $v0, $v0, 2
/* D9F900 80242430 00431023 */  subu      $v0, $v0, $v1
/* D9F904 80242434 000218C0 */  sll       $v1, $v0, 3
/* D9F908 80242438 00431021 */  addu      $v0, $v0, $v1
/* D9F90C 8024243C 000210C0 */  sll       $v0, $v0, 3
/* D9F910 80242440 10A00002 */  beqz      $a1, .L8024244C
/* D9F914 80242444 00449021 */   addu     $s2, $v0, $a0
/* D9F918 80242448 AE600070 */  sw        $zero, 0x70($s3)
.L8024244C:
/* D9F91C 8024244C 0C00FB5A */  jal       get_enemy_safe
/* D9F920 80242450 86240008 */   lh       $a0, 8($s1)
/* D9F924 80242454 14400006 */  bnez      $v0, .L80242470
/* D9F928 80242458 24020005 */   addiu    $v0, $zero, 5
/* D9F92C 8024245C 0260202D */  daddu     $a0, $s3, $zero
/* D9F930 80242460 3C05FE36 */  lui       $a1, 0xfe36
/* D9F934 80242464 34A53C80 */  ori       $a1, $a1, 0x3c80
/* D9F938 80242468 080909F4 */  j         .L802427D0
/* D9F93C 8024246C 0000302D */   daddu    $a2, $zero, $zero
.L80242470:
/* D9F940 80242470 8E23006C */  lw        $v1, 0x6c($s1)
/* D9F944 80242474 14620005 */  bne       $v1, $v0, .L8024248C
/* D9F948 80242478 0260202D */   daddu    $a0, $s3, $zero
/* D9F94C 8024247C 3C05FE36 */  lui       $a1, 0xfe36
/* D9F950 80242480 34A53C80 */  ori       $a1, $a1, 0x3c80
/* D9F954 80242484 080909F4 */  j         .L802427D0
/* D9F958 80242488 0000302D */   daddu    $a2, $zero, $zero
.L8024248C:
/* D9F95C 8024248C 86240008 */  lh        $a0, 8($s1)
/* D9F960 80242490 0C00FB5A */  jal       get_enemy_safe
/* D9F964 80242494 00000000 */   nop
/* D9F968 80242498 14400005 */  bnez      $v0, .L802424B0
/* D9F96C 8024249C 0260202D */   daddu    $a0, $s3, $zero
/* D9F970 802424A0 3C05FE36 */  lui       $a1, 0xfe36
/* D9F974 802424A4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* D9F978 802424A8 080909F4 */  j         .L802427D0
/* D9F97C 802424AC 0000302D */   daddu    $a2, $zero, $zero
.L802424B0:
/* D9F980 802424B0 86240008 */  lh        $a0, 8($s1)
/* D9F984 802424B4 0C00EABB */  jal       get_npc_unsafe
/* D9F988 802424B8 00000000 */   nop
/* D9F98C 802424BC 8E630070 */  lw        $v1, 0x70($s3)
/* D9F990 802424C0 10600006 */  beqz      $v1, .L802424DC
/* D9F994 802424C4 0040802D */   daddu    $s0, $v0, $zero
/* D9F998 802424C8 24020001 */  addiu     $v0, $zero, 1
/* D9F99C 802424CC 1062003F */  beq       $v1, $v0, .L802425CC
/* D9F9A0 802424D0 0000102D */   daddu    $v0, $zero, $zero
/* D9F9A4 802424D4 08090A04 */  j         .L80242810
/* D9F9A8 802424D8 00000000 */   nop
.L802424DC:
/* D9F9AC 802424DC AFA00010 */  sw        $zero, 0x10($sp)
/* D9F9B0 802424E0 AFA00014 */  sw        $zero, 0x14($sp)
/* D9F9B4 802424E4 8E050038 */  lw        $a1, 0x38($s0)
/* D9F9B8 802424E8 8E06003C */  lw        $a2, 0x3c($s0)
/* D9F9BC 802424EC 8E070040 */  lw        $a3, 0x40($s0)
/* D9F9C0 802424F0 0C01BECC */  jal       fx_walk_normal
/* D9F9C4 802424F4 24040002 */   addiu    $a0, $zero, 2
/* D9F9C8 802424F8 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D9F9CC 802424FC 0C00A6C9 */  jal       clamp_angle
/* D9F9D0 80242500 00000000 */   nop
/* D9F9D4 80242504 3C018024 */  lui       $at, %hi(D_80247BC8_DA5098)
/* D9F9D8 80242508 D4387BC8 */  ldc1      $f24, %lo(D_80247BC8_DA5098)($at)
/* D9F9DC 8024250C 46000521 */  cvt.d.s   $f20, $f0
/* D9F9E0 80242510 4638A300 */  add.d     $f12, $f20, $f24
/* D9F9E4 80242514 3C018024 */  lui       $at, %hi(D_80247BD0_DA50A0)
/* D9F9E8 80242518 D4367BD0 */  ldc1      $f22, %lo(D_80247BD0_DA50A0)($at)
/* D9F9EC 8024251C 0C00A6C9 */  jal       clamp_angle
/* D9F9F0 80242520 46206320 */   cvt.s.d  $f12, $f12
/* D9F9F4 80242524 4636A500 */  add.d     $f20, $f20, $f22
/* D9F9F8 80242528 4620A320 */  cvt.s.d   $f12, $f20
/* D9F9FC 8024252C 0C00A6C9 */  jal       clamp_angle
/* D9FA00 80242530 46000506 */   mov.s    $f20, $f0
/* D9FA04 80242534 4600A521 */  cvt.d.s   $f20, $f20
/* D9FA08 80242538 4636A500 */  add.d     $f20, $f20, $f22
/* D9FA0C 8024253C 46000586 */  mov.s     $f22, $f0
/* D9FA10 80242540 0C00A6C9 */  jal       clamp_angle
/* D9FA14 80242544 4620A320 */   cvt.s.d  $f12, $f20
/* D9FA18 80242548 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D9FA1C 8024254C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D9FA20 80242550 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D9FA24 80242554 C44E0084 */  lwc1      $f14, 0x84($v0)
/* D9FA28 80242558 0C00A70A */  jal       get_clamped_angle_diff
/* D9FA2C 8024255C 46000506 */   mov.s    $f20, $f0
/* D9FA30 80242560 0C00A6C9 */  jal       clamp_angle
/* D9FA34 80242564 46000306 */   mov.s    $f12, $f0
/* D9FA38 80242568 46000021 */  cvt.d.s   $f0, $f0
/* D9FA3C 8024256C 4638003C */  c.lt.d    $f0, $f24
/* D9FA40 80242570 00000000 */  nop
/* D9FA44 80242574 45020002 */  bc1fl     .L80242580
/* D9FA48 80242578 E614000C */   swc1     $f20, 0xc($s0)
/* D9FA4C 8024257C E616000C */  swc1      $f22, 0xc($s0)
.L80242580:
/* D9FA50 80242580 C6000018 */  lwc1      $f0, 0x18($s0)
/* D9FA54 80242584 3C018024 */  lui       $at, %hi(D_80247BD8_DA50A8)
/* D9FA58 80242588 D4227BD8 */  ldc1      $f2, %lo(D_80247BD8_DA50A8)($at)
/* D9FA5C 8024258C 46000021 */  cvt.d.s   $f0, $f0
/* D9FA60 80242590 46220002 */  mul.d     $f0, $f0, $f2
/* D9FA64 80242594 00000000 */  nop
/* D9FA68 80242598 3C013F66 */  lui       $at, 0x3f66
/* D9FA6C 8024259C 34216666 */  ori       $at, $at, 0x6666
/* D9FA70 802425A0 44812000 */  mtc1      $at, $f4
/* D9FA74 802425A4 2402001E */  addiu     $v0, $zero, 0x1e
/* D9FA78 802425A8 A602008E */  sh        $v0, 0x8e($s0)
/* D9FA7C 802425AC 3C014120 */  lui       $at, 0x4120
/* D9FA80 802425B0 44811000 */  mtc1      $at, $f2
/* D9FA84 802425B4 24020001 */  addiu     $v0, $zero, 1
/* D9FA88 802425B8 E6040014 */  swc1      $f4, 0x14($s0)
/* D9FA8C 802425BC E602001C */  swc1      $f2, 0x1c($s0)
/* D9FA90 802425C0 46200020 */  cvt.s.d   $f0, $f0
/* D9FA94 802425C4 E6000018 */  swc1      $f0, 0x18($s0)
/* D9FA98 802425C8 AE620070 */  sw        $v0, 0x70($s3)
.L802425CC:
/* D9FA9C 802425CC C6000038 */  lwc1      $f0, 0x38($s0)
/* D9FAA0 802425D0 C602003C */  lwc1      $f2, 0x3c($s0)
/* D9FAA4 802425D4 C6040040 */  lwc1      $f4, 0x40($s0)
/* D9FAA8 802425D8 C6060018 */  lwc1      $f6, 0x18($s0)
/* D9FAAC 802425DC 0000202D */  daddu     $a0, $zero, $zero
/* D9FAB0 802425E0 E7A00020 */  swc1      $f0, 0x20($sp)
/* D9FAB4 802425E4 E7A20024 */  swc1      $f2, 0x24($sp)
/* D9FAB8 802425E8 E7A40028 */  swc1      $f4, 0x28($sp)
/* D9FABC 802425EC E7A60010 */  swc1      $f6, 0x10($sp)
/* D9FAC0 802425F0 C600000C */  lwc1      $f0, 0xc($s0)
/* D9FAC4 802425F4 27A50020 */  addiu     $a1, $sp, 0x20
/* D9FAC8 802425F8 E7A00014 */  swc1      $f0, 0x14($sp)
/* D9FACC 802425FC 860200A6 */  lh        $v0, 0xa6($s0)
/* D9FAD0 80242600 27A60024 */  addiu     $a2, $sp, 0x24
/* D9FAD4 80242604 44820000 */  mtc1      $v0, $f0
/* D9FAD8 80242608 00000000 */  nop
/* D9FADC 8024260C 46800020 */  cvt.s.w   $f0, $f0
/* D9FAE0 80242610 E7A00018 */  swc1      $f0, 0x18($sp)
/* D9FAE4 80242614 860200A8 */  lh        $v0, 0xa8($s0)
/* D9FAE8 80242618 27A70028 */  addiu     $a3, $sp, 0x28
/* D9FAEC 8024261C 44820000 */  mtc1      $v0, $f0
/* D9FAF0 80242620 00000000 */  nop
/* D9FAF4 80242624 46800020 */  cvt.s.w   $f0, $f0
/* D9FAF8 80242628 0C037711 */  jal       func_800DDC44
/* D9FAFC 8024262C E7A0001C */   swc1     $f0, 0x1c($sp)
/* D9FB00 80242630 54400007 */  bnel      $v0, $zero, .L80242650
/* D9FB04 80242634 24140001 */   addiu    $s4, $zero, 1
/* D9FB08 80242638 8E050018 */  lw        $a1, 0x18($s0)
/* D9FB0C 8024263C 8E06000C */  lw        $a2, 0xc($s0)
/* D9FB10 80242640 0C00EA95 */  jal       npc_move_heading
/* D9FB14 80242644 0200202D */   daddu    $a0, $s0, $zero
/* D9FB18 80242648 08090995 */  j         .L80242654
/* D9FB1C 8024264C 0000902D */   daddu    $s2, $zero, $zero
.L80242650:
/* D9FB20 80242650 0000902D */  daddu     $s2, $zero, $zero
.L80242654:
/* D9FB24 80242654 C600001C */  lwc1      $f0, 0x1c($s0)
/* D9FB28 80242658 44801000 */  mtc1      $zero, $f2
/* D9FB2C 8024265C 44801800 */  mtc1      $zero, $f3
/* D9FB30 80242660 46000021 */  cvt.d.s   $f0, $f0
/* D9FB34 80242664 4622003C */  c.lt.d    $f0, $f2
/* D9FB38 80242668 00000000 */  nop
/* D9FB3C 8024266C 45000028 */  bc1f      .L80242710
/* D9FB40 80242670 27A50020 */   addiu    $a1, $sp, 0x20
/* D9FB44 80242674 27A60024 */  addiu     $a2, $sp, 0x24
/* D9FB48 80242678 27A2002C */  addiu     $v0, $sp, 0x2c
/* D9FB4C 8024267C C602003C */  lwc1      $f2, 0x3c($s0)
/* D9FB50 80242680 C6060038 */  lwc1      $f6, 0x38($s0)
/* D9FB54 80242684 3C01402A */  lui       $at, 0x402a
/* D9FB58 80242688 4481A800 */  mtc1      $at, $f21
/* D9FB5C 8024268C 4480A000 */  mtc1      $zero, $f20
/* D9FB60 80242690 460010A1 */  cvt.d.s   $f2, $f2
/* D9FB64 80242694 46341080 */  add.d     $f2, $f2, $f20
/* D9FB68 80242698 C600001C */  lwc1      $f0, 0x1c($s0)
/* D9FB6C 8024269C C6040040 */  lwc1      $f4, 0x40($s0)
/* D9FB70 802426A0 46000005 */  abs.s     $f0, $f0
/* D9FB74 802426A4 E7A40028 */  swc1      $f4, 0x28($sp)
/* D9FB78 802426A8 3C014030 */  lui       $at, 0x4030
/* D9FB7C 802426AC 44812800 */  mtc1      $at, $f5
/* D9FB80 802426B0 44802000 */  mtc1      $zero, $f4
/* D9FB84 802426B4 46000021 */  cvt.d.s   $f0, $f0
/* D9FB88 802426B8 E7A60020 */  swc1      $f6, 0x20($sp)
/* D9FB8C 802426BC 46240000 */  add.d     $f0, $f0, $f4
/* D9FB90 802426C0 462010A0 */  cvt.s.d   $f2, $f2
/* D9FB94 802426C4 E7A20024 */  swc1      $f2, 0x24($sp)
/* D9FB98 802426C8 46200020 */  cvt.s.d   $f0, $f0
/* D9FB9C 802426CC E7A0002C */  swc1      $f0, 0x2c($sp)
/* D9FBA0 802426D0 AFA20010 */  sw        $v0, 0x10($sp)
/* D9FBA4 802426D4 8E040080 */  lw        $a0, 0x80($s0)
/* D9FBA8 802426D8 0C0372DF */  jal       func_800DCB7C
/* D9FBAC 802426DC 27A70028 */   addiu    $a3, $sp, 0x28
/* D9FBB0 802426E0 1040000B */  beqz      $v0, .L80242710
/* D9FBB4 802426E4 00000000 */   nop
/* D9FBB8 802426E8 C600001C */  lwc1      $f0, 0x1c($s0)
/* D9FBBC 802426EC C7A2002C */  lwc1      $f2, 0x2c($sp)
/* D9FBC0 802426F0 46000005 */  abs.s     $f0, $f0
/* D9FBC4 802426F4 46000021 */  cvt.d.s   $f0, $f0
/* D9FBC8 802426F8 46340000 */  add.d     $f0, $f0, $f20
/* D9FBCC 802426FC 460010A1 */  cvt.d.s   $f2, $f2
/* D9FBD0 80242700 4620103E */  c.le.d    $f2, $f0
/* D9FBD4 80242704 00000000 */  nop
/* D9FBD8 80242708 45030001 */  bc1tl     .L80242710
/* D9FBDC 8024270C 24120001 */   addiu    $s2, $zero, 1
.L80242710:
/* D9FBE0 80242710 56400008 */  bnel      $s2, $zero, .L80242734
/* D9FBE4 80242714 2414000A */   addiu    $s4, $zero, 0xa
/* D9FBE8 80242718 C604003C */  lwc1      $f4, 0x3c($s0)
/* D9FBEC 8024271C C600001C */  lwc1      $f0, 0x1c($s0)
/* D9FBF0 80242720 46002100 */  add.s     $f4, $f4, $f0
/* D9FBF4 80242724 C6020014 */  lwc1      $f2, 0x14($s0)
/* D9FBF8 80242728 46020001 */  sub.s     $f0, $f0, $f2
/* D9FBFC 8024272C E604003C */  swc1      $f4, 0x3c($s0)
/* D9FC00 80242730 E600001C */  swc1      $f0, 0x1c($s0)
.L80242734:
/* D9FC04 80242734 9602008E */  lhu       $v0, 0x8e($s0)
/* D9FC08 80242738 2442FFFF */  addiu     $v0, $v0, -1
/* D9FC0C 8024273C A602008E */  sh        $v0, 0x8e($s0)
/* D9FC10 80242740 00021400 */  sll       $v0, $v0, 0x10
/* D9FC14 80242744 58400001 */  blezl     $v0, .L8024274C
/* D9FC18 80242748 2414000B */   addiu    $s4, $zero, 0xb
.L8024274C:
/* D9FC1C 8024274C 12800024 */  beqz      $s4, .L802427E0
/* D9FC20 80242750 00000000 */   nop
/* D9FC24 80242754 AFA00010 */  sw        $zero, 0x10($sp)
/* D9FC28 80242758 AFA00014 */  sw        $zero, 0x14($sp)
/* D9FC2C 8024275C 8E050038 */  lw        $a1, 0x38($s0)
/* D9FC30 80242760 8E06003C */  lw        $a2, 0x3c($s0)
/* D9FC34 80242764 8E070040 */  lw        $a3, 0x40($s0)
/* D9FC38 80242768 0C01BECC */  jal       fx_walk_normal
/* D9FC3C 8024276C 24040002 */   addiu    $a0, $zero, 2
/* D9FC40 80242770 3C01C47A */  lui       $at, 0xc47a
/* D9FC44 80242774 44810000 */  mtc1      $at, $f0
/* D9FC48 80242778 AE20006C */  sw        $zero, 0x6c($s1)
/* D9FC4C 8024277C 8E020000 */  lw        $v0, ($s0)
/* D9FC50 80242780 0200202D */  daddu     $a0, $s0, $zero
/* D9FC54 80242784 AE000038 */  sw        $zero, 0x38($s0)
/* D9FC58 80242788 AE000040 */  sw        $zero, 0x40($s0)
/* D9FC5C 8024278C 34420002 */  ori       $v0, $v0, 2
/* D9FC60 80242790 E600003C */  swc1      $f0, 0x3c($s0)
/* D9FC64 80242794 0C00EAFF */  jal       disable_npc_shadow
/* D9FC68 80242798 AE020000 */   sw       $v0, ($s0)
/* D9FC6C 8024279C 0260202D */  daddu     $a0, $s3, $zero
/* D9FC70 802427A0 3C05FE36 */  lui       $a1, 0xfe36
/* D9FC74 802427A4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* D9FC78 802427A8 24060001 */  addiu     $a2, $zero, 1
/* D9FC7C 802427AC 8E020000 */  lw        $v0, ($s0)
/* D9FC80 802427B0 2403F7FF */  addiu     $v1, $zero, -0x801
/* D9FC84 802427B4 00431024 */  and       $v0, $v0, $v1
/* D9FC88 802427B8 AE020000 */  sw        $v0, ($s0)
/* D9FC8C 802427BC 8E220000 */  lw        $v0, ($s1)
/* D9FC90 802427C0 3C031F00 */  lui       $v1, 0x1f00
/* D9FC94 802427C4 00431025 */  or        $v0, $v0, $v1
/* D9FC98 802427C8 AE220000 */  sw        $v0, ($s1)
/* D9FC9C 802427CC AC800070 */  sw        $zero, 0x70($a0)
.L802427D0:
/* D9FCA0 802427D0 0C0B2026 */  jal       set_variable
/* D9FCA4 802427D4 00000000 */   nop
/* D9FCA8 802427D8 08090A04 */  j         .L80242810
/* D9FCAC 802427DC 24020002 */   addiu    $v0, $zero, 2
.L802427E0:
/* D9FCB0 802427E0 8E220070 */  lw        $v0, 0x70($s1)
/* D9FCB4 802427E4 30420001 */  andi      $v0, $v0, 1
/* D9FCB8 802427E8 10400009 */  beqz      $v0, .L80242810
/* D9FCBC 802427EC 0000102D */   daddu    $v0, $zero, $zero
/* D9FCC0 802427F0 C600004C */  lwc1      $f0, 0x4c($s0)
/* D9FCC4 802427F4 3C01404E */  lui       $at, 0x404e
/* D9FCC8 802427F8 44811800 */  mtc1      $at, $f3
/* D9FCCC 802427FC 44801000 */  mtc1      $zero, $f2
/* D9FCD0 80242800 46000021 */  cvt.d.s   $f0, $f0
/* D9FCD4 80242804 46220000 */  add.d     $f0, $f0, $f2
/* D9FCD8 80242808 46200020 */  cvt.s.d   $f0, $f0
/* D9FCDC 8024280C E600004C */  swc1      $f0, 0x4c($s0)
.L80242810:
/* D9FCE0 80242810 8FBF0044 */  lw        $ra, 0x44($sp)
/* D9FCE4 80242814 8FB40040 */  lw        $s4, 0x40($sp)
/* D9FCE8 80242818 8FB3003C */  lw        $s3, 0x3c($sp)
/* D9FCEC 8024281C 8FB20038 */  lw        $s2, 0x38($sp)
/* D9FCF0 80242820 8FB10034 */  lw        $s1, 0x34($sp)
/* D9FCF4 80242824 8FB00030 */  lw        $s0, 0x30($sp)
/* D9FCF8 80242828 D7B80058 */  ldc1      $f24, 0x58($sp)
/* D9FCFC 8024282C D7B60050 */  ldc1      $f22, 0x50($sp)
/* D9FD00 80242830 D7B40048 */  ldc1      $f20, 0x48($sp)
/* D9FD04 80242834 03E00008 */  jr        $ra
/* D9FD08 80242838 27BD0060 */   addiu    $sp, $sp, 0x60
