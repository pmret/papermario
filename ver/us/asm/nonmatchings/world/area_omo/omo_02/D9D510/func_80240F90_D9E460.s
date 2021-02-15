.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F90_D9E460
/* D9E460 80240F90 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D9E464 80240F94 AFB40040 */  sw        $s4, 0x40($sp)
/* D9E468 80240F98 0080A02D */  daddu     $s4, $a0, $zero
/* D9E46C 80240F9C AFBF0044 */  sw        $ra, 0x44($sp)
/* D9E470 80240FA0 AFB3003C */  sw        $s3, 0x3c($sp)
/* D9E474 80240FA4 AFB20038 */  sw        $s2, 0x38($sp)
/* D9E478 80240FA8 AFB10034 */  sw        $s1, 0x34($sp)
/* D9E47C 80240FAC AFB00030 */  sw        $s0, 0x30($sp)
/* D9E480 80240FB0 8E920148 */  lw        $s2, 0x148($s4)
/* D9E484 80240FB4 00A0802D */  daddu     $s0, $a1, $zero
/* D9E488 80240FB8 86440008 */  lh        $a0, 8($s2)
/* D9E48C 80240FBC 0C00EABB */  jal       get_npc_unsafe
/* D9E490 80240FC0 00C0982D */   daddu    $s3, $a2, $zero
/* D9E494 80240FC4 8E030008 */  lw        $v1, 8($s0)
/* D9E498 80240FC8 04600031 */  bltz      $v1, .L80241090
/* D9E49C 80240FCC 0040882D */   daddu    $s1, $v0, $zero
/* D9E4A0 80240FD0 0260202D */  daddu     $a0, $s3, $zero
/* D9E4A4 80240FD4 AFA00010 */  sw        $zero, 0x10($sp)
/* D9E4A8 80240FD8 8E060018 */  lw        $a2, 0x18($s0)
/* D9E4AC 80240FDC 8E07001C */  lw        $a3, 0x1c($s0)
/* D9E4B0 80240FE0 0C01242D */  jal       func_800490B4
/* D9E4B4 80240FE4 0240282D */   daddu    $a1, $s2, $zero
/* D9E4B8 80240FE8 10400029 */  beqz      $v0, .L80241090
/* D9E4BC 80240FEC 0000202D */   daddu    $a0, $zero, $zero
/* D9E4C0 80240FF0 0220282D */  daddu     $a1, $s1, $zero
/* D9E4C4 80240FF4 0000302D */  daddu     $a2, $zero, $zero
/* D9E4C8 80240FF8 862300A8 */  lh        $v1, 0xa8($s1)
/* D9E4CC 80240FFC 3C013F80 */  lui       $at, 0x3f80
/* D9E4D0 80241000 44810000 */  mtc1      $at, $f0
/* D9E4D4 80241004 3C014000 */  lui       $at, 0x4000
/* D9E4D8 80241008 44811000 */  mtc1      $at, $f2
/* D9E4DC 8024100C 3C01C1A0 */  lui       $at, 0xc1a0
/* D9E4E0 80241010 44812000 */  mtc1      $at, $f4
/* D9E4E4 80241014 2402000F */  addiu     $v0, $zero, 0xf
/* D9E4E8 80241018 AFA2001C */  sw        $v0, 0x1c($sp)
/* D9E4EC 8024101C 44833000 */  mtc1      $v1, $f6
/* D9E4F0 80241020 00000000 */  nop
/* D9E4F4 80241024 468031A0 */  cvt.s.w   $f6, $f6
/* D9E4F8 80241028 44073000 */  mfc1      $a3, $f6
/* D9E4FC 8024102C 27A20028 */  addiu     $v0, $sp, 0x28
/* D9E500 80241030 AFA20020 */  sw        $v0, 0x20($sp)
/* D9E504 80241034 E7A00010 */  swc1      $f0, 0x10($sp)
/* D9E508 80241038 E7A20014 */  swc1      $f2, 0x14($sp)
/* D9E50C 8024103C 0C01BFA4 */  jal       fx_emote
/* D9E510 80241040 E7A40018 */   swc1     $f4, 0x18($sp)
/* D9E514 80241044 0220202D */  daddu     $a0, $s1, $zero
/* D9E518 80241048 240502F4 */  addiu     $a1, $zero, 0x2f4
/* D9E51C 8024104C 0C012530 */  jal       func_800494C0
/* D9E520 80241050 3C060020 */   lui      $a2, 0x20
/* D9E524 80241054 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D9E528 80241058 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D9E52C 8024105C C62C0038 */  lwc1      $f12, 0x38($s1)
/* D9E530 80241060 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D9E534 80241064 8C460028 */  lw        $a2, 0x28($v0)
/* D9E538 80241068 0C00A720 */  jal       atan2
/* D9E53C 8024106C 8C470030 */   lw       $a3, 0x30($v0)
/* D9E540 80241070 E620000C */  swc1      $f0, 0xc($s1)
/* D9E544 80241074 8E420018 */  lw        $v0, 0x18($s2)
/* D9E548 80241078 9442002A */  lhu       $v0, 0x2a($v0)
/* D9E54C 8024107C 30420001 */  andi      $v0, $v0, 1
/* D9E550 80241080 14400002 */  bnez      $v0, .L8024108C
/* D9E554 80241084 2402000A */   addiu    $v0, $zero, 0xa
/* D9E558 80241088 2402000C */  addiu     $v0, $zero, 0xc
.L8024108C:
/* D9E55C 8024108C AE820070 */  sw        $v0, 0x70($s4)
.L80241090:
/* D9E560 80241090 8FBF0044 */  lw        $ra, 0x44($sp)
/* D9E564 80241094 8FB40040 */  lw        $s4, 0x40($sp)
/* D9E568 80241098 8FB3003C */  lw        $s3, 0x3c($sp)
/* D9E56C 8024109C 8FB20038 */  lw        $s2, 0x38($sp)
/* D9E570 802410A0 8FB10034 */  lw        $s1, 0x34($sp)
/* D9E574 802410A4 8FB00030 */  lw        $s0, 0x30($sp)
/* D9E578 802410A8 03E00008 */  jr        $ra
/* D9E57C 802410AC 27BD0048 */   addiu    $sp, $sp, 0x48
