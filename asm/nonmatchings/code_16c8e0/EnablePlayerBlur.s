.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel EnablePlayerBlur
/* 1A3258 80274978 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A325C 8027497C AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A3260 80274980 8C82000C */  lw        $v0, 0xc($a0)
/* 1A3264 80274984 0C0B1EAF */  jal       get_variable
/* 1A3268 80274988 8C450000 */   lw       $a1, ($v0)
/* 1A326C 8027498C 0040182D */  daddu     $v1, $v0, $zero
/* 1A3270 80274990 14600005 */  bnez      $v1, .L802749A8
/* 1A3274 80274994 24020001 */   addiu    $v0, $zero, 1
/* 1A3278 80274998 0C095245 */  jal       disable_player_blur
/* 1A327C 8027499C 00000000 */   nop      
/* 1A3280 802749A0 0809D272 */  j         .L802749C8
/* 1A3284 802749A4 00000000 */   nop      
.L802749A8:
/* 1A3288 802749A8 14620005 */  bne       $v1, $v0, .L802749C0
/* 1A328C 802749AC 00000000 */   nop      
/* 1A3290 802749B0 0C0951B5 */  jal       enable_player_blur
/* 1A3294 802749B4 00000000 */   nop      
/* 1A3298 802749B8 0809D272 */  j         .L802749C8
/* 1A329C 802749BC 00000000 */   nop      
.L802749C0:
/* 1A32A0 802749C0 0C095254 */  jal       func_80254950
/* 1A32A4 802749C4 00000000 */   nop      
.L802749C8:
/* 1A32A8 802749C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A32AC 802749CC 24020002 */  addiu     $v0, $zero, 2
/* 1A32B0 802749D0 03E00008 */  jr        $ra
/* 1A32B4 802749D4 27BD0018 */   addiu    $sp, $sp, 0x18
