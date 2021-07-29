.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDD9C_31D90C
/* 31D90C 802BDD9C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31D910 802BDDA0 3C02802C */  lui       $v0, %hi(D_802BE30C)
/* 31D914 802BDDA4 8C42E30C */  lw        $v0, %lo(D_802BE30C)($v0)
/* 31D918 802BDDA8 3C068011 */  lui       $a2, %hi(D_8010EBB0)
/* 31D91C 802BDDAC 24C6EBB0 */  addiu     $a2, $a2, %lo(D_8010EBB0)
/* 31D920 802BDDB0 10400012 */  beqz      $v0, .L802BDDFC
/* 31D924 802BDDB4 AFBF0010 */   sw       $ra, 0x10($sp)
/* 31D928 802BDDB8 24C30018 */  addiu     $v1, $a2, 0x18
/* 31D92C 802BDDBC 0080102D */  daddu     $v0, $a0, $zero
/* 31D930 802BDDC0 24850340 */  addiu     $a1, $a0, 0x340
.L802BDDC4:
/* 31D934 802BDDC4 8C470000 */  lw        $a3, ($v0)
/* 31D938 802BDDC8 8C480004 */  lw        $t0, 4($v0)
/* 31D93C 802BDDCC 8C490008 */  lw        $t1, 8($v0)
/* 31D940 802BDDD0 8C4A000C */  lw        $t2, 0xc($v0)
/* 31D944 802BDDD4 AC670000 */  sw        $a3, ($v1)
/* 31D948 802BDDD8 AC680004 */  sw        $t0, 4($v1)
/* 31D94C 802BDDDC AC690008 */  sw        $t1, 8($v1)
/* 31D950 802BDDE0 AC6A000C */  sw        $t2, 0xc($v1)
/* 31D954 802BDDE4 24420010 */  addiu     $v0, $v0, 0x10
/* 31D958 802BDDE8 1445FFF6 */  bne       $v0, $a1, .L802BDDC4
/* 31D95C 802BDDEC 24630010 */   addiu    $v1, $v1, 0x10
/* 31D960 802BDDF0 24020001 */  addiu     $v0, $zero, 1
/* 31D964 802BDDF4 0C03BD17 */  jal       partner_clear_player_tracking
/* 31D968 802BDDF8 A0C20001 */   sb       $v0, 1($a2)
.L802BDDFC:
/* 31D96C 802BDDFC 0C0AF460 */  jal       func_802BD180_31CCF0
/* 31D970 802BDE00 00000000 */   nop
/* 31D974 802BDE04 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31D978 802BDE08 03E00008 */  jr        $ra
/* 31D97C 802BDE0C 27BD0018 */   addiu    $sp, $sp, 0x18
