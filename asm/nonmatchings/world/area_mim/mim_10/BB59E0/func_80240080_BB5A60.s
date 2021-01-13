.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240080_BB5A60
/* BB5A60 80240080 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB5A64 80240084 AFBF0010 */  sw        $ra, 0x10($sp)
/* BB5A68 80240088 0C046ED4 */  jal       enable_world_fog
/* BB5A6C 8024008C 00000000 */   nop
/* BB5A70 80240090 240403DE */  addiu     $a0, $zero, 0x3de
/* BB5A74 80240094 0C046EDD */  jal       set_world_fog_dist
/* BB5A78 80240098 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BB5A7C 8024009C 24040010 */  addiu     $a0, $zero, 0x10
/* BB5A80 802400A0 0080282D */  daddu     $a1, $a0, $zero
/* BB5A84 802400A4 0080302D */  daddu     $a2, $a0, $zero
/* BB5A88 802400A8 0C046EE2 */  jal       set_world_fog_color
/* BB5A8C 802400AC 240700FF */   addiu    $a3, $zero, 0xff
/* BB5A90 802400B0 3C03800B */  lui       $v1, %hi(gCameras)
/* BB5A94 802400B4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* BB5A98 802400B8 24020014 */  addiu     $v0, $zero, 0x14
/* BB5A9C 802400BC A462002C */  sh        $v0, 0x2c($v1)
/* BB5AA0 802400C0 A462002E */  sh        $v0, 0x2e($v1)
/* BB5AA4 802400C4 2402001C */  addiu     $v0, $zero, 0x1c
/* BB5AA8 802400C8 A4620030 */  sh        $v0, 0x30($v1)
/* BB5AAC 802400CC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* BB5AB0 802400D0 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* BB5AB4 802400D4 240200F0 */  addiu     $v0, $zero, 0xf0
/* BB5AB8 802400D8 A462015C */  sh        $v0, 0x15c($v1)
/* BB5ABC 802400DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* BB5AC0 802400E0 24020002 */  addiu     $v0, $zero, 2
/* BB5AC4 802400E4 03E00008 */  jr        $ra
/* BB5AC8 802400E8 27BD0018 */   addiu    $sp, $sp, 0x18
