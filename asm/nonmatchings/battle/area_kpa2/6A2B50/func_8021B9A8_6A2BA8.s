.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B9A8_6A2BA8
/* 6A2BA8 8021B9A8 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 6A2BAC 8021B9AC AFB10044 */  sw        $s1, 0x44($sp)
/* 6A2BB0 8021B9B0 0080882D */  daddu     $s1, $a0, $zero
/* 6A2BB4 8021B9B4 AFBF0064 */  sw        $ra, 0x64($sp)
/* 6A2BB8 8021B9B8 AFBE0060 */  sw        $fp, 0x60($sp)
/* 6A2BBC 8021B9BC AFB7005C */  sw        $s7, 0x5c($sp)
/* 6A2BC0 8021B9C0 AFB60058 */  sw        $s6, 0x58($sp)
/* 6A2BC4 8021B9C4 AFB50054 */  sw        $s5, 0x54($sp)
/* 6A2BC8 8021B9C8 AFB40050 */  sw        $s4, 0x50($sp)
/* 6A2BCC 8021B9CC AFB3004C */  sw        $s3, 0x4c($sp)
/* 6A2BD0 8021B9D0 AFB20048 */  sw        $s2, 0x48($sp)
/* 6A2BD4 8021B9D4 AFB00040 */  sw        $s0, 0x40($sp)
/* 6A2BD8 8021B9D8 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* 6A2BDC 8021B9DC F7B80078 */  sdc1      $f24, 0x78($sp)
/* 6A2BE0 8021B9E0 F7B60070 */  sdc1      $f22, 0x70($sp)
/* 6A2BE4 8021B9E4 F7B40068 */  sdc1      $f20, 0x68($sp)
/* 6A2BE8 8021B9E8 8E30000C */  lw        $s0, 0xc($s1)
/* 6A2BEC 8021B9EC 3C0B8023 */  lui       $t3, %hi(D_80234810_6BBA10)
/* 6A2BF0 8021B9F0 256B4810 */  addiu     $t3, $t3, %lo(D_80234810_6BBA10)
/* 6A2BF4 8021B9F4 8D680000 */  lw        $t0, ($t3)
/* 6A2BF8 8021B9F8 8D690004 */  lw        $t1, 4($t3)
/* 6A2BFC 8021B9FC 8D6A0008 */  lw        $t2, 8($t3)
/* 6A2C00 8021BA00 AFA80028 */  sw        $t0, 0x28($sp)
/* 6A2C04 8021BA04 AFA9002C */  sw        $t1, 0x2c($sp)
/* 6A2C08 8021BA08 AFAA0030 */  sw        $t2, 0x30($sp)
/* 6A2C0C 8021BA0C 8D68000C */  lw        $t0, 0xc($t3)
/* 6A2C10 8021BA10 8D690010 */  lw        $t1, 0x10($t3)
/* 6A2C14 8021BA14 8D6A0014 */  lw        $t2, 0x14($t3)
/* 6A2C18 8021BA18 AFA80034 */  sw        $t0, 0x34($sp)
/* 6A2C1C 8021BA1C AFA90038 */  sw        $t1, 0x38($sp)
/* 6A2C20 8021BA20 AFAA003C */  sw        $t2, 0x3c($sp)
/* 6A2C24 8021BA24 0C09A75B */  jal       get_actor
/* 6A2C28 8021BA28 8E240148 */   lw       $a0, 0x148($s1)
/* 6A2C2C 8021BA2C 0040902D */  daddu     $s2, $v0, $zero
/* 6A2C30 8021BA30 1240007B */  beqz      $s2, .L8021BC20
/* 6A2C34 8021BA34 24020002 */   addiu    $v0, $zero, 2
/* 6A2C38 8021BA38 8E050000 */  lw        $a1, ($s0)
/* 6A2C3C 8021BA3C 26100004 */  addiu     $s0, $s0, 4
/* 6A2C40 8021BA40 0C0B1EAF */  jal       get_variable
/* 6A2C44 8021BA44 0220202D */   daddu    $a0, $s1, $zero
/* 6A2C48 8021BA48 8E050000 */  lw        $a1, ($s0)
/* 6A2C4C 8021BA4C 26100004 */  addiu     $s0, $s0, 4
/* 6A2C50 8021BA50 0220202D */  daddu     $a0, $s1, $zero
/* 6A2C54 8021BA54 0C0B1EAF */  jal       get_variable
/* 6A2C58 8021BA58 0040F02D */   daddu    $fp, $v0, $zero
/* 6A2C5C 8021BA5C 0040A82D */  daddu     $s5, $v0, $zero
/* 6A2C60 8021BA60 8E050000 */  lw        $a1, ($s0)
/* 6A2C64 8021BA64 26100004 */  addiu     $s0, $s0, 4
/* 6A2C68 8021BA68 0C0B1EAF */  jal       get_variable
/* 6A2C6C 8021BA6C 0220202D */   daddu    $a0, $s1, $zero
/* 6A2C70 8021BA70 0220202D */  daddu     $a0, $s1, $zero
/* 6A2C74 8021BA74 8E050000 */  lw        $a1, ($s0)
/* 6A2C78 8021BA78 0C0B210B */  jal       get_float_variable
/* 6A2C7C 8021BA7C 0040B02D */   daddu    $s6, $v0, $zero
/* 6A2C80 8021BA80 82430210 */  lb        $v1, 0x210($s2)
/* 6A2C84 8021BA84 2402000A */  addiu     $v0, $zero, 0xa
/* 6A2C88 8021BA88 1062000E */  beq       $v1, $v0, .L8021BAC4
/* 6A2C8C 8021BA8C 46000606 */   mov.s    $f24, $f0
/* 6A2C90 8021BA90 3C014210 */  lui       $at, 0x4210
/* 6A2C94 8021BA94 44811000 */  mtc1      $at, $f2
/* 6A2C98 8021BA98 00000000 */  nop
/* 6A2C9C 8021BA9C 4602C082 */  mul.s     $f2, $f24, $f2
/* 6A2CA0 8021BAA0 00000000 */  nop
/* 6A2CA4 8021BAA4 44950000 */  mtc1      $s5, $f0
/* 6A2CA8 8021BAA8 00000000 */  nop
/* 6A2CAC 8021BAAC 46800020 */  cvt.s.w   $f0, $f0
/* 6A2CB0 8021BAB0 46020000 */  add.s     $f0, $f0, $f2
/* 6A2CB4 8021BAB4 4600010D */  trunc.w.s $f4, $f0
/* 6A2CB8 8021BAB8 44152000 */  mfc1      $s5, $f4
/* 6A2CBC 8021BABC 08086EBD */  j         .L8021BAF4
/* 6A2CC0 8021BAC0 0000A02D */   daddu    $s4, $zero, $zero
.L8021BAC4:
/* 6A2CC4 8021BAC4 3C018023 */  lui       $at, %hi(D_80234828_6BBA28)
/* 6A2CC8 8021BAC8 D4204828 */  ldc1      $f0, %lo(D_80234828_6BBA28)($at)
/* 6A2CCC 8021BACC 4600C0A1 */  cvt.d.s   $f2, $f24
/* 6A2CD0 8021BAD0 46201082 */  mul.d     $f2, $f2, $f0
/* 6A2CD4 8021BAD4 00000000 */  nop
/* 6A2CD8 8021BAD8 44950000 */  mtc1      $s5, $f0
/* 6A2CDC 8021BADC 00000000 */  nop
/* 6A2CE0 8021BAE0 46800021 */  cvt.d.w   $f0, $f0
/* 6A2CE4 8021BAE4 46220000 */  add.d     $f0, $f0, $f2
/* 6A2CE8 8021BAE8 4620010D */  trunc.w.d $f4, $f0
/* 6A2CEC 8021BAEC 44152000 */  mfc1      $s5, $f4
/* 6A2CF0 8021BAF0 0000A02D */  daddu     $s4, $zero, $zero
.L8021BAF4:
/* 6A2CF4 8021BAF4 3C014348 */  lui       $at, 0x4348
/* 6A2CF8 8021BAF8 4481D000 */  mtc1      $at, $f26
/* 6A2CFC 8021BAFC 26D70014 */  addiu     $s7, $s6, 0x14
/* 6A2D00 8021BB00 27B30028 */  addiu     $s3, $sp, 0x28
.L8021BB04:
/* 6A2D04 8021BB04 0C00A67F */  jal       rand_int
/* 6A2D08 8021BB08 2404001E */   addiu    $a0, $zero, 0x1e
/* 6A2D0C 8021BB0C 8E630000 */  lw        $v1, ($s3)
/* 6A2D10 8021BB10 00621821 */  addu      $v1, $v1, $v0
/* 6A2D14 8021BB14 2463FFF1 */  addiu     $v1, $v1, -0xf
/* 6A2D18 8021BB18 4483A000 */  mtc1      $v1, $f20
/* 6A2D1C 8021BB1C 00000000 */  nop
/* 6A2D20 8021BB20 4680A520 */  cvt.s.w   $f20, $f20
/* 6A2D24 8021BB24 0C00A8BB */  jal       sin_deg
/* 6A2D28 8021BB28 4600A306 */   mov.s    $f12, $f20
/* 6A2D2C 8021BB2C 461A0002 */  mul.s     $f0, $f0, $f26
/* 6A2D30 8021BB30 00000000 */  nop
/* 6A2D34 8021BB34 449EB000 */  mtc1      $fp, $f22
/* 6A2D38 8021BB38 00000000 */  nop
/* 6A2D3C 8021BB3C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6A2D40 8021BB40 46160000 */  add.s     $f0, $f0, $f22
/* 6A2D44 8021BB44 4600010D */  trunc.w.s $f4, $f0
/* 6A2D48 8021BB48 44102000 */  mfc1      $s0, $f4
/* 6A2D4C 8021BB4C 0C00A8D4 */  jal       cos_deg
/* 6A2D50 8021BB50 4600A306 */   mov.s    $f12, $f20
/* 6A2D54 8021BB54 24040001 */  addiu     $a0, $zero, 1
/* 6A2D58 8021BB58 44901000 */  mtc1      $s0, $f2
/* 6A2D5C 8021BB5C 00000000 */  nop
/* 6A2D60 8021BB60 468010A0 */  cvt.s.w   $f2, $f2
/* 6A2D64 8021BB64 E7A20010 */  swc1      $f2, 0x10($sp)
/* 6A2D68 8021BB68 44971000 */  mtc1      $s7, $f2
/* 6A2D6C 8021BB6C 00000000 */  nop
/* 6A2D70 8021BB70 468010A0 */  cvt.s.w   $f2, $f2
/* 6A2D74 8021BB74 461A0002 */  mul.s     $f0, $f0, $f26
/* 6A2D78 8021BB78 00000000 */  nop
/* 6A2D7C 8021BB7C E7A20018 */  swc1      $f2, 0x18($sp)
/* 6A2D80 8021BB80 44951000 */  mtc1      $s5, $f2
/* 6A2D84 8021BB84 00000000 */  nop
/* 6A2D88 8021BB88 468010A0 */  cvt.s.w   $f2, $f2
/* 6A2D8C 8021BB8C 2402000B */  addiu     $v0, $zero, 0xb
/* 6A2D90 8021BB90 4405B000 */  mfc1      $a1, $f22
/* 6A2D94 8021BB94 44061000 */  mfc1      $a2, $f2
/* 6A2D98 8021BB98 46020000 */  add.s     $f0, $f0, $f2
/* 6A2D9C 8021BB9C E7B8001C */  swc1      $f24, 0x1c($sp)
/* 6A2DA0 8021BBA0 AFA20020 */  sw        $v0, 0x20($sp)
/* 6A2DA4 8021BBA4 4600010D */  trunc.w.s $f4, $f0
/* 6A2DA8 8021BBA8 44022000 */  mfc1      $v0, $f4
/* 6A2DAC 8021BBAC 44962000 */  mtc1      $s6, $f4
/* 6A2DB0 8021BBB0 00000000 */  nop
/* 6A2DB4 8021BBB4 46802120 */  cvt.s.w   $f4, $f4
/* 6A2DB8 8021BBB8 44072000 */  mfc1      $a3, $f4
/* 6A2DBC 8021BBBC 44820000 */  mtc1      $v0, $f0
/* 6A2DC0 8021BBC0 00000000 */  nop
/* 6A2DC4 8021BBC4 46800020 */  cvt.s.w   $f0, $f0
/* 6A2DC8 8021BBC8 0C01C6F4 */  jal       func_80071BD0
/* 6A2DCC 8021BBCC E7A00014 */   swc1     $f0, 0x14($sp)
/* 6A2DD0 8021BBD0 24040100 */  addiu     $a0, $zero, 0x100
/* 6A2DD4 8021BBD4 0C00A67F */  jal       rand_int
/* 6A2DD8 8021BBD8 0040802D */   daddu    $s0, $v0, $zero
/* 6A2DDC 8021BBDC 24040100 */  addiu     $a0, $zero, 0x100
/* 6A2DE0 8021BBE0 0C00A67F */  jal       rand_int
/* 6A2DE4 8021BBE4 0040882D */   daddu    $s1, $v0, $zero
/* 6A2DE8 8021BBE8 24040100 */  addiu     $a0, $zero, 0x100
/* 6A2DEC 8021BBEC 0C00A67F */  jal       rand_int
/* 6A2DF0 8021BBF0 0040902D */   daddu    $s2, $v0, $zero
/* 6A2DF4 8021BBF4 8E03000C */  lw        $v1, 0xc($s0)
/* 6A2DF8 8021BBF8 AC710030 */  sw        $s1, 0x30($v1)
/* 6A2DFC 8021BBFC 8E03000C */  lw        $v1, 0xc($s0)
/* 6A2E00 8021BC00 AC720034 */  sw        $s2, 0x34($v1)
/* 6A2E04 8021BC04 8E03000C */  lw        $v1, 0xc($s0)
/* 6A2E08 8021BC08 26940001 */  addiu     $s4, $s4, 1
/* 6A2E0C 8021BC0C AC620038 */  sw        $v0, 0x38($v1)
/* 6A2E10 8021BC10 2A820006 */  slti      $v0, $s4, 6
/* 6A2E14 8021BC14 1440FFBB */  bnez      $v0, .L8021BB04
/* 6A2E18 8021BC18 26730004 */   addiu    $s3, $s3, 4
/* 6A2E1C 8021BC1C 24020002 */  addiu     $v0, $zero, 2
.L8021BC20:
/* 6A2E20 8021BC20 8FBF0064 */  lw        $ra, 0x64($sp)
/* 6A2E24 8021BC24 8FBE0060 */  lw        $fp, 0x60($sp)
/* 6A2E28 8021BC28 8FB7005C */  lw        $s7, 0x5c($sp)
/* 6A2E2C 8021BC2C 8FB60058 */  lw        $s6, 0x58($sp)
/* 6A2E30 8021BC30 8FB50054 */  lw        $s5, 0x54($sp)
/* 6A2E34 8021BC34 8FB40050 */  lw        $s4, 0x50($sp)
/* 6A2E38 8021BC38 8FB3004C */  lw        $s3, 0x4c($sp)
/* 6A2E3C 8021BC3C 8FB20048 */  lw        $s2, 0x48($sp)
/* 6A2E40 8021BC40 8FB10044 */  lw        $s1, 0x44($sp)
/* 6A2E44 8021BC44 8FB00040 */  lw        $s0, 0x40($sp)
/* 6A2E48 8021BC48 D7BA0080 */  ldc1      $f26, 0x80($sp)
/* 6A2E4C 8021BC4C D7B80078 */  ldc1      $f24, 0x78($sp)
/* 6A2E50 8021BC50 D7B60070 */  ldc1      $f22, 0x70($sp)
/* 6A2E54 8021BC54 D7B40068 */  ldc1      $f20, 0x68($sp)
/* 6A2E58 8021BC58 03E00008 */  jr        $ra
/* 6A2E5C 8021BC5C 27BD0088 */   addiu    $sp, $sp, 0x88
