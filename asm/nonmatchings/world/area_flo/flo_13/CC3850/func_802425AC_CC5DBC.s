.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425AC_CC5DBC
/* CC5DBC 802425AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CC5DC0 802425B0 AFB10014 */  sw        $s1, 0x14($sp)
/* CC5DC4 802425B4 0080882D */  daddu     $s1, $a0, $zero
/* CC5DC8 802425B8 AFBF0018 */  sw        $ra, 0x18($sp)
/* CC5DCC 802425BC AFB00010 */  sw        $s0, 0x10($sp)
/* CC5DD0 802425C0 8E300148 */  lw        $s0, 0x148($s1)
/* CC5DD4 802425C4 0C00EABB */  jal       get_npc_unsafe
/* CC5DD8 802425C8 86040008 */   lh       $a0, 8($s0)
/* CC5DDC 802425CC 0040202D */  daddu     $a0, $v0, $zero
/* CC5DE0 802425D0 9482008E */  lhu       $v0, 0x8e($a0)
/* CC5DE4 802425D4 24030003 */  addiu     $v1, $zero, 3
/* CC5DE8 802425D8 24420001 */  addiu     $v0, $v0, 1
/* CC5DEC 802425DC A482008E */  sh        $v0, 0x8e($a0)
/* CC5DF0 802425E0 00021400 */  sll       $v0, $v0, 0x10
/* CC5DF4 802425E4 00021403 */  sra       $v0, $v0, 0x10
/* CC5DF8 802425E8 14430003 */  bne       $v0, $v1, .L802425F8
/* CC5DFC 802425EC 00000000 */   nop      
/* CC5E00 802425F0 96020086 */  lhu       $v0, 0x86($s0)
/* CC5E04 802425F4 A48200A8 */  sh        $v0, 0xa8($a0)
.L802425F8:
/* CC5E08 802425F8 8482008E */  lh        $v0, 0x8e($a0)
/* CC5E0C 802425FC 8E030080 */  lw        $v1, 0x80($s0)
/* CC5E10 80242600 0043102A */  slt       $v0, $v0, $v1
/* CC5E14 80242604 14400004 */  bnez      $v0, .L80242618
/* CC5E18 80242608 00000000 */   nop      
/* CC5E1C 8024260C 96020086 */  lhu       $v0, 0x86($s0)
/* CC5E20 80242610 A48200A8 */  sh        $v0, 0xa8($a0)
/* CC5E24 80242614 AE200070 */  sw        $zero, 0x70($s1)
.L80242618:
/* CC5E28 80242618 8FBF0018 */  lw        $ra, 0x18($sp)
/* CC5E2C 8024261C 8FB10014 */  lw        $s1, 0x14($sp)
/* CC5E30 80242620 8FB00010 */  lw        $s0, 0x10($sp)
/* CC5E34 80242624 03E00008 */  jr        $ra
/* CC5E38 80242628 27BD0020 */   addiu    $sp, $sp, 0x20
