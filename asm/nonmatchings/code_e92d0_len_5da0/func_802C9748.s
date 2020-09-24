.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C9748
/* EE0F8 802C9748 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE0FC 802C974C AFB00010 */  sw        $s0, 0x10($sp)
/* EE100 802C9750 0080802D */  daddu     $s0, $a0, $zero
/* EE104 802C9754 AFBF0018 */  sw        $ra, 0x18($sp)
/* EE108 802C9758 AFB10014 */  sw        $s1, 0x14($sp)
/* EE10C 802C975C 8E11000C */  lw        $s1, 0xc($s0)
/* EE110 802C9760 8E250000 */  lw        $a1, ($s1)
/* EE114 802C9764 0C0B1EAF */  jal       get_variable
/* EE118 802C9768 26310004 */   addiu    $s1, $s1, 4
/* EE11C 802C976C 0200202D */  daddu     $a0, $s0, $zero
/* EE120 802C9770 8E250000 */  lw        $a1, ($s1)
/* EE124 802C9774 0C0B1EAF */  jal       get_variable
/* EE128 802C9778 0040802D */   daddu    $s0, $v0, $zero
/* EE12C 802C977C 10400005 */  beqz      $v0, .L802C9794
/* EE130 802C9780 00000000 */   nop      
/* EE134 802C9784 0C046D74 */  jal       func_8011B5D0
/* EE138 802C9788 3204FFFF */   andi     $a0, $s0, 0xffff
/* EE13C 802C978C 080B25E7 */  j         .L802C979C
/* EE140 802C9790 00000000 */   nop      
.L802C9794:
/* EE144 802C9794 0C046D98 */  jal       func_8011B660
/* EE148 802C9798 3204FFFF */   andi     $a0, $s0, 0xffff
.L802C979C:
/* EE14C 802C979C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EE150 802C97A0 8FB10014 */  lw        $s1, 0x14($sp)
/* EE154 802C97A4 8FB00010 */  lw        $s0, 0x10($sp)
/* EE158 802C97A8 24020002 */  addiu     $v0, $zero, 2
/* EE15C 802C97AC 03E00008 */  jr        $ra
/* EE160 802C97B0 27BD0020 */   addiu    $sp, $sp, 0x20
