.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BBB380
/* BBB380 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBB384 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* BBB388 80240008 0C046ED4 */  jal       enable_world_fog
/* BBB38C 8024000C 00000000 */   nop      
/* BBB390 80240010 240403DE */  addiu     $a0, $zero, 0x3de
/* BBB394 80240014 0C046EDD */  jal       set_world_fog_dist
/* BBB398 80240018 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BBB39C 8024001C 0000202D */  daddu     $a0, $zero, $zero
/* BBB3A0 80240020 24050008 */  addiu     $a1, $zero, 8
/* BBB3A4 80240024 24060018 */  addiu     $a2, $zero, 0x18
/* BBB3A8 80240028 0C046EE2 */  jal       set_world_fog_color
/* BBB3AC 8024002C 240700FF */   addiu    $a3, $zero, 0xff
/* BBB3B0 80240030 3C02800B */  lui       $v0, %hi(gCameras)
/* BBB3B4 80240034 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* BBB3B8 80240038 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* BBB3BC 8024003C 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* BBB3C0 80240040 24030018 */  addiu     $v1, $zero, 0x18
/* BBB3C4 80240044 A443002C */  sh        $v1, 0x2c($v0)
/* BBB3C8 80240048 A443002E */  sh        $v1, 0x2e($v0)
/* BBB3CC 8024004C A4430030 */  sh        $v1, 0x30($v0)
/* BBB3D0 80240050 A480015C */  sh        $zero, 0x15c($a0)
/* BBB3D4 80240054 8FBF0010 */  lw        $ra, 0x10($sp)
/* BBB3D8 80240058 24020002 */  addiu     $v0, $zero, 2
/* BBB3DC 8024005C 03E00008 */  jr        $ra
/* BBB3E0 80240060 27BD0018 */   addiu    $sp, $sp, 0x18
