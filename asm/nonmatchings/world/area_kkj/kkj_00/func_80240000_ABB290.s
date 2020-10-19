.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_ABB290
/* ABB290 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ABB294 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* ABB298 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* ABB29C 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* ABB2A0 80240010 0C0B1EAF */  jal       get_variable
/* ABB2A4 80240014 0000202D */   daddu    $a0, $zero, $zero
/* ABB2A8 80240018 28420060 */  slti      $v0, $v0, 0x60
/* ABB2AC 8024001C 14400004 */  bnez      $v0, .L80240030
/* ABB2B0 80240020 24020002 */   addiu    $v0, $zero, 2
/* ABB2B4 80240024 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* ABB2B8 80240028 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* ABB2BC 8024002C A0620084 */  sb        $v0, 0x84($v1)
.L80240030:
/* ABB2C0 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* ABB2C4 80240034 0000102D */  daddu     $v0, $zero, $zero
/* ABB2C8 80240038 03E00008 */  jr        $ra
/* ABB2CC 8024003C 27BD0018 */   addiu    $sp, $sp, 0x18
