.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BCC_A17DEC
/* A17DEC 80241BCC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A17DF0 80241BD0 AFB20018 */  sw        $s2, 0x18($sp)
/* A17DF4 80241BD4 0080902D */  daddu     $s2, $a0, $zero
/* A17DF8 80241BD8 AFBF001C */  sw        $ra, 0x1c($sp)
/* A17DFC 80241BDC AFB10014 */  sw        $s1, 0x14($sp)
/* A17E00 80241BE0 AFB00010 */  sw        $s0, 0x10($sp)
/* A17E04 80241BE4 8E510148 */  lw        $s1, 0x148($s2)
/* A17E08 80241BE8 0C00EABB */  jal       get_npc_unsafe
/* A17E0C 80241BEC 86240008 */   lh       $a0, 8($s1)
/* A17E10 80241BF0 0040802D */  daddu     $s0, $v0, $zero
/* A17E14 80241BF4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A17E18 80241BF8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A17E1C 80241BFC C60C0038 */  lwc1      $f12, 0x38($s0)
/* A17E20 80241C00 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A17E24 80241C04 A600008E */  sh        $zero, 0x8e($s0)
/* A17E28 80241C08 8C460028 */  lw        $a2, 0x28($v0)
/* A17E2C 80241C0C 0C00A720 */  jal       atan2
/* A17E30 80241C10 8C470030 */   lw       $a3, 0x30($v0)
/* A17E34 80241C14 E600000C */  swc1      $f0, 0xc($s0)
/* A17E38 80241C18 8E2200CC */  lw        $v0, 0xcc($s1)
/* A17E3C 80241C1C 8C420020 */  lw        $v0, 0x20($v0)
/* A17E40 80241C20 AE020028 */  sw        $v0, 0x28($s0)
/* A17E44 80241C24 2402000B */  addiu     $v0, $zero, 0xb
/* A17E48 80241C28 AE420070 */  sw        $v0, 0x70($s2)
/* A17E4C 80241C2C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A17E50 80241C30 8FB20018 */  lw        $s2, 0x18($sp)
/* A17E54 80241C34 8FB10014 */  lw        $s1, 0x14($sp)
/* A17E58 80241C38 8FB00010 */  lw        $s0, 0x10($sp)
/* A17E5C 80241C3C 03E00008 */  jr        $ra
/* A17E60 80241C40 27BD0020 */   addiu    $sp, $sp, 0x20
