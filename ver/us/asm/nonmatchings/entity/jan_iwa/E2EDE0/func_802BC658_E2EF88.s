.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC658_E2EF88
/* E2EF88 802BC658 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* E2EF8C 802BC65C 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* E2EF90 802BC660 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EF94 802BC664 30420001 */  andi      $v0, $v0, 1
/* E2EF98 802BC668 14400007 */  bnez      $v0, .L802BC688
/* E2EF9C 802BC66C AFBF0010 */   sw       $ra, 0x10($sp)
/* E2EFA0 802BC670 90820006 */  lbu       $v0, 6($a0)
/* E2EFA4 802BC674 30420008 */  andi      $v0, $v0, 8
/* E2EFA8 802BC678 10400003 */  beqz      $v0, .L802BC688
/* E2EFAC 802BC67C 00000000 */   nop
/* E2EFB0 802BC680 0C04419E */  jal       entity_start_script
/* E2EFB4 802BC684 00000000 */   nop
.L802BC688:
/* E2EFB8 802BC688 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2EFBC 802BC68C 03E00008 */  jr        $ra
/* E2EFC0 802BC690 27BD0018 */   addiu    $sp, $sp, 0x18
/* E2EFC4 802BC694 00000000 */  nop
/* E2EFC8 802BC698 00000000 */  nop
/* E2EFCC 802BC69C 00000000 */  nop
