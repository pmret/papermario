.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B94_C40944
/* C40944 80240B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* C40948 80240B98 AFB40058 */  sw        $s4, 0x58($sp)
/* C4094C 80240B9C 0080A02D */  daddu     $s4, $a0, $zero
/* C40950 80240BA0 AFBF0060 */  sw        $ra, 0x60($sp)
/* C40954 80240BA4 AFB5005C */  sw        $s5, 0x5c($sp)
/* C40958 80240BA8 AFB30054 */  sw        $s3, 0x54($sp)
/* C4095C 80240BAC AFB20050 */  sw        $s2, 0x50($sp)
/* C40960 80240BB0 AFB1004C */  sw        $s1, 0x4c($sp)
/* C40964 80240BB4 AFB00048 */  sw        $s0, 0x48($sp)
/* C40968 80240BB8 8E910148 */  lw        $s1, 0x148($s4)
/* C4096C 80240BBC 86240008 */  lh        $a0, 8($s1)
/* C40970 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* C40974 80240BC4 00A0802D */   daddu    $s0, $a1, $zero
/* C40978 80240BC8 8E83000C */  lw        $v1, 0xc($s4)
/* C4097C 80240BCC 0280202D */  daddu     $a0, $s4, $zero
/* C40980 80240BD0 8C650000 */  lw        $a1, ($v1)
/* C40984 80240BD4 0C0B1EAF */  jal       get_variable
/* C40988 80240BD8 0040902D */   daddu    $s2, $v0, $zero
/* C4098C 80240BDC AFA00018 */  sw        $zero, 0x18($sp)
/* C40990 80240BE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C40994 80240BE4 8C630094 */  lw        $v1, 0x94($v1)
/* C40998 80240BE8 AFA3001C */  sw        $v1, 0x1c($sp)
/* C4099C 80240BEC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C409A0 80240BF0 8C630080 */  lw        $v1, 0x80($v1)
/* C409A4 80240BF4 AFA30020 */  sw        $v1, 0x20($sp)
/* C409A8 80240BF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C409AC 80240BFC 8C630088 */  lw        $v1, 0x88($v1)
/* C409B0 80240C00 AFA30024 */  sw        $v1, 0x24($sp)
/* C409B4 80240C04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C409B8 80240C08 8C63008C */  lw        $v1, 0x8c($v1)
/* C409BC 80240C0C 27B50018 */  addiu     $s5, $sp, 0x18
/* C409C0 80240C10 AFA30028 */  sw        $v1, 0x28($sp)
/* C409C4 80240C14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C409C8 80240C18 3C014282 */  lui       $at, 0x4282
/* C409CC 80240C1C 44810000 */  mtc1      $at, $f0
/* C409D0 80240C20 8C630090 */  lw        $v1, 0x90($v1)
/* C409D4 80240C24 0040982D */  daddu     $s3, $v0, $zero
/* C409D8 80240C28 E7A00030 */  swc1      $f0, 0x30($sp)
/* C409DC 80240C2C A7A00034 */  sh        $zero, 0x34($sp)
/* C409E0 80240C30 16000005 */  bnez      $s0, .L80240C48
/* C409E4 80240C34 AFA3002C */   sw       $v1, 0x2c($sp)
/* C409E8 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C409EC 80240C3C 30420004 */  andi      $v0, $v0, 4
/* C409F0 80240C40 10400044 */  beqz      $v0, .L80240D54
/* C409F4 80240C44 00000000 */   nop      
.L80240C48:
/* C409F8 80240C48 2404F7FF */  addiu     $a0, $zero, -0x801
/* C409FC 80240C4C AE800070 */  sw        $zero, 0x70($s4)
/* C40A00 80240C50 A640008E */  sh        $zero, 0x8e($s2)
/* C40A04 80240C54 8E2200CC */  lw        $v0, 0xcc($s1)
/* C40A08 80240C58 8E430000 */  lw        $v1, ($s2)
/* C40A0C 80240C5C 8C420000 */  lw        $v0, ($v0)
/* C40A10 80240C60 00641824 */  and       $v1, $v1, $a0
/* C40A14 80240C64 AE430000 */  sw        $v1, ($s2)
/* C40A18 80240C68 AE420028 */  sw        $v0, 0x28($s2)
/* C40A1C 80240C6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C40A20 80240C70 8C420098 */  lw        $v0, 0x98($v0)
/* C40A24 80240C74 54400005 */  bnel      $v0, $zero, .L80240C8C
/* C40A28 80240C78 2402FDFF */   addiu    $v0, $zero, -0x201
/* C40A2C 80240C7C 34620200 */  ori       $v0, $v1, 0x200
/* C40A30 80240C80 2403FFF7 */  addiu     $v1, $zero, -9
/* C40A34 80240C84 08090325 */  j         .L80240C94
/* C40A38 80240C88 00431024 */   and      $v0, $v0, $v1
.L80240C8C:
/* C40A3C 80240C8C 00621024 */  and       $v0, $v1, $v0
/* C40A40 80240C90 34420008 */  ori       $v0, $v0, 8
.L80240C94:
/* C40A44 80240C94 AE420000 */  sw        $v0, ($s2)
/* C40A48 80240C98 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C40A4C 80240C9C 30420004 */  andi      $v0, $v0, 4
/* C40A50 80240CA0 10400008 */  beqz      $v0, .L80240CC4
/* C40A54 80240CA4 24020063 */   addiu    $v0, $zero, 0x63
/* C40A58 80240CA8 AE820070 */  sw        $v0, 0x70($s4)
/* C40A5C 80240CAC AE800074 */  sw        $zero, 0x74($s4)
/* C40A60 80240CB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C40A64 80240CB4 2403FFFB */  addiu     $v1, $zero, -5
/* C40A68 80240CB8 00431024 */  and       $v0, $v0, $v1
/* C40A6C 80240CBC 0809033C */  j         .L80240CF0
/* C40A70 80240CC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240CC4:
/* C40A74 80240CC4 8E220000 */  lw        $v0, ($s1)
/* C40A78 80240CC8 3C034000 */  lui       $v1, 0x4000
/* C40A7C 80240CCC 00431024 */  and       $v0, $v0, $v1
/* C40A80 80240CD0 10400007 */  beqz      $v0, .L80240CF0
/* C40A84 80240CD4 3C03BFFF */   lui      $v1, 0xbfff
/* C40A88 80240CD8 2402000C */  addiu     $v0, $zero, 0xc
/* C40A8C 80240CDC AE820070 */  sw        $v0, 0x70($s4)
/* C40A90 80240CE0 8E220000 */  lw        $v0, ($s1)
/* C40A94 80240CE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* C40A98 80240CE8 00431024 */  and       $v0, $v0, $v1
/* C40A9C 80240CEC AE220000 */  sw        $v0, ($s1)
.L80240CF0:
/* C40AA0 80240CF0 27A50038 */  addiu     $a1, $sp, 0x38
/* C40AA4 80240CF4 27A6003C */  addiu     $a2, $sp, 0x3c
/* C40AA8 80240CF8 C6400038 */  lwc1      $f0, 0x38($s2)
/* C40AAC 80240CFC 864200A8 */  lh        $v0, 0xa8($s2)
/* C40AB0 80240D00 3C0142C8 */  lui       $at, 0x42c8
/* C40AB4 80240D04 44812000 */  mtc1      $at, $f4
/* C40AB8 80240D08 44823000 */  mtc1      $v0, $f6
/* C40ABC 80240D0C 00000000 */  nop       
/* C40AC0 80240D10 468031A0 */  cvt.s.w   $f6, $f6
/* C40AC4 80240D14 27A20044 */  addiu     $v0, $sp, 0x44
/* C40AC8 80240D18 E7A00038 */  swc1      $f0, 0x38($sp)
/* C40ACC 80240D1C C640003C */  lwc1      $f0, 0x3c($s2)
/* C40AD0 80240D20 C6420040 */  lwc1      $f2, 0x40($s2)
/* C40AD4 80240D24 46060000 */  add.s     $f0, $f0, $f6
/* C40AD8 80240D28 E7A40044 */  swc1      $f4, 0x44($sp)
/* C40ADC 80240D2C E7A20040 */  swc1      $f2, 0x40($sp)
/* C40AE0 80240D30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* C40AE4 80240D34 AFA20010 */  sw        $v0, 0x10($sp)
/* C40AE8 80240D38 8E440080 */  lw        $a0, 0x80($s2)
/* C40AEC 80240D3C 0C0372DF */  jal       func_800DCB7C
/* C40AF0 80240D40 27A70040 */   addiu    $a3, $sp, 0x40
/* C40AF4 80240D44 10400003 */  beqz      $v0, .L80240D54
/* C40AF8 80240D48 00000000 */   nop      
/* C40AFC 80240D4C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* C40B00 80240D50 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D54:
/* C40B04 80240D54 8E830070 */  lw        $v1, 0x70($s4)
/* C40B08 80240D58 2C620064 */  sltiu     $v0, $v1, 0x64
/* C40B0C 80240D5C 10400042 */  beqz      $v0, .L80240E68
/* C40B10 80240D60 00031080 */   sll      $v0, $v1, 2
/* C40B14 80240D64 3C018024 */  lui       $at, 0x8024
/* C40B18 80240D68 00220821 */  addu      $at, $at, $v0
/* C40B1C 80240D6C 8C226A10 */  lw        $v0, 0x6a10($at)
/* C40B20 80240D70 00400008 */  jr        $v0
/* C40B24 80240D74 00000000 */   nop      
/* C40B28 80240D78 0280202D */  daddu     $a0, $s4, $zero
/* C40B2C 80240D7C 0260282D */  daddu     $a1, $s3, $zero
/* C40B30 80240D80 0C090000 */  jal       func_80240000_C3FDB0
/* C40B34 80240D84 02A0302D */   daddu    $a2, $s5, $zero
/* C40B38 80240D88 0280202D */  daddu     $a0, $s4, $zero
/* C40B3C 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* C40B40 80240D90 0C090056 */  jal       func_80240158_C3FF08
/* C40B44 80240D94 02A0302D */   daddu    $a2, $s5, $zero
/* C40B48 80240D98 0809039A */  j         .L80240E68
/* C40B4C 80240D9C 00000000 */   nop      
/* C40B50 80240DA0 0280202D */  daddu     $a0, $s4, $zero
/* C40B54 80240DA4 0260282D */  daddu     $a1, $s3, $zero
/* C40B58 80240DA8 0C090100 */  jal       UnkNpcAIFunc1
/* C40B5C 80240DAC 02A0302D */   daddu    $a2, $s5, $zero
/* C40B60 80240DB0 0280202D */  daddu     $a0, $s4, $zero
/* C40B64 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* C40B68 80240DB8 0C090130 */  jal       func_802404C0_C40270
/* C40B6C 80240DBC 02A0302D */   daddu    $a2, $s5, $zero
/* C40B70 80240DC0 0809039A */  j         .L80240E68
/* C40B74 80240DC4 00000000 */   nop      
/* C40B78 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* C40B7C 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* C40B80 80240DD0 0C09019F */  jal       func_8024067C_C4042C
/* C40B84 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* C40B88 80240DD8 0809039A */  j         .L80240E68
/* C40B8C 80240DDC 00000000 */   nop      
/* C40B90 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* C40B94 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* C40B98 80240DE8 0C0901CC */  jal       func_80240730_C404E0
/* C40B9C 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
/* C40BA0 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* C40BA4 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* C40BA8 80240DF8 0C0901E9 */  jal       func_802407A4_C40554
/* C40BAC 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* C40BB0 80240E00 0809039A */  j         .L80240E68
/* C40BB4 80240E04 00000000 */   nop      
/* C40BB8 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* C40BBC 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* C40BC0 80240E10 0C090207 */  jal       func_8024081C_C405CC
/* C40BC4 80240E14 02A0302D */   daddu    $a2, $s5, $zero
/* C40BC8 80240E18 0280202D */  daddu     $a0, $s4, $zero
/* C40BCC 80240E1C 0260282D */  daddu     $a1, $s3, $zero
/* C40BD0 80240E20 0C090253 */  jal       func_8024094C_C406FC
/* C40BD4 80240E24 02A0302D */   daddu    $a2, $s5, $zero
/* C40BD8 80240E28 0809039A */  j         .L80240E68
/* C40BDC 80240E2C 00000000 */   nop      
/* C40BE0 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* C40BE4 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* C40BE8 80240E38 0C09029B */  jal       func_80240A6C_C4081C
/* C40BEC 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* C40BF0 80240E40 0809039A */  j         .L80240E68
/* C40BF4 80240E44 00000000 */   nop      
/* C40BF8 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* C40BFC 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* C40C00 80240E50 0C0902B5 */  jal       func_80240AD4_C40884
/* C40C04 80240E54 02A0302D */   daddu    $a2, $s5, $zero
/* C40C08 80240E58 0809039A */  j         .L80240E68
/* C40C0C 80240E5C 00000000 */   nop      
/* C40C10 80240E60 0C0129CF */  jal       func_8004A73C
/* C40C14 80240E64 0280202D */   daddu    $a0, $s4, $zero
.L80240E68:
/* C40C18 80240E68 8FBF0060 */  lw        $ra, 0x60($sp)
/* C40C1C 80240E6C 8FB5005C */  lw        $s5, 0x5c($sp)
/* C40C20 80240E70 8FB40058 */  lw        $s4, 0x58($sp)
/* C40C24 80240E74 8FB30054 */  lw        $s3, 0x54($sp)
/* C40C28 80240E78 8FB20050 */  lw        $s2, 0x50($sp)
/* C40C2C 80240E7C 8FB1004C */  lw        $s1, 0x4c($sp)
/* C40C30 80240E80 8FB00048 */  lw        $s0, 0x48($sp)
/* C40C34 80240E84 0000102D */  daddu     $v0, $zero, $zero
/* C40C38 80240E88 03E00008 */  jr        $ra
/* C40C3C 80240E8C 27BD0068 */   addiu    $sp, $sp, 0x68
