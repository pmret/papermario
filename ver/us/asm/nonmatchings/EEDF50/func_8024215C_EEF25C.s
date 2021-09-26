.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80245468_EF2568
.word L80242294_EEF394, L802422A4_EEF3A4, L802422BC_EEF3BC, L802422CC_EEF3CC, L8024234C_EEF44C, L8024234C_EEF44C, L8024234C_EEF44C, L8024234C_EEF44C, L8024234C_EEF44C, L8024234C_EEF44C, L802422E4_EEF3E4, L802422F4_EEF3F4, L8024230C_EEF40C, L80242324_EEF424, L8024233C_EEF43C, 0

.section .text

glabel func_8024215C_EEF25C
/* EEF25C 8024215C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EEF260 80242160 AFB50044 */  sw        $s5, 0x44($sp)
/* EEF264 80242164 0080A82D */  daddu     $s5, $a0, $zero
/* EEF268 80242168 AFBF0048 */  sw        $ra, 0x48($sp)
/* EEF26C 8024216C AFB40040 */  sw        $s4, 0x40($sp)
/* EEF270 80242170 AFB3003C */  sw        $s3, 0x3c($sp)
/* EEF274 80242174 AFB20038 */  sw        $s2, 0x38($sp)
/* EEF278 80242178 AFB10034 */  sw        $s1, 0x34($sp)
/* EEF27C 8024217C AFB00030 */  sw        $s0, 0x30($sp)
/* EEF280 80242180 8EB20148 */  lw        $s2, 0x148($s5)
/* EEF284 80242184 86440008 */  lh        $a0, 8($s2)
/* EEF288 80242188 8EB0000C */  lw        $s0, 0xc($s5)
/* EEF28C 8024218C 0C00F92F */  jal       dead_get_npc_unsafe
/* EEF290 80242190 00A0882D */   daddu    $s1, $a1, $zero
/* EEF294 80242194 02A0202D */  daddu     $a0, $s5, $zero
/* EEF298 80242198 8E050000 */  lw        $a1, ($s0)
/* EEF29C 8024219C 0C0B53A3 */  jal       dead_evt_get_variable
/* EEF2A0 802421A0 0040A02D */   daddu    $s4, $v0, $zero
/* EEF2A4 802421A4 AFA00010 */  sw        $zero, 0x10($sp)
/* EEF2A8 802421A8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF2AC 802421AC 8C630030 */  lw        $v1, 0x30($v1)
/* EEF2B0 802421B0 AFA30014 */  sw        $v1, 0x14($sp)
/* EEF2B4 802421B4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF2B8 802421B8 8C63001C */  lw        $v1, 0x1c($v1)
/* EEF2BC 802421BC AFA30018 */  sw        $v1, 0x18($sp)
/* EEF2C0 802421C0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF2C4 802421C4 8C630024 */  lw        $v1, 0x24($v1)
/* EEF2C8 802421C8 AFA3001C */  sw        $v1, 0x1c($sp)
/* EEF2CC 802421CC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF2D0 802421D0 8C630028 */  lw        $v1, 0x28($v1)
/* EEF2D4 802421D4 AFA30020 */  sw        $v1, 0x20($sp)
/* EEF2D8 802421D8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF2DC 802421DC 3C0142F0 */  lui       $at, 0x42f0
/* EEF2E0 802421E0 44810000 */  mtc1      $at, $f0
/* EEF2E4 802421E4 8C63002C */  lw        $v1, 0x2c($v1)
/* EEF2E8 802421E8 E7A00028 */  swc1      $f0, 0x28($sp)
/* EEF2EC 802421EC A7A0002C */  sh        $zero, 0x2c($sp)
/* EEF2F0 802421F0 AFA30024 */  sw        $v1, 0x24($sp)
/* EEF2F4 802421F4 C6800038 */  lwc1      $f0, 0x38($s4)
/* EEF2F8 802421F8 E6400108 */  swc1      $f0, 0x108($s2)
/* EEF2FC 802421FC C680003C */  lwc1      $f0, 0x3c($s4)
/* EEF300 80242200 27B30010 */  addiu     $s3, $sp, 0x10
/* EEF304 80242204 E640010C */  swc1      $f0, 0x10c($s2)
/* EEF308 80242208 3C0138D1 */  lui       $at, 0x38d1
/* EEF30C 8024220C 3421B717 */  ori       $at, $at, 0xb717
/* EEF310 80242210 44810000 */  mtc1      $at, $f0
/* EEF314 80242214 C6820040 */  lwc1      $f2, 0x40($s4)
/* EEF318 80242218 0040802D */  daddu     $s0, $v0, $zero
/* EEF31C 8024221C E6400114 */  swc1      $f0, 0x114($s2)
/* EEF320 80242220 E6400118 */  swc1      $f0, 0x118($s2)
/* EEF324 80242224 12200006 */  beqz      $s1, .L80242240
/* EEF328 80242228 E6420110 */   swc1     $f2, 0x110($s2)
/* EEF32C 8024222C 0280202D */  daddu     $a0, $s4, $zero
/* EEF330 80242230 0240282D */  daddu     $a1, $s2, $zero
/* EEF334 80242234 02A0302D */  daddu     $a2, $s5, $zero
/* EEF338 80242238 0C09080E */  jal       EEDF50_UnkFunc5
/* EEF33C 8024223C 0200382D */   daddu    $a3, $s0, $zero
.L80242240:
/* EEF340 80242240 2402FFFE */  addiu     $v0, $zero, -2
/* EEF344 80242244 A28200AB */  sb        $v0, 0xab($s4)
/* EEF348 80242248 8E4300B0 */  lw        $v1, 0xb0($s2)
/* EEF34C 8024224C 30620004 */  andi      $v0, $v1, 4
/* EEF350 80242250 10400007 */  beqz      $v0, .L80242270
/* EEF354 80242254 00000000 */   nop
/* EEF358 80242258 824200B4 */  lb        $v0, 0xb4($s2)
/* EEF35C 8024225C 1440003C */  bnez      $v0, .L80242350
/* EEF360 80242260 0000102D */   daddu    $v0, $zero, $zero
/* EEF364 80242264 2402FFFB */  addiu     $v0, $zero, -5
/* EEF368 80242268 00621024 */  and       $v0, $v1, $v0
/* EEF36C 8024226C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242270:
/* EEF370 80242270 8EA30070 */  lw        $v1, 0x70($s5)
/* EEF374 80242274 2C62000F */  sltiu     $v0, $v1, 0xf
/* EEF378 80242278 10400034 */  beqz      $v0, L8024234C_EEF44C
/* EEF37C 8024227C 00031080 */   sll      $v0, $v1, 2
/* EEF380 80242280 3C018024 */  lui       $at, %hi(jtbl_80245468_EF2568)
/* EEF384 80242284 00220821 */  addu      $at, $at, $v0
/* EEF388 80242288 8C225468 */  lw        $v0, %lo(jtbl_80245468_EF2568)($at)
/* EEF38C 8024228C 00400008 */  jr        $v0
/* EEF390 80242290 00000000 */   nop
glabel L80242294_EEF394
/* EEF394 80242294 02A0202D */  daddu     $a0, $s5, $zero
/* EEF398 80242298 0200282D */  daddu     $a1, $s0, $zero
/* EEF39C 8024229C 0C090394 */  jal       EEDF50_UnkNpcAIFunc23
/* EEF3A0 802422A0 0260302D */   daddu    $a2, $s3, $zero
glabel L802422A4_EEF3A4
/* EEF3A4 802422A4 02A0202D */  daddu     $a0, $s5, $zero
/* EEF3A8 802422A8 0200282D */  daddu     $a1, $s0, $zero
/* EEF3AC 802422AC 0C090400 */  jal       func_80241000_EEE100
/* EEF3B0 802422B0 0260302D */   daddu    $a2, $s3, $zero
/* EEF3B4 802422B4 080908D4 */  j         .L80242350
/* EEF3B8 802422B8 0000102D */   daddu    $v0, $zero, $zero
glabel L802422BC_EEF3BC
/* EEF3BC 802422BC 02A0202D */  daddu     $a0, $s5, $zero
/* EEF3C0 802422C0 0200282D */  daddu     $a1, $s0, $zero
/* EEF3C4 802422C4 0C09058A */  jal       EEDF50_DeadUnkNpcAIFunc1
/* EEF3C8 802422C8 0260302D */   daddu    $a2, $s3, $zero
glabel L802422CC_EEF3CC
/* EEF3CC 802422CC 02A0202D */  daddu     $a0, $s5, $zero
/* EEF3D0 802422D0 0200282D */  daddu     $a1, $s0, $zero
/* EEF3D4 802422D4 0C0905BA */  jal       EEDF50_UnkFunc4
/* EEF3D8 802422D8 0260302D */   daddu    $a2, $s3, $zero
/* EEF3DC 802422DC 080908D4 */  j         .L80242350
/* EEF3E0 802422E0 0000102D */   daddu    $v0, $zero, $zero
glabel L802422E4_EEF3E4
/* EEF3E4 802422E4 02A0202D */  daddu     $a0, $s5, $zero
/* EEF3E8 802422E8 0200282D */  daddu     $a1, $s0, $zero
/* EEF3EC 802422EC 0C09068B */  jal       EEDF50_UnkNpcAIFunc2
/* EEF3F0 802422F0 0260302D */   daddu    $a2, $s3, $zero
glabel L802422F4_EEF3F4
/* EEF3F4 802422F4 02A0202D */  daddu     $a0, $s5, $zero
/* EEF3F8 802422F8 0200282D */  daddu     $a1, $s0, $zero
/* EEF3FC 802422FC 0C0906A9 */  jal       func_80241AA4_EEEBA4
/* EEF400 80242300 0260302D */   daddu    $a2, $s3, $zero
/* EEF404 80242304 080908D4 */  j         .L80242350
/* EEF408 80242308 0000102D */   daddu    $v0, $zero, $zero
glabel L8024230C_EEF40C
/* EEF40C 8024230C 02A0202D */  daddu     $a0, $s5, $zero
/* EEF410 80242310 0200282D */  daddu     $a1, $s0, $zero
/* EEF414 80242314 0C0906C4 */  jal       EEDF50_DeadUnkNpcAIFunc14
/* EEF418 80242318 0260302D */   daddu    $a2, $s3, $zero
/* EEF41C 8024231C 080908D4 */  j         .L80242350
/* EEF420 80242320 0000102D */   daddu    $v0, $zero, $zero
glabel L80242324_EEF424
/* EEF424 80242324 02A0202D */  daddu     $a0, $s5, $zero
/* EEF428 80242328 0200282D */  daddu     $a1, $s0, $zero
/* EEF42C 8024232C 0C090711 */  jal       EEDF50_UnkNpcAIFunc3
/* EEF430 80242330 0260302D */   daddu    $a2, $s3, $zero
/* EEF434 80242334 080908D4 */  j         .L80242350
/* EEF438 80242338 0000102D */   daddu    $v0, $zero, $zero
glabel L8024233C_EEF43C
/* EEF43C 8024233C 02A0202D */  daddu     $a0, $s5, $zero
/* EEF440 80242340 0200282D */  daddu     $a1, $s0, $zero
/* EEF444 80242344 0C09072A */  jal       EEDF50_UnkFunc6
/* EEF448 80242348 0260302D */   daddu    $a2, $s3, $zero
glabel L8024234C_EEF44C
/* EEF44C 8024234C 0000102D */  daddu     $v0, $zero, $zero
.L80242350:
/* EEF450 80242350 8FBF0048 */  lw        $ra, 0x48($sp)
/* EEF454 80242354 8FB50044 */  lw        $s5, 0x44($sp)
/* EEF458 80242358 8FB40040 */  lw        $s4, 0x40($sp)
/* EEF45C 8024235C 8FB3003C */  lw        $s3, 0x3c($sp)
/* EEF460 80242360 8FB20038 */  lw        $s2, 0x38($sp)
/* EEF464 80242364 8FB10034 */  lw        $s1, 0x34($sp)
/* EEF468 80242368 8FB00030 */  lw        $s0, 0x30($sp)
/* EEF46C 8024236C 03E00008 */  jr        $ra
/* EEF470 80242370 27BD0050 */   addiu    $sp, $sp, 0x50
