.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetActorHP
/* 1AAF80 8027C6A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AAF84 8027C6A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AAF88 8027C6A8 0080902D */  daddu     $s2, $a0, $zero
/* 1AAF8C 8027C6AC AFBF001C */  sw        $ra, 0x1c($sp)
/* 1AAF90 8027C6B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AAF94 8027C6B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AAF98 8027C6B8 8E51000C */  lw        $s1, 0xc($s2)
/* 1AAF9C 8027C6BC 8E250000 */  lw        $a1, ($s1)
/* 1AAFA0 8027C6C0 0C0B1EAF */  jal       get_variable
/* 1AAFA4 8027C6C4 26310004 */   addiu    $s1, $s1, 4
/* 1AAFA8 8027C6C8 0040802D */  daddu     $s0, $v0, $zero
/* 1AAFAC 8027C6CC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AAFB0 8027C6D0 16020002 */  bne       $s0, $v0, .L8027C6DC
/* 1AAFB4 8027C6D4 00000000 */   nop      
/* 1AAFB8 8027C6D8 8E500148 */  lw        $s0, 0x148($s2)
.L8027C6DC:
/* 1AAFBC 8027C6DC 8E310000 */  lw        $s1, ($s1)
/* 1AAFC0 8027C6E0 0C09A75B */  jal       get_actor
/* 1AAFC4 8027C6E4 0200202D */   daddu    $a0, $s0, $zero
/* 1AAFC8 8027C6E8 32040700 */  andi      $a0, $s0, 0x700
/* 1AAFCC 8027C6EC 10800006 */  beqz      $a0, .L8027C708
/* 1AAFD0 8027C6F0 0040302D */   daddu    $a2, $v0, $zero
/* 1AAFD4 8027C6F4 24020100 */  addiu     $v0, $zero, 0x100
/* 1AAFD8 8027C6F8 50820009 */  beql      $a0, $v0, .L8027C720
/* 1AAFDC 8027C6FC 24060063 */   addiu    $a2, $zero, 0x63
/* 1AAFE0 8027C700 0809F1C7 */  j         .L8027C71C
/* 1AAFE4 8027C704 00000000 */   nop      
.L8027C708:
/* 1AAFE8 8027C708 3C028011 */  lui       $v0, 0x8011
/* 1AAFEC 8027C70C 2442F290 */  addiu     $v0, $v0, -0xd70
/* 1AAFF0 8027C710 80460002 */  lb        $a2, 2($v0)
/* 1AAFF4 8027C714 0809F1C9 */  j         .L8027C724
/* 1AAFF8 8027C718 0240202D */   daddu    $a0, $s2, $zero
.L8027C71C:
/* 1AAFFC 8027C71C 80C601B8 */  lb        $a2, 0x1b8($a2)
.L8027C720:
/* 1AB000 8027C720 0240202D */  daddu     $a0, $s2, $zero
.L8027C724:
/* 1AB004 8027C724 0C0B2026 */  jal       set_variable
/* 1AB008 8027C728 0220282D */   daddu    $a1, $s1, $zero
/* 1AB00C 8027C72C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1AB010 8027C730 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AB014 8027C734 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AB018 8027C738 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AB01C 8027C73C 24020002 */  addiu     $v0, $zero, 2
/* 1AB020 8027C740 03E00008 */  jr        $ra
/* 1AB024 8027C744 27BD0020 */   addiu    $sp, $sp, 0x20
