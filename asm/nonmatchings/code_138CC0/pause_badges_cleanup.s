.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_cleanup
/* 13CA98 80249758 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 13CA9C 8024975C AFB10014 */  sw        $s1, 0x14($sp)
/* 13CAA0 80249760 0000882D */  daddu     $s1, $zero, $zero
/* 13CAA4 80249764 AFB00010 */  sw        $s0, 0x10($sp)
/* 13CAA8 80249768 3C108027 */  lui       $s0, %hi(D_802703A8)
/* 13CAAC 8024976C 261003A8 */  addiu     $s0, $s0, %lo(D_802703A8)
/* 13CAB0 80249770 AFBF0018 */  sw        $ra, 0x18($sp)
.L80249774:
/* 13CAB4 80249774 8E040000 */  lw        $a0, ($s0)
/* 13CAB8 80249778 26100004 */  addiu     $s0, $s0, 4
/* 13CABC 8024977C 0C05123D */  jal       free_icon
/* 13CAC0 80249780 26310001 */   addiu    $s1, $s1, 1
/* 13CAC4 80249784 2A220016 */  slti      $v0, $s1, 0x16
/* 13CAC8 80249788 1440FFFA */  bnez      $v0, .L80249774
/* 13CACC 8024978C 00000000 */   nop      
/* 13CAD0 80249790 8FBF0018 */  lw        $ra, 0x18($sp)
/* 13CAD4 80249794 8FB10014 */  lw        $s1, 0x14($sp)
/* 13CAD8 80249798 8FB00010 */  lw        $s0, 0x10($sp)
/* 13CADC 8024979C 03E00008 */  jr        $ra
/* 13CAE0 802497A0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 13CAE4 802497A4 00000000 */  nop       
/* 13CAE8 802497A8 00000000 */  nop       
/* 13CAEC 802497AC 00000000 */  nop       
