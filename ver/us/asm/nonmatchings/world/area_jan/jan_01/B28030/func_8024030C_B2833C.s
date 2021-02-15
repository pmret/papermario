.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_B2833C
/* B2833C 8024030C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B28340 80240310 0000202D */  daddu     $a0, $zero, $zero
/* B28344 80240314 0080282D */  daddu     $a1, $a0, $zero
/* B28348 80240318 0080302D */  daddu     $a2, $a0, $zero
/* B2834C 8024031C 0080382D */  daddu     $a3, $a0, $zero
/* B28350 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* B28354 80240324 AFA00010 */  sw        $zero, 0x10($sp)
/* B28358 80240328 0C01CA54 */  jal       func_80072950
/* B2835C 8024032C AFA00014 */   sw       $zero, 0x14($sp)
/* B28360 80240330 8FBF0018 */  lw        $ra, 0x18($sp)
/* B28364 80240334 24020002 */  addiu     $v0, $zero, 2
/* B28368 80240338 03E00008 */  jr        $ra
/* B2836C 8024033C 27BD0020 */   addiu    $sp, $sp, 0x20
