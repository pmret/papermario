.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_8DA33C
/* 8DA33C 8024023C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8DA340 80240240 240403D4 */  addiu     $a0, $zero, 0x3d4
/* 8DA344 80240244 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8DA348 80240248 0C046EDD */  jal       set_world_fog_dist
/* 8DA34C 8024024C 240503E8 */   addiu    $a1, $zero, 0x3e8
/* 8DA350 80240250 2404000F */  addiu     $a0, $zero, 0xf
/* 8DA354 80240254 24050005 */  addiu     $a1, $zero, 5
/* 8DA358 80240258 24060037 */  addiu     $a2, $zero, 0x37
/* 8DA35C 8024025C 0C046EE2 */  jal       set_world_fog_color
/* 8DA360 80240260 240700FF */   addiu    $a3, $zero, 0xff
/* 8DA364 80240264 0C046ED4 */  jal       enable_world_fog
/* 8DA368 80240268 00000000 */   nop
/* 8DA36C 8024026C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8DA370 80240270 24020002 */  addiu     $v0, $zero, 2
/* 8DA374 80240274 03E00008 */  jr        $ra
/* 8DA378 80240278 27BD0018 */   addiu    $sp, $sp, 0x18
