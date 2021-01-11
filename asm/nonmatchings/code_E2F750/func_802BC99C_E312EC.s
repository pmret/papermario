.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC99C_E312EC
/* E312EC 802BC99C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E312F0 802BC9A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* E312F4 802BC9A4 8C820000 */  lw        $v0, ($a0)
/* E312F8 802BC9A8 3C030200 */  lui       $v1, 0x200
/* E312FC 802BC9AC 00431024 */  and       $v0, $v0, $v1
/* E31300 802BC9B0 14400003 */  bnez      $v0, .L802BC9C0
/* E31304 802BC9B4 00000000 */   nop      
/* E31308 802BC9B8 0C043F5A */  jal       func_8010FD68
/* E3130C 802BC9BC 00000000 */   nop      
.L802BC9C0:
/* E31310 802BC9C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* E31314 802BC9C4 03E00008 */  jr        $ra
/* E31318 802BC9C8 27BD0018 */   addiu    $sp, $sp, 0x18
