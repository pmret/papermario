.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240060_C3AA70
/* C3AA70 80240060 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3AA74 80240064 AFB10014 */  sw        $s1, 0x14($sp)
/* C3AA78 80240068 0080882D */  daddu     $s1, $a0, $zero
/* C3AA7C 8024006C AFBF0018 */  sw        $ra, 0x18($sp)
/* C3AA80 80240070 AFB00010 */  sw        $s0, 0x10($sp)
/* C3AA84 80240074 8E300148 */  lw        $s0, 0x148($s1)
/* C3AA88 80240078 0C00EABB */  jal       get_npc_unsafe
/* C3AA8C 8024007C 86040008 */   lh       $a0, 8($s0)
/* C3AA90 80240080 24030001 */  addiu     $v1, $zero, 1
/* C3AA94 80240084 0040202D */  daddu     $a0, $v0, $zero
/* C3AA98 80240088 AE03006C */  sw        $v1, 0x6c($s0)
/* C3AA9C 8024008C 8482008C */  lh        $v0, 0x8c($a0)
/* C3AAA0 80240090 14400009 */  bnez      $v0, .L802400B8
/* C3AAA4 80240094 24020002 */   addiu    $v0, $zero, 2
/* C3AAA8 80240098 96030072 */  lhu       $v1, 0x72($s0)
/* C3AAAC 8024009C AE02006C */  sw        $v0, 0x6c($s0)
/* C3AAB0 802400A0 A483008E */  sh        $v1, 0x8e($a0)
/* C3AAB4 802400A4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C3AAB8 802400A8 8C420020 */  lw        $v0, 0x20($v0)
/* C3AABC 802400AC AC820028 */  sw        $v0, 0x28($a0)
/* C3AAC0 802400B0 2402001F */  addiu     $v0, $zero, 0x1f
/* C3AAC4 802400B4 AE220070 */  sw        $v0, 0x70($s1)
.L802400B8:
/* C3AAC8 802400B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3AACC 802400BC 8FB10014 */  lw        $s1, 0x14($sp)
/* C3AAD0 802400C0 8FB00010 */  lw        $s0, 0x10($sp)
/* C3AAD4 802400C4 03E00008 */  jr        $ra
/* C3AAD8 802400C8 27BD0020 */   addiu    $sp, $sp, 0x20
