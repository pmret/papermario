.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422F0_EE0CB0
/* EE0CB0 802422F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE0CB4 802422F4 AFB20018 */  sw        $s2, 0x18($sp)
/* EE0CB8 802422F8 0080902D */  daddu     $s2, $a0, $zero
/* EE0CBC 802422FC AFBF001C */  sw        $ra, 0x1c($sp)
/* EE0CC0 80242300 AFB10014 */  sw        $s1, 0x14($sp)
/* EE0CC4 80242304 AFB00010 */  sw        $s0, 0x10($sp)
/* EE0CC8 80242308 8E510148 */  lw        $s1, 0x148($s2)
/* EE0CCC 8024230C 0C00F92F */  jal       func_8003E4BC
/* EE0CD0 80242310 86240008 */   lh       $a0, 8($s1)
/* EE0CD4 80242314 0040802D */  daddu     $s0, $v0, $zero
/* EE0CD8 80242318 8E2300CC */  lw        $v1, 0xcc($s1)
/* EE0CDC 8024231C C60C0038 */  lwc1      $f12, 0x38($s0)
/* EE0CE0 80242320 8C630020 */  lw        $v1, 0x20($v1)
/* EE0CE4 80242324 AE030028 */  sw        $v1, 0x28($s0)
/* EE0CE8 80242328 96220076 */  lhu       $v0, 0x76($s1)
/* EE0CEC 8024232C A602008E */  sh        $v0, 0x8e($s0)
/* EE0CF0 80242330 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EE0CF4 80242334 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EE0CF8 80242338 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EE0CFC 8024233C 8C460028 */  lw        $a2, 0x28($v0)
/* EE0D00 80242340 0C00ABDC */  jal       fio_validate_header_checksums
/* EE0D04 80242344 8C470030 */   lw       $a3, 0x30($v0)
/* EE0D08 80242348 2402000D */  addiu     $v0, $zero, 0xd
/* EE0D0C 8024234C E600000C */  swc1      $f0, 0xc($s0)
/* EE0D10 80242350 AE420070 */  sw        $v0, 0x70($s2)
/* EE0D14 80242354 8FBF001C */  lw        $ra, 0x1c($sp)
/* EE0D18 80242358 8FB20018 */  lw        $s2, 0x18($sp)
/* EE0D1C 8024235C 8FB10014 */  lw        $s1, 0x14($sp)
/* EE0D20 80242360 8FB00010 */  lw        $s0, 0x10($sp)
/* EE0D24 80242364 03E00008 */  jr        $ra
/* EE0D28 80242368 27BD0020 */   addiu    $sp, $sp, 0x20
