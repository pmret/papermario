.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BFAA8
/* 3235F8 802BFAA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3235FC 802BFAAC AFB00010 */  sw        $s0, 0x10($sp)
/* 323600 802BFAB0 3C108011 */  lui       $s0, %hi(D_8010EBB0)
/* 323604 802BFAB4 2610EBB0 */  addiu     $s0, $s0, %lo(D_8010EBB0)
/* 323608 802BFAB8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 32360C 802BFABC 82020001 */  lb        $v0, 1($s0)
/* 323610 802BFAC0 1040001C */  beqz      $v0, .L802BFB34
/* 323614 802BFAC4 00000000 */   nop      
/* 323618 802BFAC8 3C02802C */  lui       $v0, %hi(D_802BFF0C)
/* 32361C 802BFACC 8C42FF0C */  lw        $v0, %lo(D_802BFF0C)($v0)
/* 323620 802BFAD0 10400018 */  beqz      $v0, .L802BFB34
/* 323624 802BFAD4 26020018 */   addiu    $v0, $s0, 0x18
/* 323628 802BFAD8 26030358 */  addiu     $v1, $s0, 0x358
.L802BFADC:
/* 32362C 802BFADC 8C450000 */  lw        $a1, ($v0)
/* 323630 802BFAE0 8C460004 */  lw        $a2, 4($v0)
/* 323634 802BFAE4 8C470008 */  lw        $a3, 8($v0)
/* 323638 802BFAE8 8C48000C */  lw        $t0, 0xc($v0)
/* 32363C 802BFAEC AC850000 */  sw        $a1, ($a0)
/* 323640 802BFAF0 AC860004 */  sw        $a2, 4($a0)
/* 323644 802BFAF4 AC870008 */  sw        $a3, 8($a0)
/* 323648 802BFAF8 AC88000C */  sw        $t0, 0xc($a0)
/* 32364C 802BFAFC 24420010 */  addiu     $v0, $v0, 0x10
/* 323650 802BFB00 1443FFF6 */  bne       $v0, $v1, .L802BFADC
/* 323654 802BFB04 24840010 */   addiu    $a0, $a0, 0x10
/* 323658 802BFB08 24020001 */  addiu     $v0, $zero, 1
/* 32365C 802BFB0C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 323660 802BFB10 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 323664 802BFB14 24040021 */  addiu     $a0, $zero, 0x21
/* 323668 802BFB18 0C039769 */  jal       set_action_state
/* 32366C 802BFB1C A062007D */   sb       $v0, 0x7d($v1)
/* 323670 802BFB20 A2000003 */  sb        $zero, 3($s0)
/* 323674 802BFB24 0C03805E */  jal       disable_player_input
/* 323678 802BFB28 A2000000 */   sb       $zero, ($s0)
/* 32367C 802BFB2C 0C03ACC5 */  jal       partner_use_ability
/* 323680 802BFB30 00000000 */   nop      
.L802BFB34:
/* 323684 802BFB34 8FBF0014 */  lw        $ra, 0x14($sp)
/* 323688 802BFB38 8FB00010 */  lw        $s0, 0x10($sp)
/* 32368C 802BFB3C 03E00008 */  jr        $ra
/* 323690 802BFB40 27BD0018 */   addiu    $sp, $sp, 0x18
