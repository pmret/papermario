.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViRepeatLine
/* 427E0 800673E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 427E4 800673E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 427E8 800673E8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 427EC 800673EC 0C01ACD8 */  jal       osDisableInt
/* 427F0 800673F0 00808021 */   addu     $s0, $a0, $zero
/* 427F4 800673F4 321000FF */  andi      $s0, $s0, 0xff
/* 427F8 800673F8 12000006 */  beqz      $s0, .L80067414
/* 427FC 800673FC 00402021 */   addu     $a0, $v0, $zero
/* 42800 80067400 3C038009 */  lui       $v1, %hi(D_800959D4)
/* 42804 80067404 8C6359D4 */  lw        $v1, %lo(D_800959D4)($v1)
/* 42808 80067408 94620000 */  lhu       $v0, ($v1)
/* 4280C 8006740C 08019D09 */  j         .L80067424
/* 42810 80067410 34420040 */   ori      $v0, $v0, 0x40
.L80067414:
/* 42814 80067414 3C038009 */  lui       $v1, %hi(D_800959D4)
/* 42818 80067418 8C6359D4 */  lw        $v1, %lo(D_800959D4)($v1)
/* 4281C 8006741C 94620000 */  lhu       $v0, ($v1)
/* 42820 80067420 3042FFBF */  andi      $v0, $v0, 0xffbf
.L80067424:
/* 42824 80067424 0C01ACF4 */  jal       osRestoreInt
/* 42828 80067428 A4620000 */   sh       $v0, ($v1)
/* 4282C 8006742C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42830 80067430 8FB00010 */  lw        $s0, 0x10($sp)
/* 42834 80067434 03E00008 */  jr        $ra
/* 42838 80067438 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4283C 8006743C 00000000 */  nop
