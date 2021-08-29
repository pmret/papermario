.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80242EF8_9809C8
.word L80241058_97EB28, L80241068_97EB38, L80241080_97EB50, L80241090_97EB60, L802410E0_97EBB0, L802410E0_97EBB0, L802410E0_97EBB0, L802410E0_97EBB0, L802410E0_97EBB0, L802410E0_97EBB0, L802410E0_97EBB0, L802410E0_97EBB0, L802410A8_97EB78, L802410B8_97EB88, L802410D0_97EBA0, 0

.section .text

glabel func_80240F3C_97EA0C
/* 97EA0C 80240F3C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 97EA10 80240F40 AFB40040 */  sw        $s4, 0x40($sp)
/* 97EA14 80240F44 0080A02D */  daddu     $s4, $a0, $zero
/* 97EA18 80240F48 AFBF0048 */  sw        $ra, 0x48($sp)
/* 97EA1C 80240F4C AFB50044 */  sw        $s5, 0x44($sp)
/* 97EA20 80240F50 AFB3003C */  sw        $s3, 0x3c($sp)
/* 97EA24 80240F54 AFB20038 */  sw        $s2, 0x38($sp)
/* 97EA28 80240F58 AFB10034 */  sw        $s1, 0x34($sp)
/* 97EA2C 80240F5C AFB00030 */  sw        $s0, 0x30($sp)
/* 97EA30 80240F60 8E920148 */  lw        $s2, 0x148($s4)
/* 97EA34 80240F64 86440008 */  lh        $a0, 8($s2)
/* 97EA38 80240F68 8E90000C */  lw        $s0, 0xc($s4)
/* 97EA3C 80240F6C 0C00EABB */  jal       get_npc_unsafe
/* 97EA40 80240F70 00A0882D */   daddu    $s1, $a1, $zero
/* 97EA44 80240F74 0280202D */  daddu     $a0, $s4, $zero
/* 97EA48 80240F78 8E050000 */  lw        $a1, ($s0)
/* 97EA4C 80240F7C 0C0B1EAF */  jal       evt_get_variable
/* 97EA50 80240F80 0040A82D */   daddu    $s5, $v0, $zero
/* 97EA54 80240F84 AFA00010 */  sw        $zero, 0x10($sp)
/* 97EA58 80240F88 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 97EA5C 80240F8C 8C630030 */  lw        $v1, 0x30($v1)
/* 97EA60 80240F90 AFA30014 */  sw        $v1, 0x14($sp)
/* 97EA64 80240F94 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 97EA68 80240F98 8C63001C */  lw        $v1, 0x1c($v1)
/* 97EA6C 80240F9C AFA30018 */  sw        $v1, 0x18($sp)
/* 97EA70 80240FA0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 97EA74 80240FA4 8C630024 */  lw        $v1, 0x24($v1)
/* 97EA78 80240FA8 AFA3001C */  sw        $v1, 0x1c($sp)
/* 97EA7C 80240FAC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 97EA80 80240FB0 8C630028 */  lw        $v1, 0x28($v1)
/* 97EA84 80240FB4 27B30010 */  addiu     $s3, $sp, 0x10
/* 97EA88 80240FB8 AFA30020 */  sw        $v1, 0x20($sp)
/* 97EA8C 80240FBC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 97EA90 80240FC0 3C0142C8 */  lui       $at, 0x42c8
/* 97EA94 80240FC4 44810000 */  mtc1      $at, $f0
/* 97EA98 80240FC8 8C63002C */  lw        $v1, 0x2c($v1)
/* 97EA9C 80240FCC 0040802D */  daddu     $s0, $v0, $zero
/* 97EAA0 80240FD0 E7A00028 */  swc1      $f0, 0x28($sp)
/* 97EAA4 80240FD4 A7A0002C */  sh        $zero, 0x2c($sp)
/* 97EAA8 80240FD8 12200016 */  beqz      $s1, .L80241034
/* 97EAAC 80240FDC AFA30024 */   sw       $v1, 0x24($sp)
/* 97EAB0 80240FE0 8EA20000 */  lw        $v0, ($s5)
/* 97EAB4 80240FE4 2403F7FF */  addiu     $v1, $zero, -0x801
/* 97EAB8 80240FE8 A6A0008E */  sh        $zero, 0x8e($s5)
/* 97EABC 80240FEC 00431024 */  and       $v0, $v0, $v1
/* 97EAC0 80240FF0 2403FDFF */  addiu     $v1, $zero, -0x201
/* 97EAC4 80240FF4 00431024 */  and       $v0, $v0, $v1
/* 97EAC8 80240FF8 34420008 */  ori       $v0, $v0, 8
/* 97EACC 80240FFC AEA20000 */  sw        $v0, ($s5)
/* 97EAD0 80241000 AE800074 */  sw        $zero, 0x74($s4)
/* 97EAD4 80241004 AE800070 */  sw        $zero, 0x70($s4)
/* 97EAD8 80241008 8E420000 */  lw        $v0, ($s2)
/* 97EADC 8024100C 3C034000 */  lui       $v1, 0x4000
/* 97EAE0 80241010 00431024 */  and       $v0, $v0, $v1
/* 97EAE4 80241014 10400007 */  beqz      $v0, .L80241034
/* 97EAE8 80241018 3C03BFFF */   lui      $v1, 0xbfff
/* 97EAEC 8024101C 2402000C */  addiu     $v0, $zero, 0xc
/* 97EAF0 80241020 AE820070 */  sw        $v0, 0x70($s4)
/* 97EAF4 80241024 8E420000 */  lw        $v0, ($s2)
/* 97EAF8 80241028 3463FFFF */  ori       $v1, $v1, 0xffff
/* 97EAFC 8024102C 00431024 */  and       $v0, $v0, $v1
/* 97EB00 80241030 AE420000 */  sw        $v0, ($s2)
.L80241034:
/* 97EB04 80241034 8E830070 */  lw        $v1, 0x70($s4)
/* 97EB08 80241038 2C62000F */  sltiu     $v0, $v1, 0xf
/* 97EB0C 8024103C 10400028 */  beqz      $v0, L802410E0_97EBB0
/* 97EB10 80241040 00031080 */   sll      $v0, $v1, 2
/* 97EB14 80241044 3C018024 */  lui       $at, %hi(jtbl_80242EF8_9809C8)
/* 97EB18 80241048 00220821 */  addu      $at, $at, $v0
/* 97EB1C 8024104C 8C222EF8 */  lw        $v0, %lo(jtbl_80242EF8_9809C8)($at)
/* 97EB20 80241050 00400008 */  jr        $v0
/* 97EB24 80241054 00000000 */   nop
glabel L80241058_97EB28
/* 97EB28 80241058 0280202D */  daddu     $a0, $s4, $zero
/* 97EB2C 8024105C 0200282D */  daddu     $a1, $s0, $zero
/* 97EB30 80241060 0C090385 */  jal       func_80240E14_97E8E4
/* 97EB34 80241064 0260302D */   daddu    $a2, $s3, $zero
glabel L80241068_97EB38
/* 97EB38 80241068 0280202D */  daddu     $a0, $s4, $zero
/* 97EB3C 8024106C 0200282D */  daddu     $a1, $s0, $zero
/* 97EB40 80241070 0C09008C */  jal       func_80240230_97DD00
/* 97EB44 80241074 0260302D */   daddu    $a2, $s3, $zero
/* 97EB48 80241078 08090438 */  j         L802410E0_97EBB0
/* 97EB4C 8024107C 00000000 */   nop
glabel L80241080_97EB50
/* 97EB50 80241080 0280202D */  daddu     $a0, $s4, $zero
/* 97EB54 80241084 0200282D */  daddu     $a1, $s0, $zero
/* 97EB58 80241088 0C09015A */  jal       isk_05_UnkNpcAIFunc1
/* 97EB5C 8024108C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241090_97EB60
/* 97EB60 80241090 0280202D */  daddu     $a0, $s4, $zero
/* 97EB64 80241094 0200282D */  daddu     $a1, $s0, $zero
/* 97EB68 80241098 0C09018A */  jal       func_80240628_97E0F8
/* 97EB6C 8024109C 0260302D */   daddu    $a2, $s3, $zero
/* 97EB70 802410A0 08090438 */  j         L802410E0_97EBB0
/* 97EB74 802410A4 00000000 */   nop
glabel L802410A8_97EB78
/* 97EB78 802410A8 0280202D */  daddu     $a0, $s4, $zero
/* 97EB7C 802410AC 0200282D */  daddu     $a1, $s0, $zero
/* 97EB80 802410B0 0C0903AA */  jal       func_80240EA8_97E978
/* 97EB84 802410B4 0260302D */   daddu    $a2, $s3, $zero
glabel L802410B8_97EB88
/* 97EB88 802410B8 0280202D */  daddu     $a0, $s4, $zero
/* 97EB8C 802410BC 0200282D */  daddu     $a1, $s0, $zero
/* 97EB90 802410C0 0C09022B */  jal       func_802408AC_97E37C
/* 97EB94 802410C4 0260302D */   daddu    $a2, $s3, $zero
/* 97EB98 802410C8 08090438 */  j         L802410E0_97EBB0
/* 97EB9C 802410CC 00000000 */   nop
glabel L802410D0_97EBA0
/* 97EBA0 802410D0 0280202D */  daddu     $a0, $s4, $zero
/* 97EBA4 802410D4 0200282D */  daddu     $a1, $s0, $zero
/* 97EBA8 802410D8 0C0902EB */  jal       isk_05_UnkDurationCheck
/* 97EBAC 802410DC 0260302D */   daddu    $a2, $s3, $zero
glabel L802410E0_97EBB0
/* 97EBB0 802410E0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 97EBB4 802410E4 8FB50044 */  lw        $s5, 0x44($sp)
/* 97EBB8 802410E8 8FB40040 */  lw        $s4, 0x40($sp)
/* 97EBBC 802410EC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 97EBC0 802410F0 8FB20038 */  lw        $s2, 0x38($sp)
/* 97EBC4 802410F4 8FB10034 */  lw        $s1, 0x34($sp)
/* 97EBC8 802410F8 8FB00030 */  lw        $s0, 0x30($sp)
/* 97EBCC 802410FC 0000102D */  daddu     $v0, $zero, $zero
/* 97EBD0 80241100 03E00008 */  jr        $ra
/* 97EBD4 80241104 27BD0050 */   addiu    $sp, $sp, 0x50
