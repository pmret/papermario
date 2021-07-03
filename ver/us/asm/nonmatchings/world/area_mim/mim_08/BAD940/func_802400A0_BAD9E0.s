.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802452A0_BB2BE0
.double 32767.0

.section .text

glabel func_802400A0_BAD9E0
/* BAD9E0 802400A0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BAD9E4 802400A4 AFB3002C */  sw        $s3, 0x2c($sp)
/* BAD9E8 802400A8 0080982D */  daddu     $s3, $a0, $zero
/* BAD9EC 802400AC AFBF0030 */  sw        $ra, 0x30($sp)
/* BAD9F0 802400B0 AFB20028 */  sw        $s2, 0x28($sp)
/* BAD9F4 802400B4 AFB10024 */  sw        $s1, 0x24($sp)
/* BAD9F8 802400B8 AFB00020 */  sw        $s0, 0x20($sp)
/* BAD9FC 802400BC 8E710148 */  lw        $s1, 0x148($s3)
/* BADA00 802400C0 86240008 */  lh        $a0, 8($s1)
/* BADA04 802400C4 0C00EABB */  jal       get_npc_unsafe
/* BADA08 802400C8 00A0902D */   daddu    $s2, $a1, $zero
/* BADA0C 802400CC 8E440004 */  lw        $a0, 4($s2)
/* BADA10 802400D0 0040802D */  daddu     $s0, $v0, $zero
/* BADA14 802400D4 00041FC2 */  srl       $v1, $a0, 0x1f
/* BADA18 802400D8 00832021 */  addu      $a0, $a0, $v1
/* BADA1C 802400DC 00042043 */  sra       $a0, $a0, 1
/* BADA20 802400E0 0C00A67F */  jal       rand_int
/* BADA24 802400E4 24840001 */   addiu    $a0, $a0, 1
/* BADA28 802400E8 8E430004 */  lw        $v1, 4($s2)
/* BADA2C 802400EC 000327C2 */  srl       $a0, $v1, 0x1f
/* BADA30 802400F0 00641821 */  addu      $v1, $v1, $a0
/* BADA34 802400F4 00031843 */  sra       $v1, $v1, 1
/* BADA38 802400F8 00621821 */  addu      $v1, $v1, $v0
/* BADA3C 802400FC A603008E */  sh        $v1, 0x8e($s0)
/* BADA40 80240100 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BADA44 80240104 C6000040 */  lwc1      $f0, 0x40($s0)
/* BADA48 80240108 C4640000 */  lwc1      $f4, ($v1)
/* BADA4C 8024010C 46802120 */  cvt.s.w   $f4, $f4
/* BADA50 80240110 C4620008 */  lwc1      $f2, 8($v1)
/* BADA54 80240114 468010A0 */  cvt.s.w   $f2, $f2
/* BADA58 80240118 E7A00010 */  swc1      $f0, 0x10($sp)
/* BADA5C 8024011C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BADA60 80240120 44061000 */  mfc1      $a2, $f2
/* BADA64 80240124 C440000C */  lwc1      $f0, 0xc($v0)
/* BADA68 80240128 46800020 */  cvt.s.w   $f0, $f0
/* BADA6C 8024012C E7A00014 */  swc1      $f0, 0x14($sp)
/* BADA70 80240130 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BADA74 80240134 44052000 */  mfc1      $a1, $f4
/* BADA78 80240138 C4400010 */  lwc1      $f0, 0x10($v0)
/* BADA7C 8024013C 46800020 */  cvt.s.w   $f0, $f0
/* BADA80 80240140 E7A00018 */  swc1      $f0, 0x18($sp)
/* BADA84 80240144 8C640018 */  lw        $a0, 0x18($v1)
/* BADA88 80240148 0C0123F5 */  jal       is_point_within_region
/* BADA8C 8024014C 8E070038 */   lw       $a3, 0x38($s0)
/* BADA90 80240150 1040000E */  beqz      $v0, .L8024018C
/* BADA94 80240154 00000000 */   nop
/* BADA98 80240158 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BADA9C 8024015C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BADAA0 80240160 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BADAA4 80240164 C4460000 */  lwc1      $f6, ($v0)
/* BADAA8 80240168 468031A0 */  cvt.s.w   $f6, $f6
/* BADAAC 8024016C 44063000 */  mfc1      $a2, $f6
/* BADAB0 80240170 C4460008 */  lwc1      $f6, 8($v0)
/* BADAB4 80240174 468031A0 */  cvt.s.w   $f6, $f6
/* BADAB8 80240178 44073000 */  mfc1      $a3, $f6
/* BADABC 8024017C 0C00A720 */  jal       atan2
/* BADAC0 80240180 00000000 */   nop
/* BADAC4 80240184 0809006F */  j         .L802401BC
/* BADAC8 80240188 E600000C */   swc1     $f0, 0xc($s0)
.L8024018C:
/* BADACC 8024018C 0C00A67F */  jal       rand_int
/* BADAD0 80240190 2404003C */   addiu    $a0, $zero, 0x3c
/* BADAD4 80240194 C60C000C */  lwc1      $f12, 0xc($s0)
/* BADAD8 80240198 44820000 */  mtc1      $v0, $f0
/* BADADC 8024019C 00000000 */  nop
/* BADAE0 802401A0 46800020 */  cvt.s.w   $f0, $f0
/* BADAE4 802401A4 46006300 */  add.s     $f12, $f12, $f0
/* BADAE8 802401A8 3C0141F0 */  lui       $at, 0x41f0
/* BADAEC 802401AC 44810000 */  mtc1      $at, $f0
/* BADAF0 802401B0 0C00A6C9 */  jal       clamp_angle
/* BADAF4 802401B4 46006301 */   sub.s    $f12, $f12, $f0
/* BADAF8 802401B8 E600000C */  swc1      $f0, 0xc($s0)
.L802401BC:
/* BADAFC 802401BC 8E2200CC */  lw        $v0, 0xcc($s1)
/* BADB00 802401C0 8C420004 */  lw        $v0, 4($v0)
/* BADB04 802401C4 AE020028 */  sw        $v0, 0x28($s0)
/* BADB08 802401C8 AE600074 */  sw        $zero, 0x74($s3)
/* BADB0C 802401CC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BADB10 802401D0 8C420014 */  lw        $v0, 0x14($v0)
/* BADB14 802401D4 04410004 */  bgez      $v0, .L802401E8
/* BADB18 802401D8 00000000 */   nop
/* BADB1C 802401DC C6400000 */  lwc1      $f0, ($s2)
/* BADB20 802401E0 08090082 */  j         .L80240208
/* BADB24 802401E4 E6000018 */   swc1     $f0, 0x18($s0)
.L802401E8:
/* BADB28 802401E8 3C018024 */  lui       $at, %hi(D_802452A0_BB2BE0)
/* BADB2C 802401EC D42252A0 */  ldc1      $f2, %lo(D_802452A0_BB2BE0)($at)
/* BADB30 802401F0 44820000 */  mtc1      $v0, $f0
/* BADB34 802401F4 00000000 */  nop
/* BADB38 802401F8 46800021 */  cvt.d.w   $f0, $f0
/* BADB3C 802401FC 46220003 */  div.d     $f0, $f0, $f2
/* BADB40 80240200 46200020 */  cvt.s.d   $f0, $f0
/* BADB44 80240204 E6000018 */  swc1      $f0, 0x18($s0)
.L80240208:
/* BADB48 80240208 C600003C */  lwc1      $f0, 0x3c($s0)
/* BADB4C 8024020C 3C014059 */  lui       $at, 0x4059
/* BADB50 80240210 44811800 */  mtc1      $at, $f3
/* BADB54 80240214 44801000 */  mtc1      $zero, $f2
/* BADB58 80240218 46000021 */  cvt.d.s   $f0, $f0
/* BADB5C 8024021C 46220002 */  mul.d     $f0, $f0, $f2
/* BADB60 80240220 00000000 */  nop
/* BADB64 80240224 24020001 */  addiu     $v0, $zero, 1
/* BADB68 80240228 4620018D */  trunc.w.d $f6, $f0
/* BADB6C 8024022C E626007C */  swc1      $f6, 0x7c($s1)
/* BADB70 80240230 AE620070 */  sw        $v0, 0x70($s3)
/* BADB74 80240234 8FBF0030 */  lw        $ra, 0x30($sp)
/* BADB78 80240238 8FB3002C */  lw        $s3, 0x2c($sp)
/* BADB7C 8024023C 8FB20028 */  lw        $s2, 0x28($sp)
/* BADB80 80240240 8FB10024 */  lw        $s1, 0x24($sp)
/* BADB84 80240244 8FB00020 */  lw        $s0, 0x20($sp)
/* BADB88 80240248 03E00008 */  jr        $ra
/* BADB8C 8024024C 27BD0038 */   addiu    $sp, $sp, 0x38
