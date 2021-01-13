.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_B06A20
/* B06A20 80240020 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B06A24 80240024 AFBF0010 */  sw        $ra, 0x10($sp)
/* B06A28 80240028 0C03A6D5 */  jal       increment_status_menu_disabled
/* B06A2C 8024002C 00000000 */   nop
/* B06A30 80240030 3C05437F */  lui       $a1, 0x437f
/* B06A34 80240034 0C04DF69 */  jal       func_80137DA4
/* B06A38 80240038 0000202D */   daddu    $a0, $zero, $zero
/* B06A3C 8024003C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B06A40 80240040 24020002 */  addiu     $v0, $zero, 2
/* B06A44 80240044 03E00008 */  jr        $ra
/* B06A48 80240048 27BD0018 */   addiu    $sp, $sp, 0x18
/* B06A4C 8024004C 00000000 */  nop
