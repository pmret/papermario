.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A98_A61468
/* A61468 80240A98 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* A6146C 80240A9C AFB3003C */  sw        $s3, 0x3c($sp)
/* A61470 80240AA0 0080982D */  daddu     $s3, $a0, $zero
/* A61474 80240AA4 AFB40040 */  sw        $s4, 0x40($sp)
/* A61478 80240AA8 0000A02D */  daddu     $s4, $zero, $zero
/* A6147C 80240AAC 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A61480 80240AB0 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A61484 80240AB4 3C04800B */  lui       $a0, %hi(gCameras)
/* A61488 80240AB8 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A6148C 80240ABC AFBF0044 */  sw        $ra, 0x44($sp)
/* A61490 80240AC0 AFB20038 */  sw        $s2, 0x38($sp)
/* A61494 80240AC4 AFB10034 */  sw        $s1, 0x34($sp)
/* A61498 80240AC8 AFB00030 */  sw        $s0, 0x30($sp)
/* A6149C 80240ACC F7B80058 */  sdc1      $f24, 0x58($sp)
/* A614A0 80240AD0 F7B60050 */  sdc1      $f22, 0x50($sp)
/* A614A4 80240AD4 F7B40048 */  sdc1      $f20, 0x48($sp)
/* A614A8 80240AD8 8E710148 */  lw        $s1, 0x148($s3)
/* A614AC 80240ADC 00031080 */  sll       $v0, $v1, 2
/* A614B0 80240AE0 00431021 */  addu      $v0, $v0, $v1
/* A614B4 80240AE4 00021080 */  sll       $v0, $v0, 2
/* A614B8 80240AE8 00431023 */  subu      $v0, $v0, $v1
/* A614BC 80240AEC 000218C0 */  sll       $v1, $v0, 3
/* A614C0 80240AF0 00431021 */  addu      $v0, $v0, $v1
/* A614C4 80240AF4 000210C0 */  sll       $v0, $v0, 3
/* A614C8 80240AF8 10A00002 */  beqz      $a1, .L80240B04
/* A614CC 80240AFC 00449021 */   addu     $s2, $v0, $a0
/* A614D0 80240B00 AE600070 */  sw        $zero, 0x70($s3)
.L80240B04:
/* A614D4 80240B04 0C00FB5A */  jal       get_enemy_safe
/* A614D8 80240B08 86240008 */   lh       $a0, 8($s1)
/* A614DC 80240B0C 14400006 */  bnez      $v0, .L80240B28
/* A614E0 80240B10 24020005 */   addiu    $v0, $zero, 5
/* A614E4 80240B14 0260202D */  daddu     $a0, $s3, $zero
/* A614E8 80240B18 3C05FE36 */  lui       $a1, 0xfe36
/* A614EC 80240B1C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A614F0 80240B20 080903A2 */  j         .L80240E88
/* A614F4 80240B24 0000302D */   daddu    $a2, $zero, $zero
.L80240B28:
/* A614F8 80240B28 8E23006C */  lw        $v1, 0x6c($s1)
/* A614FC 80240B2C 14620005 */  bne       $v1, $v0, .L80240B44
/* A61500 80240B30 0260202D */   daddu    $a0, $s3, $zero
/* A61504 80240B34 3C05FE36 */  lui       $a1, 0xfe36
/* A61508 80240B38 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A6150C 80240B3C 080903A2 */  j         .L80240E88
/* A61510 80240B40 0000302D */   daddu    $a2, $zero, $zero
.L80240B44:
/* A61514 80240B44 86240008 */  lh        $a0, 8($s1)
/* A61518 80240B48 0C00FB5A */  jal       get_enemy_safe
/* A6151C 80240B4C 00000000 */   nop
/* A61520 80240B50 14400005 */  bnez      $v0, .L80240B68
/* A61524 80240B54 0260202D */   daddu    $a0, $s3, $zero
/* A61528 80240B58 3C05FE36 */  lui       $a1, 0xfe36
/* A6152C 80240B5C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A61530 80240B60 080903A2 */  j         .L80240E88
/* A61534 80240B64 0000302D */   daddu    $a2, $zero, $zero
.L80240B68:
/* A61538 80240B68 86240008 */  lh        $a0, 8($s1)
/* A6153C 80240B6C 0C00EABB */  jal       get_npc_unsafe
/* A61540 80240B70 00000000 */   nop
/* A61544 80240B74 8E630070 */  lw        $v1, 0x70($s3)
/* A61548 80240B78 10600006 */  beqz      $v1, .L80240B94
/* A6154C 80240B7C 0040802D */   daddu    $s0, $v0, $zero
/* A61550 80240B80 24020001 */  addiu     $v0, $zero, 1
/* A61554 80240B84 1062003F */  beq       $v1, $v0, .L80240C84
/* A61558 80240B88 0000102D */   daddu    $v0, $zero, $zero
/* A6155C 80240B8C 080903B2 */  j         .L80240EC8
/* A61560 80240B90 00000000 */   nop
.L80240B94:
/* A61564 80240B94 AFA00010 */  sw        $zero, 0x10($sp)
/* A61568 80240B98 AFA00014 */  sw        $zero, 0x14($sp)
/* A6156C 80240B9C 8E050038 */  lw        $a1, 0x38($s0)
/* A61570 80240BA0 8E06003C */  lw        $a2, 0x3c($s0)
/* A61574 80240BA4 8E070040 */  lw        $a3, 0x40($s0)
/* A61578 80240BA8 0C01BECC */  jal       fx_walk
/* A6157C 80240BAC 24040002 */   addiu    $a0, $zero, 2
/* A61580 80240BB0 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A61584 80240BB4 0C00A6C9 */  jal       clamp_angle
/* A61588 80240BB8 00000000 */   nop
/* A6158C 80240BBC 3C018024 */  lui       $at, %hi(D_802434B0_A63E80)
/* A61590 80240BC0 D43834B0 */  ldc1      $f24, %lo(D_802434B0_A63E80)($at)
/* A61594 80240BC4 46000521 */  cvt.d.s   $f20, $f0
/* A61598 80240BC8 4638A300 */  add.d     $f12, $f20, $f24
/* A6159C 80240BCC 3C018024 */  lui       $at, %hi(D_802434B8_A63E88)
/* A615A0 80240BD0 D43634B8 */  ldc1      $f22, %lo(D_802434B8_A63E88)($at)
/* A615A4 80240BD4 0C00A6C9 */  jal       clamp_angle
/* A615A8 80240BD8 46206320 */   cvt.s.d  $f12, $f12
/* A615AC 80240BDC 4636A500 */  add.d     $f20, $f20, $f22
/* A615B0 80240BE0 4620A320 */  cvt.s.d   $f12, $f20
/* A615B4 80240BE4 0C00A6C9 */  jal       clamp_angle
/* A615B8 80240BE8 46000506 */   mov.s    $f20, $f0
/* A615BC 80240BEC 4600A521 */  cvt.d.s   $f20, $f20
/* A615C0 80240BF0 4636A500 */  add.d     $f20, $f20, $f22
/* A615C4 80240BF4 46000586 */  mov.s     $f22, $f0
/* A615C8 80240BF8 0C00A6C9 */  jal       clamp_angle
/* A615CC 80240BFC 4620A320 */   cvt.s.d  $f12, $f20
/* A615D0 80240C00 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A615D4 80240C04 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A615D8 80240C08 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A615DC 80240C0C C44E0084 */  lwc1      $f14, 0x84($v0)
/* A615E0 80240C10 0C00A70A */  jal       get_clamped_angle_diff
/* A615E4 80240C14 46000506 */   mov.s    $f20, $f0
/* A615E8 80240C18 0C00A6C9 */  jal       clamp_angle
/* A615EC 80240C1C 46000306 */   mov.s    $f12, $f0
/* A615F0 80240C20 46000021 */  cvt.d.s   $f0, $f0
/* A615F4 80240C24 4638003C */  c.lt.d    $f0, $f24
/* A615F8 80240C28 00000000 */  nop
/* A615FC 80240C2C 45020002 */  bc1fl     .L80240C38
/* A61600 80240C30 E614000C */   swc1     $f20, 0xc($s0)
/* A61604 80240C34 E616000C */  swc1      $f22, 0xc($s0)
.L80240C38:
/* A61608 80240C38 C6000018 */  lwc1      $f0, 0x18($s0)
/* A6160C 80240C3C 3C018024 */  lui       $at, %hi(D_802434C0_A63E90)
/* A61610 80240C40 D42234C0 */  ldc1      $f2, %lo(D_802434C0_A63E90)($at)
/* A61614 80240C44 46000021 */  cvt.d.s   $f0, $f0
/* A61618 80240C48 46220002 */  mul.d     $f0, $f0, $f2
/* A6161C 80240C4C 00000000 */  nop
/* A61620 80240C50 3C013F66 */  lui       $at, 0x3f66
/* A61624 80240C54 34216666 */  ori       $at, $at, 0x6666
/* A61628 80240C58 44812000 */  mtc1      $at, $f4
/* A6162C 80240C5C 2402001E */  addiu     $v0, $zero, 0x1e
/* A61630 80240C60 A602008E */  sh        $v0, 0x8e($s0)
/* A61634 80240C64 3C014120 */  lui       $at, 0x4120
/* A61638 80240C68 44811000 */  mtc1      $at, $f2
/* A6163C 80240C6C 24020001 */  addiu     $v0, $zero, 1
/* A61640 80240C70 E6040014 */  swc1      $f4, 0x14($s0)
/* A61644 80240C74 E602001C */  swc1      $f2, 0x1c($s0)
/* A61648 80240C78 46200020 */  cvt.s.d   $f0, $f0
/* A6164C 80240C7C E6000018 */  swc1      $f0, 0x18($s0)
/* A61650 80240C80 AE620070 */  sw        $v0, 0x70($s3)
.L80240C84:
/* A61654 80240C84 C6000038 */  lwc1      $f0, 0x38($s0)
/* A61658 80240C88 C602003C */  lwc1      $f2, 0x3c($s0)
/* A6165C 80240C8C C6040040 */  lwc1      $f4, 0x40($s0)
/* A61660 80240C90 C6060018 */  lwc1      $f6, 0x18($s0)
/* A61664 80240C94 0000202D */  daddu     $a0, $zero, $zero
/* A61668 80240C98 E7A00020 */  swc1      $f0, 0x20($sp)
/* A6166C 80240C9C E7A20024 */  swc1      $f2, 0x24($sp)
/* A61670 80240CA0 E7A40028 */  swc1      $f4, 0x28($sp)
/* A61674 80240CA4 E7A60010 */  swc1      $f6, 0x10($sp)
/* A61678 80240CA8 C600000C */  lwc1      $f0, 0xc($s0)
/* A6167C 80240CAC 27A50020 */  addiu     $a1, $sp, 0x20
/* A61680 80240CB0 E7A00014 */  swc1      $f0, 0x14($sp)
/* A61684 80240CB4 860200A6 */  lh        $v0, 0xa6($s0)
/* A61688 80240CB8 27A60024 */  addiu     $a2, $sp, 0x24
/* A6168C 80240CBC 44820000 */  mtc1      $v0, $f0
/* A61690 80240CC0 00000000 */  nop
/* A61694 80240CC4 46800020 */  cvt.s.w   $f0, $f0
/* A61698 80240CC8 E7A00018 */  swc1      $f0, 0x18($sp)
/* A6169C 80240CCC 860200A8 */  lh        $v0, 0xa8($s0)
/* A616A0 80240CD0 27A70028 */  addiu     $a3, $sp, 0x28
/* A616A4 80240CD4 44820000 */  mtc1      $v0, $f0
/* A616A8 80240CD8 00000000 */  nop
/* A616AC 80240CDC 46800020 */  cvt.s.w   $f0, $f0
/* A616B0 80240CE0 0C037711 */  jal       npc_test_move_simple_with_slipping
/* A616B4 80240CE4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* A616B8 80240CE8 54400007 */  bnel      $v0, $zero, .L80240D08
/* A616BC 80240CEC 24140001 */   addiu    $s4, $zero, 1
/* A616C0 80240CF0 8E050018 */  lw        $a1, 0x18($s0)
/* A616C4 80240CF4 8E06000C */  lw        $a2, 0xc($s0)
/* A616C8 80240CF8 0C00EA95 */  jal       npc_move_heading
/* A616CC 80240CFC 0200202D */   daddu    $a0, $s0, $zero
/* A616D0 80240D00 08090343 */  j         .L80240D0C
/* A616D4 80240D04 0000902D */   daddu    $s2, $zero, $zero
.L80240D08:
/* A616D8 80240D08 0000902D */  daddu     $s2, $zero, $zero
.L80240D0C:
/* A616DC 80240D0C C600001C */  lwc1      $f0, 0x1c($s0)
/* A616E0 80240D10 44801000 */  mtc1      $zero, $f2
/* A616E4 80240D14 44801800 */  mtc1      $zero, $f3
/* A616E8 80240D18 46000021 */  cvt.d.s   $f0, $f0
/* A616EC 80240D1C 4622003C */  c.lt.d    $f0, $f2
/* A616F0 80240D20 00000000 */  nop
/* A616F4 80240D24 45000028 */  bc1f      .L80240DC8
/* A616F8 80240D28 27A50020 */   addiu    $a1, $sp, 0x20
/* A616FC 80240D2C 27A60024 */  addiu     $a2, $sp, 0x24
/* A61700 80240D30 27A2002C */  addiu     $v0, $sp, 0x2c
/* A61704 80240D34 C602003C */  lwc1      $f2, 0x3c($s0)
/* A61708 80240D38 C6060038 */  lwc1      $f6, 0x38($s0)
/* A6170C 80240D3C 3C01402A */  lui       $at, 0x402a
/* A61710 80240D40 4481A800 */  mtc1      $at, $f21
/* A61714 80240D44 4480A000 */  mtc1      $zero, $f20
/* A61718 80240D48 460010A1 */  cvt.d.s   $f2, $f2
/* A6171C 80240D4C 46341080 */  add.d     $f2, $f2, $f20
/* A61720 80240D50 C600001C */  lwc1      $f0, 0x1c($s0)
/* A61724 80240D54 C6040040 */  lwc1      $f4, 0x40($s0)
/* A61728 80240D58 46000005 */  abs.s     $f0, $f0
/* A6172C 80240D5C E7A40028 */  swc1      $f4, 0x28($sp)
/* A61730 80240D60 3C014030 */  lui       $at, 0x4030
/* A61734 80240D64 44812800 */  mtc1      $at, $f5
/* A61738 80240D68 44802000 */  mtc1      $zero, $f4
/* A6173C 80240D6C 46000021 */  cvt.d.s   $f0, $f0
/* A61740 80240D70 E7A60020 */  swc1      $f6, 0x20($sp)
/* A61744 80240D74 46240000 */  add.d     $f0, $f0, $f4
/* A61748 80240D78 462010A0 */  cvt.s.d   $f2, $f2
/* A6174C 80240D7C E7A20024 */  swc1      $f2, 0x24($sp)
/* A61750 80240D80 46200020 */  cvt.s.d   $f0, $f0
/* A61754 80240D84 E7A0002C */  swc1      $f0, 0x2c($sp)
/* A61758 80240D88 AFA20010 */  sw        $v0, 0x10($sp)
/* A6175C 80240D8C 8E040080 */  lw        $a0, 0x80($s0)
/* A61760 80240D90 0C0372DF */  jal       npc_raycast_down_sides
/* A61764 80240D94 27A70028 */   addiu    $a3, $sp, 0x28
/* A61768 80240D98 1040000B */  beqz      $v0, .L80240DC8
/* A6176C 80240D9C 00000000 */   nop
/* A61770 80240DA0 C600001C */  lwc1      $f0, 0x1c($s0)
/* A61774 80240DA4 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A61778 80240DA8 46000005 */  abs.s     $f0, $f0
/* A6177C 80240DAC 46000021 */  cvt.d.s   $f0, $f0
/* A61780 80240DB0 46340000 */  add.d     $f0, $f0, $f20
/* A61784 80240DB4 460010A1 */  cvt.d.s   $f2, $f2
/* A61788 80240DB8 4620103E */  c.le.d    $f2, $f0
/* A6178C 80240DBC 00000000 */  nop
/* A61790 80240DC0 45030001 */  bc1tl     .L80240DC8
/* A61794 80240DC4 24120001 */   addiu    $s2, $zero, 1
.L80240DC8:
/* A61798 80240DC8 56400008 */  bnel      $s2, $zero, .L80240DEC
/* A6179C 80240DCC 2414000A */   addiu    $s4, $zero, 0xa
/* A617A0 80240DD0 C604003C */  lwc1      $f4, 0x3c($s0)
/* A617A4 80240DD4 C600001C */  lwc1      $f0, 0x1c($s0)
/* A617A8 80240DD8 46002100 */  add.s     $f4, $f4, $f0
/* A617AC 80240DDC C6020014 */  lwc1      $f2, 0x14($s0)
/* A617B0 80240DE0 46020001 */  sub.s     $f0, $f0, $f2
/* A617B4 80240DE4 E604003C */  swc1      $f4, 0x3c($s0)
/* A617B8 80240DE8 E600001C */  swc1      $f0, 0x1c($s0)
.L80240DEC:
/* A617BC 80240DEC 9602008E */  lhu       $v0, 0x8e($s0)
/* A617C0 80240DF0 2442FFFF */  addiu     $v0, $v0, -1
/* A617C4 80240DF4 A602008E */  sh        $v0, 0x8e($s0)
/* A617C8 80240DF8 00021400 */  sll       $v0, $v0, 0x10
/* A617CC 80240DFC 58400001 */  blezl     $v0, .L80240E04
/* A617D0 80240E00 2414000B */   addiu    $s4, $zero, 0xb
.L80240E04:
/* A617D4 80240E04 12800024 */  beqz      $s4, .L80240E98
/* A617D8 80240E08 00000000 */   nop
/* A617DC 80240E0C AFA00010 */  sw        $zero, 0x10($sp)
/* A617E0 80240E10 AFA00014 */  sw        $zero, 0x14($sp)
/* A617E4 80240E14 8E050038 */  lw        $a1, 0x38($s0)
/* A617E8 80240E18 8E06003C */  lw        $a2, 0x3c($s0)
/* A617EC 80240E1C 8E070040 */  lw        $a3, 0x40($s0)
/* A617F0 80240E20 0C01BECC */  jal       fx_walk
/* A617F4 80240E24 24040002 */   addiu    $a0, $zero, 2
/* A617F8 80240E28 3C01C47A */  lui       $at, 0xc47a
/* A617FC 80240E2C 44810000 */  mtc1      $at, $f0
/* A61800 80240E30 AE20006C */  sw        $zero, 0x6c($s1)
/* A61804 80240E34 8E020000 */  lw        $v0, ($s0)
/* A61808 80240E38 0200202D */  daddu     $a0, $s0, $zero
/* A6180C 80240E3C AE000038 */  sw        $zero, 0x38($s0)
/* A61810 80240E40 AE000040 */  sw        $zero, 0x40($s0)
/* A61814 80240E44 34420002 */  ori       $v0, $v0, 2
/* A61818 80240E48 E600003C */  swc1      $f0, 0x3c($s0)
/* A6181C 80240E4C 0C00EAFF */  jal       disable_npc_shadow
/* A61820 80240E50 AE020000 */   sw       $v0, ($s0)
/* A61824 80240E54 0260202D */  daddu     $a0, $s3, $zero
/* A61828 80240E58 3C05FE36 */  lui       $a1, 0xfe36
/* A6182C 80240E5C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A61830 80240E60 24060001 */  addiu     $a2, $zero, 1
/* A61834 80240E64 8E020000 */  lw        $v0, ($s0)
/* A61838 80240E68 2403F7FF */  addiu     $v1, $zero, -0x801
/* A6183C 80240E6C 00431024 */  and       $v0, $v0, $v1
/* A61840 80240E70 AE020000 */  sw        $v0, ($s0)
/* A61844 80240E74 8E220000 */  lw        $v0, ($s1)
/* A61848 80240E78 3C031F00 */  lui       $v1, 0x1f00
/* A6184C 80240E7C 00431025 */  or        $v0, $v0, $v1
/* A61850 80240E80 AE220000 */  sw        $v0, ($s1)
/* A61854 80240E84 AC800070 */  sw        $zero, 0x70($a0)
.L80240E88:
/* A61858 80240E88 0C0B2026 */  jal       set_variable
/* A6185C 80240E8C 00000000 */   nop
/* A61860 80240E90 080903B2 */  j         .L80240EC8
/* A61864 80240E94 24020002 */   addiu    $v0, $zero, 2
.L80240E98:
/* A61868 80240E98 8E220070 */  lw        $v0, 0x70($s1)
/* A6186C 80240E9C 30420001 */  andi      $v0, $v0, 1
/* A61870 80240EA0 10400009 */  beqz      $v0, .L80240EC8
/* A61874 80240EA4 0000102D */   daddu    $v0, $zero, $zero
/* A61878 80240EA8 C600004C */  lwc1      $f0, 0x4c($s0)
/* A6187C 80240EAC 3C01404E */  lui       $at, 0x404e
/* A61880 80240EB0 44811800 */  mtc1      $at, $f3
/* A61884 80240EB4 44801000 */  mtc1      $zero, $f2
/* A61888 80240EB8 46000021 */  cvt.d.s   $f0, $f0
/* A6188C 80240EBC 46220000 */  add.d     $f0, $f0, $f2
/* A61890 80240EC0 46200020 */  cvt.s.d   $f0, $f0
/* A61894 80240EC4 E600004C */  swc1      $f0, 0x4c($s0)
.L80240EC8:
/* A61898 80240EC8 8FBF0044 */  lw        $ra, 0x44($sp)
/* A6189C 80240ECC 8FB40040 */  lw        $s4, 0x40($sp)
/* A618A0 80240ED0 8FB3003C */  lw        $s3, 0x3c($sp)
/* A618A4 80240ED4 8FB20038 */  lw        $s2, 0x38($sp)
/* A618A8 80240ED8 8FB10034 */  lw        $s1, 0x34($sp)
/* A618AC 80240EDC 8FB00030 */  lw        $s0, 0x30($sp)
/* A618B0 80240EE0 D7B80058 */  ldc1      $f24, 0x58($sp)
/* A618B4 80240EE4 D7B60050 */  ldc1      $f22, 0x50($sp)
/* A618B8 80240EE8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* A618BC 80240EEC 03E00008 */  jr        $ra
/* A618C0 80240EF0 27BD0060 */   addiu    $sp, $sp, 0x60
