.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osContStartQuery
/* 3CD00 80061900 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3CD04 80061904 AFB00010 */  sw        $s0, 0x10($sp)
/* 3CD08 80061908 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3CD0C 8006190C 0C019771 */  jal       osSiGetAccess
/* 3CD10 80061910 00808021 */   addu     $s0, $a0, $zero
/* 3CD14 80061914 3C02800A */  lui       $v0, %hi(D_8009A61C)
/* 3CD18 80061918 9042A61C */  lbu       $v0, %lo(D_8009A61C)($v0)
/* 3CD1C 8006191C 1040000B */  beqz      $v0, .L8006194C
/* 3CD20 80061920 00000000 */   nop
/* 3CD24 80061924 0C018774 */  jal       osPackRequestData
/* 3CD28 80061928 00002021 */   addu     $a0, $zero, $zero
/* 3CD2C 8006192C 3C05800B */  lui       $a1, %hi(D_800B0ED0)
/* 3CD30 80061930 24A50ED0 */  addiu     $a1, $a1, %lo(D_800B0ED0)
/* 3CD34 80061934 0C019730 */  jal       osSiRawStartDma
/* 3CD38 80061938 24040001 */   addiu    $a0, $zero, 1
/* 3CD3C 8006193C 02002021 */  addu      $a0, $s0, $zero
/* 3CD40 80061940 00002821 */  addu      $a1, $zero, $zero
/* 3CD44 80061944 0C0195BC */  jal       osRecvMesg
/* 3CD48 80061948 24060001 */   addiu    $a2, $zero, 1
.L8006194C:
/* 3CD4C 8006194C 3C05800B */  lui       $a1, %hi(D_800B0ED0)
/* 3CD50 80061950 24A50ED0 */  addiu     $a1, $a1, %lo(D_800B0ED0)
/* 3CD54 80061954 0C019730 */  jal       osSiRawStartDma
/* 3CD58 80061958 00002021 */   addu     $a0, $zero, $zero
/* 3CD5C 8006195C 3C01800A */  lui       $at, %hi(D_8009A61C)
/* 3CD60 80061960 A020A61C */  sb        $zero, %lo(D_8009A61C)($at)
/* 3CD64 80061964 0C01978C */  jal       osSiRelAccess
/* 3CD68 80061968 00408021 */   addu     $s0, $v0, $zero
/* 3CD6C 8006196C 02001021 */  addu      $v0, $s0, $zero
/* 3CD70 80061970 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3CD74 80061974 8FB00010 */  lw        $s0, 0x10($sp)
/* 3CD78 80061978 03E00008 */  jr        $ra
/* 3CD7C 8006197C 27BD0018 */   addiu    $sp, $sp, 0x18
