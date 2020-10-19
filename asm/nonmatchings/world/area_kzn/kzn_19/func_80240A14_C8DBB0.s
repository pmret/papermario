.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A14_C8E5C4
/* C8E5C4 80240A14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8E5C8 80240A18 AFBF0014 */  sw        $ra, 0x14($sp)
/* C8E5CC 80240A1C AFB00010 */  sw        $s0, 0x10($sp)
/* C8E5D0 80240A20 8C900084 */  lw        $s0, 0x84($a0)
/* C8E5D4 80240A24 8602004C */  lh        $v0, 0x4c($s0)
/* C8E5D8 80240A28 44826000 */  mtc1      $v0, $f12
/* C8E5DC 80240A2C 00000000 */  nop       
/* C8E5E0 80240A30 0C00A8BB */  jal       sin_deg
/* C8E5E4 80240A34 46806320 */   cvt.s.w  $f12, $f12
/* C8E5E8 80240A38 3C013F80 */  lui       $at, 0x3f80
/* C8E5EC 80240A3C 44811000 */  mtc1      $at, $f2
/* C8E5F0 80240A40 00000000 */  nop       
/* C8E5F4 80240A44 46020000 */  add.s     $f0, $f0, $f2
/* C8E5F8 80240A48 46000000 */  add.s     $f0, $f0, $f0
/* C8E5FC 80240A4C C6020024 */  lwc1      $f2, 0x24($s0)
/* C8E600 80240A50 8602004C */  lh        $v0, 0x4c($s0)
/* C8E604 80240A54 46001080 */  add.s     $f2, $f2, $f0
/* C8E608 80240A58 24420008 */  addiu     $v0, $v0, 8
/* C8E60C 80240A5C 44826000 */  mtc1      $v0, $f12
/* C8E610 80240A60 00000000 */  nop       
/* C8E614 80240A64 46806320 */  cvt.s.w   $f12, $f12
/* C8E618 80240A68 0C00A6C9 */  jal       clamp_angle
/* C8E61C 80240A6C E6020004 */   swc1     $f2, 4($s0)
/* C8E620 80240A70 4600010D */  trunc.w.s $f4, $f0
/* C8E624 80240A74 44022000 */  mfc1      $v0, $f4
/* C8E628 80240A78 00000000 */  nop       
/* C8E62C 80240A7C A602004C */  sh        $v0, 0x4c($s0)
/* C8E630 80240A80 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C8E634 80240A84 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* C8E638 80240A88 C44C0028 */  lwc1      $f12, 0x28($v0)
/* C8E63C 80240A8C C44E0030 */  lwc1      $f14, 0x30($v0)
/* C8E640 80240A90 8E060018 */  lw        $a2, 0x18($s0)
/* C8E644 80240A94 0C00A7B5 */  jal       dist2D
/* C8E648 80240A98 8E070020 */   lw       $a3, 0x20($s0)
/* C8E64C 80240A9C 3C0141F0 */  lui       $at, 0x41f0
/* C8E650 80240AA0 44811000 */  mtc1      $at, $f2
/* C8E654 80240AA4 00000000 */  nop       
/* C8E658 80240AA8 4602003E */  c.le.s    $f0, $f2
/* C8E65C 80240AAC 00000000 */  nop       
/* C8E660 80240AB0 45000002 */  bc1f      .L80240ABC
/* C8E664 80240AB4 24020003 */   addiu    $v0, $zero, 3
/* C8E668 80240AB8 A602004E */  sh        $v0, 0x4e($s0)
.L80240ABC:
/* C8E66C 80240ABC 8E020054 */  lw        $v0, 0x54($s0)
/* C8E670 80240AC0 C6000018 */  lwc1      $f0, 0x18($s0)
/* C8E674 80240AC4 8C42000C */  lw        $v0, 0xc($v0)
/* C8E678 80240AC8 E4400004 */  swc1      $f0, 4($v0)
/* C8E67C 80240ACC 8E020054 */  lw        $v0, 0x54($s0)
/* C8E680 80240AD0 C6000004 */  lwc1      $f0, 4($s0)
/* C8E684 80240AD4 8C42000C */  lw        $v0, 0xc($v0)
/* C8E688 80240AD8 E4400008 */  swc1      $f0, 8($v0)
/* C8E68C 80240ADC 8E020054 */  lw        $v0, 0x54($s0)
/* C8E690 80240AE0 C6000020 */  lwc1      $f0, 0x20($s0)
/* C8E694 80240AE4 8C42000C */  lw        $v0, 0xc($v0)
/* C8E698 80240AE8 E440000C */  swc1      $f0, 0xc($v0)
/* C8E69C 80240AEC 8FBF0014 */  lw        $ra, 0x14($sp)
/* C8E6A0 80240AF0 8FB00010 */  lw        $s0, 0x10($sp)
/* C8E6A4 80240AF4 0000102D */  daddu     $v0, $zero, $zero
/* C8E6A8 80240AF8 03E00008 */  jr        $ra
/* C8E6AC 80240AFC 27BD0018 */   addiu    $sp, $sp, 0x18
