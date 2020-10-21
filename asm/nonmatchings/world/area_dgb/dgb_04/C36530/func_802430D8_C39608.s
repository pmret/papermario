.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802430D8_C39608
/* C39608 802430D8 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C3960C 802430DC 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* C39610 802430E0 AC800084 */  sw        $zero, 0x84($a0)
/* C39614 802430E4 80620000 */  lb        $v0, ($v1)
/* C39618 802430E8 10400005 */  beqz      $v0, .L80243100
/* C3961C 802430EC 24020003 */   addiu    $v0, $zero, 3
/* C39620 802430F0 80630003 */  lb        $v1, 3($v1)
/* C39624 802430F4 14620002 */  bne       $v1, $v0, .L80243100
/* C39628 802430F8 24020001 */   addiu    $v0, $zero, 1
/* C3962C 802430FC AC820084 */  sw        $v0, 0x84($a0)
.L80243100:
/* C39630 80243100 03E00008 */  jr        $ra
/* C39634 80243104 24020002 */   addiu    $v0, $zero, 2
/* C39638 80243108 00000000 */  nop       
/* C3963C 8024310C 00000000 */  nop       
