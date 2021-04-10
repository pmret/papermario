.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D64_C81F04
/* C81F04 80241D64 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C81F08 80241D68 AFB40040 */  sw        $s4, 0x40($sp)
/* C81F0C 80241D6C 0080A02D */  daddu     $s4, $a0, $zero
/* C81F10 80241D70 AFBF0048 */  sw        $ra, 0x48($sp)
/* C81F14 80241D74 AFB50044 */  sw        $s5, 0x44($sp)
/* C81F18 80241D78 AFB3003C */  sw        $s3, 0x3c($sp)
/* C81F1C 80241D7C AFB20038 */  sw        $s2, 0x38($sp)
/* C81F20 80241D80 AFB10034 */  sw        $s1, 0x34($sp)
/* C81F24 80241D84 AFB00030 */  sw        $s0, 0x30($sp)
/* C81F28 80241D88 8E920148 */  lw        $s2, 0x148($s4)
/* C81F2C 80241D8C 86440008 */  lh        $a0, 8($s2)
/* C81F30 80241D90 8E90000C */  lw        $s0, 0xc($s4)
/* C81F34 80241D94 0C00EABB */  jal       get_npc_unsafe
/* C81F38 80241D98 00A0882D */   daddu    $s1, $a1, $zero
/* C81F3C 80241D9C 0280202D */  daddu     $a0, $s4, $zero
/* C81F40 80241DA0 8E050000 */  lw        $a1, ($s0)
/* C81F44 80241DA4 0C0B1EAF */  jal       get_variable
/* C81F48 80241DA8 0040A82D */   daddu    $s5, $v0, $zero
/* C81F4C 80241DAC AFA00010 */  sw        $zero, 0x10($sp)
/* C81F50 80241DB0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81F54 80241DB4 8C630030 */  lw        $v1, 0x30($v1)
/* C81F58 80241DB8 AFA30014 */  sw        $v1, 0x14($sp)
/* C81F5C 80241DBC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81F60 80241DC0 8C63001C */  lw        $v1, 0x1c($v1)
/* C81F64 80241DC4 AFA30018 */  sw        $v1, 0x18($sp)
/* C81F68 80241DC8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81F6C 80241DCC 8C630024 */  lw        $v1, 0x24($v1)
/* C81F70 80241DD0 AFA3001C */  sw        $v1, 0x1c($sp)
/* C81F74 80241DD4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81F78 80241DD8 8C630028 */  lw        $v1, 0x28($v1)
/* C81F7C 80241DDC 27B30010 */  addiu     $s3, $sp, 0x10
/* C81F80 80241DE0 AFA30020 */  sw        $v1, 0x20($sp)
/* C81F84 80241DE4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81F88 80241DE8 3C0142F0 */  lui       $at, 0x42f0
/* C81F8C 80241DEC 44810000 */  mtc1      $at, $f0
/* C81F90 80241DF0 8C63002C */  lw        $v1, 0x2c($v1)
/* C81F94 80241DF4 0040802D */  daddu     $s0, $v0, $zero
/* C81F98 80241DF8 E7A00028 */  swc1      $f0, 0x28($sp)
/* C81F9C 80241DFC A7A0002C */  sh        $zero, 0x2c($sp)
/* C81FA0 80241E00 12200007 */  beqz      $s1, .L80241E20
/* C81FA4 80241E04 AFA30024 */   sw       $v1, 0x24($sp)
/* C81FA8 80241E08 02A0202D */  daddu     $a0, $s5, $zero
/* C81FAC 80241E0C 0240282D */  daddu     $a1, $s2, $zero
/* C81FB0 80241E10 0280302D */  daddu     $a2, $s4, $zero
/* C81FB4 80241E14 0C090592 */  jal       kzn_11_UnkFunc5
/* C81FB8 80241E18 0200382D */   daddu    $a3, $s0, $zero
/* C81FBC 80241E1C AE800070 */  sw        $zero, 0x70($s4)
.L80241E20:
/* C81FC0 80241E20 2402FFFE */  addiu     $v0, $zero, -2
/* C81FC4 80241E24 A2A200AB */  sb        $v0, 0xab($s5)
/* C81FC8 80241E28 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C81FCC 80241E2C 30620004 */  andi      $v0, $v1, 4
/* C81FD0 80241E30 10400007 */  beqz      $v0, .L80241E50
/* C81FD4 80241E34 00000000 */   nop
/* C81FD8 80241E38 824200B4 */  lb        $v0, 0xb4($s2)
/* C81FDC 80241E3C 1440003A */  bnez      $v0, .L80241F28
/* C81FE0 80241E40 0000102D */   daddu    $v0, $zero, $zero
/* C81FE4 80241E44 2402FFFB */  addiu     $v0, $zero, -5
/* C81FE8 80241E48 00621024 */  and       $v0, $v1, $v0
/* C81FEC 80241E4C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241E50:
/* C81FF0 80241E50 8E830070 */  lw        $v1, 0x70($s4)
/* C81FF4 80241E54 2C620015 */  sltiu     $v0, $v1, 0x15
/* C81FF8 80241E58 10400032 */  beqz      $v0, L80241F24_C820C4
/* C81FFC 80241E5C 00031080 */   sll      $v0, $v1, 2
/* C82000 80241E60 3C018024 */  lui       $at, %hi(jtbl_802458B0_C85A50)
/* C82004 80241E64 00220821 */  addu      $at, $at, $v0
/* C82008 80241E68 8C2258B0 */  lw        $v0, %lo(jtbl_802458B0_C85A50)($at)
/* C8200C 80241E6C 00400008 */  jr        $v0
/* C82010 80241E70 00000000 */   nop
glabel L80241E74_C82014
/* C82014 80241E74 0280202D */  daddu     $a0, $s4, $zero
/* C82018 80241E78 0200282D */  daddu     $a1, $s0, $zero
/* C8201C 80241E7C 0C090118 */  jal       func_80240460_C80600
/* C82020 80241E80 0260302D */   daddu    $a2, $s3, $zero
glabel L80241E84_C82024
/* C82024 80241E84 0280202D */  daddu     $a0, $s4, $zero
/* C82028 80241E88 0200282D */  daddu     $a1, $s0, $zero
/* C8202C 80241E8C 0C090184 */  jal       func_80240610_C807B0
/* C82030 80241E90 0260302D */   daddu    $a2, $s3, $zero
/* C82034 80241E94 080907CA */  j         .L80241F28
/* C82038 80241E98 0000102D */   daddu    $v0, $zero, $zero
glabel L80241E9C_C8203C
/* C8203C 80241E9C 0280202D */  daddu     $a0, $s4, $zero
/* C82040 80241EA0 0200282D */  daddu     $a1, $s0, $zero
/* C82044 80241EA4 0C09030E */  jal       kzn_11_UnkNpcAIFunc1
/* C82048 80241EA8 0260302D */   daddu    $a2, $s3, $zero
glabel L80241EAC_C8204C
/* C8204C 80241EAC 0280202D */  daddu     $a0, $s4, $zero
/* C82050 80241EB0 0200282D */  daddu     $a1, $s0, $zero
/* C82054 80241EB4 0C09033E */  jal       kzn_11_UnkFunc4
/* C82058 80241EB8 0260302D */   daddu    $a2, $s3, $zero
/* C8205C 80241EBC 080907CA */  j         .L80241F28
/* C82060 80241EC0 0000102D */   daddu    $v0, $zero, $zero
glabel L80241EC4_C82064
/* C82064 80241EC4 0280202D */  daddu     $a0, $s4, $zero
/* C82068 80241EC8 0200282D */  daddu     $a1, $s0, $zero
/* C8206C 80241ECC 0C09040F */  jal       kzn_11_UnkNpcAIFunc2
/* C82070 80241ED0 0260302D */   daddu    $a2, $s3, $zero
glabel L80241ED4_C82074
/* C82074 80241ED4 0280202D */  daddu     $a0, $s4, $zero
/* C82078 80241ED8 0200282D */  daddu     $a1, $s0, $zero
/* C8207C 80241EDC 0C09042D */  jal       func_802410B4_C81254
/* C82080 80241EE0 0260302D */   daddu    $a2, $s3, $zero
/* C82084 80241EE4 080907CA */  j         .L80241F28
/* C82088 80241EE8 0000102D */   daddu    $v0, $zero, $zero
glabel L80241EEC_C8208C
/* C8208C 80241EEC 0280202D */  daddu     $a0, $s4, $zero
/* C82090 80241EF0 0200282D */  daddu     $a1, $s0, $zero
/* C82094 80241EF4 0C090656 */  jal       kzn_11_UnkNpcAIFunc13
/* C82098 80241EF8 0260302D */   daddu    $a2, $s3, $zero
glabel L80241EFC_C8209C
/* C8209C 80241EFC 0280202D */  daddu     $a0, $s4, $zero
/* C820A0 80241F00 0200282D */  daddu     $a1, $s0, $zero
/* C820A4 80241F04 0C0906A2 */  jal       func_80241A88_C81C28
/* C820A8 80241F08 0260302D */   daddu    $a2, $s3, $zero
/* C820AC 80241F0C 080907CA */  j         .L80241F28
/* C820B0 80241F10 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F14_C820B4
/* C820B4 80241F14 0280202D */  daddu     $a0, $s4, $zero
/* C820B8 80241F18 0200282D */  daddu     $a1, $s0, $zero
/* C820BC 80241F1C 0C090742 */  jal       func_80241D08_C81EA8
/* C820C0 80241F20 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F24_C820C4
/* C820C4 80241F24 0000102D */  daddu     $v0, $zero, $zero
.L80241F28:
/* C820C8 80241F28 8FBF0048 */  lw        $ra, 0x48($sp)
/* C820CC 80241F2C 8FB50044 */  lw        $s5, 0x44($sp)
/* C820D0 80241F30 8FB40040 */  lw        $s4, 0x40($sp)
/* C820D4 80241F34 8FB3003C */  lw        $s3, 0x3c($sp)
/* C820D8 80241F38 8FB20038 */  lw        $s2, 0x38($sp)
/* C820DC 80241F3C 8FB10034 */  lw        $s1, 0x34($sp)
/* C820E0 80241F40 8FB00030 */  lw        $s0, 0x30($sp)
/* C820E4 80241F44 03E00008 */  jr        $ra
/* C820E8 80241F48 27BD0050 */   addiu    $sp, $sp, 0x50
