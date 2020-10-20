.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241128_A496E8
/* A496E8 80241128 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A496EC 8024112C AFB10014 */  sw        $s1, 0x14($sp)
/* A496F0 80241130 0080882D */  daddu     $s1, $a0, $zero
/* A496F4 80241134 AFBF0018 */  sw        $ra, 0x18($sp)
/* A496F8 80241138 AFB00010 */  sw        $s0, 0x10($sp)
/* A496FC 8024113C 8E300148 */  lw        $s0, 0x148($s1)
/* A49700 80241140 0C00EABB */  jal       get_npc_unsafe
/* A49704 80241144 86040008 */   lh       $a0, 8($s0)
/* A49708 80241148 0040282D */  daddu     $a1, $v0, $zero
/* A4970C 8024114C 94A2008E */  lhu       $v0, 0x8e($a1)
/* A49710 80241150 2442FFFF */  addiu     $v0, $v0, -1
/* A49714 80241154 A4A2008E */  sh        $v0, 0x8e($a1)
/* A49718 80241158 00021400 */  sll       $v0, $v0, 0x10
/* A4971C 8024115C 1C40000A */  bgtz      $v0, .L80241188
/* A49720 80241160 2404FFFD */   addiu    $a0, $zero, -3
/* A49724 80241164 8E0300CC */  lw        $v1, 0xcc($s0)
/* A49728 80241168 8CA20000 */  lw        $v0, ($a1)
/* A4972C 8024116C 8C630000 */  lw        $v1, ($v1)
/* A49730 80241170 00441024 */  and       $v0, $v0, $a0
/* A49734 80241174 ACA20000 */  sw        $v0, ($a1)
/* A49738 80241178 24020001 */  addiu     $v0, $zero, 1
/* A4973C 8024117C A4A0008E */  sh        $zero, 0x8e($a1)
/* A49740 80241180 ACA30028 */  sw        $v1, 0x28($a1)
/* A49744 80241184 AE220070 */  sw        $v0, 0x70($s1)
.L80241188:
/* A49748 80241188 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4974C 8024118C 8FB10014 */  lw        $s1, 0x14($sp)
/* A49750 80241190 8FB00010 */  lw        $s0, 0x10($sp)
/* A49754 80241194 03E00008 */  jr        $ra
/* A49758 80241198 27BD0020 */   addiu    $sp, $sp, 0x20
