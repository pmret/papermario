.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802455F8_C76A78
.word L80241E68_C732E8, L80241E78_C732F8, L80241E90_C73310, L80241EA0_C73320, L80241F20_C733A0, L80241F20_C733A0, L80241F20_C733A0, L80241F20_C733A0, L80241F20_C733A0, L80241F20_C733A0, L80241EB8_C73338, L80241EC8_C73348, L80241EE0_C73360, L80241EF8_C73378, L80241F10_C73390, 0

.section .text

glabel func_80241D5C_C731DC
/* C731DC 80241D5C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C731E0 80241D60 AFB40040 */  sw        $s4, 0x40($sp)
/* C731E4 80241D64 0080A02D */  daddu     $s4, $a0, $zero
/* C731E8 80241D68 AFBF0048 */  sw        $ra, 0x48($sp)
/* C731EC 80241D6C AFB50044 */  sw        $s5, 0x44($sp)
/* C731F0 80241D70 AFB3003C */  sw        $s3, 0x3c($sp)
/* C731F4 80241D74 AFB20038 */  sw        $s2, 0x38($sp)
/* C731F8 80241D78 AFB10034 */  sw        $s1, 0x34($sp)
/* C731FC 80241D7C AFB00030 */  sw        $s0, 0x30($sp)
/* C73200 80241D80 8E920148 */  lw        $s2, 0x148($s4)
/* C73204 80241D84 86440008 */  lh        $a0, 8($s2)
/* C73208 80241D88 8E90000C */  lw        $s0, 0xc($s4)
/* C7320C 80241D8C 0C00EABB */  jal       get_npc_unsafe
/* C73210 80241D90 00A0882D */   daddu    $s1, $a1, $zero
/* C73214 80241D94 0280202D */  daddu     $a0, $s4, $zero
/* C73218 80241D98 8E050000 */  lw        $a1, ($s0)
/* C7321C 80241D9C 0C0B1EAF */  jal       get_variable
/* C73220 80241DA0 0040A82D */   daddu    $s5, $v0, $zero
/* C73224 80241DA4 AFA00010 */  sw        $zero, 0x10($sp)
/* C73228 80241DA8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C7322C 80241DAC 8C630030 */  lw        $v1, 0x30($v1)
/* C73230 80241DB0 AFA30014 */  sw        $v1, 0x14($sp)
/* C73234 80241DB4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C73238 80241DB8 8C63001C */  lw        $v1, 0x1c($v1)
/* C7323C 80241DBC AFA30018 */  sw        $v1, 0x18($sp)
/* C73240 80241DC0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C73244 80241DC4 8C630024 */  lw        $v1, 0x24($v1)
/* C73248 80241DC8 AFA3001C */  sw        $v1, 0x1c($sp)
/* C7324C 80241DCC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C73250 80241DD0 8C630028 */  lw        $v1, 0x28($v1)
/* C73254 80241DD4 27B30010 */  addiu     $s3, $sp, 0x10
/* C73258 80241DD8 AFA30020 */  sw        $v1, 0x20($sp)
/* C7325C 80241DDC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C73260 80241DE0 3C0142F0 */  lui       $at, 0x42f0
/* C73264 80241DE4 44810000 */  mtc1      $at, $f0
/* C73268 80241DE8 8C63002C */  lw        $v1, 0x2c($v1)
/* C7326C 80241DEC 0040802D */  daddu     $s0, $v0, $zero
/* C73270 80241DF0 E7A00028 */  swc1      $f0, 0x28($sp)
/* C73274 80241DF4 A7A0002C */  sh        $zero, 0x2c($sp)
/* C73278 80241DF8 12200006 */  beqz      $s1, .L80241E14
/* C7327C 80241DFC AFA30024 */   sw       $v1, 0x24($sp)
/* C73280 80241E00 02A0202D */  daddu     $a0, $s5, $zero
/* C73284 80241E04 0240282D */  daddu     $a1, $s2, $zero
/* C73288 80241E08 0280302D */  daddu     $a2, $s4, $zero
/* C7328C 80241E0C 0C09070E */  jal       kzn_08_UnkFunc5
/* C73290 80241E10 0200382D */   daddu    $a3, $s0, $zero
.L80241E14:
/* C73294 80241E14 2402FFFE */  addiu     $v0, $zero, -2
/* C73298 80241E18 A2A200AB */  sb        $v0, 0xab($s5)
/* C7329C 80241E1C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C732A0 80241E20 30620004 */  andi      $v0, $v1, 4
/* C732A4 80241E24 10400007 */  beqz      $v0, .L80241E44
/* C732A8 80241E28 00000000 */   nop
/* C732AC 80241E2C 824200B4 */  lb        $v0, 0xb4($s2)
/* C732B0 80241E30 1440003C */  bnez      $v0, .L80241F24
/* C732B4 80241E34 0000102D */   daddu    $v0, $zero, $zero
/* C732B8 80241E38 2402FFFB */  addiu     $v0, $zero, -5
/* C732BC 80241E3C 00621024 */  and       $v0, $v1, $v0
/* C732C0 80241E40 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241E44:
/* C732C4 80241E44 8E830070 */  lw        $v1, 0x70($s4)
/* C732C8 80241E48 2C62000F */  sltiu     $v0, $v1, 0xf
/* C732CC 80241E4C 10400034 */  beqz      $v0, L80241F20_C733A0
/* C732D0 80241E50 00031080 */   sll      $v0, $v1, 2
/* C732D4 80241E54 3C018024 */  lui       $at, %hi(jtbl_802455F8_C76A78)
/* C732D8 80241E58 00220821 */  addu      $at, $at, $v0
/* C732DC 80241E5C 8C2255F8 */  lw        $v0, %lo(jtbl_802455F8_C76A78)($at)
/* C732E0 80241E60 00400008 */  jr        $v0
/* C732E4 80241E64 00000000 */   nop
glabel L80241E68_C732E8
/* C732E8 80241E68 0280202D */  daddu     $a0, $s4, $zero
/* C732EC 80241E6C 0200282D */  daddu     $a1, $s0, $zero
/* C732F0 80241E70 0C090294 */  jal       func_80240A50_C71ED0
/* C732F4 80241E74 0260302D */   daddu    $a2, $s3, $zero
glabel L80241E78_C732F8
/* C732F8 80241E78 0280202D */  daddu     $a0, $s4, $zero
/* C732FC 80241E7C 0200282D */  daddu     $a1, $s0, $zero
/* C73300 80241E80 0C090300 */  jal       func_80240C00_C72080
/* C73304 80241E84 0260302D */   daddu    $a2, $s3, $zero
/* C73308 80241E88 080907C9 */  j         .L80241F24
/* C7330C 80241E8C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241E90_C73310
/* C73310 80241E90 0280202D */  daddu     $a0, $s4, $zero
/* C73314 80241E94 0200282D */  daddu     $a1, $s0, $zero
/* C73318 80241E98 0C09048A */  jal       kzn_08_UnkNpcAIFunc1
/* C7331C 80241E9C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241EA0_C73320
/* C73320 80241EA0 0280202D */  daddu     $a0, $s4, $zero
/* C73324 80241EA4 0200282D */  daddu     $a1, $s0, $zero
/* C73328 80241EA8 0C0904BA */  jal       kzn_08_UnkFunc4
/* C7332C 80241EAC 0260302D */   daddu    $a2, $s3, $zero
/* C73330 80241EB0 080907C9 */  j         .L80241F24
/* C73334 80241EB4 0000102D */   daddu    $v0, $zero, $zero
glabel L80241EB8_C73338
/* C73338 80241EB8 0280202D */  daddu     $a0, $s4, $zero
/* C7333C 80241EBC 0200282D */  daddu     $a1, $s0, $zero
/* C73340 80241EC0 0C09058B */  jal       kzn_08_UnkNpcAIFunc2
/* C73344 80241EC4 0260302D */   daddu    $a2, $s3, $zero
glabel L80241EC8_C73348
/* C73348 80241EC8 0280202D */  daddu     $a0, $s4, $zero
/* C7334C 80241ECC 0200282D */  daddu     $a1, $s0, $zero
/* C73350 80241ED0 0C0905A9 */  jal       func_802416A4_C72B24
/* C73354 80241ED4 0260302D */   daddu    $a2, $s3, $zero
/* C73358 80241ED8 080907C9 */  j         .L80241F24
/* C7335C 80241EDC 0000102D */   daddu    $v0, $zero, $zero
glabel L80241EE0_C73360
/* C73360 80241EE0 0280202D */  daddu     $a0, $s4, $zero
/* C73364 80241EE4 0200282D */  daddu     $a1, $s0, $zero
/* C73368 80241EE8 0C0905C4 */  jal       kzn_08_UnkNpcAIFunc14
/* C7336C 80241EEC 0260302D */   daddu    $a2, $s3, $zero
/* C73370 80241EF0 080907C9 */  j         .L80241F24
/* C73374 80241EF4 0000102D */   daddu    $v0, $zero, $zero
glabel L80241EF8_C73378
/* C73378 80241EF8 0280202D */  daddu     $a0, $s4, $zero
/* C7337C 80241EFC 0200282D */  daddu     $a1, $s0, $zero
/* C73380 80241F00 0C090611 */  jal       kzn_08_UnkNpcAIFunc3
/* C73384 80241F04 0260302D */   daddu    $a2, $s3, $zero
/* C73388 80241F08 080907C9 */  j         .L80241F24
/* C7338C 80241F0C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F10_C73390
/* C73390 80241F10 0280202D */  daddu     $a0, $s4, $zero
/* C73394 80241F14 0200282D */  daddu     $a1, $s0, $zero
/* C73398 80241F18 0C09062A */  jal       kzn_08_UnkFunc6
/* C7339C 80241F1C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F20_C733A0
/* C733A0 80241F20 0000102D */  daddu     $v0, $zero, $zero
.L80241F24:
/* C733A4 80241F24 8FBF0048 */  lw        $ra, 0x48($sp)
/* C733A8 80241F28 8FB50044 */  lw        $s5, 0x44($sp)
/* C733AC 80241F2C 8FB40040 */  lw        $s4, 0x40($sp)
/* C733B0 80241F30 8FB3003C */  lw        $s3, 0x3c($sp)
/* C733B4 80241F34 8FB20038 */  lw        $s2, 0x38($sp)
/* C733B8 80241F38 8FB10034 */  lw        $s1, 0x34($sp)
/* C733BC 80241F3C 8FB00030 */  lw        $s0, 0x30($sp)
/* C733C0 80241F40 03E00008 */  jr        $ra
/* C733C4 80241F44 27BD0050 */   addiu    $sp, $sp, 0x50
