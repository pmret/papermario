.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD4_EB9A24
/* EB9A24 80240BD4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* EB9A28 80240BD8 AFB5005C */  sw        $s5, 0x5c($sp)
/* EB9A2C 80240BDC 0080A82D */  daddu     $s5, $a0, $zero
/* EB9A30 80240BE0 AFBF0060 */  sw        $ra, 0x60($sp)
/* EB9A34 80240BE4 AFB40058 */  sw        $s4, 0x58($sp)
/* EB9A38 80240BE8 AFB30054 */  sw        $s3, 0x54($sp)
/* EB9A3C 80240BEC AFB20050 */  sw        $s2, 0x50($sp)
/* EB9A40 80240BF0 AFB1004C */  sw        $s1, 0x4c($sp)
/* EB9A44 80240BF4 AFB00048 */  sw        $s0, 0x48($sp)
/* EB9A48 80240BF8 8EB10148 */  lw        $s1, 0x148($s5)
/* EB9A4C 80240BFC 86240008 */  lh        $a0, 8($s1)
/* EB9A50 80240C00 0C00F92F */  jal       func_8003E4BC
/* EB9A54 80240C04 00A0802D */   daddu    $s0, $a1, $zero
/* EB9A58 80240C08 8EA3000C */  lw        $v1, 0xc($s5)
/* EB9A5C 80240C0C 02A0202D */  daddu     $a0, $s5, $zero
/* EB9A60 80240C10 8C650000 */  lw        $a1, ($v1)
/* EB9A64 80240C14 0C0B53A3 */  jal       func_802D4E8C
/* EB9A68 80240C18 0040902D */   daddu    $s2, $v0, $zero
/* EB9A6C 80240C1C AFA00018 */  sw        $zero, 0x18($sp)
/* EB9A70 80240C20 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EB9A74 80240C24 8C630094 */  lw        $v1, 0x94($v1)
/* EB9A78 80240C28 AFA3001C */  sw        $v1, 0x1c($sp)
/* EB9A7C 80240C2C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EB9A80 80240C30 8C630080 */  lw        $v1, 0x80($v1)
/* EB9A84 80240C34 AFA30020 */  sw        $v1, 0x20($sp)
/* EB9A88 80240C38 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EB9A8C 80240C3C 8C630088 */  lw        $v1, 0x88($v1)
/* EB9A90 80240C40 AFA30024 */  sw        $v1, 0x24($sp)
/* EB9A94 80240C44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EB9A98 80240C48 8C63008C */  lw        $v1, 0x8c($v1)
/* EB9A9C 80240C4C AFA30028 */  sw        $v1, 0x28($sp)
/* EB9AA0 80240C50 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EB9AA4 80240C54 3C014282 */  lui       $at, 0x4282
/* EB9AA8 80240C58 44810000 */  mtc1      $at, $f0
/* EB9AAC 80240C5C 8C630090 */  lw        $v1, 0x90($v1)
/* EB9AB0 80240C60 E7A00030 */  swc1      $f0, 0x30($sp)
/* EB9AB4 80240C64 A7A00034 */  sh        $zero, 0x34($sp)
/* EB9AB8 80240C68 AFA3002C */  sw        $v1, 0x2c($sp)
/* EB9ABC 80240C6C C6400038 */  lwc1      $f0, 0x38($s2)
/* EB9AC0 80240C70 E6200108 */  swc1      $f0, 0x108($s1)
/* EB9AC4 80240C74 C640003C */  lwc1      $f0, 0x3c($s2)
/* EB9AC8 80240C78 27B40018 */  addiu     $s4, $sp, 0x18
/* EB9ACC 80240C7C E620010C */  swc1      $f0, 0x10c($s1)
/* EB9AD0 80240C80 3C0138D1 */  lui       $at, 0x38d1
/* EB9AD4 80240C84 3421B717 */  ori       $at, $at, 0xb717
/* EB9AD8 80240C88 44810000 */  mtc1      $at, $f0
/* EB9ADC 80240C8C C6420040 */  lwc1      $f2, 0x40($s2)
/* EB9AE0 80240C90 0040982D */  daddu     $s3, $v0, $zero
/* EB9AE4 80240C94 E6200114 */  swc1      $f0, 0x114($s1)
/* EB9AE8 80240C98 E6200118 */  swc1      $f0, 0x118($s1)
/* EB9AEC 80240C9C 16000005 */  bnez      $s0, .L80240CB4
/* EB9AF0 80240CA0 E6220110 */   swc1     $f2, 0x110($s1)
/* EB9AF4 80240CA4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EB9AF8 80240CA8 30420004 */  andi      $v0, $v0, 4
/* EB9AFC 80240CAC 10400044 */  beqz      $v0, .L80240DC0
/* EB9B00 80240CB0 00000000 */   nop
.L80240CB4:
/* EB9B04 80240CB4 2404F7FF */  addiu     $a0, $zero, -0x801
/* EB9B08 80240CB8 AEA00070 */  sw        $zero, 0x70($s5)
/* EB9B0C 80240CBC A640008E */  sh        $zero, 0x8e($s2)
/* EB9B10 80240CC0 8E2200CC */  lw        $v0, 0xcc($s1)
/* EB9B14 80240CC4 8E430000 */  lw        $v1, ($s2)
/* EB9B18 80240CC8 8C420000 */  lw        $v0, ($v0)
/* EB9B1C 80240CCC 00641824 */  and       $v1, $v1, $a0
/* EB9B20 80240CD0 AE430000 */  sw        $v1, ($s2)
/* EB9B24 80240CD4 AE420028 */  sw        $v0, 0x28($s2)
/* EB9B28 80240CD8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EB9B2C 80240CDC 8C420098 */  lw        $v0, 0x98($v0)
/* EB9B30 80240CE0 54400005 */  bnel      $v0, $zero, .L80240CF8
/* EB9B34 80240CE4 2402FDFF */   addiu    $v0, $zero, -0x201
/* EB9B38 80240CE8 34620200 */  ori       $v0, $v1, 0x200
/* EB9B3C 80240CEC 2403FFF7 */  addiu     $v1, $zero, -9
/* EB9B40 80240CF0 08090340 */  j         .L80240D00
/* EB9B44 80240CF4 00431024 */   and      $v0, $v0, $v1
.L80240CF8:
/* EB9B48 80240CF8 00621024 */  and       $v0, $v1, $v0
/* EB9B4C 80240CFC 34420008 */  ori       $v0, $v0, 8
.L80240D00:
/* EB9B50 80240D00 AE420000 */  sw        $v0, ($s2)
/* EB9B54 80240D04 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EB9B58 80240D08 30420004 */  andi      $v0, $v0, 4
/* EB9B5C 80240D0C 10400008 */  beqz      $v0, .L80240D30
/* EB9B60 80240D10 24020063 */   addiu    $v0, $zero, 0x63
/* EB9B64 80240D14 AEA20070 */  sw        $v0, 0x70($s5)
/* EB9B68 80240D18 AEA00074 */  sw        $zero, 0x74($s5)
/* EB9B6C 80240D1C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EB9B70 80240D20 2403FFFB */  addiu     $v1, $zero, -5
/* EB9B74 80240D24 00431024 */  and       $v0, $v0, $v1
/* EB9B78 80240D28 08090357 */  j         .L80240D5C
/* EB9B7C 80240D2C AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240D30:
/* EB9B80 80240D30 8E220000 */  lw        $v0, ($s1)
/* EB9B84 80240D34 3C034000 */  lui       $v1, 0x4000
/* EB9B88 80240D38 00431024 */  and       $v0, $v0, $v1
/* EB9B8C 80240D3C 10400007 */  beqz      $v0, .L80240D5C
/* EB9B90 80240D40 3C03BFFF */   lui      $v1, 0xbfff
/* EB9B94 80240D44 2402000C */  addiu     $v0, $zero, 0xc
/* EB9B98 80240D48 AEA20070 */  sw        $v0, 0x70($s5)
/* EB9B9C 80240D4C 8E220000 */  lw        $v0, ($s1)
/* EB9BA0 80240D50 3463FFFF */  ori       $v1, $v1, 0xffff
/* EB9BA4 80240D54 00431024 */  and       $v0, $v0, $v1
/* EB9BA8 80240D58 AE220000 */  sw        $v0, ($s1)
.L80240D5C:
/* EB9BAC 80240D5C 27A50038 */  addiu     $a1, $sp, 0x38
/* EB9BB0 80240D60 27A6003C */  addiu     $a2, $sp, 0x3c
/* EB9BB4 80240D64 C6400038 */  lwc1      $f0, 0x38($s2)
/* EB9BB8 80240D68 864200A8 */  lh        $v0, 0xa8($s2)
/* EB9BBC 80240D6C 3C0142C8 */  lui       $at, 0x42c8
/* EB9BC0 80240D70 44812000 */  mtc1      $at, $f4
/* EB9BC4 80240D74 44823000 */  mtc1      $v0, $f6
/* EB9BC8 80240D78 00000000 */  nop
/* EB9BCC 80240D7C 468031A0 */  cvt.s.w   $f6, $f6
/* EB9BD0 80240D80 27A20044 */  addiu     $v0, $sp, 0x44
/* EB9BD4 80240D84 E7A00038 */  swc1      $f0, 0x38($sp)
/* EB9BD8 80240D88 C640003C */  lwc1      $f0, 0x3c($s2)
/* EB9BDC 80240D8C C6420040 */  lwc1      $f2, 0x40($s2)
/* EB9BE0 80240D90 46060000 */  add.s     $f0, $f0, $f6
/* EB9BE4 80240D94 E7A40044 */  swc1      $f4, 0x44($sp)
/* EB9BE8 80240D98 E7A20040 */  swc1      $f2, 0x40($sp)
/* EB9BEC 80240D9C E7A0003C */  swc1      $f0, 0x3c($sp)
/* EB9BF0 80240DA0 AFA20010 */  sw        $v0, 0x10($sp)
/* EB9BF4 80240DA4 8E440080 */  lw        $a0, 0x80($s2)
/* EB9BF8 80240DA8 0C03908F */  jal       func_800E423C
/* EB9BFC 80240DAC 27A70040 */   addiu    $a3, $sp, 0x40
/* EB9C00 80240DB0 10400003 */  beqz      $v0, .L80240DC0
/* EB9C04 80240DB4 00000000 */   nop
/* EB9C08 80240DB8 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* EB9C0C 80240DBC E640003C */  swc1      $f0, 0x3c($s2)
.L80240DC0:
/* EB9C10 80240DC0 8EA30070 */  lw        $v1, 0x70($s5)
/* EB9C14 80240DC4 2C620064 */  sltiu     $v0, $v1, 0x64
/* EB9C18 80240DC8 10400042 */  beqz      $v0, .L80240ED4
/* EB9C1C 80240DCC 00031080 */   sll      $v0, $v1, 2
/* EB9C20 80240DD0 3C018025 */  lui       $at, %hi(jtbl_80249200_EC2050)
/* EB9C24 80240DD4 00220821 */  addu      $at, $at, $v0
/* EB9C28 80240DD8 8C229200 */  lw        $v0, %lo(jtbl_80249200_EC2050)($at)
/* EB9C2C 80240DDC 00400008 */  jr        $v0
/* EB9C30 80240DE0 00000000 */   nop
glabel L80240DE4_EB9C34
/* EB9C34 80240DE4 02A0202D */  daddu     $a0, $s5, $zero
/* EB9C38 80240DE8 0260282D */  daddu     $a1, $s3, $zero
/* EB9C3C 80240DEC 0C090010 */  jal       func_80240040_EB8E90
/* EB9C40 80240DF0 0280302D */   daddu    $a2, $s4, $zero
glabel L80240DF4_EB9C44
/* EB9C44 80240DF4 02A0202D */  daddu     $a0, $s5, $zero
/* EB9C48 80240DF8 0260282D */  daddu     $a1, $s3, $zero
/* EB9C4C 80240DFC 0C090066 */  jal       func_80240198_EB8FE8
/* EB9C50 80240E00 0280302D */   daddu    $a2, $s4, $zero
/* EB9C54 80240E04 080903B5 */  j         .L80240ED4
/* EB9C58 80240E08 00000000 */   nop
glabel L80240E0C_EB9C5C
/* EB9C5C 80240E0C 02A0202D */  daddu     $a0, $s5, $zero
/* EB9C60 80240E10 0260282D */  daddu     $a1, $s3, $zero
/* EB9C64 80240E14 0C090110 */  jal       func_80240440_EB9290
/* EB9C68 80240E18 0280302D */   daddu    $a2, $s4, $zero
glabel L80240E1C_EB9C6C
/* EB9C6C 80240E1C 02A0202D */  daddu     $a0, $s5, $zero
/* EB9C70 80240E20 0260282D */  daddu     $a1, $s3, $zero
/* EB9C74 80240E24 0C090140 */  jal       func_80240500_EB9350
/* EB9C78 80240E28 0280302D */   daddu    $a2, $s4, $zero
/* EB9C7C 80240E2C 080903B5 */  j         .L80240ED4
/* EB9C80 80240E30 00000000 */   nop
glabel L80240E34_EB9C84
/* EB9C84 80240E34 02A0202D */  daddu     $a0, $s5, $zero
/* EB9C88 80240E38 0260282D */  daddu     $a1, $s3, $zero
/* EB9C8C 80240E3C 0C0901AF */  jal       func_802406BC_EB950C
/* EB9C90 80240E40 0280302D */   daddu    $a2, $s4, $zero
/* EB9C94 80240E44 080903B5 */  j         .L80240ED4
/* EB9C98 80240E48 00000000 */   nop
glabel L80240E4C_EB9C9C
/* EB9C9C 80240E4C 02A0202D */  daddu     $a0, $s5, $zero
/* EB9CA0 80240E50 0260282D */  daddu     $a1, $s3, $zero
/* EB9CA4 80240E54 0C0901DC */  jal       func_80240770_EB95C0
/* EB9CA8 80240E58 0280302D */   daddu    $a2, $s4, $zero
glabel L80240E5C_EB9CAC
/* EB9CAC 80240E5C 02A0202D */  daddu     $a0, $s5, $zero
/* EB9CB0 80240E60 0260282D */  daddu     $a1, $s3, $zero
/* EB9CB4 80240E64 0C0901F9 */  jal       func_802407E4_EB9634
/* EB9CB8 80240E68 0280302D */   daddu    $a2, $s4, $zero
/* EB9CBC 80240E6C 080903B5 */  j         .L80240ED4
/* EB9CC0 80240E70 00000000 */   nop
glabel L80240E74_EB9CC4
/* EB9CC4 80240E74 02A0202D */  daddu     $a0, $s5, $zero
/* EB9CC8 80240E78 0260282D */  daddu     $a1, $s3, $zero
/* EB9CCC 80240E7C 0C090217 */  jal       func_8024085C_EB96AC
/* EB9CD0 80240E80 0280302D */   daddu    $a2, $s4, $zero
glabel L80240E84_EB9CD4
/* EB9CD4 80240E84 02A0202D */  daddu     $a0, $s5, $zero
/* EB9CD8 80240E88 0260282D */  daddu     $a1, $s3, $zero
/* EB9CDC 80240E8C 0C090263 */  jal       func_8024098C_EB97DC
/* EB9CE0 80240E90 0280302D */   daddu    $a2, $s4, $zero
/* EB9CE4 80240E94 080903B5 */  j         .L80240ED4
/* EB9CE8 80240E98 00000000 */   nop
glabel L80240E9C_EB9CEC
/* EB9CEC 80240E9C 02A0202D */  daddu     $a0, $s5, $zero
/* EB9CF0 80240EA0 0260282D */  daddu     $a1, $s3, $zero
/* EB9CF4 80240EA4 0C0902AB */  jal       func_80240AAC_EB98FC
/* EB9CF8 80240EA8 0280302D */   daddu    $a2, $s4, $zero
/* EB9CFC 80240EAC 080903B5 */  j         .L80240ED4
/* EB9D00 80240EB0 00000000 */   nop
glabel L80240EB4_EB9D04
/* EB9D04 80240EB4 02A0202D */  daddu     $a0, $s5, $zero
/* EB9D08 80240EB8 0260282D */  daddu     $a1, $s3, $zero
/* EB9D0C 80240EBC 0C0902C5 */  jal       func_80240B14_EB9964
/* EB9D10 80240EC0 0280302D */   daddu    $a2, $s4, $zero
/* EB9D14 80240EC4 080903B5 */  j         .L80240ED4
/* EB9D18 80240EC8 00000000 */   nop
glabel L80240ECC_EB9D1C
/* EB9D1C 80240ECC 0C013AE3 */  jal       func_8004EB8C
/* EB9D20 80240ED0 02A0202D */   daddu    $a0, $s5, $zero
.L80240ED4:
glabel L80240ED4_EB9D24
/* EB9D24 80240ED4 8FBF0060 */  lw        $ra, 0x60($sp)
/* EB9D28 80240ED8 8FB5005C */  lw        $s5, 0x5c($sp)
/* EB9D2C 80240EDC 8FB40058 */  lw        $s4, 0x58($sp)
/* EB9D30 80240EE0 8FB30054 */  lw        $s3, 0x54($sp)
/* EB9D34 80240EE4 8FB20050 */  lw        $s2, 0x50($sp)
/* EB9D38 80240EE8 8FB1004C */  lw        $s1, 0x4c($sp)
/* EB9D3C 80240EEC 8FB00048 */  lw        $s0, 0x48($sp)
/* EB9D40 80240EF0 0000102D */  daddu     $v0, $zero, $zero
/* EB9D44 80240EF4 03E00008 */  jr        $ra
/* EB9D48 80240EF8 27BD0068 */   addiu    $sp, $sp, 0x68
