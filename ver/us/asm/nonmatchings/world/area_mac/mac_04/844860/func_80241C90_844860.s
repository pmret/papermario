.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C90_844860
/* 844860 80241C90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 844864 80241C94 AFB00010 */  sw        $s0, 0x10($sp)
/* 844868 80241C98 0080802D */  daddu     $s0, $a0, $zero
/* 84486C 80241C9C 0000202D */  daddu     $a0, $zero, $zero
/* 844870 80241CA0 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 844874 80241CA4 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 844878 80241CA8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 84487C 80241CAC 8C620004 */  lw        $v0, 4($v1)
/* 844880 80241CB0 3C058024 */  lui       $a1, %hi(func_80241D30_844900)
/* 844884 80241CB4 24A51D30 */  addiu     $a1, $a1, %lo(func_80241D30_844900)
/* 844888 80241CB8 34422000 */  ori       $v0, $v0, 0x2000
/* 84488C 80241CBC 0C048C56 */  jal       create_generic_entity_world
/* 844890 80241CC0 AC620004 */   sw       $v0, 4($v1)
/* 844894 80241CC4 0200202D */  daddu     $a0, $s0, $zero
/* 844898 80241CC8 3C05FD05 */  lui       $a1, 0xfd05
/* 84489C 80241CCC 34A50F8B */  ori       $a1, $a1, 0xf8b
/* 8448A0 80241CD0 0C0B2026 */  jal       set_variable
/* 8448A4 80241CD4 0040302D */   daddu    $a2, $v0, $zero
/* 8448A8 80241CD8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8448AC 80241CDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 8448B0 80241CE0 24020002 */  addiu     $v0, $zero, 2
/* 8448B4 80241CE4 03E00008 */  jr        $ra
/* 8448B8 80241CE8 27BD0018 */   addiu    $sp, $sp, 0x18
