.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006040C
/* 36356C E006040C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 363570 E0060410 3C02E006 */  lui       $v0, %hi(func_E0060450)
/* 363574 E0060414 24420450 */  addiu     $v0, $v0, %lo(func_E0060450)
/* 363578 E0060418 AFA2001C */  sw        $v0, 0x1c($sp)
/* 36357C E006041C 2402002D */  addiu     $v0, $zero, 0x2d
/* 363580 E0060420 AFA40018 */  sw        $a0, 0x18($sp)
/* 363584 E0060424 27A40010 */  addiu     $a0, $sp, 0x10
/* 363588 E0060428 AFBF0020 */  sw        $ra, 0x20($sp)
/* 36358C E006042C AFA00014 */  sw        $zero, 0x14($sp)
/* 363590 E0060430 0C080120 */  jal       func_E0200480
/* 363594 E0060434 AFA20010 */   sw       $v0, 0x10($sp)
/* 363598 E0060438 8C430000 */  lw        $v1, ($v0)
/* 36359C E006043C 34630002 */  ori       $v1, $v1, 2
/* 3635A0 E0060440 AC430000 */  sw        $v1, ($v0)
/* 3635A4 E0060444 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3635A8 E0060448 03E00008 */  jr        $ra
/* 3635AC E006044C 27BD0028 */   addiu    $sp, $sp, 0x28
