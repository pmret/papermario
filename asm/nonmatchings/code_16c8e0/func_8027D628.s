.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8027D628
/* 1ABF08 8027D628 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1ABF0C 8027D62C AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABF10 8027D630 0080802D */  daddu     $s0, $a0, $zero
/* 1ABF14 8027D634 AFBF0014 */  sw        $ra, 0x14($sp)
/* 1ABF18 8027D638 8E02000C */  lw        $v0, 0xc($s0)
/* 1ABF1C 8027D63C 0C0B1EAF */  jal       get_variable
/* 1ABF20 8027D640 8C450000 */   lw       $a1, ($v0)
/* 1ABF24 8027D644 0040202D */  daddu     $a0, $v0, $zero
/* 1ABF28 8027D648 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABF2C 8027D64C 14820002 */  bne       $a0, $v0, .L8027D658
/* 1ABF30 8027D650 00000000 */   nop      
/* 1ABF34 8027D654 8E040148 */  lw        $a0, 0x148($s0)
.L8027D658:
/* 1ABF38 8027D658 0C09A75B */  jal       get_actor
/* 1ABF3C 8027D65C 00000000 */   nop      
/* 1ABF40 8027D660 0C095184 */  jal       func_80254610
/* 1ABF44 8027D664 0040202D */   daddu    $a0, $v0, $zero
/* 1ABF48 8027D668 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1ABF4C 8027D66C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABF50 8027D670 24020002 */  addiu     $v0, $zero, 2
/* 1ABF54 8027D674 03E00008 */  jr        $ra
/* 1ABF58 8027D678 27BD0018 */   addiu    $sp, $sp, 0x18
