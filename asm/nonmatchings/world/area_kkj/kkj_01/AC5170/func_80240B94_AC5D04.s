.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B94_AC5D04
/* AC5D04 80240B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* AC5D08 80240B98 AFB40058 */  sw        $s4, 0x58($sp)
/* AC5D0C 80240B9C 0080A02D */  daddu     $s4, $a0, $zero
/* AC5D10 80240BA0 AFBF0060 */  sw        $ra, 0x60($sp)
/* AC5D14 80240BA4 AFB5005C */  sw        $s5, 0x5c($sp)
/* AC5D18 80240BA8 AFB30054 */  sw        $s3, 0x54($sp)
/* AC5D1C 80240BAC AFB20050 */  sw        $s2, 0x50($sp)
/* AC5D20 80240BB0 AFB1004C */  sw        $s1, 0x4c($sp)
/* AC5D24 80240BB4 AFB00048 */  sw        $s0, 0x48($sp)
/* AC5D28 80240BB8 8E910148 */  lw        $s1, 0x148($s4)
/* AC5D2C 80240BBC 86240008 */  lh        $a0, 8($s1)
/* AC5D30 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* AC5D34 80240BC4 00A0802D */   daddu    $s0, $a1, $zero
/* AC5D38 80240BC8 8E83000C */  lw        $v1, 0xc($s4)
/* AC5D3C 80240BCC 0280202D */  daddu     $a0, $s4, $zero
/* AC5D40 80240BD0 8C650000 */  lw        $a1, ($v1)
/* AC5D44 80240BD4 0C0B1EAF */  jal       get_variable
/* AC5D48 80240BD8 0040902D */   daddu    $s2, $v0, $zero
/* AC5D4C 80240BDC AFA00018 */  sw        $zero, 0x18($sp)
/* AC5D50 80240BE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* AC5D54 80240BE4 8C630094 */  lw        $v1, 0x94($v1)
/* AC5D58 80240BE8 AFA3001C */  sw        $v1, 0x1c($sp)
/* AC5D5C 80240BEC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* AC5D60 80240BF0 8C630080 */  lw        $v1, 0x80($v1)
/* AC5D64 80240BF4 AFA30020 */  sw        $v1, 0x20($sp)
/* AC5D68 80240BF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* AC5D6C 80240BFC 8C630088 */  lw        $v1, 0x88($v1)
/* AC5D70 80240C00 AFA30024 */  sw        $v1, 0x24($sp)
/* AC5D74 80240C04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* AC5D78 80240C08 8C63008C */  lw        $v1, 0x8c($v1)
/* AC5D7C 80240C0C 27B50018 */  addiu     $s5, $sp, 0x18
/* AC5D80 80240C10 AFA30028 */  sw        $v1, 0x28($sp)
/* AC5D84 80240C14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* AC5D88 80240C18 3C014282 */  lui       $at, 0x4282
/* AC5D8C 80240C1C 44810000 */  mtc1      $at, $f0
/* AC5D90 80240C20 8C630090 */  lw        $v1, 0x90($v1)
/* AC5D94 80240C24 0040982D */  daddu     $s3, $v0, $zero
/* AC5D98 80240C28 E7A00030 */  swc1      $f0, 0x30($sp)
/* AC5D9C 80240C2C A7A00034 */  sh        $zero, 0x34($sp)
/* AC5DA0 80240C30 16000005 */  bnez      $s0, .L80240C48
/* AC5DA4 80240C34 AFA3002C */   sw       $v1, 0x2c($sp)
/* AC5DA8 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* AC5DAC 80240C3C 30420004 */  andi      $v0, $v0, 4
/* AC5DB0 80240C40 10400044 */  beqz      $v0, .L80240D54
/* AC5DB4 80240C44 00000000 */   nop      
.L80240C48:
/* AC5DB8 80240C48 2404F7FF */  addiu     $a0, $zero, -0x801
/* AC5DBC 80240C4C AE800070 */  sw        $zero, 0x70($s4)
/* AC5DC0 80240C50 A640008E */  sh        $zero, 0x8e($s2)
/* AC5DC4 80240C54 8E2200CC */  lw        $v0, 0xcc($s1)
/* AC5DC8 80240C58 8E430000 */  lw        $v1, ($s2)
/* AC5DCC 80240C5C 8C420000 */  lw        $v0, ($v0)
/* AC5DD0 80240C60 00641824 */  and       $v1, $v1, $a0
/* AC5DD4 80240C64 AE430000 */  sw        $v1, ($s2)
/* AC5DD8 80240C68 AE420028 */  sw        $v0, 0x28($s2)
/* AC5DDC 80240C6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* AC5DE0 80240C70 8C420098 */  lw        $v0, 0x98($v0)
/* AC5DE4 80240C74 54400005 */  bnel      $v0, $zero, .L80240C8C
/* AC5DE8 80240C78 2402FDFF */   addiu    $v0, $zero, -0x201
/* AC5DEC 80240C7C 34620200 */  ori       $v0, $v1, 0x200
/* AC5DF0 80240C80 2403FFF7 */  addiu     $v1, $zero, -9
/* AC5DF4 80240C84 08090325 */  j         .L80240C94
/* AC5DF8 80240C88 00431024 */   and      $v0, $v0, $v1
.L80240C8C:
/* AC5DFC 80240C8C 00621024 */  and       $v0, $v1, $v0
/* AC5E00 80240C90 34420008 */  ori       $v0, $v0, 8
.L80240C94:
/* AC5E04 80240C94 AE420000 */  sw        $v0, ($s2)
/* AC5E08 80240C98 8E2200B0 */  lw        $v0, 0xb0($s1)
/* AC5E0C 80240C9C 30420004 */  andi      $v0, $v0, 4
/* AC5E10 80240CA0 10400008 */  beqz      $v0, .L80240CC4
/* AC5E14 80240CA4 24020063 */   addiu    $v0, $zero, 0x63
/* AC5E18 80240CA8 AE820070 */  sw        $v0, 0x70($s4)
/* AC5E1C 80240CAC AE800074 */  sw        $zero, 0x74($s4)
/* AC5E20 80240CB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* AC5E24 80240CB4 2403FFFB */  addiu     $v1, $zero, -5
/* AC5E28 80240CB8 00431024 */  and       $v0, $v0, $v1
/* AC5E2C 80240CBC 0809033C */  j         .L80240CF0
/* AC5E30 80240CC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240CC4:
/* AC5E34 80240CC4 8E220000 */  lw        $v0, ($s1)
/* AC5E38 80240CC8 3C034000 */  lui       $v1, 0x4000
/* AC5E3C 80240CCC 00431024 */  and       $v0, $v0, $v1
/* AC5E40 80240CD0 10400007 */  beqz      $v0, .L80240CF0
/* AC5E44 80240CD4 3C03BFFF */   lui      $v1, 0xbfff
/* AC5E48 80240CD8 2402000C */  addiu     $v0, $zero, 0xc
/* AC5E4C 80240CDC AE820070 */  sw        $v0, 0x70($s4)
/* AC5E50 80240CE0 8E220000 */  lw        $v0, ($s1)
/* AC5E54 80240CE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* AC5E58 80240CE8 00431024 */  and       $v0, $v0, $v1
/* AC5E5C 80240CEC AE220000 */  sw        $v0, ($s1)
.L80240CF0:
/* AC5E60 80240CF0 27A50038 */  addiu     $a1, $sp, 0x38
/* AC5E64 80240CF4 27A6003C */  addiu     $a2, $sp, 0x3c
/* AC5E68 80240CF8 C6400038 */  lwc1      $f0, 0x38($s2)
/* AC5E6C 80240CFC 864200A8 */  lh        $v0, 0xa8($s2)
/* AC5E70 80240D00 3C0142C8 */  lui       $at, 0x42c8
/* AC5E74 80240D04 44812000 */  mtc1      $at, $f4
/* AC5E78 80240D08 44823000 */  mtc1      $v0, $f6
/* AC5E7C 80240D0C 00000000 */  nop       
/* AC5E80 80240D10 468031A0 */  cvt.s.w   $f6, $f6
/* AC5E84 80240D14 27A20044 */  addiu     $v0, $sp, 0x44
/* AC5E88 80240D18 E7A00038 */  swc1      $f0, 0x38($sp)
/* AC5E8C 80240D1C C640003C */  lwc1      $f0, 0x3c($s2)
/* AC5E90 80240D20 C6420040 */  lwc1      $f2, 0x40($s2)
/* AC5E94 80240D24 46060000 */  add.s     $f0, $f0, $f6
/* AC5E98 80240D28 E7A40044 */  swc1      $f4, 0x44($sp)
/* AC5E9C 80240D2C E7A20040 */  swc1      $f2, 0x40($sp)
/* AC5EA0 80240D30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* AC5EA4 80240D34 AFA20010 */  sw        $v0, 0x10($sp)
/* AC5EA8 80240D38 8E440080 */  lw        $a0, 0x80($s2)
/* AC5EAC 80240D3C 0C0372DF */  jal       func_800DCB7C
/* AC5EB0 80240D40 27A70040 */   addiu    $a3, $sp, 0x40
/* AC5EB4 80240D44 10400003 */  beqz      $v0, .L80240D54
/* AC5EB8 80240D48 00000000 */   nop      
/* AC5EBC 80240D4C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* AC5EC0 80240D50 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D54:
/* AC5EC4 80240D54 8E830070 */  lw        $v1, 0x70($s4)
/* AC5EC8 80240D58 2C620064 */  sltiu     $v0, $v1, 0x64
/* AC5ECC 80240D5C 10400042 */  beqz      $v0, .L80240E68
/* AC5ED0 80240D60 00031080 */   sll      $v0, $v1, 2
/* AC5ED4 80240D64 3C018024 */  lui       $at, 0x8024
/* AC5ED8 80240D68 00220821 */  addu      $at, $at, $v0
/* AC5EDC 80240D6C 8C223A20 */  lw        $v0, 0x3a20($at)
/* AC5EE0 80240D70 00400008 */  jr        $v0
/* AC5EE4 80240D74 00000000 */   nop      
/* AC5EE8 80240D78 0280202D */  daddu     $a0, $s4, $zero
/* AC5EEC 80240D7C 0260282D */  daddu     $a1, $s3, $zero
/* AC5EF0 80240D80 0C090000 */  jal       func_80240000
/* AC5EF4 80240D84 02A0302D */   daddu    $a2, $s5, $zero
/* AC5EF8 80240D88 0280202D */  daddu     $a0, $s4, $zero
/* AC5EFC 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* AC5F00 80240D90 0C090056 */  jal       func_80240158
/* AC5F04 80240D94 02A0302D */   daddu    $a2, $s5, $zero
/* AC5F08 80240D98 0809039A */  j         .L80240E68
/* AC5F0C 80240D9C 00000000 */   nop      
/* AC5F10 80240DA0 0280202D */  daddu     $a0, $s4, $zero
/* AC5F14 80240DA4 0260282D */  daddu     $a1, $s3, $zero
/* AC5F18 80240DA8 0C090100 */  jal       func_80240400
/* AC5F1C 80240DAC 02A0302D */   daddu    $a2, $s5, $zero
/* AC5F20 80240DB0 0280202D */  daddu     $a0, $s4, $zero
/* AC5F24 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* AC5F28 80240DB8 0C090130 */  jal       func_802404C0
/* AC5F2C 80240DBC 02A0302D */   daddu    $a2, $s5, $zero
/* AC5F30 80240DC0 0809039A */  j         .L80240E68
/* AC5F34 80240DC4 00000000 */   nop      
/* AC5F38 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* AC5F3C 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* AC5F40 80240DD0 0C09019F */  jal       func_8024067C
/* AC5F44 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* AC5F48 80240DD8 0809039A */  j         .L80240E68
/* AC5F4C 80240DDC 00000000 */   nop      
/* AC5F50 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* AC5F54 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* AC5F58 80240DE8 0C0901CC */  jal       func_80240730
/* AC5F5C 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
/* AC5F60 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* AC5F64 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* AC5F68 80240DF8 0C0901E9 */  jal       func_802407A4
/* AC5F6C 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* AC5F70 80240E00 0809039A */  j         .L80240E68
/* AC5F74 80240E04 00000000 */   nop      
/* AC5F78 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* AC5F7C 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* AC5F80 80240E10 0C090207 */  jal       func_8024081C
/* AC5F84 80240E14 02A0302D */   daddu    $a2, $s5, $zero
/* AC5F88 80240E18 0280202D */  daddu     $a0, $s4, $zero
/* AC5F8C 80240E1C 0260282D */  daddu     $a1, $s3, $zero
/* AC5F90 80240E20 0C090253 */  jal       func_8024094C
/* AC5F94 80240E24 02A0302D */   daddu    $a2, $s5, $zero
/* AC5F98 80240E28 0809039A */  j         .L80240E68
/* AC5F9C 80240E2C 00000000 */   nop      
/* AC5FA0 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* AC5FA4 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* AC5FA8 80240E38 0C09029B */  jal       func_80240A6C
/* AC5FAC 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* AC5FB0 80240E40 0809039A */  j         .L80240E68
/* AC5FB4 80240E44 00000000 */   nop      
/* AC5FB8 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* AC5FBC 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* AC5FC0 80240E50 0C0902B5 */  jal       func_80240AD4
/* AC5FC4 80240E54 02A0302D */   daddu    $a2, $s5, $zero
/* AC5FC8 80240E58 0809039A */  j         .L80240E68
/* AC5FCC 80240E5C 00000000 */   nop      
/* AC5FD0 80240E60 0C0129CF */  jal       func_8004A73C
/* AC5FD4 80240E64 0280202D */   daddu    $a0, $s4, $zero
.L80240E68:
/* AC5FD8 80240E68 8FBF0060 */  lw        $ra, 0x60($sp)
/* AC5FDC 80240E6C 8FB5005C */  lw        $s5, 0x5c($sp)
/* AC5FE0 80240E70 8FB40058 */  lw        $s4, 0x58($sp)
/* AC5FE4 80240E74 8FB30054 */  lw        $s3, 0x54($sp)
/* AC5FE8 80240E78 8FB20050 */  lw        $s2, 0x50($sp)
/* AC5FEC 80240E7C 8FB1004C */  lw        $s1, 0x4c($sp)
/* AC5FF0 80240E80 8FB00048 */  lw        $s0, 0x48($sp)
/* AC5FF4 80240E84 0000102D */  daddu     $v0, $zero, $zero
/* AC5FF8 80240E88 03E00008 */  jr        $ra
/* AC5FFC 80240E8C 27BD0068 */   addiu    $sp, $sp, 0x68
