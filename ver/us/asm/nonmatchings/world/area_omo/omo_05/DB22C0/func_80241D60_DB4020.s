.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D60_DB4020
/* DB4020 80241D60 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DB4024 80241D64 AFB40040 */  sw        $s4, 0x40($sp)
/* DB4028 80241D68 0080A02D */  daddu     $s4, $a0, $zero
/* DB402C 80241D6C AFBF0048 */  sw        $ra, 0x48($sp)
/* DB4030 80241D70 AFB50044 */  sw        $s5, 0x44($sp)
/* DB4034 80241D74 AFB3003C */  sw        $s3, 0x3c($sp)
/* DB4038 80241D78 AFB20038 */  sw        $s2, 0x38($sp)
/* DB403C 80241D7C AFB10034 */  sw        $s1, 0x34($sp)
/* DB4040 80241D80 AFB00030 */  sw        $s0, 0x30($sp)
/* DB4044 80241D84 8E920148 */  lw        $s2, 0x148($s4)
/* DB4048 80241D88 86440008 */  lh        $a0, 8($s2)
/* DB404C 80241D8C 8E90000C */  lw        $s0, 0xc($s4)
/* DB4050 80241D90 0C00EABB */  jal       get_npc_unsafe
/* DB4054 80241D94 00A0882D */   daddu    $s1, $a1, $zero
/* DB4058 80241D98 0280202D */  daddu     $a0, $s4, $zero
/* DB405C 80241D9C 8E050000 */  lw        $a1, ($s0)
/* DB4060 80241DA0 0C0B1EAF */  jal       get_variable
/* DB4064 80241DA4 0040A82D */   daddu    $s5, $v0, $zero
/* DB4068 80241DA8 AFA00010 */  sw        $zero, 0x10($sp)
/* DB406C 80241DAC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DB4070 80241DB0 8C630030 */  lw        $v1, 0x30($v1)
/* DB4074 80241DB4 AFA30014 */  sw        $v1, 0x14($sp)
/* DB4078 80241DB8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DB407C 80241DBC 8C63001C */  lw        $v1, 0x1c($v1)
/* DB4080 80241DC0 AFA30018 */  sw        $v1, 0x18($sp)
/* DB4084 80241DC4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DB4088 80241DC8 8C630024 */  lw        $v1, 0x24($v1)
/* DB408C 80241DCC AFA3001C */  sw        $v1, 0x1c($sp)
/* DB4090 80241DD0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DB4094 80241DD4 8C630028 */  lw        $v1, 0x28($v1)
/* DB4098 80241DD8 27B30010 */  addiu     $s3, $sp, 0x10
/* DB409C 80241DDC AFA30020 */  sw        $v1, 0x20($sp)
/* DB40A0 80241DE0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DB40A4 80241DE4 3C0142F0 */  lui       $at, 0x42f0
/* DB40A8 80241DE8 44810000 */  mtc1      $at, $f0
/* DB40AC 80241DEC 8C63002C */  lw        $v1, 0x2c($v1)
/* DB40B0 80241DF0 0040802D */  daddu     $s0, $v0, $zero
/* DB40B4 80241DF4 E7A00028 */  swc1      $f0, 0x28($sp)
/* DB40B8 80241DF8 A7A0002C */  sh        $zero, 0x2c($sp)
/* DB40BC 80241DFC 12200006 */  beqz      $s1, .L80241E18
/* DB40C0 80241E00 AFA30024 */   sw       $v1, 0x24($sp)
/* DB40C4 80241E04 02A0202D */  daddu     $a0, $s5, $zero
/* DB40C8 80241E08 0240282D */  daddu     $a1, $s2, $zero
/* DB40CC 80241E0C 0280302D */  daddu     $a2, $s4, $zero
/* DB40D0 80241E10 0C09070F */  jal       func_80241C3C_DB3EFC
/* DB40D4 80241E14 0200382D */   daddu    $a3, $s0, $zero
.L80241E18:
/* DB40D8 80241E18 2402FFFE */  addiu     $v0, $zero, -2
/* DB40DC 80241E1C A2A200AB */  sb        $v0, 0xab($s5)
/* DB40E0 80241E20 8E4300B0 */  lw        $v1, 0xb0($s2)
/* DB40E4 80241E24 30620004 */  andi      $v0, $v1, 4
/* DB40E8 80241E28 10400007 */  beqz      $v0, .L80241E48
/* DB40EC 80241E2C 00000000 */   nop
/* DB40F0 80241E30 824200B4 */  lb        $v0, 0xb4($s2)
/* DB40F4 80241E34 1440003C */  bnez      $v0, .L80241F28
/* DB40F8 80241E38 0000102D */   daddu    $v0, $zero, $zero
/* DB40FC 80241E3C 2402FFFB */  addiu     $v0, $zero, -5
/* DB4100 80241E40 00621024 */  and       $v0, $v1, $v0
/* DB4104 80241E44 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241E48:
/* DB4108 80241E48 8E830070 */  lw        $v1, 0x70($s4)
/* DB410C 80241E4C 2C62000F */  sltiu     $v0, $v1, 0xf
/* DB4110 80241E50 10400034 */  beqz      $v0, L80241F24_DB41E4
/* DB4114 80241E54 00031080 */   sll      $v0, $v1, 2
/* DB4118 80241E58 3C018024 */  lui       $at, %hi(jtbl_80245608_DB78C8)
/* DB411C 80241E5C 00220821 */  addu      $at, $at, $v0
/* DB4120 80241E60 8C225608 */  lw        $v0, %lo(jtbl_80245608_DB78C8)($at)
/* DB4124 80241E64 00400008 */  jr        $v0
/* DB4128 80241E68 00000000 */   nop
glabel L80241E6C_DB412C
/* DB412C 80241E6C 0280202D */  daddu     $a0, $s4, $zero
/* DB4130 80241E70 0200282D */  daddu     $a1, $s0, $zero
/* DB4134 80241E74 0C090295 */  jal       func_80240A54_DB2D14
/* DB4138 80241E78 0260302D */   daddu    $a2, $s3, $zero
glabel L80241E7C_DB413C
/* DB413C 80241E7C 0280202D */  daddu     $a0, $s4, $zero
/* DB4140 80241E80 0200282D */  daddu     $a1, $s0, $zero
/* DB4144 80241E84 0C090301 */  jal       func_80240C04_DB2EC4
/* DB4148 80241E88 0260302D */   daddu    $a2, $s3, $zero
/* DB414C 80241E8C 080907CA */  j         .L80241F28
/* DB4150 80241E90 0000102D */   daddu    $v0, $zero, $zero
glabel L80241E94_DB4154
/* DB4154 80241E94 0280202D */  daddu     $a0, $s4, $zero
/* DB4158 80241E98 0200282D */  daddu     $a1, $s0, $zero
/* DB415C 80241E9C 0C09048B */  jal       omo_05_UnkNpcAIFunc1
/* DB4160 80241EA0 0260302D */   daddu    $a2, $s3, $zero
glabel L80241EA4_DB4164
/* DB4164 80241EA4 0280202D */  daddu     $a0, $s4, $zero
/* DB4168 80241EA8 0200282D */  daddu     $a1, $s0, $zero
/* DB416C 80241EAC 0C0904BB */  jal       func_802412EC_DB35AC
/* DB4170 80241EB0 0260302D */   daddu    $a2, $s3, $zero
/* DB4174 80241EB4 080907CA */  j         .L80241F28
/* DB4178 80241EB8 0000102D */   daddu    $v0, $zero, $zero
glabel L80241EBC_DB417C
/* DB417C 80241EBC 0280202D */  daddu     $a0, $s4, $zero
/* DB4180 80241EC0 0200282D */  daddu     $a1, $s0, $zero
/* DB4184 80241EC4 0C09058C */  jal       omo_05_UnkNpcAIFunc2
/* DB4188 80241EC8 0260302D */   daddu    $a2, $s3, $zero
glabel L80241ECC_DB418C
/* DB418C 80241ECC 0280202D */  daddu     $a0, $s4, $zero
/* DB4190 80241ED0 0200282D */  daddu     $a1, $s0, $zero
/* DB4194 80241ED4 0C0905AA */  jal       func_802416A8_DB3968
/* DB4198 80241ED8 0260302D */   daddu    $a2, $s3, $zero
/* DB419C 80241EDC 080907CA */  j         .L80241F28
/* DB41A0 80241EE0 0000102D */   daddu    $v0, $zero, $zero
glabel L80241EE4_DB41A4
/* DB41A4 80241EE4 0280202D */  daddu     $a0, $s4, $zero
/* DB41A8 80241EE8 0200282D */  daddu     $a1, $s0, $zero
/* DB41AC 80241EEC 0C0905C5 */  jal       omo_05_UnkNpcAIFunc14
/* DB41B0 80241EF0 0260302D */   daddu    $a2, $s3, $zero
/* DB41B4 80241EF4 080907CA */  j         .L80241F28
/* DB41B8 80241EF8 0000102D */   daddu    $v0, $zero, $zero
glabel L80241EFC_DB41BC
/* DB41BC 80241EFC 0280202D */  daddu     $a0, $s4, $zero
/* DB41C0 80241F00 0200282D */  daddu     $a1, $s0, $zero
/* DB41C4 80241F04 0C090612 */  jal       omo_05_UnkNpcAIFunc3
/* DB41C8 80241F08 0260302D */   daddu    $a2, $s3, $zero
/* DB41CC 80241F0C 080907CA */  j         .L80241F28
/* DB41D0 80241F10 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F14_DB41D4
/* DB41D4 80241F14 0280202D */  daddu     $a0, $s4, $zero
/* DB41D8 80241F18 0200282D */  daddu     $a1, $s0, $zero
/* DB41DC 80241F1C 0C09062B */  jal       func_802418AC_DB3B6C
/* DB41E0 80241F20 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F24_DB41E4
/* DB41E4 80241F24 0000102D */  daddu     $v0, $zero, $zero
.L80241F28:
/* DB41E8 80241F28 8FBF0048 */  lw        $ra, 0x48($sp)
/* DB41EC 80241F2C 8FB50044 */  lw        $s5, 0x44($sp)
/* DB41F0 80241F30 8FB40040 */  lw        $s4, 0x40($sp)
/* DB41F4 80241F34 8FB3003C */  lw        $s3, 0x3c($sp)
/* DB41F8 80241F38 8FB20038 */  lw        $s2, 0x38($sp)
/* DB41FC 80241F3C 8FB10034 */  lw        $s1, 0x34($sp)
/* DB4200 80241F40 8FB00030 */  lw        $s0, 0x30($sp)
/* DB4204 80241F44 03E00008 */  jr        $ra
/* DB4208 80241F48 27BD0050 */   addiu    $sp, $sp, 0x50
