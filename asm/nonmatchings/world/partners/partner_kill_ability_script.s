.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_kill_ability_script
/* 84C7C 800EB7CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 84C80 800EB7D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 84C84 800EB7D4 3C108011 */  lui       $s0, %hi(D_8010CFDC)
/* 84C88 800EB7D8 2610CFDC */  addiu     $s0, $s0, %lo(D_8010CFDC)
/* 84C8C 800EB7DC AFBF0014 */  sw        $ra, 0x14($sp)
/* 84C90 800EB7E0 8E040000 */  lw        $a0, ($s0)
/* 84C94 800EB7E4 2402000A */  addiu     $v0, $zero, 0xa
/* 84C98 800EB7E8 3C018011 */  lui       $at, %hi(D_8010CFE8)
/* 84C9C 800EB7EC AC22CFE8 */  sw        $v0, %lo(D_8010CFE8)($at)
/* 84CA0 800EB7F0 0C0B1059 */  jal       does_script_exist
/* 84CA4 800EB7F4 00000000 */   nop
/* 84CA8 800EB7F8 10400003 */  beqz      $v0, .L800EB808
/* 84CAC 800EB7FC 00000000 */   nop
/* 84CB0 800EB800 0C0B102B */  jal       kill_script_by_ID
/* 84CB4 800EB804 8E040000 */   lw       $a0, ($s0)
.L800EB808:
/* 84CB8 800EB808 8FBF0014 */  lw        $ra, 0x14($sp)
/* 84CBC 800EB80C 8FB00010 */  lw        $s0, 0x10($sp)
/* 84CC0 800EB810 03E00008 */  jr        $ra
/* 84CC4 800EB814 27BD0018 */   addiu    $sp, $sp, 0x18
