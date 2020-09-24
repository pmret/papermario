.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005600C
/* 3140C 8005600C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31410 80056010 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31414 80056014 0C0157D6 */  jal       func_80055F58
/* 31418 80056018 2406007F */   addiu    $a2, $zero, 0x7f
/* 3141C 8005601C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31420 80056020 03E00008 */  jr        $ra
/* 31424 80056024 27BD0018 */   addiu    $sp, $sp, 0x18
