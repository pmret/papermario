.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_items_cleanup
/* 13E0D0 8024AD90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 13E0D4 8024AD94 AFB10014 */  sw        $s1, 0x14($sp)
/* 13E0D8 8024AD98 0000882D */  daddu     $s1, $zero, $zero
/* 13E0DC 8024AD9C AFB00010 */  sw        $s0, 0x10($sp)
/* 13E0E0 8024ADA0 3C108027 */  lui       $s0, 0x8027
/* 13E0E4 8024ADA4 261005E8 */  addiu     $s0, $s0, 0x5e8
/* 13E0E8 8024ADA8 AFBF0018 */  sw        $ra, 0x18($sp)
.L8024ADAC:
/* 13E0EC 8024ADAC 8E040000 */  lw        $a0, ($s0)
/* 13E0F0 8024ADB0 26100004 */  addiu     $s0, $s0, 4
/* 13E0F4 8024ADB4 0C05123D */  jal       free_icon
/* 13E0F8 8024ADB8 26310001 */   addiu    $s1, $s1, 1
/* 13E0FC 8024ADBC 2A220014 */  slti      $v0, $s1, 0x14
/* 13E100 8024ADC0 1440FFFA */  bnez      $v0, .L8024ADAC
/* 13E104 8024ADC4 00000000 */   nop      
/* 13E108 8024ADC8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 13E10C 8024ADCC 8FB10014 */  lw        $s1, 0x14($sp)
/* 13E110 8024ADD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 13E114 8024ADD4 03E00008 */  jr        $ra
/* 13E118 8024ADD8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 13E11C 8024ADDC 00000000 */  nop       
