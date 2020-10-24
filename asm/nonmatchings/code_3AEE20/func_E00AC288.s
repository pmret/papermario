.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00AC288
/* 3AF0A8 E00AC288 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3AF0AC E00AC28C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3AF0B0 E00AC290 0C02B0A9 */  jal       func_E00AC2A4
/* 3AF0B4 E00AC294 00000000 */   nop      
/* 3AF0B8 E00AC298 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3AF0BC E00AC29C 03E00008 */  jr        $ra
/* 3AF0C0 E00AC2A0 27BD0018 */   addiu    $sp, $sp, 0x18
