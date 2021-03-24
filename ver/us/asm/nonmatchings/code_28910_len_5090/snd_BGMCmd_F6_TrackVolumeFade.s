.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_BGMCmd_F6_TrackVolumeFade
/* 2B2D0 8004FED0 908200D6 */  lbu       $v0, 0xd6($a0)
/* 2B2D4 8004FED4 948600D4 */  lhu       $a2, 0xd4($a0)
/* 2B2D8 8004FED8 3044007F */  andi      $a0, $v0, 0x7f
/* 2B2DC 8004FEDC 54800001 */  bnel      $a0, $zero, .L8004FEE4
/* 2B2E0 8004FEE0 00042600 */   sll      $a0, $a0, 0x18
.L8004FEE4:
/* 2B2E4 8004FEE4 8CA20018 */  lw        $v0, 0x18($a1)
/* 2B2E8 8004FEE8 10820012 */  beq       $a0, $v0, .L8004FF34
/* 2B2EC 8004FEEC 00000000 */   nop
/* 2B2F0 8004FEF0 58C00002 */  blezl     $a2, .L8004FEFC
/* 2B2F4 8004FEF4 24060001 */   addiu    $a2, $zero, 1
/* 2B2F8 8004FEF8 8CA20018 */  lw        $v0, 0x18($a1)
.L8004FEFC:
/* 2B2FC 8004FEFC 00821023 */  subu      $v0, $a0, $v0
/* 2B300 8004FF00 14C00002 */  bnez      $a2, .L8004FF0C
/* 2B304 8004FF04 0046001A */   div      $zero, $v0, $a2
/* 2B308 8004FF08 0007000D */  break     7
.L8004FF0C:
/* 2B30C 8004FF0C 2401FFFF */   addiu    $at, $zero, -1
/* 2B310 8004FF10 14C10004 */  bne       $a2, $at, .L8004FF24
/* 2B314 8004FF14 3C018000 */   lui      $at, 0x8000
/* 2B318 8004FF18 14410002 */  bne       $v0, $at, .L8004FF24
/* 2B31C 8004FF1C 00000000 */   nop
/* 2B320 8004FF20 0006000D */  break     6
.L8004FF24:
/* 2B324 8004FF24 00001012 */   mflo     $v0
/* 2B328 8004FF28 ACA60024 */  sw        $a2, 0x24($a1)
/* 2B32C 8004FF2C ACA40020 */  sw        $a0, 0x20($a1)
/* 2B330 8004FF30 ACA2001C */  sw        $v0, 0x1c($a1)
.L8004FF34:
/* 2B334 8004FF34 03E00008 */  jr        $ra
/* 2B338 8004FF38 00000000 */   nop
