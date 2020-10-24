.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242458_CD9738
/* CD9738 80242458 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD973C 8024245C AFB10014 */  sw        $s1, 0x14($sp)
/* CD9740 80242460 0080882D */  daddu     $s1, $a0, $zero
/* CD9744 80242464 AFBF0018 */  sw        $ra, 0x18($sp)
/* CD9748 80242468 AFB00010 */  sw        $s0, 0x10($sp)
/* CD974C 8024246C 8E300148 */  lw        $s0, 0x148($s1)
/* CD9750 80242470 0C00EABB */  jal       get_npc_unsafe
/* CD9754 80242474 86040008 */   lh       $a0, 8($s0)
/* CD9758 80242478 0040202D */  daddu     $a0, $v0, $zero
/* CD975C 8024247C 9482008E */  lhu       $v0, 0x8e($a0)
/* CD9760 80242480 24030003 */  addiu     $v1, $zero, 3
/* CD9764 80242484 24420001 */  addiu     $v0, $v0, 1
/* CD9768 80242488 A482008E */  sh        $v0, 0x8e($a0)
/* CD976C 8024248C 00021400 */  sll       $v0, $v0, 0x10
/* CD9770 80242490 00021403 */  sra       $v0, $v0, 0x10
/* CD9774 80242494 14430003 */  bne       $v0, $v1, .L802424A4
/* CD9778 80242498 00000000 */   nop      
/* CD977C 8024249C 96020086 */  lhu       $v0, 0x86($s0)
/* CD9780 802424A0 A48200A8 */  sh        $v0, 0xa8($a0)
.L802424A4:
/* CD9784 802424A4 8482008E */  lh        $v0, 0x8e($a0)
/* CD9788 802424A8 8E030080 */  lw        $v1, 0x80($s0)
/* CD978C 802424AC 0043102A */  slt       $v0, $v0, $v1
/* CD9790 802424B0 14400004 */  bnez      $v0, .L802424C4
/* CD9794 802424B4 00000000 */   nop      
/* CD9798 802424B8 96020086 */  lhu       $v0, 0x86($s0)
/* CD979C 802424BC A48200A8 */  sh        $v0, 0xa8($a0)
/* CD97A0 802424C0 AE200070 */  sw        $zero, 0x70($s1)
.L802424C4:
/* CD97A4 802424C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD97A8 802424C8 8FB10014 */  lw        $s1, 0x14($sp)
/* CD97AC 802424CC 8FB00010 */  lw        $s0, 0x10($sp)
/* CD97B0 802424D0 03E00008 */  jr        $ra
/* CD97B4 802424D4 27BD0020 */   addiu    $sp, $sp, 0x20
