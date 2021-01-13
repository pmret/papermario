.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242070_C62D80
/* C62D80 80242070 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C62D84 80242074 AFB10014 */  sw        $s1, 0x14($sp)
/* C62D88 80242078 0080882D */  daddu     $s1, $a0, $zero
/* C62D8C 8024207C AFBF0018 */  sw        $ra, 0x18($sp)
/* C62D90 80242080 AFB00010 */  sw        $s0, 0x10($sp)
/* C62D94 80242084 8E300148 */  lw        $s0, 0x148($s1)
/* C62D98 80242088 0C00EABB */  jal       get_npc_unsafe
/* C62D9C 8024208C 86040008 */   lh       $a0, 8($s0)
/* C62DA0 80242090 0040202D */  daddu     $a0, $v0, $zero
/* C62DA4 80242094 9482008E */  lhu       $v0, 0x8e($a0)
/* C62DA8 80242098 2442FFFF */  addiu     $v0, $v0, -1
/* C62DAC 8024209C A482008E */  sh        $v0, 0x8e($a0)
/* C62DB0 802420A0 00021400 */  sll       $v0, $v0, 0x10
/* C62DB4 802420A4 8E030098 */  lw        $v1, 0x98($s0)
/* C62DB8 802420A8 00021403 */  sra       $v0, $v0, 0x10
/* C62DBC 802420AC 0062182A */  slt       $v1, $v1, $v0
/* C62DC0 802420B0 14600005 */  bnez      $v1, .L802420C8
/* C62DC4 802420B4 3C03E0EF */   lui      $v1, 0xe0ef
/* C62DC8 802420B8 8E020000 */  lw        $v0, ($s0)
/* C62DCC 802420BC 3463FFFF */  ori       $v1, $v1, 0xffff
/* C62DD0 802420C0 00431024 */  and       $v0, $v0, $v1
/* C62DD4 802420C4 AE020000 */  sw        $v0, ($s0)
.L802420C8:
/* C62DD8 802420C8 8482008E */  lh        $v0, 0x8e($a0)
/* C62DDC 802420CC 14400007 */  bnez      $v0, .L802420EC
/* C62DE0 802420D0 00000000 */   nop
/* C62DE4 802420D4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C62DE8 802420D8 8C420028 */  lw        $v0, 0x28($v0)
/* C62DEC 802420DC A480008E */  sh        $zero, 0x8e($a0)
/* C62DF0 802420E0 AC820028 */  sw        $v0, 0x28($a0)
/* C62DF4 802420E4 2402000C */  addiu     $v0, $zero, 0xc
/* C62DF8 802420E8 AE220070 */  sw        $v0, 0x70($s1)
.L802420EC:
/* C62DFC 802420EC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C62E00 802420F0 8FB10014 */  lw        $s1, 0x14($sp)
/* C62E04 802420F4 8FB00010 */  lw        $s0, 0x10($sp)
/* C62E08 802420F8 03E00008 */  jr        $ra
/* C62E0C 802420FC 27BD0020 */   addiu    $sp, $sp, 0x20
