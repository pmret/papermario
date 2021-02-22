.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetMenuSelection
/* 1A1CA4 802733C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A1CA8 802733C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 1A1CAC 802733CC 0080802D */  daddu     $s0, $a0, $zero
/* 1A1CB0 802733D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1A1CB4 802733D4 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1A1CB8 802733D8 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1A1CBC 802733DC AFBF0020 */  sw        $ra, 0x20($sp)
/* 1A1CC0 802733E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1A1CC4 802733E4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1A1CC8 802733E8 8E02000C */  lw        $v0, 0xc($s0)
/* 1A1CCC 802733EC 82260178 */  lb        $a2, 0x178($s1)
/* 1A1CD0 802733F0 8C450000 */  lw        $a1, ($v0)
/* 1A1CD4 802733F4 24420004 */  addiu     $v0, $v0, 4
/* 1A1CD8 802733F8 8C520000 */  lw        $s2, ($v0)
/* 1A1CDC 802733FC 0C0B2026 */  jal       set_variable
/* 1A1CE0 80273400 8C530004 */   lw       $s3, 4($v0)
/* 1A1CE4 80273404 0200202D */  daddu     $a0, $s0, $zero
/* 1A1CE8 80273408 8626017A */  lh        $a2, 0x17a($s1)
/* 1A1CEC 8027340C 0C0B2026 */  jal       set_variable
/* 1A1CF0 80273410 0240282D */   daddu    $a1, $s2, $zero
/* 1A1CF4 80273414 0200202D */  daddu     $a0, $s0, $zero
/* 1A1CF8 80273418 8626017C */  lh        $a2, 0x17c($s1)
/* 1A1CFC 8027341C 0C0B2026 */  jal       set_variable
/* 1A1D00 80273420 0260282D */   daddu    $a1, $s3, $zero
/* 1A1D04 80273424 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1A1D08 80273428 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1A1D0C 8027342C 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A1D10 80273430 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A1D14 80273434 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A1D18 80273438 24020002 */  addiu     $v0, $zero, 2
/* 1A1D1C 8027343C 03E00008 */  jr        $ra
/* 1A1D20 80273440 27BD0028 */   addiu    $sp, $sp, 0x28
