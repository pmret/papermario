.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243CD4_804554
/* 804554 80243CD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 804558 80243CD8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 80455C 80243CDC 10A00003 */  beqz      $a1, .L80243CEC
/* 804560 80243CE0 8C86000C */   lw       $a2, 0xc($a0)
/* 804564 80243CE4 3C018025 */  lui       $at, 0x8025
/* 804568 80243CE8 AC20D944 */  sw        $zero, -0x26bc($at)
.L80243CEC:
/* 80456C 80243CEC 3C038025 */  lui       $v1, 0x8025
/* 804570 80243CF0 2463D944 */  addiu     $v1, $v1, -0x26bc
/* 804574 80243CF4 8C620000 */  lw        $v0, ($v1)
/* 804578 80243CF8 54400003 */  bnel      $v0, $zero, .L80243D08
/* 80457C 80243CFC AC600000 */   sw       $zero, ($v1)
/* 804580 80243D00 08090F47 */  j         .L80243D1C
/* 804584 80243D04 0000102D */   daddu    $v0, $zero, $zero
.L80243D08:
/* 804588 80243D08 8CC50000 */  lw        $a1, ($a2)
/* 80458C 80243D0C 3C068025 */  lui       $a2, 0x8025
/* 804590 80243D10 0C0B2026 */  jal       set_variable
/* 804594 80243D14 8CC6D948 */   lw       $a2, -0x26b8($a2)
/* 804598 80243D18 24020002 */  addiu     $v0, $zero, 2
.L80243D1C:
/* 80459C 80243D1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8045A0 80243D20 03E00008 */  jr        $ra
/* 8045A4 80243D24 27BD0018 */   addiu    $sp, $sp, 0x18
