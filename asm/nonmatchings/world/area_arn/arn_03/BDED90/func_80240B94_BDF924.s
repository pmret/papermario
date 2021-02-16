.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B94_BDF924
/* BDF924 80240B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* BDF928 80240B98 AFB40058 */  sw        $s4, 0x58($sp)
/* BDF92C 80240B9C 0080A02D */  daddu     $s4, $a0, $zero
/* BDF930 80240BA0 AFBF0060 */  sw        $ra, 0x60($sp)
/* BDF934 80240BA4 AFB5005C */  sw        $s5, 0x5c($sp)
/* BDF938 80240BA8 AFB30054 */  sw        $s3, 0x54($sp)
/* BDF93C 80240BAC AFB20050 */  sw        $s2, 0x50($sp)
/* BDF940 80240BB0 AFB1004C */  sw        $s1, 0x4c($sp)
/* BDF944 80240BB4 AFB00048 */  sw        $s0, 0x48($sp)
/* BDF948 80240BB8 8E910148 */  lw        $s1, 0x148($s4)
/* BDF94C 80240BBC 86240008 */  lh        $a0, 8($s1)
/* BDF950 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* BDF954 80240BC4 00A0802D */   daddu    $s0, $a1, $zero
/* BDF958 80240BC8 8E83000C */  lw        $v1, 0xc($s4)
/* BDF95C 80240BCC 0280202D */  daddu     $a0, $s4, $zero
/* BDF960 80240BD0 8C650000 */  lw        $a1, ($v1)
/* BDF964 80240BD4 0C0B1EAF */  jal       get_variable
/* BDF968 80240BD8 0040902D */   daddu    $s2, $v0, $zero
/* BDF96C 80240BDC AFA00018 */  sw        $zero, 0x18($sp)
/* BDF970 80240BE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BDF974 80240BE4 8C630094 */  lw        $v1, 0x94($v1)
/* BDF978 80240BE8 AFA3001C */  sw        $v1, 0x1c($sp)
/* BDF97C 80240BEC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BDF980 80240BF0 8C630080 */  lw        $v1, 0x80($v1)
/* BDF984 80240BF4 AFA30020 */  sw        $v1, 0x20($sp)
/* BDF988 80240BF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BDF98C 80240BFC 8C630088 */  lw        $v1, 0x88($v1)
/* BDF990 80240C00 AFA30024 */  sw        $v1, 0x24($sp)
/* BDF994 80240C04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BDF998 80240C08 8C63008C */  lw        $v1, 0x8c($v1)
/* BDF99C 80240C0C 27B50018 */  addiu     $s5, $sp, 0x18
/* BDF9A0 80240C10 AFA30028 */  sw        $v1, 0x28($sp)
/* BDF9A4 80240C14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BDF9A8 80240C18 3C014282 */  lui       $at, 0x4282
/* BDF9AC 80240C1C 44810000 */  mtc1      $at, $f0
/* BDF9B0 80240C20 8C630090 */  lw        $v1, 0x90($v1)
/* BDF9B4 80240C24 0040982D */  daddu     $s3, $v0, $zero
/* BDF9B8 80240C28 E7A00030 */  swc1      $f0, 0x30($sp)
/* BDF9BC 80240C2C A7A00034 */  sh        $zero, 0x34($sp)
/* BDF9C0 80240C30 16000005 */  bnez      $s0, .L80240C48
/* BDF9C4 80240C34 AFA3002C */   sw       $v1, 0x2c($sp)
/* BDF9C8 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BDF9CC 80240C3C 30420004 */  andi      $v0, $v0, 4
/* BDF9D0 80240C40 10400044 */  beqz      $v0, .L80240D54
/* BDF9D4 80240C44 00000000 */   nop
.L80240C48:
/* BDF9D8 80240C48 2404F7FF */  addiu     $a0, $zero, -0x801
/* BDF9DC 80240C4C AE800070 */  sw        $zero, 0x70($s4)
/* BDF9E0 80240C50 A640008E */  sh        $zero, 0x8e($s2)
/* BDF9E4 80240C54 8E2200CC */  lw        $v0, 0xcc($s1)
/* BDF9E8 80240C58 8E430000 */  lw        $v1, ($s2)
/* BDF9EC 80240C5C 8C420000 */  lw        $v0, ($v0)
/* BDF9F0 80240C60 00641824 */  and       $v1, $v1, $a0
/* BDF9F4 80240C64 AE430000 */  sw        $v1, ($s2)
/* BDF9F8 80240C68 AE420028 */  sw        $v0, 0x28($s2)
/* BDF9FC 80240C6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BDFA00 80240C70 8C420098 */  lw        $v0, 0x98($v0)
/* BDFA04 80240C74 54400005 */  bnel      $v0, $zero, .L80240C8C
/* BDFA08 80240C78 2402FDFF */   addiu    $v0, $zero, -0x201
/* BDFA0C 80240C7C 34620200 */  ori       $v0, $v1, 0x200
/* BDFA10 80240C80 2403FFF7 */  addiu     $v1, $zero, -9
/* BDFA14 80240C84 08090325 */  j         .L80240C94
/* BDFA18 80240C88 00431024 */   and      $v0, $v0, $v1
.L80240C8C:
/* BDFA1C 80240C8C 00621024 */  and       $v0, $v1, $v0
/* BDFA20 80240C90 34420008 */  ori       $v0, $v0, 8
.L80240C94:
/* BDFA24 80240C94 AE420000 */  sw        $v0, ($s2)
/* BDFA28 80240C98 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BDFA2C 80240C9C 30420004 */  andi      $v0, $v0, 4
/* BDFA30 80240CA0 10400008 */  beqz      $v0, .L80240CC4
/* BDFA34 80240CA4 24020063 */   addiu    $v0, $zero, 0x63
/* BDFA38 80240CA8 AE820070 */  sw        $v0, 0x70($s4)
/* BDFA3C 80240CAC AE800074 */  sw        $zero, 0x74($s4)
/* BDFA40 80240CB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BDFA44 80240CB4 2403FFFB */  addiu     $v1, $zero, -5
/* BDFA48 80240CB8 00431024 */  and       $v0, $v0, $v1
/* BDFA4C 80240CBC 0809033C */  j         .L80240CF0
/* BDFA50 80240CC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240CC4:
/* BDFA54 80240CC4 8E220000 */  lw        $v0, ($s1)
/* BDFA58 80240CC8 3C034000 */  lui       $v1, 0x4000
/* BDFA5C 80240CCC 00431024 */  and       $v0, $v0, $v1
/* BDFA60 80240CD0 10400007 */  beqz      $v0, .L80240CF0
/* BDFA64 80240CD4 3C03BFFF */   lui      $v1, 0xbfff
/* BDFA68 80240CD8 2402000C */  addiu     $v0, $zero, 0xc
/* BDFA6C 80240CDC AE820070 */  sw        $v0, 0x70($s4)
/* BDFA70 80240CE0 8E220000 */  lw        $v0, ($s1)
/* BDFA74 80240CE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* BDFA78 80240CE8 00431024 */  and       $v0, $v0, $v1
/* BDFA7C 80240CEC AE220000 */  sw        $v0, ($s1)
.L80240CF0:
/* BDFA80 80240CF0 27A50038 */  addiu     $a1, $sp, 0x38
/* BDFA84 80240CF4 27A6003C */  addiu     $a2, $sp, 0x3c
/* BDFA88 80240CF8 C6400038 */  lwc1      $f0, 0x38($s2)
/* BDFA8C 80240CFC 864200A8 */  lh        $v0, 0xa8($s2)
/* BDFA90 80240D00 3C0142C8 */  lui       $at, 0x42c8
/* BDFA94 80240D04 44812000 */  mtc1      $at, $f4
/* BDFA98 80240D08 44823000 */  mtc1      $v0, $f6
/* BDFA9C 80240D0C 00000000 */  nop
/* BDFAA0 80240D10 468031A0 */  cvt.s.w   $f6, $f6
/* BDFAA4 80240D14 27A20044 */  addiu     $v0, $sp, 0x44
/* BDFAA8 80240D18 E7A00038 */  swc1      $f0, 0x38($sp)
/* BDFAAC 80240D1C C640003C */  lwc1      $f0, 0x3c($s2)
/* BDFAB0 80240D20 C6420040 */  lwc1      $f2, 0x40($s2)
/* BDFAB4 80240D24 46060000 */  add.s     $f0, $f0, $f6
/* BDFAB8 80240D28 E7A40044 */  swc1      $f4, 0x44($sp)
/* BDFABC 80240D2C E7A20040 */  swc1      $f2, 0x40($sp)
/* BDFAC0 80240D30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* BDFAC4 80240D34 AFA20010 */  sw        $v0, 0x10($sp)
/* BDFAC8 80240D38 8E440080 */  lw        $a0, 0x80($s2)
/* BDFACC 80240D3C 0C0372DF */  jal       func_800DCB7C
/* BDFAD0 80240D40 27A70040 */   addiu    $a3, $sp, 0x40
/* BDFAD4 80240D44 10400003 */  beqz      $v0, .L80240D54
/* BDFAD8 80240D48 00000000 */   nop
/* BDFADC 80240D4C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* BDFAE0 80240D50 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D54:
/* BDFAE4 80240D54 8E830070 */  lw        $v1, 0x70($s4)
/* BDFAE8 80240D58 2C620064 */  sltiu     $v0, $v1, 0x64
/* BDFAEC 80240D5C 10400042 */  beqz      $v0, .L80240E68
/* BDFAF0 80240D60 00031080 */   sll      $v0, $v1, 2
/* BDFAF4 80240D64 3C018024 */  lui       $at, %hi(jtbl_80244870_BE3600)
/* BDFAF8 80240D68 00220821 */  addu      $at, $at, $v0
/* BDFAFC 80240D6C 8C224870 */  lw        $v0, %lo(jtbl_80244870_BE3600)($at)
/* BDFB00 80240D70 00400008 */  jr        $v0
/* BDFB04 80240D74 00000000 */   nop
glabel L80240D78_BDFB08
/* BDFB08 80240D78 0280202D */  daddu     $a0, $s4, $zero
/* BDFB0C 80240D7C 0260282D */  daddu     $a1, $s3, $zero
/* BDFB10 80240D80 0C090000 */  jal       func_80240000_BDED90
/* BDFB14 80240D84 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240D88_BDFB18
/* BDFB18 80240D88 0280202D */  daddu     $a0, $s4, $zero
/* BDFB1C 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* BDFB20 80240D90 0C090056 */  jal       func_80240158_BDEEE8
/* BDFB24 80240D94 02A0302D */   daddu    $a2, $s5, $zero
/* BDFB28 80240D98 0809039A */  j         .L80240E68
/* BDFB2C 80240D9C 00000000 */   nop
glabel L80240DA0_BDFB30
/* BDFB30 80240DA0 0280202D */  daddu     $a0, $s4, $zero
/* BDFB34 80240DA4 0260282D */  daddu     $a1, $s3, $zero
/* BDFB38 80240DA8 0C090100 */  jal       arn_03_UnkNpcAIFunc1
/* BDFB3C 80240DAC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DB0_BDFB40
/* BDFB40 80240DB0 0280202D */  daddu     $a0, $s4, $zero
/* BDFB44 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* BDFB48 80240DB8 0C090130 */  jal       func_802404C0_BDF250
/* BDFB4C 80240DBC 02A0302D */   daddu    $a2, $s5, $zero
/* BDFB50 80240DC0 0809039A */  j         .L80240E68
/* BDFB54 80240DC4 00000000 */   nop
glabel L80240DC8_BDFB58
/* BDFB58 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* BDFB5C 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* BDFB60 80240DD0 0C09019F */  jal       func_8024067C_BDF40C
/* BDFB64 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* BDFB68 80240DD8 0809039A */  j         .L80240E68
/* BDFB6C 80240DDC 00000000 */   nop
glabel L80240DE0_BDFB70
/* BDFB70 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* BDFB74 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* BDFB78 80240DE8 0C0901CC */  jal       arn_03_NpcJumpFunc2
/* BDFB7C 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DF0_BDFB80
/* BDFB80 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* BDFB84 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* BDFB88 80240DF8 0C0901E9 */  jal       arn_03_NpcJumpFunc
/* BDFB8C 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* BDFB90 80240E00 0809039A */  j         .L80240E68
/* BDFB94 80240E04 00000000 */   nop
glabel L80240E08_BDFB98
/* BDFB98 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* BDFB9C 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* BDFBA0 80240E10 0C090207 */  jal       arn_03_UnkNpcAIFunc13
/* BDFBA4 80240E14 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240E18_BDFBA8
/* BDFBA8 80240E18 0280202D */  daddu     $a0, $s4, $zero
/* BDFBAC 80240E1C 0260282D */  daddu     $a1, $s3, $zero
/* BDFBB0 80240E20 0C090253 */  jal       func_8024094C_BDF6DC
/* BDFBB4 80240E24 02A0302D */   daddu    $a2, $s5, $zero
/* BDFBB8 80240E28 0809039A */  j         .L80240E68
/* BDFBBC 80240E2C 00000000 */   nop
glabel L80240E30_BDFBC0
/* BDFBC0 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* BDFBC4 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* BDFBC8 80240E38 0C09029B */  jal       arn_03_UnkNpcDurationFlagFunc
/* BDFBCC 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* BDFBD0 80240E40 0809039A */  j         .L80240E68
/* BDFBD4 80240E44 00000000 */   nop
glabel L80240E48_BDFBD8
/* BDFBD8 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* BDFBDC 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* BDFBE0 80240E50 0C0902B5 */  jal       func_80240AD4_BDF864
/* BDFBE4 80240E54 02A0302D */   daddu    $a2, $s5, $zero
/* BDFBE8 80240E58 0809039A */  j         .L80240E68
/* BDFBEC 80240E5C 00000000 */   nop
glabel L80240E60_BDFBF0
/* BDFBF0 80240E60 0C0129CF */  jal       func_8004A73C
/* BDFBF4 80240E64 0280202D */   daddu    $a0, $s4, $zero
.L80240E68:
glabel L80240E68_BDFBF8
/* BDFBF8 80240E68 8FBF0060 */  lw        $ra, 0x60($sp)
/* BDFBFC 80240E6C 8FB5005C */  lw        $s5, 0x5c($sp)
/* BDFC00 80240E70 8FB40058 */  lw        $s4, 0x58($sp)
/* BDFC04 80240E74 8FB30054 */  lw        $s3, 0x54($sp)
/* BDFC08 80240E78 8FB20050 */  lw        $s2, 0x50($sp)
/* BDFC0C 80240E7C 8FB1004C */  lw        $s1, 0x4c($sp)
/* BDFC10 80240E80 8FB00048 */  lw        $s0, 0x48($sp)
/* BDFC14 80240E84 0000102D */  daddu     $v0, $zero, $zero
/* BDFC18 80240E88 03E00008 */  jr        $ra
/* BDFC1C 80240E8C 27BD0068 */   addiu    $sp, $sp, 0x68
