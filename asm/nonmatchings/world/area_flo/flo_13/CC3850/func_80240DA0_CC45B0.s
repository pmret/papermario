.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA0_CC45B0
/* CC45B0 80240DA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CC45B4 80240DA4 AFB20018 */  sw        $s2, 0x18($sp)
/* CC45B8 80240DA8 0080902D */  daddu     $s2, $a0, $zero
/* CC45BC 80240DAC AFBF001C */  sw        $ra, 0x1c($sp)
/* CC45C0 80240DB0 AFB10014 */  sw        $s1, 0x14($sp)
/* CC45C4 80240DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* CC45C8 80240DB8 8E510148 */  lw        $s1, 0x148($s2)
/* CC45CC 80240DBC 0C00EABB */  jal       get_npc_unsafe
/* CC45D0 80240DC0 86240008 */   lh       $a0, 8($s1)
/* CC45D4 80240DC4 0040802D */  daddu     $s0, $v0, $zero
/* CC45D8 80240DC8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CC45DC 80240DCC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CC45E0 80240DD0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CC45E4 80240DD4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CC45E8 80240DD8 A600008E */  sh        $zero, 0x8e($s0)
/* CC45EC 80240DDC 8C460028 */  lw        $a2, 0x28($v0)
/* CC45F0 80240DE0 0C00A720 */  jal       atan2
/* CC45F4 80240DE4 8C470030 */   lw       $a3, 0x30($v0)
/* CC45F8 80240DE8 E600000C */  swc1      $f0, 0xc($s0)
/* CC45FC 80240DEC 8E2200CC */  lw        $v0, 0xcc($s1)
/* CC4600 80240DF0 8C420020 */  lw        $v0, 0x20($v0)
/* CC4604 80240DF4 AE020028 */  sw        $v0, 0x28($s0)
/* CC4608 80240DF8 2402000B */  addiu     $v0, $zero, 0xb
/* CC460C 80240DFC AE420070 */  sw        $v0, 0x70($s2)
/* CC4610 80240E00 8FBF001C */  lw        $ra, 0x1c($sp)
/* CC4614 80240E04 8FB20018 */  lw        $s2, 0x18($sp)
/* CC4618 80240E08 8FB10014 */  lw        $s1, 0x14($sp)
/* CC461C 80240E0C 8FB00010 */  lw        $s0, 0x10($sp)
/* CC4620 80240E10 03E00008 */  jr        $ra
/* CC4624 80240E14 27BD0020 */   addiu    $sp, $sp, 0x20
