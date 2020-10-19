.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422F8_C73778
/* C73778 802422F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C7377C 802422FC AFB10014 */  sw        $s1, 0x14($sp)
/* C73780 80242300 0080882D */  daddu     $s1, $a0, $zero
/* C73784 80242304 AFBF0018 */  sw        $ra, 0x18($sp)
/* C73788 80242308 AFB00010 */  sw        $s0, 0x10($sp)
/* C7378C 8024230C 8E300148 */  lw        $s0, 0x148($s1)
/* C73790 80242310 0C00EABB */  jal       get_npc_unsafe
/* C73794 80242314 86040008 */   lh       $a0, 8($s0)
/* C73798 80242318 0040182D */  daddu     $v1, $v0, $zero
/* C7379C 8024231C 9462008E */  lhu       $v0, 0x8e($v1)
/* C737A0 80242320 2442FFFF */  addiu     $v0, $v0, -1
/* C737A4 80242324 A462008E */  sh        $v0, 0x8e($v1)
/* C737A8 80242328 00021400 */  sll       $v0, $v0, 0x10
/* C737AC 8024232C 1C400004 */  bgtz      $v0, .L80242340
/* C737B0 80242330 00000000 */   nop      
/* C737B4 80242334 AE000074 */  sw        $zero, 0x74($s0)
/* C737B8 80242338 A460008E */  sh        $zero, 0x8e($v1)
/* C737BC 8024233C AE200070 */  sw        $zero, 0x70($s1)
.L80242340:
/* C737C0 80242340 8FBF0018 */  lw        $ra, 0x18($sp)
/* C737C4 80242344 8FB10014 */  lw        $s1, 0x14($sp)
/* C737C8 80242348 8FB00010 */  lw        $s0, 0x10($sp)
/* C737CC 8024234C 03E00008 */  jr        $ra
/* C737D0 80242350 27BD0020 */   addiu    $sp, $sp, 0x20
