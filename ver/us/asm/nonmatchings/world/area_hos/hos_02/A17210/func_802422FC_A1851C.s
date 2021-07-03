.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80244E38_A1B058
.word L80242408_A18628, L80242418_A18638, L80242430_A18650, L80242440_A18660, L802424C0_A186E0, L802424C0_A186E0, L802424C0_A186E0, L802424C0_A186E0, L802424C0_A186E0, L802424C0_A186E0, L80242458_A18678, L80242468_A18688, L80242480_A186A0, L80242498_A186B8, L802424B0_A186D0, 0

.section .text

glabel func_802422FC_A1851C
/* A1851C 802422FC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A18520 80242300 AFB40040 */  sw        $s4, 0x40($sp)
/* A18524 80242304 0080A02D */  daddu     $s4, $a0, $zero
/* A18528 80242308 AFBF0048 */  sw        $ra, 0x48($sp)
/* A1852C 8024230C AFB50044 */  sw        $s5, 0x44($sp)
/* A18530 80242310 AFB3003C */  sw        $s3, 0x3c($sp)
/* A18534 80242314 AFB20038 */  sw        $s2, 0x38($sp)
/* A18538 80242318 AFB10034 */  sw        $s1, 0x34($sp)
/* A1853C 8024231C AFB00030 */  sw        $s0, 0x30($sp)
/* A18540 80242320 8E920148 */  lw        $s2, 0x148($s4)
/* A18544 80242324 86440008 */  lh        $a0, 8($s2)
/* A18548 80242328 8E90000C */  lw        $s0, 0xc($s4)
/* A1854C 8024232C 0C00EABB */  jal       get_npc_unsafe
/* A18550 80242330 00A0882D */   daddu    $s1, $a1, $zero
/* A18554 80242334 0280202D */  daddu     $a0, $s4, $zero
/* A18558 80242338 8E050000 */  lw        $a1, ($s0)
/* A1855C 8024233C 0C0B1EAF */  jal       get_variable
/* A18560 80242340 0040A82D */   daddu    $s5, $v0, $zero
/* A18564 80242344 AFA00010 */  sw        $zero, 0x10($sp)
/* A18568 80242348 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A1856C 8024234C 8C630030 */  lw        $v1, 0x30($v1)
/* A18570 80242350 AFA30014 */  sw        $v1, 0x14($sp)
/* A18574 80242354 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A18578 80242358 8C63001C */  lw        $v1, 0x1c($v1)
/* A1857C 8024235C AFA30018 */  sw        $v1, 0x18($sp)
/* A18580 80242360 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A18584 80242364 8C630024 */  lw        $v1, 0x24($v1)
/* A18588 80242368 AFA3001C */  sw        $v1, 0x1c($sp)
/* A1858C 8024236C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A18590 80242370 8C630028 */  lw        $v1, 0x28($v1)
/* A18594 80242374 27B30010 */  addiu     $s3, $sp, 0x10
/* A18598 80242378 AFA30020 */  sw        $v1, 0x20($sp)
/* A1859C 8024237C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A185A0 80242380 3C0142F0 */  lui       $at, 0x42f0
/* A185A4 80242384 44810000 */  mtc1      $at, $f0
/* A185A8 80242388 8C63002C */  lw        $v1, 0x2c($v1)
/* A185AC 8024238C 0040802D */  daddu     $s0, $v0, $zero
/* A185B0 80242390 E7A00028 */  swc1      $f0, 0x28($sp)
/* A185B4 80242394 A7A0002C */  sh        $zero, 0x2c($sp)
/* A185B8 80242398 12200006 */  beqz      $s1, .L802423B4
/* A185BC 8024239C AFA30024 */   sw       $v1, 0x24($sp)
/* A185C0 802423A0 02A0202D */  daddu     $a0, $s5, $zero
/* A185C4 802423A4 0240282D */  daddu     $a1, $s2, $zero
/* A185C8 802423A8 0280302D */  daddu     $a2, $s4, $zero
/* A185CC 802423AC 0C090876 */  jal       hos_02_UnkFunc5
/* A185D0 802423B0 0200382D */   daddu    $a3, $s0, $zero
.L802423B4:
/* A185D4 802423B4 2402FFFE */  addiu     $v0, $zero, -2
/* A185D8 802423B8 A2A200AB */  sb        $v0, 0xab($s5)
/* A185DC 802423BC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A185E0 802423C0 30620004 */  andi      $v0, $v1, 4
/* A185E4 802423C4 10400007 */  beqz      $v0, .L802423E4
/* A185E8 802423C8 00000000 */   nop
/* A185EC 802423CC 824200B4 */  lb        $v0, 0xb4($s2)
/* A185F0 802423D0 1440003C */  bnez      $v0, .L802424C4
/* A185F4 802423D4 0000102D */   daddu    $v0, $zero, $zero
/* A185F8 802423D8 2402FFFB */  addiu     $v0, $zero, -5
/* A185FC 802423DC 00621024 */  and       $v0, $v1, $v0
/* A18600 802423E0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802423E4:
/* A18604 802423E4 8E830070 */  lw        $v1, 0x70($s4)
/* A18608 802423E8 2C62000F */  sltiu     $v0, $v1, 0xf
/* A1860C 802423EC 10400034 */  beqz      $v0, L802424C0_A186E0
/* A18610 802423F0 00031080 */   sll      $v0, $v1, 2
/* A18614 802423F4 3C018024 */  lui       $at, %hi(jtbl_80244E38_A1B058)
/* A18618 802423F8 00220821 */  addu      $at, $at, $v0
/* A1861C 802423FC 8C224E38 */  lw        $v0, %lo(jtbl_80244E38_A1B058)($at)
/* A18620 80242400 00400008 */  jr        $v0
/* A18624 80242404 00000000 */   nop
glabel L80242408_A18628
/* A18628 80242408 0280202D */  daddu     $a0, $s4, $zero
/* A1862C 8024240C 0200282D */  daddu     $a1, $s0, $zero
/* A18630 80242410 0C0903FC */  jal       func_80240FF0_A17210
/* A18634 80242414 0260302D */   daddu    $a2, $s3, $zero
glabel L80242418_A18638
/* A18638 80242418 0280202D */  daddu     $a0, $s4, $zero
/* A1863C 8024241C 0200282D */  daddu     $a1, $s0, $zero
/* A18640 80242420 0C090468 */  jal       func_802411A0_A173C0
/* A18644 80242424 0260302D */   daddu    $a2, $s3, $zero
/* A18648 80242428 08090931 */  j         .L802424C4
/* A1864C 8024242C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242430_A18650
/* A18650 80242430 0280202D */  daddu     $a0, $s4, $zero
/* A18654 80242434 0200282D */  daddu     $a1, $s0, $zero
/* A18658 80242438 0C0905F2 */  jal       hos_02_UnkNpcAIFunc1
/* A1865C 8024243C 0260302D */   daddu    $a2, $s3, $zero
glabel L80242440_A18660
/* A18660 80242440 0280202D */  daddu     $a0, $s4, $zero
/* A18664 80242444 0200282D */  daddu     $a1, $s0, $zero
/* A18668 80242448 0C090622 */  jal       hos_02_UnkFunc4
/* A1866C 8024244C 0260302D */   daddu    $a2, $s3, $zero
/* A18670 80242450 08090931 */  j         .L802424C4
/* A18674 80242454 0000102D */   daddu    $v0, $zero, $zero
glabel L80242458_A18678
/* A18678 80242458 0280202D */  daddu     $a0, $s4, $zero
/* A1867C 8024245C 0200282D */  daddu     $a1, $s0, $zero
/* A18680 80242460 0C0906F3 */  jal       hos_02_UnkNpcAIFunc2
/* A18684 80242464 0260302D */   daddu    $a2, $s3, $zero
glabel L80242468_A18688
/* A18688 80242468 0280202D */  daddu     $a0, $s4, $zero
/* A1868C 8024246C 0200282D */  daddu     $a1, $s0, $zero
/* A18690 80242470 0C090711 */  jal       func_80241C44_A17E64
/* A18694 80242474 0260302D */   daddu    $a2, $s3, $zero
/* A18698 80242478 08090931 */  j         .L802424C4
/* A1869C 8024247C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242480_A186A0
/* A186A0 80242480 0280202D */  daddu     $a0, $s4, $zero
/* A186A4 80242484 0200282D */  daddu     $a1, $s0, $zero
/* A186A8 80242488 0C09072C */  jal       hos_02_UnkNpcAIFunc14
/* A186AC 8024248C 0260302D */   daddu    $a2, $s3, $zero
/* A186B0 80242490 08090931 */  j         .L802424C4
/* A186B4 80242494 0000102D */   daddu    $v0, $zero, $zero
glabel L80242498_A186B8
/* A186B8 80242498 0280202D */  daddu     $a0, $s4, $zero
/* A186BC 8024249C 0200282D */  daddu     $a1, $s0, $zero
/* A186C0 802424A0 0C090779 */  jal       hos_02_UnkNpcAIFunc3
/* A186C4 802424A4 0260302D */   daddu    $a2, $s3, $zero
/* A186C8 802424A8 08090931 */  j         .L802424C4
/* A186CC 802424AC 0000102D */   daddu    $v0, $zero, $zero
glabel L802424B0_A186D0
/* A186D0 802424B0 0280202D */  daddu     $a0, $s4, $zero
/* A186D4 802424B4 0200282D */  daddu     $a1, $s0, $zero
/* A186D8 802424B8 0C090792 */  jal       hos_02_UnkFunc6
/* A186DC 802424BC 0260302D */   daddu    $a2, $s3, $zero
glabel L802424C0_A186E0
/* A186E0 802424C0 0000102D */  daddu     $v0, $zero, $zero
.L802424C4:
/* A186E4 802424C4 8FBF0048 */  lw        $ra, 0x48($sp)
/* A186E8 802424C8 8FB50044 */  lw        $s5, 0x44($sp)
/* A186EC 802424CC 8FB40040 */  lw        $s4, 0x40($sp)
/* A186F0 802424D0 8FB3003C */  lw        $s3, 0x3c($sp)
/* A186F4 802424D4 8FB20038 */  lw        $s2, 0x38($sp)
/* A186F8 802424D8 8FB10034 */  lw        $s1, 0x34($sp)
/* A186FC 802424DC 8FB00030 */  lw        $s0, 0x30($sp)
/* A18700 802424E0 03E00008 */  jr        $ra
/* A18704 802424E4 27BD0050 */   addiu    $sp, $sp, 0x50
