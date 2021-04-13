.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035A20
/* 10E20 80035A20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10E24 80035A24 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10E28 80035A28 0C03A5B7 */  jal       func_800E96DC
/* 10E2C 80035A2C 00000000 */   nop
/* 10E30 80035A30 0C00F89C */  jal       func_8003E270
/* 10E34 80035A34 00000000 */   nop
/* 10E38 80035A38 0C04FDE6 */  jal       func_8013F798
/* 10E3C 80035A3C 00000000 */   nop
/* 10E40 80035A40 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10E44 80035A44 03E00008 */  jr        $ra
/* 10E48 80035A48 27BD0018 */   addiu    $sp, $sp, 0x18
