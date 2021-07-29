.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D930
/* 28D30 8004D930 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 28D34 8004D934 AFA40010 */  sw        $a0, 0x10($sp)
/* 28D38 8004D938 27A40010 */  addiu     $a0, $sp, 0x10
/* 28D3C 8004D93C 0000282D */  daddu     $a1, $zero, $zero
/* 28D40 8004D940 AFBF0030 */  sw        $ra, 0x30($sp)
/* 28D44 8004D944 AFA00014 */  sw        $zero, 0x14($sp)
/* 28D48 8004D948 AFA00018 */  sw        $zero, 0x18($sp)
/* 28D4C 8004D94C AFA0001C */  sw        $zero, 0x1c($sp)
/* 28D50 8004D950 AFA00020 */  sw        $zero, 0x20($sp)
/* 28D54 8004D954 0C01365A */  jal       func_8004D968
/* 28D58 8004D958 AFA00024 */   sw       $zero, 0x24($sp)
/* 28D5C 8004D95C 8FBF0030 */  lw        $ra, 0x30($sp)
/* 28D60 8004D960 03E00008 */  jr        $ra
/* 28D64 8004D964 27BD0038 */   addiu    $sp, $sp, 0x38
