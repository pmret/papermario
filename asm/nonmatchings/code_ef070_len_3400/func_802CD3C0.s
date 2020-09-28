.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD3C0
/* F1D70 802CD3C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F1D74 802CD3C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* F1D78 802CD3C8 AFB00010 */  sw        $s0, 0x10($sp)
/* F1D7C 802CD3CC 8C82000C */  lw        $v0, 0xc($a0)
/* F1D80 802CD3D0 0C0B1EAF */  jal       get_variable
/* F1D84 802CD3D4 8C450000 */   lw       $a1, ($v0)
/* F1D88 802CD3D8 3C03802E */  lui       $v1, 0x802e
/* F1D8C 802CD3DC 8C63AE30 */  lw        $v1, -0x51d0($v1)
/* F1D90 802CD3E0 00021080 */  sll       $v0, $v0, 2
/* F1D94 802CD3E4 00431021 */  addu      $v0, $v0, $v1
/* F1D98 802CD3E8 8C500000 */  lw        $s0, ($v0)
/* F1D9C 802CD3EC 0C047FF8 */  jal       func_8011FFE0
/* F1DA0 802CD3F0 8E040000 */   lw       $a0, ($s0)
/* F1DA4 802CD3F4 0C04790E */  jal       func_8011E438
/* F1DA8 802CD3F8 0040202D */   daddu    $a0, $v0, $zero
/* F1DAC 802CD3FC 2403FFFF */  addiu     $v1, $zero, -1
/* F1DB0 802CD400 AE030000 */  sw        $v1, ($s0)
/* F1DB4 802CD404 8FBF0014 */  lw        $ra, 0x14($sp)
/* F1DB8 802CD408 8FB00010 */  lw        $s0, 0x10($sp)
/* F1DBC 802CD40C 24020002 */  addiu     $v0, $zero, 2
/* F1DC0 802CD410 03E00008 */  jr        $ra
/* F1DC4 802CD414 27BD0018 */   addiu    $sp, $sp, 0x18
