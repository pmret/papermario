.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240590_DE5C40
/* DE5C40 80240590 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* DE5C44 80240594 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* DE5C48 80240598 24020006 */  addiu     $v0, $zero, 6
/* DE5C4C 8024059C 54620003 */  bnel      $v1, $v0, .L802405AC
/* DE5C50 802405A0 AC800088 */   sw       $zero, 0x88($a0)
/* DE5C54 802405A4 24020001 */  addiu     $v0, $zero, 1
/* DE5C58 802405A8 AC820088 */  sw        $v0, 0x88($a0)
.L802405AC:
/* DE5C5C 802405AC 03E00008 */  jr        $ra
/* DE5C60 802405B0 24020002 */   addiu    $v0, $zero, 2
/* DE5C64 802405B4 00000000 */  nop       
/* DE5C68 802405B8 00000000 */  nop       
/* DE5C6C 802405BC 00000000 */  nop       
