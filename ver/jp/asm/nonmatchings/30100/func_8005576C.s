.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005576C
/* 30B6C 8005576C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30B70 80055770 AFA40010 */  sw        $a0, 0x10($sp)
/* 30B74 80055774 27A40010 */  addiu     $a0, $sp, 0x10
/* 30B78 80055778 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30B7C 8005577C AFA50014 */  sw        $a1, 0x14($sp)
/* 30B80 80055780 AFA00018 */  sw        $zero, 0x18($sp)
/* 30B84 80055784 AFA0001C */  sw        $zero, 0x1c($sp)
/* 30B88 80055788 AFA60020 */  sw        $a2, 0x20($sp)
/* 30B8C 8005578C 0C0135FF */  jal       func_8004D7FC
/* 30B90 80055790 AFA00024 */   sw       $zero, 0x24($sp)
/* 30B94 80055794 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30B98 80055798 03E00008 */  jr        $ra
/* 30B9C 8005579C 27BD0038 */   addiu    $sp, $sp, 0x38
