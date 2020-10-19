.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F08_A96648
/* A96648 80242F08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A9664C 80242F0C AFB10014 */  sw        $s1, 0x14($sp)
/* A96650 80242F10 0080882D */  daddu     $s1, $a0, $zero
/* A96654 80242F14 AFBF0018 */  sw        $ra, 0x18($sp)
/* A96658 80242F18 AFB00010 */  sw        $s0, 0x10($sp)
/* A9665C 80242F1C 8E300148 */  lw        $s0, 0x148($s1)
/* A96660 80242F20 0C00EABB */  jal       get_npc_unsafe
/* A96664 80242F24 86040008 */   lh       $a0, 8($s0)
/* A96668 80242F28 0040202D */  daddu     $a0, $v0, $zero
/* A9666C 80242F2C 9482008E */  lhu       $v0, 0x8e($a0)
/* A96670 80242F30 2442FFFF */  addiu     $v0, $v0, -1
/* A96674 80242F34 A482008E */  sh        $v0, 0x8e($a0)
/* A96678 80242F38 00021400 */  sll       $v0, $v0, 0x10
/* A9667C 80242F3C 1C400008 */  bgtz      $v0, .L80242F60
/* A96680 80242F40 00000000 */   nop      
/* A96684 80242F44 8E0200CC */  lw        $v0, 0xcc($s0)
/* A96688 80242F48 8C430024 */  lw        $v1, 0x24($v0)
/* A9668C 80242F4C 24020007 */  addiu     $v0, $zero, 7
/* A96690 80242F50 A482008E */  sh        $v0, 0x8e($a0)
/* A96694 80242F54 24020017 */  addiu     $v0, $zero, 0x17
/* A96698 80242F58 AC830028 */  sw        $v1, 0x28($a0)
/* A9669C 80242F5C AE220070 */  sw        $v0, 0x70($s1)
.L80242F60:
/* A966A0 80242F60 8FBF0018 */  lw        $ra, 0x18($sp)
/* A966A4 80242F64 8FB10014 */  lw        $s1, 0x14($sp)
/* A966A8 80242F68 8FB00010 */  lw        $s0, 0x10($sp)
/* A966AC 80242F6C 03E00008 */  jr        $ra
/* A966B0 80242F70 27BD0020 */   addiu    $sp, $sp, 0x20
