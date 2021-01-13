.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80137E10
/* CE510 80137E10 28820002 */  slti      $v0, $a0, 2
/* CE514 80137E14 1040000B */  beqz      $v0, .L80137E44
/* CE518 80137E18 00000000 */   nop
/* CE51C 80137E1C 04800009 */  bltz      $a0, .L80137E44
/* CE520 80137E20 00041040 */   sll      $v0, $a0, 1
/* CE524 80137E24 3C038016 */  lui       $v1, %hi(D_8015C790)
/* CE528 80137E28 2463C790 */  addiu     $v1, $v1, %lo(D_8015C790)
/* CE52C 80137E2C 00441021 */  addu      $v0, $v0, $a0
/* CE530 80137E30 000210C0 */  sll       $v0, $v0, 3
/* CE534 80137E34 00431021 */  addu      $v0, $v0, $v1
/* CE538 80137E38 A0450000 */  sb        $a1, ($v0)
/* CE53C 80137E3C A0460001 */  sb        $a2, 1($v0)
/* CE540 80137E40 A0470002 */  sb        $a3, 2($v0)
.L80137E44:
/* CE544 80137E44 03E00008 */  jr        $ra
/* CE548 80137E48 00000000 */   nop
