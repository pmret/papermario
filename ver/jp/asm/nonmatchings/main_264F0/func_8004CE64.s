.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CE64
/* 28264 8004CE64 8CA20000 */  lw        $v0, ($a1)
/* 28268 8004CE68 90470002 */  lbu       $a3, 2($v0)
/* 2826C 8004CE6C 90430000 */  lbu       $v1, ($v0)
/* 28270 8004CE70 90440001 */  lbu       $a0, 1($v0)
/* 28274 8004CE74 24420003 */  addiu     $v0, $v0, 3
/* 28278 8004CE78 ACA20000 */  sw        $v0, ($a1)
/* 2827C 8004CE7C 00031A00 */  sll       $v1, $v1, 8
/* 28280 8004CE80 00832021 */  addu      $a0, $a0, $v1
/* 28284 8004CE84 10E00003 */  beqz      $a3, .L8004CE94
/* 28288 8004CE88 0080302D */   daddu    $a2, $a0, $zero
/* 2828C 8004CE8C 00071200 */  sll       $v0, $a3, 8
/* 28290 8004CE90 344700FF */  ori       $a3, $v0, 0xff
.L8004CE94:
/* 28294 8004CE94 00041400 */  sll       $v0, $a0, 0x10
/* 28298 8004CE98 58400001 */  blezl     $v0, .L8004CEA0
/* 2829C 8004CE9C 24060001 */   addiu    $a2, $zero, 1
.L8004CEA0:
/* 282A0 8004CEA0 8CA2006C */  lw        $v0, 0x6c($a1)
/* 282A4 8004CEA4 00071C00 */  sll       $v1, $a3, 0x10
/* 282A8 8004CEA8 00621823 */  subu      $v1, $v1, $v0
/* 282AC 8004CEAC 00061400 */  sll       $v0, $a2, 0x10
/* 282B0 8004CEB0 00021403 */  sra       $v0, $v0, 0x10
/* 282B4 8004CEB4 14400002 */  bnez      $v0, .L8004CEC0
/* 282B8 8004CEB8 0062001A */   div      $zero, $v1, $v0
/* 282BC 8004CEBC 0007000D */  break     7
.L8004CEC0:
/* 282C0 8004CEC0 2401FFFF */   addiu    $at, $zero, -1
/* 282C4 8004CEC4 14410004 */  bne       $v0, $at, .L8004CED8
/* 282C8 8004CEC8 3C018000 */   lui      $at, 0x8000
/* 282CC 8004CECC 14610002 */  bne       $v1, $at, .L8004CED8
/* 282D0 8004CED0 00000000 */   nop
/* 282D4 8004CED4 0006000D */  break     6
.L8004CED8:
/* 282D8 8004CED8 00001812 */   mflo     $v1
/* 282DC 8004CEDC A4A60074 */  sh        $a2, 0x74($a1)
/* 282E0 8004CEE0 A4A70076 */  sh        $a3, 0x76($a1)
/* 282E4 8004CEE4 03E00008 */  jr        $ra
/* 282E8 8004CEE8 ACA30070 */   sw       $v1, 0x70($a1)
