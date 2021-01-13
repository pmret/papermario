.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D08_ECAA08
/* ECAA08 80240D08 3C038011 */  lui       $v1, %hi(D_80117160)
/* ECAA0C 80240D0C 24637160 */  addiu     $v1, $v1, %lo(D_80117160)
/* ECAA10 80240D10 AC800084 */  sw        $zero, 0x84($a0)
/* ECAA14 80240D14 80620000 */  lb        $v0, ($v1)
/* ECAA18 80240D18 10400005 */  beqz      $v0, .L80240D30
/* ECAA1C 80240D1C 24020003 */   addiu    $v0, $zero, 3
/* ECAA20 80240D20 80630003 */  lb        $v1, 3($v1)
/* ECAA24 80240D24 14620002 */  bne       $v1, $v0, .L80240D30
/* ECAA28 80240D28 24020001 */   addiu    $v0, $zero, 1
/* ECAA2C 80240D2C AC820084 */  sw        $v0, 0x84($a0)
.L80240D30:
/* ECAA30 80240D30 03E00008 */  jr        $ra
/* ECAA34 80240D34 24020002 */   addiu    $v0, $zero, 2
/* ECAA38 80240D38 00000000 */  nop
/* ECAA3C 80240D3C 00000000 */  nop
