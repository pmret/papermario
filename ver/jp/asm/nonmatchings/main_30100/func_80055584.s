.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055584
/* 30984 80055584 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30988 80055588 AFB00018 */  sw        $s0, 0x18($sp)
/* 3098C 8005558C 0080802D */  daddu     $s0, $a0, $zero
/* 30990 80055590 00A0202D */  daddu     $a0, $a1, $zero
/* 30994 80055594 27A50010 */  addiu     $a1, $sp, 0x10
/* 30998 80055598 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3099C 8005559C 0C014E42 */  jal       func_80053908
/* 309A0 800555A0 27A60014 */   addiu    $a2, $sp, 0x14
/* 309A4 800555A4 8FA50010 */  lw        $a1, 0x10($sp)
/* 309A8 800555A8 10A00004 */  beqz      $a1, .L800555BC
/* 309AC 800555AC 24020003 */   addiu    $v0, $zero, 3
/* 309B0 800555B0 8FA60014 */  lw        $a2, 0x14($sp)
/* 309B4 800555B4 0C014E6A */  jal       func_800539A8
/* 309B8 800555B8 0200202D */   daddu    $a0, $s0, $zero
.L800555BC:
/* 309BC 800555BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 309C0 800555C0 8FB00018 */  lw        $s0, 0x18($sp)
/* 309C4 800555C4 03E00008 */  jr        $ra
/* 309C8 800555C8 27BD0020 */   addiu    $sp, $sp, 0x20
