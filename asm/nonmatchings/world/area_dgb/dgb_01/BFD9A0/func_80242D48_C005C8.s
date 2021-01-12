.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D48_C005C8
/* C005C8 80242D48 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C005CC 80242D4C AFB3001C */  sw        $s3, 0x1c($sp)
/* C005D0 80242D50 0080982D */  daddu     $s3, $a0, $zero
/* C005D4 80242D54 AFBF0020 */  sw        $ra, 0x20($sp)
/* C005D8 80242D58 AFB20018 */  sw        $s2, 0x18($sp)
/* C005DC 80242D5C AFB10014 */  sw        $s1, 0x14($sp)
/* C005E0 80242D60 AFB00010 */  sw        $s0, 0x10($sp)
/* C005E4 80242D64 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C005E8 80242D68 8E710148 */  lw        $s1, 0x148($s3)
/* C005EC 80242D6C 86240008 */  lh        $a0, 8($s1)
/* C005F0 80242D70 0C00EABB */  jal       get_npc_unsafe
/* C005F4 80242D74 00A0802D */   daddu    $s0, $a1, $zero
/* C005F8 80242D78 8E040020 */  lw        $a0, 0x20($s0)
/* C005FC 80242D7C 0040902D */  daddu     $s2, $v0, $zero
/* C00600 80242D80 00041FC2 */  srl       $v1, $a0, 0x1f
/* C00604 80242D84 00832021 */  addu      $a0, $a0, $v1
/* C00608 80242D88 00042043 */  sra       $a0, $a0, 1
/* C0060C 80242D8C 0C00A67F */  jal       rand_int
/* C00610 80242D90 24840001 */   addiu    $a0, $a0, 1
/* C00614 80242D94 8E030020 */  lw        $v1, 0x20($s0)
/* C00618 80242D98 C64C0038 */  lwc1      $f12, 0x38($s2)
/* C0061C 80242D9C 000327C2 */  srl       $a0, $v1, 0x1f
/* C00620 80242DA0 00641821 */  addu      $v1, $v1, $a0
/* C00624 80242DA4 00031843 */  sra       $v1, $v1, 1
/* C00628 80242DA8 00621821 */  addu      $v1, $v1, $v0
/* C0062C 80242DAC A643008E */  sh        $v1, 0x8e($s2)
/* C00630 80242DB0 8E2200CC */  lw        $v0, 0xcc($s1)
/* C00634 80242DB4 C64E0040 */  lwc1      $f14, 0x40($s2)
/* C00638 80242DB8 8C42000C */  lw        $v0, 0xc($v0)
/* C0063C 80242DBC AE420028 */  sw        $v0, 0x28($s2)
/* C00640 80242DC0 C6000018 */  lwc1      $f0, 0x18($s0)
/* C00644 80242DC4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C00648 80242DC8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C0064C 80242DCC E6400018 */  swc1      $f0, 0x18($s2)
/* C00650 80242DD0 8C460028 */  lw        $a2, 0x28($v0)
/* C00654 80242DD4 0C00A720 */  jal       atan2
/* C00658 80242DD8 8C470030 */   lw       $a3, 0x30($v0)
/* C0065C 80242DDC 46000506 */  mov.s     $f20, $f0
/* C00660 80242DE0 C64C000C */  lwc1      $f12, 0xc($s2)
/* C00664 80242DE4 0C00A70A */  jal       get_clamped_angle_diff
/* C00668 80242DE8 4600A386 */   mov.s    $f14, $f20
/* C0066C 80242DEC 46000086 */  mov.s     $f2, $f0
/* C00670 80242DF0 8E02001C */  lw        $v0, 0x1c($s0)
/* C00674 80242DF4 46001005 */  abs.s     $f0, $f2
/* C00678 80242DF8 44822000 */  mtc1      $v0, $f4
/* C0067C 80242DFC 00000000 */  nop
/* C00680 80242E00 46802120 */  cvt.s.w   $f4, $f4
/* C00684 80242E04 4600203C */  c.lt.s    $f4, $f0
/* C00688 80242E08 00000000 */  nop
/* C0068C 80242E0C 4500000D */  bc1f      .L80242E44
/* C00690 80242E10 00000000 */   nop
/* C00694 80242E14 44800000 */  mtc1      $zero, $f0
/* C00698 80242E18 C654000C */  lwc1      $f20, 0xc($s2)
/* C0069C 80242E1C 4600103C */  c.lt.s    $f2, $f0
/* C006A0 80242E20 00000000 */  nop
/* C006A4 80242E24 45000006 */  bc1f      .L80242E40
/* C006A8 80242E28 00021023 */   negu     $v0, $v0
/* C006AC 80242E2C 44820000 */  mtc1      $v0, $f0
/* C006B0 80242E30 00000000 */  nop
/* C006B4 80242E34 46800020 */  cvt.s.w   $f0, $f0
/* C006B8 80242E38 08090B91 */  j         .L80242E44
/* C006BC 80242E3C 4600A500 */   add.s    $f20, $f20, $f0
.L80242E40:
/* C006C0 80242E40 4604A500 */  add.s     $f20, $f20, $f4
.L80242E44:
/* C006C4 80242E44 0C00A6C9 */  jal       clamp_angle
/* C006C8 80242E48 4600A306 */   mov.s    $f12, $f20
/* C006CC 80242E4C 2402000D */  addiu     $v0, $zero, 0xd
/* C006D0 80242E50 E640000C */  swc1      $f0, 0xc($s2)
/* C006D4 80242E54 AE620070 */  sw        $v0, 0x70($s3)
/* C006D8 80242E58 8FBF0020 */  lw        $ra, 0x20($sp)
/* C006DC 80242E5C 8FB3001C */  lw        $s3, 0x1c($sp)
/* C006E0 80242E60 8FB20018 */  lw        $s2, 0x18($sp)
/* C006E4 80242E64 8FB10014 */  lw        $s1, 0x14($sp)
/* C006E8 80242E68 8FB00010 */  lw        $s0, 0x10($sp)
/* C006EC 80242E6C D7B40028 */  ldc1      $f20, 0x28($sp)
/* C006F0 80242E70 03E00008 */  jr        $ra
/* C006F4 80242E74 27BD0030 */   addiu    $sp, $sp, 0x30
