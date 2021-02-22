.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024486C_A2EAAC
/* A2EAAC 8024486C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A2EAB0 80244870 AFB00018 */  sw        $s0, 0x18($sp)
/* A2EAB4 80244874 00A0802D */  daddu     $s0, $a1, $zero
/* A2EAB8 80244878 AFBF0020 */  sw        $ra, 0x20($sp)
/* A2EABC 8024487C AFB1001C */  sw        $s1, 0x1c($sp)
/* A2EAC0 80244880 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A2EAC4 80244884 0C0B36B0 */  jal       resolve_npc
/* A2EAC8 80244888 24050009 */   addiu    $a1, $zero, 9
/* A2EACC 8024488C 12000004 */  beqz      $s0, .L802448A0
/* A2EAD0 80244890 0040882D */   daddu    $s1, $v0, $zero
/* A2EAD4 80244894 C620003C */  lwc1      $f0, 0x3c($s1)
/* A2EAD8 80244898 3C018025 */  lui       $at, %hi(D_8024F378)
/* A2EADC 8024489C E420F378 */  swc1      $f0, %lo(D_8024F378)($at)
.L802448A0:
/* A2EAE0 802448A0 3C018025 */  lui       $at, %hi(D_8024F378)
/* A2EAE4 802448A4 C420F378 */  lwc1      $f0, %lo(D_8024F378)($at)
/* A2EAE8 802448A8 24040003 */  addiu     $a0, $zero, 3
/* A2EAEC 802448AC 44050000 */  mfc1      $a1, $f0
/* A2EAF0 802448B0 3C0143FA */  lui       $at, 0x43fa
/* A2EAF4 802448B4 44810000 */  mtc1      $at, $f0
/* A2EAF8 802448B8 44852000 */  mtc1      $a1, $f4
/* A2EAFC 802448BC 3C108025 */  lui       $s0, %hi(D_8024AEC8_A35108)
/* A2EB00 802448C0 2610AEC8 */  addiu     $s0, $s0, %lo(D_8024AEC8_A35108)
/* A2EB04 802448C4 46002100 */  add.s     $f4, $f4, $f0
/* A2EB08 802448C8 3C014220 */  lui       $at, 0x4220
/* A2EB0C 802448CC 4481A000 */  mtc1      $at, $f20
/* A2EB10 802448D0 8E070000 */  lw        $a3, ($s0)
/* A2EB14 802448D4 44062000 */  mfc1      $a2, $f4
/* A2EB18 802448D8 2622003C */  addiu     $v0, $s1, 0x3c
/* A2EB1C 802448DC AFA20014 */  sw        $v0, 0x14($sp)
/* A2EB20 802448E0 0C090439 */  jal       func_802410E4_A2B324
/* A2EB24 802448E4 E7B40010 */   swc1     $f20, 0x10($sp)
/* A2EB28 802448E8 C6020000 */  lwc1      $f2, ($s0)
/* A2EB2C 802448EC 3C013F80 */  lui       $at, 0x3f80
/* A2EB30 802448F0 44810000 */  mtc1      $at, $f0
/* A2EB34 802448F4 00000000 */  nop
/* A2EB38 802448F8 46001080 */  add.s     $f2, $f2, $f0
/* A2EB3C 802448FC C620003C */  lwc1      $f0, 0x3c($s1)
/* A2EB40 80244900 24020001 */  addiu     $v0, $zero, 1
/* A2EB44 80244904 E6200070 */  swc1      $f0, 0x70($s1)
/* A2EB48 80244908 4602A03C */  c.lt.s    $f20, $f2
/* A2EB4C 8024490C 00000000 */  nop
/* A2EB50 80244910 45010002 */  bc1t      .L8024491C
/* A2EB54 80244914 E6020000 */   swc1     $f2, ($s0)
/* A2EB58 80244918 0000102D */  daddu     $v0, $zero, $zero
.L8024491C:
/* A2EB5C 8024491C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2EB60 80244920 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2EB64 80244924 8FB00018 */  lw        $s0, 0x18($sp)
/* A2EB68 80244928 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A2EB6C 8024492C 03E00008 */  jr        $ra
/* A2EB70 80244930 27BD0030 */   addiu    $sp, $sp, 0x30
