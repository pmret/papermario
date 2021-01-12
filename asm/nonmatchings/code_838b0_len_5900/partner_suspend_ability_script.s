.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_suspend_ability_script
/* 84CC8 800EB818 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 84CCC 800EB81C 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 84CD0 800EB820 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 84CD4 800EB824 AFBF0014 */  sw        $ra, 0x14($sp)
/* 84CD8 800EB828 10400009 */  beqz      $v0, .L800EB850
/* 84CDC 800EB82C AFB00010 */   sw       $s0, 0x10($sp)
/* 84CE0 800EB830 3C108011 */  lui       $s0, %hi(D_8010CFDC)
/* 84CE4 800EB834 2610CFDC */  addiu     $s0, $s0, %lo(D_8010CFDC)
/* 84CE8 800EB838 0C0B1059 */  jal       does_script_exist
/* 84CEC 800EB83C 8E040000 */   lw       $a0, ($s0)
/* 84CF0 800EB840 10400003 */  beqz      $v0, .L800EB850
/* 84CF4 800EB844 00000000 */   nop
/* 84CF8 800EB848 0C0B1108 */  jal       suspend_all_script
/* 84CFC 800EB84C 8E040000 */   lw       $a0, ($s0)
.L800EB850:
/* 84D00 800EB850 8FBF0014 */  lw        $ra, 0x14($sp)
/* 84D04 800EB854 8FB00010 */  lw        $s0, 0x10($sp)
/* 84D08 800EB858 03E00008 */  jr        $ra
/* 84D0C 800EB85C 27BD0018 */   addiu    $sp, $sp, 0x18
