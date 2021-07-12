.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9764_42CE54
/* 42CE54 802A9764 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42CE58 802A9768 3C02802A */  lui       $v0, %hi(D_8029FBE0)
/* 42CE5C 802A976C 2442FBE0 */  addiu     $v0, $v0, %lo(D_8029FBE0)
/* 42CE60 802A9770 AFB10014 */  sw        $s1, 0x14($sp)
/* 42CE64 802A9774 24110001 */  addiu     $s1, $zero, 1
/* 42CE68 802A9778 AFBF0018 */  sw        $ra, 0x18($sp)
/* 42CE6C 802A977C AFB00010 */  sw        $s0, 0x10($sp)
/* 42CE70 802A9780 8C440004 */  lw        $a0, 4($v0)
/* 42CE74 802A9784 0C05123D */  jal       free_hud_element
/* 42CE78 802A9788 24500004 */   addiu    $s0, $v0, 4
.L802A978C:
/* 42CE7C 802A978C 8E040004 */  lw        $a0, 4($s0)
/* 42CE80 802A9790 26100004 */  addiu     $s0, $s0, 4
/* 42CE84 802A9794 0C05123D */  jal       free_hud_element
/* 42CE88 802A9798 26310001 */   addiu    $s1, $s1, 1
/* 42CE8C 802A979C 2A22000F */  slti      $v0, $s1, 0xf
/* 42CE90 802A97A0 1440FFFA */  bnez      $v0, .L802A978C
/* 42CE94 802A97A4 00000000 */   nop
/* 42CE98 802A97A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42CE9C 802A97AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 42CEA0 802A97B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 42CEA4 802A97B4 03E00008 */  jr        $ra
/* 42CEA8 802A97B8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 42CEAC 802A97BC 00000000 */  nop
