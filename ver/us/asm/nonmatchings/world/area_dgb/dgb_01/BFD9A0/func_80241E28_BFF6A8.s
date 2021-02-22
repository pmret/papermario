.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E28_BFF6A8
/* BFF6A8 80241E28 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BFF6AC 80241E2C AFB00010 */  sw        $s0, 0x10($sp)
/* BFF6B0 80241E30 0080802D */  daddu     $s0, $a0, $zero
/* BFF6B4 80241E34 AFBF0014 */  sw        $ra, 0x14($sp)
/* BFF6B8 80241E38 8E020148 */  lw        $v0, 0x148($s0)
/* BFF6BC 80241E3C 0C00EABB */  jal       get_npc_unsafe
/* BFF6C0 80241E40 84440008 */   lh       $a0, 8($v0)
/* BFF6C4 80241E44 9443008E */  lhu       $v1, 0x8e($v0)
/* BFF6C8 80241E48 2463FFFF */  addiu     $v1, $v1, -1
/* BFF6CC 80241E4C A443008E */  sh        $v1, 0x8e($v0)
/* BFF6D0 80241E50 00031C00 */  sll       $v1, $v1, 0x10
/* BFF6D4 80241E54 1C600002 */  bgtz      $v1, .L80241E60
/* BFF6D8 80241E58 2402001E */   addiu    $v0, $zero, 0x1e
/* BFF6DC 80241E5C AE020070 */  sw        $v0, 0x70($s0)
.L80241E60:
/* BFF6E0 80241E60 8FBF0014 */  lw        $ra, 0x14($sp)
/* BFF6E4 80241E64 8FB00010 */  lw        $s0, 0x10($sp)
/* BFF6E8 80241E68 03E00008 */  jr        $ra
/* BFF6EC 80241E6C 27BD0018 */   addiu    $sp, $sp, 0x18
