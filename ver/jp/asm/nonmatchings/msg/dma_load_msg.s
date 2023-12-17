.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel dma_load_msg
/* BF8F8 8012AA68 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BF8FC 8012AA6C AFB00018 */  sw        $s0, 0x18($sp)
/* BF900 8012AA70 0080802D */  daddu     $s0, $a0, $zero
/* BF904 8012AA74 AFB20020 */  sw        $s2, 0x20($sp)
/* BF908 8012AA78 00A0902D */  daddu     $s2, $a1, $zero
/* BF90C 8012AA7C 00101382 */  srl       $v0, $s0, 14
/* BF910 8012AA80 AFB1001C */  sw        $s1, 0x1C($sp)
/* BF914 8012AA84 3C1101D4 */  lui       $s1, %hi(D_1D40004)
/* BF918 8012AA88 00512021 */  addu      $a0, $v0, $s1
/* BF91C 8012AA8C 24850004 */  addiu     $a1, $a0, %lo(D_1D40004)
/* BF920 8012AA90 AFBF0024 */  sw        $ra, 0x24($sp)
/* BF924 8012AA94 0C00A5BF */  jal       dma_copy
/* BF928 8012AA98 27A60010 */   addiu    $a2, $sp, 0x10
/* BF92C 8012AA9C 27A60010 */  addiu     $a2, $sp, 0x10
/* BF930 8012AAA0 3210FFFF */  andi      $s0, $s0, 0xFFFF
/* BF934 8012AAA4 00108080 */  sll       $s0, $s0, 2
/* BF938 8012AAA8 8FA20010 */  lw        $v0, 0x10($sp)
/* BF93C 8012AAAC 02118021 */  addu      $s0, $s0, $s1
/* BF940 8012AAB0 00502021 */  addu      $a0, $v0, $s0
/* BF944 8012AAB4 0C00A5BF */  jal       dma_copy
/* BF948 8012AAB8 24850008 */   addiu    $a1, $a0, %lo(D_1D40008)
/* BF94C 8012AABC 0240302D */  daddu     $a2, $s2, $zero
/* BF950 8012AAC0 8FA40010 */  lw        $a0, 0x10($sp)
/* BF954 8012AAC4 8FA50014 */  lw        $a1, 0x14($sp)
/* BF958 8012AAC8 00912021 */  addu      $a0, $a0, $s1
/* BF95C 8012AACC 0C00A5BF */  jal       dma_copy
/* BF960 8012AAD0 00B12821 */   addu     $a1, $a1, $s1
/* BF964 8012AAD4 8FBF0024 */  lw        $ra, 0x24($sp)
/* BF968 8012AAD8 8FB20020 */  lw        $s2, 0x20($sp)
/* BF96C 8012AADC 8FB1001C */  lw        $s1, 0x1C($sp)
/* BF970 8012AAE0 8FB00018 */  lw        $s0, 0x18($sp)
/* BF974 8012AAE4 03E00008 */  jr        $ra
/* BF978 8012AAE8 27BD0028 */   addiu    $sp, $sp, 0x28
.size dma_load_msg, . - dma_load_msg
