.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800618D0
/* 3CCD0 800618D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3CCD4 800618D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 3CCD8 800618D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3CCDC 800618DC 0C019765 */  jal       func_80065D94
/* 3CCE0 800618E0 00808021 */   addu     $s0, $a0, $zero
/* 3CCE4 800618E4 3C02800A */  lui       $v0, %hi(D_8009A5FC)
/* 3CCE8 800618E8 9042A5FC */  lbu       $v0, %lo(D_8009A5FC)($v0)
/* 3CCEC 800618EC 1040000B */  beqz      $v0, .L8006191C
/* 3CCF0 800618F0 00000000 */   nop
/* 3CCF4 800618F4 0C018768 */  jal       func_80061DA0
/* 3CCF8 800618F8 00002021 */   addu     $a0, $zero, $zero
/* 3CCFC 800618FC 3C05800B */  lui       $a1, %hi(D_800B0EB0)
/* 3CD00 80061900 24A50EB0 */  addiu     $a1, $a1, %lo(D_800B0EB0)
/* 3CD04 80061904 0C019724 */  jal       func_80065C90
/* 3CD08 80061908 24040001 */   addiu    $a0, $zero, 1
/* 3CD0C 8006190C 02002021 */  addu      $a0, $s0, $zero
/* 3CD10 80061910 00002821 */  addu      $a1, $zero, $zero
/* 3CD14 80061914 0C0195B0 */  jal       func_800656C0
/* 3CD18 80061918 24060001 */   addiu    $a2, $zero, 1
.L8006191C:
/* 3CD1C 8006191C 3C05800B */  lui       $a1, %hi(D_800B0EB0)
/* 3CD20 80061920 24A50EB0 */  addiu     $a1, $a1, %lo(D_800B0EB0)
/* 3CD24 80061924 0C019724 */  jal       func_80065C90
/* 3CD28 80061928 00002021 */   addu     $a0, $zero, $zero
/* 3CD2C 8006192C 3C01800A */  lui       $at, %hi(D_8009A5FC)
/* 3CD30 80061930 A020A5FC */  sb        $zero, %lo(D_8009A5FC)($at)
/* 3CD34 80061934 0C019780 */  jal       func_80065E00
/* 3CD38 80061938 00408021 */   addu     $s0, $v0, $zero
/* 3CD3C 8006193C 02001021 */  addu      $v0, $s0, $zero
/* 3CD40 80061940 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3CD44 80061944 8FB00010 */  lw        $s0, 0x10($sp)
/* 3CD48 80061948 03E00008 */  jr        $ra
/* 3CD4C 8006194C 27BD0018 */   addiu    $sp, $sp, 0x18
