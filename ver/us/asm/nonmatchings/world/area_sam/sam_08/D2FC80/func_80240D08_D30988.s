.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D08_D30988
/* D30988 80240D08 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* D3098C 80240D0C 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* D30990 80240D10 AC800084 */  sw        $zero, 0x84($a0)
/* D30994 80240D14 80620000 */  lb        $v0, ($v1)
/* D30998 80240D18 10400005 */  beqz      $v0, .L80240D30
/* D3099C 80240D1C 24020003 */   addiu    $v0, $zero, 3
/* D309A0 80240D20 80630003 */  lb        $v1, 3($v1)
/* D309A4 80240D24 14620002 */  bne       $v1, $v0, .L80240D30
/* D309A8 80240D28 24020001 */   addiu    $v0, $zero, 1
/* D309AC 80240D2C AC820084 */  sw        $v0, 0x84($a0)
.L80240D30:
/* D309B0 80240D30 03E00008 */  jr        $ra
/* D309B4 80240D34 24020002 */   addiu    $v0, $zero, 2
/* D309B8 80240D38 00000000 */  nop
/* D309BC 80240D3C 00000000 */  nop
