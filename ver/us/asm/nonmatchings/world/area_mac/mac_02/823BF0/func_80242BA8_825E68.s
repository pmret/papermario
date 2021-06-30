.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_draw_switch_to_player_825E68
/* 825E68 80242BA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 825E6C 80242BAC AFBF0010 */  sw        $ra, 0x10($sp)
/* 825E70 80242BB0 8C82000C */  lw        $v0, 0xc($a0)
/* 825E74 80242BB4 0C0B1EAF */  jal       get_variable
/* 825E78 80242BB8 8C450000 */   lw       $a1, ($v0)
/* 825E7C 80242BBC 0040182D */  daddu     $v1, $v0, $zero
/* 825E80 80242BC0 10600012 */  beqz      $v1, .L80242C0C
/* 825E84 80242BC4 0000202D */   daddu    $a0, $zero, $zero
/* 825E88 80242BC8 8C620000 */  lw        $v0, ($v1)
/* 825E8C 80242BCC 5040000A */  beql      $v0, $zero, .L80242BF8
/* 825E90 80242BD0 00041080 */   sll      $v0, $a0, 2
/* 825E94 80242BD4 3C058025 */  lui       $a1, %hi(D_8024E738)
/* 825E98 80242BD8 24A5E738 */  addiu     $a1, $a1, %lo(D_8024E738)
.L80242BDC:
/* 825E9C 80242BDC 24630004 */  addiu     $v1, $v1, 4
/* 825EA0 80242BE0 24840001 */  addiu     $a0, $a0, 1
/* 825EA4 80242BE4 ACA20000 */  sw        $v0, ($a1)
/* 825EA8 80242BE8 8C620000 */  lw        $v0, ($v1)
/* 825EAC 80242BEC 1440FFFB */  bnez      $v0, .L80242BDC
/* 825EB0 80242BF0 24A50004 */   addiu    $a1, $a1, 4
/* 825EB4 80242BF4 00041080 */  sll       $v0, $a0, 2
.L80242BF8:
/* 825EB8 80242BF8 3C018025 */  lui       $at, %hi(D_8024E738)
/* 825EBC 80242BFC 00220821 */  addu      $at, $at, $v0
/* 825EC0 80242C00 AC20E738 */  sw        $zero, %lo(D_8024E738)($at)
/* 825EC4 80242C04 08090B0D */  j         .L80242C34
/* 825EC8 80242C08 00000000 */   nop
.L80242C0C:
/* 825ECC 80242C0C 3C038025 */  lui       $v1, %hi(D_8024E738)
/* 825ED0 80242C10 2463E738 */  addiu     $v1, $v1, %lo(D_8024E738)
/* 825ED4 80242C14 0060282D */  daddu     $a1, $v1, $zero
.L80242C18:
/* 825ED8 80242C18 24820080 */  addiu     $v0, $a0, 0x80
/* 825EDC 80242C1C AC620000 */  sw        $v0, ($v1)
/* 825EE0 80242C20 24630004 */  addiu     $v1, $v1, 4
/* 825EE4 80242C24 24840001 */  addiu     $a0, $a0, 1
/* 825EE8 80242C28 2882005B */  slti      $v0, $a0, 0x5b
/* 825EEC 80242C2C 1440FFFA */  bnez      $v0, .L80242C18
/* 825EF0 80242C30 ACA0016C */   sw       $zero, 0x16c($a1)
.L80242C34:
/* 825EF4 80242C34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 825EF8 80242C38 24020002 */  addiu     $v0, $zero, 2
/* 825EFC 80242C3C 03E00008 */  jr        $ra
/* 825F00 80242C40 27BD0018 */   addiu    $sp, $sp, 0x18
