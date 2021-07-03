.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802485C8_B34A38
.double 32767.0

.section .text

glabel func_80240AAC_B2CF1C
/* B2CF1C 80240AAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2CF20 80240AB0 AFB10014 */  sw        $s1, 0x14($sp)
/* B2CF24 80240AB4 0080882D */  daddu     $s1, $a0, $zero
/* B2CF28 80240AB8 AFBF001C */  sw        $ra, 0x1c($sp)
/* B2CF2C 80240ABC AFB20018 */  sw        $s2, 0x18($sp)
/* B2CF30 80240AC0 AFB00010 */  sw        $s0, 0x10($sp)
/* B2CF34 80240AC4 8E300148 */  lw        $s0, 0x148($s1)
/* B2CF38 80240AC8 86040008 */  lh        $a0, 8($s0)
/* B2CF3C 80240ACC 0C00EABB */  jal       get_npc_unsafe
/* B2CF40 80240AD0 00A0902D */   daddu    $s2, $a1, $zero
/* B2CF44 80240AD4 8E230078 */  lw        $v1, 0x78($s1)
/* B2CF48 80240AD8 24630001 */  addiu     $v1, $v1, 1
/* B2CF4C 80240ADC AE230078 */  sw        $v1, 0x78($s1)
/* B2CF50 80240AE0 8E0400D0 */  lw        $a0, 0xd0($s0)
/* B2CF54 80240AE4 8C840000 */  lw        $a0, ($a0)
/* B2CF58 80240AE8 0064182A */  slt       $v1, $v1, $a0
/* B2CF5C 80240AEC 14600002 */  bnez      $v1, .L80240AF8
/* B2CF60 80240AF0 0040282D */   daddu    $a1, $v0, $zero
/* B2CF64 80240AF4 AE200078 */  sw        $zero, 0x78($s1)
.L80240AF8:
/* B2CF68 80240AF8 8E0200CC */  lw        $v0, 0xcc($s0)
/* B2CF6C 80240AFC 8C420004 */  lw        $v0, 4($v0)
/* B2CF70 80240B00 ACA20028 */  sw        $v0, 0x28($a1)
/* B2CF74 80240B04 8E0200D0 */  lw        $v0, 0xd0($s0)
/* B2CF78 80240B08 8C42007C */  lw        $v0, 0x7c($v0)
/* B2CF7C 80240B0C 04410004 */  bgez      $v0, .L80240B20
/* B2CF80 80240B10 00000000 */   nop
/* B2CF84 80240B14 C6400000 */  lwc1      $f0, ($s2)
/* B2CF88 80240B18 080902D0 */  j         .L80240B40
/* B2CF8C 80240B1C E4A00018 */   swc1     $f0, 0x18($a1)
.L80240B20:
/* B2CF90 80240B20 3C018025 */  lui       $at, %hi(D_802485C8_B34A38)
/* B2CF94 80240B24 D42285C8 */  ldc1      $f2, %lo(D_802485C8_B34A38)($at)
/* B2CF98 80240B28 44820000 */  mtc1      $v0, $f0
/* B2CF9C 80240B2C 00000000 */  nop
/* B2CFA0 80240B30 46800021 */  cvt.d.w   $f0, $f0
/* B2CFA4 80240B34 46220003 */  div.d     $f0, $f0, $f2
/* B2CFA8 80240B38 46200020 */  cvt.s.d   $f0, $f0
/* B2CFAC 80240B3C E4A00018 */  swc1      $f0, 0x18($a1)
.L80240B40:
/* B2CFB0 80240B40 24020001 */  addiu     $v0, $zero, 1
/* B2CFB4 80240B44 AE220070 */  sw        $v0, 0x70($s1)
/* B2CFB8 80240B48 8FBF001C */  lw        $ra, 0x1c($sp)
/* B2CFBC 80240B4C 8FB20018 */  lw        $s2, 0x18($sp)
/* B2CFC0 80240B50 8FB10014 */  lw        $s1, 0x14($sp)
/* B2CFC4 80240B54 8FB00010 */  lw        $s0, 0x10($sp)
/* B2CFC8 80240B58 03E00008 */  jr        $ra
/* B2CFCC 80240B5C 27BD0020 */   addiu    $sp, $sp, 0x20
