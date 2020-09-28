.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055BB8
/* 30FB8 80055BB8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30FBC 80055BBC 24020001 */  addiu     $v0, $zero, 1
/* 30FC0 80055BC0 AFA40010 */  sw        $a0, 0x10($sp)
/* 30FC4 80055BC4 27A40010 */  addiu     $a0, $sp, 0x10
/* 30FC8 80055BC8 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30FCC 80055BCC AFA50014 */  sw        $a1, 0x14($sp)
/* 30FD0 80055BD0 AFA00018 */  sw        $zero, 0x18($sp)
/* 30FD4 80055BD4 AFA0001C */  sw        $zero, 0x1c($sp)
/* 30FD8 80055BD8 AFA00020 */  sw        $zero, 0x20($sp)
/* 30FDC 80055BDC 0C0136D3 */  jal       func_8004DB4C
/* 30FE0 80055BE0 AFA20024 */   sw       $v0, 0x24($sp)
/* 30FE4 80055BE4 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30FE8 80055BE8 03E00008 */  jr        $ra
/* 30FEC 80055BEC 27BD0038 */   addiu    $sp, $sp, 0x38
