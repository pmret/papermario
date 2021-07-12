.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_file_2_title
/* 165FC8 80245768 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 165FCC 8024576C 0080402D */  daddu     $t0, $a0, $zero
/* 165FD0 80245770 00A0482D */  daddu     $t1, $a1, $zero
/* 165FD4 80245774 00C0502D */  daddu     $t2, $a2, $zero
/* 165FD8 80245778 0100282D */  daddu     $a1, $t0, $zero
/* 165FDC 8024577C 8FA20038 */  lw        $v0, 0x38($sp)
/* 165FE0 80245780 8FA3003C */  lw        $v1, 0x3c($sp)
/* 165FE4 80245784 8FA40040 */  lw        $a0, 0x40($sp)
/* 165FE8 80245788 0120302D */  daddu     $a2, $t1, $zero
/* 165FEC 8024578C AFA70010 */  sw        $a3, 0x10($sp)
/* 165FF0 80245790 0140382D */  daddu     $a3, $t2, $zero
/* 165FF4 80245794 AFBF0020 */  sw        $ra, 0x20($sp)
/* 165FF8 80245798 AFA4001C */  sw        $a0, 0x1c($sp)
/* 165FFC 8024579C 24040002 */  addiu     $a0, $zero, 2
/* 166000 802457A0 AFA20014 */  sw        $v0, 0x14($sp)
/* 166004 802457A4 0C091513 */  jal       filemenu_draw_contents_file_title
/* 166008 802457A8 AFA30018 */   sw       $v1, 0x18($sp)
/* 16600C 802457AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 166010 802457B0 03E00008 */  jr        $ra
/* 166014 802457B4 27BD0028 */   addiu    $sp, $sp, 0x28
