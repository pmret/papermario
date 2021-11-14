.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802439F0_A6AAF0
.double 180.0

dlabel D_802439F8_A6AAF8
.double 90.0

dlabel D_80243A00_A6AB00
.double 1.2

.section .text

glabel func_80240B78_A67C78
/* A67C78 80240B78 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* A67C7C 80240B7C AFB3003C */  sw        $s3, 0x3c($sp)
/* A67C80 80240B80 0080982D */  daddu     $s3, $a0, $zero
/* A67C84 80240B84 AFB40040 */  sw        $s4, 0x40($sp)
/* A67C88 80240B88 0000A02D */  daddu     $s4, $zero, $zero
/* A67C8C 80240B8C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A67C90 80240B90 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A67C94 80240B94 3C04800B */  lui       $a0, %hi(gCameras)
/* A67C98 80240B98 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A67C9C 80240B9C AFBF0044 */  sw        $ra, 0x44($sp)
/* A67CA0 80240BA0 AFB20038 */  sw        $s2, 0x38($sp)
/* A67CA4 80240BA4 AFB10034 */  sw        $s1, 0x34($sp)
/* A67CA8 80240BA8 AFB00030 */  sw        $s0, 0x30($sp)
/* A67CAC 80240BAC F7B80058 */  sdc1      $f24, 0x58($sp)
/* A67CB0 80240BB0 F7B60050 */  sdc1      $f22, 0x50($sp)
/* A67CB4 80240BB4 F7B40048 */  sdc1      $f20, 0x48($sp)
/* A67CB8 80240BB8 8E710148 */  lw        $s1, 0x148($s3)
/* A67CBC 80240BBC 00031080 */  sll       $v0, $v1, 2
/* A67CC0 80240BC0 00431021 */  addu      $v0, $v0, $v1
/* A67CC4 80240BC4 00021080 */  sll       $v0, $v0, 2
/* A67CC8 80240BC8 00431023 */  subu      $v0, $v0, $v1
/* A67CCC 80240BCC 000218C0 */  sll       $v1, $v0, 3
/* A67CD0 80240BD0 00431021 */  addu      $v0, $v0, $v1
/* A67CD4 80240BD4 000210C0 */  sll       $v0, $v0, 3
/* A67CD8 80240BD8 10A00002 */  beqz      $a1, .L80240BE4
/* A67CDC 80240BDC 00449021 */   addu     $s2, $v0, $a0
/* A67CE0 80240BE0 AE600070 */  sw        $zero, 0x70($s3)
.L80240BE4:
/* A67CE4 80240BE4 0C00FB5A */  jal       get_enemy_safe
/* A67CE8 80240BE8 86240008 */   lh       $a0, 8($s1)
/* A67CEC 80240BEC 14400006 */  bnez      $v0, .L80240C08
/* A67CF0 80240BF0 24020005 */   addiu    $v0, $zero, 5
/* A67CF4 80240BF4 0260202D */  daddu     $a0, $s3, $zero
/* A67CF8 80240BF8 3C05FE36 */  lui       $a1, 0xfe36
/* A67CFC 80240BFC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A67D00 80240C00 080903DA */  j         .L80240F68
/* A67D04 80240C04 0000302D */   daddu    $a2, $zero, $zero
.L80240C08:
/* A67D08 80240C08 8E23006C */  lw        $v1, 0x6c($s1)
/* A67D0C 80240C0C 14620005 */  bne       $v1, $v0, .L80240C24
/* A67D10 80240C10 0260202D */   daddu    $a0, $s3, $zero
/* A67D14 80240C14 3C05FE36 */  lui       $a1, 0xfe36
/* A67D18 80240C18 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A67D1C 80240C1C 080903DA */  j         .L80240F68
/* A67D20 80240C20 0000302D */   daddu    $a2, $zero, $zero
.L80240C24:
/* A67D24 80240C24 86240008 */  lh        $a0, 8($s1)
/* A67D28 80240C28 0C00FB5A */  jal       get_enemy_safe
/* A67D2C 80240C2C 00000000 */   nop
/* A67D30 80240C30 14400005 */  bnez      $v0, .L80240C48
/* A67D34 80240C34 0260202D */   daddu    $a0, $s3, $zero
/* A67D38 80240C38 3C05FE36 */  lui       $a1, 0xfe36
/* A67D3C 80240C3C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A67D40 80240C40 080903DA */  j         .L80240F68
/* A67D44 80240C44 0000302D */   daddu    $a2, $zero, $zero
.L80240C48:
/* A67D48 80240C48 86240008 */  lh        $a0, 8($s1)
/* A67D4C 80240C4C 0C00EABB */  jal       get_npc_unsafe
/* A67D50 80240C50 00000000 */   nop
/* A67D54 80240C54 8E630070 */  lw        $v1, 0x70($s3)
/* A67D58 80240C58 10600006 */  beqz      $v1, .L80240C74
/* A67D5C 80240C5C 0040802D */   daddu    $s0, $v0, $zero
/* A67D60 80240C60 24020001 */  addiu     $v0, $zero, 1
/* A67D64 80240C64 1062003F */  beq       $v1, $v0, .L80240D64
/* A67D68 80240C68 0000102D */   daddu    $v0, $zero, $zero
/* A67D6C 80240C6C 080903EA */  j         .L80240FA8
/* A67D70 80240C70 00000000 */   nop
.L80240C74:
/* A67D74 80240C74 AFA00010 */  sw        $zero, 0x10($sp)
/* A67D78 80240C78 AFA00014 */  sw        $zero, 0x14($sp)
/* A67D7C 80240C7C 8E050038 */  lw        $a1, 0x38($s0)
/* A67D80 80240C80 8E06003C */  lw        $a2, 0x3c($s0)
/* A67D84 80240C84 8E070040 */  lw        $a3, 0x40($s0)
/* A67D88 80240C88 0C01BECC */  jal       fx_walk
/* A67D8C 80240C8C 24040002 */   addiu    $a0, $zero, 2
/* A67D90 80240C90 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A67D94 80240C94 0C00A6C9 */  jal       clamp_angle
/* A67D98 80240C98 00000000 */   nop
/* A67D9C 80240C9C 3C018024 */  lui       $at, %hi(D_802439F0_A6AAF0)
/* A67DA0 80240CA0 D43839F0 */  ldc1      $f24, %lo(D_802439F0_A6AAF0)($at)
/* A67DA4 80240CA4 46000521 */  cvt.d.s   $f20, $f0
/* A67DA8 80240CA8 4638A300 */  add.d     $f12, $f20, $f24
/* A67DAC 80240CAC 3C018024 */  lui       $at, %hi(D_802439F8_A6AAF8)
/* A67DB0 80240CB0 D43639F8 */  ldc1      $f22, %lo(D_802439F8_A6AAF8)($at)
/* A67DB4 80240CB4 0C00A6C9 */  jal       clamp_angle
/* A67DB8 80240CB8 46206320 */   cvt.s.d  $f12, $f12
/* A67DBC 80240CBC 4636A500 */  add.d     $f20, $f20, $f22
/* A67DC0 80240CC0 4620A320 */  cvt.s.d   $f12, $f20
/* A67DC4 80240CC4 0C00A6C9 */  jal       clamp_angle
/* A67DC8 80240CC8 46000506 */   mov.s    $f20, $f0
/* A67DCC 80240CCC 4600A521 */  cvt.d.s   $f20, $f20
/* A67DD0 80240CD0 4636A500 */  add.d     $f20, $f20, $f22
/* A67DD4 80240CD4 46000586 */  mov.s     $f22, $f0
/* A67DD8 80240CD8 0C00A6C9 */  jal       clamp_angle
/* A67DDC 80240CDC 4620A320 */   cvt.s.d  $f12, $f20
/* A67DE0 80240CE0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A67DE4 80240CE4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A67DE8 80240CE8 C64C006C */  lwc1      $f12, 0x6c($s2)
/* A67DEC 80240CEC C44E0084 */  lwc1      $f14, 0x84($v0)
/* A67DF0 80240CF0 0C00A70A */  jal       get_clamped_angle_diff
/* A67DF4 80240CF4 46000506 */   mov.s    $f20, $f0
/* A67DF8 80240CF8 0C00A6C9 */  jal       clamp_angle
/* A67DFC 80240CFC 46000306 */   mov.s    $f12, $f0
/* A67E00 80240D00 46000021 */  cvt.d.s   $f0, $f0
/* A67E04 80240D04 4638003C */  c.lt.d    $f0, $f24
/* A67E08 80240D08 00000000 */  nop
/* A67E0C 80240D0C 45020002 */  bc1fl     .L80240D18
/* A67E10 80240D10 E614000C */   swc1     $f20, 0xc($s0)
/* A67E14 80240D14 E616000C */  swc1      $f22, 0xc($s0)
.L80240D18:
/* A67E18 80240D18 C6000018 */  lwc1      $f0, 0x18($s0)
/* A67E1C 80240D1C 3C018024 */  lui       $at, %hi(D_80243A00_A6AB00)
/* A67E20 80240D20 D4223A00 */  ldc1      $f2, %lo(D_80243A00_A6AB00)($at)
/* A67E24 80240D24 46000021 */  cvt.d.s   $f0, $f0
/* A67E28 80240D28 46220002 */  mul.d     $f0, $f0, $f2
/* A67E2C 80240D2C 00000000 */  nop
/* A67E30 80240D30 3C013F66 */  lui       $at, 0x3f66
/* A67E34 80240D34 34216666 */  ori       $at, $at, 0x6666
/* A67E38 80240D38 44812000 */  mtc1      $at, $f4
/* A67E3C 80240D3C 2402001E */  addiu     $v0, $zero, 0x1e
/* A67E40 80240D40 A602008E */  sh        $v0, 0x8e($s0)
/* A67E44 80240D44 3C014120 */  lui       $at, 0x4120
/* A67E48 80240D48 44811000 */  mtc1      $at, $f2
/* A67E4C 80240D4C 24020001 */  addiu     $v0, $zero, 1
/* A67E50 80240D50 E6040014 */  swc1      $f4, 0x14($s0)
/* A67E54 80240D54 E602001C */  swc1      $f2, 0x1c($s0)
/* A67E58 80240D58 46200020 */  cvt.s.d   $f0, $f0
/* A67E5C 80240D5C E6000018 */  swc1      $f0, 0x18($s0)
/* A67E60 80240D60 AE620070 */  sw        $v0, 0x70($s3)
.L80240D64:
/* A67E64 80240D64 C6000038 */  lwc1      $f0, 0x38($s0)
/* A67E68 80240D68 C602003C */  lwc1      $f2, 0x3c($s0)
/* A67E6C 80240D6C C6040040 */  lwc1      $f4, 0x40($s0)
/* A67E70 80240D70 C6060018 */  lwc1      $f6, 0x18($s0)
/* A67E74 80240D74 0000202D */  daddu     $a0, $zero, $zero
/* A67E78 80240D78 E7A00020 */  swc1      $f0, 0x20($sp)
/* A67E7C 80240D7C E7A20024 */  swc1      $f2, 0x24($sp)
/* A67E80 80240D80 E7A40028 */  swc1      $f4, 0x28($sp)
/* A67E84 80240D84 E7A60010 */  swc1      $f6, 0x10($sp)
/* A67E88 80240D88 C600000C */  lwc1      $f0, 0xc($s0)
/* A67E8C 80240D8C 27A50020 */  addiu     $a1, $sp, 0x20
/* A67E90 80240D90 E7A00014 */  swc1      $f0, 0x14($sp)
/* A67E94 80240D94 860200A6 */  lh        $v0, 0xa6($s0)
/* A67E98 80240D98 27A60024 */  addiu     $a2, $sp, 0x24
/* A67E9C 80240D9C 44820000 */  mtc1      $v0, $f0
/* A67EA0 80240DA0 00000000 */  nop
/* A67EA4 80240DA4 46800020 */  cvt.s.w   $f0, $f0
/* A67EA8 80240DA8 E7A00018 */  swc1      $f0, 0x18($sp)
/* A67EAC 80240DAC 860200A8 */  lh        $v0, 0xa8($s0)
/* A67EB0 80240DB0 27A70028 */  addiu     $a3, $sp, 0x28
/* A67EB4 80240DB4 44820000 */  mtc1      $v0, $f0
/* A67EB8 80240DB8 00000000 */  nop
/* A67EBC 80240DBC 46800020 */  cvt.s.w   $f0, $f0
/* A67EC0 80240DC0 0C037711 */  jal       npc_test_move_simple_with_slipping
/* A67EC4 80240DC4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* A67EC8 80240DC8 54400007 */  bnel      $v0, $zero, .L80240DE8
/* A67ECC 80240DCC 24140001 */   addiu    $s4, $zero, 1
/* A67ED0 80240DD0 8E050018 */  lw        $a1, 0x18($s0)
/* A67ED4 80240DD4 8E06000C */  lw        $a2, 0xc($s0)
/* A67ED8 80240DD8 0C00EA95 */  jal       npc_move_heading
/* A67EDC 80240DDC 0200202D */   daddu    $a0, $s0, $zero
/* A67EE0 80240DE0 0809037B */  j         .L80240DEC
/* A67EE4 80240DE4 0000902D */   daddu    $s2, $zero, $zero
.L80240DE8:
/* A67EE8 80240DE8 0000902D */  daddu     $s2, $zero, $zero
.L80240DEC:
/* A67EEC 80240DEC C600001C */  lwc1      $f0, 0x1c($s0)
/* A67EF0 80240DF0 44801000 */  mtc1      $zero, $f2
/* A67EF4 80240DF4 44801800 */  mtc1      $zero, $f3
/* A67EF8 80240DF8 46000021 */  cvt.d.s   $f0, $f0
/* A67EFC 80240DFC 4622003C */  c.lt.d    $f0, $f2
/* A67F00 80240E00 00000000 */  nop
/* A67F04 80240E04 45000028 */  bc1f      .L80240EA8
/* A67F08 80240E08 27A50020 */   addiu    $a1, $sp, 0x20
/* A67F0C 80240E0C 27A60024 */  addiu     $a2, $sp, 0x24
/* A67F10 80240E10 27A2002C */  addiu     $v0, $sp, 0x2c
/* A67F14 80240E14 C602003C */  lwc1      $f2, 0x3c($s0)
/* A67F18 80240E18 C6060038 */  lwc1      $f6, 0x38($s0)
/* A67F1C 80240E1C 3C01402A */  lui       $at, 0x402a
/* A67F20 80240E20 4481A800 */  mtc1      $at, $f21
/* A67F24 80240E24 4480A000 */  mtc1      $zero, $f20
/* A67F28 80240E28 460010A1 */  cvt.d.s   $f2, $f2
/* A67F2C 80240E2C 46341080 */  add.d     $f2, $f2, $f20
/* A67F30 80240E30 C600001C */  lwc1      $f0, 0x1c($s0)
/* A67F34 80240E34 C6040040 */  lwc1      $f4, 0x40($s0)
/* A67F38 80240E38 46000005 */  abs.s     $f0, $f0
/* A67F3C 80240E3C E7A40028 */  swc1      $f4, 0x28($sp)
/* A67F40 80240E40 3C014030 */  lui       $at, 0x4030
/* A67F44 80240E44 44812800 */  mtc1      $at, $f5
/* A67F48 80240E48 44802000 */  mtc1      $zero, $f4
/* A67F4C 80240E4C 46000021 */  cvt.d.s   $f0, $f0
/* A67F50 80240E50 E7A60020 */  swc1      $f6, 0x20($sp)
/* A67F54 80240E54 46240000 */  add.d     $f0, $f0, $f4
/* A67F58 80240E58 462010A0 */  cvt.s.d   $f2, $f2
/* A67F5C 80240E5C E7A20024 */  swc1      $f2, 0x24($sp)
/* A67F60 80240E60 46200020 */  cvt.s.d   $f0, $f0
/* A67F64 80240E64 E7A0002C */  swc1      $f0, 0x2c($sp)
/* A67F68 80240E68 AFA20010 */  sw        $v0, 0x10($sp)
/* A67F6C 80240E6C 8E040080 */  lw        $a0, 0x80($s0)
/* A67F70 80240E70 0C0372DF */  jal       npc_raycast_down_sides
/* A67F74 80240E74 27A70028 */   addiu    $a3, $sp, 0x28
/* A67F78 80240E78 1040000B */  beqz      $v0, .L80240EA8
/* A67F7C 80240E7C 00000000 */   nop
/* A67F80 80240E80 C600001C */  lwc1      $f0, 0x1c($s0)
/* A67F84 80240E84 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A67F88 80240E88 46000005 */  abs.s     $f0, $f0
/* A67F8C 80240E8C 46000021 */  cvt.d.s   $f0, $f0
/* A67F90 80240E90 46340000 */  add.d     $f0, $f0, $f20
/* A67F94 80240E94 460010A1 */  cvt.d.s   $f2, $f2
/* A67F98 80240E98 4620103E */  c.le.d    $f2, $f0
/* A67F9C 80240E9C 00000000 */  nop
/* A67FA0 80240EA0 45030001 */  bc1tl     .L80240EA8
/* A67FA4 80240EA4 24120001 */   addiu    $s2, $zero, 1
.L80240EA8:
/* A67FA8 80240EA8 56400008 */  bnel      $s2, $zero, .L80240ECC
/* A67FAC 80240EAC 2414000A */   addiu    $s4, $zero, 0xa
/* A67FB0 80240EB0 C604003C */  lwc1      $f4, 0x3c($s0)
/* A67FB4 80240EB4 C600001C */  lwc1      $f0, 0x1c($s0)
/* A67FB8 80240EB8 46002100 */  add.s     $f4, $f4, $f0
/* A67FBC 80240EBC C6020014 */  lwc1      $f2, 0x14($s0)
/* A67FC0 80240EC0 46020001 */  sub.s     $f0, $f0, $f2
/* A67FC4 80240EC4 E604003C */  swc1      $f4, 0x3c($s0)
/* A67FC8 80240EC8 E600001C */  swc1      $f0, 0x1c($s0)
.L80240ECC:
/* A67FCC 80240ECC 9602008E */  lhu       $v0, 0x8e($s0)
/* A67FD0 80240ED0 2442FFFF */  addiu     $v0, $v0, -1
/* A67FD4 80240ED4 A602008E */  sh        $v0, 0x8e($s0)
/* A67FD8 80240ED8 00021400 */  sll       $v0, $v0, 0x10
/* A67FDC 80240EDC 58400001 */  blezl     $v0, .L80240EE4
/* A67FE0 80240EE0 2414000B */   addiu    $s4, $zero, 0xb
.L80240EE4:
/* A67FE4 80240EE4 12800024 */  beqz      $s4, .L80240F78
/* A67FE8 80240EE8 00000000 */   nop
/* A67FEC 80240EEC AFA00010 */  sw        $zero, 0x10($sp)
/* A67FF0 80240EF0 AFA00014 */  sw        $zero, 0x14($sp)
/* A67FF4 80240EF4 8E050038 */  lw        $a1, 0x38($s0)
/* A67FF8 80240EF8 8E06003C */  lw        $a2, 0x3c($s0)
/* A67FFC 80240EFC 8E070040 */  lw        $a3, 0x40($s0)
/* A68000 80240F00 0C01BECC */  jal       fx_walk
/* A68004 80240F04 24040002 */   addiu    $a0, $zero, 2
/* A68008 80240F08 3C01C47A */  lui       $at, 0xc47a
/* A6800C 80240F0C 44810000 */  mtc1      $at, $f0
/* A68010 80240F10 AE20006C */  sw        $zero, 0x6c($s1)
/* A68014 80240F14 8E020000 */  lw        $v0, ($s0)
/* A68018 80240F18 0200202D */  daddu     $a0, $s0, $zero
/* A6801C 80240F1C AE000038 */  sw        $zero, 0x38($s0)
/* A68020 80240F20 AE000040 */  sw        $zero, 0x40($s0)
/* A68024 80240F24 34420002 */  ori       $v0, $v0, 2
/* A68028 80240F28 E600003C */  swc1      $f0, 0x3c($s0)
/* A6802C 80240F2C 0C00EAFF */  jal       disable_npc_shadow
/* A68030 80240F30 AE020000 */   sw       $v0, ($s0)
/* A68034 80240F34 0260202D */  daddu     $a0, $s3, $zero
/* A68038 80240F38 3C05FE36 */  lui       $a1, 0xfe36
/* A6803C 80240F3C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A68040 80240F40 24060001 */  addiu     $a2, $zero, 1
/* A68044 80240F44 8E020000 */  lw        $v0, ($s0)
/* A68048 80240F48 2403F7FF */  addiu     $v1, $zero, -0x801
/* A6804C 80240F4C 00431024 */  and       $v0, $v0, $v1
/* A68050 80240F50 AE020000 */  sw        $v0, ($s0)
/* A68054 80240F54 8E220000 */  lw        $v0, ($s1)
/* A68058 80240F58 3C031F00 */  lui       $v1, 0x1f00
/* A6805C 80240F5C 00431025 */  or        $v0, $v0, $v1
/* A68060 80240F60 AE220000 */  sw        $v0, ($s1)
/* A68064 80240F64 AC800070 */  sw        $zero, 0x70($a0)
.L80240F68:
/* A68068 80240F68 0C0B2026 */  jal       evt_set_variable
/* A6806C 80240F6C 00000000 */   nop
/* A68070 80240F70 080903EA */  j         .L80240FA8
/* A68074 80240F74 24020002 */   addiu    $v0, $zero, 2
.L80240F78:
/* A68078 80240F78 8E220070 */  lw        $v0, 0x70($s1)
/* A6807C 80240F7C 30420001 */  andi      $v0, $v0, 1
/* A68080 80240F80 10400009 */  beqz      $v0, .L80240FA8
/* A68084 80240F84 0000102D */   daddu    $v0, $zero, $zero
/* A68088 80240F88 C600004C */  lwc1      $f0, 0x4c($s0)
/* A6808C 80240F8C 3C01404E */  lui       $at, 0x404e
/* A68090 80240F90 44811800 */  mtc1      $at, $f3
/* A68094 80240F94 44801000 */  mtc1      $zero, $f2
/* A68098 80240F98 46000021 */  cvt.d.s   $f0, $f0
/* A6809C 80240F9C 46220000 */  add.d     $f0, $f0, $f2
/* A680A0 80240FA0 46200020 */  cvt.s.d   $f0, $f0
/* A680A4 80240FA4 E600004C */  swc1      $f0, 0x4c($s0)
.L80240FA8:
/* A680A8 80240FA8 8FBF0044 */  lw        $ra, 0x44($sp)
/* A680AC 80240FAC 8FB40040 */  lw        $s4, 0x40($sp)
/* A680B0 80240FB0 8FB3003C */  lw        $s3, 0x3c($sp)
/* A680B4 80240FB4 8FB20038 */  lw        $s2, 0x38($sp)
/* A680B8 80240FB8 8FB10034 */  lw        $s1, 0x34($sp)
/* A680BC 80240FBC 8FB00030 */  lw        $s0, 0x30($sp)
/* A680C0 80240FC0 D7B80058 */  ldc1      $f24, 0x58($sp)
/* A680C4 80240FC4 D7B60050 */  ldc1      $f22, 0x50($sp)
/* A680C8 80240FC8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* A680CC 80240FCC 03E00008 */  jr        $ra
/* A680D0 80240FD0 27BD0060 */   addiu    $sp, $sp, 0x60
