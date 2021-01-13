.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401C4_EDEB84
/* EDEB84 802401C4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EDEB88 802401C8 AFB3002C */  sw        $s3, 0x2c($sp)
/* EDEB8C 802401CC 0080982D */  daddu     $s3, $a0, $zero
/* EDEB90 802401D0 AFBF0030 */  sw        $ra, 0x30($sp)
/* EDEB94 802401D4 AFB20028 */  sw        $s2, 0x28($sp)
/* EDEB98 802401D8 AFB10024 */  sw        $s1, 0x24($sp)
/* EDEB9C 802401DC AFB00020 */  sw        $s0, 0x20($sp)
/* EDEBA0 802401E0 8E710148 */  lw        $s1, 0x148($s3)
/* EDEBA4 802401E4 86240008 */  lh        $a0, 8($s1)
/* EDEBA8 802401E8 0C00F92F */  jal       func_8003E4BC
/* EDEBAC 802401EC 00A0902D */   daddu    $s2, $a1, $zero
/* EDEBB0 802401F0 8E440004 */  lw        $a0, 4($s2)
/* EDEBB4 802401F4 0040802D */  daddu     $s0, $v0, $zero
/* EDEBB8 802401F8 00041FC2 */  srl       $v1, $a0, 0x1f
/* EDEBBC 802401FC 00832021 */  addu      $a0, $a0, $v1
/* EDEBC0 80240200 00042043 */  sra       $a0, $a0, 1
/* EDEBC4 80240204 0C00AB3B */  jal       func_8002ACEC
/* EDEBC8 80240208 24840001 */   addiu    $a0, $a0, 1
/* EDEBCC 8024020C 8E430004 */  lw        $v1, 4($s2)
/* EDEBD0 80240210 000327C2 */  srl       $a0, $v1, 0x1f
/* EDEBD4 80240214 00641821 */  addu      $v1, $v1, $a0
/* EDEBD8 80240218 00031843 */  sra       $v1, $v1, 1
/* EDEBDC 8024021C 00621821 */  addu      $v1, $v1, $v0
/* EDEBE0 80240220 A603008E */  sh        $v1, 0x8e($s0)
/* EDEBE4 80240224 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EDEBE8 80240228 C6000040 */  lwc1      $f0, 0x40($s0)
/* EDEBEC 8024022C C4640000 */  lwc1      $f4, ($v1)
/* EDEBF0 80240230 46802120 */  cvt.s.w   $f4, $f4
/* EDEBF4 80240234 C4620008 */  lwc1      $f2, 8($v1)
/* EDEBF8 80240238 468010A0 */  cvt.s.w   $f2, $f2
/* EDEBFC 8024023C E7A00010 */  swc1      $f0, 0x10($sp)
/* EDEC00 80240240 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDEC04 80240244 44061000 */  mfc1      $a2, $f2
/* EDEC08 80240248 C440000C */  lwc1      $f0, 0xc($v0)
/* EDEC0C 8024024C 46800020 */  cvt.s.w   $f0, $f0
/* EDEC10 80240250 E7A00014 */  swc1      $f0, 0x14($sp)
/* EDEC14 80240254 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDEC18 80240258 44052000 */  mfc1      $a1, $f4
/* EDEC1C 8024025C C4400010 */  lwc1      $f0, 0x10($v0)
/* EDEC20 80240260 46800020 */  cvt.s.w   $f0, $f0
/* EDEC24 80240264 E7A00018 */  swc1      $f0, 0x18($sp)
/* EDEC28 80240268 8C640018 */  lw        $a0, 0x18($v1)
/* EDEC2C 8024026C 0C013431 */  jal       func_8004D0C4
/* EDEC30 80240270 8E070038 */   lw       $a3, 0x38($s0)
/* EDEC34 80240274 1040000E */  beqz      $v0, .L802402B0
/* EDEC38 80240278 00000000 */   nop
/* EDEC3C 8024027C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDEC40 80240280 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EDEC44 80240284 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EDEC48 80240288 C4460000 */  lwc1      $f6, ($v0)
/* EDEC4C 8024028C 468031A0 */  cvt.s.w   $f6, $f6
/* EDEC50 80240290 44063000 */  mfc1      $a2, $f6
/* EDEC54 80240294 C4460008 */  lwc1      $f6, 8($v0)
/* EDEC58 80240298 468031A0 */  cvt.s.w   $f6, $f6
/* EDEC5C 8024029C 44073000 */  mfc1      $a3, $f6
/* EDEC60 802402A0 0C00ABDC */  jal       fio_validate_header_checksums
/* EDEC64 802402A4 00000000 */   nop
/* EDEC68 802402A8 080900B8 */  j         .L802402E0
/* EDEC6C 802402AC E600000C */   swc1     $f0, 0xc($s0)
.L802402B0:
/* EDEC70 802402B0 0C00AB3B */  jal       func_8002ACEC
/* EDEC74 802402B4 2404003C */   addiu    $a0, $zero, 0x3c
/* EDEC78 802402B8 C60C000C */  lwc1      $f12, 0xc($s0)
/* EDEC7C 802402BC 44820000 */  mtc1      $v0, $f0
/* EDEC80 802402C0 00000000 */  nop
/* EDEC84 802402C4 46800020 */  cvt.s.w   $f0, $f0
/* EDEC88 802402C8 46006300 */  add.s     $f12, $f12, $f0
/* EDEC8C 802402CC 3C0141F0 */  lui       $at, 0x41f0
/* EDEC90 802402D0 44810000 */  mtc1      $at, $f0
/* EDEC94 802402D4 0C00AB85 */  jal       func_8002AE14
/* EDEC98 802402D8 46006301 */   sub.s    $f12, $f12, $f0
/* EDEC9C 802402DC E600000C */  swc1      $f0, 0xc($s0)
.L802402E0:
/* EDECA0 802402E0 8E2200CC */  lw        $v0, 0xcc($s1)
/* EDECA4 802402E4 8C420004 */  lw        $v0, 4($v0)
/* EDECA8 802402E8 AE020028 */  sw        $v0, 0x28($s0)
/* EDECAC 802402EC AE600074 */  sw        $zero, 0x74($s3)
/* EDECB0 802402F0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDECB4 802402F4 8C420014 */  lw        $v0, 0x14($v0)
/* EDECB8 802402F8 04410004 */  bgez      $v0, .L8024030C
/* EDECBC 802402FC 00000000 */   nop
/* EDECC0 80240300 C6400000 */  lwc1      $f0, ($s2)
/* EDECC4 80240304 080900CB */  j         .L8024032C
/* EDECC8 80240308 E6000018 */   swc1     $f0, 0x18($s0)
.L8024030C:
/* EDECCC 8024030C 3C018024 */  lui       $at, %hi(D_80247AF0)
/* EDECD0 80240310 D4227AF0 */  ldc1      $f2, %lo(D_80247AF0)($at)
/* EDECD4 80240314 44820000 */  mtc1      $v0, $f0
/* EDECD8 80240318 00000000 */  nop
/* EDECDC 8024031C 46800021 */  cvt.d.w   $f0, $f0
/* EDECE0 80240320 46220003 */  div.d     $f0, $f0, $f2
/* EDECE4 80240324 46200020 */  cvt.s.d   $f0, $f0
/* EDECE8 80240328 E6000018 */  swc1      $f0, 0x18($s0)
.L8024032C:
/* EDECEC 8024032C C600003C */  lwc1      $f0, 0x3c($s0)
/* EDECF0 80240330 3C014059 */  lui       $at, 0x4059
/* EDECF4 80240334 44811800 */  mtc1      $at, $f3
/* EDECF8 80240338 44801000 */  mtc1      $zero, $f2
/* EDECFC 8024033C 46000021 */  cvt.d.s   $f0, $f0
/* EDED00 80240340 46220002 */  mul.d     $f0, $f0, $f2
/* EDED04 80240344 00000000 */  nop
/* EDED08 80240348 24020001 */  addiu     $v0, $zero, 1
/* EDED0C 8024034C 4620018D */  trunc.w.d $f6, $f0
/* EDED10 80240350 E626007C */  swc1      $f6, 0x7c($s1)
/* EDED14 80240354 AE620070 */  sw        $v0, 0x70($s3)
/* EDED18 80240358 8FBF0030 */  lw        $ra, 0x30($sp)
/* EDED1C 8024035C 8FB3002C */  lw        $s3, 0x2c($sp)
/* EDED20 80240360 8FB20028 */  lw        $s2, 0x28($sp)
/* EDED24 80240364 8FB10024 */  lw        $s1, 0x24($sp)
/* EDED28 80240368 8FB00020 */  lw        $s0, 0x20($sp)
/* EDED2C 8024036C 03E00008 */  jr        $ra
/* EDED30 80240370 27BD0038 */   addiu    $sp, $sp, 0x38
