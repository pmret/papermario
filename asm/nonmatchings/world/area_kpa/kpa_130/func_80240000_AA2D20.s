.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AA2D20
/* AA2D20 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AA2D24 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* AA2D28 80240008 24100032 */  addiu     $s0, $zero, 0x32
/* AA2D2C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
.L80240010:
/* AA2D30 80240010 0C00FB3A */  jal       get_enemy
/* AA2D34 80240014 0200202D */   daddu    $a0, $s0, $zero
/* AA2D38 80240018 8C42006C */  lw        $v0, 0x6c($v0)
/* AA2D3C 8024001C 54400003 */  bnel      $v0, $zero, .L8024002C
/* AA2D40 80240020 26100001 */   addiu    $s0, $s0, 1
/* AA2D44 80240024 0809000E */  j         .L80240038
/* AA2D48 80240028 0200102D */   daddu    $v0, $s0, $zero
.L8024002C:
/* AA2D4C 8024002C 2A02003C */  slti      $v0, $s0, 0x3c
/* AA2D50 80240030 1440FFF7 */  bnez      $v0, .L80240010
/* AA2D54 80240034 2402FFFF */   addiu    $v0, $zero, -1
.L80240038:
/* AA2D58 80240038 8FBF0014 */  lw        $ra, 0x14($sp)
/* AA2D5C 8024003C 8FB00010 */  lw        $s0, 0x10($sp)
/* AA2D60 80240040 03E00008 */  jr        $ra
/* AA2D64 80240044 27BD0018 */   addiu    $sp, $sp, 0x18
