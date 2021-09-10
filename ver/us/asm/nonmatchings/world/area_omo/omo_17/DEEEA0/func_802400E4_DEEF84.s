.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E4_DEEF84
/* DEEF84 802400E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DEEF88 802400E8 AFB10014 */  sw        $s1, 0x14($sp)
/* DEEF8C 802400EC 0080882D */  daddu     $s1, $a0, $zero
/* DEEF90 802400F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DEEF94 802400F4 AFB00010 */  sw        $s0, 0x10($sp)
/* DEEF98 802400F8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DEEF9C 802400FC 8E30000C */  lw        $s0, 0xc($s1)
/* DEEFA0 80240100 8E050000 */  lw        $a1, ($s0)
/* DEEFA4 80240104 0C0B210B */  jal       evt_get_float_variable
/* DEEFA8 80240108 26100004 */   addiu    $s0, $s0, 4
/* DEEFAC 8024010C 8E050000 */  lw        $a1, ($s0)
/* DEEFB0 80240110 26100004 */  addiu     $s0, $s0, 4
/* DEEFB4 80240114 0220202D */  daddu     $a0, $s1, $zero
/* DEEFB8 80240118 0C0B210B */  jal       evt_get_float_variable
/* DEEFBC 8024011C 46000506 */   mov.s    $f20, $f0
/* DEEFC0 80240120 4614003C */  c.lt.s    $f0, $f20
/* DEEFC4 80240124 00000000 */  nop
/* DEEFC8 80240128 45000004 */  bc1f      .L8024013C
/* DEEFCC 8024012C 0220202D */   daddu    $a0, $s1, $zero
/* DEEFD0 80240130 8E050000 */  lw        $a1, ($s0)
/* DEEFD4 80240134 08090051 */  j         .L80240144
/* DEEFD8 80240138 24060001 */   addiu    $a2, $zero, 1
.L8024013C:
/* DEEFDC 8024013C 8E050000 */  lw        $a1, ($s0)
/* DEEFE0 80240140 0000302D */  daddu     $a2, $zero, $zero
.L80240144:
/* DEEFE4 80240144 0C0B2026 */  jal       evt_set_variable
/* DEEFE8 80240148 00000000 */   nop
/* DEEFEC 8024014C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DEEFF0 80240150 8FB10014 */  lw        $s1, 0x14($sp)
/* DEEFF4 80240154 8FB00010 */  lw        $s0, 0x10($sp)
/* DEEFF8 80240158 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DEEFFC 8024015C 24020002 */  addiu     $v0, $zero, 2
/* DEF000 80240160 03E00008 */  jr        $ra
/* DEF004 80240164 27BD0028 */   addiu    $sp, $sp, 0x28
