.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242940_CD4770
/* CD4770 80242940 AC800084 */  sw        $zero, 0x84($a0)
/* CD4774 80242944 3C038011 */  lui       $v1, %hi(gPlayerActionState)
/* CD4778 80242948 8063F07C */  lb        $v1, %lo(gPlayerActionState)($v1)
/* CD477C 8024294C 2402000E */  addiu     $v0, $zero, 0xe
/* CD4780 80242950 10620004 */  beq       $v1, $v0, .L80242964
/* CD4784 80242954 24020001 */   addiu    $v0, $zero, 1
/* CD4788 80242958 24020010 */  addiu     $v0, $zero, 0x10
/* CD478C 8024295C 14620002 */  bne       $v1, $v0, .L80242968
/* CD4790 80242960 24020001 */   addiu    $v0, $zero, 1
.L80242964:
/* CD4794 80242964 AC820084 */  sw        $v0, 0x84($a0)
.L80242968:
/* CD4798 80242968 03E00008 */  jr        $ra
/* CD479C 8024296C 24020002 */   addiu    $v0, $zero, 2
