.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B38_A4FB38
/* A4FB38 80240B38 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* A4FB3C 80240B3C AFB3003C */  sw        $s3, 0x3c($sp)
/* A4FB40 80240B40 0080982D */  daddu     $s3, $a0, $zero
/* A4FB44 80240B44 AFB40040 */  sw        $s4, 0x40($sp)
/* A4FB48 80240B48 0000A02D */  daddu     $s4, $zero, $zero
/* A4FB4C 80240B4C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A4FB50 80240B50 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A4FB54 80240B54 3C04800B */  lui       $a0, %hi(gCameras)
/* A4FB58 80240B58 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A4FB5C 80240B5C AFBF0044 */  sw        $ra, 0x44($sp)
/* A4FB60 80240B60 AFB20038 */  sw        $s2, 0x38($sp)
/* A4FB64 80240B64 AFB10034 */  sw        $s1, 0x34($sp)
/* A4FB68 80240B68 AFB00030 */  sw        $s0, 0x30($sp)
/* A4FB6C 80240B6C F7B80058 */  sdc1      $f24, 0x58($sp)
/* A4FB70 80240B70 F7B60050 */  sdc1      $f22, 0x50($sp)
/* A4FB74 80240B74 F7B40048 */  sdc1      $f20, 0x48($sp)
/* A4FB78 80240B78 8E710148 */  lw        $s1, 0x148($s3)
/* A4FB7C 80240B7C 00031080 */  sll       $v0, $v1, 2
/* A4FB80 80240B80 00431021 */  addu      $v0, $v0, $v1
/* A4FB84 80240B84 00021080 */  sll       $v0, $v0, 2
/* A4FB88 80240B88 00431023 */  subu      $v0, $v0, $v1
/* A4FB8C 80240B8C 000218C0 */  sll       $v1, $v0, 3
/* A4FB90 80240B90 00431021 */  addu      $v0, $v0, $v1
/* A4FB94 80240B94 000210C0 */  sll       $v0, $v0, 3
/* A4FB98 80240B98 10A00002 */  beqz      $a1, .L80240BA4
/* A4FB9C 80240B9C 00449021 */   addu     $s2, $v0, $a0
/* A4FBA0 80240BA0 AE600070 */  sw        $zero, 0x70($s3)
.L80240BA4:
/* A4FBA4 80240BA4 0C00FB5A */  jal       get_enemy_safe
/* A4FBA8 80240BA8 86240008 */   lh       $a0, 8($s1)
/* A4FBAC 80240BAC 14400006 */  bnez      $v0, .L80240BC8
/* A4FBB0 80240BB0 24020005 */   addiu    $v0, $zero, 5
/* A4FBB4 80240BB4 0260202D */  daddu     $a0, $s3, $zero
/* A4FBB8 80240BB8 3C05FE36 */  lui       $a1, 0xfe36
/* A4FBBC 80240BBC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A4FBC0 80240BC0 080903CA */  j         .L80240F28
/* A4FBC4 80240BC4 0000302D */   daddu    $a2, $zero, $zero
.L80240BC8:
/* A4FBC8 80240BC8 8E23006C */  lw        $v1, 0x6c($s1)
/* A4FBCC 80240BCC 14620005 */  bne       $v1, $v0, .L80240BE4
/* A4FBD0 80240BD0 0260202D */   daddu    $a0, $s3, $zero
/* A4FBD4 80240BD4 3C05FE36 */  lui       $a1, 0xfe36
/* A4FBD8 80240BD8 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A4FBDC 80240BDC 080903CA */  j         .L80240F28
/* A4FBE0 80240BE0 0000302D */   daddu    $a2, $zero, $zero
.L80240BE4:
/* A4FBE4 80240BE4 86240008 */  lh        $a0, 8($s1)
/* A4FBE8 80240BE8 0C00FB5A */  jal       get_enemy_safe
/* A4FBEC 80240BEC 00000000 */   nop
/* A4FBF0 80240BF0 14400005 */  bnez      $v0, .L80240C08
/* A4FBF4 80240BF4 0260202D */   daddu    $a0, $s3, $zero
/* A4FBF8 80240BF8 3C05FE36 */  lui       $a1, 0xfe36
/* A4FBFC 80240BFC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A4FC00 80240C00 080903CA */  j         .L80240F28
/* A4FC04 80240C04 0000302D */   daddu    $a2, $zero, $zero
.L80240C08:
/* A4FC08 80240C08 86240008 */  lh        $a0, 8($s1)
/* A4FC0C 80240C0C 0C00EABB */  jal       get_npc_unsafe
/* A4FC10 80240C10 00000000 */   nop
/* A4FC14 80240C14 8E630070 */  lw        $v1, 0x70($s3)
/* A4FC18 80240C18 10600006 */  beqz      $v1, .L80240C34
/* A4FC1C 80240C1C 0040802D */   daddu    $s0, $v0, $zero
/* A4FC20 80240C20 24020001 */  addiu     $v0, $zero, 1
/* A4FC24 80240C24 1062003F */  beq       $v1, $v0, .L80240D24
/* A4FC28 80240C28 0000102D */   daddu    $v0, $zero, $zero
/* A4FC2C 80240C2C 080903DA */  j         .L80240F68
/* A4FC30 80240C30 00000000 */   nop
.L80240C34:
/* A4FC34 80240C34 AFA00010 */  sw        $zero, 0x10($sp)
/* A4FC38 80240C38 AFA00014 */  sw        $zero, 0x14($sp)
/* A4FC3C 80240C3C 8E050038 */  lw        $a1, 0x38($s0)
/* A4FC40 80240C40 8E06003C */  lw        $a2, 0x3c($s0)
/* A4FC44 80240C44 8E070040 */  lw        $a3, 0x40($s0)
/* A4FC48 80240C48 0C01BECC */  jal       fx_walk
/* A4FC4C 80240C4C 24040002 */   addiu    $a0, $zero, 2
/* A4FC50 80240C50 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A4FC54 80240C54 0C00A6C9 */  jal       clamp_angle
/* A4FC58 80240C58 00000000 */   nop
/* A4FC5C 80240C5C 3C018024 */  lui       $at, %hi(D_802427D0_A517D0)
/* A4FC60 80240C60 D43827D0 */  ldc1      $f24, %lo(D_802427D0_A517D0)($at)
/* A4FC64 80240C64 46000521 */  cvt.d.s   $f20, $f0
/* A4FC68 80240C68 4638A300 */  add.d     $f12, $f20, $f24
/* A4FC6C 80240C6C 3C018024 */  lui       $at, %hi(D_802427D8_A517D8)
/* A4FC70 80240C70 D43627D8 */  ldc1      $f22, %lo(D_802427D8_A517D8)($at)
/* A4FC74 80240C74 0C00A6C9 */  jal       clamp_angle
/* A4FC78 80240C78 46206320 */   cvt.s.d  $f12, $f12
/* A4FC7C 80240C7C 4636A500 */  add.d     $f20, $f20, $f22
/* A4FC80 80240C80 4620A320 */  cvt.s.d   $f12, $f20
/* A4FC84 80240C84 0C00A6C9 */  jal       clamp_angle
/* A4FC88 80240C88 46000506 */   mov.s    $f20, $f0
/* A4FC8C 80240C8C 4600A521 */  cvt.d.s   $f20, $f20
/* A4FC90 80240C90 4636A500 */  add.d     $f20, $f20, $f22
/* A4FC94 80240C94 46000586 */  mov.s     $f22, $f0
/* A4FC98 80240C98 0C00A6C9 */  jal       clamp_angle
/* A4FC9C 80240C9C 4620A320 */   cvt.s.d  $f12, $f20
/* A4FCA0 80240CA0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A4FCA4 80240CA4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A4FCA8 80240CA8 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A4FCAC 80240CAC C44E0084 */  lwc1      $f14, 0x84($v0)
/* A4FCB0 80240CB0 0C00A70A */  jal       get_clamped_angle_diff
/* A4FCB4 80240CB4 46000506 */   mov.s    $f20, $f0
/* A4FCB8 80240CB8 0C00A6C9 */  jal       clamp_angle
/* A4FCBC 80240CBC 46000306 */   mov.s    $f12, $f0
/* A4FCC0 80240CC0 46000021 */  cvt.d.s   $f0, $f0
/* A4FCC4 80240CC4 4638003C */  c.lt.d    $f0, $f24
/* A4FCC8 80240CC8 00000000 */  nop
/* A4FCCC 80240CCC 45020002 */  bc1fl     .L80240CD8
/* A4FCD0 80240CD0 E614000C */   swc1     $f20, 0xc($s0)
/* A4FCD4 80240CD4 E616000C */  swc1      $f22, 0xc($s0)
.L80240CD8:
/* A4FCD8 80240CD8 C6000018 */  lwc1      $f0, 0x18($s0)
/* A4FCDC 80240CDC 3C018024 */  lui       $at, %hi(D_802427E0_A517E0)
/* A4FCE0 80240CE0 D42227E0 */  ldc1      $f2, %lo(D_802427E0_A517E0)($at)
/* A4FCE4 80240CE4 46000021 */  cvt.d.s   $f0, $f0
/* A4FCE8 80240CE8 46220002 */  mul.d     $f0, $f0, $f2
/* A4FCEC 80240CEC 00000000 */  nop
/* A4FCF0 80240CF0 3C013F66 */  lui       $at, 0x3f66
/* A4FCF4 80240CF4 34216666 */  ori       $at, $at, 0x6666
/* A4FCF8 80240CF8 44812000 */  mtc1      $at, $f4
/* A4FCFC 80240CFC 2402001E */  addiu     $v0, $zero, 0x1e
/* A4FD00 80240D00 A602008E */  sh        $v0, 0x8e($s0)
/* A4FD04 80240D04 3C014120 */  lui       $at, 0x4120
/* A4FD08 80240D08 44811000 */  mtc1      $at, $f2
/* A4FD0C 80240D0C 24020001 */  addiu     $v0, $zero, 1
/* A4FD10 80240D10 E6040014 */  swc1      $f4, 0x14($s0)
/* A4FD14 80240D14 E602001C */  swc1      $f2, 0x1c($s0)
/* A4FD18 80240D18 46200020 */  cvt.s.d   $f0, $f0
/* A4FD1C 80240D1C E6000018 */  swc1      $f0, 0x18($s0)
/* A4FD20 80240D20 AE620070 */  sw        $v0, 0x70($s3)
.L80240D24:
/* A4FD24 80240D24 C6000038 */  lwc1      $f0, 0x38($s0)
/* A4FD28 80240D28 C602003C */  lwc1      $f2, 0x3c($s0)
/* A4FD2C 80240D2C C6040040 */  lwc1      $f4, 0x40($s0)
/* A4FD30 80240D30 C6060018 */  lwc1      $f6, 0x18($s0)
/* A4FD34 80240D34 0000202D */  daddu     $a0, $zero, $zero
/* A4FD38 80240D38 E7A00020 */  swc1      $f0, 0x20($sp)
/* A4FD3C 80240D3C E7A20024 */  swc1      $f2, 0x24($sp)
/* A4FD40 80240D40 E7A40028 */  swc1      $f4, 0x28($sp)
/* A4FD44 80240D44 E7A60010 */  swc1      $f6, 0x10($sp)
/* A4FD48 80240D48 C600000C */  lwc1      $f0, 0xc($s0)
/* A4FD4C 80240D4C 27A50020 */  addiu     $a1, $sp, 0x20
/* A4FD50 80240D50 E7A00014 */  swc1      $f0, 0x14($sp)
/* A4FD54 80240D54 860200A6 */  lh        $v0, 0xa6($s0)
/* A4FD58 80240D58 27A60024 */  addiu     $a2, $sp, 0x24
/* A4FD5C 80240D5C 44820000 */  mtc1      $v0, $f0
/* A4FD60 80240D60 00000000 */  nop
/* A4FD64 80240D64 46800020 */  cvt.s.w   $f0, $f0
/* A4FD68 80240D68 E7A00018 */  swc1      $f0, 0x18($sp)
/* A4FD6C 80240D6C 860200A8 */  lh        $v0, 0xa8($s0)
/* A4FD70 80240D70 27A70028 */  addiu     $a3, $sp, 0x28
/* A4FD74 80240D74 44820000 */  mtc1      $v0, $f0
/* A4FD78 80240D78 00000000 */  nop
/* A4FD7C 80240D7C 46800020 */  cvt.s.w   $f0, $f0
/* A4FD80 80240D80 0C037711 */  jal       npc_test_move_simple_with_slipping
/* A4FD84 80240D84 E7A0001C */   swc1     $f0, 0x1c($sp)
/* A4FD88 80240D88 54400007 */  bnel      $v0, $zero, .L80240DA8
/* A4FD8C 80240D8C 24140001 */   addiu    $s4, $zero, 1
/* A4FD90 80240D90 8E050018 */  lw        $a1, 0x18($s0)
/* A4FD94 80240D94 8E06000C */  lw        $a2, 0xc($s0)
/* A4FD98 80240D98 0C00EA95 */  jal       npc_move_heading
/* A4FD9C 80240D9C 0200202D */   daddu    $a0, $s0, $zero
/* A4FDA0 80240DA0 0809036B */  j         .L80240DAC
/* A4FDA4 80240DA4 0000902D */   daddu    $s2, $zero, $zero
.L80240DA8:
/* A4FDA8 80240DA8 0000902D */  daddu     $s2, $zero, $zero
.L80240DAC:
/* A4FDAC 80240DAC C600001C */  lwc1      $f0, 0x1c($s0)
/* A4FDB0 80240DB0 44801000 */  mtc1      $zero, $f2
/* A4FDB4 80240DB4 44801800 */  mtc1      $zero, $f3
/* A4FDB8 80240DB8 46000021 */  cvt.d.s   $f0, $f0
/* A4FDBC 80240DBC 4622003C */  c.lt.d    $f0, $f2
/* A4FDC0 80240DC0 00000000 */  nop
/* A4FDC4 80240DC4 45000028 */  bc1f      .L80240E68
/* A4FDC8 80240DC8 27A50020 */   addiu    $a1, $sp, 0x20
/* A4FDCC 80240DCC 27A60024 */  addiu     $a2, $sp, 0x24
/* A4FDD0 80240DD0 27A2002C */  addiu     $v0, $sp, 0x2c
/* A4FDD4 80240DD4 C602003C */  lwc1      $f2, 0x3c($s0)
/* A4FDD8 80240DD8 C6060038 */  lwc1      $f6, 0x38($s0)
/* A4FDDC 80240DDC 3C01402A */  lui       $at, 0x402a
/* A4FDE0 80240DE0 4481A800 */  mtc1      $at, $f21
/* A4FDE4 80240DE4 4480A000 */  mtc1      $zero, $f20
/* A4FDE8 80240DE8 460010A1 */  cvt.d.s   $f2, $f2
/* A4FDEC 80240DEC 46341080 */  add.d     $f2, $f2, $f20
/* A4FDF0 80240DF0 C600001C */  lwc1      $f0, 0x1c($s0)
/* A4FDF4 80240DF4 C6040040 */  lwc1      $f4, 0x40($s0)
/* A4FDF8 80240DF8 46000005 */  abs.s     $f0, $f0
/* A4FDFC 80240DFC E7A40028 */  swc1      $f4, 0x28($sp)
/* A4FE00 80240E00 3C014030 */  lui       $at, 0x4030
/* A4FE04 80240E04 44812800 */  mtc1      $at, $f5
/* A4FE08 80240E08 44802000 */  mtc1      $zero, $f4
/* A4FE0C 80240E0C 46000021 */  cvt.d.s   $f0, $f0
/* A4FE10 80240E10 E7A60020 */  swc1      $f6, 0x20($sp)
/* A4FE14 80240E14 46240000 */  add.d     $f0, $f0, $f4
/* A4FE18 80240E18 462010A0 */  cvt.s.d   $f2, $f2
/* A4FE1C 80240E1C E7A20024 */  swc1      $f2, 0x24($sp)
/* A4FE20 80240E20 46200020 */  cvt.s.d   $f0, $f0
/* A4FE24 80240E24 E7A0002C */  swc1      $f0, 0x2c($sp)
/* A4FE28 80240E28 AFA20010 */  sw        $v0, 0x10($sp)
/* A4FE2C 80240E2C 8E040080 */  lw        $a0, 0x80($s0)
/* A4FE30 80240E30 0C0372DF */  jal       npc_raycast_down_sides
/* A4FE34 80240E34 27A70028 */   addiu    $a3, $sp, 0x28
/* A4FE38 80240E38 1040000B */  beqz      $v0, .L80240E68
/* A4FE3C 80240E3C 00000000 */   nop
/* A4FE40 80240E40 C600001C */  lwc1      $f0, 0x1c($s0)
/* A4FE44 80240E44 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A4FE48 80240E48 46000005 */  abs.s     $f0, $f0
/* A4FE4C 80240E4C 46000021 */  cvt.d.s   $f0, $f0
/* A4FE50 80240E50 46340000 */  add.d     $f0, $f0, $f20
/* A4FE54 80240E54 460010A1 */  cvt.d.s   $f2, $f2
/* A4FE58 80240E58 4620103E */  c.le.d    $f2, $f0
/* A4FE5C 80240E5C 00000000 */  nop
/* A4FE60 80240E60 45030001 */  bc1tl     .L80240E68
/* A4FE64 80240E64 24120001 */   addiu    $s2, $zero, 1
.L80240E68:
/* A4FE68 80240E68 56400008 */  bnel      $s2, $zero, .L80240E8C
/* A4FE6C 80240E6C 2414000A */   addiu    $s4, $zero, 0xa
/* A4FE70 80240E70 C604003C */  lwc1      $f4, 0x3c($s0)
/* A4FE74 80240E74 C600001C */  lwc1      $f0, 0x1c($s0)
/* A4FE78 80240E78 46002100 */  add.s     $f4, $f4, $f0
/* A4FE7C 80240E7C C6020014 */  lwc1      $f2, 0x14($s0)
/* A4FE80 80240E80 46020001 */  sub.s     $f0, $f0, $f2
/* A4FE84 80240E84 E604003C */  swc1      $f4, 0x3c($s0)
/* A4FE88 80240E88 E600001C */  swc1      $f0, 0x1c($s0)
.L80240E8C:
/* A4FE8C 80240E8C 9602008E */  lhu       $v0, 0x8e($s0)
/* A4FE90 80240E90 2442FFFF */  addiu     $v0, $v0, -1
/* A4FE94 80240E94 A602008E */  sh        $v0, 0x8e($s0)
/* A4FE98 80240E98 00021400 */  sll       $v0, $v0, 0x10
/* A4FE9C 80240E9C 58400001 */  blezl     $v0, .L80240EA4
/* A4FEA0 80240EA0 2414000B */   addiu    $s4, $zero, 0xb
.L80240EA4:
/* A4FEA4 80240EA4 12800024 */  beqz      $s4, .L80240F38
/* A4FEA8 80240EA8 00000000 */   nop
/* A4FEAC 80240EAC AFA00010 */  sw        $zero, 0x10($sp)
/* A4FEB0 80240EB0 AFA00014 */  sw        $zero, 0x14($sp)
/* A4FEB4 80240EB4 8E050038 */  lw        $a1, 0x38($s0)
/* A4FEB8 80240EB8 8E06003C */  lw        $a2, 0x3c($s0)
/* A4FEBC 80240EBC 8E070040 */  lw        $a3, 0x40($s0)
/* A4FEC0 80240EC0 0C01BECC */  jal       fx_walk
/* A4FEC4 80240EC4 24040002 */   addiu    $a0, $zero, 2
/* A4FEC8 80240EC8 3C01C47A */  lui       $at, 0xc47a
/* A4FECC 80240ECC 44810000 */  mtc1      $at, $f0
/* A4FED0 80240ED0 AE20006C */  sw        $zero, 0x6c($s1)
/* A4FED4 80240ED4 8E020000 */  lw        $v0, ($s0)
/* A4FED8 80240ED8 0200202D */  daddu     $a0, $s0, $zero
/* A4FEDC 80240EDC AE000038 */  sw        $zero, 0x38($s0)
/* A4FEE0 80240EE0 AE000040 */  sw        $zero, 0x40($s0)
/* A4FEE4 80240EE4 34420002 */  ori       $v0, $v0, 2
/* A4FEE8 80240EE8 E600003C */  swc1      $f0, 0x3c($s0)
/* A4FEEC 80240EEC 0C00EAFF */  jal       disable_npc_shadow
/* A4FEF0 80240EF0 AE020000 */   sw       $v0, ($s0)
/* A4FEF4 80240EF4 0260202D */  daddu     $a0, $s3, $zero
/* A4FEF8 80240EF8 3C05FE36 */  lui       $a1, 0xfe36
/* A4FEFC 80240EFC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A4FF00 80240F00 24060001 */  addiu     $a2, $zero, 1
/* A4FF04 80240F04 8E020000 */  lw        $v0, ($s0)
/* A4FF08 80240F08 2403F7FF */  addiu     $v1, $zero, -0x801
/* A4FF0C 80240F0C 00431024 */  and       $v0, $v0, $v1
/* A4FF10 80240F10 AE020000 */  sw        $v0, ($s0)
/* A4FF14 80240F14 8E220000 */  lw        $v0, ($s1)
/* A4FF18 80240F18 3C031F00 */  lui       $v1, 0x1f00
/* A4FF1C 80240F1C 00431025 */  or        $v0, $v0, $v1
/* A4FF20 80240F20 AE220000 */  sw        $v0, ($s1)
/* A4FF24 80240F24 AC800070 */  sw        $zero, 0x70($a0)
.L80240F28:
/* A4FF28 80240F28 0C0B2026 */  jal       set_variable
/* A4FF2C 80240F2C 00000000 */   nop
/* A4FF30 80240F30 080903DA */  j         .L80240F68
/* A4FF34 80240F34 24020002 */   addiu    $v0, $zero, 2
.L80240F38:
/* A4FF38 80240F38 8E220070 */  lw        $v0, 0x70($s1)
/* A4FF3C 80240F3C 30420001 */  andi      $v0, $v0, 1
/* A4FF40 80240F40 10400009 */  beqz      $v0, .L80240F68
/* A4FF44 80240F44 0000102D */   daddu    $v0, $zero, $zero
/* A4FF48 80240F48 C600004C */  lwc1      $f0, 0x4c($s0)
/* A4FF4C 80240F4C 3C01404E */  lui       $at, 0x404e
/* A4FF50 80240F50 44811800 */  mtc1      $at, $f3
/* A4FF54 80240F54 44801000 */  mtc1      $zero, $f2
/* A4FF58 80240F58 46000021 */  cvt.d.s   $f0, $f0
/* A4FF5C 80240F5C 46220000 */  add.d     $f0, $f0, $f2
/* A4FF60 80240F60 46200020 */  cvt.s.d   $f0, $f0
/* A4FF64 80240F64 E600004C */  swc1      $f0, 0x4c($s0)
.L80240F68:
/* A4FF68 80240F68 8FBF0044 */  lw        $ra, 0x44($sp)
/* A4FF6C 80240F6C 8FB40040 */  lw        $s4, 0x40($sp)
/* A4FF70 80240F70 8FB3003C */  lw        $s3, 0x3c($sp)
/* A4FF74 80240F74 8FB20038 */  lw        $s2, 0x38($sp)
/* A4FF78 80240F78 8FB10034 */  lw        $s1, 0x34($sp)
/* A4FF7C 80240F7C 8FB00030 */  lw        $s0, 0x30($sp)
/* A4FF80 80240F80 D7B80058 */  ldc1      $f24, 0x58($sp)
/* A4FF84 80240F84 D7B60050 */  ldc1      $f22, 0x50($sp)
/* A4FF88 80240F88 D7B40048 */  ldc1      $f20, 0x48($sp)
/* A4FF8C 80240F8C 03E00008 */  jr        $ra
/* A4FF90 80240F90 27BD0060 */   addiu    $sp, $sp, 0x60
