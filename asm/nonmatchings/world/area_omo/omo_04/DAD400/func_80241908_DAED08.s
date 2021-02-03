.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241908_DAED08
/* DAED08 80241908 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DAED0C 8024190C AFB20028 */  sw        $s2, 0x28($sp)
/* DAED10 80241910 0080902D */  daddu     $s2, $a0, $zero
/* DAED14 80241914 AFBF002C */  sw        $ra, 0x2c($sp)
/* DAED18 80241918 AFB10024 */  sw        $s1, 0x24($sp)
/* DAED1C 8024191C AFB00020 */  sw        $s0, 0x20($sp)
/* DAED20 80241920 8E510148 */  lw        $s1, 0x148($s2)
/* DAED24 80241924 0C00EABB */  jal       get_npc_unsafe
/* DAED28 80241928 86240008 */   lh       $a0, 8($s1)
/* DAED2C 8024192C 0040802D */  daddu     $s0, $v0, $zero
/* DAED30 80241930 0200202D */  daddu     $a0, $s0, $zero
/* DAED34 80241934 C600000C */  lwc1      $f0, 0xc($s0)
/* DAED38 80241938 27A60018 */  addiu     $a2, $sp, 0x18
/* DAED3C 8024193C E7A00018 */  swc1      $f0, 0x18($sp)
/* DAED40 80241940 AFA00010 */  sw        $zero, 0x10($sp)
/* DAED44 80241944 AFA00014 */  sw        $zero, 0x14($sp)
/* DAED48 80241948 8E050018 */  lw        $a1, 0x18($s0)
/* DAED4C 8024194C 0C0129E1 */  jal       func_8004A784
/* DAED50 80241950 0000382D */   daddu    $a3, $zero, $zero
/* DAED54 80241954 14400005 */  bnez      $v0, .L8024196C
/* DAED58 80241958 00000000 */   nop
/* DAED5C 8024195C 8E050018 */  lw        $a1, 0x18($s0)
/* DAED60 80241960 8E06000C */  lw        $a2, 0xc($s0)
/* DAED64 80241964 0C00EA95 */  jal       npc_move_heading
/* DAED68 80241968 0200202D */   daddu    $a0, $s0, $zero
.L8024196C:
/* DAED6C 8024196C 9602008E */  lhu       $v0, 0x8e($s0)
/* DAED70 80241970 2442FFFF */  addiu     $v0, $v0, -1
/* DAED74 80241974 A602008E */  sh        $v0, 0x8e($s0)
/* DAED78 80241978 00021400 */  sll       $v0, $v0, 0x10
/* DAED7C 8024197C 14400010 */  bnez      $v0, .L802419C0
/* DAED80 80241980 00000000 */   nop
/* DAED84 80241984 C6000018 */  lwc1      $f0, 0x18($s0)
/* DAED88 80241988 3C018024 */  lui       $at, %hi(D_80244D10_DB2110)
/* DAED8C 8024198C D4224D10 */  ldc1      $f2, %lo(D_80244D10_DB2110)($at)
/* DAED90 80241990 46000021 */  cvt.d.s   $f0, $f0
/* DAED94 80241994 46220002 */  mul.d     $f0, $f0, $f2
/* DAED98 80241998 00000000 */  nop
/* DAED9C 8024199C 46200020 */  cvt.s.d   $f0, $f0
/* DAEDA0 802419A0 E6000018 */  swc1      $f0, 0x18($s0)
/* DAEDA4 802419A4 8E2200CC */  lw        $v0, 0xcc($s1)
/* DAEDA8 802419A8 8C43002C */  lw        $v1, 0x2c($v0)
/* DAEDAC 802419AC 2402000A */  addiu     $v0, $zero, 0xa
/* DAEDB0 802419B0 A602008E */  sh        $v0, 0x8e($s0)
/* DAEDB4 802419B4 24020010 */  addiu     $v0, $zero, 0x10
/* DAEDB8 802419B8 AE030028 */  sw        $v1, 0x28($s0)
/* DAEDBC 802419BC AE420070 */  sw        $v0, 0x70($s2)
.L802419C0:
/* DAEDC0 802419C0 8FBF002C */  lw        $ra, 0x2c($sp)
/* DAEDC4 802419C4 8FB20028 */  lw        $s2, 0x28($sp)
/* DAEDC8 802419C8 8FB10024 */  lw        $s1, 0x24($sp)
/* DAEDCC 802419CC 8FB00020 */  lw        $s0, 0x20($sp)
/* DAEDD0 802419D0 03E00008 */  jr        $ra
/* DAEDD4 802419D4 27BD0030 */   addiu    $sp, $sp, 0x30
