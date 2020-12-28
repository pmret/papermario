.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802183A0_47F450
/* 47F450 802183A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 47F454 802183A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 47F458 802183A8 0080882D */  daddu     $s1, $a0, $zero
/* 47F45C 802183AC AFBF0018 */  sw        $ra, 0x18($sp)
/* 47F460 802183B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 47F464 802183B4 8E30000C */  lw        $s0, 0xc($s1)
/* 47F468 802183B8 8E050000 */  lw        $a1, ($s0)
/* 47F46C 802183BC 0C0B1EAF */  jal       get_variable
/* 47F470 802183C0 26100004 */   addiu    $s0, $s0, 4
/* 47F474 802183C4 0220202D */  daddu     $a0, $s1, $zero
/* 47F478 802183C8 8E050000 */  lw        $a1, ($s0)
/* 47F47C 802183CC 0C0B1EAF */  jal       get_variable
/* 47F480 802183D0 0040802D */   daddu    $s0, $v0, $zero
/* 47F484 802183D4 0200202D */  daddu     $a0, $s0, $zero
/* 47F488 802183D8 0C00A3C2 */  jal       start_rumble
/* 47F48C 802183DC 0040282D */   daddu    $a1, $v0, $zero
/* 47F490 802183E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 47F494 802183E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 47F498 802183E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 47F49C 802183EC 24020002 */  addiu     $v0, $zero, 2
/* 47F4A0 802183F0 03E00008 */  jr        $ra
/* 47F4A4 802183F4 27BD0020 */   addiu    $sp, $sp, 0x20
