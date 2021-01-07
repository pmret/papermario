.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802199E0_448E20
/* 448E20 802199E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 448E24 802199E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 448E28 802199E8 0C046ED4 */  jal       enable_world_fog
/* 448E2C 802199EC 00000000 */   nop      
/* 448E30 802199F0 240403B6 */  addiu     $a0, $zero, 0x3b6
/* 448E34 802199F4 0C046EDD */  jal       set_world_fog_dist
/* 448E38 802199F8 240503E8 */   addiu    $a1, $zero, 0x3e8
/* 448E3C 802199FC 24040010 */  addiu     $a0, $zero, 0x10
/* 448E40 80219A00 0080282D */  daddu     $a1, $a0, $zero
/* 448E44 80219A04 0080302D */  daddu     $a2, $a0, $zero
/* 448E48 80219A08 0C046EE2 */  jal       set_world_fog_color
/* 448E4C 80219A0C 240700FF */   addiu    $a3, $zero, 0xff
/* 448E50 80219A10 3C02800B */  lui       $v0, %hi(gCameras)
/* 448E54 80219A14 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 448E58 80219A18 24030014 */  addiu     $v1, $zero, 0x14
/* 448E5C 80219A1C A4430584 */  sh        $v1, 0x584($v0)
/* 448E60 80219A20 A4430586 */  sh        $v1, 0x586($v0)
/* 448E64 80219A24 2403001C */  addiu     $v1, $zero, 0x1c
/* 448E68 80219A28 A4430588 */  sh        $v1, 0x588($v0)
/* 448E6C 80219A2C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 448E70 80219A30 24020002 */  addiu     $v0, $zero, 2
/* 448E74 80219A34 03E00008 */  jr        $ra
/* 448E78 80219A38 27BD0018 */   addiu    $sp, $sp, 0x18
/* 448E7C 80219A3C 00000000 */  nop       
