.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E40A0
/* 105920 802E40A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105924 802E40A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 105928 802E40A8 0080802D */  daddu     $s0, $a0, $zero
/* 10592C 802E40AC AFBF0014 */  sw        $ra, 0x14($sp)
/* 105930 802E40B0 0C0441A9 */  jal       get_entity_type
/* 105934 802E40B4 92040004 */   lbu      $a0, 4($s0)
/* 105938 802E40B8 0040182D */  daddu     $v1, $v0, $zero
/* 10593C 802E40BC 24020012 */  addiu     $v0, $zero, 0x12
/* 105940 802E40C0 10620003 */  beq       $v1, $v0, .L802E40D0
/* 105944 802E40C4 24020014 */   addiu    $v0, $zero, 0x14
/* 105948 802E40C8 14620006 */  bne       $v1, $v0, .L802E40E4
/* 10594C 802E40CC 00000000 */   nop      
.L802E40D0:
/* 105950 802E40D0 86040014 */  lh        $a0, 0x14($s0)
/* 105954 802E40D4 3C050000 */  lui       $a1, 0
/* 105958 802E40D8 24A50094 */  addiu     $a1, $a1, 0x94
/* 10595C 802E40DC 080B903C */  j         .L802E40F0
/* 105960 802E40E0 00000000 */   nop      
.L802E40E4:
/* 105964 802E40E4 86040014 */  lh        $a0, 0x14($s0)
/* 105968 802E40E8 3C050000 */  lui       $a1, 0
/* 10596C 802E40EC 24A50094 */  addiu     $a1, $a1, 0x94
.L802E40F0:
/* 105970 802E40F0 0C048052 */  jal       play_model_animation
/* 105974 802E40F4 00000000 */   nop      
/* 105978 802E40F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 10597C 802E40FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 105980 802E4100 03E00008 */  jr        $ra
/* 105984 802E4104 27BD0018 */   addiu    $sp, $sp, 0x18
