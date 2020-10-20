.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024072C_D3ACFC
/* D3ACFC 8024072C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D3AD00 80240730 8C42EFC8 */  lw        $v0, %lo(gPlayerStatus)($v0)
/* D3AD04 80240734 30423000 */  andi      $v0, $v0, 0x3000
/* D3AD08 80240738 10400003 */  beqz      $v0, .L80240748
/* D3AD0C 8024073C 24020001 */   addiu    $v0, $zero, 1
/* D3AD10 80240740 080901D3 */  j         .L8024074C
/* D3AD14 80240744 AC820084 */   sw       $v0, 0x84($a0)
.L80240748:
/* D3AD18 80240748 AC800084 */  sw        $zero, 0x84($a0)
.L8024074C:
/* D3AD1C 8024074C 03E00008 */  jr        $ra
/* D3AD20 80240750 24020002 */   addiu    $v0, $zero, 2
