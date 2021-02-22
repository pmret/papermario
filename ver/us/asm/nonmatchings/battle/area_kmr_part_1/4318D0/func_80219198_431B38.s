.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219198_431B38
/* 431B38 80219198 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 431B3C 8021919C 240403D4 */  addiu     $a0, $zero, 0x3d4
/* 431B40 802191A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 431B44 802191A4 0C046EDD */  jal       set_world_fog_dist
/* 431B48 802191A8 240503E8 */   addiu    $a1, $zero, 0x3e8
/* 431B4C 802191AC 2404000F */  addiu     $a0, $zero, 0xf
/* 431B50 802191B0 24050005 */  addiu     $a1, $zero, 5
/* 431B54 802191B4 24060037 */  addiu     $a2, $zero, 0x37
/* 431B58 802191B8 0C046EE2 */  jal       set_world_fog_color
/* 431B5C 802191BC 240700FF */   addiu    $a3, $zero, 0xff
/* 431B60 802191C0 0C046ED4 */  jal       enable_world_fog
/* 431B64 802191C4 00000000 */   nop
/* 431B68 802191C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 431B6C 802191CC 24020002 */  addiu     $v0, $zero, 2
/* 431B70 802191D0 03E00008 */  jr        $ra
/* 431B74 802191D4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 431B78 802191D8 00000000 */  nop
/* 431B7C 802191DC 00000000 */  nop
