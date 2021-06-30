.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_file_2_info
/* 165E88 80245628 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 165E8C 8024562C 0080402D */  daddu     $t0, $a0, $zero
/* 165E90 80245630 00A0482D */  daddu     $t1, $a1, $zero
/* 165E94 80245634 00C0502D */  daddu     $t2, $a2, $zero
/* 165E98 80245638 0100282D */  daddu     $a1, $t0, $zero
/* 165E9C 8024563C 8FA20038 */  lw        $v0, 0x38($sp)
/* 165EA0 80245640 8FA3003C */  lw        $v1, 0x3c($sp)
/* 165EA4 80245644 8FA40040 */  lw        $a0, 0x40($sp)
/* 165EA8 80245648 0120302D */  daddu     $a2, $t1, $zero
/* 165EAC 8024564C AFA70010 */  sw        $a3, 0x10($sp)
/* 165EB0 80245650 0140382D */  daddu     $a3, $t2, $zero
/* 165EB4 80245654 AFBF0020 */  sw        $ra, 0x20($sp)
/* 165EB8 80245658 AFA4001C */  sw        $a0, 0x1c($sp)
/* 165EBC 8024565C 24040002 */  addiu     $a0, $zero, 2
/* 165EC0 80245660 AFA20014 */  sw        $v0, 0x14($sp)
/* 165EC4 80245664 0C0913F5 */  jal       filemenu_draw_contents_file_info
/* 165EC8 80245668 AFA30018 */   sw       $v1, 0x18($sp)
/* 165ECC 8024566C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 165ED0 80245670 03E00008 */  jr        $ra
/* 165ED4 80245674 27BD0028 */   addiu    $sp, $sp, 0x28
