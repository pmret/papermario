.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osSiRelAccess
/* 041230 80065E30 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 041234 80065E34 AFBF0010 */  sw    $ra, 0x10($sp)
/* 041238 80065E38 3C04800E */  lui   $a0, 0x800e
/* 04123C 80065E3C 2484ACA8 */  addiu $a0, $a0, -0x5358
/* 041240 80065E40 00002821 */  addu  $a1, $zero, $zero
/* 041244 80065E44 0C019608 */  jal   osSendMesg
/* 041248 80065E48 00003021 */   addu  $a2, $zero, $zero
/* 04124C 80065E4C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 041250 80065E50 03E00008 */  jr    $ra
/* 041254 80065E54 27BD0018 */   addiu $sp, $sp, 0x18

/* 041258 80065E58 00000000 */  nop   
/* 04125C 80065E5C 00000000 */  nop   


