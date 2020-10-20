.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406C4_91BFA4
/* 91BFA4 802406C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91BFA8 802406C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 91BFAC 802406CC 0080882D */  daddu     $s1, $a0, $zero
/* 91BFB0 802406D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91BFB4 802406D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 91BFB8 802406D8 8E300148 */  lw        $s0, 0x148($s1)
/* 91BFBC 802406DC 0C00EABB */  jal       get_npc_unsafe
/* 91BFC0 802406E0 86040008 */   lh       $a0, 8($s0)
/* 91BFC4 802406E4 96030096 */  lhu       $v1, 0x96($s0)
/* 91BFC8 802406E8 A443008E */  sh        $v1, 0x8e($v0)
/* 91BFCC 802406EC 8E0300CC */  lw        $v1, 0xcc($s0)
/* 91BFD0 802406F0 8C630034 */  lw        $v1, 0x34($v1)
/* 91BFD4 802406F4 AC430028 */  sw        $v1, 0x28($v0)
/* 91BFD8 802406F8 24020015 */  addiu     $v0, $zero, 0x15
/* 91BFDC 802406FC AE220070 */  sw        $v0, 0x70($s1)
/* 91BFE0 80240700 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91BFE4 80240704 8FB10014 */  lw        $s1, 0x14($sp)
/* 91BFE8 80240708 8FB00010 */  lw        $s0, 0x10($sp)
/* 91BFEC 8024070C 03E00008 */  jr        $ra
/* 91BFF0 80240710 27BD0020 */   addiu    $sp, $sp, 0x20
