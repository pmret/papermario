.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DE894
/* 101984 802DE894 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 101988 802DE898 00A0402D */  daddu     $t0, $a1, $zero
/* 10198C 802DE89C 00C0482D */  daddu     $t1, $a2, $zero
/* 101990 802DE8A0 8FA20038 */  lw        $v0, 0x38($sp)
/* 101994 802DE8A4 8FA3003C */  lw        $v1, 0x3c($sp)
/* 101998 802DE8A8 8FA50040 */  lw        $a1, 0x40($sp)
/* 10199C 802DE8AC 0100302D */  daddu     $a2, $t0, $zero
/* 1019A0 802DE8B0 AFA70010 */  sw        $a3, 0x10($sp)
/* 1019A4 802DE8B4 0120382D */  daddu     $a3, $t1, $zero
/* 1019A8 802DE8B8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1019AC 802DE8BC AFA5001C */  sw        $a1, 0x1c($sp)
/* 1019B0 802DE8C0 2405FFFF */  addiu     $a1, $zero, -1
/* 1019B4 802DE8C4 AFA20014 */  sw        $v0, 0x14($sp)
/* 1019B8 802DE8C8 0C0B79E0 */  jal       func_802DE780
/* 1019BC 802DE8CC AFA30018 */   sw       $v1, 0x18($sp)
/* 1019C0 802DE8D0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1019C4 802DE8D4 03E00008 */  jr        $ra
/* 1019C8 802DE8D8 27BD0028 */   addiu    $sp, $sp, 0x28
