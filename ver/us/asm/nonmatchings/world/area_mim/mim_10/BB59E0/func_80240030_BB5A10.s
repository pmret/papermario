.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240030_BB5A10
/* BB5A10 80240030 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB5A14 80240034 AFBF0010 */  sw        $ra, 0x10($sp)
/* BB5A18 80240038 0C046ED4 */  jal       enable_world_fog
/* BB5A1C 8024003C 00000000 */   nop
/* BB5A20 80240040 24040010 */  addiu     $a0, $zero, 0x10
/* BB5A24 80240044 0080282D */  daddu     $a1, $a0, $zero
/* BB5A28 80240048 0080302D */  daddu     $a2, $a0, $zero
/* BB5A2C 8024004C 0C046EE2 */  jal       set_world_fog_color
/* BB5A30 80240050 240700FF */   addiu    $a3, $zero, 0xff
/* BB5A34 80240054 3C02800B */  lui       $v0, %hi(gCameras)
/* BB5A38 80240058 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* BB5A3C 8024005C 24030014 */  addiu     $v1, $zero, 0x14
/* BB5A40 80240060 A443002C */  sh        $v1, 0x2c($v0)
/* BB5A44 80240064 A443002E */  sh        $v1, 0x2e($v0)
/* BB5A48 80240068 2403001C */  addiu     $v1, $zero, 0x1c
/* BB5A4C 8024006C A4430030 */  sh        $v1, 0x30($v0)
/* BB5A50 80240070 8FBF0010 */  lw        $ra, 0x10($sp)
/* BB5A54 80240074 24020002 */  addiu     $v0, $zero, 2
/* BB5A58 80240078 03E00008 */  jr        $ra
/* BB5A5C 8024007C 27BD0018 */   addiu    $sp, $sp, 0x18
