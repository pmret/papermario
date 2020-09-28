.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055C64
/* 31064 80055C64 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 31068 80055C68 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 3106C 80055C6C AFA20014 */  sw        $v0, 0x14($sp)
/* 31070 80055C70 24022000 */  addiu     $v0, $zero, 0x2000
/* 31074 80055C74 AFA40010 */  sw        $a0, 0x10($sp)
/* 31078 80055C78 27A40010 */  addiu     $a0, $sp, 0x10
/* 3107C 80055C7C AFBF0030 */  sw        $ra, 0x30($sp)
/* 31080 80055C80 0C01383D */  jal       func_8004E0F4
/* 31084 80055C84 AFA2001C */   sw       $v0, 0x1c($sp)
/* 31088 80055C88 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3108C 80055C8C 03E00008 */  jr        $ra
/* 31090 80055C90 27BD0038 */   addiu    $sp, $sp, 0x38
