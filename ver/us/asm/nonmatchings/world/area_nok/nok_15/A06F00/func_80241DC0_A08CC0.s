.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80244D68_A0BC68
.word L80241ECC_A08DCC, L80241EDC_A08DDC, L80241EF4_A08DF4, L80241F04_A08E04, L80241F84_A08E84, L80241F84_A08E84, L80241F84_A08E84, L80241F84_A08E84, L80241F84_A08E84, L80241F84_A08E84, L80241F1C_A08E1C, L80241F2C_A08E2C, L80241F44_A08E44, L80241F5C_A08E5C, L80241F74_A08E74, 0

.section .text

glabel func_80241DC0_A08CC0
/* A08CC0 80241DC0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A08CC4 80241DC4 AFB40040 */  sw        $s4, 0x40($sp)
/* A08CC8 80241DC8 0080A02D */  daddu     $s4, $a0, $zero
/* A08CCC 80241DCC AFBF0048 */  sw        $ra, 0x48($sp)
/* A08CD0 80241DD0 AFB50044 */  sw        $s5, 0x44($sp)
/* A08CD4 80241DD4 AFB3003C */  sw        $s3, 0x3c($sp)
/* A08CD8 80241DD8 AFB20038 */  sw        $s2, 0x38($sp)
/* A08CDC 80241DDC AFB10034 */  sw        $s1, 0x34($sp)
/* A08CE0 80241DE0 AFB00030 */  sw        $s0, 0x30($sp)
/* A08CE4 80241DE4 8E920148 */  lw        $s2, 0x148($s4)
/* A08CE8 80241DE8 86440008 */  lh        $a0, 8($s2)
/* A08CEC 80241DEC 8E90000C */  lw        $s0, 0xc($s4)
/* A08CF0 80241DF0 0C00EABB */  jal       get_npc_unsafe
/* A08CF4 80241DF4 00A0882D */   daddu    $s1, $a1, $zero
/* A08CF8 80241DF8 0280202D */  daddu     $a0, $s4, $zero
/* A08CFC 80241DFC 8E050000 */  lw        $a1, ($s0)
/* A08D00 80241E00 0C0B1EAF */  jal       evt_get_variable
/* A08D04 80241E04 0040A82D */   daddu    $s5, $v0, $zero
/* A08D08 80241E08 AFA00010 */  sw        $zero, 0x10($sp)
/* A08D0C 80241E0C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A08D10 80241E10 8C630030 */  lw        $v1, 0x30($v1)
/* A08D14 80241E14 AFA30014 */  sw        $v1, 0x14($sp)
/* A08D18 80241E18 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A08D1C 80241E1C 8C63001C */  lw        $v1, 0x1c($v1)
/* A08D20 80241E20 AFA30018 */  sw        $v1, 0x18($sp)
/* A08D24 80241E24 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A08D28 80241E28 8C630024 */  lw        $v1, 0x24($v1)
/* A08D2C 80241E2C AFA3001C */  sw        $v1, 0x1c($sp)
/* A08D30 80241E30 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A08D34 80241E34 8C630028 */  lw        $v1, 0x28($v1)
/* A08D38 80241E38 27B30010 */  addiu     $s3, $sp, 0x10
/* A08D3C 80241E3C AFA30020 */  sw        $v1, 0x20($sp)
/* A08D40 80241E40 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A08D44 80241E44 3C0142F0 */  lui       $at, 0x42f0
/* A08D48 80241E48 44810000 */  mtc1      $at, $f0
/* A08D4C 80241E4C 8C63002C */  lw        $v1, 0x2c($v1)
/* A08D50 80241E50 0040802D */  daddu     $s0, $v0, $zero
/* A08D54 80241E54 E7A00028 */  swc1      $f0, 0x28($sp)
/* A08D58 80241E58 A7A0002C */  sh        $zero, 0x2c($sp)
/* A08D5C 80241E5C 12200006 */  beqz      $s1, .L80241E78
/* A08D60 80241E60 AFA30024 */   sw       $v1, 0x24($sp)
/* A08D64 80241E64 02A0202D */  daddu     $a0, $s5, $zero
/* A08D68 80241E68 0240282D */  daddu     $a1, $s2, $zero
/* A08D6C 80241E6C 0280302D */  daddu     $a2, $s4, $zero
/* A08D70 80241E70 0C090727 */  jal       nok_15_UnkFunc5
/* A08D74 80241E74 0200382D */   daddu    $a3, $s0, $zero
.L80241E78:
/* A08D78 80241E78 2402FFFE */  addiu     $v0, $zero, -2
/* A08D7C 80241E7C A2A200AB */  sb        $v0, 0xab($s5)
/* A08D80 80241E80 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A08D84 80241E84 30620004 */  andi      $v0, $v1, 4
/* A08D88 80241E88 10400007 */  beqz      $v0, .L80241EA8
/* A08D8C 80241E8C 00000000 */   nop
/* A08D90 80241E90 824200B4 */  lb        $v0, 0xb4($s2)
/* A08D94 80241E94 1440003C */  bnez      $v0, .L80241F88
/* A08D98 80241E98 0000102D */   daddu    $v0, $zero, $zero
/* A08D9C 80241E9C 2402FFFB */  addiu     $v0, $zero, -5
/* A08DA0 80241EA0 00621024 */  and       $v0, $v1, $v0
/* A08DA4 80241EA4 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241EA8:
/* A08DA8 80241EA8 8E830070 */  lw        $v1, 0x70($s4)
/* A08DAC 80241EAC 2C62000F */  sltiu     $v0, $v1, 0xf
/* A08DB0 80241EB0 10400034 */  beqz      $v0, L80241F84_A08E84
/* A08DB4 80241EB4 00031080 */   sll      $v0, $v1, 2
/* A08DB8 80241EB8 3C018024 */  lui       $at, %hi(jtbl_80244D68_A0BC68)
/* A08DBC 80241EBC 00220821 */  addu      $at, $at, $v0
/* A08DC0 80241EC0 8C224D68 */  lw        $v0, %lo(jtbl_80244D68_A0BC68)($at)
/* A08DC4 80241EC4 00400008 */  jr        $v0
/* A08DC8 80241EC8 00000000 */   nop
dlabel L80241ECC_A08DCC
/* A08DCC 80241ECC 0280202D */  daddu     $a0, $s4, $zero
/* A08DD0 80241ED0 0200282D */  daddu     $a1, $s0, $zero
/* A08DD4 80241ED4 0C0902AD */  jal       nok_15_UnkNpcAIFunc23
/* A08DD8 80241ED8 0260302D */   daddu    $a2, $s3, $zero
dlabel L80241EDC_A08DDC
/* A08DDC 80241EDC 0280202D */  daddu     $a0, $s4, $zero
/* A08DE0 80241EE0 0200282D */  daddu     $a1, $s0, $zero
/* A08DE4 80241EE4 0C090319 */  jal       func_80240C64_A07B64
/* A08DE8 80241EE8 0260302D */   daddu    $a2, $s3, $zero
/* A08DEC 80241EEC 080907E2 */  j         .L80241F88
/* A08DF0 80241EF0 0000102D */   daddu    $v0, $zero, $zero
dlabel L80241EF4_A08DF4
/* A08DF4 80241EF4 0280202D */  daddu     $a0, $s4, $zero
/* A08DF8 80241EF8 0200282D */  daddu     $a1, $s0, $zero
/* A08DFC 80241EFC 0C0904A3 */  jal       nok_15_UnkNpcAIFunc1
/* A08E00 80241F00 0260302D */   daddu    $a2, $s3, $zero
dlabel L80241F04_A08E04
/* A08E04 80241F04 0280202D */  daddu     $a0, $s4, $zero
/* A08E08 80241F08 0200282D */  daddu     $a1, $s0, $zero
/* A08E0C 80241F0C 0C0904D3 */  jal       nok_15_UnkFunc4
/* A08E10 80241F10 0260302D */   daddu    $a2, $s3, $zero
/* A08E14 80241F14 080907E2 */  j         .L80241F88
/* A08E18 80241F18 0000102D */   daddu    $v0, $zero, $zero
dlabel L80241F1C_A08E1C
/* A08E1C 80241F1C 0280202D */  daddu     $a0, $s4, $zero
/* A08E20 80241F20 0200282D */  daddu     $a1, $s0, $zero
/* A08E24 80241F24 0C0905A4 */  jal       nok_15_UnkNpcAIFunc2
/* A08E28 80241F28 0260302D */   daddu    $a2, $s3, $zero
dlabel L80241F2C_A08E2C
/* A08E2C 80241F2C 0280202D */  daddu     $a0, $s4, $zero
/* A08E30 80241F30 0200282D */  daddu     $a1, $s0, $zero
/* A08E34 80241F34 0C0905C2 */  jal       func_80241708_A08608
/* A08E38 80241F38 0260302D */   daddu    $a2, $s3, $zero
/* A08E3C 80241F3C 080907E2 */  j         .L80241F88
/* A08E40 80241F40 0000102D */   daddu    $v0, $zero, $zero
dlabel L80241F44_A08E44
/* A08E44 80241F44 0280202D */  daddu     $a0, $s4, $zero
/* A08E48 80241F48 0200282D */  daddu     $a1, $s0, $zero
/* A08E4C 80241F4C 0C0905DD */  jal       nok_15_UnkNpcAIFunc14
/* A08E50 80241F50 0260302D */   daddu    $a2, $s3, $zero
/* A08E54 80241F54 080907E2 */  j         .L80241F88
/* A08E58 80241F58 0000102D */   daddu    $v0, $zero, $zero
dlabel L80241F5C_A08E5C
/* A08E5C 80241F5C 0280202D */  daddu     $a0, $s4, $zero
/* A08E60 80241F60 0200282D */  daddu     $a1, $s0, $zero
/* A08E64 80241F64 0C09062A */  jal       nok_15_UnkNpcAIFunc3
/* A08E68 80241F68 0260302D */   daddu    $a2, $s3, $zero
/* A08E6C 80241F6C 080907E2 */  j         .L80241F88
/* A08E70 80241F70 0000102D */   daddu    $v0, $zero, $zero
dlabel L80241F74_A08E74
/* A08E74 80241F74 0280202D */  daddu     $a0, $s4, $zero
/* A08E78 80241F78 0200282D */  daddu     $a1, $s0, $zero
/* A08E7C 80241F7C 0C090643 */  jal       nok_15_UnkFunc6
/* A08E80 80241F80 0260302D */   daddu    $a2, $s3, $zero
dlabel L80241F84_A08E84
/* A08E84 80241F84 0000102D */  daddu     $v0, $zero, $zero
.L80241F88:
/* A08E88 80241F88 8FBF0048 */  lw        $ra, 0x48($sp)
/* A08E8C 80241F8C 8FB50044 */  lw        $s5, 0x44($sp)
/* A08E90 80241F90 8FB40040 */  lw        $s4, 0x40($sp)
/* A08E94 80241F94 8FB3003C */  lw        $s3, 0x3c($sp)
/* A08E98 80241F98 8FB20038 */  lw        $s2, 0x38($sp)
/* A08E9C 80241F9C 8FB10034 */  lw        $s1, 0x34($sp)
/* A08EA0 80241FA0 8FB00030 */  lw        $s0, 0x30($sp)
/* A08EA4 80241FA4 03E00008 */  jr        $ra
/* A08EA8 80241FA8 27BD0050 */   addiu    $sp, $sp, 0x50
