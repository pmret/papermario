.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429CC_BE617C
/* BE617C 802429CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE6180 802429D0 AFB10014 */  sw        $s1, 0x14($sp)
/* BE6184 802429D4 0080882D */  daddu     $s1, $a0, $zero
/* BE6188 802429D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* BE618C 802429DC AFB00010 */  sw        $s0, 0x10($sp)
/* BE6190 802429E0 8E300148 */  lw        $s0, 0x148($s1)
/* BE6194 802429E4 0C00EABB */  jal       get_npc_unsafe
/* BE6198 802429E8 86040008 */   lh       $a0, 8($s0)
/* BE619C 802429EC 96030096 */  lhu       $v1, 0x96($s0)
/* BE61A0 802429F0 A443008E */  sh        $v1, 0x8e($v0)
/* BE61A4 802429F4 8E0300CC */  lw        $v1, 0xcc($s0)
/* BE61A8 802429F8 8C630034 */  lw        $v1, 0x34($v1)
/* BE61AC 802429FC AC430028 */  sw        $v1, 0x28($v0)
/* BE61B0 80242A00 24020015 */  addiu     $v0, $zero, 0x15
/* BE61B4 80242A04 AE220070 */  sw        $v0, 0x70($s1)
/* BE61B8 80242A08 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE61BC 80242A0C 8FB10014 */  lw        $s1, 0x14($sp)
/* BE61C0 80242A10 8FB00010 */  lw        $s0, 0x10($sp)
/* BE61C4 80242A14 03E00008 */  jr        $ra
/* BE61C8 80242A18 27BD0020 */   addiu    $sp, $sp, 0x20
