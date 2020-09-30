.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0260
/* 79710 800E0260 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79714 800E0264 AFBF0010 */  sw        $ra, 0x10($sp)
/* 79718 800E0268 0C038196 */  jal       func_800E0658
/* 7971C 800E026C 00000000 */   nop      
/* 79720 800E0270 0C0382B4 */  jal       func_800E0AD0
/* 79724 800E0274 00000000 */   nop      
/* 79728 800E0278 0C038134 */  jal       func_800E04D0
/* 7972C 800E027C 00000000 */   nop      
/* 79730 800E0280 0C0380CC */  jal       func_800E0330
/* 79734 800E0284 00000000 */   nop      
/* 79738 800E0288 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7973C 800E028C 03E00008 */  jr        $ra
/* 79740 800E0290 27BD0018 */   addiu    $sp, $sp, 0x18
