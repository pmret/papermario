.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FB04
/* 3AF04 8005FB04 0000202D */  daddu     $a0, $zero, $zero
/* 3AF08 8005FB08 3C03800B */  lui       $v1, %hi(D_800B1D27)
/* 3AF0C 8005FB0C 24631D27 */  addiu     $v1, $v1, %lo(D_800B1D27)
.L8005FB10:
/* 3AF10 8005FB10 90620000 */  lbu       $v0, ($v1)
/* 3AF14 8005FB14 24840001 */  addiu     $a0, $a0, 1
/* 3AF18 8005FB18 3042007F */  andi      $v0, $v0, 0x7f
/* 3AF1C 8005FB1C A0620000 */  sb        $v0, ($v1)
/* 3AF20 8005FB20 2C820004 */  sltiu     $v0, $a0, 4
/* 3AF24 8005FB24 1440FFFA */  bnez      $v0, .L8005FB10
/* 3AF28 8005FB28 2463000A */   addiu    $v1, $v1, 0xa
/* 3AF2C 8005FB2C 03E00008 */  jr        $ra
/* 3AF30 8005FB30 0000102D */   daddu    $v0, $zero, $zero
/* 3AF34 8005FB34 00000000 */  nop
/* 3AF38 8005FB38 00000000 */  nop
/* 3AF3C 8005FB3C 00000000 */  nop
