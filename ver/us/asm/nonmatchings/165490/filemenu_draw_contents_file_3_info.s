.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_file_3_info
/* 165ED8 80245678 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 165EDC 8024567C 0080402D */  daddu     $t0, $a0, $zero
/* 165EE0 80245680 00A0482D */  daddu     $t1, $a1, $zero
/* 165EE4 80245684 00C0502D */  daddu     $t2, $a2, $zero
/* 165EE8 80245688 0100282D */  daddu     $a1, $t0, $zero
/* 165EEC 8024568C 8FA20038 */  lw        $v0, 0x38($sp)
/* 165EF0 80245690 8FA3003C */  lw        $v1, 0x3c($sp)
/* 165EF4 80245694 8FA40040 */  lw        $a0, 0x40($sp)
/* 165EF8 80245698 0120302D */  daddu     $a2, $t1, $zero
/* 165EFC 8024569C AFA70010 */  sw        $a3, 0x10($sp)
/* 165F00 802456A0 0140382D */  daddu     $a3, $t2, $zero
/* 165F04 802456A4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 165F08 802456A8 AFA4001C */  sw        $a0, 0x1c($sp)
/* 165F0C 802456AC 24040003 */  addiu     $a0, $zero, 3
/* 165F10 802456B0 AFA20014 */  sw        $v0, 0x14($sp)
/* 165F14 802456B4 0C0913F5 */  jal       filemenu_draw_contents_file_info
/* 165F18 802456B8 AFA30018 */   sw       $v1, 0x18($sp)
/* 165F1C 802456BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 165F20 802456C0 03E00008 */  jr        $ra
/* 165F24 802456C4 27BD0028 */   addiu    $sp, $sp, 0x28
