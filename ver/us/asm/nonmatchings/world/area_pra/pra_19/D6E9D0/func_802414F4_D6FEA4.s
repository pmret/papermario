.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414F4_D6FEA4
/* D6FEA4 802414F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6FEA8 802414F8 AFB00010 */  sw        $s0, 0x10($sp)
/* D6FEAC 802414FC 0080802D */  daddu     $s0, $a0, $zero
/* D6FEB0 80241500 3C058024 */  lui       $a1, %hi(func_80241530_D6FEE0)
/* D6FEB4 80241504 24A51530 */  addiu     $a1, $a1, %lo(func_80241530_D6FEE0)
/* D6FEB8 80241508 AFBF0014 */  sw        $ra, 0x14($sp)
/* D6FEBC 8024150C 0C048C56 */  jal       create_generic_entity_world
/* D6FEC0 80241510 0000202D */   daddu    $a0, $zero, $zero
/* D6FEC4 80241514 8E03013C */  lw        $v1, 0x13c($s0)
/* D6FEC8 80241518 AC620000 */  sw        $v0, ($v1)
/* D6FECC 8024151C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D6FED0 80241520 8FB00010 */  lw        $s0, 0x10($sp)
/* D6FED4 80241524 24020002 */  addiu     $v0, $zero, 2
/* D6FED8 80241528 03E00008 */  jr        $ra
/* D6FEDC 8024152C 27BD0018 */   addiu    $sp, $sp, 0x18
