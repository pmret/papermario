.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dma_load_string
/* BBF04 80125804 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BBF08 80125808 AFB00018 */  sw        $s0, 0x18($sp)
/* BBF0C 8012580C 0080802D */  daddu     $s0, $a0, $zero
/* BBF10 80125810 AFB20020 */  sw        $s2, 0x20($sp)
/* BBF14 80125814 00A0902D */  daddu     $s2, $a1, $zero
/* BBF18 80125818 AFB1001C */  sw        $s1, 0x1c($sp)
/* BBF1C 8012581C 3C1101B8 */  lui       $s1, 0x1b8
/* BBF20 80125820 36313000 */  ori       $s1, $s1, 0x3000
/* BBF24 80125824 00101382 */  srl       $v0, $s0, 0xe
/* BBF28 80125828 00512021 */  addu      $a0, $v0, $s1
/* BBF2C 8012582C 24850004 */  addiu     $a1, $a0, 4
/* BBF30 80125830 AFBF0024 */  sw        $ra, 0x24($sp)
/* BBF34 80125834 0C00A5CF */  jal       dma_copy
/* BBF38 80125838 27A60010 */   addiu    $a2, $sp, 0x10
/* BBF3C 8012583C 27A60010 */  addiu     $a2, $sp, 0x10
/* BBF40 80125840 3210FFFF */  andi      $s0, $s0, 0xffff
/* BBF44 80125844 00108080 */  sll       $s0, $s0, 2
/* BBF48 80125848 8FA20010 */  lw        $v0, 0x10($sp)
/* BBF4C 8012584C 02118021 */  addu      $s0, $s0, $s1
/* BBF50 80125850 00502021 */  addu      $a0, $v0, $s0
/* BBF54 80125854 0C00A5CF */  jal       dma_copy
/* BBF58 80125858 24850008 */   addiu    $a1, $a0, 8
/* BBF5C 8012585C 0240302D */  daddu     $a2, $s2, $zero
/* BBF60 80125860 8FA40010 */  lw        $a0, 0x10($sp)
/* BBF64 80125864 8FA50014 */  lw        $a1, 0x14($sp)
/* BBF68 80125868 00912021 */  addu      $a0, $a0, $s1
/* BBF6C 8012586C 0C00A5CF */  jal       dma_copy
/* BBF70 80125870 00B12821 */   addu     $a1, $a1, $s1
/* BBF74 80125874 8FBF0024 */  lw        $ra, 0x24($sp)
/* BBF78 80125878 8FB20020 */  lw        $s2, 0x20($sp)
/* BBF7C 8012587C 8FB1001C */  lw        $s1, 0x1c($sp)
/* BBF80 80125880 8FB00018 */  lw        $s0, 0x18($sp)
/* BBF84 80125884 03E00008 */  jr        $ra
/* BBF88 80125888 27BD0028 */   addiu    $sp, $sp, 0x28
