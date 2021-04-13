.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061950
/* 3CD50 80061950 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3CD54 80061954 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3CD58 80061958 00802821 */  addu      $a1, $a0, $zero
/* 3CD5C 8006195C 0C01873B */  jal       func_80061CEC
/* 3CD60 80061960 27A40010 */   addiu    $a0, $sp, 0x10
/* 3CD64 80061964 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3CD68 80061968 03E00008 */  jr        $ra
/* 3CD6C 8006196C 27BD0020 */   addiu    $sp, $sp, 0x20
