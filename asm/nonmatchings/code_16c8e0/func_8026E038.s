.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026E038
/* 19C918 8026E038 8C82000C */  lw        $v0, 0xc($a0)
/* 19C91C 8026E03C 8C420000 */  lw        $v0, ($v0)
/* 19C920 8026E040 3C01800E */  lui       $at, 0x800e
/* 19C924 8026E044 AC22C0E4 */  sw        $v0, -0x3f1c($at)
/* 19C928 8026E048 03E00008 */  jr        $ra
/* 19C92C 8026E04C 24020002 */   addiu    $v0, $zero, 2
