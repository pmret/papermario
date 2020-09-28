.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055B80
/* 30F80 80055B80 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30F84 80055B84 AFA40010 */  sw        $a0, 0x10($sp)
/* 30F88 80055B88 27A40010 */  addiu     $a0, $sp, 0x10
/* 30F8C 80055B8C 24050001 */  addiu     $a1, $zero, 1
/* 30F90 80055B90 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30F94 80055B94 AFA00014 */  sw        $zero, 0x14($sp)
/* 30F98 80055B98 AFA00018 */  sw        $zero, 0x18($sp)
/* 30F9C 80055B9C AFA0001C */  sw        $zero, 0x1c($sp)
/* 30FA0 80055BA0 AFA00020 */  sw        $zero, 0x20($sp)
/* 30FA4 80055BA4 0C01372E */  jal       func_8004DCB8
/* 30FA8 80055BA8 AFA00024 */   sw       $zero, 0x24($sp)
/* 30FAC 80055BAC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30FB0 80055BB0 03E00008 */  jr        $ra
/* 30FB4 80055BB4 27BD0038 */   addiu    $sp, $sp, 0x38
