.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055868
/* 30C68 80055868 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30C6C 8005586C 24020001 */  addiu     $v0, $zero, 1
/* 30C70 80055870 AFA40010 */  sw        $a0, 0x10($sp)
/* 30C74 80055874 27A40010 */  addiu     $a0, $sp, 0x10
/* 30C78 80055878 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30C7C 8005587C AFA50014 */  sw        $a1, 0x14($sp)
/* 30C80 80055880 AFA00018 */  sw        $zero, 0x18($sp)
/* 30C84 80055884 AFA0001C */  sw        $zero, 0x1c($sp)
/* 30C88 80055888 AFA00020 */  sw        $zero, 0x20($sp)
/* 30C8C 8005588C 0C0135FF */  jal       func_8004D7FC
/* 30C90 80055890 AFA20024 */   sw       $v0, 0x24($sp)
/* 30C94 80055894 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30C98 80055898 03E00008 */  jr        $ra
/* 30C9C 8005589C 27BD0038 */   addiu    $sp, $sp, 0x38
