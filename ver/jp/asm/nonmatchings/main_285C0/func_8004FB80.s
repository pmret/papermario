.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FB80
/* 2AF80 8004FB80 908200D6 */  lbu       $v0, 0xd6($a0)
/* 2AF84 8004FB84 948600D4 */  lhu       $a2, 0xd4($a0)
/* 2AF88 8004FB88 3044007F */  andi      $a0, $v0, 0x7f
/* 2AF8C 8004FB8C 54800001 */  bnel      $a0, $zero, .L8004FB94
/* 2AF90 8004FB90 00042600 */   sll      $a0, $a0, 0x18
.L8004FB94:
/* 2AF94 8004FB94 8CA20018 */  lw        $v0, 0x18($a1)
/* 2AF98 8004FB98 10820012 */  beq       $a0, $v0, .L8004FBE4
/* 2AF9C 8004FB9C 00000000 */   nop
/* 2AFA0 8004FBA0 58C00002 */  blezl     $a2, .L8004FBAC
/* 2AFA4 8004FBA4 24060001 */   addiu    $a2, $zero, 1
/* 2AFA8 8004FBA8 8CA20018 */  lw        $v0, 0x18($a1)
.L8004FBAC:
/* 2AFAC 8004FBAC 00821023 */  subu      $v0, $a0, $v0
/* 2AFB0 8004FBB0 14C00002 */  bnez      $a2, .L8004FBBC
/* 2AFB4 8004FBB4 0046001A */   div      $zero, $v0, $a2
/* 2AFB8 8004FBB8 0007000D */  break     7
.L8004FBBC:
/* 2AFBC 8004FBBC 2401FFFF */   addiu    $at, $zero, -1
/* 2AFC0 8004FBC0 14C10004 */  bne       $a2, $at, .L8004FBD4
/* 2AFC4 8004FBC4 3C018000 */   lui      $at, 0x8000
/* 2AFC8 8004FBC8 14410002 */  bne       $v0, $at, .L8004FBD4
/* 2AFCC 8004FBCC 00000000 */   nop
/* 2AFD0 8004FBD0 0006000D */  break     6
.L8004FBD4:
/* 2AFD4 8004FBD4 00001012 */   mflo     $v0
/* 2AFD8 8004FBD8 ACA60024 */  sw        $a2, 0x24($a1)
/* 2AFDC 8004FBDC ACA40020 */  sw        $a0, 0x20($a1)
/* 2AFE0 8004FBE0 ACA2001C */  sw        $v0, 0x1c($a1)
.L8004FBE4:
/* 2AFE4 8004FBE4 03E00008 */  jr        $ra
/* 2AFE8 8004FBE8 00000000 */   nop
