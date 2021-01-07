.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219998_448DD8
/* 448DD8 80219998 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 448DDC 8021999C 240403D4 */  addiu     $a0, $zero, 0x3d4
/* 448DE0 802199A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 448DE4 802199A4 0C046EDD */  jal       set_world_fog_dist
/* 448DE8 802199A8 240503E8 */   addiu    $a1, $zero, 0x3e8
/* 448DEC 802199AC 2404000F */  addiu     $a0, $zero, 0xf
/* 448DF0 802199B0 24050005 */  addiu     $a1, $zero, 5
/* 448DF4 802199B4 24060037 */  addiu     $a2, $zero, 0x37
/* 448DF8 802199B8 0C046EE2 */  jal       set_world_fog_color
/* 448DFC 802199BC 240700FF */   addiu    $a3, $zero, 0xff
/* 448E00 802199C0 0C046ED4 */  jal       enable_world_fog
/* 448E04 802199C4 00000000 */   nop      
/* 448E08 802199C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 448E0C 802199CC 24020002 */  addiu     $v0, $zero, 2
/* 448E10 802199D0 03E00008 */  jr        $ra
/* 448E14 802199D4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 448E18 802199D8 00000000 */  nop       
/* 448E1C 802199DC 00000000 */  nop       
