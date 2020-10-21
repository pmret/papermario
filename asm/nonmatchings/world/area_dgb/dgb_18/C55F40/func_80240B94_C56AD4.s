.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B94_C56AD4
/* C56AD4 80240B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* C56AD8 80240B98 AFB40058 */  sw        $s4, 0x58($sp)
/* C56ADC 80240B9C 0080A02D */  daddu     $s4, $a0, $zero
/* C56AE0 80240BA0 AFBF0060 */  sw        $ra, 0x60($sp)
/* C56AE4 80240BA4 AFB5005C */  sw        $s5, 0x5c($sp)
/* C56AE8 80240BA8 AFB30054 */  sw        $s3, 0x54($sp)
/* C56AEC 80240BAC AFB20050 */  sw        $s2, 0x50($sp)
/* C56AF0 80240BB0 AFB1004C */  sw        $s1, 0x4c($sp)
/* C56AF4 80240BB4 AFB00048 */  sw        $s0, 0x48($sp)
/* C56AF8 80240BB8 8E910148 */  lw        $s1, 0x148($s4)
/* C56AFC 80240BBC 86240008 */  lh        $a0, 8($s1)
/* C56B00 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* C56B04 80240BC4 00A0802D */   daddu    $s0, $a1, $zero
/* C56B08 80240BC8 8E83000C */  lw        $v1, 0xc($s4)
/* C56B0C 80240BCC 0280202D */  daddu     $a0, $s4, $zero
/* C56B10 80240BD0 8C650000 */  lw        $a1, ($v1)
/* C56B14 80240BD4 0C0B1EAF */  jal       get_variable
/* C56B18 80240BD8 0040902D */   daddu    $s2, $v0, $zero
/* C56B1C 80240BDC AFA00018 */  sw        $zero, 0x18($sp)
/* C56B20 80240BE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C56B24 80240BE4 8C630094 */  lw        $v1, 0x94($v1)
/* C56B28 80240BE8 AFA3001C */  sw        $v1, 0x1c($sp)
/* C56B2C 80240BEC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C56B30 80240BF0 8C630080 */  lw        $v1, 0x80($v1)
/* C56B34 80240BF4 AFA30020 */  sw        $v1, 0x20($sp)
/* C56B38 80240BF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C56B3C 80240BFC 8C630088 */  lw        $v1, 0x88($v1)
/* C56B40 80240C00 AFA30024 */  sw        $v1, 0x24($sp)
/* C56B44 80240C04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C56B48 80240C08 8C63008C */  lw        $v1, 0x8c($v1)
/* C56B4C 80240C0C 27B50018 */  addiu     $s5, $sp, 0x18
/* C56B50 80240C10 AFA30028 */  sw        $v1, 0x28($sp)
/* C56B54 80240C14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C56B58 80240C18 3C014282 */  lui       $at, 0x4282
/* C56B5C 80240C1C 44810000 */  mtc1      $at, $f0
/* C56B60 80240C20 8C630090 */  lw        $v1, 0x90($v1)
/* C56B64 80240C24 0040982D */  daddu     $s3, $v0, $zero
/* C56B68 80240C28 E7A00030 */  swc1      $f0, 0x30($sp)
/* C56B6C 80240C2C A7A00034 */  sh        $zero, 0x34($sp)
/* C56B70 80240C30 16000005 */  bnez      $s0, .L80240C48
/* C56B74 80240C34 AFA3002C */   sw       $v1, 0x2c($sp)
/* C56B78 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C56B7C 80240C3C 30420004 */  andi      $v0, $v0, 4
/* C56B80 80240C40 10400044 */  beqz      $v0, .L80240D54
/* C56B84 80240C44 00000000 */   nop      
.L80240C48:
/* C56B88 80240C48 2404F7FF */  addiu     $a0, $zero, -0x801
/* C56B8C 80240C4C AE800070 */  sw        $zero, 0x70($s4)
/* C56B90 80240C50 A640008E */  sh        $zero, 0x8e($s2)
/* C56B94 80240C54 8E2200CC */  lw        $v0, 0xcc($s1)
/* C56B98 80240C58 8E430000 */  lw        $v1, ($s2)
/* C56B9C 80240C5C 8C420000 */  lw        $v0, ($v0)
/* C56BA0 80240C60 00641824 */  and       $v1, $v1, $a0
/* C56BA4 80240C64 AE430000 */  sw        $v1, ($s2)
/* C56BA8 80240C68 AE420028 */  sw        $v0, 0x28($s2)
/* C56BAC 80240C6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C56BB0 80240C70 8C420098 */  lw        $v0, 0x98($v0)
/* C56BB4 80240C74 54400005 */  bnel      $v0, $zero, .L80240C8C
/* C56BB8 80240C78 2402FDFF */   addiu    $v0, $zero, -0x201
/* C56BBC 80240C7C 34620200 */  ori       $v0, $v1, 0x200
/* C56BC0 80240C80 2403FFF7 */  addiu     $v1, $zero, -9
/* C56BC4 80240C84 08090325 */  j         .L80240C94
/* C56BC8 80240C88 00431024 */   and      $v0, $v0, $v1
.L80240C8C:
/* C56BCC 80240C8C 00621024 */  and       $v0, $v1, $v0
/* C56BD0 80240C90 34420008 */  ori       $v0, $v0, 8
.L80240C94:
/* C56BD4 80240C94 AE420000 */  sw        $v0, ($s2)
/* C56BD8 80240C98 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C56BDC 80240C9C 30420004 */  andi      $v0, $v0, 4
/* C56BE0 80240CA0 10400008 */  beqz      $v0, .L80240CC4
/* C56BE4 80240CA4 24020063 */   addiu    $v0, $zero, 0x63
/* C56BE8 80240CA8 AE820070 */  sw        $v0, 0x70($s4)
/* C56BEC 80240CAC AE800074 */  sw        $zero, 0x74($s4)
/* C56BF0 80240CB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C56BF4 80240CB4 2403FFFB */  addiu     $v1, $zero, -5
/* C56BF8 80240CB8 00431024 */  and       $v0, $v0, $v1
/* C56BFC 80240CBC 0809033C */  j         .L80240CF0
/* C56C00 80240CC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240CC4:
/* C56C04 80240CC4 8E220000 */  lw        $v0, ($s1)
/* C56C08 80240CC8 3C034000 */  lui       $v1, 0x4000
/* C56C0C 80240CCC 00431024 */  and       $v0, $v0, $v1
/* C56C10 80240CD0 10400007 */  beqz      $v0, .L80240CF0
/* C56C14 80240CD4 3C03BFFF */   lui      $v1, 0xbfff
/* C56C18 80240CD8 2402000C */  addiu     $v0, $zero, 0xc
/* C56C1C 80240CDC AE820070 */  sw        $v0, 0x70($s4)
/* C56C20 80240CE0 8E220000 */  lw        $v0, ($s1)
/* C56C24 80240CE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* C56C28 80240CE8 00431024 */  and       $v0, $v0, $v1
/* C56C2C 80240CEC AE220000 */  sw        $v0, ($s1)
.L80240CF0:
/* C56C30 80240CF0 27A50038 */  addiu     $a1, $sp, 0x38
/* C56C34 80240CF4 27A6003C */  addiu     $a2, $sp, 0x3c
/* C56C38 80240CF8 C6400038 */  lwc1      $f0, 0x38($s2)
/* C56C3C 80240CFC 864200A8 */  lh        $v0, 0xa8($s2)
/* C56C40 80240D00 3C0142C8 */  lui       $at, 0x42c8
/* C56C44 80240D04 44812000 */  mtc1      $at, $f4
/* C56C48 80240D08 44823000 */  mtc1      $v0, $f6
/* C56C4C 80240D0C 00000000 */  nop       
/* C56C50 80240D10 468031A0 */  cvt.s.w   $f6, $f6
/* C56C54 80240D14 27A20044 */  addiu     $v0, $sp, 0x44
/* C56C58 80240D18 E7A00038 */  swc1      $f0, 0x38($sp)
/* C56C5C 80240D1C C640003C */  lwc1      $f0, 0x3c($s2)
/* C56C60 80240D20 C6420040 */  lwc1      $f2, 0x40($s2)
/* C56C64 80240D24 46060000 */  add.s     $f0, $f0, $f6
/* C56C68 80240D28 E7A40044 */  swc1      $f4, 0x44($sp)
/* C56C6C 80240D2C E7A20040 */  swc1      $f2, 0x40($sp)
/* C56C70 80240D30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* C56C74 80240D34 AFA20010 */  sw        $v0, 0x10($sp)
/* C56C78 80240D38 8E440080 */  lw        $a0, 0x80($s2)
/* C56C7C 80240D3C 0C0372DF */  jal       func_800DCB7C
/* C56C80 80240D40 27A70040 */   addiu    $a3, $sp, 0x40
/* C56C84 80240D44 10400003 */  beqz      $v0, .L80240D54
/* C56C88 80240D48 00000000 */   nop      
/* C56C8C 80240D4C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* C56C90 80240D50 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D54:
/* C56C94 80240D54 8E830070 */  lw        $v1, 0x70($s4)
/* C56C98 80240D58 2C620064 */  sltiu     $v0, $v1, 0x64
/* C56C9C 80240D5C 10400042 */  beqz      $v0, .L80240E68
/* C56CA0 80240D60 00031080 */   sll      $v0, $v1, 2
/* C56CA4 80240D64 3C018024 */  lui       $at, 0x8024
/* C56CA8 80240D68 00220821 */  addu      $at, $at, $v0
/* C56CAC 80240D6C 8C2238F0 */  lw        $v0, 0x38f0($at)
/* C56CB0 80240D70 00400008 */  jr        $v0
/* C56CB4 80240D74 00000000 */   nop      
/* C56CB8 80240D78 0280202D */  daddu     $a0, $s4, $zero
/* C56CBC 80240D7C 0260282D */  daddu     $a1, $s3, $zero
/* C56CC0 80240D80 0C090000 */  jal       func_80240000_C55F40
/* C56CC4 80240D84 02A0302D */   daddu    $a2, $s5, $zero
/* C56CC8 80240D88 0280202D */  daddu     $a0, $s4, $zero
/* C56CCC 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* C56CD0 80240D90 0C090056 */  jal       func_80240158_C56098
/* C56CD4 80240D94 02A0302D */   daddu    $a2, $s5, $zero
/* C56CD8 80240D98 0809039A */  j         .L80240E68
/* C56CDC 80240D9C 00000000 */   nop      
/* C56CE0 80240DA0 0280202D */  daddu     $a0, $s4, $zero
/* C56CE4 80240DA4 0260282D */  daddu     $a1, $s3, $zero
/* C56CE8 80240DA8 0C090100 */  jal       func_80240400_C56340
/* C56CEC 80240DAC 02A0302D */   daddu    $a2, $s5, $zero
/* C56CF0 80240DB0 0280202D */  daddu     $a0, $s4, $zero
/* C56CF4 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* C56CF8 80240DB8 0C090130 */  jal       func_802404C0_C56400
/* C56CFC 80240DBC 02A0302D */   daddu    $a2, $s5, $zero
/* C56D00 80240DC0 0809039A */  j         .L80240E68
/* C56D04 80240DC4 00000000 */   nop      
/* C56D08 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* C56D0C 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* C56D10 80240DD0 0C09019F */  jal       func_8024067C_C565BC
/* C56D14 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* C56D18 80240DD8 0809039A */  j         .L80240E68
/* C56D1C 80240DDC 00000000 */   nop      
/* C56D20 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* C56D24 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* C56D28 80240DE8 0C0901CC */  jal       func_80240730_C56670
/* C56D2C 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
/* C56D30 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* C56D34 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* C56D38 80240DF8 0C0901E9 */  jal       func_802407A4_C566E4
/* C56D3C 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* C56D40 80240E00 0809039A */  j         .L80240E68
/* C56D44 80240E04 00000000 */   nop      
/* C56D48 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* C56D4C 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* C56D50 80240E10 0C090207 */  jal       func_8024081C_C5675C
/* C56D54 80240E14 02A0302D */   daddu    $a2, $s5, $zero
/* C56D58 80240E18 0280202D */  daddu     $a0, $s4, $zero
/* C56D5C 80240E1C 0260282D */  daddu     $a1, $s3, $zero
/* C56D60 80240E20 0C090253 */  jal       func_8024094C_C5688C
/* C56D64 80240E24 02A0302D */   daddu    $a2, $s5, $zero
/* C56D68 80240E28 0809039A */  j         .L80240E68
/* C56D6C 80240E2C 00000000 */   nop      
/* C56D70 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* C56D74 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* C56D78 80240E38 0C09029B */  jal       func_80240A6C_C569AC
/* C56D7C 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* C56D80 80240E40 0809039A */  j         .L80240E68
/* C56D84 80240E44 00000000 */   nop      
/* C56D88 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* C56D8C 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* C56D90 80240E50 0C0902B5 */  jal       func_80240AD4_C56A14
/* C56D94 80240E54 02A0302D */   daddu    $a2, $s5, $zero
/* C56D98 80240E58 0809039A */  j         .L80240E68
/* C56D9C 80240E5C 00000000 */   nop      
/* C56DA0 80240E60 0C0129CF */  jal       func_8004A73C
/* C56DA4 80240E64 0280202D */   daddu    $a0, $s4, $zero
.L80240E68:
/* C56DA8 80240E68 8FBF0060 */  lw        $ra, 0x60($sp)
/* C56DAC 80240E6C 8FB5005C */  lw        $s5, 0x5c($sp)
/* C56DB0 80240E70 8FB40058 */  lw        $s4, 0x58($sp)
/* C56DB4 80240E74 8FB30054 */  lw        $s3, 0x54($sp)
/* C56DB8 80240E78 8FB20050 */  lw        $s2, 0x50($sp)
/* C56DBC 80240E7C 8FB1004C */  lw        $s1, 0x4c($sp)
/* C56DC0 80240E80 8FB00048 */  lw        $s0, 0x48($sp)
/* C56DC4 80240E84 0000102D */  daddu     $v0, $zero, $zero
/* C56DC8 80240E88 03E00008 */  jr        $ra
/* C56DCC 80240E8C 27BD0068 */   addiu    $sp, $sp, 0x68
