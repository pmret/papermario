.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024102C
/* D93F6C 8024102C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D93F70 80241030 AFB10034 */  sw        $s1, 0x34($sp)
/* D93F74 80241034 0080882D */  daddu     $s1, $a0, $zero
/* D93F78 80241038 AFBF0038 */  sw        $ra, 0x38($sp)
/* D93F7C 8024103C AFB00030 */  sw        $s0, 0x30($sp)
/* D93F80 80241040 8E300148 */  lw        $s0, 0x148($s1)
/* D93F84 80241044 0C00EABB */  jal       get_npc_unsafe
/* D93F88 80241048 86040008 */   lh       $a0, 8($s0)
/* D93F8C 8024104C 0040282D */  daddu     $a1, $v0, $zero
/* D93F90 80241050 94A2008E */  lhu       $v0, 0x8e($a1)
/* D93F94 80241054 2442FFFF */  addiu     $v0, $v0, -1
/* D93F98 80241058 A4A2008E */  sh        $v0, 0x8e($a1)
/* D93F9C 8024105C 00021400 */  sll       $v0, $v0, 0x10
/* D93FA0 80241060 1C400023 */  bgtz      $v0, .L802410F0
/* D93FA4 80241064 24020004 */   addiu    $v0, $zero, 4
/* D93FA8 80241068 8E0300CC */  lw        $v1, 0xcc($s0)
/* D93FAC 8024106C AE02006C */  sw        $v0, 0x6c($s0)
/* D93FB0 80241070 8C620000 */  lw        $v0, ($v1)
/* D93FB4 80241074 ACA20028 */  sw        $v0, 0x28($a1)
/* D93FB8 80241078 9602007A */  lhu       $v0, 0x7a($s0)
/* D93FBC 8024107C A4A2008E */  sh        $v0, 0x8e($a1)
/* D93FC0 80241080 8E020078 */  lw        $v0, 0x78($s0)
/* D93FC4 80241084 28420008 */  slti      $v0, $v0, 8
/* D93FC8 80241088 14400018 */  bnez      $v0, .L802410EC
/* D93FCC 8024108C 24020021 */   addiu    $v0, $zero, 0x21
/* D93FD0 80241090 24040003 */  addiu     $a0, $zero, 3
/* D93FD4 80241094 27A30028 */  addiu     $v1, $sp, 0x28
/* D93FD8 80241098 84A700A8 */  lh        $a3, 0xa8($a1)
/* D93FDC 8024109C 3C013F80 */  lui       $at, 0x3f80
/* D93FE0 802410A0 44810000 */  mtc1      $at, $f0
/* D93FE4 802410A4 3C014000 */  lui       $at, 0x4000
/* D93FE8 802410A8 44811000 */  mtc1      $at, $f2
/* D93FEC 802410AC 3C01C1A0 */  lui       $at, 0xc1a0
/* D93FF0 802410B0 44812000 */  mtc1      $at, $f4
/* D93FF4 802410B4 44873000 */  mtc1      $a3, $f6
/* D93FF8 802410B8 00000000 */  nop       
/* D93FFC 802410BC 468031A0 */  cvt.s.w   $f6, $f6
/* D94000 802410C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* D94004 802410C4 E7A20014 */  swc1      $f2, 0x14($sp)
/* D94008 802410C8 E7A40018 */  swc1      $f4, 0x18($sp)
/* D9400C 802410CC 8E020078 */  lw        $v0, 0x78($s0)
/* D94010 802410D0 44073000 */  mfc1      $a3, $f6
/* D94014 802410D4 0000302D */  daddu     $a2, $zero, $zero
/* D94018 802410D8 AFA30020 */  sw        $v1, 0x20($sp)
/* D9401C 802410DC 2442FFFF */  addiu     $v0, $v0, -1
/* D94020 802410E0 0C01BFA4 */  jal       fx_emote
/* D94024 802410E4 AFA2001C */   sw       $v0, 0x1c($sp)
/* D94028 802410E8 24020021 */  addiu     $v0, $zero, 0x21
.L802410EC:
/* D9402C 802410EC AE220070 */  sw        $v0, 0x70($s1)
.L802410F0:
/* D94030 802410F0 8FBF0038 */  lw        $ra, 0x38($sp)
/* D94034 802410F4 8FB10034 */  lw        $s1, 0x34($sp)
/* D94038 802410F8 8FB00030 */  lw        $s0, 0x30($sp)
/* D9403C 802410FC 03E00008 */  jr        $ra
/* D94040 80241100 27BD0040 */   addiu    $sp, $sp, 0x40
