.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188A8_5CEF38
/* 5CEF38 802188A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5CEF3C 802188AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 5CEF40 802188B0 0C04760B */  jal       func_8011D82C
/* 5CEF44 802188B4 24040001 */   addiu    $a0, $zero, 1
/* 5CEF48 802188B8 0000202D */  daddu     $a0, $zero, $zero
/* 5CEF4C 802188BC 24020001 */  addiu     $v0, $zero, 1
/* 5CEF50 802188C0 0080282D */  daddu     $a1, $a0, $zero
/* 5CEF54 802188C4 0080302D */  daddu     $a2, $a0, $zero
/* 5CEF58 802188C8 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 5CEF5C 802188CC 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 5CEF60 802188D0 0080382D */  daddu     $a3, $a0, $zero
/* 5CEF64 802188D4 0C046F97 */  jal       set_background_color_blend
/* 5CEF68 802188D8 A0620000 */   sb       $v0, ($v1)
/* 5CEF6C 802188DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5CEF70 802188E0 24020002 */  addiu     $v0, $zero, 2
/* 5CEF74 802188E4 03E00008 */  jr        $ra
/* 5CEF78 802188E8 27BD0018 */   addiu    $sp, $sp, 0x18
