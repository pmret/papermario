.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242604_EE0FC4
/* EE0FC4 80242604 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE0FC8 80242608 AFB10014 */  sw        $s1, 0x14($sp)
/* EE0FCC 8024260C 0080882D */  daddu     $s1, $a0, $zero
/* EE0FD0 80242610 AFBF0018 */  sw        $ra, 0x18($sp)
/* EE0FD4 80242614 AFB00010 */  sw        $s0, 0x10($sp)
/* EE0FD8 80242618 8E300148 */  lw        $s0, 0x148($s1)
/* EE0FDC 8024261C 0C00F92F */  jal       dead_get_npc_unsafe
/* EE0FE0 80242620 86040008 */   lh       $a0, 8($s0)
/* EE0FE4 80242624 0040202D */  daddu     $a0, $v0, $zero
/* EE0FE8 80242628 9482008E */  lhu       $v0, 0x8e($a0)
/* EE0FEC 8024262C 24030003 */  addiu     $v1, $zero, 3
/* EE0FF0 80242630 24420001 */  addiu     $v0, $v0, 1
/* EE0FF4 80242634 A482008E */  sh        $v0, 0x8e($a0)
/* EE0FF8 80242638 00021400 */  sll       $v0, $v0, 0x10
/* EE0FFC 8024263C 00021403 */  sra       $v0, $v0, 0x10
/* EE1000 80242640 14430003 */  bne       $v0, $v1, .L80242650
/* EE1004 80242644 00000000 */   nop
/* EE1008 80242648 96020086 */  lhu       $v0, 0x86($s0)
/* EE100C 8024264C A48200A8 */  sh        $v0, 0xa8($a0)
.L80242650:
/* EE1010 80242650 8482008E */  lh        $v0, 0x8e($a0)
/* EE1014 80242654 8E030080 */  lw        $v1, 0x80($s0)
/* EE1018 80242658 0043102A */  slt       $v0, $v0, $v1
/* EE101C 8024265C 14400004 */  bnez      $v0, .L80242670
/* EE1020 80242660 00000000 */   nop
/* EE1024 80242664 96020086 */  lhu       $v0, 0x86($s0)
/* EE1028 80242668 A48200A8 */  sh        $v0, 0xa8($a0)
/* EE102C 8024266C AE200070 */  sw        $zero, 0x70($s1)
.L80242670:
/* EE1030 80242670 8FBF0018 */  lw        $ra, 0x18($sp)
/* EE1034 80242674 8FB10014 */  lw        $s1, 0x14($sp)
/* EE1038 80242678 8FB00010 */  lw        $s0, 0x10($sp)
/* EE103C 8024267C 03E00008 */  jr        $ra
/* EE1040 80242680 27BD0020 */   addiu    $sp, $sp, 0x20
