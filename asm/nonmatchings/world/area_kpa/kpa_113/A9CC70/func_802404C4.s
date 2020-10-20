.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C4
/* A9D0F4 802404C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A9D0F8 802404C8 AFB10014 */  sw        $s1, 0x14($sp)
/* A9D0FC 802404CC 0080882D */  daddu     $s1, $a0, $zero
/* A9D100 802404D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A9D104 802404D4 AFB00010 */  sw        $s0, 0x10($sp)
/* A9D108 802404D8 8E300148 */  lw        $s0, 0x148($s1)
/* A9D10C 802404DC 0C00EABB */  jal       get_npc_unsafe
/* A9D110 802404E0 86040008 */   lh       $a0, 8($s0)
/* A9D114 802404E4 0040202D */  daddu     $a0, $v0, $zero
/* A9D118 802404E8 9482008E */  lhu       $v0, 0x8e($a0)
/* A9D11C 802404EC 24030003 */  addiu     $v1, $zero, 3
/* A9D120 802404F0 24420001 */  addiu     $v0, $v0, 1
/* A9D124 802404F4 A482008E */  sh        $v0, 0x8e($a0)
/* A9D128 802404F8 00021400 */  sll       $v0, $v0, 0x10
/* A9D12C 802404FC 00021403 */  sra       $v0, $v0, 0x10
/* A9D130 80240500 14430003 */  bne       $v0, $v1, .L80240510
/* A9D134 80240504 00000000 */   nop      
/* A9D138 80240508 96020086 */  lhu       $v0, 0x86($s0)
/* A9D13C 8024050C A48200A8 */  sh        $v0, 0xa8($a0)
.L80240510:
/* A9D140 80240510 8482008E */  lh        $v0, 0x8e($a0)
/* A9D144 80240514 8E030080 */  lw        $v1, 0x80($s0)
/* A9D148 80240518 0043102A */  slt       $v0, $v0, $v1
/* A9D14C 8024051C 14400004 */  bnez      $v0, .L80240530
/* A9D150 80240520 00000000 */   nop      
/* A9D154 80240524 96020086 */  lhu       $v0, 0x86($s0)
/* A9D158 80240528 A48200A8 */  sh        $v0, 0xa8($a0)
/* A9D15C 8024052C AE200070 */  sw        $zero, 0x70($s1)
.L80240530:
/* A9D160 80240530 8FBF0018 */  lw        $ra, 0x18($sp)
/* A9D164 80240534 8FB10014 */  lw        $s1, 0x14($sp)
/* A9D168 80240538 8FB00010 */  lw        $s0, 0x10($sp)
/* A9D16C 8024053C 03E00008 */  jr        $ra
/* A9D170 80240540 27BD0020 */   addiu    $sp, $sp, 0x20
