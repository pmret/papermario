.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BF920
/* 320690 802BF920 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 320694 802BF924 3C058011 */  lui       $a1, 0x8011
/* 320698 802BF928 24A5C954 */  addiu     $a1, $a1, -0x36ac
/* 32069C 802BF92C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3206A0 802BF930 8CA20000 */  lw        $v0, ($a1)
/* 3206A4 802BF934 10400008 */  beqz      $v0, .L802BF958
/* 3206A8 802BF938 00000000 */   nop      
/* 3206AC 802BF93C 3C03802C */  lui       $v1, 0x802c
/* 3206B0 802BF940 8C63FDF8 */  lw        $v1, -0x208($v1)
/* 3206B4 802BF944 8C620008 */  lw        $v0, 8($v1)
/* 3206B8 802BF948 ACA00000 */  sw        $zero, ($a1)
/* 3206BC 802BF94C AC820000 */  sw        $v0, ($a0)
/* 3206C0 802BF950 0C03BD17 */  jal       clear_partner_move_history
/* 3206C4 802BF954 AC600004 */   sw       $zero, 4($v1)
.L802BF958:
/* 3206C8 802BF958 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3206CC 802BF95C 03E00008 */  jr        $ra
/* 3206D0 802BF960 27BD0018 */   addiu    $sp, $sp, 0x18
