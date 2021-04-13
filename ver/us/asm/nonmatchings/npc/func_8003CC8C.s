.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003CC8C
/* 1808C 8003CC8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18090 8003CC90 00052880 */  sll       $a1, $a1, 2
/* 18094 8003CC94 00852021 */  addu      $a0, $a0, $a1
/* 18098 8003CC98 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1809C 8003CC9C 0C016914 */  jal       remove_effect
/* 180A0 8003CCA0 8C840324 */   lw       $a0, 0x324($a0)
/* 180A4 8003CCA4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 180A8 8003CCA8 03E00008 */  jr        $ra
/* 180AC 8003CCAC 27BD0018 */   addiu    $sp, $sp, 0x18
