.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A10_4E3150
/* 4E3150 80218A10 3C048022 */  lui       $a0, %hi(D_80224D70)
/* 4E3154 80218A14 8C844D70 */  lw        $a0, %lo(D_80224D70)($a0)
/* 4E3158 80218A18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4E315C 80218A1C AFBF0010 */  sw        $ra, 0x10($sp)
/* 4E3160 80218A20 0C016914 */  jal       remove_effect
/* 4E3164 80218A24 00000000 */   nop      
/* 4E3168 80218A28 3C048022 */  lui       $a0, %hi(D_80224D74)
/* 4E316C 80218A2C 8C844D74 */  lw        $a0, %lo(D_80224D74)($a0)
/* 4E3170 80218A30 0C016914 */  jal       remove_effect
/* 4E3174 80218A34 00000000 */   nop      
/* 4E3178 80218A38 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E317C 80218A3C 24020002 */  addiu     $v0, $zero, 2
/* 4E3180 80218A40 03E00008 */  jr        $ra
/* 4E3184 80218A44 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4E3188 80218A48 00000000 */  nop       
/* 4E318C 80218A4C 00000000 */  nop       
