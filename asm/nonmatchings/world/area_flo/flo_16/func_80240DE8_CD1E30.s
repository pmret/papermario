.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DE8_CD2C18
/* CD2C18 80240DE8 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* CD2C1C 80240DEC 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* CD2C20 80240DF0 AC800084 */  sw        $zero, 0x84($a0)
/* CD2C24 80240DF4 80620000 */  lb        $v0, ($v1)
/* CD2C28 80240DF8 10400005 */  beqz      $v0, .L80240E10
/* CD2C2C 80240DFC 24020003 */   addiu    $v0, $zero, 3
/* CD2C30 80240E00 80630003 */  lb        $v1, 3($v1)
/* CD2C34 80240E04 14620002 */  bne       $v1, $v0, .L80240E10
/* CD2C38 80240E08 24020001 */   addiu    $v0, $zero, 1
/* CD2C3C 80240E0C AC820084 */  sw        $v0, 0x84($a0)
.L80240E10:
/* CD2C40 80240E10 03E00008 */  jr        $ra
/* CD2C44 80240E14 24020002 */   addiu    $v0, $zero, 2
