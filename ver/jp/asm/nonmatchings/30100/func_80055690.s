.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055690
/* 30A90 80055690 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 30A94 80055694 AFBF0010 */  sw        $ra, 0x10($sp)
/* 30A98 80055698 0C0135C9 */  jal       func_8004D724
/* 30A9C 8005569C 00000000 */   nop
/* 30AA0 800556A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 30AA4 800556A4 03E00008 */  jr        $ra
/* 30AA8 800556A8 27BD0018 */   addiu    $sp, $sp, 0x18
