.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802470C8_DC4378
.word L80242D90_DC0040, L80242DA0_DC0050, L80242DB8_DC0068, L80242DC8_DC0078, L80242E48_DC00F8, L80242E48_DC00F8, L80242E48_DC00F8, L80242E48_DC00F8, L80242E48_DC00F8, L80242E48_DC00F8, L80242DE0_DC0090, L80242DF0_DC00A0, L80242E08_DC00B8, L80242E20_DC00D0, L80242E38_DC00E8, 0, 0, 0

.section .text

glabel func_80242C84_DBFF34
/* DBFF34 80242C84 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DBFF38 80242C88 AFB40040 */  sw        $s4, 0x40($sp)
/* DBFF3C 80242C8C 0080A02D */  daddu     $s4, $a0, $zero
/* DBFF40 80242C90 AFBF0048 */  sw        $ra, 0x48($sp)
/* DBFF44 80242C94 AFB50044 */  sw        $s5, 0x44($sp)
/* DBFF48 80242C98 AFB3003C */  sw        $s3, 0x3c($sp)
/* DBFF4C 80242C9C AFB20038 */  sw        $s2, 0x38($sp)
/* DBFF50 80242CA0 AFB10034 */  sw        $s1, 0x34($sp)
/* DBFF54 80242CA4 AFB00030 */  sw        $s0, 0x30($sp)
/* DBFF58 80242CA8 8E920148 */  lw        $s2, 0x148($s4)
/* DBFF5C 80242CAC 86440008 */  lh        $a0, 8($s2)
/* DBFF60 80242CB0 8E90000C */  lw        $s0, 0xc($s4)
/* DBFF64 80242CB4 0C00EABB */  jal       get_npc_unsafe
/* DBFF68 80242CB8 00A0882D */   daddu    $s1, $a1, $zero
/* DBFF6C 80242CBC 0280202D */  daddu     $a0, $s4, $zero
/* DBFF70 80242CC0 8E050000 */  lw        $a1, ($s0)
/* DBFF74 80242CC4 0C0B1EAF */  jal       evt_get_variable
/* DBFF78 80242CC8 0040A82D */   daddu    $s5, $v0, $zero
/* DBFF7C 80242CCC AFA00010 */  sw        $zero, 0x10($sp)
/* DBFF80 80242CD0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DBFF84 80242CD4 8C630030 */  lw        $v1, 0x30($v1)
/* DBFF88 80242CD8 AFA30014 */  sw        $v1, 0x14($sp)
/* DBFF8C 80242CDC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DBFF90 80242CE0 8C63001C */  lw        $v1, 0x1c($v1)
/* DBFF94 80242CE4 AFA30018 */  sw        $v1, 0x18($sp)
/* DBFF98 80242CE8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DBFF9C 80242CEC 8C630024 */  lw        $v1, 0x24($v1)
/* DBFFA0 80242CF0 AFA3001C */  sw        $v1, 0x1c($sp)
/* DBFFA4 80242CF4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DBFFA8 80242CF8 8C630028 */  lw        $v1, 0x28($v1)
/* DBFFAC 80242CFC 27B30010 */  addiu     $s3, $sp, 0x10
/* DBFFB0 80242D00 AFA30020 */  sw        $v1, 0x20($sp)
/* DBFFB4 80242D04 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DBFFB8 80242D08 3C0142F0 */  lui       $at, 0x42f0
/* DBFFBC 80242D0C 44810000 */  mtc1      $at, $f0
/* DBFFC0 80242D10 8C63002C */  lw        $v1, 0x2c($v1)
/* DBFFC4 80242D14 0040802D */  daddu     $s0, $v0, $zero
/* DBFFC8 80242D18 E7A00028 */  swc1      $f0, 0x28($sp)
/* DBFFCC 80242D1C A7A0002C */  sh        $zero, 0x2c($sp)
/* DBFFD0 80242D20 12200006 */  beqz      $s1, .L80242D3C
/* DBFFD4 80242D24 AFA30024 */   sw       $v1, 0x24($sp)
/* DBFFD8 80242D28 02A0202D */  daddu     $a0, $s5, $zero
/* DBFFDC 80242D2C 0240282D */  daddu     $a1, $s2, $zero
/* DBFFE0 80242D30 0280302D */  daddu     $a2, $s4, $zero
/* DBFFE4 80242D34 0C090AD8 */  jal       omo_07_UnkFunc5
/* DBFFE8 80242D38 0200382D */   daddu    $a3, $s0, $zero
.L80242D3C:
/* DBFFEC 80242D3C 2402FFFE */  addiu     $v0, $zero, -2
/* DBFFF0 80242D40 A2A200AB */  sb        $v0, 0xab($s5)
/* DBFFF4 80242D44 8E4300B0 */  lw        $v1, 0xb0($s2)
/* DBFFF8 80242D48 30620004 */  andi      $v0, $v1, 4
/* DBFFFC 80242D4C 10400007 */  beqz      $v0, .L80242D6C
/* DC0000 80242D50 00000000 */   nop
/* DC0004 80242D54 824200B4 */  lb        $v0, 0xb4($s2)
/* DC0008 80242D58 1440003C */  bnez      $v0, .L80242E4C
/* DC000C 80242D5C 0000102D */   daddu    $v0, $zero, $zero
/* DC0010 80242D60 2402FFFB */  addiu     $v0, $zero, -5
/* DC0014 80242D64 00621024 */  and       $v0, $v1, $v0
/* DC0018 80242D68 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242D6C:
/* DC001C 80242D6C 8E830070 */  lw        $v1, 0x70($s4)
/* DC0020 80242D70 2C62000F */  sltiu     $v0, $v1, 0xf
/* DC0024 80242D74 10400034 */  beqz      $v0, L80242E48_DC00F8
/* DC0028 80242D78 00031080 */   sll      $v0, $v1, 2
/* DC002C 80242D7C 3C018024 */  lui       $at, %hi(jtbl_802470C8_DC4378)
/* DC0030 80242D80 00220821 */  addu      $at, $at, $v0
/* DC0034 80242D84 8C2270C8 */  lw        $v0, %lo(jtbl_802470C8_DC4378)($at)
/* DC0038 80242D88 00400008 */  jr        $v0
/* DC003C 80242D8C 00000000 */   nop
glabel L80242D90_DC0040
/* DC0040 80242D90 0280202D */  daddu     $a0, $s4, $zero
/* DC0044 80242D94 0200282D */  daddu     $a1, $s0, $zero
/* DC0048 80242D98 0C09065E */  jal       omo_07_UnkNpcAIFunc23
/* DC004C 80242D9C 0260302D */   daddu    $a2, $s3, $zero
glabel L80242DA0_DC0050
/* DC0050 80242DA0 0280202D */  daddu     $a0, $s4, $zero
/* DC0054 80242DA4 0200282D */  daddu     $a1, $s0, $zero
/* DC0058 80242DA8 0C0906CA */  jal       func_80241B28_DBEDD8
/* DC005C 80242DAC 0260302D */   daddu    $a2, $s3, $zero
/* DC0060 80242DB0 08090B93 */  j         .L80242E4C
/* DC0064 80242DB4 0000102D */   daddu    $v0, $zero, $zero
glabel L80242DB8_DC0068
/* DC0068 80242DB8 0280202D */  daddu     $a0, $s4, $zero
/* DC006C 80242DBC 0200282D */  daddu     $a1, $s0, $zero
/* DC0070 80242DC0 0C090854 */  jal       dup_omo_07_UnkNpcAIFunc1
/* DC0074 80242DC4 0260302D */   daddu    $a2, $s3, $zero
glabel L80242DC8_DC0078
/* DC0078 80242DC8 0280202D */  daddu     $a0, $s4, $zero
/* DC007C 80242DCC 0200282D */  daddu     $a1, $s0, $zero
/* DC0080 80242DD0 0C090884 */  jal       omo_07_UnkFunc4
/* DC0084 80242DD4 0260302D */   daddu    $a2, $s3, $zero
/* DC0088 80242DD8 08090B93 */  j         .L80242E4C
/* DC008C 80242DDC 0000102D */   daddu    $v0, $zero, $zero
glabel L80242DE0_DC0090
/* DC0090 80242DE0 0280202D */  daddu     $a0, $s4, $zero
/* DC0094 80242DE4 0200282D */  daddu     $a1, $s0, $zero
/* DC0098 80242DE8 0C090955 */  jal       omo_07_UnkNpcAIFunc2
/* DC009C 80242DEC 0260302D */   daddu    $a2, $s3, $zero
glabel L80242DF0_DC00A0
/* DC00A0 80242DF0 0280202D */  daddu     $a0, $s4, $zero
/* DC00A4 80242DF4 0200282D */  daddu     $a1, $s0, $zero
/* DC00A8 80242DF8 0C090973 */  jal       func_802425CC_DBF87C
/* DC00AC 80242DFC 0260302D */   daddu    $a2, $s3, $zero
/* DC00B0 80242E00 08090B93 */  j         .L80242E4C
/* DC00B4 80242E04 0000102D */   daddu    $v0, $zero, $zero
glabel L80242E08_DC00B8
/* DC00B8 80242E08 0280202D */  daddu     $a0, $s4, $zero
/* DC00BC 80242E0C 0200282D */  daddu     $a1, $s0, $zero
/* DC00C0 80242E10 0C09098E */  jal       omo_07_UnkNpcAIFunc14
/* DC00C4 80242E14 0260302D */   daddu    $a2, $s3, $zero
/* DC00C8 80242E18 08090B93 */  j         .L80242E4C
/* DC00CC 80242E1C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242E20_DC00D0
/* DC00D0 80242E20 0280202D */  daddu     $a0, $s4, $zero
/* DC00D4 80242E24 0200282D */  daddu     $a1, $s0, $zero
/* DC00D8 80242E28 0C0909DB */  jal       omo_07_UnkNpcAIFunc3
/* DC00DC 80242E2C 0260302D */   daddu    $a2, $s3, $zero
/* DC00E0 80242E30 08090B93 */  j         .L80242E4C
/* DC00E4 80242E34 0000102D */   daddu    $v0, $zero, $zero
glabel L80242E38_DC00E8
/* DC00E8 80242E38 0280202D */  daddu     $a0, $s4, $zero
/* DC00EC 80242E3C 0200282D */  daddu     $a1, $s0, $zero
/* DC00F0 80242E40 0C0909F4 */  jal       omo_07_UnkFunc6
/* DC00F4 80242E44 0260302D */   daddu    $a2, $s3, $zero
glabel L80242E48_DC00F8
/* DC00F8 80242E48 0000102D */  daddu     $v0, $zero, $zero
.L80242E4C:
/* DC00FC 80242E4C 8FBF0048 */  lw        $ra, 0x48($sp)
/* DC0100 80242E50 8FB50044 */  lw        $s5, 0x44($sp)
/* DC0104 80242E54 8FB40040 */  lw        $s4, 0x40($sp)
/* DC0108 80242E58 8FB3003C */  lw        $s3, 0x3c($sp)
/* DC010C 80242E5C 8FB20038 */  lw        $s2, 0x38($sp)
/* DC0110 80242E60 8FB10034 */  lw        $s1, 0x34($sp)
/* DC0114 80242E64 8FB00030 */  lw        $s0, 0x30($sp)
/* DC0118 80242E68 03E00008 */  jr        $ra
/* DC011C 80242E6C 27BD0050 */   addiu    $sp, $sp, 0x50
