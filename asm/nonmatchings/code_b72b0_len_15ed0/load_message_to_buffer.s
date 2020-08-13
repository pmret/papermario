.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel load_message_to_buffer
/* 0BBF8C 8012588C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0BBF90 80125890 AFB10014 */  sw    $s1, 0x14($sp)
/* 0BBF94 80125894 3C118015 */  lui   $s1, 0x8015
/* 0BBF98 80125898 2631C296 */  addiu $s1, $s1, -0x3d6a
/* 0BBF9C 8012589C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0BBFA0 801258A0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0BBFA4 801258A4 86250000 */  lh    $a1, ($s1)
/* 0BBFA8 801258A8 3C108015 */  lui   $s0, 0x8015
/* 0BBFAC 801258AC 26104430 */  addiu $s0, $s0, 0x4430
/* 0BBFB0 801258B0 00052A80 */  sll   $a1, $a1, 0xa
/* 0BBFB4 801258B4 0C049601 */  jal   dma_load_string
/* 0BBFB8 801258B8 00B02821 */   addu  $a1, $a1, $s0
/* 0BBFBC 801258BC 96220000 */  lhu   $v0, ($s1)
/* 0BBFC0 801258C0 86230000 */  lh    $v1, ($s1)
/* 0BBFC4 801258C4 24420001 */  addiu $v0, $v0, 1
/* 0BBFC8 801258C8 00031A80 */  sll   $v1, $v1, 0xa
/* 0BBFCC 801258CC A6220000 */  sh    $v0, ($s1)
/* 0BBFD0 801258D0 00021400 */  sll   $v0, $v0, 0x10
/* 0BBFD4 801258D4 00021403 */  sra   $v0, $v0, 0x10
/* 0BBFD8 801258D8 28420002 */  slti  $v0, $v0, 2
/* 0BBFDC 801258DC 14400002 */  bnez  $v0, .L801258E8
/* 0BBFE0 801258E0 00701821 */   addu  $v1, $v1, $s0
/* 0BBFE4 801258E4 A6200000 */  sh    $zero, ($s1)
.L801258E8:
/* 0BBFE8 801258E8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0BBFEC 801258EC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0BBFF0 801258F0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0BBFF4 801258F4 0060102D */  daddu $v0, $v1, $zero
/* 0BBFF8 801258F8 03E00008 */  jr    $ra
/* 0BBFFC 801258FC 27BD0020 */   addiu $sp, $sp, 0x20

