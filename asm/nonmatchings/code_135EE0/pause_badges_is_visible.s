.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_is_visible
/* 13A5B0 80247270 3C038027 */  lui       $v1, 0x8027
/* 13A5B4 80247274 8C63038C */  lw        $v1, 0x38c($v1)
/* 13A5B8 80247278 2462FFE0 */  addiu     $v0, $v1, -0x20
/* 13A5BC 8024727C 0082102A */  slt       $v0, $a0, $v0
/* 13A5C0 80247280 14400003 */  bnez      $v0, .L80247290
/* 13A5C4 80247284 24620080 */   addiu    $v0, $v1, 0x80
/* 13A5C8 80247288 03E00008 */  jr        $ra
/* 13A5CC 8024728C 0082102A */   slt      $v0, $a0, $v0
.L80247290:
/* 13A5D0 80247290 03E00008 */  jr        $ra
/* 13A5D4 80247294 0000102D */   daddu    $v0, $zero, $zero
