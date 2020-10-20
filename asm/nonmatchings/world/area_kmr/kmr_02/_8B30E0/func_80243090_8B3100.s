.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243090_8B3100
/* 8B3100 80243090 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B3104 80243094 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B3108 80243098 0C03A631 */  jal       func_800E98C4
/* 8B310C 8024309C 00000000 */   nop      
/* 8B3110 802430A0 0C03A6DB */  jal       sync_status_menu
/* 8B3114 802430A4 00000000 */   nop      
/* 8B3118 802430A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B311C 802430AC 24020002 */  addiu     $v0, $zero, 2
/* 8B3120 802430B0 03E00008 */  jr        $ra
/* 8B3124 802430B4 27BD0018 */   addiu    $sp, $sp, 0x18
