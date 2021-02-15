.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055A6C
/* 30E6C 80055A6C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30E70 80055A70 AFB00030 */  sw        $s0, 0x30($sp)
/* 30E74 80055A74 3C108008 */  lui       $s0, %hi(D_80078DB0)
/* 30E78 80055A78 26108DB0 */  addiu     $s0, $s0, %lo(D_80078DB0)
/* 30E7C 80055A7C 24020001 */  addiu     $v0, $zero, 1
/* 30E80 80055A80 AFBF0034 */  sw        $ra, 0x34($sp)
/* 30E84 80055A84 AE020000 */  sw        $v0, ($s0)
/* 30E88 80055A88 AFA40010 */  sw        $a0, 0x10($sp)
/* 30E8C 80055A8C 27A40010 */  addiu     $a0, $sp, 0x10
/* 30E90 80055A90 AFA50014 */  sw        $a1, 0x14($sp)
/* 30E94 80055A94 AFA60018 */  sw        $a2, 0x18($sp)
/* 30E98 80055A98 AFA7001C */  sw        $a3, 0x1c($sp)
/* 30E9C 80055A9C AFA00020 */  sw        $zero, 0x20($sp)
/* 30EA0 80055AA0 0C0135F8 */  jal       func_8004D7E0
/* 30EA4 80055AA4 AFA00024 */   sw       $zero, 0x24($sp)
/* 30EA8 80055AA8 AE000000 */  sw        $zero, ($s0)
/* 30EAC 80055AAC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30EB0 80055AB0 8FB00030 */  lw        $s0, 0x30($sp)
/* 30EB4 80055AB4 03E00008 */  jr        $ra
/* 30EB8 80055AB8 27BD0038 */   addiu    $sp, $sp, 0x38
