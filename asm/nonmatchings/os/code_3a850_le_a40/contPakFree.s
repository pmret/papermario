.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel contPakFree
/* 3AB48 8005F748 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3AB4C 8005F74C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3AB50 8005F750 8C85000C */  lw        $a1, 0xc($a0)
/* 3AB54 8005F754 8CA20000 */  lw        $v0, ($a1)
/* 3AB58 8005F758 8C440000 */  lw        $a0, ($v0)
/* 3AB5C 8005F75C 0C01A3E0 */  jal       osPfsFreeBlocks
/* 3AB60 8005F760 24A50004 */   addiu    $a1, $a1, 4
/* 3AB64 8005F764 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3AB68 8005F768 03E00008 */  jr        $ra
/* 3AB6C 8005F76C 27BD0018 */   addiu    $sp, $sp, 0x18
