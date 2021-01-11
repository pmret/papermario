.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DE8_EEDEE8
/* EEDEE8 80240DE8 3C038011 */  lui       $v1, %hi(D_80117160)
/* EEDEEC 80240DEC 24637160 */  addiu     $v1, $v1, %lo(D_80117160)
/* EEDEF0 80240DF0 AC800084 */  sw        $zero, 0x84($a0)
/* EEDEF4 80240DF4 80620000 */  lb        $v0, ($v1)
/* EEDEF8 80240DF8 10400005 */  beqz      $v0, .L80240E10
/* EEDEFC 80240DFC 24020003 */   addiu    $v0, $zero, 3
/* EEDF00 80240E00 80630003 */  lb        $v1, 3($v1)
/* EEDF04 80240E04 14620002 */  bne       $v1, $v0, .L80240E10
/* EEDF08 80240E08 24020001 */   addiu    $v0, $zero, 1
/* EEDF0C 80240E0C AC820084 */  sw        $v0, 0x84($a0)
.L80240E10:
/* EEDF10 80240E10 03E00008 */  jr        $ra
/* EEDF14 80240E14 24020002 */   addiu    $v0, $zero, 2
