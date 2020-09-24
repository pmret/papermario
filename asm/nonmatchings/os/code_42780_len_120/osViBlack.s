.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViBlack
/* 42780 80067380 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42784 80067384 AFB00010 */  sw        $s0, 0x10($sp)
/* 42788 80067388 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4278C 8006738C 0C01ACD8 */  jal       __osDisableInt
/* 42790 80067390 00808021 */   addu     $s0, $a0, $zero
/* 42794 80067394 321000FF */  andi      $s0, $s0, 0xff
/* 42798 80067398 12000006 */  beqz      $s0, .L800673B4
/* 4279C 8006739C 00402021 */   addu     $a0, $v0, $zero
/* 427A0 800673A0 3C038009 */  lui       $v1, 0x8009
/* 427A4 800673A4 8C6359D4 */  lw        $v1, 0x59d4($v1)
/* 427A8 800673A8 94620000 */  lhu       $v0, ($v1)
/* 427AC 800673AC 08019CF1 */  j         .L800673C4
/* 427B0 800673B0 34420020 */   ori      $v0, $v0, 0x20
.L800673B4:
/* 427B4 800673B4 3C038009 */  lui       $v1, 0x8009
/* 427B8 800673B8 8C6359D4 */  lw        $v1, 0x59d4($v1)
/* 427BC 800673BC 94620000 */  lhu       $v0, ($v1)
/* 427C0 800673C0 3042FFDF */  andi      $v0, $v0, 0xffdf
.L800673C4:
/* 427C4 800673C4 0C01ACF4 */  jal       __osRestoreInt
/* 427C8 800673C8 A4620000 */   sh       $v0, ($v1)
/* 427CC 800673CC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 427D0 800673D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 427D4 800673D4 03E00008 */  jr        $ra
/* 427D8 800673D8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 427DC 800673DC 00000000 */  nop       
