.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E0260
/* 079710 800E0260 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 079714 800E0264 AFBF0010 */  sw    $ra, 0x10($sp)
/* 079718 800E0268 0C038196 */  jal   func_800E0658
/* 07971C 800E026C 00000000 */   nop   
/* 079720 800E0270 0C0382B4 */  jal   func_800E0AD0
/* 079724 800E0274 00000000 */   nop   
/* 079728 800E0278 0C038134 */  jal   func_800E04D0
/* 07972C 800E027C 00000000 */   nop   
/* 079730 800E0280 0C0380CC */  jal   func_800E0330
/* 079734 800E0284 00000000 */   nop   
/* 079738 800E0288 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07973C 800E028C 03E00008 */  jr    $ra
/* 079740 800E0290 27BD0018 */   addiu $sp, $sp, 0x18

