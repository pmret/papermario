.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412BC_BD4B2C
/* BD4B2C 802412BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD4B30 802412C0 AFB00010 */  sw        $s0, 0x10($sp)
/* BD4B34 802412C4 0080802D */  daddu     $s0, $a0, $zero
/* BD4B38 802412C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD4B3C 802412CC 8E020084 */  lw        $v0, 0x84($s0)
/* BD4B40 802412D0 2442FFFE */  addiu     $v0, $v0, -2
/* BD4B44 802412D4 44826000 */  mtc1      $v0, $f12
/* BD4B48 802412D8 00000000 */  nop
/* BD4B4C 802412DC 0C00A6C9 */  jal       clamp_angle
/* BD4B50 802412E0 46806320 */   cvt.s.w  $f12, $f12
/* BD4B54 802412E4 4600008D */  trunc.w.s $f2, $f0
/* BD4B58 802412E8 E6020084 */  swc1      $f2, 0x84($s0)
/* BD4B5C 802412EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD4B60 802412F0 8FB00010 */  lw        $s0, 0x10($sp)
/* BD4B64 802412F4 24020002 */  addiu     $v0, $zero, 2
/* BD4B68 802412F8 03E00008 */  jr        $ra
/* BD4B6C 802412FC 27BD0018 */   addiu    $sp, $sp, 0x18
