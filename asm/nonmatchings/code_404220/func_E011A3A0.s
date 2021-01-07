.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E011A3A0
/* 4045C0 E011A3A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4045C4 E011A3A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4045C8 E011A3A8 0C0469C0 */  jal       func_E011A700
/* 4045CC E011A3AC 00000000 */   nop      
/* 4045D0 E011A3B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4045D4 E011A3B4 03E00008 */  jr        $ra
/* 4045D8 E011A3B8 27BD0018 */   addiu    $sp, $sp, 0x18
