.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_D86A20
/* D86A20 80240020 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D86A24 80240024 AFBF001C */  sw        $ra, 0x1c($sp)
/* D86A28 80240028 AFB00018 */  sw        $s0, 0x18($sp)
/* D86A2C 8024002C 8C900084 */  lw        $s0, 0x84($a0)
/* D86A30 80240030 C6000008 */  lwc1      $f0, 8($s0)
/* D86A34 80240034 240400A2 */  addiu     $a0, $zero, 0xa2
/* D86A38 80240038 E7A00010 */  swc1      $f0, 0x10($sp)
/* D86A3C 8024003C 8E060000 */  lw        $a2, ($s0)
/* D86A40 80240040 8E070004 */  lw        $a3, 4($s0)
/* D86A44 80240044 0C05267B */  jal       func_801499EC
/* D86A48 80240048 0000282D */   daddu    $a1, $zero, $zero
/* D86A4C 8024004C 86020044 */  lh        $v0, 0x44($s0)
/* D86A50 80240050 8FBF001C */  lw        $ra, 0x1c($sp)
/* D86A54 80240054 8FB00018 */  lw        $s0, 0x18($sp)
/* D86A58 80240058 28420002 */  slti      $v0, $v0, 2
/* D86A5C 8024005C 38420001 */  xori      $v0, $v0, 1
/* D86A60 80240060 00021040 */  sll       $v0, $v0, 1
/* D86A64 80240064 03E00008 */  jr        $ra
/* D86A68 80240068 27BD0020 */   addiu    $sp, $sp, 0x20
