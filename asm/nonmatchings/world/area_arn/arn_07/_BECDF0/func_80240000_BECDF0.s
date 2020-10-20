.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BECDF0
/* BECDF0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BECDF4 80240004 AFBF001C */  sw        $ra, 0x1c($sp)
/* BECDF8 80240008 AFB00018 */  sw        $s0, 0x18($sp)
/* BECDFC 8024000C 8C900084 */  lw        $s0, 0x84($a0)
/* BECE00 80240010 C6000008 */  lwc1      $f0, 8($s0)
/* BECE04 80240014 240400A2 */  addiu     $a0, $zero, 0xa2
/* BECE08 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* BECE0C 8024001C 8E060000 */  lw        $a2, ($s0)
/* BECE10 80240020 8E070004 */  lw        $a3, 4($s0)
/* BECE14 80240024 0C05267B */  jal       func_801499EC
/* BECE18 80240028 0000282D */   daddu    $a1, $zero, $zero
/* BECE1C 8024002C 86020044 */  lh        $v0, 0x44($s0)
/* BECE20 80240030 8FBF001C */  lw        $ra, 0x1c($sp)
/* BECE24 80240034 8FB00018 */  lw        $s0, 0x18($sp)
/* BECE28 80240038 28420002 */  slti      $v0, $v0, 2
/* BECE2C 8024003C 38420001 */  xori      $v0, $v0, 1
/* BECE30 80240040 00021040 */  sll       $v0, $v0, 1
/* BECE34 80240044 03E00008 */  jr        $ra
/* BECE38 80240048 27BD0020 */   addiu    $sp, $sp, 0x20
