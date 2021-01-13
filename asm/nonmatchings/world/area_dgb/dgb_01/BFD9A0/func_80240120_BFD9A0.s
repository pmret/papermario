.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240120_BFD9A0
/* BFD9A0 80240120 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BFD9A4 80240124 AFB3002C */  sw        $s3, 0x2c($sp)
/* BFD9A8 80240128 0080982D */  daddu     $s3, $a0, $zero
/* BFD9AC 8024012C AFBF0030 */  sw        $ra, 0x30($sp)
/* BFD9B0 80240130 AFB20028 */  sw        $s2, 0x28($sp)
/* BFD9B4 80240134 AFB10024 */  sw        $s1, 0x24($sp)
/* BFD9B8 80240138 AFB00020 */  sw        $s0, 0x20($sp)
/* BFD9BC 8024013C 8E710148 */  lw        $s1, 0x148($s3)
/* BFD9C0 80240140 86240008 */  lh        $a0, 8($s1)
/* BFD9C4 80240144 0C00EABB */  jal       get_npc_unsafe
/* BFD9C8 80240148 00A0902D */   daddu    $s2, $a1, $zero
/* BFD9CC 8024014C 8E440004 */  lw        $a0, 4($s2)
/* BFD9D0 80240150 0040802D */  daddu     $s0, $v0, $zero
/* BFD9D4 80240154 00041FC2 */  srl       $v1, $a0, 0x1f
/* BFD9D8 80240158 00832021 */  addu      $a0, $a0, $v1
/* BFD9DC 8024015C 00042043 */  sra       $a0, $a0, 1
/* BFD9E0 80240160 0C00A67F */  jal       rand_int
/* BFD9E4 80240164 24840001 */   addiu    $a0, $a0, 1
/* BFD9E8 80240168 8E430004 */  lw        $v1, 4($s2)
/* BFD9EC 8024016C 000327C2 */  srl       $a0, $v1, 0x1f
/* BFD9F0 80240170 00641821 */  addu      $v1, $v1, $a0
/* BFD9F4 80240174 00031843 */  sra       $v1, $v1, 1
/* BFD9F8 80240178 00621821 */  addu      $v1, $v1, $v0
/* BFD9FC 8024017C A603008E */  sh        $v1, 0x8e($s0)
/* BFDA00 80240180 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BFDA04 80240184 C6000040 */  lwc1      $f0, 0x40($s0)
/* BFDA08 80240188 C4640000 */  lwc1      $f4, ($v1)
/* BFDA0C 8024018C 46802120 */  cvt.s.w   $f4, $f4
/* BFDA10 80240190 C4620008 */  lwc1      $f2, 8($v1)
/* BFDA14 80240194 468010A0 */  cvt.s.w   $f2, $f2
/* BFDA18 80240198 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFDA1C 8024019C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFDA20 802401A0 44061000 */  mfc1      $a2, $f2
/* BFDA24 802401A4 C440000C */  lwc1      $f0, 0xc($v0)
/* BFDA28 802401A8 46800020 */  cvt.s.w   $f0, $f0
/* BFDA2C 802401AC E7A00014 */  swc1      $f0, 0x14($sp)
/* BFDA30 802401B0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFDA34 802401B4 44052000 */  mfc1      $a1, $f4
/* BFDA38 802401B8 C4400010 */  lwc1      $f0, 0x10($v0)
/* BFDA3C 802401BC 46800020 */  cvt.s.w   $f0, $f0
/* BFDA40 802401C0 E7A00018 */  swc1      $f0, 0x18($sp)
/* BFDA44 802401C4 8C640018 */  lw        $a0, 0x18($v1)
/* BFDA48 802401C8 0C0123F5 */  jal       is_point_within_region
/* BFDA4C 802401CC 8E070038 */   lw       $a3, 0x38($s0)
/* BFDA50 802401D0 1040000E */  beqz      $v0, .L8024020C
/* BFDA54 802401D4 00000000 */   nop
/* BFDA58 802401D8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFDA5C 802401DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* BFDA60 802401E0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BFDA64 802401E4 C4460000 */  lwc1      $f6, ($v0)
/* BFDA68 802401E8 468031A0 */  cvt.s.w   $f6, $f6
/* BFDA6C 802401EC 44063000 */  mfc1      $a2, $f6
/* BFDA70 802401F0 C4460008 */  lwc1      $f6, 8($v0)
/* BFDA74 802401F4 468031A0 */  cvt.s.w   $f6, $f6
/* BFDA78 802401F8 44073000 */  mfc1      $a3, $f6
/* BFDA7C 802401FC 0C00A720 */  jal       atan2
/* BFDA80 80240200 00000000 */   nop
/* BFDA84 80240204 0809008F */  j         .L8024023C
/* BFDA88 80240208 E600000C */   swc1     $f0, 0xc($s0)
.L8024020C:
/* BFDA8C 8024020C 0C00A67F */  jal       rand_int
/* BFDA90 80240210 2404003C */   addiu    $a0, $zero, 0x3c
/* BFDA94 80240214 C60C000C */  lwc1      $f12, 0xc($s0)
/* BFDA98 80240218 44820000 */  mtc1      $v0, $f0
/* BFDA9C 8024021C 00000000 */  nop
/* BFDAA0 80240220 46800020 */  cvt.s.w   $f0, $f0
/* BFDAA4 80240224 46006300 */  add.s     $f12, $f12, $f0
/* BFDAA8 80240228 3C0141F0 */  lui       $at, 0x41f0
/* BFDAAC 8024022C 44810000 */  mtc1      $at, $f0
/* BFDAB0 80240230 0C00A6C9 */  jal       clamp_angle
/* BFDAB4 80240234 46006301 */   sub.s    $f12, $f12, $f0
/* BFDAB8 80240238 E600000C */  swc1      $f0, 0xc($s0)
.L8024023C:
/* BFDABC 8024023C 8E2200CC */  lw        $v0, 0xcc($s1)
/* BFDAC0 80240240 8C420004 */  lw        $v0, 4($v0)
/* BFDAC4 80240244 AE020028 */  sw        $v0, 0x28($s0)
/* BFDAC8 80240248 AE600074 */  sw        $zero, 0x74($s3)
/* BFDACC 8024024C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFDAD0 80240250 8C420014 */  lw        $v0, 0x14($v0)
/* BFDAD4 80240254 04410004 */  bgez      $v0, .L80240268
/* BFDAD8 80240258 00000000 */   nop
/* BFDADC 8024025C C6400000 */  lwc1      $f0, ($s2)
/* BFDAE0 80240260 080900A2 */  j         .L80240288
/* BFDAE4 80240264 E6000018 */   swc1     $f0, 0x18($s0)
.L80240268:
/* BFDAE8 80240268 3C018026 */  lui       $at, %hi(D_80263420)
/* BFDAEC 8024026C D4223420 */  ldc1      $f2, %lo(D_80263420)($at)
/* BFDAF0 80240270 44820000 */  mtc1      $v0, $f0
/* BFDAF4 80240274 00000000 */  nop
/* BFDAF8 80240278 46800021 */  cvt.d.w   $f0, $f0
/* BFDAFC 8024027C 46220003 */  div.d     $f0, $f0, $f2
/* BFDB00 80240280 46200020 */  cvt.s.d   $f0, $f0
/* BFDB04 80240284 E6000018 */  swc1      $f0, 0x18($s0)
.L80240288:
/* BFDB08 80240288 C600003C */  lwc1      $f0, 0x3c($s0)
/* BFDB0C 8024028C 3C014059 */  lui       $at, 0x4059
/* BFDB10 80240290 44811800 */  mtc1      $at, $f3
/* BFDB14 80240294 44801000 */  mtc1      $zero, $f2
/* BFDB18 80240298 46000021 */  cvt.d.s   $f0, $f0
/* BFDB1C 8024029C 46220002 */  mul.d     $f0, $f0, $f2
/* BFDB20 802402A0 00000000 */  nop
/* BFDB24 802402A4 24020001 */  addiu     $v0, $zero, 1
/* BFDB28 802402A8 4620018D */  trunc.w.d $f6, $f0
/* BFDB2C 802402AC E626007C */  swc1      $f6, 0x7c($s1)
/* BFDB30 802402B0 AE620070 */  sw        $v0, 0x70($s3)
/* BFDB34 802402B4 8FBF0030 */  lw        $ra, 0x30($sp)
/* BFDB38 802402B8 8FB3002C */  lw        $s3, 0x2c($sp)
/* BFDB3C 802402BC 8FB20028 */  lw        $s2, 0x28($sp)
/* BFDB40 802402C0 8FB10024 */  lw        $s1, 0x24($sp)
/* BFDB44 802402C4 8FB00020 */  lw        $s0, 0x20($sp)
/* BFDB48 802402C8 03E00008 */  jr        $ra
/* BFDB4C 802402CC 27BD0038 */   addiu    $sp, $sp, 0x38
