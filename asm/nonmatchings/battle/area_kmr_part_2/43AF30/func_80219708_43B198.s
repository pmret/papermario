.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219708_43B198
/* 43B198 80219708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 43B19C 8021970C 240403D4 */  addiu     $a0, $zero, 0x3d4
/* 43B1A0 80219710 AFBF0010 */  sw        $ra, 0x10($sp)
/* 43B1A4 80219714 0C046EDD */  jal       set_world_fog_dist
/* 43B1A8 80219718 240503E8 */   addiu    $a1, $zero, 0x3e8
/* 43B1AC 8021971C 2404000F */  addiu     $a0, $zero, 0xf
/* 43B1B0 80219720 24050005 */  addiu     $a1, $zero, 5
/* 43B1B4 80219724 24060037 */  addiu     $a2, $zero, 0x37
/* 43B1B8 80219728 0C046EE2 */  jal       set_world_fog_color
/* 43B1BC 8021972C 240700FF */   addiu    $a3, $zero, 0xff
/* 43B1C0 80219730 0C046ED4 */  jal       enable_world_fog
/* 43B1C4 80219734 00000000 */   nop      
/* 43B1C8 80219738 8FBF0010 */  lw        $ra, 0x10($sp)
/* 43B1CC 8021973C 24020002 */  addiu     $v0, $zero, 2
/* 43B1D0 80219740 03E00008 */  jr        $ra
/* 43B1D4 80219744 27BD0018 */   addiu    $sp, $sp, 0x18
/* 43B1D8 80219748 00000000 */  nop       
/* 43B1DC 8021974C 00000000 */  nop       
