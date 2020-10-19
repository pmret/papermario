.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240550_AFE090
/* AFE090 80240550 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AFE094 80240554 AFBF0010 */  sw        $ra, 0x10($sp)
/* AFE098 80240558 8C82000C */  lw        $v0, 0xc($a0)
/* AFE09C 8024055C 3C068011 */  lui       $a2, 0x8011
/* AFE0A0 80240560 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* AFE0A4 80240564 0C0B2026 */  jal       set_variable
/* AFE0A8 80240568 8C450000 */   lw       $a1, ($v0)
/* AFE0AC 8024056C 0C03AC5A */  jal       func_800EB168
/* AFE0B0 80240570 0000202D */   daddu    $a0, $zero, $zero
/* AFE0B4 80240574 8FBF0010 */  lw        $ra, 0x10($sp)
/* AFE0B8 80240578 24020002 */  addiu     $v0, $zero, 2
/* AFE0BC 8024057C 03E00008 */  jr        $ra
/* AFE0C0 80240580 27BD0018 */   addiu    $sp, $sp, 0x18
