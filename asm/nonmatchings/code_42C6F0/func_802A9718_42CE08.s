.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9718_42CE08
/* 42CE08 802A9718 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42CE0C 802A971C AFB10014 */  sw        $s1, 0x14($sp)
/* 42CE10 802A9720 24110001 */  addiu     $s1, $zero, 1
/* 42CE14 802A9724 AFB00010 */  sw        $s0, 0x10($sp)
/* 42CE18 802A9728 3C10802A */  lui       $s0, %hi(D_8029FBE4)
/* 42CE1C 802A972C 2610FBE4 */  addiu     $s0, $s0, %lo(D_8029FBE4)
/* 42CE20 802A9730 AFBF0018 */  sw        $ra, 0x18($sp)
.L802A9734:
/* 42CE24 802A9734 8E040004 */  lw        $a0, 4($s0)
/* 42CE28 802A9738 26100004 */  addiu     $s0, $s0, 4
/* 42CE2C 802A973C 0C0511EA */  jal       draw_icon_0
/* 42CE30 802A9740 26310001 */   addiu    $s1, $s1, 1
/* 42CE34 802A9744 2A22000F */  slti      $v0, $s1, 0xf
/* 42CE38 802A9748 1440FFFA */  bnez      $v0, .L802A9734
/* 42CE3C 802A974C 00000000 */   nop
/* 42CE40 802A9750 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42CE44 802A9754 8FB10014 */  lw        $s1, 0x14($sp)
/* 42CE48 802A9758 8FB00010 */  lw        $s0, 0x10($sp)
/* 42CE4C 802A975C 03E00008 */  jr        $ra
/* 42CE50 802A9760 27BD0020 */   addiu    $sp, $sp, 0x20
