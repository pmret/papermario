.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241618_BFEE98
/* BFEE98 80241618 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BFEE9C 8024161C AFB3001C */  sw        $s3, 0x1c($sp)
/* BFEEA0 80241620 0080982D */  daddu     $s3, $a0, $zero
/* BFEEA4 80241624 AFBF0020 */  sw        $ra, 0x20($sp)
/* BFEEA8 80241628 AFB20018 */  sw        $s2, 0x18($sp)
/* BFEEAC 8024162C AFB10014 */  sw        $s1, 0x14($sp)
/* BFEEB0 80241630 AFB00010 */  sw        $s0, 0x10($sp)
/* BFEEB4 80241634 F7B40028 */  sdc1      $f20, 0x28($sp)
/* BFEEB8 80241638 8E720148 */  lw        $s2, 0x148($s3)
/* BFEEBC 8024163C 86440008 */  lh        $a0, 8($s2)
/* BFEEC0 80241640 0C00EABB */  jal       get_npc_unsafe
/* BFEEC4 80241644 00A0882D */   daddu    $s1, $a1, $zero
/* BFEEC8 80241648 0040802D */  daddu     $s0, $v0, $zero
/* BFEECC 8024164C 9602008E */  lhu       $v0, 0x8e($s0)
/* BFEED0 80241650 2442FFFF */  addiu     $v0, $v0, -1
/* BFEED4 80241654 A602008E */  sh        $v0, 0x8e($s0)
/* BFEED8 80241658 00021400 */  sll       $v0, $v0, 0x10
/* BFEEDC 8024165C 1C40003C */  bgtz      $v0, .L80241750
/* BFEEE0 80241660 3C03FFDF */   lui      $v1, 0xffdf
/* BFEEE4 80241664 8E020000 */  lw        $v0, ($s0)
/* BFEEE8 80241668 3463FFFF */  ori       $v1, $v1, 0xffff
/* BFEEEC 8024166C 00431024 */  and       $v0, $v0, $v1
/* BFEEF0 80241670 AE020000 */  sw        $v0, ($s0)
/* BFEEF4 80241674 8E240020 */  lw        $a0, 0x20($s1)
/* BFEEF8 80241678 000417C2 */  srl       $v0, $a0, 0x1f
/* BFEEFC 8024167C 00822021 */  addu      $a0, $a0, $v0
/* BFEF00 80241680 00042043 */  sra       $a0, $a0, 1
/* BFEF04 80241684 0C00A67F */  jal       rand_int
/* BFEF08 80241688 24840001 */   addiu    $a0, $a0, 1
/* BFEF0C 8024168C 8E230020 */  lw        $v1, 0x20($s1)
/* BFEF10 80241690 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BFEF14 80241694 000327C2 */  srl       $a0, $v1, 0x1f
/* BFEF18 80241698 00641821 */  addu      $v1, $v1, $a0
/* BFEF1C 8024169C 00031843 */  sra       $v1, $v1, 1
/* BFEF20 802416A0 00621821 */  addu      $v1, $v1, $v0
/* BFEF24 802416A4 A603008E */  sh        $v1, 0x8e($s0)
/* BFEF28 802416A8 8E4200CC */  lw        $v0, 0xcc($s2)
/* BFEF2C 802416AC C60E0040 */  lwc1      $f14, 0x40($s0)
/* BFEF30 802416B0 8C420020 */  lw        $v0, 0x20($v0)
/* BFEF34 802416B4 AE020028 */  sw        $v0, 0x28($s0)
/* BFEF38 802416B8 C6200018 */  lwc1      $f0, 0x18($s1)
/* BFEF3C 802416BC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BFEF40 802416C0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BFEF44 802416C4 E6000018 */  swc1      $f0, 0x18($s0)
/* BFEF48 802416C8 8C460028 */  lw        $a2, 0x28($v0)
/* BFEF4C 802416CC 0C00A720 */  jal       atan2
/* BFEF50 802416D0 8C470030 */   lw       $a3, 0x30($v0)
/* BFEF54 802416D4 46000506 */  mov.s     $f20, $f0
/* BFEF58 802416D8 C60C000C */  lwc1      $f12, 0xc($s0)
/* BFEF5C 802416DC 0C00A70A */  jal       get_clamped_angle_diff
/* BFEF60 802416E0 4600A386 */   mov.s    $f14, $f20
/* BFEF64 802416E4 46000086 */  mov.s     $f2, $f0
/* BFEF68 802416E8 8E22001C */  lw        $v0, 0x1c($s1)
/* BFEF6C 802416EC 46001005 */  abs.s     $f0, $f2
/* BFEF70 802416F0 44822000 */  mtc1      $v0, $f4
/* BFEF74 802416F4 00000000 */  nop
/* BFEF78 802416F8 46802120 */  cvt.s.w   $f4, $f4
/* BFEF7C 802416FC 4600203C */  c.lt.s    $f4, $f0
/* BFEF80 80241700 00000000 */  nop
/* BFEF84 80241704 4500000D */  bc1f      .L8024173C
/* BFEF88 80241708 00000000 */   nop
/* BFEF8C 8024170C 44800000 */  mtc1      $zero, $f0
/* BFEF90 80241710 C614000C */  lwc1      $f20, 0xc($s0)
/* BFEF94 80241714 4600103C */  c.lt.s    $f2, $f0
/* BFEF98 80241718 00000000 */  nop
/* BFEF9C 8024171C 45000006 */  bc1f      .L80241738
/* BFEFA0 80241720 00021023 */   negu     $v0, $v0
/* BFEFA4 80241724 44820000 */  mtc1      $v0, $f0
/* BFEFA8 80241728 00000000 */  nop
/* BFEFAC 8024172C 46800020 */  cvt.s.w   $f0, $f0
/* BFEFB0 80241730 080905CF */  j         .L8024173C
/* BFEFB4 80241734 4600A500 */   add.s    $f20, $f20, $f0
.L80241738:
/* BFEFB8 80241738 4604A500 */  add.s     $f20, $f20, $f4
.L8024173C:
/* BFEFBC 8024173C 0C00A6C9 */  jal       clamp_angle
/* BFEFC0 80241740 4600A306 */   mov.s    $f12, $f20
/* BFEFC4 80241744 2402000D */  addiu     $v0, $zero, 0xd
/* BFEFC8 80241748 E600000C */  swc1      $f0, 0xc($s0)
/* BFEFCC 8024174C AE620070 */  sw        $v0, 0x70($s3)
.L80241750:
/* BFEFD0 80241750 8FBF0020 */  lw        $ra, 0x20($sp)
/* BFEFD4 80241754 8FB3001C */  lw        $s3, 0x1c($sp)
/* BFEFD8 80241758 8FB20018 */  lw        $s2, 0x18($sp)
/* BFEFDC 8024175C 8FB10014 */  lw        $s1, 0x14($sp)
/* BFEFE0 80241760 8FB00010 */  lw        $s0, 0x10($sp)
/* BFEFE4 80241764 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BFEFE8 80241768 03E00008 */  jr        $ra
/* BFEFEC 8024176C 27BD0030 */   addiu    $sp, $sp, 0x30
