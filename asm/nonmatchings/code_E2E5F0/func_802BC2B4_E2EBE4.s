.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC2B4_E2EBE4
/* E2EBE4 802BC2B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EBE8 802BC2B8 3C05802C */  lui       $a1, %hi(D_802BCCB0)
/* E2EBEC 802BC2BC 24A5CCB0 */  addiu     $a1, $a1, %lo(D_802BCCB0)
/* E2EBF0 802BC2C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2EBF4 802BC2C4 0C0AF074 */  jal       func_802BC1D0_E2EB00
/* E2EBF8 802BC2C8 00000000 */   nop      
/* E2EBFC 802BC2CC 3C027FFF */  lui       $v0, 0x7fff
/* E2EC00 802BC2D0 3442FFFF */  ori       $v0, $v0, 0xffff
/* E2EC04 802BC2D4 3C040008 */  lui       $a0, 8
/* E2EC08 802BC2D8 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* E2EC0C 802BC2DC 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* E2EC10 802BC2E0 8C650000 */  lw        $a1, ($v1)
/* E2EC14 802BC2E4 3484001F */  ori       $a0, $a0, 0x1f
/* E2EC18 802BC2E8 A06000B5 */  sb        $zero, 0xb5($v1)
/* E2EC1C 802BC2EC A06000B4 */  sb        $zero, 0xb4($v1)
/* E2EC20 802BC2F0 00A22824 */  and       $a1, $a1, $v0
/* E2EC24 802BC2F4 0C037FDE */  jal       func_800DFF78
/* E2EC28 802BC2F8 AC650000 */   sw       $a1, ($v1)
/* E2EC2C 802BC2FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2EC30 802BC300 03E00008 */  jr        $ra
/* E2EC34 802BC304 27BD0018 */   addiu    $sp, $sp, 0x18
