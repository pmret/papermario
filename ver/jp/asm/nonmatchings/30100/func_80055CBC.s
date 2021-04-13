.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055CBC
/* 310BC 80055CBC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 310C0 80055CC0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 310C4 80055CC4 0C015702 */  jal       func_80055C08
/* 310C8 80055CC8 2406007F */   addiu    $a2, $zero, 0x7f
/* 310CC 80055CCC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 310D0 80055CD0 03E00008 */  jr        $ra
/* 310D4 80055CD4 27BD0018 */   addiu    $sp, $sp, 0x18
