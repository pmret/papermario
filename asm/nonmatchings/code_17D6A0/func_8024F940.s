.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024F940
/* 17E220 8024F940 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17E224 8024F944 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17E228 8024F948 0C093DF2 */  jal       func_8024F7C8
/* 17E22C 8024F94C 00000000 */   nop
/* 17E230 8024F950 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17E234 8024F954 24020002 */  addiu     $v0, $zero, 2
/* 17E238 8024F958 03E00008 */  jr        $ra
/* 17E23C 8024F95C 27BD0018 */   addiu    $sp, $sp, 0x18
