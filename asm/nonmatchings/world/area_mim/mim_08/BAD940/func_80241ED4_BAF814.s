.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241ED4_BAF814
/* BAF814 80241ED4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BAF818 80241ED8 AFB3003C */  sw        $s3, 0x3c($sp)
/* BAF81C 80241EDC 0080982D */  daddu     $s3, $a0, $zero
/* BAF820 80241EE0 AFBF0040 */  sw        $ra, 0x40($sp)
/* BAF824 80241EE4 AFB20038 */  sw        $s2, 0x38($sp)
/* BAF828 80241EE8 AFB10034 */  sw        $s1, 0x34($sp)
/* BAF82C 80241EEC AFB00030 */  sw        $s0, 0x30($sp)
/* BAF830 80241EF0 8E720148 */  lw        $s2, 0x148($s3)
/* BAF834 80241EF4 00A0882D */  daddu     $s1, $a1, $zero
/* BAF838 80241EF8 86440008 */  lh        $a0, 8($s2)
/* BAF83C 80241EFC 0C00EABB */  jal       get_npc_unsafe
/* BAF840 80241F00 00C0802D */   daddu    $s0, $a2, $zero
/* BAF844 80241F04 0200202D */  daddu     $a0, $s0, $zero
/* BAF848 80241F08 0240282D */  daddu     $a1, $s2, $zero
/* BAF84C 80241F0C AFA00010 */  sw        $zero, 0x10($sp)
/* BAF850 80241F10 8E26000C */  lw        $a2, 0xc($s1)
/* BAF854 80241F14 8E270010 */  lw        $a3, 0x10($s1)
/* BAF858 80241F18 0C01242D */  jal       func_800490B4
/* BAF85C 80241F1C 0040882D */   daddu    $s1, $v0, $zero
/* BAF860 80241F20 10400024 */  beqz      $v0, .L80241FB4
/* BAF864 80241F24 0220202D */   daddu    $a0, $s1, $zero
/* BAF868 80241F28 24050322 */  addiu     $a1, $zero, 0x322
/* BAF86C 80241F2C 0C012530 */  jal       func_800494C0
/* BAF870 80241F30 0000302D */   daddu    $a2, $zero, $zero
/* BAF874 80241F34 0000202D */  daddu     $a0, $zero, $zero
/* BAF878 80241F38 0220282D */  daddu     $a1, $s1, $zero
/* BAF87C 80241F3C 0000302D */  daddu     $a2, $zero, $zero
/* BAF880 80241F40 2410000A */  addiu     $s0, $zero, 0xa
/* BAF884 80241F44 862300A8 */  lh        $v1, 0xa8($s1)
/* BAF888 80241F48 3C013F80 */  lui       $at, 0x3f80
/* BAF88C 80241F4C 44810000 */  mtc1      $at, $f0
/* BAF890 80241F50 3C014000 */  lui       $at, 0x4000
/* BAF894 80241F54 44811000 */  mtc1      $at, $f2
/* BAF898 80241F58 3C01C1A0 */  lui       $at, 0xc1a0
/* BAF89C 80241F5C 44812000 */  mtc1      $at, $f4
/* BAF8A0 80241F60 44833000 */  mtc1      $v1, $f6
/* BAF8A4 80241F64 00000000 */  nop       
/* BAF8A8 80241F68 468031A0 */  cvt.s.w   $f6, $f6
/* BAF8AC 80241F6C 44073000 */  mfc1      $a3, $f6
/* BAF8B0 80241F70 27A20028 */  addiu     $v0, $sp, 0x28
/* BAF8B4 80241F74 AFB0001C */  sw        $s0, 0x1c($sp)
/* BAF8B8 80241F78 AFA20020 */  sw        $v0, 0x20($sp)
/* BAF8BC 80241F7C E7A00010 */  swc1      $f0, 0x10($sp)
/* BAF8C0 80241F80 E7A20014 */  swc1      $f2, 0x14($sp)
/* BAF8C4 80241F84 0C01BFA4 */  jal       fx_emote
/* BAF8C8 80241F88 E7A40018 */   swc1     $f4, 0x18($sp)
/* BAF8CC 80241F8C 0220202D */  daddu     $a0, $s1, $zero
/* BAF8D0 80241F90 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BAF8D4 80241F94 0C012530 */  jal       func_800494C0
/* BAF8D8 80241F98 3C060020 */   lui      $a2, 0x20
/* BAF8DC 80241F9C 8E4200CC */  lw        $v0, 0xcc($s2)
/* BAF8E0 80241FA0 8C420020 */  lw        $v0, 0x20($v0)
/* BAF8E4 80241FA4 AE220028 */  sw        $v0, 0x28($s1)
/* BAF8E8 80241FA8 9642008E */  lhu       $v0, 0x8e($s2)
/* BAF8EC 80241FAC A622008E */  sh        $v0, 0x8e($s1)
/* BAF8F0 80241FB0 AE700070 */  sw        $s0, 0x70($s3)
.L80241FB4:
/* BAF8F4 80241FB4 8FBF0040 */  lw        $ra, 0x40($sp)
/* BAF8F8 80241FB8 8FB3003C */  lw        $s3, 0x3c($sp)
/* BAF8FC 80241FBC 8FB20038 */  lw        $s2, 0x38($sp)
/* BAF900 80241FC0 8FB10034 */  lw        $s1, 0x34($sp)
/* BAF904 80241FC4 8FB00030 */  lw        $s0, 0x30($sp)
/* BAF908 80241FC8 03E00008 */  jr        $ra
/* BAF90C 80241FCC 27BD0048 */   addiu    $sp, $sp, 0x48
