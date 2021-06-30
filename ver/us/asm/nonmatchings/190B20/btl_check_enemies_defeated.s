.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_check_enemies_defeated
/* 191D14 80263434 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 191D18 80263438 AFBF0010 */  sw        $ra, 0x10($sp)
/* 191D1C 8026343C 0C098CFA */  jal       btl_are_all_enemies_defeated
/* 191D20 80263440 00000000 */   nop
/* 191D24 80263444 10400004 */  beqz      $v0, .L80263458
/* 191D28 80263448 0000102D */   daddu    $v0, $zero, $zero
/* 191D2C 8026344C 0C090464 */  jal       btl_set_state
/* 191D30 80263450 2404001A */   addiu    $a0, $zero, 0x1a
/* 191D34 80263454 24020001 */  addiu     $v0, $zero, 1
.L80263458:
/* 191D38 80263458 8FBF0010 */  lw        $ra, 0x10($sp)
/* 191D3C 8026345C 03E00008 */  jr        $ra
/* 191D40 80263460 27BD0018 */   addiu    $sp, $sp, 0x18
