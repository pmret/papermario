.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E68
/* BAF7A8 80241E68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BAF7AC 80241E6C AFB10014 */  sw        $s1, 0x14($sp)
/* BAF7B0 80241E70 0080882D */  daddu     $s1, $a0, $zero
/* BAF7B4 80241E74 AFBF0018 */  sw        $ra, 0x18($sp)
/* BAF7B8 80241E78 AFB00010 */  sw        $s0, 0x10($sp)
/* BAF7BC 80241E7C 8E300148 */  lw        $s0, 0x148($s1)
/* BAF7C0 80241E80 0C00EABB */  jal       get_npc_unsafe
/* BAF7C4 80241E84 86040008 */   lh       $a0, 8($s0)
/* BAF7C8 80241E88 0040202D */  daddu     $a0, $v0, $zero
/* BAF7CC 80241E8C 8482008E */  lh        $v0, 0x8e($a0)
/* BAF7D0 80241E90 9483008E */  lhu       $v1, 0x8e($a0)
/* BAF7D4 80241E94 18400003 */  blez      $v0, .L80241EA4
/* BAF7D8 80241E98 2462FFFF */   addiu    $v0, $v1, -1
/* BAF7DC 80241E9C 080907B0 */  j         .L80241EC0
/* BAF7E0 80241EA0 A482008E */   sh       $v0, 0x8e($a0)
.L80241EA4:
/* BAF7E4 80241EA4 8E0200CC */  lw        $v0, 0xcc($s0)
/* BAF7E8 80241EA8 AE00006C */  sw        $zero, 0x6c($s0)
/* BAF7EC 80241EAC 8C420000 */  lw        $v0, ($v0)
/* BAF7F0 80241EB0 AC820028 */  sw        $v0, 0x28($a0)
/* BAF7F4 80241EB4 24020001 */  addiu     $v0, $zero, 1
/* BAF7F8 80241EB8 AE200074 */  sw        $zero, 0x74($s1)
/* BAF7FC 80241EBC AE220070 */  sw        $v0, 0x70($s1)
.L80241EC0:
/* BAF800 80241EC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BAF804 80241EC4 8FB10014 */  lw        $s1, 0x14($sp)
/* BAF808 80241EC8 8FB00010 */  lw        $s0, 0x10($sp)
/* BAF80C 80241ECC 03E00008 */  jr        $ra
/* BAF810 80241ED0 27BD0020 */   addiu    $sp, $sp, 0x20
