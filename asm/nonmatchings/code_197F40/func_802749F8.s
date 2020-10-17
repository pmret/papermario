.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802749F8
/* 1A32D8 802749F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A32DC 802749FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A32E0 80274A00 0C095270 */  jal       func_802549C0
/* 1A32E4 80274A04 00000000 */   nop      
/* 1A32E8 80274A08 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A32EC 80274A0C 24020002 */  addiu     $v0, $zero, 2
/* 1A32F0 80274A10 03E00008 */  jr        $ra
/* 1A32F4 80274A14 27BD0018 */   addiu    $sp, $sp, 0x18
