.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BF0_58CEE0
/* 58CEE0 80218BF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 58CEE4 80218BF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 58CEE8 80218BF8 0080882D */  daddu     $s1, $a0, $zero
/* 58CEEC 80218BFC AFBF0018 */  sw        $ra, 0x18($sp)
/* 58CEF0 80218C00 AFB00010 */  sw        $s0, 0x10($sp)
/* 58CEF4 80218C04 8E30000C */  lw        $s0, 0xc($s1)
/* 58CEF8 80218C08 8E050000 */  lw        $a1, ($s0)
/* 58CEFC 80218C0C 0C0B1EAF */  jal       get_variable
/* 58CF00 80218C10 26100004 */   addiu    $s0, $s0, 4
/* 58CF04 80218C14 0220202D */  daddu     $a0, $s1, $zero
/* 58CF08 80218C18 8E050000 */  lw        $a1, ($s0)
/* 58CF0C 80218C1C 0C0B1EAF */  jal       get_variable
/* 58CF10 80218C20 0040802D */   daddu    $s0, $v0, $zero
/* 58CF14 80218C24 0200202D */  daddu     $a0, $s0, $zero
/* 58CF18 80218C28 0C00A3C2 */  jal       start_rumble
/* 58CF1C 80218C2C 0040282D */   daddu    $a1, $v0, $zero
/* 58CF20 80218C30 8FBF0018 */  lw        $ra, 0x18($sp)
/* 58CF24 80218C34 8FB10014 */  lw        $s1, 0x14($sp)
/* 58CF28 80218C38 8FB00010 */  lw        $s0, 0x10($sp)
/* 58CF2C 80218C3C 24020002 */  addiu     $v0, $zero, 2
/* 58CF30 80218C40 03E00008 */  jr        $ra
/* 58CF34 80218C44 27BD0020 */   addiu    $sp, $sp, 0x20
