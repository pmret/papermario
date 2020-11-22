.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* D8F06C 80241E1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8F070 80241E20 AFB10014 */  sw        $s1, 0x14($sp)
/* D8F074 80241E24 0080882D */  daddu     $s1, $a0, $zero
/* D8F078 80241E28 AFBF0018 */  sw        $ra, 0x18($sp)
/* D8F07C 80241E2C AFB00010 */  sw        $s0, 0x10($sp)
/* D8F080 80241E30 8E300148 */  lw        $s0, 0x148($s1)
/* D8F084 80241E34 0C00EABB */  jal       get_npc_unsafe
/* D8F088 80241E38 86040008 */   lh       $a0, 8($s0)
/* D8F08C 80241E3C 0040202D */  daddu     $a0, $v0, $zero
/* D8F090 80241E40 9482008E */  lhu       $v0, 0x8e($a0)
/* D8F094 80241E44 2442FFFF */  addiu     $v0, $v0, -1
/* D8F098 80241E48 A482008E */  sh        $v0, 0x8e($a0)
/* D8F09C 80241E4C 00021400 */  sll       $v0, $v0, 0x10
/* D8F0A0 80241E50 1C400009 */  bgtz      $v0, .L80241E78
/* D8F0A4 80241E54 24020003 */   addiu    $v0, $zero, 3
/* D8F0A8 80241E58 96030076 */  lhu       $v1, 0x76($s0)
/* D8F0AC 80241E5C AE02006C */  sw        $v0, 0x6c($s0)
/* D8F0B0 80241E60 A483008E */  sh        $v1, 0x8e($a0)
/* D8F0B4 80241E64 8E0200CC */  lw        $v0, 0xcc($s0)
/* D8F0B8 80241E68 8C420024 */  lw        $v0, 0x24($v0)
/* D8F0BC 80241E6C AC820028 */  sw        $v0, 0x28($a0)
/* D8F0C0 80241E70 24020020 */  addiu     $v0, $zero, 0x20
/* D8F0C4 80241E74 AE220070 */  sw        $v0, 0x70($s1)
.L80241E78:
/* D8F0C8 80241E78 8FBF0018 */  lw        $ra, 0x18($sp)
/* D8F0CC 80241E7C 8FB10014 */  lw        $s1, 0x14($sp)
/* D8F0D0 80241E80 8FB00010 */  lw        $s0, 0x10($sp)
/* D8F0D4 80241E84 03E00008 */  jr        $ra
/* D8F0D8 80241E88 27BD0020 */   addiu    $sp, $sp, 0x20
