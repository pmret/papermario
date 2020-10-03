.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055AF0
/* 30EF0 80055AF0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30EF4 80055AF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 30EF8 80055AF8 27A40010 */  addiu     $a0, $sp, 0x10
/* 30EFC 80055AFC 0000282D */  daddu     $a1, $zero, $zero
/* 30F00 80055B00 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30F04 80055B04 AFA00014 */  sw        $zero, 0x14($sp)
/* 30F08 80055B08 AFA00018 */  sw        $zero, 0x18($sp)
/* 30F0C 80055B0C AFA0001C */  sw        $zero, 0x1c($sp)
/* 30F10 80055B10 AFA00020 */  sw        $zero, 0x20($sp)
/* 30F14 80055B14 0C01372E */  jal       func_8004DCB8
/* 30F18 80055B18 AFA00024 */   sw       $zero, 0x24($sp)
/* 30F1C 80055B1C 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30F20 80055B20 03E00008 */  jr        $ra
/* 30F24 80055B24 27BD0038 */   addiu    $sp, $sp, 0x38
