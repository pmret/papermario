.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_partner_move_history
/* 8890C 800EF45C 3C058011 */  lui       $a1, 0x8011
/* 88910 800EF460 24A5CD38 */  addiu     $a1, $a1, -0x32c8
/* 88914 800EF464 0000302D */  daddu     $a2, $zero, $zero
/* 88918 800EF468 3C028010 */  lui       $v0, 0x8010
/* 8891C 800EF46C 2442833C */  addiu     $v0, $v0, -0x7cc4
/* 88920 800EF470 0040482D */  daddu     $t1, $v0, $zero
/* 88924 800EF474 3C028010 */  lui       $v0, 0x8010
/* 88928 800EF478 24428340 */  addiu     $v0, $v0, -0x7cc0
/* 8892C 800EF47C 0040402D */  daddu     $t0, $v0, $zero
/* 88930 800EF480 3C028010 */  lui       $v0, 0x8010
/* 88934 800EF484 24428344 */  addiu     $v0, $v0, -0x7cbc
/* 88938 800EF488 0040382D */  daddu     $a3, $v0, $zero
/* 8893C 800EF48C C4800038 */  lwc1      $f0, 0x38($a0)
/* 88940 800EF490 C482003C */  lwc1      $f2, 0x3c($a0)
/* 88944 800EF494 C4840040 */  lwc1      $f4, 0x40($a0)
/* 88948 800EF498 24A3000C */  addiu     $v1, $a1, 0xc
/* 8894C 800EF49C E5200000 */  swc1      $f0, ($t1)
/* 88950 800EF4A0 E5020000 */  swc1      $f2, ($t0)
/* 88954 800EF4A4 E4E40000 */  swc1      $f4, ($a3)
.L800EF4A8:
/* 88958 800EF4A8 24C60001 */  addiu     $a2, $a2, 1
/* 8895C 800EF4AC C5200000 */  lwc1      $f0, ($t1)
/* 88960 800EF4B0 C5020000 */  lwc1      $f2, ($t0)
/* 88964 800EF4B4 C4E40000 */  lwc1      $f4, ($a3)
/* 88968 800EF4B8 28C20028 */  slti      $v0, $a2, 0x28
/* 8896C 800EF4BC E460FFF8 */  swc1      $f0, -8($v1)
/* 88970 800EF4C0 E462FFFC */  swc1      $f2, -4($v1)
/* 88974 800EF4C4 E4640000 */  swc1      $f4, ($v1)
/* 88978 800EF4C8 24630010 */  addiu     $v1, $v1, 0x10
/* 8897C 800EF4CC A0A00000 */  sb        $zero, ($a1)
/* 88980 800EF4D0 1440FFF5 */  bnez      $v0, .L800EF4A8
/* 88984 800EF4D4 24A50010 */   addiu    $a1, $a1, 0x10
/* 88988 800EF4D8 03E00008 */  jr        $ra
/* 8898C 800EF4DC 00000000 */   nop      
