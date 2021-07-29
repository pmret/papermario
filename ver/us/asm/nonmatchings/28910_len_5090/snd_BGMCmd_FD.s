.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_BGMCmd_FD
/* 2B55C 8005015C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2B560 80050160 AFBF0010 */  sw        $ra, 0x10($sp)
/* 2B564 80050164 8C8600D4 */  lw        $a2, 0xd4($a0)
/* 2B568 80050168 90840234 */  lbu       $a0, 0x234($a0)
/* 2B56C 8005016C 90A5005C */  lbu       $a1, 0x5c($a1)
/* 2B570 80050170 0C01582F */  jal       func_800560BC
/* 2B574 80050174 00063202 */   srl      $a2, $a2, 8
/* 2B578 80050178 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2B57C 8005017C 03E00008 */  jr        $ra
/* 2B580 80050180 27BD0018 */   addiu    $sp, $sp, 0x18
