.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218618_4FF068
/* 4FF068 80218618 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4FF06C 8021861C AFB00010 */  sw        $s0, 0x10($sp)
/* 4FF070 80218620 0080802D */  daddu     $s0, $a0, $zero
/* 4FF074 80218624 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4FF078 80218628 8E02000C */  lw        $v0, 0xc($s0)
/* 4FF07C 8021862C 0C0B1EAF */  jal       get_variable
/* 4FF080 80218630 8C450000 */   lw       $a1, ($v0)
/* 4FF084 80218634 8E040148 */  lw        $a0, 0x148($s0)
/* 4FF088 80218638 0C09A75B */  jal       get_actor
/* 4FF08C 8021863C 0040802D */   daddu    $s0, $v0, $zero
/* 4FF090 80218640 16000005 */  bnez      $s0, .L80218658
/* 4FF094 80218644 00000000 */   nop      
/* 4FF098 80218648 8C430008 */  lw        $v1, 8($v0)
/* 4FF09C 8021864C 24020004 */  addiu     $v0, $zero, 4
/* 4FF0A0 80218650 08086198 */  j         .L80218660
/* 4FF0A4 80218654 A062001D */   sb       $v0, 0x1d($v1)
.L80218658:
/* 4FF0A8 80218658 8C420008 */  lw        $v0, 8($v0)
/* 4FF0AC 8021865C A040001D */  sb        $zero, 0x1d($v0)
.L80218660:
/* 4FF0B0 80218660 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4FF0B4 80218664 8FB00010 */  lw        $s0, 0x10($sp)
/* 4FF0B8 80218668 24020002 */  addiu     $v0, $zero, 2
/* 4FF0BC 8021866C 03E00008 */  jr        $ra
/* 4FF0C0 80218670 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4FF0C4 80218674 00000000 */  nop       
/* 4FF0C8 80218678 00000000 */  nop       
/* 4FF0CC 8021867C 00000000 */  nop       
