.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D4DF60
/* D4DF60 80240F20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4DF64 80240F24 240403D4 */  addiu     $a0, $zero, 0x3d4
/* D4DF68 80240F28 AFBF0010 */  sw        $ra, 0x10($sp)
/* D4DF6C 80240F2C 0C046EDD */  jal       set_world_fog_dist
/* D4DF70 80240F30 240503E8 */   addiu    $a1, $zero, 0x3e8
/* D4DF74 80240F34 2404000F */  addiu     $a0, $zero, 0xf
/* D4DF78 80240F38 24050005 */  addiu     $a1, $zero, 5
/* D4DF7C 80240F3C 24060037 */  addiu     $a2, $zero, 0x37
/* D4DF80 80240F40 0C046EE2 */  jal       set_world_fog_color
/* D4DF84 80240F44 240700FF */   addiu    $a3, $zero, 0xff
/* D4DF88 80240F48 0C046ED4 */  jal       enable_world_fog
/* D4DF8C 80240F4C 00000000 */   nop
/* D4DF90 80240F50 8FBF0010 */  lw        $ra, 0x10($sp)
/* D4DF94 80240F54 24020002 */  addiu     $v0, $zero, 2
/* D4DF98 80240F58 03E00008 */  jr        $ra
/* D4DF9C 80240F5C 27BD0018 */   addiu    $sp, $sp, 0x18
