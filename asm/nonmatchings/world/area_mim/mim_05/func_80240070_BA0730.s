.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070_BA07A0
/* BA07A0 80240070 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA07A4 80240074 AFB10014 */  sw        $s1, 0x14($sp)
/* BA07A8 80240078 0080882D */  daddu     $s1, $a0, $zero
/* BA07AC 8024007C AFBF0018 */  sw        $ra, 0x18($sp)
/* BA07B0 80240080 AFB00010 */  sw        $s0, 0x10($sp)
/* BA07B4 80240084 8E300148 */  lw        $s0, 0x148($s1)
/* BA07B8 80240088 0C00EABB */  jal       get_npc_unsafe
/* BA07BC 8024008C 86040008 */   lh       $a0, 8($s0)
/* BA07C0 80240090 24030001 */  addiu     $v1, $zero, 1
/* BA07C4 80240094 0040202D */  daddu     $a0, $v0, $zero
/* BA07C8 80240098 AE03006C */  sw        $v1, 0x6c($s0)
/* BA07CC 8024009C 8482008C */  lh        $v0, 0x8c($a0)
/* BA07D0 802400A0 14400009 */  bnez      $v0, .L802400C8
/* BA07D4 802400A4 24020002 */   addiu    $v0, $zero, 2
/* BA07D8 802400A8 96030072 */  lhu       $v1, 0x72($s0)
/* BA07DC 802400AC AE02006C */  sw        $v0, 0x6c($s0)
/* BA07E0 802400B0 A483008E */  sh        $v1, 0x8e($a0)
/* BA07E4 802400B4 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA07E8 802400B8 8C420020 */  lw        $v0, 0x20($v0)
/* BA07EC 802400BC AC820028 */  sw        $v0, 0x28($a0)
/* BA07F0 802400C0 2402001F */  addiu     $v0, $zero, 0x1f
/* BA07F4 802400C4 AE220070 */  sw        $v0, 0x70($s1)
.L802400C8:
/* BA07F8 802400C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA07FC 802400CC 8FB10014 */  lw        $s1, 0x14($sp)
/* BA0800 802400D0 8FB00010 */  lw        $s0, 0x10($sp)
/* BA0804 802400D4 03E00008 */  jr        $ra
/* BA0808 802400D8 27BD0020 */   addiu    $sp, $sp, 0x20
