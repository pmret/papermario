.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055CD8
/* 310D8 80055CD8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 310DC 80055CDC AFBF0010 */  sw        $ra, 0x10($sp)
/* 310E0 80055CE0 0C0140DE */  jal       func_80050378
/* 310E4 80055CE4 30A500FF */   andi     $a1, $a1, 0xff
/* 310E8 80055CE8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 310EC 80055CEC 03E00008 */  jr        $ra
/* 310F0 80055CF0 27BD0018 */   addiu    $sp, $sp, 0x18
