.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_file_1_info
/* 165E38 802455D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 165E3C 802455DC 0080402D */  daddu     $t0, $a0, $zero
/* 165E40 802455E0 00A0482D */  daddu     $t1, $a1, $zero
/* 165E44 802455E4 00C0502D */  daddu     $t2, $a2, $zero
/* 165E48 802455E8 0100282D */  daddu     $a1, $t0, $zero
/* 165E4C 802455EC 8FA20038 */  lw        $v0, 0x38($sp)
/* 165E50 802455F0 8FA3003C */  lw        $v1, 0x3c($sp)
/* 165E54 802455F4 8FA40040 */  lw        $a0, 0x40($sp)
/* 165E58 802455F8 0120302D */  daddu     $a2, $t1, $zero
/* 165E5C 802455FC AFA70010 */  sw        $a3, 0x10($sp)
/* 165E60 80245600 0140382D */  daddu     $a3, $t2, $zero
/* 165E64 80245604 AFBF0020 */  sw        $ra, 0x20($sp)
/* 165E68 80245608 AFA4001C */  sw        $a0, 0x1c($sp)
/* 165E6C 8024560C 24040001 */  addiu     $a0, $zero, 1
/* 165E70 80245610 AFA20014 */  sw        $v0, 0x14($sp)
/* 165E74 80245614 0C0913F5 */  jal       filemenu_draw_contents_file_info
/* 165E78 80245618 AFA30018 */   sw       $v1, 0x18($sp)
/* 165E7C 8024561C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 165E80 80245620 03E00008 */  jr        $ra
/* 165E84 80245624 27BD0028 */   addiu    $sp, $sp, 0x28
