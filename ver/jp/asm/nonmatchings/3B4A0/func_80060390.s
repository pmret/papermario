.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060390
/* 3B790 80060390 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B794 80060394 3C04800B */  lui       $a0, %hi(D_800AC500)
/* 3B798 80060398 2484C500 */  addiu     $a0, $a0, %lo(D_800AC500)
/* 3B79C 8006039C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B7A0 800603A0 0C0197FC */  jal       func_80065FF0
/* 3B7A4 800603A4 00000000 */   nop
/* 3B7A8 800603A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B7AC 800603AC 03E00008 */  jr        $ra
/* 3B7B0 800603B0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3B7B4 800603B4 00000000 */  nop
/* 3B7B8 800603B8 00000000 */  nop
/* 3B7BC 800603BC 00000000 */  nop
