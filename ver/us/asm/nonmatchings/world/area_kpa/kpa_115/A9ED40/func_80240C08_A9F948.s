.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C08_A9F948
/* A9F948 80240C08 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* A9F94C 80240C0C AFB3003C */  sw        $s3, 0x3c($sp)
/* A9F950 80240C10 0080982D */  daddu     $s3, $a0, $zero
/* A9F954 80240C14 AFB40040 */  sw        $s4, 0x40($sp)
/* A9F958 80240C18 0000A02D */  daddu     $s4, $zero, $zero
/* A9F95C 80240C1C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A9F960 80240C20 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A9F964 80240C24 3C04800B */  lui       $a0, %hi(gCameras)
/* A9F968 80240C28 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A9F96C 80240C2C AFBF0044 */  sw        $ra, 0x44($sp)
/* A9F970 80240C30 AFB20038 */  sw        $s2, 0x38($sp)
/* A9F974 80240C34 AFB10034 */  sw        $s1, 0x34($sp)
/* A9F978 80240C38 AFB00030 */  sw        $s0, 0x30($sp)
/* A9F97C 80240C3C F7B80058 */  sdc1      $f24, 0x58($sp)
/* A9F980 80240C40 F7B60050 */  sdc1      $f22, 0x50($sp)
/* A9F984 80240C44 F7B40048 */  sdc1      $f20, 0x48($sp)
/* A9F988 80240C48 8E710148 */  lw        $s1, 0x148($s3)
/* A9F98C 80240C4C 00031080 */  sll       $v0, $v1, 2
/* A9F990 80240C50 00431021 */  addu      $v0, $v0, $v1
/* A9F994 80240C54 00021080 */  sll       $v0, $v0, 2
/* A9F998 80240C58 00431023 */  subu      $v0, $v0, $v1
/* A9F99C 80240C5C 000218C0 */  sll       $v1, $v0, 3
/* A9F9A0 80240C60 00431021 */  addu      $v0, $v0, $v1
/* A9F9A4 80240C64 000210C0 */  sll       $v0, $v0, 3
/* A9F9A8 80240C68 10A00002 */  beqz      $a1, .L80240C74
/* A9F9AC 80240C6C 00449021 */   addu     $s2, $v0, $a0
/* A9F9B0 80240C70 AE600070 */  sw        $zero, 0x70($s3)
.L80240C74:
/* A9F9B4 80240C74 0C00FB5A */  jal       get_enemy_safe
/* A9F9B8 80240C78 86240008 */   lh       $a0, 8($s1)
/* A9F9BC 80240C7C 14400006 */  bnez      $v0, .L80240C98
/* A9F9C0 80240C80 24020005 */   addiu    $v0, $zero, 5
/* A9F9C4 80240C84 0260202D */  daddu     $a0, $s3, $zero
/* A9F9C8 80240C88 3C05FE36 */  lui       $a1, 0xfe36
/* A9F9CC 80240C8C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9F9D0 80240C90 080903FE */  j         .L80240FF8
/* A9F9D4 80240C94 0000302D */   daddu    $a2, $zero, $zero
.L80240C98:
/* A9F9D8 80240C98 8E23006C */  lw        $v1, 0x6c($s1)
/* A9F9DC 80240C9C 14620005 */  bne       $v1, $v0, .L80240CB4
/* A9F9E0 80240CA0 0260202D */   daddu    $a0, $s3, $zero
/* A9F9E4 80240CA4 3C05FE36 */  lui       $a1, 0xfe36
/* A9F9E8 80240CA8 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9F9EC 80240CAC 080903FE */  j         .L80240FF8
/* A9F9F0 80240CB0 0000302D */   daddu    $a2, $zero, $zero
.L80240CB4:
/* A9F9F4 80240CB4 86240008 */  lh        $a0, 8($s1)
/* A9F9F8 80240CB8 0C00FB5A */  jal       get_enemy_safe
/* A9F9FC 80240CBC 00000000 */   nop
/* A9FA00 80240CC0 14400005 */  bnez      $v0, .L80240CD8
/* A9FA04 80240CC4 0260202D */   daddu    $a0, $s3, $zero
/* A9FA08 80240CC8 3C05FE36 */  lui       $a1, 0xfe36
/* A9FA0C 80240CCC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9FA10 80240CD0 080903FE */  j         .L80240FF8
/* A9FA14 80240CD4 0000302D */   daddu    $a2, $zero, $zero
.L80240CD8:
/* A9FA18 80240CD8 86240008 */  lh        $a0, 8($s1)
/* A9FA1C 80240CDC 0C00EABB */  jal       get_npc_unsafe
/* A9FA20 80240CE0 00000000 */   nop
/* A9FA24 80240CE4 8E630070 */  lw        $v1, 0x70($s3)
/* A9FA28 80240CE8 10600006 */  beqz      $v1, .L80240D04
/* A9FA2C 80240CEC 0040802D */   daddu    $s0, $v0, $zero
/* A9FA30 80240CF0 24020001 */  addiu     $v0, $zero, 1
/* A9FA34 80240CF4 1062003F */  beq       $v1, $v0, .L80240DF4
/* A9FA38 80240CF8 0000102D */   daddu    $v0, $zero, $zero
/* A9FA3C 80240CFC 0809040E */  j         .L80241038
/* A9FA40 80240D00 00000000 */   nop
.L80240D04:
/* A9FA44 80240D04 AFA00010 */  sw        $zero, 0x10($sp)
/* A9FA48 80240D08 AFA00014 */  sw        $zero, 0x14($sp)
/* A9FA4C 80240D0C 8E050038 */  lw        $a1, 0x38($s0)
/* A9FA50 80240D10 8E06003C */  lw        $a2, 0x3c($s0)
/* A9FA54 80240D14 8E070040 */  lw        $a3, 0x40($s0)
/* A9FA58 80240D18 0C01BECC */  jal       fx_walk
/* A9FA5C 80240D1C 24040002 */   addiu    $a0, $zero, 2
/* A9FA60 80240D20 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A9FA64 80240D24 0C00A6C9 */  jal       clamp_angle
/* A9FA68 80240D28 00000000 */   nop
/* A9FA6C 80240D2C 3C018024 */  lui       $at, %hi(D_80242FF0_AA1D30)
/* A9FA70 80240D30 D4382FF0 */  ldc1      $f24, %lo(D_80242FF0_AA1D30)($at)
/* A9FA74 80240D34 46000521 */  cvt.d.s   $f20, $f0
/* A9FA78 80240D38 4638A300 */  add.d     $f12, $f20, $f24
/* A9FA7C 80240D3C 3C018024 */  lui       $at, %hi(D_80242FF8_AA1D38)
/* A9FA80 80240D40 D4362FF8 */  ldc1      $f22, %lo(D_80242FF8_AA1D38)($at)
/* A9FA84 80240D44 0C00A6C9 */  jal       clamp_angle
/* A9FA88 80240D48 46206320 */   cvt.s.d  $f12, $f12
/* A9FA8C 80240D4C 4636A500 */  add.d     $f20, $f20, $f22
/* A9FA90 80240D50 4620A320 */  cvt.s.d   $f12, $f20
/* A9FA94 80240D54 0C00A6C9 */  jal       clamp_angle
/* A9FA98 80240D58 46000506 */   mov.s    $f20, $f0
/* A9FA9C 80240D5C 4600A521 */  cvt.d.s   $f20, $f20
/* A9FAA0 80240D60 4636A500 */  add.d     $f20, $f20, $f22
/* A9FAA4 80240D64 46000586 */  mov.s     $f22, $f0
/* A9FAA8 80240D68 0C00A6C9 */  jal       clamp_angle
/* A9FAAC 80240D6C 4620A320 */   cvt.s.d  $f12, $f20
/* A9FAB0 80240D70 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A9FAB4 80240D74 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A9FAB8 80240D78 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A9FABC 80240D7C C44E0084 */  lwc1      $f14, 0x84($v0)
/* A9FAC0 80240D80 0C00A70A */  jal       get_clamped_angle_diff
/* A9FAC4 80240D84 46000506 */   mov.s    $f20, $f0
/* A9FAC8 80240D88 0C00A6C9 */  jal       clamp_angle
/* A9FACC 80240D8C 46000306 */   mov.s    $f12, $f0
/* A9FAD0 80240D90 46000021 */  cvt.d.s   $f0, $f0
/* A9FAD4 80240D94 4638003C */  c.lt.d    $f0, $f24
/* A9FAD8 80240D98 00000000 */  nop
/* A9FADC 80240D9C 45020002 */  bc1fl     .L80240DA8
/* A9FAE0 80240DA0 E614000C */   swc1     $f20, 0xc($s0)
/* A9FAE4 80240DA4 E616000C */  swc1      $f22, 0xc($s0)
.L80240DA8:
/* A9FAE8 80240DA8 C6000018 */  lwc1      $f0, 0x18($s0)
/* A9FAEC 80240DAC 3C018024 */  lui       $at, %hi(D_80243000_AA1D40)
/* A9FAF0 80240DB0 D4223000 */  ldc1      $f2, %lo(D_80243000_AA1D40)($at)
/* A9FAF4 80240DB4 46000021 */  cvt.d.s   $f0, $f0
/* A9FAF8 80240DB8 46220002 */  mul.d     $f0, $f0, $f2
/* A9FAFC 80240DBC 00000000 */  nop
/* A9FB00 80240DC0 3C013F66 */  lui       $at, 0x3f66
/* A9FB04 80240DC4 34216666 */  ori       $at, $at, 0x6666
/* A9FB08 80240DC8 44812000 */  mtc1      $at, $f4
/* A9FB0C 80240DCC 2402001E */  addiu     $v0, $zero, 0x1e
/* A9FB10 80240DD0 A602008E */  sh        $v0, 0x8e($s0)
/* A9FB14 80240DD4 3C014120 */  lui       $at, 0x4120
/* A9FB18 80240DD8 44811000 */  mtc1      $at, $f2
/* A9FB1C 80240DDC 24020001 */  addiu     $v0, $zero, 1
/* A9FB20 80240DE0 E6040014 */  swc1      $f4, 0x14($s0)
/* A9FB24 80240DE4 E602001C */  swc1      $f2, 0x1c($s0)
/* A9FB28 80240DE8 46200020 */  cvt.s.d   $f0, $f0
/* A9FB2C 80240DEC E6000018 */  swc1      $f0, 0x18($s0)
/* A9FB30 80240DF0 AE620070 */  sw        $v0, 0x70($s3)
.L80240DF4:
/* A9FB34 80240DF4 C6000038 */  lwc1      $f0, 0x38($s0)
/* A9FB38 80240DF8 C602003C */  lwc1      $f2, 0x3c($s0)
/* A9FB3C 80240DFC C6040040 */  lwc1      $f4, 0x40($s0)
/* A9FB40 80240E00 C6060018 */  lwc1      $f6, 0x18($s0)
/* A9FB44 80240E04 0000202D */  daddu     $a0, $zero, $zero
/* A9FB48 80240E08 E7A00020 */  swc1      $f0, 0x20($sp)
/* A9FB4C 80240E0C E7A20024 */  swc1      $f2, 0x24($sp)
/* A9FB50 80240E10 E7A40028 */  swc1      $f4, 0x28($sp)
/* A9FB54 80240E14 E7A60010 */  swc1      $f6, 0x10($sp)
/* A9FB58 80240E18 C600000C */  lwc1      $f0, 0xc($s0)
/* A9FB5C 80240E1C 27A50020 */  addiu     $a1, $sp, 0x20
/* A9FB60 80240E20 E7A00014 */  swc1      $f0, 0x14($sp)
/* A9FB64 80240E24 860200A6 */  lh        $v0, 0xa6($s0)
/* A9FB68 80240E28 27A60024 */  addiu     $a2, $sp, 0x24
/* A9FB6C 80240E2C 44820000 */  mtc1      $v0, $f0
/* A9FB70 80240E30 00000000 */  nop
/* A9FB74 80240E34 46800020 */  cvt.s.w   $f0, $f0
/* A9FB78 80240E38 E7A00018 */  swc1      $f0, 0x18($sp)
/* A9FB7C 80240E3C 860200A8 */  lh        $v0, 0xa8($s0)
/* A9FB80 80240E40 27A70028 */  addiu     $a3, $sp, 0x28
/* A9FB84 80240E44 44820000 */  mtc1      $v0, $f0
/* A9FB88 80240E48 00000000 */  nop
/* A9FB8C 80240E4C 46800020 */  cvt.s.w   $f0, $f0
/* A9FB90 80240E50 0C037711 */  jal       npc_test_move_simple_with_slipping
/* A9FB94 80240E54 E7A0001C */   swc1     $f0, 0x1c($sp)
/* A9FB98 80240E58 54400007 */  bnel      $v0, $zero, .L80240E78
/* A9FB9C 80240E5C 24140001 */   addiu    $s4, $zero, 1
/* A9FBA0 80240E60 8E050018 */  lw        $a1, 0x18($s0)
/* A9FBA4 80240E64 8E06000C */  lw        $a2, 0xc($s0)
/* A9FBA8 80240E68 0C00EA95 */  jal       npc_move_heading
/* A9FBAC 80240E6C 0200202D */   daddu    $a0, $s0, $zero
/* A9FBB0 80240E70 0809039F */  j         .L80240E7C
/* A9FBB4 80240E74 0000902D */   daddu    $s2, $zero, $zero
.L80240E78:
/* A9FBB8 80240E78 0000902D */  daddu     $s2, $zero, $zero
.L80240E7C:
/* A9FBBC 80240E7C C600001C */  lwc1      $f0, 0x1c($s0)
/* A9FBC0 80240E80 44801000 */  mtc1      $zero, $f2
/* A9FBC4 80240E84 44801800 */  mtc1      $zero, $f3
/* A9FBC8 80240E88 46000021 */  cvt.d.s   $f0, $f0
/* A9FBCC 80240E8C 4622003C */  c.lt.d    $f0, $f2
/* A9FBD0 80240E90 00000000 */  nop
/* A9FBD4 80240E94 45000028 */  bc1f      .L80240F38
/* A9FBD8 80240E98 27A50020 */   addiu    $a1, $sp, 0x20
/* A9FBDC 80240E9C 27A60024 */  addiu     $a2, $sp, 0x24
/* A9FBE0 80240EA0 27A2002C */  addiu     $v0, $sp, 0x2c
/* A9FBE4 80240EA4 C602003C */  lwc1      $f2, 0x3c($s0)
/* A9FBE8 80240EA8 C6060038 */  lwc1      $f6, 0x38($s0)
/* A9FBEC 80240EAC 3C01402A */  lui       $at, 0x402a
/* A9FBF0 80240EB0 4481A800 */  mtc1      $at, $f21
/* A9FBF4 80240EB4 4480A000 */  mtc1      $zero, $f20
/* A9FBF8 80240EB8 460010A1 */  cvt.d.s   $f2, $f2
/* A9FBFC 80240EBC 46341080 */  add.d     $f2, $f2, $f20
/* A9FC00 80240EC0 C600001C */  lwc1      $f0, 0x1c($s0)
/* A9FC04 80240EC4 C6040040 */  lwc1      $f4, 0x40($s0)
/* A9FC08 80240EC8 46000005 */  abs.s     $f0, $f0
/* A9FC0C 80240ECC E7A40028 */  swc1      $f4, 0x28($sp)
/* A9FC10 80240ED0 3C014030 */  lui       $at, 0x4030
/* A9FC14 80240ED4 44812800 */  mtc1      $at, $f5
/* A9FC18 80240ED8 44802000 */  mtc1      $zero, $f4
/* A9FC1C 80240EDC 46000021 */  cvt.d.s   $f0, $f0
/* A9FC20 80240EE0 E7A60020 */  swc1      $f6, 0x20($sp)
/* A9FC24 80240EE4 46240000 */  add.d     $f0, $f0, $f4
/* A9FC28 80240EE8 462010A0 */  cvt.s.d   $f2, $f2
/* A9FC2C 80240EEC E7A20024 */  swc1      $f2, 0x24($sp)
/* A9FC30 80240EF0 46200020 */  cvt.s.d   $f0, $f0
/* A9FC34 80240EF4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* A9FC38 80240EF8 AFA20010 */  sw        $v0, 0x10($sp)
/* A9FC3C 80240EFC 8E040080 */  lw        $a0, 0x80($s0)
/* A9FC40 80240F00 0C0372DF */  jal       npc_raycast_down_sides
/* A9FC44 80240F04 27A70028 */   addiu    $a3, $sp, 0x28
/* A9FC48 80240F08 1040000B */  beqz      $v0, .L80240F38
/* A9FC4C 80240F0C 00000000 */   nop
/* A9FC50 80240F10 C600001C */  lwc1      $f0, 0x1c($s0)
/* A9FC54 80240F14 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A9FC58 80240F18 46000005 */  abs.s     $f0, $f0
/* A9FC5C 80240F1C 46000021 */  cvt.d.s   $f0, $f0
/* A9FC60 80240F20 46340000 */  add.d     $f0, $f0, $f20
/* A9FC64 80240F24 460010A1 */  cvt.d.s   $f2, $f2
/* A9FC68 80240F28 4620103E */  c.le.d    $f2, $f0
/* A9FC6C 80240F2C 00000000 */  nop
/* A9FC70 80240F30 45030001 */  bc1tl     .L80240F38
/* A9FC74 80240F34 24120001 */   addiu    $s2, $zero, 1
.L80240F38:
/* A9FC78 80240F38 56400008 */  bnel      $s2, $zero, .L80240F5C
/* A9FC7C 80240F3C 2414000A */   addiu    $s4, $zero, 0xa
/* A9FC80 80240F40 C604003C */  lwc1      $f4, 0x3c($s0)
/* A9FC84 80240F44 C600001C */  lwc1      $f0, 0x1c($s0)
/* A9FC88 80240F48 46002100 */  add.s     $f4, $f4, $f0
/* A9FC8C 80240F4C C6020014 */  lwc1      $f2, 0x14($s0)
/* A9FC90 80240F50 46020001 */  sub.s     $f0, $f0, $f2
/* A9FC94 80240F54 E604003C */  swc1      $f4, 0x3c($s0)
/* A9FC98 80240F58 E600001C */  swc1      $f0, 0x1c($s0)
.L80240F5C:
/* A9FC9C 80240F5C 9602008E */  lhu       $v0, 0x8e($s0)
/* A9FCA0 80240F60 2442FFFF */  addiu     $v0, $v0, -1
/* A9FCA4 80240F64 A602008E */  sh        $v0, 0x8e($s0)
/* A9FCA8 80240F68 00021400 */  sll       $v0, $v0, 0x10
/* A9FCAC 80240F6C 58400001 */  blezl     $v0, .L80240F74
/* A9FCB0 80240F70 2414000B */   addiu    $s4, $zero, 0xb
.L80240F74:
/* A9FCB4 80240F74 12800024 */  beqz      $s4, .L80241008
/* A9FCB8 80240F78 00000000 */   nop
/* A9FCBC 80240F7C AFA00010 */  sw        $zero, 0x10($sp)
/* A9FCC0 80240F80 AFA00014 */  sw        $zero, 0x14($sp)
/* A9FCC4 80240F84 8E050038 */  lw        $a1, 0x38($s0)
/* A9FCC8 80240F88 8E06003C */  lw        $a2, 0x3c($s0)
/* A9FCCC 80240F8C 8E070040 */  lw        $a3, 0x40($s0)
/* A9FCD0 80240F90 0C01BECC */  jal       fx_walk
/* A9FCD4 80240F94 24040002 */   addiu    $a0, $zero, 2
/* A9FCD8 80240F98 3C01C47A */  lui       $at, 0xc47a
/* A9FCDC 80240F9C 44810000 */  mtc1      $at, $f0
/* A9FCE0 80240FA0 AE20006C */  sw        $zero, 0x6c($s1)
/* A9FCE4 80240FA4 8E020000 */  lw        $v0, ($s0)
/* A9FCE8 80240FA8 0200202D */  daddu     $a0, $s0, $zero
/* A9FCEC 80240FAC AE000038 */  sw        $zero, 0x38($s0)
/* A9FCF0 80240FB0 AE000040 */  sw        $zero, 0x40($s0)
/* A9FCF4 80240FB4 34420002 */  ori       $v0, $v0, 2
/* A9FCF8 80240FB8 E600003C */  swc1      $f0, 0x3c($s0)
/* A9FCFC 80240FBC 0C00EAFF */  jal       disable_npc_shadow
/* A9FD00 80240FC0 AE020000 */   sw       $v0, ($s0)
/* A9FD04 80240FC4 0260202D */  daddu     $a0, $s3, $zero
/* A9FD08 80240FC8 3C05FE36 */  lui       $a1, 0xfe36
/* A9FD0C 80240FCC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9FD10 80240FD0 24060001 */  addiu     $a2, $zero, 1
/* A9FD14 80240FD4 8E020000 */  lw        $v0, ($s0)
/* A9FD18 80240FD8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A9FD1C 80240FDC 00431024 */  and       $v0, $v0, $v1
/* A9FD20 80240FE0 AE020000 */  sw        $v0, ($s0)
/* A9FD24 80240FE4 8E220000 */  lw        $v0, ($s1)
/* A9FD28 80240FE8 3C031F00 */  lui       $v1, 0x1f00
/* A9FD2C 80240FEC 00431025 */  or        $v0, $v0, $v1
/* A9FD30 80240FF0 AE220000 */  sw        $v0, ($s1)
/* A9FD34 80240FF4 AC800070 */  sw        $zero, 0x70($a0)
.L80240FF8:
/* A9FD38 80240FF8 0C0B2026 */  jal       set_variable
/* A9FD3C 80240FFC 00000000 */   nop
/* A9FD40 80241000 0809040E */  j         .L80241038
/* A9FD44 80241004 24020002 */   addiu    $v0, $zero, 2
.L80241008:
/* A9FD48 80241008 8E220070 */  lw        $v0, 0x70($s1)
/* A9FD4C 8024100C 30420001 */  andi      $v0, $v0, 1
/* A9FD50 80241010 10400009 */  beqz      $v0, .L80241038
/* A9FD54 80241014 0000102D */   daddu    $v0, $zero, $zero
/* A9FD58 80241018 C600004C */  lwc1      $f0, 0x4c($s0)
/* A9FD5C 8024101C 3C01404E */  lui       $at, 0x404e
/* A9FD60 80241020 44811800 */  mtc1      $at, $f3
/* A9FD64 80241024 44801000 */  mtc1      $zero, $f2
/* A9FD68 80241028 46000021 */  cvt.d.s   $f0, $f0
/* A9FD6C 8024102C 46220000 */  add.d     $f0, $f0, $f2
/* A9FD70 80241030 46200020 */  cvt.s.d   $f0, $f0
/* A9FD74 80241034 E600004C */  swc1      $f0, 0x4c($s0)
.L80241038:
/* A9FD78 80241038 8FBF0044 */  lw        $ra, 0x44($sp)
/* A9FD7C 8024103C 8FB40040 */  lw        $s4, 0x40($sp)
/* A9FD80 80241040 8FB3003C */  lw        $s3, 0x3c($sp)
/* A9FD84 80241044 8FB20038 */  lw        $s2, 0x38($sp)
/* A9FD88 80241048 8FB10034 */  lw        $s1, 0x34($sp)
/* A9FD8C 8024104C 8FB00030 */  lw        $s0, 0x30($sp)
/* A9FD90 80241050 D7B80058 */  ldc1      $f24, 0x58($sp)
/* A9FD94 80241054 D7B60050 */  ldc1      $f22, 0x50($sp)
/* A9FD98 80241058 D7B40048 */  ldc1      $f20, 0x48($sp)
/* A9FD9C 8024105C 03E00008 */  jr        $ra
/* A9FDA0 80241060 27BD0060 */   addiu    $sp, $sp, 0x60
