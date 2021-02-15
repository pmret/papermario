.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B94_B84D14
/* B84D14 80240B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B84D18 80240B98 AFB40058 */  sw        $s4, 0x58($sp)
/* B84D1C 80240B9C 0080A02D */  daddu     $s4, $a0, $zero
/* B84D20 80240BA0 AFBF0060 */  sw        $ra, 0x60($sp)
/* B84D24 80240BA4 AFB5005C */  sw        $s5, 0x5c($sp)
/* B84D28 80240BA8 AFB30054 */  sw        $s3, 0x54($sp)
/* B84D2C 80240BAC AFB20050 */  sw        $s2, 0x50($sp)
/* B84D30 80240BB0 AFB1004C */  sw        $s1, 0x4c($sp)
/* B84D34 80240BB4 AFB00048 */  sw        $s0, 0x48($sp)
/* B84D38 80240BB8 8E910148 */  lw        $s1, 0x148($s4)
/* B84D3C 80240BBC 86240008 */  lh        $a0, 8($s1)
/* B84D40 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* B84D44 80240BC4 00A0802D */   daddu    $s0, $a1, $zero
/* B84D48 80240BC8 8E83000C */  lw        $v1, 0xc($s4)
/* B84D4C 80240BCC 0280202D */  daddu     $a0, $s4, $zero
/* B84D50 80240BD0 8C650000 */  lw        $a1, ($v1)
/* B84D54 80240BD4 0C0B1EAF */  jal       get_variable
/* B84D58 80240BD8 0040902D */   daddu    $s2, $v0, $zero
/* B84D5C 80240BDC AFA00018 */  sw        $zero, 0x18($sp)
/* B84D60 80240BE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B84D64 80240BE4 8C630094 */  lw        $v1, 0x94($v1)
/* B84D68 80240BE8 AFA3001C */  sw        $v1, 0x1c($sp)
/* B84D6C 80240BEC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B84D70 80240BF0 8C630080 */  lw        $v1, 0x80($v1)
/* B84D74 80240BF4 AFA30020 */  sw        $v1, 0x20($sp)
/* B84D78 80240BF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B84D7C 80240BFC 8C630088 */  lw        $v1, 0x88($v1)
/* B84D80 80240C00 AFA30024 */  sw        $v1, 0x24($sp)
/* B84D84 80240C04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B84D88 80240C08 8C63008C */  lw        $v1, 0x8c($v1)
/* B84D8C 80240C0C 27B50018 */  addiu     $s5, $sp, 0x18
/* B84D90 80240C10 AFA30028 */  sw        $v1, 0x28($sp)
/* B84D94 80240C14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B84D98 80240C18 3C014282 */  lui       $at, 0x4282
/* B84D9C 80240C1C 44810000 */  mtc1      $at, $f0
/* B84DA0 80240C20 8C630090 */  lw        $v1, 0x90($v1)
/* B84DA4 80240C24 0040982D */  daddu     $s3, $v0, $zero
/* B84DA8 80240C28 E7A00030 */  swc1      $f0, 0x30($sp)
/* B84DAC 80240C2C A7A00034 */  sh        $zero, 0x34($sp)
/* B84DB0 80240C30 16000005 */  bnez      $s0, .L80240C48
/* B84DB4 80240C34 AFA3002C */   sw       $v1, 0x2c($sp)
/* B84DB8 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B84DBC 80240C3C 30420004 */  andi      $v0, $v0, 4
/* B84DC0 80240C40 10400044 */  beqz      $v0, .L80240D54
/* B84DC4 80240C44 00000000 */   nop
.L80240C48:
/* B84DC8 80240C48 2404F7FF */  addiu     $a0, $zero, -0x801
/* B84DCC 80240C4C AE800070 */  sw        $zero, 0x70($s4)
/* B84DD0 80240C50 A640008E */  sh        $zero, 0x8e($s2)
/* B84DD4 80240C54 8E2200CC */  lw        $v0, 0xcc($s1)
/* B84DD8 80240C58 8E430000 */  lw        $v1, ($s2)
/* B84DDC 80240C5C 8C420000 */  lw        $v0, ($v0)
/* B84DE0 80240C60 00641824 */  and       $v1, $v1, $a0
/* B84DE4 80240C64 AE430000 */  sw        $v1, ($s2)
/* B84DE8 80240C68 AE420028 */  sw        $v0, 0x28($s2)
/* B84DEC 80240C6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B84DF0 80240C70 8C420098 */  lw        $v0, 0x98($v0)
/* B84DF4 80240C74 54400005 */  bnel      $v0, $zero, .L80240C8C
/* B84DF8 80240C78 2402FDFF */   addiu    $v0, $zero, -0x201
/* B84DFC 80240C7C 34620200 */  ori       $v0, $v1, 0x200
/* B84E00 80240C80 2403FFF7 */  addiu     $v1, $zero, -9
/* B84E04 80240C84 08090325 */  j         .L80240C94
/* B84E08 80240C88 00431024 */   and      $v0, $v0, $v1
.L80240C8C:
/* B84E0C 80240C8C 00621024 */  and       $v0, $v1, $v0
/* B84E10 80240C90 34420008 */  ori       $v0, $v0, 8
.L80240C94:
/* B84E14 80240C94 AE420000 */  sw        $v0, ($s2)
/* B84E18 80240C98 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B84E1C 80240C9C 30420004 */  andi      $v0, $v0, 4
/* B84E20 80240CA0 10400008 */  beqz      $v0, .L80240CC4
/* B84E24 80240CA4 24020063 */   addiu    $v0, $zero, 0x63
/* B84E28 80240CA8 AE820070 */  sw        $v0, 0x70($s4)
/* B84E2C 80240CAC AE800074 */  sw        $zero, 0x74($s4)
/* B84E30 80240CB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B84E34 80240CB4 2403FFFB */  addiu     $v1, $zero, -5
/* B84E38 80240CB8 00431024 */  and       $v0, $v0, $v1
/* B84E3C 80240CBC 0809033C */  j         .L80240CF0
/* B84E40 80240CC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240CC4:
/* B84E44 80240CC4 8E220000 */  lw        $v0, ($s1)
/* B84E48 80240CC8 3C034000 */  lui       $v1, 0x4000
/* B84E4C 80240CCC 00431024 */  and       $v0, $v0, $v1
/* B84E50 80240CD0 10400007 */  beqz      $v0, .L80240CF0
/* B84E54 80240CD4 3C03BFFF */   lui      $v1, 0xbfff
/* B84E58 80240CD8 2402000C */  addiu     $v0, $zero, 0xc
/* B84E5C 80240CDC AE820070 */  sw        $v0, 0x70($s4)
/* B84E60 80240CE0 8E220000 */  lw        $v0, ($s1)
/* B84E64 80240CE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* B84E68 80240CE8 00431024 */  and       $v0, $v0, $v1
/* B84E6C 80240CEC AE220000 */  sw        $v0, ($s1)
.L80240CF0:
/* B84E70 80240CF0 27A50038 */  addiu     $a1, $sp, 0x38
/* B84E74 80240CF4 27A6003C */  addiu     $a2, $sp, 0x3c
/* B84E78 80240CF8 C6400038 */  lwc1      $f0, 0x38($s2)
/* B84E7C 80240CFC 864200A8 */  lh        $v0, 0xa8($s2)
/* B84E80 80240D00 3C0142C8 */  lui       $at, 0x42c8
/* B84E84 80240D04 44812000 */  mtc1      $at, $f4
/* B84E88 80240D08 44823000 */  mtc1      $v0, $f6
/* B84E8C 80240D0C 00000000 */  nop
/* B84E90 80240D10 468031A0 */  cvt.s.w   $f6, $f6
/* B84E94 80240D14 27A20044 */  addiu     $v0, $sp, 0x44
/* B84E98 80240D18 E7A00038 */  swc1      $f0, 0x38($sp)
/* B84E9C 80240D1C C640003C */  lwc1      $f0, 0x3c($s2)
/* B84EA0 80240D20 C6420040 */  lwc1      $f2, 0x40($s2)
/* B84EA4 80240D24 46060000 */  add.s     $f0, $f0, $f6
/* B84EA8 80240D28 E7A40044 */  swc1      $f4, 0x44($sp)
/* B84EAC 80240D2C E7A20040 */  swc1      $f2, 0x40($sp)
/* B84EB0 80240D30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* B84EB4 80240D34 AFA20010 */  sw        $v0, 0x10($sp)
/* B84EB8 80240D38 8E440080 */  lw        $a0, 0x80($s2)
/* B84EBC 80240D3C 0C0372DF */  jal       func_800DCB7C
/* B84EC0 80240D40 27A70040 */   addiu    $a3, $sp, 0x40
/* B84EC4 80240D44 10400003 */  beqz      $v0, .L80240D54
/* B84EC8 80240D48 00000000 */   nop
/* B84ECC 80240D4C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* B84ED0 80240D50 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D54:
/* B84ED4 80240D54 8E830070 */  lw        $v1, 0x70($s4)
/* B84ED8 80240D58 2C620064 */  sltiu     $v0, $v1, 0x64
/* B84EDC 80240D5C 10400042 */  beqz      $v0, .L80240E68
/* B84EE0 80240D60 00031080 */   sll      $v0, $v1, 2
/* B84EE4 80240D64 3C018025 */  lui       $at, %hi(jtbl_8024B9B0_B8FB30)
/* B84EE8 80240D68 00220821 */  addu      $at, $at, $v0
/* B84EEC 80240D6C 8C22B9B0 */  lw        $v0, %lo(jtbl_8024B9B0_B8FB30)($at)
/* B84EF0 80240D70 00400008 */  jr        $v0
/* B84EF4 80240D74 00000000 */   nop
glabel L80240D78_B84EF8
/* B84EF8 80240D78 0280202D */  daddu     $a0, $s4, $zero
/* B84EFC 80240D7C 0260282D */  daddu     $a1, $s3, $zero
/* B84F00 80240D80 0C090000 */  jal       func_80240000_B84180
/* B84F04 80240D84 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240D88_B84F08
/* B84F08 80240D88 0280202D */  daddu     $a0, $s4, $zero
/* B84F0C 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* B84F10 80240D90 0C090056 */  jal       func_80240158_B842D8
/* B84F14 80240D94 02A0302D */   daddu    $a2, $s5, $zero
/* B84F18 80240D98 0809039A */  j         .L80240E68
/* B84F1C 80240D9C 00000000 */   nop
glabel L80240DA0_B84F20
/* B84F20 80240DA0 0280202D */  daddu     $a0, $s4, $zero
/* B84F24 80240DA4 0260282D */  daddu     $a1, $s3, $zero
/* B84F28 80240DA8 0C090100 */  jal       jan_22_UnkNpcAIFunc1
/* B84F2C 80240DAC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DB0_B84F30
/* B84F30 80240DB0 0280202D */  daddu     $a0, $s4, $zero
/* B84F34 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* B84F38 80240DB8 0C090130 */  jal       func_802404C0_B84640
/* B84F3C 80240DBC 02A0302D */   daddu    $a2, $s5, $zero
/* B84F40 80240DC0 0809039A */  j         .L80240E68
/* B84F44 80240DC4 00000000 */   nop
glabel L80240DC8_B84F48
/* B84F48 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* B84F4C 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* B84F50 80240DD0 0C09019F */  jal       func_8024067C_B847FC
/* B84F54 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* B84F58 80240DD8 0809039A */  j         .L80240E68
/* B84F5C 80240DDC 00000000 */   nop
glabel L80240DE0_B84F60
/* B84F60 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* B84F64 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* B84F68 80240DE8 0C0901CC */  jal       jan_22_NpcJumpFunc2
/* B84F6C 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DF0_B84F70
/* B84F70 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* B84F74 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* B84F78 80240DF8 0C0901E9 */  jal       jan_22_NpcJumpFunc
/* B84F7C 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* B84F80 80240E00 0809039A */  j         .L80240E68
/* B84F84 80240E04 00000000 */   nop
glabel L80240E08_B84F88
/* B84F88 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* B84F8C 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* B84F90 80240E10 0C090207 */  jal       func_8024081C_B8499C
/* B84F94 80240E14 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240E18_B84F98
/* B84F98 80240E18 0280202D */  daddu     $a0, $s4, $zero
/* B84F9C 80240E1C 0260282D */  daddu     $a1, $s3, $zero
/* B84FA0 80240E20 0C090253 */  jal       func_8024094C_B84ACC
/* B84FA4 80240E24 02A0302D */   daddu    $a2, $s5, $zero
/* B84FA8 80240E28 0809039A */  j         .L80240E68
/* B84FAC 80240E2C 00000000 */   nop
glabel L80240E30_B84FB0
/* B84FB0 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* B84FB4 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* B84FB8 80240E38 0C09029B */  jal       jan_22_UnkNpcDurationFlagFunc
/* B84FBC 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* B84FC0 80240E40 0809039A */  j         .L80240E68
/* B84FC4 80240E44 00000000 */   nop
glabel L80240E48_B84FC8
/* B84FC8 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* B84FCC 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* B84FD0 80240E50 0C0902B5 */  jal       func_80240AD4_B84C54
/* B84FD4 80240E54 02A0302D */   daddu    $a2, $s5, $zero
/* B84FD8 80240E58 0809039A */  j         .L80240E68
/* B84FDC 80240E5C 00000000 */   nop
glabel L80240E60_B84FE0
/* B84FE0 80240E60 0C0129CF */  jal       func_8004A73C
/* B84FE4 80240E64 0280202D */   daddu    $a0, $s4, $zero
.L80240E68:
glabel L80240E68_B84FE8
/* B84FE8 80240E68 8FBF0060 */  lw        $ra, 0x60($sp)
/* B84FEC 80240E6C 8FB5005C */  lw        $s5, 0x5c($sp)
/* B84FF0 80240E70 8FB40058 */  lw        $s4, 0x58($sp)
/* B84FF4 80240E74 8FB30054 */  lw        $s3, 0x54($sp)
/* B84FF8 80240E78 8FB20050 */  lw        $s2, 0x50($sp)
/* B84FFC 80240E7C 8FB1004C */  lw        $s1, 0x4c($sp)
/* B85000 80240E80 8FB00048 */  lw        $s0, 0x48($sp)
/* B85004 80240E84 0000102D */  daddu     $v0, $zero, $zero
/* B85008 80240E88 03E00008 */  jr        $ra
/* B8500C 80240E8C 27BD0068 */   addiu    $sp, $sp, 0x68
