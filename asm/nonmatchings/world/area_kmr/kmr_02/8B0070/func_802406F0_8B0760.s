.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406F0_8B0760
/* 8B0760 802406F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B0764 802406F4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8B0768 802406F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B076C 802406FC 0C00EABB */  jal       get_npc_unsafe
/* 8B0770 80240700 8C84014C */   lw       $a0, 0x14c($a0)
/* 8B0774 80240704 24040008 */  addiu     $a0, $zero, 8
/* 8B0778 80240708 0040802D */  daddu     $s0, $v0, $zero
/* 8B077C 8024070C 3C028024 */  lui       $v0, 0x8024
/* 8B0780 80240710 2442075C */  addiu     $v0, $v0, 0x75c
/* 8B0784 80240714 0C00AB39 */  jal       heap_malloc
/* 8B0788 80240718 AE020008 */   sw       $v0, 8($s0)
/* 8B078C 8024071C 0040182D */  daddu     $v1, $v0, $zero
/* 8B0790 80240720 AE030020 */  sw        $v1, 0x20($s0)
/* 8B0794 80240724 AC600000 */  sw        $zero, ($v1)
/* 8B0798 80240728 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8B079C 8024072C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B07A0 80240730 24020001 */  addiu     $v0, $zero, 1
/* 8B07A4 80240734 03E00008 */  jr        $ra
/* 8B07A8 80240738 27BD0018 */   addiu    $sp, $sp, 0x18
