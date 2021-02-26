.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055620
/* 30A20 80055620 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30A24 80055624 AFB00030 */  sw        $s0, 0x30($sp)
/* 30A28 80055628 3C108008 */  lui       $s0, %hi(D_80078D80)
/* 30A2C 8005562C 26108D80 */  addiu     $s0, $s0, %lo(D_80078D80)
/* 30A30 80055630 24020001 */  addiu     $v0, $zero, 1
/* 30A34 80055634 AFBF0034 */  sw        $ra, 0x34($sp)
/* 30A38 80055638 AE020000 */  sw        $v0, ($s0)
/* 30A3C 8005563C 2402007F */  addiu     $v0, $zero, 0x7f
/* 30A40 80055640 AFA40010 */  sw        $a0, 0x10($sp)
/* 30A44 80055644 27A40010 */  addiu     $a0, $sp, 0x10
/* 30A48 80055648 AFA00014 */  sw        $zero, 0x14($sp)
/* 30A4C 8005564C AFA20018 */  sw        $v0, 0x18($sp)
/* 30A50 80055650 AFA2001C */  sw        $v0, 0x1c($sp)
/* 30A54 80055654 AFA50020 */  sw        $a1, 0x20($sp)
/* 30A58 80055658 0C013524 */  jal       func_8004D490
/* 30A5C 8005565C AFA00024 */   sw       $zero, 0x24($sp)
/* 30A60 80055660 AE000000 */  sw        $zero, ($s0)
/* 30A64 80055664 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30A68 80055668 8FB00030 */  lw        $s0, 0x30($sp)
/* 30A6C 8005566C 03E00008 */  jr        $ra
/* 30A70 80055670 27BD0038 */   addiu    $sp, $sp, 0x38
