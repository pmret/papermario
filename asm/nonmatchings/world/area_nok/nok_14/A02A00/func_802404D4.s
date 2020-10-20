.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D4
/* A02D14 802404D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A02D18 802404D8 AFB10014 */  sw        $s1, 0x14($sp)
/* A02D1C 802404DC 0080882D */  daddu     $s1, $a0, $zero
/* A02D20 802404E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A02D24 802404E4 AFB00010 */  sw        $s0, 0x10($sp)
/* A02D28 802404E8 8E300148 */  lw        $s0, 0x148($s1)
/* A02D2C 802404EC 0C00EABB */  jal       get_npc_unsafe
/* A02D30 802404F0 86040008 */   lh       $a0, 8($s0)
/* A02D34 802404F4 0040202D */  daddu     $a0, $v0, $zero
/* A02D38 802404F8 9482008E */  lhu       $v0, 0x8e($a0)
/* A02D3C 802404FC 24030003 */  addiu     $v1, $zero, 3
/* A02D40 80240500 24420001 */  addiu     $v0, $v0, 1
/* A02D44 80240504 A482008E */  sh        $v0, 0x8e($a0)
/* A02D48 80240508 00021400 */  sll       $v0, $v0, 0x10
/* A02D4C 8024050C 00021403 */  sra       $v0, $v0, 0x10
/* A02D50 80240510 14430003 */  bne       $v0, $v1, .L80240520
/* A02D54 80240514 00000000 */   nop      
/* A02D58 80240518 96020086 */  lhu       $v0, 0x86($s0)
/* A02D5C 8024051C A48200A8 */  sh        $v0, 0xa8($a0)
.L80240520:
/* A02D60 80240520 8482008E */  lh        $v0, 0x8e($a0)
/* A02D64 80240524 8E030080 */  lw        $v1, 0x80($s0)
/* A02D68 80240528 0043102A */  slt       $v0, $v0, $v1
/* A02D6C 8024052C 14400004 */  bnez      $v0, .L80240540
/* A02D70 80240530 00000000 */   nop      
/* A02D74 80240534 96020086 */  lhu       $v0, 0x86($s0)
/* A02D78 80240538 A48200A8 */  sh        $v0, 0xa8($a0)
/* A02D7C 8024053C AE200070 */  sw        $zero, 0x70($s1)
.L80240540:
/* A02D80 80240540 8FBF0018 */  lw        $ra, 0x18($sp)
/* A02D84 80240544 8FB10014 */  lw        $s1, 0x14($sp)
/* A02D88 80240548 8FB00010 */  lw        $s0, 0x10($sp)
/* A02D8C 8024054C 03E00008 */  jr        $ra
/* A02D90 80240550 27BD0020 */   addiu    $sp, $sp, 0x20
