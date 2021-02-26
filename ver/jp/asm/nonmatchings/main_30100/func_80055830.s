.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055830
/* 30C30 80055830 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30C34 80055834 AFA40010 */  sw        $a0, 0x10($sp)
/* 30C38 80055838 27A40010 */  addiu     $a0, $sp, 0x10
/* 30C3C 8005583C 24050001 */  addiu     $a1, $zero, 1
/* 30C40 80055840 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30C44 80055844 AFA00014 */  sw        $zero, 0x14($sp)
/* 30C48 80055848 AFA00018 */  sw        $zero, 0x18($sp)
/* 30C4C 8005584C AFA0001C */  sw        $zero, 0x1c($sp)
/* 30C50 80055850 AFA00020 */  sw        $zero, 0x20($sp)
/* 30C54 80055854 0C01365A */  jal       func_8004D968
/* 30C58 80055858 AFA00024 */   sw       $zero, 0x24($sp)
/* 30C5C 8005585C 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30C60 80055860 03E00008 */  jr        $ra
/* 30C64 80055864 27BD0038 */   addiu    $sp, $sp, 0x38
