.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802822A8
/* 7E3128 802822A8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7E312C 802822AC AFBF002C */  sw        $ra, 0x2c($sp)
/* 7E3130 802822B0 AFB00028 */  sw        $s0, 0x28($sp)
/* 7E3134 802822B4 8C82000C */  lw        $v0, 0xc($a0)
/* 7E3138 802822B8 8C450000 */  lw        $a1, ($v0)
/* 7E313C 802822BC 0C0B1EAF */  jal       get_variable
/* 7E3140 802822C0 8C900074 */   lw       $s0, 0x74($a0)
/* 7E3144 802822C4 27A50018 */  addiu     $a1, $sp, 0x18
/* 7E3148 802822C8 27A6001C */  addiu     $a2, $sp, 0x1c
/* 7E314C 802822CC 27A70020 */  addiu     $a3, $sp, 0x20
/* 7E3150 802822D0 8E040060 */  lw        $a0, 0x60($s0)
/* 7E3154 802822D4 0C016F84 */  jal       get_collider_center
/* 7E3158 802822D8 0040802D */   daddu    $s0, $v0, $zero
/* 7E315C 802822DC 0200202D */  daddu     $a0, $s0, $zero
/* 7E3160 802822E0 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 7E3164 802822E4 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* 7E3168 802822E8 44060000 */  mfc1      $a2, $f0
/* 7E316C 802822EC 44071000 */  mfc1      $a3, $f2
/* 7E3170 802822F0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7E3174 802822F4 0000282D */  daddu     $a1, $zero, $zero
/* 7E3178 802822F8 0C052757 */  jal       play_sound_at_position
/* 7E317C 802822FC E7A00010 */   swc1     $f0, 0x10($sp)
/* 7E3180 80282300 8FBF002C */  lw        $ra, 0x2c($sp)
/* 7E3184 80282304 8FB00028 */  lw        $s0, 0x28($sp)
/* 7E3188 80282308 24020002 */  addiu     $v0, $zero, 2
/* 7E318C 8028230C 03E00008 */  jr        $ra
/* 7E3190 80282310 27BD0030 */   addiu    $sp, $sp, 0x30
