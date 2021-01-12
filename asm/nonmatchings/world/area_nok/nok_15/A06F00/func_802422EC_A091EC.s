.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422EC_A091EC
/* A091EC 802422EC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A091F0 802422F0 AFB3003C */  sw        $s3, 0x3c($sp)
/* A091F4 802422F4 0080982D */  daddu     $s3, $a0, $zero
/* A091F8 802422F8 AFBF0048 */  sw        $ra, 0x48($sp)
/* A091FC 802422FC AFB50044 */  sw        $s5, 0x44($sp)
/* A09200 80242300 AFB40040 */  sw        $s4, 0x40($sp)
/* A09204 80242304 AFB20038 */  sw        $s2, 0x38($sp)
/* A09208 80242308 AFB10034 */  sw        $s1, 0x34($sp)
/* A0920C 8024230C AFB00030 */  sw        $s0, 0x30($sp)
/* A09210 80242310 8E720148 */  lw        $s2, 0x148($s3)
/* A09214 80242314 86440008 */  lh        $a0, 8($s2)
/* A09218 80242318 8E70000C */  lw        $s0, 0xc($s3)
/* A0921C 8024231C 0C00EABB */  jal       get_npc_unsafe
/* A09220 80242320 00A0882D */   daddu    $s1, $a1, $zero
/* A09224 80242324 0260202D */  daddu     $a0, $s3, $zero
/* A09228 80242328 8E050000 */  lw        $a1, ($s0)
/* A0922C 8024232C 0C0B1EAF */  jal       get_variable
/* A09230 80242330 0040A82D */   daddu    $s5, $v0, $zero
/* A09234 80242334 AFA00010 */  sw        $zero, 0x10($sp)
/* A09238 80242338 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A0923C 8024233C 8C630030 */  lw        $v1, 0x30($v1)
/* A09240 80242340 AFA30014 */  sw        $v1, 0x14($sp)
/* A09244 80242344 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A09248 80242348 8C63001C */  lw        $v1, 0x1c($v1)
/* A0924C 8024234C AFA30018 */  sw        $v1, 0x18($sp)
/* A09250 80242350 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A09254 80242354 8C630024 */  lw        $v1, 0x24($v1)
/* A09258 80242358 AFA3001C */  sw        $v1, 0x1c($sp)
/* A0925C 8024235C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A09260 80242360 8C630028 */  lw        $v1, 0x28($v1)
/* A09264 80242364 27B40010 */  addiu     $s4, $sp, 0x10
/* A09268 80242368 AFA30020 */  sw        $v1, 0x20($sp)
/* A0926C 8024236C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A09270 80242370 3C0142F0 */  lui       $at, 0x42f0
/* A09274 80242374 44810000 */  mtc1      $at, $f0
/* A09278 80242378 8C63002C */  lw        $v1, 0x2c($v1)
/* A0927C 8024237C 0040802D */  daddu     $s0, $v0, $zero
/* A09280 80242380 E7A00028 */  swc1      $f0, 0x28($sp)
/* A09284 80242384 A7A0002C */  sh        $zero, 0x2c($sp)
/* A09288 80242388 12200009 */  beqz      $s1, .L802423B0
/* A0928C 8024238C AFA30024 */   sw       $v1, 0x24($sp)
/* A09290 80242390 02A0202D */  daddu     $a0, $s5, $zero
/* A09294 80242394 0240282D */  daddu     $a1, $s2, $zero
/* A09298 80242398 0260302D */  daddu     $a2, $s3, $zero
/* A0929C 8024239C 0C090727 */  jal       func_80241C9C_A08B9C
/* A092A0 802423A0 0200382D */   daddu    $a3, $s0, $zero
/* A092A4 802423A4 86A200A8 */  lh        $v0, 0xa8($s5)
/* A092A8 802423A8 AE42008C */  sw        $v0, 0x8c($s2)
/* A092AC 802423AC AE600070 */  sw        $zero, 0x70($s3)
.L802423B0:
/* A092B0 802423B0 2402FFFD */  addiu     $v0, $zero, -3
/* A092B4 802423B4 A2A200AB */  sb        $v0, 0xab($s5)
/* A092B8 802423B8 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A092BC 802423BC 30620004 */  andi      $v0, $v1, 4
/* A092C0 802423C0 10400007 */  beqz      $v0, .L802423E0
/* A092C4 802423C4 00000000 */   nop
/* A092C8 802423C8 824200B4 */  lb        $v0, 0xb4($s2)
/* A092CC 802423CC 14400052 */  bnez      $v0, .L80242518
/* A092D0 802423D0 0000102D */   daddu    $v0, $zero, $zero
/* A092D4 802423D4 2402FFFB */  addiu     $v0, $zero, -5
/* A092D8 802423D8 00621024 */  and       $v0, $v1, $v0
/* A092DC 802423DC AE4200B0 */  sw        $v0, 0xb0($s2)
.L802423E0:
/* A092E0 802423E0 8E630070 */  lw        $v1, 0x70($s3)
/* A092E4 802423E4 2C620010 */  sltiu     $v0, $v1, 0x10
/* A092E8 802423E8 1040004A */  beqz      $v0, .L80242514
/* A092EC 802423EC 00031080 */   sll      $v0, $v1, 2
/* A092F0 802423F0 3C018024 */  lui       $at, %hi(jtbl_80244DA8_A0BCA8)
/* A092F4 802423F4 00220821 */  addu      $at, $at, $v0
/* A092F8 802423F8 8C224DA8 */  lw        $v0, %lo(jtbl_80244DA8_A0BCA8)($at)
/* A092FC 802423FC 00400008 */  jr        $v0
/* A09300 80242400 00000000 */   nop
glabel L80242404_A09304
/* A09304 80242404 0260202D */  daddu     $a0, $s3, $zero
/* A09308 80242408 0200282D */  daddu     $a1, $s0, $zero
/* A0930C 8024240C 0C0902AD */  jal       func_80240AB4_A079B4
/* A09310 80242410 0280302D */   daddu    $a2, $s4, $zero
glabel L80242414_A09314
/* A09314 80242414 0260202D */  daddu     $a0, $s3, $zero
/* A09318 80242418 0200282D */  daddu     $a1, $s0, $zero
/* A0931C 8024241C 0C090319 */  jal       func_80240C64_A07B64
/* A09320 80242420 0280302D */   daddu    $a2, $s4, $zero
/* A09324 80242424 8E630070 */  lw        $v1, 0x70($s3)
/* A09328 80242428 24020002 */  addiu     $v0, $zero, 2
/* A0932C 8024242C 1462003A */  bne       $v1, $v0, .L80242518
/* A09330 80242430 0000102D */   daddu    $v0, $zero, $zero
glabel L80242434_A09334
/* A09334 80242434 0260202D */  daddu     $a0, $s3, $zero
/* A09338 80242438 0200282D */  daddu     $a1, $s0, $zero
/* A0933C 8024243C 0C0904A3 */  jal       nok_15_UnkNpcAIFunc1
/* A09340 80242440 0280302D */   daddu    $a2, $s4, $zero
glabel L80242444_A09344
/* A09344 80242444 0260202D */  daddu     $a0, $s3, $zero
/* A09348 80242448 0200282D */  daddu     $a1, $s0, $zero
/* A0934C 8024244C 0C0904D3 */  jal       func_8024134C_A0824C
/* A09350 80242450 0280302D */   daddu    $a2, $s4, $zero
/* A09354 80242454 8E630070 */  lw        $v1, 0x70($s3)
/* A09358 80242458 2402000A */  addiu     $v0, $zero, 0xa
/* A0935C 8024245C 1462002E */  bne       $v1, $v0, .L80242518
/* A09360 80242460 0000102D */   daddu    $v0, $zero, $zero
glabel L80242464_A09364
/* A09364 80242464 0260202D */  daddu     $a0, $s3, $zero
/* A09368 80242468 0200282D */  daddu     $a1, $s0, $zero
/* A0936C 8024246C 0C0905A4 */  jal       func_80241690_A08590
/* A09370 80242470 0280302D */   daddu    $a2, $s4, $zero
/* A09374 80242474 8E630070 */  lw        $v1, 0x70($s3)
/* A09378 80242478 2402000B */  addiu     $v0, $zero, 0xb
/* A0937C 8024247C 14620026 */  bne       $v1, $v0, .L80242518
/* A09380 80242480 0000102D */   daddu    $v0, $zero, $zero
glabel L80242484_A09384
/* A09384 80242484 0260202D */  daddu     $a0, $s3, $zero
/* A09388 80242488 0200282D */  daddu     $a1, $s0, $zero
/* A0938C 8024248C 0C0905C2 */  jal       func_80241708_A08608
/* A09390 80242490 0280302D */   daddu    $a2, $s4, $zero
/* A09394 80242494 8E630070 */  lw        $v1, 0x70($s3)
/* A09398 80242498 2402000C */  addiu     $v0, $zero, 0xc
/* A0939C 8024249C 1462001E */  bne       $v1, $v0, .L80242518
/* A093A0 802424A0 0000102D */   daddu    $v0, $zero, $zero
glabel L802424A4_A093A4
/* A093A4 802424A4 0260202D */  daddu     $a0, $s3, $zero
/* A093A8 802424A8 0200282D */  daddu     $a1, $s0, $zero
/* A093AC 802424AC 0C0907EB */  jal       func_80241FAC_A08EAC
/* A093B0 802424B0 0280302D */   daddu    $a2, $s4, $zero
/* A093B4 802424B4 8E630070 */  lw        $v1, 0x70($s3)
/* A093B8 802424B8 2402000D */  addiu     $v0, $zero, 0xd
/* A093BC 802424BC 14620016 */  bne       $v1, $v0, .L80242518
/* A093C0 802424C0 0000102D */   daddu    $v0, $zero, $zero
glabel L802424C4_A093C4
/* A093C4 802424C4 0260202D */  daddu     $a0, $s3, $zero
/* A093C8 802424C8 0200282D */  daddu     $a1, $s0, $zero
/* A093CC 802424CC 0C090835 */  jal       func_802420D4_A08FD4
/* A093D0 802424D0 0280302D */   daddu    $a2, $s4, $zero
/* A093D4 802424D4 8E630070 */  lw        $v1, 0x70($s3)
/* A093D8 802424D8 2402000E */  addiu     $v0, $zero, 0xe
/* A093DC 802424DC 1462000E */  bne       $v1, $v0, .L80242518
/* A093E0 802424E0 0000102D */   daddu    $v0, $zero, $zero
glabel L802424E4_A093E4
/* A093E4 802424E4 0260202D */  daddu     $a0, $s3, $zero
/* A093E8 802424E8 0200282D */  daddu     $a1, $s0, $zero
/* A093EC 802424EC 0C090864 */  jal       func_80242190_A09090
/* A093F0 802424F0 0280302D */   daddu    $a2, $s4, $zero
/* A093F4 802424F4 8E630070 */  lw        $v1, 0x70($s3)
/* A093F8 802424F8 2402000F */  addiu     $v0, $zero, 0xf
/* A093FC 802424FC 14620006 */  bne       $v1, $v0, .L80242518
/* A09400 80242500 0000102D */   daddu    $v0, $zero, $zero
glabel L80242504_A09404
/* A09404 80242504 0260202D */  daddu     $a0, $s3, $zero
/* A09408 80242508 0200282D */  daddu     $a1, $s0, $zero
/* A0940C 8024250C 0C0908AA */  jal       nok_15_UnkDurationCheck
/* A09410 80242510 0280302D */   daddu    $a2, $s4, $zero
.L80242514:
glabel L80242514_A09414
/* A09414 80242514 0000102D */  daddu     $v0, $zero, $zero
.L80242518:
/* A09418 80242518 8FBF0048 */  lw        $ra, 0x48($sp)
/* A0941C 8024251C 8FB50044 */  lw        $s5, 0x44($sp)
/* A09420 80242520 8FB40040 */  lw        $s4, 0x40($sp)
/* A09424 80242524 8FB3003C */  lw        $s3, 0x3c($sp)
/* A09428 80242528 8FB20038 */  lw        $s2, 0x38($sp)
/* A0942C 8024252C 8FB10034 */  lw        $s1, 0x34($sp)
/* A09430 80242530 8FB00030 */  lw        $s0, 0x30($sp)
/* A09434 80242534 03E00008 */  jr        $ra
/* A09438 80242538 27BD0050 */   addiu    $sp, $sp, 0x50
/* A0943C 8024253C 00000000 */  nop
