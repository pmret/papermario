.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024174C_BAF08C
/* BAF08C 8024174C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BAF090 80241750 AFB10014 */  sw        $s1, 0x14($sp)
/* BAF094 80241754 0080882D */  daddu     $s1, $a0, $zero
/* BAF098 80241758 AFBF0018 */  sw        $ra, 0x18($sp)
/* BAF09C 8024175C AFB00010 */  sw        $s0, 0x10($sp)
/* BAF0A0 80241760 8E300148 */  lw        $s0, 0x148($s1)
/* BAF0A4 80241764 0C00EABB */  jal       get_npc_unsafe
/* BAF0A8 80241768 86040008 */   lh       $a0, 8($s0)
/* BAF0AC 8024176C 9443008E */  lhu       $v1, 0x8e($v0)
/* BAF0B0 80241770 2463FFFF */  addiu     $v1, $v1, -1
/* BAF0B4 80241774 A443008E */  sh        $v1, 0x8e($v0)
/* BAF0B8 80241778 00031C00 */  sll       $v1, $v1, 0x10
/* BAF0BC 8024177C 1C600003 */  bgtz      $v1, .L8024178C
/* BAF0C0 80241780 2402000C */   addiu    $v0, $zero, 0xc
/* BAF0C4 80241784 AE00006C */  sw        $zero, 0x6c($s0)
/* BAF0C8 80241788 AE220070 */  sw        $v0, 0x70($s1)
.L8024178C:
/* BAF0CC 8024178C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BAF0D0 80241790 8FB10014 */  lw        $s1, 0x14($sp)
/* BAF0D4 80241794 8FB00010 */  lw        $s0, 0x10($sp)
/* BAF0D8 80241798 03E00008 */  jr        $ra
/* BAF0DC 8024179C 27BD0020 */   addiu    $sp, $sp, 0x20
