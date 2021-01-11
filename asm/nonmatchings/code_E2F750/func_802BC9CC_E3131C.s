.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC9CC_E3131C
/* E3131C 802BC9CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E31320 802BC9D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* E31324 802BC9D4 8C820040 */  lw        $v0, 0x40($a0)
/* E31328 802BC9D8 90420002 */  lbu       $v0, 2($v0)
/* E3132C 802BC9DC 30420001 */  andi      $v0, $v0, 1
/* E31330 802BC9E0 10400003 */  beqz      $v0, .L802BC9F0
/* E31334 802BC9E4 00000000 */   nop      
/* E31338 802BC9E8 0C04419E */  jal       func_80110678
/* E3133C 802BC9EC 00000000 */   nop      
.L802BC9F0:
/* E31340 802BC9F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* E31344 802BC9F4 03E00008 */  jr        $ra
/* E31348 802BC9F8 27BD0018 */   addiu    $sp, $sp, 0x18
