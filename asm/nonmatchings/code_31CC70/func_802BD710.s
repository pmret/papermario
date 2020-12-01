.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD710
/* 31D280 802BD710 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31D284 802BD714 3C058011 */  lui       $a1, %hi(D_8010C954)
/* 31D288 802BD718 24A5C954 */  addiu     $a1, $a1, %lo(D_8010C954)
/* 31D28C 802BD71C AFBF0010 */  sw        $ra, 0x10($sp)
/* 31D290 802BD720 8CA20000 */  lw        $v0, ($a1)
/* 31D294 802BD724 10400008 */  beqz      $v0, .L802BD748
/* 31D298 802BD728 00000000 */   nop      
/* 31D29C 802BD72C 3C03802C */  lui       $v1, %hi(D_802BE274)
/* 31D2A0 802BD730 8C63E274 */  lw        $v1, %lo(D_802BE274)($v1)
/* 31D2A4 802BD734 8C620008 */  lw        $v0, 8($v1)
/* 31D2A8 802BD738 ACA00000 */  sw        $zero, ($a1)
/* 31D2AC 802BD73C AC820000 */  sw        $v0, ($a0)
/* 31D2B0 802BD740 0C03BD17 */  jal       clear_partner_move_history
/* 31D2B4 802BD744 AC600004 */   sw       $zero, 4($v1)
.L802BD748:
/* 31D2B8 802BD748 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31D2BC 802BD74C 03E00008 */  jr        $ra
/* 31D2C0 802BD750 27BD0018 */   addiu    $sp, $sp, 0x18
