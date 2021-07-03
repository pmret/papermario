.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8024BD70_A26E70
.double 32767.0

.section .text

glabel func_80240CB0_A1BDB0
/* A1BDB0 80240CB0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A1BDB4 80240CB4 AFB3002C */  sw        $s3, 0x2c($sp)
/* A1BDB8 80240CB8 0080982D */  daddu     $s3, $a0, $zero
/* A1BDBC 80240CBC AFBF0030 */  sw        $ra, 0x30($sp)
/* A1BDC0 80240CC0 AFB20028 */  sw        $s2, 0x28($sp)
/* A1BDC4 80240CC4 AFB10024 */  sw        $s1, 0x24($sp)
/* A1BDC8 80240CC8 AFB00020 */  sw        $s0, 0x20($sp)
/* A1BDCC 80240CCC 8E710148 */  lw        $s1, 0x148($s3)
/* A1BDD0 80240CD0 86240008 */  lh        $a0, 8($s1)
/* A1BDD4 80240CD4 0C00EABB */  jal       get_npc_unsafe
/* A1BDD8 80240CD8 00A0902D */   daddu    $s2, $a1, $zero
/* A1BDDC 80240CDC 8E440004 */  lw        $a0, 4($s2)
/* A1BDE0 80240CE0 0040802D */  daddu     $s0, $v0, $zero
/* A1BDE4 80240CE4 00041FC2 */  srl       $v1, $a0, 0x1f
/* A1BDE8 80240CE8 00832021 */  addu      $a0, $a0, $v1
/* A1BDEC 80240CEC 00042043 */  sra       $a0, $a0, 1
/* A1BDF0 80240CF0 0C00A67F */  jal       rand_int
/* A1BDF4 80240CF4 24840001 */   addiu    $a0, $a0, 1
/* A1BDF8 80240CF8 8E430004 */  lw        $v1, 4($s2)
/* A1BDFC 80240CFC 000327C2 */  srl       $a0, $v1, 0x1f
/* A1BE00 80240D00 00641821 */  addu      $v1, $v1, $a0
/* A1BE04 80240D04 00031843 */  sra       $v1, $v1, 1
/* A1BE08 80240D08 00621821 */  addu      $v1, $v1, $v0
/* A1BE0C 80240D0C A603008E */  sh        $v1, 0x8e($s0)
/* A1BE10 80240D10 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A1BE14 80240D14 C6000040 */  lwc1      $f0, 0x40($s0)
/* A1BE18 80240D18 C4640000 */  lwc1      $f4, ($v1)
/* A1BE1C 80240D1C 46802120 */  cvt.s.w   $f4, $f4
/* A1BE20 80240D20 C4620008 */  lwc1      $f2, 8($v1)
/* A1BE24 80240D24 468010A0 */  cvt.s.w   $f2, $f2
/* A1BE28 80240D28 E7A00010 */  swc1      $f0, 0x10($sp)
/* A1BE2C 80240D2C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A1BE30 80240D30 44061000 */  mfc1      $a2, $f2
/* A1BE34 80240D34 C440000C */  lwc1      $f0, 0xc($v0)
/* A1BE38 80240D38 46800020 */  cvt.s.w   $f0, $f0
/* A1BE3C 80240D3C E7A00014 */  swc1      $f0, 0x14($sp)
/* A1BE40 80240D40 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A1BE44 80240D44 44052000 */  mfc1      $a1, $f4
/* A1BE48 80240D48 C4400010 */  lwc1      $f0, 0x10($v0)
/* A1BE4C 80240D4C 46800020 */  cvt.s.w   $f0, $f0
/* A1BE50 80240D50 E7A00018 */  swc1      $f0, 0x18($sp)
/* A1BE54 80240D54 8C640018 */  lw        $a0, 0x18($v1)
/* A1BE58 80240D58 0C0123F5 */  jal       is_point_within_region
/* A1BE5C 80240D5C 8E070038 */   lw       $a3, 0x38($s0)
/* A1BE60 80240D60 1040000E */  beqz      $v0, .L80240D9C
/* A1BE64 80240D64 00000000 */   nop
/* A1BE68 80240D68 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A1BE6C 80240D6C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A1BE70 80240D70 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A1BE74 80240D74 C4460000 */  lwc1      $f6, ($v0)
/* A1BE78 80240D78 468031A0 */  cvt.s.w   $f6, $f6
/* A1BE7C 80240D7C 44063000 */  mfc1      $a2, $f6
/* A1BE80 80240D80 C4460008 */  lwc1      $f6, 8($v0)
/* A1BE84 80240D84 468031A0 */  cvt.s.w   $f6, $f6
/* A1BE88 80240D88 44073000 */  mfc1      $a3, $f6
/* A1BE8C 80240D8C 0C00A720 */  jal       atan2
/* A1BE90 80240D90 00000000 */   nop
/* A1BE94 80240D94 08090373 */  j         .L80240DCC
/* A1BE98 80240D98 E600000C */   swc1     $f0, 0xc($s0)
.L80240D9C:
/* A1BE9C 80240D9C 0C00A67F */  jal       rand_int
/* A1BEA0 80240DA0 2404003C */   addiu    $a0, $zero, 0x3c
/* A1BEA4 80240DA4 C60C000C */  lwc1      $f12, 0xc($s0)
/* A1BEA8 80240DA8 44820000 */  mtc1      $v0, $f0
/* A1BEAC 80240DAC 00000000 */  nop
/* A1BEB0 80240DB0 46800020 */  cvt.s.w   $f0, $f0
/* A1BEB4 80240DB4 46006300 */  add.s     $f12, $f12, $f0
/* A1BEB8 80240DB8 3C0141F0 */  lui       $at, 0x41f0
/* A1BEBC 80240DBC 44810000 */  mtc1      $at, $f0
/* A1BEC0 80240DC0 0C00A6C9 */  jal       clamp_angle
/* A1BEC4 80240DC4 46006301 */   sub.s    $f12, $f12, $f0
/* A1BEC8 80240DC8 E600000C */  swc1      $f0, 0xc($s0)
.L80240DCC:
/* A1BECC 80240DCC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A1BED0 80240DD0 8C420004 */  lw        $v0, 4($v0)
/* A1BED4 80240DD4 AE020028 */  sw        $v0, 0x28($s0)
/* A1BED8 80240DD8 AE600074 */  sw        $zero, 0x74($s3)
/* A1BEDC 80240DDC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A1BEE0 80240DE0 8C420014 */  lw        $v0, 0x14($v0)
/* A1BEE4 80240DE4 04410004 */  bgez      $v0, .L80240DF8
/* A1BEE8 80240DE8 00000000 */   nop
/* A1BEEC 80240DEC C6400000 */  lwc1      $f0, ($s2)
/* A1BEF0 80240DF0 08090386 */  j         .L80240E18
/* A1BEF4 80240DF4 E6000018 */   swc1     $f0, 0x18($s0)
.L80240DF8:
/* A1BEF8 80240DF8 3C018025 */  lui       $at, %hi(D_8024BD70_A26E70)
/* A1BEFC 80240DFC D422BD70 */  ldc1      $f2, %lo(D_8024BD70_A26E70)($at)
/* A1BF00 80240E00 44820000 */  mtc1      $v0, $f0
/* A1BF04 80240E04 00000000 */  nop
/* A1BF08 80240E08 46800021 */  cvt.d.w   $f0, $f0
/* A1BF0C 80240E0C 46220003 */  div.d     $f0, $f0, $f2
/* A1BF10 80240E10 46200020 */  cvt.s.d   $f0, $f0
/* A1BF14 80240E14 E6000018 */  swc1      $f0, 0x18($s0)
.L80240E18:
/* A1BF18 80240E18 C600003C */  lwc1      $f0, 0x3c($s0)
/* A1BF1C 80240E1C 3C014059 */  lui       $at, 0x4059
/* A1BF20 80240E20 44811800 */  mtc1      $at, $f3
/* A1BF24 80240E24 44801000 */  mtc1      $zero, $f2
/* A1BF28 80240E28 46000021 */  cvt.d.s   $f0, $f0
/* A1BF2C 80240E2C 46220002 */  mul.d     $f0, $f0, $f2
/* A1BF30 80240E30 00000000 */  nop
/* A1BF34 80240E34 24020001 */  addiu     $v0, $zero, 1
/* A1BF38 80240E38 4620018D */  trunc.w.d $f6, $f0
/* A1BF3C 80240E3C E626007C */  swc1      $f6, 0x7c($s1)
/* A1BF40 80240E40 AE620070 */  sw        $v0, 0x70($s3)
/* A1BF44 80240E44 8FBF0030 */  lw        $ra, 0x30($sp)
/* A1BF48 80240E48 8FB3002C */  lw        $s3, 0x2c($sp)
/* A1BF4C 80240E4C 8FB20028 */  lw        $s2, 0x28($sp)
/* A1BF50 80240E50 8FB10024 */  lw        $s1, 0x24($sp)
/* A1BF54 80240E54 8FB00020 */  lw        $s0, 0x20($sp)
/* A1BF58 80240E58 03E00008 */  jr        $ra
/* A1BF5C 80240E5C 27BD0038 */   addiu    $sp, $sp, 0x38
