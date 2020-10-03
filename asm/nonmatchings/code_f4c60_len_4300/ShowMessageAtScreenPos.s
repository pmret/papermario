.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ShowMessageAtScreenPos
/* F5244 802D0894 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F5248 802D0898 AFB20018 */  sw        $s2, 0x18($sp)
/* F524C 802D089C 0080902D */  daddu     $s2, $a0, $zero
/* F5250 802D08A0 AFBF001C */  sw        $ra, 0x1c($sp)
/* F5254 802D08A4 AFB10014 */  sw        $s1, 0x14($sp)
/* F5258 802D08A8 AFB00010 */  sw        $s0, 0x10($sp)
/* F525C 802D08AC 10A00019 */  beqz      $a1, .L802D0914
/* F5260 802D08B0 8E51000C */   lw       $s1, 0xc($s2)
/* F5264 802D08B4 8E250000 */  lw        $a1, ($s1)
/* F5268 802D08B8 0C0B1EAF */  jal       get_variable
/* F526C 802D08BC 26310004 */   addiu    $s1, $s1, 4
/* F5270 802D08C0 8E250000 */  lw        $a1, ($s1)
/* F5274 802D08C4 26310004 */  addiu     $s1, $s1, 4
/* F5278 802D08C8 0240202D */  daddu     $a0, $s2, $zero
/* F527C 802D08CC 0C0B1EAF */  jal       get_variable
/* F5280 802D08D0 0040802D */   daddu    $s0, $v0, $zero
/* F5284 802D08D4 0240202D */  daddu     $a0, $s2, $zero
/* F5288 802D08D8 8E250000 */  lw        $a1, ($s1)
/* F528C 802D08DC 0C0B1EAF */  jal       get_variable
/* F5290 802D08E0 0040882D */   daddu    $s1, $v0, $zero
/* F5294 802D08E4 0200202D */  daddu     $a0, $s0, $zero
/* F5298 802D08E8 3C05802E */  lui       $a1, %hi(D_802DB264)
/* F529C 802D08EC 24A5B264 */  addiu     $a1, $a1, %lo(D_802DB264)
/* F52A0 802D08F0 0040802D */  daddu     $s0, $v0, $zero
/* F52A4 802D08F4 0C049640 */  jal       load_string
/* F52A8 802D08F8 ACA00000 */   sw       $zero, ($a1)
/* F52AC 802D08FC 0040202D */  daddu     $a0, $v0, $zero
/* F52B0 802D0900 0220282D */  daddu     $a1, $s1, $zero
/* F52B4 802D0904 3C01802E */  lui       $at, %hi(gCurrentPrintContext)
/* F52B8 802D0908 AC24B260 */  sw        $a0, %lo(gCurrentPrintContext)($at)
/* F52BC 802D090C 0C0496AE */  jal       clamp_printer_coords
/* F52C0 802D0910 0200302D */   daddu    $a2, $s0, $zero
.L802D0914:
/* F52C4 802D0914 3C04802E */  lui       $a0, %hi(gCurrentPrintContext)
/* F52C8 802D0918 8C84B260 */  lw        $a0, %lo(gCurrentPrintContext)($a0)
/* F52CC 802D091C 8C8204FC */  lw        $v0, 0x4fc($a0)
/* F52D0 802D0920 30420040 */  andi      $v0, $v0, 0x40
/* F52D4 802D0924 14400007 */  bnez      $v0, .L802D0944
/* F52D8 802D0928 24020001 */   addiu    $v0, $zero, 1
/* F52DC 802D092C 3C03802E */  lui       $v1, %hi(D_802DB264)
/* F52E0 802D0930 8C63B264 */  lw        $v1, %lo(D_802DB264)($v1)
/* F52E4 802D0934 54620003 */  bnel      $v1, $v0, .L802D0944
/* F52E8 802D0938 0000102D */   daddu    $v0, $zero, $zero
/* F52EC 802D093C 908304E8 */  lbu       $v1, 0x4e8($a0)
/* F52F0 802D0940 AE430084 */  sw        $v1, 0x84($s2)
.L802D0944:
/* F52F4 802D0944 8FBF001C */  lw        $ra, 0x1c($sp)
/* F52F8 802D0948 8FB20018 */  lw        $s2, 0x18($sp)
/* F52FC 802D094C 8FB10014 */  lw        $s1, 0x14($sp)
/* F5300 802D0950 8FB00010 */  lw        $s0, 0x10($sp)
/* F5304 802D0954 03E00008 */  jr        $ra
/* F5308 802D0958 27BD0020 */   addiu    $sp, $sp, 0x20
