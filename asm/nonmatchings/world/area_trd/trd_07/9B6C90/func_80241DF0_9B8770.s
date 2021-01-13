.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DF0_9B8770
/* 9B8770 80241DF0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9B8774 80241DF4 AFB40040 */  sw        $s4, 0x40($sp)
/* 9B8778 80241DF8 0080A02D */  daddu     $s4, $a0, $zero
/* 9B877C 80241DFC AFBF0048 */  sw        $ra, 0x48($sp)
/* 9B8780 80241E00 AFB50044 */  sw        $s5, 0x44($sp)
/* 9B8784 80241E04 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9B8788 80241E08 AFB20038 */  sw        $s2, 0x38($sp)
/* 9B878C 80241E0C AFB10034 */  sw        $s1, 0x34($sp)
/* 9B8790 80241E10 AFB00030 */  sw        $s0, 0x30($sp)
/* 9B8794 80241E14 8E920148 */  lw        $s2, 0x148($s4)
/* 9B8798 80241E18 86440008 */  lh        $a0, 8($s2)
/* 9B879C 80241E1C 8E90000C */  lw        $s0, 0xc($s4)
/* 9B87A0 80241E20 0C00EABB */  jal       get_npc_unsafe
/* 9B87A4 80241E24 00A0882D */   daddu    $s1, $a1, $zero
/* 9B87A8 80241E28 0280202D */  daddu     $a0, $s4, $zero
/* 9B87AC 80241E2C 8E050000 */  lw        $a1, ($s0)
/* 9B87B0 80241E30 0C0B1EAF */  jal       get_variable
/* 9B87B4 80241E34 0040A82D */   daddu    $s5, $v0, $zero
/* 9B87B8 80241E38 AFA00010 */  sw        $zero, 0x10($sp)
/* 9B87BC 80241E3C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B87C0 80241E40 8C630030 */  lw        $v1, 0x30($v1)
/* 9B87C4 80241E44 AFA30014 */  sw        $v1, 0x14($sp)
/* 9B87C8 80241E48 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B87CC 80241E4C 8C63001C */  lw        $v1, 0x1c($v1)
/* 9B87D0 80241E50 AFA30018 */  sw        $v1, 0x18($sp)
/* 9B87D4 80241E54 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B87D8 80241E58 8C630024 */  lw        $v1, 0x24($v1)
/* 9B87DC 80241E5C AFA3001C */  sw        $v1, 0x1c($sp)
/* 9B87E0 80241E60 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B87E4 80241E64 8C630028 */  lw        $v1, 0x28($v1)
/* 9B87E8 80241E68 27B30010 */  addiu     $s3, $sp, 0x10
/* 9B87EC 80241E6C AFA30020 */  sw        $v1, 0x20($sp)
/* 9B87F0 80241E70 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B87F4 80241E74 3C0142F0 */  lui       $at, 0x42f0
/* 9B87F8 80241E78 44810000 */  mtc1      $at, $f0
/* 9B87FC 80241E7C 8C63002C */  lw        $v1, 0x2c($v1)
/* 9B8800 80241E80 0040802D */  daddu     $s0, $v0, $zero
/* 9B8804 80241E84 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9B8808 80241E88 A7A0002C */  sh        $zero, 0x2c($sp)
/* 9B880C 80241E8C 12200006 */  beqz      $s1, .L80241EA8
/* 9B8810 80241E90 AFA30024 */   sw       $v1, 0x24($sp)
/* 9B8814 80241E94 02A0202D */  daddu     $a0, $s5, $zero
/* 9B8818 80241E98 0240282D */  daddu     $a1, $s2, $zero
/* 9B881C 80241E9C 0280302D */  daddu     $a2, $s4, $zero
/* 9B8820 80241EA0 0C090733 */  jal       func_80241CCC_9B864C
/* 9B8824 80241EA4 0200382D */   daddu    $a3, $s0, $zero
.L80241EA8:
/* 9B8828 80241EA8 2402FFFE */  addiu     $v0, $zero, -2
/* 9B882C 80241EAC A2A200AB */  sb        $v0, 0xab($s5)
/* 9B8830 80241EB0 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 9B8834 80241EB4 30620004 */  andi      $v0, $v1, 4
/* 9B8838 80241EB8 10400007 */  beqz      $v0, .L80241ED8
/* 9B883C 80241EBC 00000000 */   nop
/* 9B8840 80241EC0 824200B4 */  lb        $v0, 0xb4($s2)
/* 9B8844 80241EC4 1440003C */  bnez      $v0, .L80241FB8
/* 9B8848 80241EC8 0000102D */   daddu    $v0, $zero, $zero
/* 9B884C 80241ECC 2402FFFB */  addiu     $v0, $zero, -5
/* 9B8850 80241ED0 00621024 */  and       $v0, $v1, $v0
/* 9B8854 80241ED4 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241ED8:
/* 9B8858 80241ED8 8E830070 */  lw        $v1, 0x70($s4)
/* 9B885C 80241EDC 2C62000F */  sltiu     $v0, $v1, 0xf
/* 9B8860 80241EE0 10400034 */  beqz      $v0, .L80241FB4
/* 9B8864 80241EE4 00031080 */   sll      $v0, $v1, 2
/* 9B8868 80241EE8 3C018024 */  lui       $at, %hi(jtbl_80244898_9BB218)
/* 9B886C 80241EEC 00220821 */  addu      $at, $at, $v0
/* 9B8870 80241EF0 8C224898 */  lw        $v0, %lo(jtbl_80244898_9BB218)($at)
/* 9B8874 80241EF4 00400008 */  jr        $v0
/* 9B8878 80241EF8 00000000 */   nop
glabel L80241EFC_9B887C
/* 9B887C 80241EFC 0280202D */  daddu     $a0, $s4, $zero
/* 9B8880 80241F00 0200282D */  daddu     $a1, $s0, $zero
/* 9B8884 80241F04 0C0902B9 */  jal       func_80240AE4_9B7464
/* 9B8888 80241F08 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F0C_9B888C
/* 9B888C 80241F0C 0280202D */  daddu     $a0, $s4, $zero
/* 9B8890 80241F10 0200282D */  daddu     $a1, $s0, $zero
/* 9B8894 80241F14 0C090325 */  jal       func_80240C94_9B7614
/* 9B8898 80241F18 0260302D */   daddu    $a2, $s3, $zero
/* 9B889C 80241F1C 080907EE */  j         .L80241FB8
/* 9B88A0 80241F20 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F24_9B88A4
/* 9B88A4 80241F24 0280202D */  daddu     $a0, $s4, $zero
/* 9B88A8 80241F28 0200282D */  daddu     $a1, $s0, $zero
/* 9B88AC 80241F2C 0C0904AF */  jal       trd_07_UnkNpcAIFunc1
/* 9B88B0 80241F30 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F34_9B88B4
/* 9B88B4 80241F34 0280202D */  daddu     $a0, $s4, $zero
/* 9B88B8 80241F38 0200282D */  daddu     $a1, $s0, $zero
/* 9B88BC 80241F3C 0C0904DF */  jal       func_8024137C_9B7CFC
/* 9B88C0 80241F40 0260302D */   daddu    $a2, $s3, $zero
/* 9B88C4 80241F44 080907EE */  j         .L80241FB8
/* 9B88C8 80241F48 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F4C_9B88CC
/* 9B88CC 80241F4C 0280202D */  daddu     $a0, $s4, $zero
/* 9B88D0 80241F50 0200282D */  daddu     $a1, $s0, $zero
/* 9B88D4 80241F54 0C0905B0 */  jal       trd_07_UnkNpcAIFunc2
/* 9B88D8 80241F58 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F5C_9B88DC
/* 9B88DC 80241F5C 0280202D */  daddu     $a0, $s4, $zero
/* 9B88E0 80241F60 0200282D */  daddu     $a1, $s0, $zero
/* 9B88E4 80241F64 0C0905CE */  jal       func_80241738_9B80B8
/* 9B88E8 80241F68 0260302D */   daddu    $a2, $s3, $zero
/* 9B88EC 80241F6C 080907EE */  j         .L80241FB8
/* 9B88F0 80241F70 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F74_9B88F4
/* 9B88F4 80241F74 0280202D */  daddu     $a0, $s4, $zero
/* 9B88F8 80241F78 0200282D */  daddu     $a1, $s0, $zero
/* 9B88FC 80241F7C 0C0905E9 */  jal       func_802417A4_9B8124
/* 9B8900 80241F80 0260302D */   daddu    $a2, $s3, $zero
/* 9B8904 80241F84 080907EE */  j         .L80241FB8
/* 9B8908 80241F88 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F8C_9B890C
/* 9B890C 80241F8C 0280202D */  daddu     $a0, $s4, $zero
/* 9B8910 80241F90 0200282D */  daddu     $a1, $s0, $zero
/* 9B8914 80241F94 0C090636 */  jal       trd_07_UnkNpcAIFunc3
/* 9B8918 80241F98 0260302D */   daddu    $a2, $s3, $zero
/* 9B891C 80241F9C 080907EE */  j         .L80241FB8
/* 9B8920 80241FA0 0000102D */   daddu    $v0, $zero, $zero
glabel L80241FA4_9B8924
/* 9B8924 80241FA4 0280202D */  daddu     $a0, $s4, $zero
/* 9B8928 80241FA8 0200282D */  daddu     $a1, $s0, $zero
/* 9B892C 80241FAC 0C09064F */  jal       func_8024193C_9B82BC
/* 9B8930 80241FB0 0260302D */   daddu    $a2, $s3, $zero
.L80241FB4:
glabel L80241FB4_9B8934
/* 9B8934 80241FB4 0000102D */  daddu     $v0, $zero, $zero
.L80241FB8:
/* 9B8938 80241FB8 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9B893C 80241FBC 8FB50044 */  lw        $s5, 0x44($sp)
/* 9B8940 80241FC0 8FB40040 */  lw        $s4, 0x40($sp)
/* 9B8944 80241FC4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9B8948 80241FC8 8FB20038 */  lw        $s2, 0x38($sp)
/* 9B894C 80241FCC 8FB10034 */  lw        $s1, 0x34($sp)
/* 9B8950 80241FD0 8FB00030 */  lw        $s0, 0x30($sp)
/* 9B8954 80241FD4 03E00008 */  jr        $ra
/* 9B8958 80241FD8 27BD0050 */   addiu    $sp, $sp, 0x50
