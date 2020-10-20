.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A14
/* CD8CF4 80241A14 27BDFF98 */  addiu     $sp, $sp, -0x68
/* CD8CF8 80241A18 AFB20048 */  sw        $s2, 0x48($sp)
/* CD8CFC 80241A1C 0080902D */  daddu     $s2, $a0, $zero
/* CD8D00 80241A20 AFBF0054 */  sw        $ra, 0x54($sp)
/* CD8D04 80241A24 AFB40050 */  sw        $s4, 0x50($sp)
/* CD8D08 80241A28 AFB3004C */  sw        $s3, 0x4c($sp)
/* CD8D0C 80241A2C AFB10044 */  sw        $s1, 0x44($sp)
/* CD8D10 80241A30 AFB00040 */  sw        $s0, 0x40($sp)
/* CD8D14 80241A34 F7B60060 */  sdc1      $f22, 0x60($sp)
/* CD8D18 80241A38 F7B40058 */  sdc1      $f20, 0x58($sp)
/* CD8D1C 80241A3C 8E510148 */  lw        $s1, 0x148($s2)
/* CD8D20 80241A40 00A0982D */  daddu     $s3, $a1, $zero
/* CD8D24 80241A44 86240008 */  lh        $a0, 8($s1)
/* CD8D28 80241A48 0C00EABB */  jal       get_npc_unsafe
/* CD8D2C 80241A4C 00C0A02D */   daddu    $s4, $a2, $zero
/* CD8D30 80241A50 0040802D */  daddu     $s0, $v0, $zero
/* CD8D34 80241A54 C6200078 */  lwc1      $f0, 0x78($s1)
/* CD8D38 80241A58 46800020 */  cvt.s.w   $f0, $f0
/* CD8D3C 80241A5C 46000021 */  cvt.d.s   $f0, $f0
/* CD8D40 80241A60 3C014059 */  lui       $at, 0x4059
/* CD8D44 80241A64 44814800 */  mtc1      $at, $f9
/* CD8D48 80241A68 44804000 */  mtc1      $zero, $f8
/* CD8D4C 80241A6C 8602008E */  lh        $v0, 0x8e($s0)
/* CD8D50 80241A70 9603008E */  lhu       $v1, 0x8e($s0)
/* CD8D54 80241A74 46280003 */  div.d     $f0, $f0, $f8
/* CD8D58 80241A78 18400003 */  blez      $v0, .L80241A88
/* CD8D5C 80241A7C 462005A0 */   cvt.s.d  $f22, $f0
/* CD8D60 80241A80 2462FFFF */  addiu     $v0, $v1, -1
/* CD8D64 80241A84 A602008E */  sh        $v0, 0x8e($s0)
.L80241A88:
/* CD8D68 80241A88 27A50028 */  addiu     $a1, $sp, 0x28
/* CD8D6C 80241A8C 27A6002C */  addiu     $a2, $sp, 0x2c
/* CD8D70 80241A90 27A70030 */  addiu     $a3, $sp, 0x30
/* CD8D74 80241A94 C6000038 */  lwc1      $f0, 0x38($s0)
/* CD8D78 80241A98 C602003C */  lwc1      $f2, 0x3c($s0)
/* CD8D7C 80241A9C C6040040 */  lwc1      $f4, 0x40($s0)
/* CD8D80 80241AA0 3C01447A */  lui       $at, 0x447a
/* CD8D84 80241AA4 44813000 */  mtc1      $at, $f6
/* CD8D88 80241AA8 27A20034 */  addiu     $v0, $sp, 0x34
/* CD8D8C 80241AAC E7A00028 */  swc1      $f0, 0x28($sp)
/* CD8D90 80241AB0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CD8D94 80241AB4 E7A40030 */  swc1      $f4, 0x30($sp)
/* CD8D98 80241AB8 E7A60034 */  swc1      $f6, 0x34($sp)
/* CD8D9C 80241ABC C6340070 */  lwc1      $f20, 0x70($s1)
/* CD8DA0 80241AC0 4680A520 */  cvt.s.w   $f20, $f20
/* CD8DA4 80241AC4 4600A521 */  cvt.d.s   $f20, $f20
/* CD8DA8 80241AC8 4628A503 */  div.d     $f20, $f20, $f8
/* CD8DAC 80241ACC AFA20010 */  sw        $v0, 0x10($sp)
/* CD8DB0 80241AD0 8E040080 */  lw        $a0, 0x80($s0)
/* CD8DB4 80241AD4 0C0372DF */  jal       func_800DCB7C
/* CD8DB8 80241AD8 4620A520 */   cvt.s.d  $f20, $f20
/* CD8DBC 80241ADC C62C0074 */  lwc1      $f12, 0x74($s1)
/* CD8DC0 80241AE0 0C00A8BB */  jal       sin_deg
/* CD8DC4 80241AE4 46806320 */   cvt.s.w  $f12, $f12
/* CD8DC8 80241AE8 46140002 */  mul.s     $f0, $f0, $f20
/* CD8DCC 80241AEC 00000000 */  nop       
/* CD8DD0 80241AF0 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* CD8DD4 80241AF4 46161080 */  add.s     $f2, $f2, $f22
/* CD8DD8 80241AF8 46001080 */  add.s     $f2, $f2, $f0
/* CD8DDC 80241AFC E602003C */  swc1      $f2, 0x3c($s0)
/* CD8DE0 80241B00 8E220074 */  lw        $v0, 0x74($s1)
/* CD8DE4 80241B04 2442000C */  addiu     $v0, $v0, 0xc
/* CD8DE8 80241B08 44826000 */  mtc1      $v0, $f12
/* CD8DEC 80241B0C 00000000 */  nop       
/* CD8DF0 80241B10 0C00A6C9 */  jal       clamp_angle
/* CD8DF4 80241B14 46806320 */   cvt.s.w  $f12, $f12
/* CD8DF8 80241B18 4600028D */  trunc.w.s $f10, $f0
/* CD8DFC 80241B1C E62A0074 */  swc1      $f10, 0x74($s1)
/* CD8E00 80241B20 0280202D */  daddu     $a0, $s4, $zero
/* CD8E04 80241B24 24020001 */  addiu     $v0, $zero, 1
/* CD8E08 80241B28 AFA20010 */  sw        $v0, 0x10($sp)
/* CD8E0C 80241B2C 8E660024 */  lw        $a2, 0x24($s3)
/* CD8E10 80241B30 8E670028 */  lw        $a3, 0x28($s3)
/* CD8E14 80241B34 0C01242D */  jal       func_800490B4
/* CD8E18 80241B38 0220282D */   daddu    $a1, $s1, $zero
/* CD8E1C 80241B3C 1040001D */  beqz      $v0, .L80241BB4
/* CD8E20 80241B40 0000202D */   daddu    $a0, $zero, $zero
/* CD8E24 80241B44 0200282D */  daddu     $a1, $s0, $zero
/* CD8E28 80241B48 0000302D */  daddu     $a2, $zero, $zero
/* CD8E2C 80241B4C 860300A8 */  lh        $v1, 0xa8($s0)
/* CD8E30 80241B50 3C013F80 */  lui       $at, 0x3f80
/* CD8E34 80241B54 44810000 */  mtc1      $at, $f0
/* CD8E38 80241B58 3C014000 */  lui       $at, 0x4000
/* CD8E3C 80241B5C 44811000 */  mtc1      $at, $f2
/* CD8E40 80241B60 3C01C1A0 */  lui       $at, 0xc1a0
/* CD8E44 80241B64 44812000 */  mtc1      $at, $f4
/* CD8E48 80241B68 2402000F */  addiu     $v0, $zero, 0xf
/* CD8E4C 80241B6C AFA2001C */  sw        $v0, 0x1c($sp)
/* CD8E50 80241B70 44835000 */  mtc1      $v1, $f10
/* CD8E54 80241B74 00000000 */  nop       
/* CD8E58 80241B78 468052A0 */  cvt.s.w   $f10, $f10
/* CD8E5C 80241B7C 44075000 */  mfc1      $a3, $f10
/* CD8E60 80241B80 27A20038 */  addiu     $v0, $sp, 0x38
/* CD8E64 80241B84 AFA20020 */  sw        $v0, 0x20($sp)
/* CD8E68 80241B88 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD8E6C 80241B8C E7A20014 */  swc1      $f2, 0x14($sp)
/* CD8E70 80241B90 0C01BFA4 */  jal       fx_emote
/* CD8E74 80241B94 E7A40018 */   swc1     $f4, 0x18($sp)
/* CD8E78 80241B98 0200202D */  daddu     $a0, $s0, $zero
/* CD8E7C 80241B9C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CD8E80 80241BA0 0C012530 */  jal       func_800494C0
/* CD8E84 80241BA4 3C060020 */   lui      $a2, 0x20
/* CD8E88 80241BA8 2402000C */  addiu     $v0, $zero, 0xc
/* CD8E8C 80241BAC 0809070F */  j         .L80241C3C
/* CD8E90 80241BB0 AE420070 */   sw       $v0, 0x70($s2)
.L80241BB4:
/* CD8E94 80241BB4 8602008C */  lh        $v0, 0x8c($s0)
/* CD8E98 80241BB8 14400020 */  bnez      $v0, .L80241C3C
/* CD8E9C 80241BBC 00000000 */   nop      
/* CD8EA0 80241BC0 8602008E */  lh        $v0, 0x8e($s0)
/* CD8EA4 80241BC4 1C40001D */  bgtz      $v0, .L80241C3C
/* CD8EA8 80241BC8 00000000 */   nop      
/* CD8EAC 80241BCC 8E420074 */  lw        $v0, 0x74($s2)
/* CD8EB0 80241BD0 2442FFFF */  addiu     $v0, $v0, -1
/* CD8EB4 80241BD4 18400018 */  blez      $v0, .L80241C38
/* CD8EB8 80241BD8 AE420074 */   sw       $v0, 0x74($s2)
/* CD8EBC 80241BDC C600000C */  lwc1      $f0, 0xc($s0)
/* CD8EC0 80241BE0 3C014334 */  lui       $at, 0x4334
/* CD8EC4 80241BE4 44816000 */  mtc1      $at, $f12
/* CD8EC8 80241BE8 0C00A6C9 */  jal       clamp_angle
/* CD8ECC 80241BEC 460C0300 */   add.s    $f12, $f0, $f12
/* CD8ED0 80241BF0 240403E8 */  addiu     $a0, $zero, 0x3e8
/* CD8ED4 80241BF4 0C00A67F */  jal       rand_int
/* CD8ED8 80241BF8 E600000C */   swc1     $f0, 0xc($s0)
/* CD8EDC 80241BFC 3C032E8B */  lui       $v1, 0x2e8b
/* CD8EE0 80241C00 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* CD8EE4 80241C04 00430018 */  mult      $v0, $v1
/* CD8EE8 80241C08 00021FC3 */  sra       $v1, $v0, 0x1f
/* CD8EEC 80241C0C 00004010 */  mfhi      $t0
/* CD8EF0 80241C10 00082043 */  sra       $a0, $t0, 1
/* CD8EF4 80241C14 00832023 */  subu      $a0, $a0, $v1
/* CD8EF8 80241C18 00041840 */  sll       $v1, $a0, 1
/* CD8EFC 80241C1C 00641821 */  addu      $v1, $v1, $a0
/* CD8F00 80241C20 00031880 */  sll       $v1, $v1, 2
/* CD8F04 80241C24 00641823 */  subu      $v1, $v1, $a0
/* CD8F08 80241C28 00431023 */  subu      $v0, $v0, $v1
/* CD8F0C 80241C2C 24420005 */  addiu     $v0, $v0, 5
/* CD8F10 80241C30 0809070F */  j         .L80241C3C
/* CD8F14 80241C34 A602008E */   sh       $v0, 0x8e($s0)
.L80241C38:
/* CD8F18 80241C38 AE400070 */  sw        $zero, 0x70($s2)
.L80241C3C:
/* CD8F1C 80241C3C 8FBF0054 */  lw        $ra, 0x54($sp)
/* CD8F20 80241C40 8FB40050 */  lw        $s4, 0x50($sp)
/* CD8F24 80241C44 8FB3004C */  lw        $s3, 0x4c($sp)
/* CD8F28 80241C48 8FB20048 */  lw        $s2, 0x48($sp)
/* CD8F2C 80241C4C 8FB10044 */  lw        $s1, 0x44($sp)
/* CD8F30 80241C50 8FB00040 */  lw        $s0, 0x40($sp)
/* CD8F34 80241C54 D7B60060 */  ldc1      $f22, 0x60($sp)
/* CD8F38 80241C58 D7B40058 */  ldc1      $f20, 0x58($sp)
/* CD8F3C 80241C5C 03E00008 */  jr        $ra
/* CD8F40 80241C60 27BD0068 */   addiu    $sp, $sp, 0x68
