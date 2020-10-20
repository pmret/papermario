.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EA8
/* 912558 80242EA8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91255C 80242EAC AFB10014 */  sw        $s1, 0x14($sp)
/* 912560 80242EB0 0080882D */  daddu     $s1, $a0, $zero
/* 912564 80242EB4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 912568 80242EB8 AFB00010 */  sw        $s0, 0x10($sp)
/* 91256C 80242EBC 8E300148 */  lw        $s0, 0x148($s1)
/* 912570 80242EC0 0C00EABB */  jal       get_npc_unsafe
/* 912574 80242EC4 86040008 */   lh       $a0, 8($s0)
/* 912578 80242EC8 0040182D */  daddu     $v1, $v0, $zero
/* 91257C 80242ECC 9462008E */  lhu       $v0, 0x8e($v1)
/* 912580 80242ED0 2442FFFF */  addiu     $v0, $v0, -1
/* 912584 80242ED4 A462008E */  sh        $v0, 0x8e($v1)
/* 912588 80242ED8 00021400 */  sll       $v0, $v0, 0x10
/* 91258C 80242EDC 1C400007 */  bgtz      $v0, .L80242EFC
/* 912590 80242EE0 24020008 */   addiu    $v0, $zero, 8
/* 912594 80242EE4 A462008E */  sh        $v0, 0x8e($v1)
/* 912598 80242EE8 8E0200CC */  lw        $v0, 0xcc($s0)
/* 91259C 80242EEC 8C420038 */  lw        $v0, 0x38($v0)
/* 9125A0 80242EF0 AC620028 */  sw        $v0, 0x28($v1)
/* 9125A4 80242EF4 24020034 */  addiu     $v0, $zero, 0x34
/* 9125A8 80242EF8 AE220070 */  sw        $v0, 0x70($s1)
.L80242EFC:
/* 9125AC 80242EFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9125B0 80242F00 8FB10014 */  lw        $s1, 0x14($sp)
/* 9125B4 80242F04 8FB00010 */  lw        $s0, 0x10($sp)
/* 9125B8 80242F08 03E00008 */  jr        $ra
/* 9125BC 80242F0C 27BD0020 */   addiu    $sp, $sp, 0x20
