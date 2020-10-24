.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F04_A4D924
/* A4D924 80240F04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4D928 80240F08 AFB10014 */  sw        $s1, 0x14($sp)
/* A4D92C 80240F0C 0080882D */  daddu     $s1, $a0, $zero
/* A4D930 80240F10 AFBF0018 */  sw        $ra, 0x18($sp)
/* A4D934 80240F14 AFB00010 */  sw        $s0, 0x10($sp)
/* A4D938 80240F18 8E300148 */  lw        $s0, 0x148($s1)
/* A4D93C 80240F1C 0C00EABB */  jal       get_npc_unsafe
/* A4D940 80240F20 86040008 */   lh       $a0, 8($s0)
/* A4D944 80240F24 0040202D */  daddu     $a0, $v0, $zero
/* A4D948 80240F28 9482008E */  lhu       $v0, 0x8e($a0)
/* A4D94C 80240F2C 2442FFFF */  addiu     $v0, $v0, -1
/* A4D950 80240F30 A482008E */  sh        $v0, 0x8e($a0)
/* A4D954 80240F34 00021400 */  sll       $v0, $v0, 0x10
/* A4D958 80240F38 1C400008 */  bgtz      $v0, .L80240F5C
/* A4D95C 80240F3C 00000000 */   nop      
/* A4D960 80240F40 8E0200CC */  lw        $v0, 0xcc($s0)
/* A4D964 80240F44 8C430024 */  lw        $v1, 0x24($v0)
/* A4D968 80240F48 24020009 */  addiu     $v0, $zero, 9
/* A4D96C 80240F4C A482008E */  sh        $v0, 0x8e($a0)
/* A4D970 80240F50 24020017 */  addiu     $v0, $zero, 0x17
/* A4D974 80240F54 AC830028 */  sw        $v1, 0x28($a0)
/* A4D978 80240F58 AE220070 */  sw        $v0, 0x70($s1)
.L80240F5C:
/* A4D97C 80240F5C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4D980 80240F60 8FB10014 */  lw        $s1, 0x14($sp)
/* A4D984 80240F64 8FB00010 */  lw        $s0, 0x10($sp)
/* A4D988 80240F68 03E00008 */  jr        $ra
/* A4D98C 80240F6C 27BD0020 */   addiu    $sp, $sp, 0x20
