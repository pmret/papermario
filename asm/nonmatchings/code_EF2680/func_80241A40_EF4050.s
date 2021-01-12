.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A40_EF4050
/* EF4050 80241A40 27BDFF98 */  addiu     $sp, $sp, -0x68
/* EF4054 80241A44 AFB20048 */  sw        $s2, 0x48($sp)
/* EF4058 80241A48 0080902D */  daddu     $s2, $a0, $zero
/* EF405C 80241A4C AFBF0054 */  sw        $ra, 0x54($sp)
/* EF4060 80241A50 AFB40050 */  sw        $s4, 0x50($sp)
/* EF4064 80241A54 AFB3004C */  sw        $s3, 0x4c($sp)
/* EF4068 80241A58 AFB10044 */  sw        $s1, 0x44($sp)
/* EF406C 80241A5C AFB00040 */  sw        $s0, 0x40($sp)
/* EF4070 80241A60 F7B60060 */  sdc1      $f22, 0x60($sp)
/* EF4074 80241A64 F7B40058 */  sdc1      $f20, 0x58($sp)
/* EF4078 80241A68 8E510148 */  lw        $s1, 0x148($s2)
/* EF407C 80241A6C 00A0982D */  daddu     $s3, $a1, $zero
/* EF4080 80241A70 86240008 */  lh        $a0, 8($s1)
/* EF4084 80241A74 0C00F92F */  jal       func_8003E4BC
/* EF4088 80241A78 00C0A02D */   daddu    $s4, $a2, $zero
/* EF408C 80241A7C 0040802D */  daddu     $s0, $v0, $zero
/* EF4090 80241A80 C6200078 */  lwc1      $f0, 0x78($s1)
/* EF4094 80241A84 46800020 */  cvt.s.w   $f0, $f0
/* EF4098 80241A88 46000021 */  cvt.d.s   $f0, $f0
/* EF409C 80241A8C 3C014059 */  lui       $at, 0x4059
/* EF40A0 80241A90 44814800 */  mtc1      $at, $f9
/* EF40A4 80241A94 44804000 */  mtc1      $zero, $f8
/* EF40A8 80241A98 8602008E */  lh        $v0, 0x8e($s0)
/* EF40AC 80241A9C 9603008E */  lhu       $v1, 0x8e($s0)
/* EF40B0 80241AA0 46280003 */  div.d     $f0, $f0, $f8
/* EF40B4 80241AA4 18400003 */  blez      $v0, .L80241AB4
/* EF40B8 80241AA8 462005A0 */   cvt.s.d  $f22, $f0
/* EF40BC 80241AAC 2462FFFF */  addiu     $v0, $v1, -1
/* EF40C0 80241AB0 A602008E */  sh        $v0, 0x8e($s0)
.L80241AB4:
/* EF40C4 80241AB4 27A50028 */  addiu     $a1, $sp, 0x28
/* EF40C8 80241AB8 27A6002C */  addiu     $a2, $sp, 0x2c
/* EF40CC 80241ABC 27A70030 */  addiu     $a3, $sp, 0x30
/* EF40D0 80241AC0 C6000038 */  lwc1      $f0, 0x38($s0)
/* EF40D4 80241AC4 C602003C */  lwc1      $f2, 0x3c($s0)
/* EF40D8 80241AC8 C6040040 */  lwc1      $f4, 0x40($s0)
/* EF40DC 80241ACC 3C01447A */  lui       $at, 0x447a
/* EF40E0 80241AD0 44813000 */  mtc1      $at, $f6
/* EF40E4 80241AD4 27A20034 */  addiu     $v0, $sp, 0x34
/* EF40E8 80241AD8 E7A00028 */  swc1      $f0, 0x28($sp)
/* EF40EC 80241ADC E7A2002C */  swc1      $f2, 0x2c($sp)
/* EF40F0 80241AE0 E7A40030 */  swc1      $f4, 0x30($sp)
/* EF40F4 80241AE4 E7A60034 */  swc1      $f6, 0x34($sp)
/* EF40F8 80241AE8 C6340070 */  lwc1      $f20, 0x70($s1)
/* EF40FC 80241AEC 4680A520 */  cvt.s.w   $f20, $f20
/* EF4100 80241AF0 4600A521 */  cvt.d.s   $f20, $f20
/* EF4104 80241AF4 4628A503 */  div.d     $f20, $f20, $f8
/* EF4108 80241AF8 AFA20010 */  sw        $v0, 0x10($sp)
/* EF410C 80241AFC 8E040080 */  lw        $a0, 0x80($s0)
/* EF4110 80241B00 0C03908F */  jal       func_800E423C
/* EF4114 80241B04 4620A520 */   cvt.s.d  $f20, $f20
/* EF4118 80241B08 C62C0074 */  lwc1      $f12, 0x74($s1)
/* EF411C 80241B0C 0C00AD77 */  jal       func_8002B5DC
/* EF4120 80241B10 46806320 */   cvt.s.w  $f12, $f12
/* EF4124 80241B14 46140002 */  mul.s     $f0, $f0, $f20
/* EF4128 80241B18 00000000 */  nop
/* EF412C 80241B1C C7A2002C */  lwc1      $f2, 0x2c($sp)
/* EF4130 80241B20 46161080 */  add.s     $f2, $f2, $f22
/* EF4134 80241B24 46001080 */  add.s     $f2, $f2, $f0
/* EF4138 80241B28 E602003C */  swc1      $f2, 0x3c($s0)
/* EF413C 80241B2C 8E220074 */  lw        $v0, 0x74($s1)
/* EF4140 80241B30 2442000C */  addiu     $v0, $v0, 0xc
/* EF4144 80241B34 44826000 */  mtc1      $v0, $f12
/* EF4148 80241B38 00000000 */  nop
/* EF414C 80241B3C 0C00AB85 */  jal       func_8002AE14
/* EF4150 80241B40 46806320 */   cvt.s.w  $f12, $f12
/* EF4154 80241B44 4600028D */  trunc.w.s $f10, $f0
/* EF4158 80241B48 E62A0074 */  swc1      $f10, 0x74($s1)
/* EF415C 80241B4C 0280202D */  daddu     $a0, $s4, $zero
/* EF4160 80241B50 24020001 */  addiu     $v0, $zero, 1
/* EF4164 80241B54 AFA20010 */  sw        $v0, 0x10($sp)
/* EF4168 80241B58 8E660024 */  lw        $a2, 0x24($s3)
/* EF416C 80241B5C 8E670028 */  lw        $a3, 0x28($s3)
/* EF4170 80241B60 0C013469 */  jal       func_8004D1A4
/* EF4174 80241B64 0220282D */   daddu    $a1, $s1, $zero
/* EF4178 80241B68 1040001D */  beqz      $v0, .L80241BE0
/* EF417C 80241B6C 0000202D */   daddu    $a0, $zero, $zero
/* EF4180 80241B70 0200282D */  daddu     $a1, $s0, $zero
/* EF4184 80241B74 0000302D */  daddu     $a2, $zero, $zero
/* EF4188 80241B78 860300A8 */  lh        $v1, 0xa8($s0)
/* EF418C 80241B7C 3C013F80 */  lui       $at, 0x3f80
/* EF4190 80241B80 44810000 */  mtc1      $at, $f0
/* EF4194 80241B84 3C014000 */  lui       $at, 0x4000
/* EF4198 80241B88 44811000 */  mtc1      $at, $f2
/* EF419C 80241B8C 3C01C1A0 */  lui       $at, 0xc1a0
/* EF41A0 80241B90 44812000 */  mtc1      $at, $f4
/* EF41A4 80241B94 2402000F */  addiu     $v0, $zero, 0xf
/* EF41A8 80241B98 AFA2001C */  sw        $v0, 0x1c($sp)
/* EF41AC 80241B9C 44835000 */  mtc1      $v1, $f10
/* EF41B0 80241BA0 00000000 */  nop
/* EF41B4 80241BA4 468052A0 */  cvt.s.w   $f10, $f10
/* EF41B8 80241BA8 44075000 */  mfc1      $a3, $f10
/* EF41BC 80241BAC 27A20038 */  addiu     $v0, $sp, 0x38
/* EF41C0 80241BB0 AFA20020 */  sw        $v0, 0x20($sp)
/* EF41C4 80241BB4 E7A00010 */  swc1      $f0, 0x10($sp)
/* EF41C8 80241BB8 E7A20014 */  swc1      $f2, 0x14($sp)
/* EF41CC 80241BBC 0C01D444 */  jal       func_80075110
/* EF41D0 80241BC0 E7A40018 */   swc1     $f4, 0x18($sp)
/* EF41D4 80241BC4 0200202D */  daddu     $a0, $s0, $zero
/* EF41D8 80241BC8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EF41DC 80241BCC 0C013600 */  jal       func_8004D800
/* EF41E0 80241BD0 3C060020 */   lui      $a2, 0x20
/* EF41E4 80241BD4 2402000C */  addiu     $v0, $zero, 0xc
/* EF41E8 80241BD8 0809071A */  j         .L80241C68
/* EF41EC 80241BDC AE420070 */   sw       $v0, 0x70($s2)
.L80241BE0:
/* EF41F0 80241BE0 8602008C */  lh        $v0, 0x8c($s0)
/* EF41F4 80241BE4 14400020 */  bnez      $v0, .L80241C68
/* EF41F8 80241BE8 00000000 */   nop
/* EF41FC 80241BEC 8602008E */  lh        $v0, 0x8e($s0)
/* EF4200 80241BF0 1C40001D */  bgtz      $v0, .L80241C68
/* EF4204 80241BF4 00000000 */   nop
/* EF4208 80241BF8 8E420074 */  lw        $v0, 0x74($s2)
/* EF420C 80241BFC 2442FFFF */  addiu     $v0, $v0, -1
/* EF4210 80241C00 18400018 */  blez      $v0, .L80241C64
/* EF4214 80241C04 AE420074 */   sw       $v0, 0x74($s2)
/* EF4218 80241C08 C600000C */  lwc1      $f0, 0xc($s0)
/* EF421C 80241C0C 3C014334 */  lui       $at, 0x4334
/* EF4220 80241C10 44816000 */  mtc1      $at, $f12
/* EF4224 80241C14 0C00AB85 */  jal       func_8002AE14
/* EF4228 80241C18 460C0300 */   add.s    $f12, $f0, $f12
/* EF422C 80241C1C 240403E8 */  addiu     $a0, $zero, 0x3e8
/* EF4230 80241C20 0C00AB3B */  jal       func_8002ACEC
/* EF4234 80241C24 E600000C */   swc1     $f0, 0xc($s0)
/* EF4238 80241C28 3C032E8B */  lui       $v1, 0x2e8b
/* EF423C 80241C2C 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* EF4240 80241C30 00430018 */  mult      $v0, $v1
/* EF4244 80241C34 00021FC3 */  sra       $v1, $v0, 0x1f
/* EF4248 80241C38 00004010 */  mfhi      $t0
/* EF424C 80241C3C 00082043 */  sra       $a0, $t0, 1
/* EF4250 80241C40 00832023 */  subu      $a0, $a0, $v1
/* EF4254 80241C44 00041840 */  sll       $v1, $a0, 1
/* EF4258 80241C48 00641821 */  addu      $v1, $v1, $a0
/* EF425C 80241C4C 00031880 */  sll       $v1, $v1, 2
/* EF4260 80241C50 00641823 */  subu      $v1, $v1, $a0
/* EF4264 80241C54 00431023 */  subu      $v0, $v0, $v1
/* EF4268 80241C58 24420005 */  addiu     $v0, $v0, 5
/* EF426C 80241C5C 0809071A */  j         .L80241C68
/* EF4270 80241C60 A602008E */   sh       $v0, 0x8e($s0)
.L80241C64:
/* EF4274 80241C64 AE400070 */  sw        $zero, 0x70($s2)
.L80241C68:
/* EF4278 80241C68 8FBF0054 */  lw        $ra, 0x54($sp)
/* EF427C 80241C6C 8FB40050 */  lw        $s4, 0x50($sp)
/* EF4280 80241C70 8FB3004C */  lw        $s3, 0x4c($sp)
/* EF4284 80241C74 8FB20048 */  lw        $s2, 0x48($sp)
/* EF4288 80241C78 8FB10044 */  lw        $s1, 0x44($sp)
/* EF428C 80241C7C 8FB00040 */  lw        $s0, 0x40($sp)
/* EF4290 80241C80 D7B60060 */  ldc1      $f22, 0x60($sp)
/* EF4294 80241C84 D7B40058 */  ldc1      $f20, 0x58($sp)
/* EF4298 80241C88 03E00008 */  jr        $ra
/* EF429C 80241C8C 27BD0068 */   addiu    $sp, $sp, 0x68
