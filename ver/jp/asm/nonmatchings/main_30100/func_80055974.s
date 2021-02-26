.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055974
/* 30D74 80055974 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30D78 80055978 AFA40010 */  sw        $a0, 0x10($sp)
/* 30D7C 8005597C 27A40010 */  addiu     $a0, $sp, 0x10
/* 30D80 80055980 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30D84 80055984 0C014188 */  jal       func_80050620
/* 30D88 80055988 AFA50020 */   sw       $a1, 0x20($sp)
/* 30D8C 8005598C 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30D90 80055990 03E00008 */  jr        $ra
/* 30D94 80055994 27BD0038 */   addiu    $sp, $sp, 0x38
