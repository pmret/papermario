.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800359D4
/* 10DD4 800359D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10DD8 800359D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10DDC 800359DC 0C00F879 */  jal       func_8003E1E4
/* 10DE0 800359E0 00000000 */   nop
/* 10DE4 800359E4 0C00E57C */  jal       func_800395F0
/* 10DE8 800359E8 00000000 */   nop
/* 10DEC 800359EC 0C037DC8 */  jal       func_800DF720
/* 10DF0 800359F0 00000000 */   nop
/* 10DF4 800359F4 0C04DC17 */  jal       func_8013705C
/* 10DF8 800359F8 00000000 */   nop
/* 10DFC 800359FC 0C016680 */  jal       func_80059A00
/* 10E00 80035A00 00000000 */   nop
/* 10E04 80035A04 0C046E21 */  jal       func_8011B884
/* 10E08 80035A08 00000000 */   nop
/* 10E0C 80035A0C 0C00B424 */  jal       func_8002D090
/* 10E10 80035A10 00000000 */   nop
/* 10E14 80035A14 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10E18 80035A18 03E00008 */  jr        $ra
/* 10E1C 80035A1C 27BD0018 */   addiu    $sp, $sp, 0x18
