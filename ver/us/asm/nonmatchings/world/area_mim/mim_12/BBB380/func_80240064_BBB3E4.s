.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240064_BBB3E4
/* BBB3E4 80240064 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBB3E8 80240068 AFBF0010 */  sw        $ra, 0x10($sp)
/* BBB3EC 8024006C 0C046ED4 */  jal       enable_world_fog
/* BBB3F0 80240070 00000000 */   nop
/* BBB3F4 80240074 240403D4 */  addiu     $a0, $zero, 0x3d4
/* BBB3F8 80240078 0C046EDD */  jal       set_world_fog_dist
/* BBB3FC 8024007C 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BBB400 80240080 0000202D */  daddu     $a0, $zero, $zero
/* BBB404 80240084 24050008 */  addiu     $a1, $zero, 8
/* BBB408 80240088 24060018 */  addiu     $a2, $zero, 0x18
/* BBB40C 8024008C 0C046EE2 */  jal       set_world_fog_color
/* BBB410 80240090 240700FF */   addiu    $a3, $zero, 0xff
/* BBB414 80240094 3C03800B */  lui       $v1, %hi(gCameras)
/* BBB418 80240098 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* BBB41C 8024009C 24020018 */  addiu     $v0, $zero, 0x18
/* BBB420 802400A0 A462002C */  sh        $v0, 0x2c($v1)
/* BBB424 802400A4 A462002E */  sh        $v0, 0x2e($v1)
/* BBB428 802400A8 A4620030 */  sh        $v0, 0x30($v1)
/* BBB42C 802400AC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* BBB430 802400B0 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* BBB434 802400B4 240200E8 */  addiu     $v0, $zero, 0xe8
/* BBB438 802400B8 A462015C */  sh        $v0, 0x15c($v1)
/* BBB43C 802400BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* BBB440 802400C0 24020002 */  addiu     $v0, $zero, 2
/* BBB444 802400C4 03E00008 */  jr        $ra
/* BBB448 802400C8 27BD0018 */   addiu    $sp, $sp, 0x18
