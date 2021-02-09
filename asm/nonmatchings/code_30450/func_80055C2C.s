.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055C2C
/* 3102C 80055C2C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 31030 80055C30 24020001 */  addiu     $v0, $zero, 1
/* 31034 80055C34 AFA40010 */  sw        $a0, 0x10($sp)
/* 31038 80055C38 27A40010 */  addiu     $a0, $sp, 0x10
/* 3103C 80055C3C AFBF0030 */  sw        $ra, 0x30($sp)
/* 31040 80055C40 AFA00014 */  sw        $zero, 0x14($sp)
/* 31044 80055C44 AFA00018 */  sw        $zero, 0x18($sp)
/* 31048 80055C48 AFA0001C */  sw        $zero, 0x1c($sp)
/* 3104C 80055C4C AFA00020 */  sw        $zero, 0x20($sp)
/* 31050 80055C50 0C01378B */  jal       func_8004DE2C
/* 31054 80055C54 AFA20024 */   sw       $v0, 0x24($sp)
/* 31058 80055C58 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3105C 80055C5C 03E00008 */  jr        $ra
/* 31060 80055C60 27BD0038 */   addiu    $sp, $sp, 0x38
