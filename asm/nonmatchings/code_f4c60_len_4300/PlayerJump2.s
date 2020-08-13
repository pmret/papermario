.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel PlayerJump2
/* 0F62D0 802D1920 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F62D4 802D1924 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F62D8 802D1928 0C0B4538 */  jal   player_jump
/* 0F62DC 802D192C 24060002 */   addiu $a2, $zero, 2
/* 0F62E0 802D1930 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F62E4 802D1934 03E00008 */  jr    $ra
/* 0F62E8 802D1938 27BD0018 */   addiu $sp, $sp, 0x18

