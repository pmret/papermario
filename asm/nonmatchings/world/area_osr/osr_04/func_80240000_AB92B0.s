.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AB92B0
/* AB92B0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB92B4 80240004 3C04800E */  lui       $a0, 0x800e
/* AB92B8 80240008 24849230 */  addiu     $a0, $a0, -0x6dd0
/* AB92BC 8024000C 3C058024 */  lui       $a1, 0x8024
/* AB92C0 80240010 24A51FB0 */  addiu     $a1, $a1, 0x1fb0
/* AB92C4 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AB92C8 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AB92CC 8024001C 24020002 */  addiu     $v0, $zero, 2
/* AB92D0 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* AB92D4 80240024 0C01953C */  jal       sprintf
/* AB92D8 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* AB92DC 8024002C 3C04800E */  lui       $a0, 0x800e
/* AB92E0 80240030 248491E0 */  addiu     $a0, $a0, -0x6e20
/* AB92E4 80240034 3C058024 */  lui       $a1, 0x8024
/* AB92E8 80240038 0C01953C */  jal       sprintf
/* AB92EC 8024003C 24A51FC0 */   addiu    $a1, $a1, 0x1fc0
/* AB92F0 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* AB92F4 80240044 0000102D */  daddu     $v0, $zero, $zero
/* AB92F8 80240048 03E00008 */  jr        $ra
/* AB92FC 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18
