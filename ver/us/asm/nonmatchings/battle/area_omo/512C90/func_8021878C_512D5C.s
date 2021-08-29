.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021878C_512D5C
/* 512D5C 8021878C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 512D60 80218790 AFB10014 */  sw        $s1, 0x14($sp)
/* 512D64 80218794 0080882D */  daddu     $s1, $a0, $zero
/* 512D68 80218798 AFBF0024 */  sw        $ra, 0x24($sp)
/* 512D6C 8021879C AFB40020 */  sw        $s4, 0x20($sp)
/* 512D70 802187A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 512D74 802187A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 512D78 802187A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 512D7C 802187AC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 512D80 802187B0 8E30000C */  lw        $s0, 0xc($s1)
/* 512D84 802187B4 8E050000 */  lw        $a1, ($s0)
/* 512D88 802187B8 0C0B1EAF */  jal       get_variable
/* 512D8C 802187BC 26100004 */   addiu    $s0, $s0, 4
/* 512D90 802187C0 8E050000 */  lw        $a1, ($s0)
/* 512D94 802187C4 26100004 */  addiu     $s0, $s0, 4
/* 512D98 802187C8 0220202D */  daddu     $a0, $s1, $zero
/* 512D9C 802187CC 0C0B1EAF */  jal       get_variable
/* 512DA0 802187D0 0040A02D */   daddu    $s4, $v0, $zero
/* 512DA4 802187D4 8E050000 */  lw        $a1, ($s0)
/* 512DA8 802187D8 26100004 */  addiu     $s0, $s0, 4
/* 512DAC 802187DC 0220202D */  daddu     $a0, $s1, $zero
/* 512DB0 802187E0 0C0B1EAF */  jal       get_variable
/* 512DB4 802187E4 0040982D */   daddu    $s3, $v0, $zero
/* 512DB8 802187E8 8E050000 */  lw        $a1, ($s0)
/* 512DBC 802187EC 26100004 */  addiu     $s0, $s0, 4
/* 512DC0 802187F0 0220202D */  daddu     $a0, $s1, $zero
/* 512DC4 802187F4 0C0B210B */  jal       evt_get_float_variable
/* 512DC8 802187F8 0040902D */   daddu    $s2, $v0, $zero
/* 512DCC 802187FC 0220202D */  daddu     $a0, $s1, $zero
/* 512DD0 80218800 8E050000 */  lw        $a1, ($s0)
/* 512DD4 80218804 0C0B1EAF */  jal       get_variable
/* 512DD8 80218808 46000506 */   mov.s    $f20, $f0
/* 512DDC 8021880C 24040006 */  addiu     $a0, $zero, 6
/* 512DE0 80218810 3C058023 */  lui       $a1, %hi(D_802310D0)
/* 512DE4 80218814 24A510D0 */  addiu     $a1, $a1, %lo(D_802310D0)
/* 512DE8 80218818 44940000 */  mtc1      $s4, $f0
/* 512DEC 8021881C 00000000 */  nop
/* 512DF0 80218820 46800020 */  cvt.s.w   $f0, $f0
/* 512DF4 80218824 E4A00028 */  swc1      $f0, 0x28($a1)
/* 512DF8 80218828 44930000 */  mtc1      $s3, $f0
/* 512DFC 8021882C 00000000 */  nop
/* 512E00 80218830 46800020 */  cvt.s.w   $f0, $f0
/* 512E04 80218834 E4A0002C */  swc1      $f0, 0x2c($a1)
/* 512E08 80218838 44920000 */  mtc1      $s2, $f0
/* 512E0C 8021883C 00000000 */  nop
/* 512E10 80218840 46800020 */  cvt.s.w   $f0, $f0
/* 512E14 80218844 4406A000 */  mfc1      $a2, $f20
/* 512E18 80218848 0040382D */  daddu     $a3, $v0, $zero
/* 512E1C 8021884C 0C01C4B4 */  jal       playFX_46_whirlwind
/* 512E20 80218850 E4A00030 */   swc1     $f0, 0x30($a1)
/* 512E24 80218854 8FBF0024 */  lw        $ra, 0x24($sp)
/* 512E28 80218858 8FB40020 */  lw        $s4, 0x20($sp)
/* 512E2C 8021885C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 512E30 80218860 8FB20018 */  lw        $s2, 0x18($sp)
/* 512E34 80218864 8FB10014 */  lw        $s1, 0x14($sp)
/* 512E38 80218868 8FB00010 */  lw        $s0, 0x10($sp)
/* 512E3C 8021886C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 512E40 80218870 24020002 */  addiu     $v0, $zero, 2
/* 512E44 80218874 03E00008 */  jr        $ra
/* 512E48 80218878 27BD0030 */   addiu    $sp, $sp, 0x30
/* 512E4C 8021887C 00000000 */  nop
