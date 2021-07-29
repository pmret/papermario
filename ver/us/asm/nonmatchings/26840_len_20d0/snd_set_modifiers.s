.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_set_modifiers
/* 27758 8004C358 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2775C 8004C35C AFB40020 */  sw        $s4, 0x20($sp)
/* 27760 8004C360 0080A02D */  daddu     $s4, $a0, $zero
/* 27764 8004C364 AFB20018 */  sw        $s2, 0x18($sp)
/* 27768 8004C368 00A0902D */  daddu     $s2, $a1, $zero
/* 2776C 8004C36C AFB10014 */  sw        $s1, 0x14($sp)
/* 27770 8004C370 0000882D */  daddu     $s1, $zero, $zero
/* 27774 8004C374 AFBF0024 */  sw        $ra, 0x24($sp)
/* 27778 8004C378 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2777C 8004C37C AFB00010 */  sw        $s0, 0x10($sp)
/* 27780 8004C380 96420000 */  lhu       $v0, ($s2)
/* 27784 8004C384 2410016C */  addiu     $s0, $zero, 0x16c
/* 27788 8004C388 305323FF */  andi      $s3, $v0, 0x23ff
.L8004C38C:
/* 2778C 8004C38C 02902021 */  addu      $a0, $s4, $s0
/* 27790 8004C390 94820096 */  lhu       $v0, 0x96($a0)
/* 27794 8004C394 54530004 */  bnel      $v0, $s3, .L8004C3A8
/* 27798 8004C398 26310001 */   addiu    $s1, $s1, 1
/* 2779C 8004C39C 0C0130F5 */  jal       snd_set_player_modifiers
/* 277A0 8004C3A0 0240282D */   daddu    $a1, $s2, $zero
/* 277A4 8004C3A4 26310001 */  addiu     $s1, $s1, 1
.L8004C3A8:
/* 277A8 8004C3A8 2A220008 */  slti      $v0, $s1, 8
/* 277AC 8004C3AC 1440FFF7 */  bnez      $v0, .L8004C38C
/* 277B0 8004C3B0 261000AC */   addiu    $s0, $s0, 0xac
/* 277B4 8004C3B4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 277B8 8004C3B8 8FB40020 */  lw        $s4, 0x20($sp)
/* 277BC 8004C3BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 277C0 8004C3C0 8FB20018 */  lw        $s2, 0x18($sp)
/* 277C4 8004C3C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 277C8 8004C3C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 277CC 8004C3CC 03E00008 */  jr        $ra
/* 277D0 8004C3D0 27BD0028 */   addiu    $sp, $sp, 0x28
