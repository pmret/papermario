.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CD2C
/* 2812C 8004CD2C 00A0382D */  daddu     $a3, $a1, $zero
/* 28130 8004CD30 8CE20000 */  lw        $v0, ($a3)
/* 28134 8004CD34 90430000 */  lbu       $v1, ($v0)
/* 28138 8004CD38 90450001 */  lbu       $a1, 1($v0)
/* 2813C 8004CD3C 90440002 */  lbu       $a0, 2($v0)
/* 28140 8004CD40 24420003 */  addiu     $v0, $v0, 3
/* 28144 8004CD44 ACE20000 */  sw        $v0, ($a3)
/* 28148 8004CD48 00031A00 */  sll       $v1, $v1, 8
/* 2814C 8004CD4C 00A32821 */  addu      $a1, $a1, $v1
/* 28150 8004CD50 00A0302D */  daddu     $a2, $a1, $zero
/* 28154 8004CD54 3084007F */  andi      $a0, $a0, 0x7f
/* 28158 8004CD58 00041040 */  sll       $v0, $a0, 1
/* 2815C 8004CD5C 00441021 */  addu      $v0, $v0, $a0
/* 28160 8004CD60 000210C0 */  sll       $v0, $v0, 3
/* 28164 8004CD64 00441821 */  addu      $v1, $v0, $a0
/* 28168 8004CD68 00052C00 */  sll       $a1, $a1, 0x10
/* 2816C 8004CD6C 1CA00002 */  bgtz      $a1, .L8004CD78
/* 28170 8004CD70 00032080 */   sll      $a0, $v1, 2
/* 28174 8004CD74 24060001 */  addiu     $a2, $zero, 1
.L8004CD78:
/* 28178 8004CD78 8CE20060 */  lw        $v0, 0x60($a3)
/* 2817C 8004CD7C 00031C80 */  sll       $v1, $v1, 0x12
/* 28180 8004CD80 00621823 */  subu      $v1, $v1, $v0
/* 28184 8004CD84 00061400 */  sll       $v0, $a2, 0x10
/* 28188 8004CD88 00021403 */  sra       $v0, $v0, 0x10
/* 2818C 8004CD8C 14400002 */  bnez      $v0, .L8004CD98
/* 28190 8004CD90 0062001A */   div      $zero, $v1, $v0
/* 28194 8004CD94 0007000D */  break     7
.L8004CD98:
/* 28198 8004CD98 2401FFFF */   addiu    $at, $zero, -1
/* 2819C 8004CD9C 14410004 */  bne       $v0, $at, .L8004CDB0
/* 281A0 8004CDA0 3C018000 */   lui      $at, 0x8000
/* 281A4 8004CDA4 14610002 */  bne       $v1, $at, .L8004CDB0
/* 281A8 8004CDA8 00000000 */   nop
/* 281AC 8004CDAC 0006000D */  break     6
.L8004CDB0:
/* 281B0 8004CDB0 00001812 */   mflo     $v1
/* 281B4 8004CDB4 A4E60068 */  sh        $a2, 0x68($a3)
/* 281B8 8004CDB8 A4E4006A */  sh        $a0, 0x6a($a3)
/* 281BC 8004CDBC 03E00008 */  jr        $ra
/* 281C0 8004CDC0 ACE30064 */   sw       $v1, 0x64($a3)
