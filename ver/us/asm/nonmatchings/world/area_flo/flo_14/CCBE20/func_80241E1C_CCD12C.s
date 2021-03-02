.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E1C_CCD12C
/* CCD12C 80241E1C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CCD130 80241E20 AFB40040 */  sw        $s4, 0x40($sp)
/* CCD134 80241E24 0080A02D */  daddu     $s4, $a0, $zero
/* CCD138 80241E28 AFBF0048 */  sw        $ra, 0x48($sp)
/* CCD13C 80241E2C AFB50044 */  sw        $s5, 0x44($sp)
/* CCD140 80241E30 AFB3003C */  sw        $s3, 0x3c($sp)
/* CCD144 80241E34 AFB20038 */  sw        $s2, 0x38($sp)
/* CCD148 80241E38 AFB10034 */  sw        $s1, 0x34($sp)
/* CCD14C 80241E3C AFB00030 */  sw        $s0, 0x30($sp)
/* CCD150 80241E40 8E920148 */  lw        $s2, 0x148($s4)
/* CCD154 80241E44 86440008 */  lh        $a0, 8($s2)
/* CCD158 80241E48 8E90000C */  lw        $s0, 0xc($s4)
/* CCD15C 80241E4C 0C00EABB */  jal       get_npc_unsafe
/* CCD160 80241E50 00A0882D */   daddu    $s1, $a1, $zero
/* CCD164 80241E54 0280202D */  daddu     $a0, $s4, $zero
/* CCD168 80241E58 8E050000 */  lw        $a1, ($s0)
/* CCD16C 80241E5C 0C0B1EAF */  jal       get_variable
/* CCD170 80241E60 0040A82D */   daddu    $s5, $v0, $zero
/* CCD174 80241E64 AFA00010 */  sw        $zero, 0x10($sp)
/* CCD178 80241E68 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CCD17C 80241E6C 8C630030 */  lw        $v1, 0x30($v1)
/* CCD180 80241E70 AFA30014 */  sw        $v1, 0x14($sp)
/* CCD184 80241E74 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CCD188 80241E78 8C63001C */  lw        $v1, 0x1c($v1)
/* CCD18C 80241E7C AFA30018 */  sw        $v1, 0x18($sp)
/* CCD190 80241E80 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CCD194 80241E84 8C630024 */  lw        $v1, 0x24($v1)
/* CCD198 80241E88 AFA3001C */  sw        $v1, 0x1c($sp)
/* CCD19C 80241E8C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CCD1A0 80241E90 8C630028 */  lw        $v1, 0x28($v1)
/* CCD1A4 80241E94 27B30010 */  addiu     $s3, $sp, 0x10
/* CCD1A8 80241E98 AFA30020 */  sw        $v1, 0x20($sp)
/* CCD1AC 80241E9C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CCD1B0 80241EA0 3C0142F0 */  lui       $at, 0x42f0
/* CCD1B4 80241EA4 44810000 */  mtc1      $at, $f0
/* CCD1B8 80241EA8 8C63002C */  lw        $v1, 0x2c($v1)
/* CCD1BC 80241EAC 0040802D */  daddu     $s0, $v0, $zero
/* CCD1C0 80241EB0 E7A00028 */  swc1      $f0, 0x28($sp)
/* CCD1C4 80241EB4 A7A0002C */  sh        $zero, 0x2c($sp)
/* CCD1C8 80241EB8 12200006 */  beqz      $s1, .L80241ED4
/* CCD1CC 80241EBC AFA30024 */   sw       $v1, 0x24($sp)
/* CCD1D0 80241EC0 02A0202D */  daddu     $a0, $s5, $zero
/* CCD1D4 80241EC4 0240282D */  daddu     $a1, $s2, $zero
/* CCD1D8 80241EC8 0280302D */  daddu     $a2, $s4, $zero
/* CCD1DC 80241ECC 0C09073E */  jal       func_80241CF8_CCD008
/* CCD1E0 80241ED0 0200382D */   daddu    $a3, $s0, $zero
.L80241ED4:
/* CCD1E4 80241ED4 2402FFFE */  addiu     $v0, $zero, -2
/* CCD1E8 80241ED8 A2A200AB */  sb        $v0, 0xab($s5)
/* CCD1EC 80241EDC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* CCD1F0 80241EE0 30620004 */  andi      $v0, $v1, 4
/* CCD1F4 80241EE4 10400007 */  beqz      $v0, .L80241F04
/* CCD1F8 80241EE8 00000000 */   nop
/* CCD1FC 80241EEC 824200B4 */  lb        $v0, 0xb4($s2)
/* CCD200 80241EF0 1440003C */  bnez      $v0, .L80241FE4
/* CCD204 80241EF4 0000102D */   daddu    $v0, $zero, $zero
/* CCD208 80241EF8 2402FFFB */  addiu     $v0, $zero, -5
/* CCD20C 80241EFC 00621024 */  and       $v0, $v1, $v0
/* CCD210 80241F00 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241F04:
/* CCD214 80241F04 8E830070 */  lw        $v1, 0x70($s4)
/* CCD218 80241F08 2C62000F */  sltiu     $v0, $v1, 0xf
/* CCD21C 80241F0C 10400034 */  beqz      $v0, L80241FE0_CCD2F0
/* CCD220 80241F10 00031080 */   sll      $v0, $v1, 2
/* CCD224 80241F14 3C018024 */  lui       $at, %hi(jtbl_80245368_CD0678)
/* CCD228 80241F18 00220821 */  addu      $at, $at, $v0
/* CCD22C 80241F1C 8C225368 */  lw        $v0, %lo(jtbl_80245368_CD0678)($at)
/* CCD230 80241F20 00400008 */  jr        $v0
/* CCD234 80241F24 00000000 */   nop
glabel L80241F28_CCD238
/* CCD238 80241F28 0280202D */  daddu     $a0, $s4, $zero
/* CCD23C 80241F2C 0200282D */  daddu     $a1, $s0, $zero
/* CCD240 80241F30 0C0902C4 */  jal       func_80240B10_CCBE20
/* CCD244 80241F34 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F38_CCD248
/* CCD248 80241F38 0280202D */  daddu     $a0, $s4, $zero
/* CCD24C 80241F3C 0200282D */  daddu     $a1, $s0, $zero
/* CCD250 80241F40 0C090330 */  jal       func_80240CC0_CCBFD0
/* CCD254 80241F44 0260302D */   daddu    $a2, $s3, $zero
/* CCD258 80241F48 080907F9 */  j         .L80241FE4
/* CCD25C 80241F4C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F50_CCD260
/* CCD260 80241F50 0280202D */  daddu     $a0, $s4, $zero
/* CCD264 80241F54 0200282D */  daddu     $a1, $s0, $zero
/* CCD268 80241F58 0C0904BA */  jal       flo_14_UnkNpcAIFunc1
/* CCD26C 80241F5C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F60_CCD270
/* CCD270 80241F60 0280202D */  daddu     $a0, $s4, $zero
/* CCD274 80241F64 0200282D */  daddu     $a1, $s0, $zero
/* CCD278 80241F68 0C0904EA */  jal       func_802413A8_CCC6B8
/* CCD27C 80241F6C 0260302D */   daddu    $a2, $s3, $zero
/* CCD280 80241F70 080907F9 */  j         .L80241FE4
/* CCD284 80241F74 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F78_CCD288
/* CCD288 80241F78 0280202D */  daddu     $a0, $s4, $zero
/* CCD28C 80241F7C 0200282D */  daddu     $a1, $s0, $zero
/* CCD290 80241F80 0C0905BB */  jal       flo_14_UnkNpcAIFunc2
/* CCD294 80241F84 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F88_CCD298
/* CCD298 80241F88 0280202D */  daddu     $a0, $s4, $zero
/* CCD29C 80241F8C 0200282D */  daddu     $a1, $s0, $zero
/* CCD2A0 80241F90 0C0905D9 */  jal       func_80241764_CCCA74
/* CCD2A4 80241F94 0260302D */   daddu    $a2, $s3, $zero
/* CCD2A8 80241F98 080907F9 */  j         .L80241FE4
/* CCD2AC 80241F9C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241FA0_CCD2B0
/* CCD2B0 80241FA0 0280202D */  daddu     $a0, $s4, $zero
/* CCD2B4 80241FA4 0200282D */  daddu     $a1, $s0, $zero
/* CCD2B8 80241FA8 0C0905F4 */  jal       flo_14_UnkNpcAIFunc14
/* CCD2BC 80241FAC 0260302D */   daddu    $a2, $s3, $zero
/* CCD2C0 80241FB0 080907F9 */  j         .L80241FE4
/* CCD2C4 80241FB4 0000102D */   daddu    $v0, $zero, $zero
glabel L80241FB8_CCD2C8
/* CCD2C8 80241FB8 0280202D */  daddu     $a0, $s4, $zero
/* CCD2CC 80241FBC 0200282D */  daddu     $a1, $s0, $zero
/* CCD2D0 80241FC0 0C090641 */  jal       flo_14_UnkNpcAIFunc3
/* CCD2D4 80241FC4 0260302D */   daddu    $a2, $s3, $zero
/* CCD2D8 80241FC8 080907F9 */  j         .L80241FE4
/* CCD2DC 80241FCC 0000102D */   daddu    $v0, $zero, $zero
glabel L80241FD0_CCD2E0
/* CCD2E0 80241FD0 0280202D */  daddu     $a0, $s4, $zero
/* CCD2E4 80241FD4 0200282D */  daddu     $a1, $s0, $zero
/* CCD2E8 80241FD8 0C09065A */  jal       func_80241968_CCCC78
/* CCD2EC 80241FDC 0260302D */   daddu    $a2, $s3, $zero
glabel L80241FE0_CCD2F0
/* CCD2F0 80241FE0 0000102D */  daddu     $v0, $zero, $zero
.L80241FE4:
/* CCD2F4 80241FE4 8FBF0048 */  lw        $ra, 0x48($sp)
/* CCD2F8 80241FE8 8FB50044 */  lw        $s5, 0x44($sp)
/* CCD2FC 80241FEC 8FB40040 */  lw        $s4, 0x40($sp)
/* CCD300 80241FF0 8FB3003C */  lw        $s3, 0x3c($sp)
/* CCD304 80241FF4 8FB20038 */  lw        $s2, 0x38($sp)
/* CCD308 80241FF8 8FB10034 */  lw        $s1, 0x34($sp)
/* CCD30C 80241FFC 8FB00030 */  lw        $s0, 0x30($sp)
/* CCD310 80242000 03E00008 */  jr        $ra
/* CCD314 80242004 27BD0050 */   addiu    $sp, $sp, 0x50
