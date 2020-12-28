.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218360_4F7F40
/* 4F7F40 80218360 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4F7F44 80218364 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4F7F48 80218368 0C046ED4 */  jal       enable_world_fog
/* 4F7F4C 8021836C 00000000 */   nop      
/* 4F7F50 80218370 240403B6 */  addiu     $a0, $zero, 0x3b6
/* 4F7F54 80218374 0C046EDD */  jal       set_world_fog_dist
/* 4F7F58 80218378 240503E8 */   addiu    $a1, $zero, 0x3e8
/* 4F7F5C 8021837C 24040010 */  addiu     $a0, $zero, 0x10
/* 4F7F60 80218380 0080282D */  daddu     $a1, $a0, $zero
/* 4F7F64 80218384 0080302D */  daddu     $a2, $a0, $zero
/* 4F7F68 80218388 0C046EE2 */  jal       set_world_fog_color
/* 4F7F6C 8021838C 240700FF */   addiu    $a3, $zero, 0xff
/* 4F7F70 80218390 3C02800B */  lui       $v0, %hi(gCameras)
/* 4F7F74 80218394 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 4F7F78 80218398 24030014 */  addiu     $v1, $zero, 0x14
/* 4F7F7C 8021839C A4430584 */  sh        $v1, 0x584($v0)
/* 4F7F80 802183A0 A4430586 */  sh        $v1, 0x586($v0)
/* 4F7F84 802183A4 2403001C */  addiu     $v1, $zero, 0x1c
/* 4F7F88 802183A8 A4430588 */  sh        $v1, 0x588($v0)
/* 4F7F8C 802183AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4F7F90 802183B0 24020002 */  addiu     $v0, $zero, 2
/* 4F7F94 802183B4 03E00008 */  jr        $ra
/* 4F7F98 802183B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4F7F9C 802183BC 00000000 */  nop       
