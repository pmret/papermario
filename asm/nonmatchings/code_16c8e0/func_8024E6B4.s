.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E6B4
/* 17CF94 8024E6B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17CF98 8024E6B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 17CF9C 8024E6BC 0080802D */  daddu     $s0, $a0, $zero
/* 17CFA0 8024E6C0 3C028028 */  lui       $v0, 0x8028
/* 17CFA4 8024E6C4 80420CE0 */  lb        $v0, 0xce0($v0)
/* 17CFA8 8024E6C8 00A0182D */  daddu     $v1, $a1, $zero
/* 17CFAC 8024E6CC AFBF0014 */  sw        $ra, 0x14($sp)
/* 17CFB0 8024E6D0 8E05000C */  lw        $a1, 0xc($s0)
/* 17CFB4 8024E6D4 14400018 */  bnez      $v0, .L8024E738
/* 17CFB8 8024E6D8 24020002 */   addiu    $v0, $zero, 2
/* 17CFBC 8024E6DC 54600001 */  bnel      $v1, $zero, .L8024E6E4
/* 17CFC0 8024E6E0 AE000070 */   sw       $zero, 0x70($s0)
.L8024E6E4:
/* 17CFC4 8024E6E4 8E030070 */  lw        $v1, 0x70($s0)
/* 17CFC8 8024E6E8 10600005 */  beqz      $v1, .L8024E700
/* 17CFCC 8024E6EC 24020001 */   addiu    $v0, $zero, 1
/* 17CFD0 8024E6F0 1062000B */  beq       $v1, $v0, .L8024E720
/* 17CFD4 8024E6F4 00000000 */   nop      
/* 17CFD8 8024E6F8 080939CE */  j         .L8024E738
/* 17CFDC 8024E6FC 0000102D */   daddu    $v0, $zero, $zero
.L8024E700:
/* 17CFE0 8024E700 8CA50000 */  lw        $a1, ($a1)
/* 17CFE4 8024E704 0C0B1EAF */  jal       get_variable
/* 17CFE8 8024E708 0200202D */   daddu    $a0, $s0, $zero
/* 17CFEC 8024E70C 0C093903 */  jal       func_8024E40C
/* 17CFF0 8024E710 0040202D */   daddu    $a0, $v0, $zero
/* 17CFF4 8024E714 24020001 */  addiu     $v0, $zero, 1
/* 17CFF8 8024E718 080939CD */  j         .L8024E734
/* 17CFFC 8024E71C AE020070 */   sw       $v0, 0x70($s0)
.L8024E720:
/* 17D000 8024E720 0C093961 */  jal       func_8024E584
/* 17D004 8024E724 00000000 */   nop      
/* 17D008 8024E728 0040182D */  daddu     $v1, $v0, $zero
/* 17D00C 8024E72C 14600002 */  bnez      $v1, .L8024E738
/* 17D010 8024E730 24020002 */   addiu    $v0, $zero, 2
.L8024E734:
/* 17D014 8024E734 0000102D */  daddu     $v0, $zero, $zero
.L8024E738:
/* 17D018 8024E738 8FBF0014 */  lw        $ra, 0x14($sp)
/* 17D01C 8024E73C 8FB00010 */  lw        $s0, 0x10($sp)
/* 17D020 8024E740 03E00008 */  jr        $ra
/* 17D024 8024E744 27BD0018 */   addiu    $sp, $sp, 0x18
