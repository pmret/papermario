.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C4_EA0DC4
/* EA0DC4 802404C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA0DC8 802404C8 AFB10014 */  sw        $s1, 0x14($sp)
/* EA0DCC 802404CC 0080882D */  daddu     $s1, $a0, $zero
/* EA0DD0 802404D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA0DD4 802404D4 AFB00010 */  sw        $s0, 0x10($sp)
/* EA0DD8 802404D8 8E300148 */  lw        $s0, 0x148($s1)
/* EA0DDC 802404DC 0C00F92F */  jal       func_8003E4BC
/* EA0DE0 802404E0 86040008 */   lh       $a0, 8($s0)
/* EA0DE4 802404E4 9443008E */  lhu       $v1, 0x8e($v0)
/* EA0DE8 802404E8 2463FFFF */  addiu     $v1, $v1, -1
/* EA0DEC 802404EC A443008E */  sh        $v1, 0x8e($v0)
/* EA0DF0 802404F0 00031C00 */  sll       $v1, $v1, 0x10
/* EA0DF4 802404F4 1C600003 */  bgtz      $v1, .L80240504
/* EA0DF8 802404F8 2402000C */   addiu    $v0, $zero, 0xc
/* EA0DFC 802404FC AE00006C */  sw        $zero, 0x6c($s0)
/* EA0E00 80240500 AE220070 */  sw        $v0, 0x70($s1)
.L80240504:
/* EA0E04 80240504 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA0E08 80240508 8FB10014 */  lw        $s1, 0x14($sp)
/* EA0E0C 8024050C 8FB00010 */  lw        $s0, 0x10($sp)
/* EA0E10 80240510 03E00008 */  jr        $ra
/* EA0E14 80240514 27BD0020 */   addiu    $sp, $sp, 0x20
