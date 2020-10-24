.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A6C_BE521C
/* BE521C 80241A6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE5220 80241A70 AFB20018 */  sw        $s2, 0x18($sp)
/* BE5224 80241A74 0080902D */  daddu     $s2, $a0, $zero
/* BE5228 80241A78 AFBF001C */  sw        $ra, 0x1c($sp)
/* BE522C 80241A7C AFB10014 */  sw        $s1, 0x14($sp)
/* BE5230 80241A80 AFB00010 */  sw        $s0, 0x10($sp)
/* BE5234 80241A84 8E510148 */  lw        $s1, 0x148($s2)
/* BE5238 80241A88 0C00EABB */  jal       get_npc_unsafe
/* BE523C 80241A8C 86240008 */   lh       $a0, 8($s1)
/* BE5240 80241A90 0040802D */  daddu     $s0, $v0, $zero
/* BE5244 80241A94 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE5248 80241A98 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE524C 80241A9C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE5250 80241AA0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE5254 80241AA4 A600008E */  sh        $zero, 0x8e($s0)
/* BE5258 80241AA8 8C460028 */  lw        $a2, 0x28($v0)
/* BE525C 80241AAC 0C00A720 */  jal       atan2
/* BE5260 80241AB0 8C470030 */   lw       $a3, 0x30($v0)
/* BE5264 80241AB4 E600000C */  swc1      $f0, 0xc($s0)
/* BE5268 80241AB8 8E2200CC */  lw        $v0, 0xcc($s1)
/* BE526C 80241ABC 8C420020 */  lw        $v0, 0x20($v0)
/* BE5270 80241AC0 AE020028 */  sw        $v0, 0x28($s0)
/* BE5274 80241AC4 2402000B */  addiu     $v0, $zero, 0xb
/* BE5278 80241AC8 AE420070 */  sw        $v0, 0x70($s2)
/* BE527C 80241ACC 8FBF001C */  lw        $ra, 0x1c($sp)
/* BE5280 80241AD0 8FB20018 */  lw        $s2, 0x18($sp)
/* BE5284 80241AD4 8FB10014 */  lw        $s1, 0x14($sp)
/* BE5288 80241AD8 8FB00010 */  lw        $s0, 0x10($sp)
/* BE528C 80241ADC 03E00008 */  jr        $ra
/* BE5290 80241AE0 27BD0020 */   addiu    $sp, $sp, 0x20
