.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CA0_BC8B00
/* BC8B00 80240CA0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC8B04 80240CA4 AFB00010 */  sw        $s0, 0x10($sp)
/* BC8B08 80240CA8 0080802D */  daddu     $s0, $a0, $zero
/* BC8B0C 80240CAC 0000202D */  daddu     $a0, $zero, $zero
/* BC8B10 80240CB0 3C05FD05 */  lui       $a1, 0xfd05
/* BC8B14 80240CB4 AFBF0014 */  sw        $ra, 0x14($sp)
/* BC8B18 80240CB8 0C0B1EAF */  jal       evt_get_variable
/* BC8B1C 80240CBC 34A50F85 */   ori      $a1, $a1, 0xf85
/* BC8B20 80240CC0 0C00EABB */  jal       get_npc_unsafe
/* BC8B24 80240CC4 0040202D */   daddu    $a0, $v0, $zero
/* BC8B28 80240CC8 C4400038 */  lwc1      $f0, 0x38($v0)
/* BC8B2C 80240CCC 4600008D */  trunc.w.s $f2, $f0
/* BC8B30 80240CD0 E6020084 */  swc1      $f2, 0x84($s0)
/* BC8B34 80240CD4 C440003C */  lwc1      $f0, 0x3c($v0)
/* BC8B38 80240CD8 4600008D */  trunc.w.s $f2, $f0
/* BC8B3C 80240CDC E6020088 */  swc1      $f2, 0x88($s0)
/* BC8B40 80240CE0 C4400040 */  lwc1      $f0, 0x40($v0)
/* BC8B44 80240CE4 4600008D */  trunc.w.s $f2, $f0
/* BC8B48 80240CE8 E602008C */  swc1      $f2, 0x8c($s0)
/* BC8B4C 80240CEC 8FBF0014 */  lw        $ra, 0x14($sp)
/* BC8B50 80240CF0 8FB00010 */  lw        $s0, 0x10($sp)
/* BC8B54 80240CF4 24020002 */  addiu     $v0, $zero, 2
/* BC8B58 80240CF8 03E00008 */  jr        $ra
/* BC8B5C 80240CFC 27BD0018 */   addiu    $sp, $sp, 0x18
