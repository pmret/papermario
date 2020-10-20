.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407F4_9C3104
/* 9C3104 802407F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C3108 802407F8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C310C 802407FC 0C00D77C */  jal       func_80035DF0
/* 9C3110 80240800 2404000A */   addiu    $a0, $zero, 0xa
/* 9C3114 80240804 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C3118 80240808 24020002 */  addiu     $v0, $zero, 2
/* 9C311C 8024080C 03E00008 */  jr        $ra
/* 9C3120 80240810 27BD0018 */   addiu    $sp, $sp, 0x18
/* 9C3124 80240814 00000000 */  nop       
/* 9C3128 80240818 00000000 */  nop       
/* 9C312C 8024081C 00000000 */  nop       
