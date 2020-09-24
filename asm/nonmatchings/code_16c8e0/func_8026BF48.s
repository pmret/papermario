.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026BF48
/* 19A828 8026BF48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19A82C 8026BF4C AFBF0018 */  sw        $ra, 0x18($sp)
/* 19A830 8026BF50 AFB10014 */  sw        $s1, 0x14($sp)
/* 19A834 8026BF54 AFB00010 */  sw        $s0, 0x10($sp)
/* 19A838 8026BF58 8C82000C */  lw        $v0, 0xc($a0)
/* 19A83C 8026BF5C 3C10800E */  lui       $s0, 0x800e
/* 19A840 8026BF60 2610C070 */  addiu     $s0, $s0, -0x3f90
/* 19A844 8026BF64 8C450000 */  lw        $a1, ($v0)
/* 19A848 8026BF68 0C0B1EAF */  jal       get_variable
/* 19A84C 8026BF6C 0200882D */   daddu    $s1, $s0, $zero
/* 19A850 8026BF70 10400005 */  beqz      $v0, .L8026BF88
/* 19A854 8026BF74 00000000 */   nop      
/* 19A858 8026BF78 9202008C */  lbu       $v0, 0x8c($s0)
/* 19A85C 8026BF7C 24420001 */  addiu     $v0, $v0, 1
/* 19A860 8026BF80 0809AFE7 */  j         .L8026BF9C
/* 19A864 8026BF84 A202008C */   sb       $v0, 0x8c($s0)
.L8026BF88:
/* 19A868 8026BF88 8222008C */  lb        $v0, 0x8c($s1)
/* 19A86C 8026BF8C 9223008C */  lbu       $v1, 0x8c($s1)
/* 19A870 8026BF90 18400002 */  blez      $v0, .L8026BF9C
/* 19A874 8026BF94 2462FFFF */   addiu    $v0, $v1, -1
/* 19A878 8026BF98 A222008C */  sb        $v0, 0x8c($s1)
.L8026BF9C:
/* 19A87C 8026BF9C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19A880 8026BFA0 8FB10014 */  lw        $s1, 0x14($sp)
/* 19A884 8026BFA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 19A888 8026BFA8 24020002 */  addiu     $v0, $zero, 2
/* 19A88C 8026BFAC 03E00008 */  jr        $ra
/* 19A890 8026BFB0 27BD0020 */   addiu    $sp, $sp, 0x20
