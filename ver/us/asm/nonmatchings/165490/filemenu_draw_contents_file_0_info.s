.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_file_0_info
/* 165DE8 80245588 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 165DEC 8024558C 0080402D */  daddu     $t0, $a0, $zero
/* 165DF0 80245590 00A0482D */  daddu     $t1, $a1, $zero
/* 165DF4 80245594 00C0502D */  daddu     $t2, $a2, $zero
/* 165DF8 80245598 0100282D */  daddu     $a1, $t0, $zero
/* 165DFC 8024559C 8FA20038 */  lw        $v0, 0x38($sp)
/* 165E00 802455A0 8FA3003C */  lw        $v1, 0x3c($sp)
/* 165E04 802455A4 8FA40040 */  lw        $a0, 0x40($sp)
/* 165E08 802455A8 0120302D */  daddu     $a2, $t1, $zero
/* 165E0C 802455AC AFA70010 */  sw        $a3, 0x10($sp)
/* 165E10 802455B0 0140382D */  daddu     $a3, $t2, $zero
/* 165E14 802455B4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 165E18 802455B8 AFA4001C */  sw        $a0, 0x1c($sp)
/* 165E1C 802455BC 0000202D */  daddu     $a0, $zero, $zero
/* 165E20 802455C0 AFA20014 */  sw        $v0, 0x14($sp)
/* 165E24 802455C4 0C0913F5 */  jal       filemenu_draw_contents_file_info
/* 165E28 802455C8 AFA30018 */   sw       $v1, 0x18($sp)
/* 165E2C 802455CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 165E30 802455D0 03E00008 */  jr        $ra
/* 165E34 802455D4 27BD0028 */   addiu    $sp, $sp, 0x28
