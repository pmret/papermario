.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A88_C81C28
/* C81C28 80241A88 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* C81C2C 80241A8C AFB3004C */  sw        $s3, 0x4c($sp)
/* C81C30 80241A90 0080982D */  daddu     $s3, $a0, $zero
/* C81C34 80241A94 AFBF0050 */  sw        $ra, 0x50($sp)
/* C81C38 80241A98 AFB20048 */  sw        $s2, 0x48($sp)
/* C81C3C 80241A9C AFB10044 */  sw        $s1, 0x44($sp)
/* C81C40 80241AA0 AFB00040 */  sw        $s0, 0x40($sp)
/* C81C44 80241AA4 8E720148 */  lw        $s2, 0x148($s3)
/* C81C48 80241AA8 00A0882D */  daddu     $s1, $a1, $zero
/* C81C4C 80241AAC 86440008 */  lh        $a0, 8($s2)
/* C81C50 80241AB0 0C00EABB */  jal       get_npc_unsafe
/* C81C54 80241AB4 00C0802D */   daddu    $s0, $a2, $zero
/* C81C58 80241AB8 0200202D */  daddu     $a0, $s0, $zero
/* C81C5C 80241ABC 0240282D */  daddu     $a1, $s2, $zero
/* C81C60 80241AC0 24030001 */  addiu     $v1, $zero, 1
/* C81C64 80241AC4 AFA30010 */  sw        $v1, 0x10($sp)
/* C81C68 80241AC8 8E260024 */  lw        $a2, 0x24($s1)
/* C81C6C 80241ACC 8E270028 */  lw        $a3, 0x28($s1)
/* C81C70 80241AD0 0C01242D */  jal       func_800490B4
/* C81C74 80241AD4 0040802D */   daddu    $s0, $v0, $zero
/* C81C78 80241AD8 14400020 */  bnez      $v0, .L80241B5C
/* C81C7C 80241ADC 24040002 */   addiu    $a0, $zero, 2
/* C81C80 80241AE0 0200282D */  daddu     $a1, $s0, $zero
/* C81C84 80241AE4 0000302D */  daddu     $a2, $zero, $zero
/* C81C88 80241AE8 860300A8 */  lh        $v1, 0xa8($s0)
/* C81C8C 80241AEC 3C013F80 */  lui       $at, 0x3f80
/* C81C90 80241AF0 44810000 */  mtc1      $at, $f0
/* C81C94 80241AF4 3C014000 */  lui       $at, 0x4000
/* C81C98 80241AF8 44811000 */  mtc1      $at, $f2
/* C81C9C 80241AFC 3C01C1A0 */  lui       $at, 0xc1a0
/* C81CA0 80241B00 44812000 */  mtc1      $at, $f4
/* C81CA4 80241B04 2402000F */  addiu     $v0, $zero, 0xf
/* C81CA8 80241B08 AFA2001C */  sw        $v0, 0x1c($sp)
/* C81CAC 80241B0C 44834000 */  mtc1      $v1, $f8
/* C81CB0 80241B10 00000000 */  nop
/* C81CB4 80241B14 46804220 */  cvt.s.w   $f8, $f8
/* C81CB8 80241B18 44074000 */  mfc1      $a3, $f8
/* C81CBC 80241B1C 27A20028 */  addiu     $v0, $sp, 0x28
/* C81CC0 80241B20 AFA20020 */  sw        $v0, 0x20($sp)
/* C81CC4 80241B24 E7A00010 */  swc1      $f0, 0x10($sp)
/* C81CC8 80241B28 E7A20014 */  swc1      $f2, 0x14($sp)
/* C81CCC 80241B2C 0C01BFA4 */  jal       fx_emote
/* C81CD0 80241B30 E7A40018 */   swc1     $f4, 0x18($sp)
/* C81CD4 80241B34 8E4200CC */  lw        $v0, 0xcc($s2)
/* C81CD8 80241B38 8C430000 */  lw        $v1, ($v0)
/* C81CDC 80241B3C 2402001E */  addiu     $v0, $zero, 0x1e
/* C81CE0 80241B40 A602008E */  sh        $v0, 0x8e($s0)
/* C81CE4 80241B44 24020014 */  addiu     $v0, $zero, 0x14
/* C81CE8 80241B48 AE030028 */  sw        $v1, 0x28($s0)
/* C81CEC 80241B4C AE620070 */  sw        $v0, 0x70($s3)
/* C81CF0 80241B50 2402001E */  addiu     $v0, $zero, 0x1e
/* C81CF4 80241B54 0809073B */  j         .L80241CEC
/* C81CF8 80241B58 AE420090 */   sw       $v0, 0x90($s2)
.L80241B5C:
/* C81CFC 80241B5C 8E050018 */  lw        $a1, 0x18($s0)
/* C81D00 80241B60 8E06000C */  lw        $a2, 0xc($s0)
/* C81D04 80241B64 0C00EA95 */  jal       npc_move_heading
/* C81D08 80241B68 0200202D */   daddu    $a0, $s0, $zero
/* C81D0C 80241B6C 8E020000 */  lw        $v0, ($s0)
/* C81D10 80241B70 30420008 */  andi      $v0, $v0, 8
/* C81D14 80241B74 14400028 */  bnez      $v0, .L80241C18
/* C81D18 80241B78 0000882D */   daddu    $s1, $zero, $zero
/* C81D1C 80241B7C 27A5002C */  addiu     $a1, $sp, 0x2c
/* C81D20 80241B80 27A60030 */  addiu     $a2, $sp, 0x30
/* C81D24 80241B84 860200A8 */  lh        $v0, 0xa8($s0)
/* C81D28 80241B88 C6000038 */  lwc1      $f0, 0x38($s0)
/* C81D2C 80241B8C 44821000 */  mtc1      $v0, $f2
/* C81D30 80241B90 00000000 */  nop
/* C81D34 80241B94 468010A0 */  cvt.s.w   $f2, $f2
/* C81D38 80241B98 E7A0002C */  swc1      $f0, 0x2c($sp)
/* C81D3C 80241B9C 860200A8 */  lh        $v0, 0xa8($s0)
/* C81D40 80241BA0 C604003C */  lwc1      $f4, 0x3c($s0)
/* C81D44 80241BA4 C6060040 */  lwc1      $f6, 0x40($s0)
/* C81D48 80241BA8 44820000 */  mtc1      $v0, $f0
/* C81D4C 80241BAC 00000000 */  nop
/* C81D50 80241BB0 46800021 */  cvt.d.w   $f0, $f0
/* C81D54 80241BB4 46022100 */  add.s     $f4, $f4, $f2
/* C81D58 80241BB8 3C014008 */  lui       $at, 0x4008
/* C81D5C 80241BBC 44811800 */  mtc1      $at, $f3
/* C81D60 80241BC0 44801000 */  mtc1      $zero, $f2
/* C81D64 80241BC4 27A20038 */  addiu     $v0, $sp, 0x38
/* C81D68 80241BC8 46220000 */  add.d     $f0, $f0, $f2
/* C81D6C 80241BCC E7A60034 */  swc1      $f6, 0x34($sp)
/* C81D70 80241BD0 E7A40030 */  swc1      $f4, 0x30($sp)
/* C81D74 80241BD4 46200020 */  cvt.s.d   $f0, $f0
/* C81D78 80241BD8 E7A00038 */  swc1      $f0, 0x38($sp)
/* C81D7C 80241BDC AFA20010 */  sw        $v0, 0x10($sp)
/* C81D80 80241BE0 8E040080 */  lw        $a0, 0x80($s0)
/* C81D84 80241BE4 0C0372DF */  jal       func_800DCB7C
/* C81D88 80241BE8 27A70034 */   addiu    $a3, $sp, 0x34
/* C81D8C 80241BEC 1040000A */  beqz      $v0, .L80241C18
/* C81D90 80241BF0 00000000 */   nop
/* C81D94 80241BF4 860200A8 */  lh        $v0, 0xa8($s0)
/* C81D98 80241BF8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* C81D9C 80241BFC 44820000 */  mtc1      $v0, $f0
/* C81DA0 80241C00 00000000 */  nop
/* C81DA4 80241C04 46800020 */  cvt.s.w   $f0, $f0
/* C81DA8 80241C08 4600103C */  c.lt.s    $f2, $f0
/* C81DAC 80241C0C 00000000 */  nop
/* C81DB0 80241C10 45030001 */  bc1tl     .L80241C18
/* C81DB4 80241C14 24110001 */   addiu    $s1, $zero, 1
.L80241C18:
/* C81DB8 80241C18 12200008 */  beqz      $s1, .L80241C3C
/* C81DBC 80241C1C 00000000 */   nop
/* C81DC0 80241C20 C7A00030 */  lwc1      $f0, 0x30($sp)
/* C81DC4 80241C24 3C013FF0 */  lui       $at, 0x3ff0
/* C81DC8 80241C28 44811800 */  mtc1      $at, $f3
/* C81DCC 80241C2C 44801000 */  mtc1      $zero, $f2
/* C81DD0 80241C30 46000021 */  cvt.d.s   $f0, $f0
/* C81DD4 80241C34 08090731 */  j         .L80241CC4
/* C81DD8 80241C38 46220000 */   add.d    $f0, $f0, $f2
.L80241C3C:
/* C81DDC 80241C3C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C81DE0 80241C40 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C81DE4 80241C44 3C014018 */  lui       $at, 0x4018
/* C81DE8 80241C48 44811800 */  mtc1      $at, $f3
/* C81DEC 80241C4C 44801000 */  mtc1      $zero, $f2
/* C81DF0 80241C50 C440002C */  lwc1      $f0, 0x2c($v0)
/* C81DF4 80241C54 C604003C */  lwc1      $f4, 0x3c($s0)
/* C81DF8 80241C58 46000021 */  cvt.d.s   $f0, $f0
/* C81DFC 80241C5C 46220000 */  add.d     $f0, $f0, $f2
/* C81E00 80241C60 46002121 */  cvt.d.s   $f4, $f4
/* C81E04 80241C64 46202001 */  sub.d     $f0, $f4, $f0
/* C81E08 80241C68 462001A0 */  cvt.s.d   $f6, $f0
/* C81E0C 80241C6C 44800000 */  mtc1      $zero, $f0
/* C81E10 80241C70 44800800 */  mtc1      $zero, $f1
/* C81E14 80241C74 460030A1 */  cvt.d.s   $f2, $f6
/* C81E18 80241C78 4620103C */  c.lt.d    $f2, $f0
/* C81E1C 80241C7C 00000000 */  nop
/* C81E20 80241C80 45010009 */  bc1t      .L80241CA8
/* C81E24 80241C84 00000000 */   nop
/* C81E28 80241C88 3C014010 */  lui       $at, 0x4010
/* C81E2C 80241C8C 44810800 */  mtc1      $at, $f1
/* C81E30 80241C90 44800000 */  mtc1      $zero, $f0
/* C81E34 80241C94 00000000 */  nop
/* C81E38 80241C98 4622003C */  c.lt.d    $f0, $f2
/* C81E3C 80241C9C 00000000 */  nop
/* C81E40 80241CA0 4500000A */  bc1f      .L80241CCC
/* C81E44 80241CA4 00000000 */   nop
.L80241CA8:
/* C81E48 80241CA8 3C018024 */  lui       $at, %hi(D_802458A8)
/* C81E4C 80241CAC D42258A8 */  ldc1      $f2, %lo(D_802458A8)($at)
/* C81E50 80241CB0 46003187 */  neg.s     $f6, $f6
/* C81E54 80241CB4 46003021 */  cvt.d.s   $f0, $f6
/* C81E58 80241CB8 46220002 */  mul.d     $f0, $f0, $f2
/* C81E5C 80241CBC 00000000 */  nop
/* C81E60 80241CC0 46202000 */  add.d     $f0, $f4, $f0
.L80241CC4:
/* C81E64 80241CC4 46200020 */  cvt.s.d   $f0, $f0
/* C81E68 80241CC8 E600003C */  swc1      $f0, 0x3c($s0)
.L80241CCC:
/* C81E6C 80241CCC 8602008E */  lh        $v0, 0x8e($s0)
/* C81E70 80241CD0 9603008E */  lhu       $v1, 0x8e($s0)
/* C81E74 80241CD4 18400003 */  blez      $v0, .L80241CE4
/* C81E78 80241CD8 2462FFFF */   addiu    $v0, $v1, -1
/* C81E7C 80241CDC 0809073B */  j         .L80241CEC
/* C81E80 80241CE0 A602008E */   sh       $v0, 0x8e($s0)
.L80241CE4:
/* C81E84 80241CE4 2402000C */  addiu     $v0, $zero, 0xc
/* C81E88 80241CE8 AE620070 */  sw        $v0, 0x70($s3)
.L80241CEC:
/* C81E8C 80241CEC 8FBF0050 */  lw        $ra, 0x50($sp)
/* C81E90 80241CF0 8FB3004C */  lw        $s3, 0x4c($sp)
/* C81E94 80241CF4 8FB20048 */  lw        $s2, 0x48($sp)
/* C81E98 80241CF8 8FB10044 */  lw        $s1, 0x44($sp)
/* C81E9C 80241CFC 8FB00040 */  lw        $s0, 0x40($sp)
/* C81EA0 80241D00 03E00008 */  jr        $ra
/* C81EA4 80241D04 27BD0058 */   addiu    $sp, $sp, 0x58
