.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241498_DDDCC8
/* DDDCC8 80241498 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* DDDCCC 8024149C 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* DDDCD0 802414A0 AC800084 */  sw        $zero, 0x84($a0)
/* DDDCD4 802414A4 80620000 */  lb        $v0, ($v1)
/* DDDCD8 802414A8 10400005 */  beqz      $v0, .L802414C0
/* DDDCDC 802414AC 24020003 */   addiu    $v0, $zero, 3
/* DDDCE0 802414B0 80630003 */  lb        $v1, 3($v1)
/* DDDCE4 802414B4 14620002 */  bne       $v1, $v0, .L802414C0
/* DDDCE8 802414B8 24020001 */   addiu    $v0, $zero, 1
/* DDDCEC 802414BC AC820084 */  sw        $v0, 0x84($a0)
.L802414C0:
/* DDDCF0 802414C0 03E00008 */  jr        $ra
/* DDDCF4 802414C4 24020002 */   addiu    $v0, $zero, 2
/* DDDCF8 802414C8 00000000 */  nop       
/* DDDCFC 802414CC 00000000 */  nop       
