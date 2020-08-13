.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetCamPosA
/* 0F0608 802CBC58 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F060C 802CBC5C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0610 802CBC60 0080902D */  daddu $s2, $a0, $zero
/* 0F0614 802CBC64 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0618 802CBC68 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F061C 802CBC6C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0620 802CBC70 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F0624 802CBC74 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0628 802CBC78 8E250000 */  lw    $a1, ($s1)
/* 0F062C 802CBC7C 0C0B1EAF */  jal   get_variable
/* 0F0630 802CBC80 26310004 */   addiu $s1, $s1, 4
/* 0F0634 802CBC84 8E250000 */  lw    $a1, ($s1)
/* 0F0638 802CBC88 26310004 */  addiu $s1, $s1, 4
/* 0F063C 802CBC8C 0240202D */  daddu $a0, $s2, $zero
/* 0F0640 802CBC90 3C03800B */  lui   $v1, 0x800b
/* 0F0644 802CBC94 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0648 802CBC98 00028080 */  sll   $s0, $v0, 2
/* 0F064C 802CBC9C 02028021 */  addu  $s0, $s0, $v0
/* 0F0650 802CBCA0 00108080 */  sll   $s0, $s0, 2
/* 0F0654 802CBCA4 02028023 */  subu  $s0, $s0, $v0
/* 0F0658 802CBCA8 001010C0 */  sll   $v0, $s0, 3
/* 0F065C 802CBCAC 02028021 */  addu  $s0, $s0, $v0
/* 0F0660 802CBCB0 001080C0 */  sll   $s0, $s0, 3
/* 0F0664 802CBCB4 0C0B210B */  jal   get_float_variable
/* 0F0668 802CBCB8 02038021 */   addu  $s0, $s0, $v1
/* 0F066C 802CBCBC 0240202D */  daddu $a0, $s2, $zero
/* 0F0670 802CBCC0 8E250000 */  lw    $a1, ($s1)
/* 0F0674 802CBCC4 0C0B210B */  jal   get_float_variable
/* 0F0678 802CBCC8 46000506 */   mov.s $f20, $f0
/* 0F067C 802CBCCC E61404E4 */  swc1  $f20, 0x4e4($s0)
/* 0F0680 802CBCD0 E60004EC */  swc1  $f0, 0x4ec($s0)
/* 0F0684 802CBCD4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0688 802CBCD8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F068C 802CBCDC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0690 802CBCE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0694 802CBCE4 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F0698 802CBCE8 24020002 */  addiu $v0, $zero, 2
/* 0F069C 802CBCEC 03E00008 */  jr    $ra
/* 0F06A0 802CBCF0 27BD0028 */   addiu $sp, $sp, 0x28

