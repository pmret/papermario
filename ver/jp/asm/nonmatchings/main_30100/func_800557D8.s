.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800557D8
/* 30BD8 800557D8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30BDC 800557DC AFB00030 */  sw        $s0, 0x30($sp)
/* 30BE0 800557E0 3C108008 */  lui       $s0, %hi(D_80078D80)
/* 30BE4 800557E4 26108D80 */  addiu     $s0, $s0, %lo(D_80078D80)
/* 30BE8 800557E8 24030001 */  addiu     $v1, $zero, 1
/* 30BEC 800557EC 240207D0 */  addiu     $v0, $zero, 0x7d0
/* 30BF0 800557F0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 30BF4 800557F4 AE030000 */  sw        $v1, ($s0)
/* 30BF8 800557F8 AFA20014 */  sw        $v0, 0x14($sp)
/* 30BFC 800557FC 2402007F */  addiu     $v0, $zero, 0x7f
/* 30C00 80055800 AFA40010 */  sw        $a0, 0x10($sp)
/* 30C04 80055804 27A40010 */  addiu     $a0, $sp, 0x10
/* 30C08 80055808 AFA30018 */  sw        $v1, 0x18($sp)
/* 30C0C 8005580C AFA2001C */  sw        $v0, 0x1c($sp)
/* 30C10 80055810 AFA00020 */  sw        $zero, 0x20($sp)
/* 30C14 80055814 0C0136B7 */  jal       func_8004DADC
/* 30C18 80055818 AFA00024 */   sw       $zero, 0x24($sp)
/* 30C1C 8005581C AE000000 */  sw        $zero, ($s0)
/* 30C20 80055820 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30C24 80055824 8FB00030 */  lw        $s0, 0x30($sp)
/* 30C28 80055828 03E00008 */  jr        $ra
/* 30C2C 8005582C 27BD0038 */   addiu    $sp, $sp, 0x38
