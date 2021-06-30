.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_03_SetReverb
/* 2830C 8004CF0C 8CA20000 */  lw        $v0, ($a1)
/* 28310 8004CF10 90A3009A */  lbu       $v1, 0x9a($a1)
/* 28314 8004CF14 90460000 */  lbu       $a2, ($v0)
/* 28318 8004CF18 24420001 */  addiu     $v0, $v0, 1
/* 2831C 8004CF1C 30630020 */  andi      $v1, $v1, 0x20
/* 28320 8004CF20 10600002 */  beqz      $v1, .L8004CF2C
/* 28324 8004CF24 ACA20000 */   sw       $v0, ($a1)
/* 28328 8004CF28 9086008D */  lbu       $a2, 0x8d($a0)
.L8004CF2C:
/* 2832C 8004CF2C 24020001 */  addiu     $v0, $zero, 1
/* 28330 8004CF30 A0A6009C */  sb        $a2, 0x9c($a1)
/* 28334 8004CF34 03E00008 */  jr        $ra
/* 28338 8004CF38 A0A20057 */   sb       $v0, 0x57($a1)
