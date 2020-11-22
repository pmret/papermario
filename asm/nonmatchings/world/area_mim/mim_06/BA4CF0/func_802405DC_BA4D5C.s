.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* BA4D5C 802405DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA4D60 802405E0 AFB10014 */  sw        $s1, 0x14($sp)
/* BA4D64 802405E4 0080882D */  daddu     $s1, $a0, $zero
/* BA4D68 802405E8 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA4D6C 802405EC AFB00010 */  sw        $s0, 0x10($sp)
/* BA4D70 802405F0 8E300148 */  lw        $s0, 0x148($s1)
/* BA4D74 802405F4 0C00EABB */  jal       get_npc_unsafe
/* BA4D78 802405F8 86040008 */   lh       $a0, 8($s0)
/* BA4D7C 802405FC 0040202D */  daddu     $a0, $v0, $zero
/* BA4D80 80240600 9482008E */  lhu       $v0, 0x8e($a0)
/* BA4D84 80240604 2442FFFF */  addiu     $v0, $v0, -1
/* BA4D88 80240608 A482008E */  sh        $v0, 0x8e($a0)
/* BA4D8C 8024060C 00021400 */  sll       $v0, $v0, 0x10
/* BA4D90 80240610 1C400009 */  bgtz      $v0, .L80240638
/* BA4D94 80240614 24020003 */   addiu    $v0, $zero, 3
/* BA4D98 80240618 96030076 */  lhu       $v1, 0x76($s0)
/* BA4D9C 8024061C AE02006C */  sw        $v0, 0x6c($s0)
/* BA4DA0 80240620 A483008E */  sh        $v1, 0x8e($a0)
/* BA4DA4 80240624 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA4DA8 80240628 8C420024 */  lw        $v0, 0x24($v0)
/* BA4DAC 8024062C AC820028 */  sw        $v0, 0x28($a0)
/* BA4DB0 80240630 24020020 */  addiu     $v0, $zero, 0x20
/* BA4DB4 80240634 AE220070 */  sw        $v0, 0x70($s1)
.L80240638:
/* BA4DB8 80240638 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA4DBC 8024063C 8FB10014 */  lw        $s1, 0x14($sp)
/* BA4DC0 80240640 8FB00010 */  lw        $s0, 0x10($sp)
/* BA4DC4 80240644 03E00008 */  jr        $ra
/* BA4DC8 80240648 27BD0020 */   addiu    $sp, $sp, 0x20
