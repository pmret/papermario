.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C4_C85F74
/* C85F74 802404C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C85F78 802404C8 AFB10014 */  sw        $s1, 0x14($sp)
/* C85F7C 802404CC 0080882D */  daddu     $s1, $a0, $zero
/* C85F80 802404D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C85F84 802404D4 AFB00010 */  sw        $s0, 0x10($sp)
/* C85F88 802404D8 8E300148 */  lw        $s0, 0x148($s1)
/* C85F8C 802404DC 0C00EABB */  jal       get_npc_unsafe
/* C85F90 802404E0 86040008 */   lh       $a0, 8($s0)
/* C85F94 802404E4 9443008E */  lhu       $v1, 0x8e($v0)
/* C85F98 802404E8 2463FFFF */  addiu     $v1, $v1, -1
/* C85F9C 802404EC A443008E */  sh        $v1, 0x8e($v0)
/* C85FA0 802404F0 00031C00 */  sll       $v1, $v1, 0x10
/* C85FA4 802404F4 1C600003 */  bgtz      $v1, .L80240504
/* C85FA8 802404F8 2402000C */   addiu    $v0, $zero, 0xc
/* C85FAC 802404FC AE00006C */  sw        $zero, 0x6c($s0)
/* C85FB0 80240500 AE220070 */  sw        $v0, 0x70($s1)
.L80240504:
/* C85FB4 80240504 8FBF0018 */  lw        $ra, 0x18($sp)
/* C85FB8 80240508 8FB10014 */  lw        $s1, 0x14($sp)
/* C85FBC 8024050C 8FB00010 */  lw        $s0, 0x10($sp)
/* C85FC0 80240510 03E00008 */  jr        $ra
/* C85FC4 80240514 27BD0020 */   addiu    $sp, $sp, 0x20
