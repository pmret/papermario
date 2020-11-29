.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240840_A57CF0
/* A57CF0 80240840 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* A57CF4 80240844 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* A57CF8 80240848 24020008 */  addiu     $v0, $zero, 8
/* A57CFC 8024084C 54620003 */  bnel      $v1, $v0, .L8024085C
/* A57D00 80240850 AC8000A8 */   sw       $zero, 0xa8($a0)
/* A57D04 80240854 24020001 */  addiu     $v0, $zero, 1
/* A57D08 80240858 AC8200A8 */  sw        $v0, 0xa8($a0)
.L8024085C:
/* A57D0C 8024085C 03E00008 */  jr        $ra
/* A57D10 80240860 24020002 */   addiu    $v0, $zero, 2
/* A57D14 80240864 00000000 */  nop       
/* A57D18 80240868 00000000 */  nop       
/* A57D1C 8024086C 00000000 */  nop       
